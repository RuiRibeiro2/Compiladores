#include <stdlib.h>
#include <stdio.h>
#include "ast.h"

// create a node of a given category with a given lexical symbol, line, and column
struct node *newnode(char *valor, char *token, int line, int col) {
    struct node *new = malloc(sizeof(struct node));
    if (new == NULL) {
        return NULL; // handle memory allocation failure
    }
    new->root = NULL;
    new->valor = valor;
    new->token = token;
    new->line = line;
    new->col = col;
    new->sibling = NULL;  // Initialize sibling pointer to NULL

    // Initialize children list
    new->children = malloc(sizeof(struct node_list));
    if (new->children == NULL) {
        free(new);
        return NULL;
    }
    new->children->node = NULL;
    new->children->next = NULL;

    return new;
}

// Add a child node to the parent
void addchild(struct node *parent, struct node *child) {
    if (parent == NULL || child == NULL) {
        return; // Do nothing if either the parent or child is NULL
    }
    
    if (parent->children == NULL) {
        // If parent has no children, initialize the children list
        parent->children = malloc(sizeof(struct node_list));
        if (parent->children == NULL) {
            return; // handle memory allocation failure
        }
        parent->children->node = child;
        parent->children->next = NULL;
    } else {
        // Otherwise, traverse to the end of the sibling list of the first child
        struct node *current_child = parent->children->node;
        while (current_child->sibling != NULL) {
            current_child = current_child->sibling;
        }
        current_child->sibling = child; // Add the new child as a sibling of the last child
    }
}

void printtree(struct node *root, int level) {
    if (root == NULL) {
        return;
    }

    // Print the current node with indentation based on its level in the tree
    for (int i = 0; i < level; i++) {
        printf("  "); // Two spaces for each level of indentation
    }

    if (root->valor != NULL) {
        printf("%s(%s)\n", root->token, root->valor); // Print token and valor if available
    } else {
        printf("%s\n", root->token); // Print only token if valor is NULL
    }

    // Traverse and print all children
    struct node_list *children = root->children;
    while (children != NULL) {
        printtree(children->node, level + 1); // Recursive call with increased indentation
        children = children->next;
    }
}


//void freetree(struct node *root);
void freetree(struct node *root) {
    if(root == NULL)
        return;
    struct node_list *children = root->children;
    while(children != NULL) {
        freetree(children->node);
        struct node_list *next = children->next;
        free(children);
        children = next;
    }
    free(root);
}