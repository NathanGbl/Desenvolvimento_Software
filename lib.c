#include <stdio.h>
#include <string.h>
#include "lib.h"

int menu() {
  
  int opcao;
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
  scanf("%d", &opcao);
  return opcao;
  
}

void novo_cliente(lista_clientes *lc) {

  printf("\tDigite o nome do cliente: \n");
  
}