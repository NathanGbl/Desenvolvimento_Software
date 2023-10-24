#include <stdio.h>

typedef struct {
  char operacao[13];
  float valor;
} dados_extrato;

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
  cliente cliente[10];
  int qtnd;
} lista_clientes;

void menu(int *opcao);

void novo_cliente(lista_clientes *lc);

void apagar_cliente(lista_clientes *lc);

void listar_clientes(lista_clientes *lc);

void debito(lista_clientes *lc);

void deposito(lista_clientes *lc);

void extrato(lista_clientes *lc);

void cria_arquivo(char *nome, FILE *f, char cpf[12]);

void apaga_extrato(lista_clientes *lc, int pos);

void transf(lista_clientes *lc);

void salva_bin(lista_clientes *lc);

void le_bin(lista_clientes *lc);

void cria_bin();

int menu2();