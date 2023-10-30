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

void debito(lista_clientes *lc) {

  char cpf_debito[12];
  char senha_debito[101];
  float debito;
  int find_cpf = 0;
  int find_senha = 0;
  int saldo = 0;
  int x = 0;

  printf("\tCPF do cliente: ");
  scanf("%s", cpf_debito);
  printf("\n");

  printf("\tSenha do cliente: ");
  scanf("%s", senha_debito);
  printf("\n");

  printf("\n\tValor do débito: ");
  scanf("%f", &debito);
  printf("\n");

  for (; x < lc->qtnd; x++) {
    // Laço que itera sobre os cpfs da lista_clientes e verifica se o cpf existe no sistema.
    if (strcmp(lc->cliente[x].cpf, cpf_debito) == 0 && strcmp(lc->cliente[x].senha, senha_debito) == 0) {
      find_cpf = 1;
      find_senha = 1;
      break;
    }
  }

  if (find_cpf == 1 && find_senha == 1) {
    if (strcmp(lc->cliente[x].tipo_conta, "c") == 0 && lc->cliente[x].saldo - debito * 1.05 >= -1000) {
      // Se o cpf existir, a conta for comum e o saldo depois do debito for maior que -1000 realizará o débito
      lc->cliente[x].saldo -= debito * 1.05;
      strcpy(lc->cliente[x].extrato[lc->cliente[x].qtnd].operacao, "Débito"); // String "Débito" adicionada na variável operacao do extrato.
      lc->cliente[x].extrato[lc->cliente[x].qtnd].valor = -debito * 1.05; // Adiciona o valor do deposito na variável valor do extrato
      lc->cliente[x].qtnd += 1; // Aumenta em 1 

      printf("\n\tDébito de R$%.2f realizado com sucesso!\n\n", debito);
    }
    else if (strcmp(lc->cliente[x].tipo_conta, "p") == 0 && lc->cliente[x].saldo - debito * 1.03 >= -5000) {
      // Se o cpf existir, a conta for plus e o saldo depois do debito for maior que -5000 realizará o débito
      lc->cliente[x].saldo -= debito * 1.03;
      strcpy(lc->cliente[x].extrato[lc->cliente[x].qtnd].operacao, "Débito");
      lc->cliente[x].extrato[lc->cliente[x].qtnd].valor = -debito * 1.03;
      lc->cliente[x].qtnd += 1;
      printf("\n\tDébito de R$%.2f realizado com sucesso!\n\n", debito);
    }
    else {
      printf("\tSaldo insuficiente!\n\n");
    }
  }
  else {
    printf("\tDados incorretos\n\n");
  }
  
}

void salva_bin(lista_clientes *lc) {

  FILE *f = fopen("dados_clientes", "wb"); // Abre o arquivo no modo "escrita em binário"
  if (f == NULL) { // Se o arquivo não existir, para a função.
    return;
  }
  else {
    fwrite(lc, sizeof(lista_clientes), 1, f); // Escreve os dados dos clientes presentes no struct lista_clientes no arquivo.
    fclose(f); // Fecha o arquivo.
  }
  
}

void le_bin(lista_clientes *lc) {
  
  FILE *f = fopen("dados_clientes", "rb"); // Abre o arquivo no modo "leitura em binário"
  if (f == NULL) { // Se o arquivo não existir, para a função.
    return;
  }
  else {
    fread(lc, sizeof(lista_clientes), 1, f); // Lê os dados dos clientes presentes no struct lista_clientes no arquivo.
    fclose(f); // Fecha o arquivo.
  }
  
}
