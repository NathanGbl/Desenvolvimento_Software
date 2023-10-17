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

void menu(int *opcao);

void novo_cliente(lista_clientes *lc);



void debito(lista_clientes *lc);

