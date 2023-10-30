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
  else { // Caso o menu se repetir, não exibirá a mensagem "Bem vindo ao banco QuemPoupaTem!".
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


void transf(lista_clientes *lc) {

  char cpf_origem[12];
  char cpf_destino[12];
  char senha_origem[101];
  int find_cpfsenha_origem = 0;
  int find_cpf_destino = 0;
  int pos_origem = 0;
  int pos_destino = 0;
  float transf;

  printf("\n\tCPF de origem: ");
  scanf("%s", cpf_origem);

  printf("\n\tCPF de destino: ");
  scanf("%s", cpf_destino);

  printf("\n\tSenha de origem: ");
  scanf("%s", senha_origem);

  for (; pos_origem < lc->qtnd; pos_origem++) {
    // Laço que itera sobre os cpfs e senhas dos clientes dentro do lista_clientes e verifica se o cpf e a senha existem no sistema.
    if (strcmp(lc->cliente[pos_origem].cpf, cpf_origem) == 0 && strcmp(lc->cliente[pos_origem].senha, senha_origem) == 0) {
      find_cpfsenha_origem = 1;
      break;
    }
  }
  for (; pos_destino < lc->qtnd; pos_destino++) {
    // Laço que itera sobre os cpfs dos clientes dentro do lista_clientes e verifica se o cpf existe no sistema.
    if (strcmp(lc->cliente[pos_destino].cpf, cpf_destino) == 0) {
      find_cpf_destino = 1;
      break;
    }
  }

  if (find_cpfsenha_origem == 1 && find_cpf_destino == 1) {
    // Se existir, continua com o funcionamento da função. Senão, exibe mensagem de erro.
    printf("\n\tValor da transferência: ");
    scanf("%f", &transf);

    if (strcmp(lc->cliente[pos_origem].tipo_conta, "c") == 0 && lc->cliente[pos_origem].saldo - transf * 1.05 >= -1000) {
      // Se o tipo de conta do cliente de origem for comum e o saldo pós transferência for maior ou igual a -1000, então fará a transferência.
      lc->cliente[pos_origem].saldo -= transf * 1.05; // Tira o valor mais 5% de taxa da conta do cliente de origem.
      strcpy(lc->cliente[pos_origem].extrato[lc->cliente[pos_origem].qtnd].operacao, "Transferência"); // String operacao agora é "Tranferência".
      lc->cliente[pos_origem].extrato[lc->cliente[pos_origem].qtnd].valor = -transf * 1.05; // Variável valor agora é o -valor da transferência + 5% de taxa.
      lc->cliente[pos_origem].qtnd += 1; // Aumenta a quantidade para apontar para a última operação.

      lc->cliente[pos_destino].saldo += transf; // Adiciona o valor na conta do cliente de destino.
      strcpy(lc->cliente[pos_destino].extrato[lc->cliente[pos_destino].qtnd].operacao, "Transferência"); // String operacao agora é "Tranferência".
      lc->cliente[pos_destino].extrato[lc->cliente[pos_destino].qtnd].valor = transf; // // Variável valor agora é o valor recebido.
      lc->cliente[pos_destino].qtnd += 1; // Aumenta a quantidade para apontar para a última operação.
    }

    else if (strcmp(lc->cliente[pos_origem].tipo_conta, "p") == 0 && lc->cliente[pos_origem].saldo - transf * 1.03 >= -5000) {
      // Se o tipo de conta do cliente de origem for plus e o saldo pós transferência for maior ou igual a -5000, então fará a transferência.
    lc->cliente[pos_origem].saldo -= transf * 1.03;
    strcpy(lc->cliente[pos_origem].extrato[lc->cliente[pos_origem].qtnd].operacao, "Transferência");
    lc->cliente[pos_origem].extrato[lc->cliente[pos_origem].qtnd].valor = -transf * 1.03;
    lc->cliente[pos_origem].qtnd += 1;

    lc->cliente[pos_destino].saldo += transf;
    strcpy(lc->cliente[pos_destino].extrato[lc->cliente[pos_destino].qtnd].operacao, "Transferência");
    lc->cliente[pos_destino].extrato[lc->cliente[pos_destino].qtnd].valor = transf;
    lc->cliente[pos_destino].qtnd += 1;
    }

    else {
      printf("\n\tSaldo insuficiente!");
    }
    
    printf("\n\tTranferência realizada com sucesso!\n");
  }
  else {
    printf("\n\tDados incorretos!");
  }
  
}
