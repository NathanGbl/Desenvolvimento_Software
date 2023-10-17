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
  char cpf[50];
  char tipo_conta[50];
  float saldo;
  char senha[101];
  
  int tamanho_cpf = 0;
  int tamanho_tipo_conta = 0;
  
  printf("\tDigite o nome do cliente: ");
  scanf("%s", nome);
  printf("\n");
  
  printf("\tDigite CPF: ");
  scanf("%s", cpf);
  printf("\n");
  
  printf("\tDigite o tipo de conta (c para comum ou p para plus): ");
  scanf("%s", tipo_conta);
  printf("\n");

  printf("\tDigite o saldo inicial da conta: ");
  scanf("%f", &saldo);
  printf("\n");

  printf("\tDigite a senha da conta: ");
  scanf("%s", senha);
  printf("\n");

  tamanho_cpf = strlen(cpf);
  tamanho_tipo_conta = strlen(tipo_conta);

  if (tamanho_cpf != 11 || tamanho_tipo_conta != 1 ) {
    printf("\tCPF e/ou tipo de conta inválidos.\n\n");
  }
  else {
    strcpy(cliente.nome, nome);
    strcpy(cliente.cpf, cpf);
    strcpy(cliente.tipo_conta, tipo_conta);
    cliente.saldo = saldo;
    strcpy(cliente.senha, senha);

    lc->cliente[lc->qtnd] = cliente;
    lc->qtnd += 1;

    printf("\tDados cadastrados com sucesso!\n\n");
  }
  
}

void apagar_cliente(lista_clientes *lc) {
  
  char cpf_apagado[50];
  int x = 0;
  int find = 0;

  printf("CPF a ser apagado: ");
  scanf("%s", cpf_apagado);

  for (; x < lc->qtnd; x++) {
    if (strcmp(lc->cliente[x].cpf, cpf_apagado) == 0) {
      for (; x < lc->qtnd; x++) {
        strcpy(lc->cliente[x].nome, lc->cliente[x + 1].nome);
        strcpy(lc->cliente[x].cpf, lc->cliente[x + 1].cpf);
        strcpy(lc->cliente[x].tipo_conta, lc->cliente[x + 1].tipo_conta);
        lc->cliente[x].saldo = lc->cliente[x + 1].saldo;
        strcpy(lc->cliente[x].senha, lc->cliente[x + 1].senha);
      }
      find = 1;
      lc->qtnd -= 1;
      printf("\tCliente apagado com sucesso!\n\n");
    }
    break;
  }
  if (find == 0) {
    printf("\tCPF incorreto!\n\n");
  }
}

