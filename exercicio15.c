/*
Escreva um programa recursivo que, dado um número positivo n fornecido pelo usuário,
seja capaz de imprimir todas as combinações dos n primeiros naturais. Para n = 3.

achei muuuuuuuito dificil
*/

#include <stdio.h>
#include <stdlib.h>

void printCombinations(int* arr, int n, int index, int combLength, int* comb, int k); // Corrigir a declaração

int main() {
    int n;

    // Ler o número n
    printf("Digite um número positivo n: ");
    scanf("%d", &n);

    // Alocar um vetor para armazenar os números de 1 a n
    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    // Preencher o vetor com os primeiros n números naturais
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    // Imprimir todas as combinações dos n primeiros números
    printf("Combinacoes dos %d primeiros numeros:\n", n);
    int* comb = (int*)malloc(n * sizeof(int)); // Vetor para armazenar a combinação
    for (int k = 1; k <= n; k++) {
        printCombinations(arr, n, 0, 0, comb, k);  // Passando k para gerar combinações de tamanho k
    }

    // Liberar a memória alocada
    free(arr);
    free(comb);

    return 0;
}

// Função recursiva para imprimir as combinações
void printCombinations(int* arr, int n, int index, int combLength, int* comb, int k) {
    // Caso base: Imprimir a combinação quando ela tiver exatamente k elementos
    if (combLength == k) {
        for (int i = 0; i < combLength; i++) {
            printf("%d", comb[i]);
        }
        printf("\n");
        return;
    }

    // Gerar combinações recursivamente
    for (int i = index; i < n; i++) {
        comb[combLength] = arr[i];  // Adiciona o número atual à combinação
        printCombinations(arr, n, i + 1, combLength + 1, comb, k);  // Chama recursivamente para a próxima combinação
    }
}
