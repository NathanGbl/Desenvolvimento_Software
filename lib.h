#include <stdio.h>

typedef struct {
  char nome[101];
  char cpf[12];
  char tipo_conta[6];
  float valor_inicial;
  char senha[101];
} cliente;

typedef struct {
  cliente cliente[100];
  int qtnd;
} lista_clientes;

int menu();

void novo_cliente();