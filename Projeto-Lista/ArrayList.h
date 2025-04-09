#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// Definindo o tamanho máximo dos campos
#define MAX_NOME 100
#define MAX_ENDERECO 200
#define MAX_EMAIL 100
#define MAX_TELEFONE 15


typedef struct {
    char nome[MAX_NOME];
    char endereco[MAX_ENDERECO];
    char cpf[12];
    char telefone[MAX_TELEFONE];
    char email[MAX_EMAIL];
} Pessoa;

// Variáveis
extern int posicao;
extern Pessoa *lista;
extern int tamanho;

// Protótipos
void init();
bool add(Pessoa p);
bool searchByCpf(const char *cpf, Pessoa *p);
int size();
void delete(const char *cpf);
void sort();
bool set(const char *cpf, Pessoa p);
void expand();
void destroy();
void input(char *field, size_t size);


#endif //ARRAYLIST_H
