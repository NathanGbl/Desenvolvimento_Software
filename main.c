#include <stdio.h>
#include "lib.h"

int main() {
  
  int opcao;
  lista_clientes lc;
  lc.qtnd = 0;
  do {
    menu(&opcao);
    while (opcao > 9 || opcao < 0) {
      menu(&opcao);
    }
    switch(opcao) {
      case 1:
        novo_cliente(&lc);
        break;
      case 3:
        listar_clientes(&lc);
        break;
    }
  } while (opcao != 0);
  
    return 0;
  
}