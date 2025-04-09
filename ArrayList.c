#include "ArrayList.h"
#include <stdio.h>
#include <string.h>

// Variáveis
int posicao = 0;
Pessoa *lista = NULL;
int tamanho = 5;


// Funções
void input(char *field, size_t size) {
    char temp[size];
    if (fgets(temp, size, stdin)) {
        // Remove o '\n' da string, se houver
        temp[strcspn(temp, "\n")] = 0;

        // Se o usuário não digitou nada, não altera o campo
        if (temp[0] != '\0') {
            strncpy(field, temp, size);
        }
    }
}

bool add(Pessoa p) {
    // Verifica se o CPF já está cadastrado
    Pessoa pessoaTemp;
    if (searchByCpf(p.cpf, &pessoaTemp)) {
        printf("CPF %s já cadastrado.\n", p.cpf);
        return false;
    }

    if (posicao == tamanho) {
        expand();
    }
    lista[posicao] = p;
    posicao++;
    return true;
}

bool searchByCpf(const char *cpf, Pessoa *p) {
    for (int i = 0; i < posicao; i++) {
        if (strcmp(lista[i].cpf, cpf) == 0) {
            *p = lista[i];  // Encontrou, copia para p
            return true;  // CPF encontrado
        }
    }
    return false;  // CPF não encontrado
}

void delete(const char *cpf) {
    int i;
    Pessoa pessoaTemp;
    if (!searchByCpf(cpf, &pessoaTemp)) {
        return; // CPF não encontrado
    }

    for (i = 0; i < posicao; i++) {
        if (strcmp(lista[i].cpf, cpf) == 0) {
            break;
        }
    }

    for (; i < posicao - 1; i++) {
        lista[i] = lista[i + 1];
    }
    posicao--;
}

void sort() {
    for (int i = 0; i < posicao - 1; i++) {
        for (int j = i + 1; j < posicao; j++) {
            if (strcmp(lista[i].nome, lista[j].nome) > 0) {
                Pessoa temp = lista[i];
                lista[i] = lista[j];
                lista[j] = temp;
            }
        }
    }
}

bool set(const char *cpf, Pessoa p) {
    for (int i = 0; i < posicao; i++) {
        if (strcmp(lista[i].cpf, cpf) == 0) {
            lista[i] = p;
            return true;
        }
    }
    return false;
}

void init() {
    lista = malloc(sizeof(Pessoa) * tamanho);
    if (!lista) {
        printf("Erro ao alocar memoria\n");
        exit(EXIT_FAILURE);
    }
}

void destroy() {
    free(lista);
}

void expand() {
    int novoTamanho = tamanho + 5;
    Pessoa *aux = malloc(sizeof(Pessoa) * novoTamanho);
    if (!aux) {
        printf("Erro ao alocar memoria\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < tamanho; i++) {
        aux[i] = lista[i];
    }

    free(lista);
    lista = aux;
    tamanho = novoTamanho;
}
int size() {
    return posicao;
}