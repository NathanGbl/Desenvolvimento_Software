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

void novo_cliente(lista_clientes *lc, operacoes *op) {

  cliente cliente;
  dados_extrato dados_extrato;
  char nome[101];
  char cpf[50];
  char tipo_conta[50];
  float saldo;
  char senha[101];
  
  int tamanho_cpf = 0;
  int tamanho_tipo_conta = 0;
  
  printf("\n\tDigite o nome do cliente: ");
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

  // if (tamanho_cpf != 11 || tamanho_tipo_conta != 1 ) {
  //   printf("\tCPF e/ou tipo de conta inválidos.\n\n");
  // }
  // else {
    strcpy(cliente.nome, nome);
    strcpy(cliente.cpf, cpf);
    strcpy(cliente.tipo_conta, tipo_conta);
    cliente.saldo = saldo;
    strcpy(cliente.senha, senha);

    lc->cliente[lc->qtnd] = cliente;
    lc->qtnd += 1;

    strcpy(dados_extrato.operacao, "0");
    dados_extrato.valor = 0;

    op->extrato[op->qtnd] = dados_extrato;
  
    printf("\tDados cadastrados com sucesso!\n\n");
  // }
  
}

void deposito(lista_clientes *lc, operacoes *op) {

  char cpf_deposito[12];
  float deposito;
  int find_cpf = 0;

  printf("\tCPF do cliente: ");
  scanf("%s", cpf_deposito);
  printf("\n");

  printf("\tValor do depósito: ");
  scanf("%f", &deposito);
  printf("\n");

  for (int x = 0; x < lc->qtnd; x++) {
    if (strcmp(lc->cliente[x].cpf, cpf_deposito) == 0) {
      lc->cliente[x].saldo += deposito;
      find_cpf = 1;
      strcpy(op->extrato[x].operacao, "Depósito");
      op->extrato[x].valor = deposito;
      op->qtnd += 1;
      printf("\tDepósito de %.2f realizado com sucesso\n\n", deposito);
    }
  }
  
  if (find_cpf == 0) {
    printf("\n\tCPF incorreto!\n");
  }
  
}

