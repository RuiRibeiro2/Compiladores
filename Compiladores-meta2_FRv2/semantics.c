// Copied from TrabalhoNuno semantics.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "ast.h"
#include "semantics.h"

#define MAX_ERRORS 4096
#define MAX_ERROR_SIZE 4096
char *error_messages[MAX_ERRORS];
int error_count = 0;

int semantic_errors = 0;

struct symbol_list *symbol_table;
struct scopes_queue *symbol_scopes;


extern char *type_name[];
char *type_name_stat[] = t_name;

enum type category_to_type(enum category category){
    switch(category){
        case Int:
        case Natural:
            return integer;
        case Float32:
        case Decimal:
            return float32;
        case Bool:
            return bool;
        case String:
        case StrLit:
            return string;
        default:
            return undef;

    }
}

char *category_to_operator(enum category cat){
    switch(cat){
        case Or:
            return "||";
        case And:
            return "&&";
        case Eq:
            return "==";
        case Ne:
            return "!=";
        case Lt:
            return "<";
        case Gt:
            return ">";
        case Le:
            return "<=";
        case Ge:
            return ">=";
        case Add:
            return "+";
        case Sub:
            return "-";
        case Mul:
            return "*";
        case Div:
            return "/";
        case Mod:
            return "%";
        case Not:
            return "!";
        case Minus:
            return "-";
        case Plus:
            return "+";
        default:
            return "";
    }
}

void add_error(char *message) {
    error_messages[error_count++] = strdup(message);
}

int compare_errors(const void *a, const void *b) {
    char *error_a = *(char **)a;
    char *error_b = *(char **)b;
    return strcmp(error_a, error_b);
}

void sort_and_print_errors() {
    qsort(error_messages, error_count, sizeof(char *), compare_errors);
    for (int i = 0; i < error_count; i++) {
        printf("%s", error_messages[i]);
        free(error_messages[i]);
    }
}

int check_program(struct node *program){
    if(program == NULL){
        return 0;
    }

    // Initialize the global symbol table
    symbol_table = (struct symbol_list *) malloc(sizeof(struct symbol_list));
    symbol_table->identifier = "global";
    symbol_table->next = NULL;

    // Initialize the local scopes
    symbol_scopes = NULL; // Initialize to NULL

    struct node_list *cur_child = program->children;

    while((cur_child = cur_child->next) != NULL){
        struct node *cur_node = cur_child->node;
        enum category cur_category = cur_node->category;
        if(cur_category == VarDecl){
            check_var_decl(cur_node, symbol_table);
        }
        if(cur_category == FuncDecl){
            check_func_decl(cur_node);
        }
    }

    // Start checking the function bodies
    struct scopes_queue *cur_scope = symbol_scopes;
    while (cur_scope != NULL) {
        check_func_body(cur_scope->func_body, cur_scope->table);
        cur_scope = cur_scope->next;
    }

    check_unused_symbols();
    sort_and_print_errors();
    return semantic_errors;
}

// ============================================================================
// IMPLEMENTAÇÕES DAS FUNÇÕES DE VERIFICAÇÃO SEMÂNTICA
// ============================================================================

// Obter n-ésimo filho (helper - já deve estar em ast.c, mas por precaução)
struct node *get_child_semantic(struct node *parent, int position) {
    if(parent == NULL || parent->children == NULL) return NULL;
    struct node_list *cur = parent->children->next;
    int i = 0;
    while(cur != NULL) {
        if(i == position) return cur->node;
        cur = cur->next;
        i++;
    }
    return NULL;
}

// ============================================================================
// CHECK_VAR_DECL - Verificar declaração de variáveis
// ============================================================================
void check_var_decl(struct node *var_decl, struct symbol_list *scope) {
    if (var_decl == NULL || scope == NULL) return;

    // 1º filho: tipo (Int, Float32, Bool, String)
    struct node *type_node = get_child_semantic(var_decl, 0);
    if (type_node == NULL) return;

    enum type var_type = category_to_type(type_node->category);
    
    // Percorrer identificadores (a partir do 1º filho)
    struct node_list *child = var_decl->children->next;
    
    while (child != NULL) {
        struct node *id_node = child->node;
        
        if (id_node->category == Identifier) {
            char *var_name = id_node->token;
            
            // Verificar se já existe na tabela atual
            struct symbol_list *existing = scope->next;
            while (existing != NULL) {
                if (strcmp(existing->identifier, var_name) == 0) {
                    char error_msg[MAX_ERROR_SIZE];
                    snprintf(error_msg, MAX_ERROR_SIZE,
                             "Line %d, column %d: Symbol %s already defined\n",
                             id_node->token_line, id_node->token_column, var_name);
                    add_error(error_msg);
                    semantic_errors = 1;
                    goto skip_insert;
                }
                existing = existing->next;
            }
            
            // Inserir símbolo
            insert_symbol(scope, var_name, var_type, id_node, 0, 0, 0);
            
            skip_insert:
            id_node->type = var_type;
        }
        child = child->next;
    }
}

