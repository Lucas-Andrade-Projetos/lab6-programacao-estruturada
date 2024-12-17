/*
ImplementeumafunçãorecursivaparagerarasequênciadeCollatzparaumdadonúmero
inteiro positivo. A sequência de Collatz é gerada a partir das seguintes regras:
 • Se onúmero atual for par, divida-o por 2.
 • Se onúmero atual for ímpar, multiplique-o por 3 e some 1.
A função deve imprimir cada termo da sequência até que o número atual seja 1, momento em que a
recursão deve parar.
*/

#include <stdio.h>

void collatz(int n);

int main() {
    int n;

    scanf("%d", &n);

    if (n <= 0) {
        printf("Por favor, insira um número inteiro positivo.\n");
        return 1;
    }

    collatz(n);
    printf("\n");

    return 0;
}

//Função recursiva para gerar a sequência de Collatz
void collatz(int n) {
    //Imprime o número atual
    printf("%d ", n);

    //Caso base: se o número atual for 1, termina a recursão
    if (n == 1) {
        return;
    }

    //Verifica se o número é par ou ímpar e faz a chamada recursiva
    if (n % 2 == 0) {
        collatz(n / 2); //Número par: divide por 2
    } else {
        collatz(3 * n + 1); //Número ímpar: multiplica por 3 e soma 1
    }
}

