#include <stdio.h>

typedef struct {
  char nome[101];
  char cpf[12];
  char tipo_conta[2];
  float saldo;
  char senha[101];
} cliente;

typedef struct {
  cliente cliente[100];
  int qtnd;
} lista_clientes;

void menu(int *opcao);

void novo_cliente(lista_clientes *lc);

void listar_clientes(lista_clientes *lc);
