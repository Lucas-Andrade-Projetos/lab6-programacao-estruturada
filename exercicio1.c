/*
Implemente a função recursiva
void count_down(int n);
Essa é uma função recursiva que faz uma contagem regressiva.
apenas para dar commit
*/
#include <stdio.h>

void count_down(int n);

int main() {
    count_down(5); 
    return 0;
}

void count_down(int n) {
    if (n > 0) { //Caso base da recursão
        printf("%d\n", n);
        count_down(n - 1); //Chamada recursiva com n decrementado
    } else {
        printf("ACABOU!\n"); //Condição de parada
    }
}
