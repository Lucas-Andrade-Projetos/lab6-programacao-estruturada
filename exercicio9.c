/*
Escreva uma função recursiva que calcule(n k),
para n≥0 e k≥0. Para isso, observe a
seguinte propriedade:
*/

#include <stdio.h>

int binomial(int n, int k);

int main() {
    int n, k;

    scanf("%d %d", &n, &k);

    if (k > n) {
        printf("Erro: k não pode ser maior que n.\n");
        return 1;
    }

    printf("%d\n", binomial(n, k));

    return 0;
}

//Função recursiva para calcular o coeficiente binomial (n choose k)
int binomial(int n, int k) {
	//Caso base: quando k == 0 ou k == n, o valor é 1
    if (k == 0 || k == n) {
        return 1;
    }

    //Recursão: usa a relação (n choose k) = (n-1 choose k-1) + (n-1 choose k)
    return binomial(n - 1, k - 1) + binomial(n - 1, k);
}

