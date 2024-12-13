#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ast.h"

// Cria um novo nó com os atributos fornecidos
struct node *newNode(char *valor, char *token) {
    struct node *new = malloc(sizeof(struct node));
    if (new == NULL) {
        return NULL; // Falha na alocação de memória
    }
    new->root = NULL;

    // Alocar memória para os valores de string
    new->valor = valor ? strdup(valor) : NULL;
    new->token = token ? strdup(token) : NULL;

    new->children = NULL;
    new->sibling = NULL;

    return new;
}

// Adiciona um filho a um nó pai
void addchild(struct node *parent, struct node *child) {
    if (parent == NULL || child == NULL) {
        return; // Ignorar se qualquer um for NULL
    }

    struct node_list *new_child = malloc(sizeof(struct node_list));
    if (new_child == NULL) {
        return; // Falha na alocação de memória
    }
    new_child->node = child;
    new_child->next = NULL;

    if (parent->children == NULL) {
        parent->children = new_child;
    } else {
        struct node_list *current = parent->children;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_child;
    }
}

// Adiciona um nó irmão a outro nó
void addsiblings(struct node *parent, struct node *sibling) {
    if (parent == NULL || sibling == NULL) {
        return; // Ignorar se qualquer um for NULL
    }

    struct node *current = parent;
    while (current->sibling != NULL) {
        current = current->sibling;
    }
    current->sibling = sibling;
}

// Imprime a árvore em formato hierárquico
void printtree(struct node *root, int level) {
    if (root == NULL) {
        return;
    }

    // Print the current node with indentation based on its level in the tree
    for (int i = 0; i < level; i++) {
        printf("  "); // Two spaces for each level of indentation
    }

    if (root->valor) {
        printf("%s(%s)\n", root->token, root->valor); // Print token and valor if available
    } else {
        printf("%s\n", root->token); // Print only token if valor is NULL
    }

    // Traverse and print all children
    struct node_list *current_child = root->children;
    while (current_child != NULL && current_child->node != NULL) {
        printtree(current_child->node, level + 1); // Recursive call with increased indentation
        current_child = current_child->next;
    }
}

// Libera a memória alocada para a árvore
void freetree(struct node *root) {
    if (root == NULL) {
        return;
    }

    struct node_list *child = root->children;
    while (child != NULL) {
        struct node_list *next = child->next;
        freetree(child->node);
        free(child);
        child = next;
    }

    free(root->valor);
    free(root->token);
    free(root);
}
