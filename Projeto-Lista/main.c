#include <stdio.h>
#include <string.h>
#include "ArrayList.h"

//Kaique Santos de Carvalho
//Rogério de Lima Rodrigues

// Contantes
enum {
    OP_NAO_SELECIONADA = 0,
    OP_ADD,
    OP_DELETE,
    OP_SET,
    OP_IMPRIMIR,
    OP_IMPRIMIR_TODOS,
    OP_SORT,
    OP_SAIR
};

// Protótipos
int menu();
void imprimirPessoa(Pessoa p);
void imprimirTodos();


int main(void) {
    int opcao = OP_NAO_SELECIONADA;
    char cpf[12];
    Pessoa p;

    init();

    while (opcao != OP_SAIR) {
        opcao = menu();
        switch (opcao) {
            case OP_ADD:
                printf("Insira o CPF: ");
                scanf("%s", p.cpf);
                printf("Insira o nome: ");
                getchar();
                fgets(p.nome, sizeof(p.nome), stdin);
                p.nome[strcspn(p.nome, "\n")] = 0;
                printf("Insira o endereco: ");
                fgets(p.endereco, sizeof(p.endereco), stdin);
                p.endereco[strcspn(p.endereco, "\n")] = 0;
                printf("Insira o telefone: ");
                fgets(p.telefone, sizeof(p.telefone), stdin);
                p.telefone[strcspn(p.telefone, "\n")] = 0;
                printf("Insira o email: ");
                fgets(p.email, sizeof(p.email), stdin);
                p.email[strcspn(p.email, "\n")] = 0;

                add(p);
                break;
            case OP_DELETE:
                printf("Insira o CPF para excluir: ");
                scanf("%s", cpf);
                delete(cpf);
                break;
            case OP_SORT:
                sort();
                break;
            case OP_SET:
                printf("Insira o CPF para alterar: ");
                scanf("%s", cpf);
                if (searchByCpf(cpf, &p)) {
                    printf("Alterando os dados para o CPF %s\n", cpf);
                    printf("Insira o novo nome (deixe em branco para manter o anterior): ");
                    getchar();
                    input(p.nome, sizeof(p.nome));

                    printf("Insira o novo endereco (deixe em branco para manter o anterior): ");
                    input(p.endereco, sizeof(p.endereco));

                    printf("Insira o novo telefone (deixe em branco para manter o anterior): ");
                    input(p.telefone, sizeof(p.telefone));

                    printf("Insira o novo email (deixe em branco para manter o anterior): ");
                    input(p.email, sizeof(p.email));

                    set(cpf, p);
                } else {
                    printf("CPF nao cadastrado.\n");
                }
            break;
            case OP_IMPRIMIR:
                printf("Insira o CPF para imprimir: ");
                scanf("%s", cpf);
                if (searchByCpf(cpf, &p)) {
                    imprimirPessoa(p);
                } else {
                    printf("CPF nao cadastrado.\n");
                }
                break;
            case OP_IMPRIMIR_TODOS:
                imprimirTodos();
                break;
            case OP_SAIR:
                break;
            default:
                printf("Opcao invalida!\n");
        }
    }

    destroy();
    return 0;
}

int menu() {
    int op = OP_NAO_SELECIONADA;
    printf("Menu\n");
    printf("%d - Adicionar\n", OP_ADD);
    printf("%d - Excluir\n", OP_DELETE);
    printf("%d - Alterar\n", OP_SET);
    printf("%d - Imprimir\n", OP_IMPRIMIR);
    printf("%d - Imprimir Todos\n", OP_IMPRIMIR_TODOS);
    printf("%d - Ordenar\n", OP_SORT);
    printf("%d - Sair\n", OP_SAIR);
    printf("Insira a opcao: ");
    scanf("%d", &op);
    return op;
}

void imprimirPessoa(Pessoa p) {
    printf("Nome: %s\n", p.nome);
    printf("Endereco: %s\n", p.endereco);
    printf("CPF: %s\n", p.cpf);
    printf("Telefone: %s\n", p.telefone);
    printf("Email: %s\n", p.email);
}

void imprimirTodos() {
    if (size() == 0) {
        printf("Nao ha registros.\n");
        return;
    }

    for (int i = 0; i < size(); i++) {
        imprimirPessoa(lista[i]);
        printf("\n");
    }
}
