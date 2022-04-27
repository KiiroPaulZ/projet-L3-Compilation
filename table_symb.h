#ifndef _INTERFACE_H
#define _INTERFACE_H
//#define TAILLE 103
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define BUFFER_SIZE 200

int pos;

typedef enum { INT_, VOID_, STRUCT_ } type_t;

typedef enum { FONCTION_, VARIABLE_, STRUCTURE_} ts_type;

typedef struct _param_t {
    type_t type;
    char *nom;
} param_t;

typedef struct _symbole_t{
    char *nom;
    bool isPtr;
    type_t type;
    int taille;
    int position;
    struct _symbole_t *suivant;
}symbole_t;

typedef struct _table_t {
    symbole_t *symbole;
    struct _table_t *preced;
}table_t;

table_t *pile;

table_t *nouvelle_table();
void push(table_t * t);

table_t ** top();
symbole_t *rechercher(symbole_t * list, char * name);
symbole_t *ajouter(symbole_t ** list, char *nom);

table_t * pop();
void detruire_table(table_t ** list);
void print_table();
#endif