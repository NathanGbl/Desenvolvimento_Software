#include <stdio.h>
#include "lib.h"

int main() {
  int opcao;
  int cont = 0;
  lista_clientes lc;
  lc.qtnd = 0;
  le_bin(&lc); // Atualiza o struct lista_clientes com o conteúdo do arquivo dados_clientes.

  do {
    menu(&opcao, &cont);
    while (opcao > 9 || opcao < 0) {
      menu(&opcao, &cont);
    }
  switch(opcao) {
    case 1:
      novo_cliente(&lc);
      // salva_bin(&lc);
      break;
    case 3:
      listar_clientes(&lc);
      // salva_bin(&lc);
      break;
    case 0:
      salva_bin(&lc);
      break;
    }
  } while (opcao != 0);
  
    return 0;
  
}