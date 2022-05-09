#ifndef AULA
#define AULA

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTAM 100

typedef struct Bloco Bloco;
typedef struct Item{
    char value[100];
    int cont;
}Item;

struct Bloco{
    Item dado;
    Bloco *prox;
};

typedef struct Lista{
    Bloco* cabeca;
    Bloco* cauda;
}Lista;

int tamanhoLista;

void FLVazia(Lista *l);
void preencheLista(Lista *l,char f[80], bool novo);
void insertLista(Lista *l);
void removeListaItem(Lista *l);
void removeRepet(Lista *l);
void showRepet(Lista *l);
void printLista(Lista *l);
void preencheArquivo(FILE* arq);
void atualizaArquivo(Lista *l,char nomearquvio[80]);
#endif