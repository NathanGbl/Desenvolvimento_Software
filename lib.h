#include <stdio.h>

typedef struct {
  char nome[101];
  char cpf[50];
  char tipo_conta[50];
  float saldo;
  char senha[101];
  int qtnd;
} cliente;

typedef struct {
  cliente cliente[10];
  int qtnd;
} lista_clientes;

void menu(int *opcao, int *cont);

void novo_cliente(lista_clientes *lc);