#include <stdio.h>
#include "lib.h"

int main() {
  int opcao;
  lista_clientes lc;
  do {
    menu(&opcao);
    while (opcao > 9 || opcao < 0) {
      menu(&opcao);
    }
    switch(opcao) {
      case 1:
        novo_cliente(&lc);
        break;
      //case 2:
      //  apagar_cliente();
      //  break;
      case 3:
        listar_clientes(&lc);
        break;
    }
    printf("%d", opcao);
  } while (opcao != 0);
  
    return 0;
}