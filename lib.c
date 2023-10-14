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
  scanf("");
  
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
  scanf(" %s", tipo_conta);
  printf("\n");

  printf("\tDigite o saldo inicial da conta: ");
  scanf("%f", &saldo);
  printf("\n");

  printf("\tDigite a senha da conta: ");
  scanf("%s", senha);
  printf("\n");

  // for (int x; cpf[x] != '\0'; x++) {
  //   tamanho_cpf++;
  // }

  // for (int x; tipo_conta[x] != '\0'; x++) {
  //   tamanho_tipo_conta++;
  // }

  // if (tamanho_cpf != 11 || tamanho_tipo_conta != 2 ) {
  //   printf("\tDados inválidos.");
  // }

  strcpy(cliente.nome, nome);
  strcpy(cliente.cpf, cpf);
  strcpy(cliente.tipo_conta, tipo_conta);
  cliente.saldo = saldo;
  strcpy(cliente.senha, senha);

  lc->cliente[lc->qtnd] = cliente;
  lc->qtnd += 1;

  printf("\tDados cadastrados com sucesso!");
  
}

void apagar_cliente(lista_clientes *lc) {
  
  char cpf_apagado[12];
  scanf("%c", cpf_apagado);

  for (int x; x < lc->qtnd; x++) {
    if (strcmp(lc->cliente[x].cpf, cpf_apagado) == 0) {
      for (; x < lc->qtnd; x++) {
        strcpy(lc->cliente[x].nome, lc->cliente[x + 1].nome);
        strcpy(lc->cliente[x].cpf, lc->cliente[x + 1].cpf);
        strcpy(lc->cliente[x].tipo_conta, lc->cliente[x + 1].tipo_conta);
        lc->cliente[x].saldo = lc->cliente[x + 1].saldo;
        strcpy(lc->cliente[x].senha, lc->cliente[x + 1].senha);
      }
      lc->qtnd -= 1;
    }
    break;
  }
  printf("\tCliente apagado com sucesso!");
  
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