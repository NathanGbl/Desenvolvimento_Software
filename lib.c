#include <stdio.h>
#include <string.h>
#include "lib.h"

void menu(int *opcao) {
  
  printf("Bem vindo ao banco QuemPoupaTem!\n");
  printf("Escolha uma das opções abaixo:\n");
  printf("1. Novo cliente\n");
  printf("2. Apagar cliente\n");
  printf("3. Listar clientes\n");
  printf("4. Débito\n");
  printf("5. Depósito\n");
  printf("6. Extrato\n");
  printf("7. Transferência entre contas\n");
  printf("0. Sair\n");
  printf("Opção: ");
  scanf("%d", opcao);
  
}

void novo_cliente(lista_clientes *lc) {

  cliente cliente;
  char nome[101];
  char cpf[12];
  char tipo_conta[2];
  float saldo = 0;
  char senha[50];
  
  int tamanho_cpf = 0;
  int tamanho_tipo_conta = 0;
  
  printf("\tDigite o nome do cliente: ");
  scanf("%c", nome);
  printf("\n");
  
  printf("\tDigite CPF: ");
  scanf("%c", cpf);
  printf("\n");
  
  printf("\tDigite o tipo de conta (c para comum ou p para plus): ");
  scanf(" %c", tipo_conta);
  printf("\n");

  printf("\tDigite o saldo inicial da conta: ");
  scanf("%f", saldo);
  printf("\n");

  printf("\tDigite a senha da conta: ");
  scanf("%c", senha);
  printf("\n");

  for (int x; cpf[x] != '\0'; x++) {
    tamanho_cpf++;
  }

  for (int x; tipo_conta[x] != '\0'; x++) {
    tamanho_tipo_conta++;
  }

  if (tamanho_cpf != 11 || tamanho_tipo_conta != 2 ) {
    printf("\tDados inválidos.");
  }

  strcpy(cliente.nome, nome);
  strcpy(cliente.cpf, cpf);
  strcpy(cliente.tipo_conta, tipo_conta);
  cliente.saldo = saldo;
  strcpy(cliente.senha, senha);

  lc->cliente[lc->qtnd] = cliente;
  lc->qtnd += 1;

  printf("\tDados cadastrados com sucesso!");
  
}

void listar_clientes(lista_clientes *lc) {

  for (int x; x < lc->qtnd; x++) {
    printf("\tNome: %s", lc->cliente[x].nome);
    printf("\tCPF: %s", lc->cliente[x].cpf);
    printf("\tTipo de conta: %s", lc->cliente[x].tipo_conta);
    printf("\tSaldo: %f", lc->cliente[x].saldo);
    printf("\tSenha: %s", lc->cliente[x].senha);
  }
}