// ============================================================================
// CHECK_PARAMETERS - Processar parâmetros da função
// ============================================================================
char* check_parameters(struct node *func_params, struct symbol_list *scope) {
    if (func_params == NULL) return strdup("()");
    
    char param_str[1024] = "(";
    int first = 1;
    
    struct node_list *child = func_params->children->next;
    while (child != NULL) {
        struct node *param_decl = child->node;
        
        if (param_decl->category == ParamDecl) {
            // ParamDecl tem: Type + Identifier
            struct node *type_node = get_child_semantic(param_decl, 0);
            struct node *id_node = get_child_semantic(param_decl, 1);
            
            if (type_node != NULL && id_node != NULL) {
                enum type param_type = category_to_type(type_node->category);
                
                // Adicionar à string de parâmetros
                if (!first) strcat(param_str, ",");
                strcat(param_str, type_name_stat[param_type]);
                first = 0;
                
                // Verificar duplicados
                struct symbol_list *existing = scope->next;
                while (existing != NULL) {
                    if (strcmp(existing->identifier, id_node->token) == 0) {
                        char error_msg[MAX_ERROR_SIZE];
                        snprintf(error_msg, MAX_ERROR_SIZE,
                                 "Line %d, column %d: Symbol %s already defined\n",
                                 id_node->token_line, id_node->token_column, 
                                 id_node->token);
                        add_error(error_msg);
                        semantic_errors = 1;
                        goto skip_param;
                    }
                    existing = existing->next;
                }
                
                // Inserir parâmetro na tabela local
                insert_symbol(scope, id_node->token, param_type, id_node, 1, 0, 0);
                
                skip_param:
                id_node->type = param_type;
            }
        }
        child = child->next;
    }
    
    strcat(param_str, ")");
    return strdup(param_str);
}

// ============================================================================
// CHECK_FUNC_DECL - Verificar declaração de função
// ============================================================================
void check_func_decl(struct node *func_decl) {
    if (func_decl == NULL) return;

    struct node *header = get_child_semantic(func_decl, 0);
    struct node *body = get_child_semantic(func_decl, 1);
    
    if (header == NULL) return;

    struct node *func_name_node = get_child_semantic(header, 0);
    if (func_name_node == NULL || func_name_node->category != Identifier) return;
    
    char *func_name = func_name_node->token;

    // Determinar tipo de retorno e nó de parâmetros
    enum type return_type = none;
    struct node *params_node = NULL;
    
    int header_children_count = 0;
    struct node_list *hc = header->children->next;
    while (hc != NULL) {
        header_children_count++;
        hc = hc->next;
    }
    
    if (header_children_count == 2) {
        params_node = get_child_semantic(header, 1);
    } else if (header_children_count == 3) {
        struct node *type_node = get_child_semantic(header, 1);
        return_type = category_to_type(type_node->category);
        params_node = get_child_semantic(header, 2);
    }

    // Verificar duplicados na tabela global
    struct symbol_list *existing = symbol_table->next;
    while (existing != NULL) {
        if (strcmp(existing->identifier, func_name) == 0) {
            char error_msg[MAX_ERROR_SIZE];
            snprintf(error_msg, MAX_ERROR_SIZE,
                     "Line %d, column %d: Symbol %s already defined\n",
                     func_name_node->token_line, func_name_node->token_column, 
                     func_name);
            add_error(error_msg);
            semantic_errors = 1;
            return;
        }
        existing = existing->next;
    }

    // Criar tabela local
    struct symbol_list *local_table = (struct symbol_list *) malloc(sizeof(struct symbol_list));
    local_table->identifier = strdup(func_name);
    local_table->next = NULL;

    char *param_types_str = check_parameters(params_node, local_table);

    // Inserir função na tabela global
    insert_symbol(symbol_table, func_name, return_type, func_name_node, 0, 1, 1);
    
    struct symbol_list *func_symbol = symbol_table->next;
    while (func_symbol != NULL) {
        if (strcmp(func_symbol->identifier, func_name) == 0) {
            func_symbol->function_parameters = param_types_str;
            break;
        }
        func_symbol = func_symbol->next;
    }

    // Inserir "return"
    insert_symbol(local_table, "return", return_type, NULL, 0, 1, 0);

    // Adicionar scope
    struct scopes_queue *new_scope = (struct scopes_queue *) malloc(sizeof(struct scopes_queue));
    new_scope->table = local_table;
    new_scope->func_body = body;
    new_scope->identifier = strdup(func_name);
    new_scope->next = NULL;

    if (symbol_scopes == NULL) {
        symbol_scopes = new_scope;
    } else {
        struct scopes_queue *last = symbol_scopes;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = new_scope;
    }
}

// ============================================================================
// CHECK_FUNC_BODY - Processar corpo da função (STUB por agora)
// ============================================================================
void check_func_body(struct node *func_body, struct symbol_list *scope) {
    if (func_body == NULL || scope == NULL) return;
    
    // TODO: Processar statements dentro do body
    // Por agora, apenas evita erro de linkagem
    (void)scope; // Evitar warning
}

// ============================================================================
// CHECK_UNUSED_SYMBOLS - Verificar símbolos não usados (STUB)
// ============================================================================
void check_unused_symbols() {
    // TODO: Implementar verificação de símbolos não usados
    // Por agora, apenas evita erro de linkagem
}

// ============================================================================
// INSERT_SYMBOL - Inserir símbolo na tabela
// ============================================================================
struct symbol_list *insert_symbol(struct symbol_list *symbol_table, 
                                  char *identifier, 
                                  enum type type, 
                                  struct node *node, 
                                  int is_parameter, 
                                  int mark_as_used, 
                                  int is_function) {
    struct symbol_list *new_symbol = (struct symbol_list *) malloc(sizeof(struct symbol_list));
    new_symbol->identifier = strdup(identifier);
    new_symbol->type = type;
    new_symbol->node = node;
    new_symbol->is_parameter = is_parameter;
    new_symbol->was_used = mark_as_used;
    new_symbol->is_function = is_function;
    new_symbol->function_parameters = NULL;
    new_symbol->next = NULL;

    // Inserir no final
    struct symbol_list *current = symbol_table;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_symbol;

    return new_symbol;
}