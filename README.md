# 📂 Projeto de Estrutura de Dados - Lista em C

Este é um projeto acadêmico desenvolvido para a disciplina de Estrutura de Dados. O objetivo é implementar uma **lista baseada em vetores** utilizando a linguagem C, simulando um sistema de gerenciamento de registros similar a um arquivo em disco.

## 🧠 Funcionalidades

O sistema permite realizar as seguintes operações com os dados de pessoas:

- 👤 **Adicionar**: Insere um novo registro na lista, garantindo unicidade do CPF.
- ❌ **Excluir**: Remove um registro existente baseado no CPF.
- ✏️ **Alterar**: Permite alterar os dados de um registro existente.
- 🧾 **Imprimir**: Exibe os dados de um registro específico pelo CPF.
- 📋 **Imprimir todos**: Lista todos os registros cadastrados.
- 🔃 **Ordenar**: Ordena os registros por **Nome**.
- 🚪 **Sair**: Encerra o programa.

## 📌 Estrutura dos Dados

Cada elemento da lista possui os seguintes campos:

- **Nome**
- **Endereço**
- **CPF** (Chave de busca)
- **Telefone**
- **E-mail**

> ❗ O sistema impede o cadastro de CPFs duplicados.

## 🧭 Menu do Programa

1- Adicionar

2- Excluir

3- Alterar

4- Imprimir

5- Imprimir todos

6- Ordenar

7- Sair


## 💡 Regras de Negócio

- **Adicionar**: Verifica se o CPF já existe antes de inserir. Se sim, exibe "CPF já cadastrado".
- **Excluir**: Solicita o CPF e remove o registro, caso exista. Caso contrário, não exibe mensagens.
- **Alterar**: Solicita o CPF e permite editar os campos. Se o campo não for alterado, basta pressionar `<ENTER>`. Exibe "CPF não cadastrado" se não for encontrado.
- **Imprimir**: Exibe os dados completos de um CPF específico, se existente.
- **Ordenar**: Ordena os registros pelo campo **Nome**.

## 🛠️ Tecnologias

- Linguagem: **C**

##
Projeto desenvolvido com fins educacionais.
Sinta-se livre para contribuir ou sugerir melhorias!
