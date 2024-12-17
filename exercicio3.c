/*
Implemente a função recursiva
int soma(int v[], int n);
Essa função recursiva retorna a soma de todos os elementos do vetor v.
*/

#include <stdio.h>
#define max 100


int soma(int v[], int n);

int main() {
    int n;
	
	scanf("%d", &n);
	int v[max];

    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    printf("%d\n", soma(v, n));

    return 0;
}

int soma(int v[], int n) {
    if (n == 0) { //Caso base: quando o vetor tem tamanho 0, a soma é 0
        return 0;
    } else {
        return v[n - 1] + soma(v, n - 1); //Soma o último elemento com a soma do restante do vetor
    }
}