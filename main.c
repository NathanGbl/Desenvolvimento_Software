#include <stdio.h>
#include "lib.h"

int main() {
    int opcao;
    do {
        opcao = menu(opcao);
    } while (opcao != 0);
  
    return 0;
}