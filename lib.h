#include <stdio.h>

typedef struct {
  char operacao[13];
  float valor;
} dados_extrato; // Criação do struct com os dados para cada movimentação de dinheiro dentro da conta.

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
  cliente cliente[10];
  int qtnd;
} lista_clientes; // Criação do struct com a lista de todos os structs de cada cliente.

void menu(int *opcao, int *cont);

void novo_cliente(lista_clientes *lc);

void transf(lista_clientes *lc);
