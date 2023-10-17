#include <stdio.h>

typedef struct {
  char nome[101];
  char cpf[50];
  char tipo_conta[50];
  float saldo;
  char senha[101];
} cliente;

typedef struct {
  cliente cliente[1000];
  int qtnd;
} lista_clientes;

typedef struct {
  char operacao[13];
  float valor;
} dados_extrato;

typedef struct {
  dados_extrato extrato[100];
  int qtnd;
} operacoes;

void menu(int *opcao);

void novo_cliente(lista_clientes *lc, operacoes *op);

void deposito(lista_clientes *lc, operacoes *op);

void extrato(lista_clientes *lc, operacoes *op);