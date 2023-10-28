#include <stdio.h>

typedef struct {
  char nome[101];
  char cpf[50];
  char tipo_conta[50];
  float saldo;
  char senha[101];
  dados_extrato extrato[100];
  int qtnd;
} cliente; // Criação do struct responsável por armazenar as informações do cliente.

typedef struct {
  cliente cliente[1000];
  int qtnd;
} lista_clientes; // Criação do struct com a lista de todos os structs de cada cliente.

void menu(int *opcao, int *cont);

void novo_cliente(lista_clientes *lc);

void listar_clientes(lista_clientes *lc);