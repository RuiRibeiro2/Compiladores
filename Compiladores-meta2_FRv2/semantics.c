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

// (rest of semantics.c is identical to TrabalhoNuno version)
