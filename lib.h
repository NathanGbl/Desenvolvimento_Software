#include <stdio.h>

typedef struct {
  char nome[101];
  char cpf[50];
  char tipo_conta[50];
  float saldo;
  char senha[101];
  dados_extrato extrato[100];
  int qtnd;
} cliente; 

typedef struct {
  cliente cliente[1000];
  int qtnd;
} lista_clientes; 

void menu(int *opcao, int *cont);

void novo_cliente(lista_clientes *lc);

void apagar_cliente(lista_clientes *lc);

void apaga_extrato(lista_clientes *lc, int pos);

