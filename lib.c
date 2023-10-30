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

void apaga_extrato(lista_clientes *lc, int pos) {

  // Recebe o struct com todos os clientes e a posição do cliente na lista a ser apagado.
  cliente c = lc->cliente[pos];

  for (; pos < lc->cliente[pos].qtnd; pos++) {
    // Para cada posição da lista de struct dados_extrato, ele substitui as informações de operação e valor da posição atual pelas informações da próxima posição.
    strcpy(c.extrato[c.qtnd].operacao, lc->cliente[pos + 1].extrato[lc->cliente[pos + 1].qtnd].operacao);
    c.extrato[c.qtnd].valor = lc->cliente[pos + 1].extrato[lc->cliente[pos + 1].qtnd].valor;
  }
  
}

void apagar_cliente(lista_clientes *lc) {

  char cpf_apagado[50];
  int x = 0;
  int find = 0;

  printf("CPF a ser apagado: ");
  scanf("%s", cpf_apagado);
  
  for (; x < lc->qtnd; x++) {
    // Laço que itera sobre o cpf de cada cliente dentro do struct lista_cliente para verificar se existe o cpf no sistema.
    if (strcmp(lc->cliente[x].cpf, cpf_apagado) == 0) {
      // Se existir, valor de find é alterado e para o laço.
      find = 1;
      break;
    }
  }

  if (find == 1) { // Se o cpf existir, apaga o cliente. Senão, exibe uma mensagem de erro.
    for (; x < lc->qtnd; x++) {
      // Com a posição encontrada pelo laço anterior, o loop começa a copiar as informações do cliente da próxima posição para a posição atual.
      strcpy(lc->cliente[x].nome, lc->cliente[x + 1].nome);
      strcpy(lc->cliente[x].cpf, lc->cliente[x + 1].cpf);
      strcpy(lc->cliente[x].tipo_conta, lc->cliente[x + 1].tipo_conta);
      lc->cliente[x].saldo = lc->cliente[x + 1].saldo;
      strcpy(lc->cliente[x].senha, lc->cliente[x + 1].senha);
      apaga_extrato(lc, x);
    }
    lc->qtnd -= 1; // Decrementa 1 na quantidade do struct lista_cliente para apontar para o último cliente.
    lc->cliente->qtnd -= 1; // Decrementa 1 na quantidade dentro do struct cliente para apontar para os dados da ultíma operação feita.
    printf("\tCliente apagado com sucesso!\n\n"); // Exibi mensagem que deu certo.
  }
  else {
    printf("\tCPF incorreto!\n\n"); // Exibi mensagem de erro.
void listar_clientes(lista_clientes *lc) {

  for (int x = 0; x < lc->qtnd; x++) {
    // Loop que itera sobre os dados dos clientes dentro do lista_clientes e imprime as informações deles na tela.
    printf("\n\tCliente %d\n", x);
    printf("\t\tNome: %s\n", lc->cliente[x].nome);
    printf("\t\tCPF: %s\n", lc->cliente[x].cpf);
    printf("\t\tTipo de conta: %s\n", lc->cliente[x].tipo_conta);
    printf("\t\tSaldo: R$%.2f\n", lc->cliente[x].saldo);
    printf("\t\tSenha: %s\n\n", lc->cliente[x].senha);
  }
  
}