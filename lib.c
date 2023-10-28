#include "lib.h"
#include <stdio.h>
#include <string.h>

void menu(int *opcao, int *cont) {

  // Exibe o menu e recebe um inteiro do usuário.
  if (*cont == 0) { // Se for a primeira vez que o usuário entrar no programa, ele recebe o menu inicial.
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
    printf("\n");
    *cont += 1;
  }
  else { // Case o menu se repetir, não exibirá a mensagem "Bem vindo ao banco QuemPoupaTem!".
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
    printf("\n");
    *cont += 1;
  }
  
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

  tamanho_cpf = strlen(cpf); // Verifica o comprimento da string cpf.
  tamanho_tipo_conta = strlen(tipo_conta); // Verifica o comprimento da string tipo_conta.

  if (tamanho_cpf != 11 || tamanho_tipo_conta != 1 || strcmp(tipo_conta, "c") != 0 && strcmp(tipo_conta, "p") != 0) { // Se o comprimento das strings do cpf e do tipo de conta estiverem errados e o tipo de conta for diferente de c ou p, para a função novo_cliente após exibir uma mensagem.
    printf("\tCPF e/ou tipo de conta inválidos.\n\n");
  }
  else { // Caso contrário, os dados são adicionados no struct cliente com as informações do cliente.
  strcpy(cliente.nome, nome);
  strcpy(cliente.cpf, cpf);
  strcpy(cliente.tipo_conta, tipo_conta);
  cliente.saldo = saldo;
  strcpy(cliente.senha, senha);

  lc->cliente[lc->qtnd] = cliente; // Adiciona o struct cliente preenchido no struct lista_clientes.
  lc->qtnd += 1; // Atualiza a quantidade de clientes dentro do lista_clientes para apontar para a última posição do array.
  printf("\tDados cadastrados com sucesso!\n\n");
  }
  
}