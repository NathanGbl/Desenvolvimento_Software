#include "lib.h"
#include <stdio.h>
#include <string.h>

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

  if (tamanho_cpf != 11 || tamanho_tipo_conta != 1 || strcmp(tipo_conta, "c") != 0 && strcmp(tipo_conta, "p") != 0) {
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

void debito(lista_clientes *lc) {

  char cpf_debito[12];
  char senha_debito[101];
  float debito;
  int find_cpf = 0;
  int find_senha = 0;
  int saldo = 0;
  dados_extrato dados_extrato;

  printf("\tCPF do cliente: ");
  scanf("%s", cpf_debito);
  printf("\n");

  printf("\tSenha do cliente: ");
  scanf("%s", senha_debito);
  printf("\n");

  printf("\n\tValor do débito: ");
  scanf("%f", &debito);
  printf("\n");

  for (int x = 0; x < lc->qtnd; x++) {
    if (strcmp(lc->cliente[x].cpf, cpf_debito) == 0 &&
        strcmp(lc->cliente[x].senha, senha_debito) == 0 &&
        strcmp(lc->cliente[x].tipo_conta, "c") == 0 &&
        lc->cliente[x].saldo - debito * 1.05 >= -1000) {
      find_cpf = 1;
      find_senha = 1;
      lc->cliente[x].saldo -= debito * 1.05;

      strcpy(lc->cliente[x].extrato[lc->cliente[x].qtnd].operacao, "Débito");
      lc->cliente[x].extrato[lc->cliente[x].qtnd].valor = -debito * 1.05;
      lc->cliente->qtnd += 1;
      printf("\tDébito de %.2f realizado com sucesso!\n", debito);
    } else if (strcmp(lc->cliente[x].cpf, cpf_debito) == 0 &&
               strcmp(lc->cliente[x].senha, senha_debito) == 0 &&
               strcmp(lc->cliente[x].tipo_conta, "p") == 0 &&
               lc->cliente[x].saldo - debito * 1.03 >= -5000) {
      find_cpf = 1;
      find_senha = 1;
      lc->cliente[x].saldo -= debito * 1.03;
      strcpy(lc->cliente[x].extrato[lc->cliente[x].qtnd].operacao, "Débito");
      lc->cliente[x].extrato[lc->cliente[x].qtnd].valor = -debito * 1.03;

      printf("\tDébito de %.2f realizado com sucesso!\n", debito);
    } else if (strcmp(lc->cliente[x].tipo_conta, "c") == 0 &&
                   lc->cliente[x].saldo - debito * 1.05 < -1000 ||
               strcmp(lc->cliente[x].tipo_conta, "p") == 0 &&
                   lc->cliente[x].saldo - debito * 1.03 < -5000) {
      saldo = -1;
    }
  }

  if (find_cpf == 0 || find_senha == 0 || saldo == -1) {
    printf("\tDados incorretos e/ou saldo insuficiente!\n");
  }
}

