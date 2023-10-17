#include <stdio.h>
#include "lib.h"

int main() {
  
  int opcao;
  lista_clientes lc;
  operacoes op;
  lc.qtnd = 0;
  do {
    menu(&opcao);
    while (opcao > 9 || opcao < 0) {
      menu(&opcao);
    }
    switch(opcao) {
      case 1:
        novo_cliente(&lc, &op);
        break;
      case 5:
        deposito(&lc, &op);
        break;
      case 6:
        extrato(&lc, &op);
        break;
    }
  } while (opcao != 0);
  
    return 0;
  
}