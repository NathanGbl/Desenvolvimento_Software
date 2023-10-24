#include <stdio.h>
#include "lib.h"

int main() {
  int opcao;
  lista_clientes lc;
  lc.qtnd = 0;
  // le_bin(&lc);

  do {
    menu(&opcao);
    while (opcao > 9 || opcao < 0) {
      menu(&opcao);
    }
  switch(opcao) {
    case 1:
      novo_cliente(&lc);
      // salva_bin(&lc);
      break;
    case 4:
      debito(&lc);
      // salva_bin(&lc);
      break;
    case 0:
      // salva_bin(&lc);
      break;
    }
  } while (opcao != 0);
  
    return 0;
  
}