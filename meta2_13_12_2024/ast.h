/*
    Projeto de Compiladores 2023/2024~
    Meta 2
    2021189478 - Rui Ribeiro
    2021221169 - Francisco Rodrigues
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#ifndef _AST_H
#define _AST_H

//enum category { Program, Function, Parameters, Parameter, Arguments, Integer, Double, Identifier, Natural, Decimal, Call, If, Add, Sub, Mul, Div };

typedef struct node {
    struct node *root;
    char *valor;
    char *token;
    int line;
    int col;
    struct node_list *children;
    struct node *sibling;
} node;
//Não usamos o line e column está a dar problemas

struct node_list {
    struct node *node;
    struct node_list *next;
};

struct node *newNode(char *valor, char *token);
void addchild(struct node *parent, struct node *child);
void addsiblings(struct node *parent, struct node *child);
void printtree(struct node *current_node, int level);
void freetree(struct node *root);

#endif
