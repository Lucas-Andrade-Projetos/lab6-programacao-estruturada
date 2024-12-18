/*
Escreva um programa recursivo que, dados n números positivos e um inteiro k, onde
1 ≤k≤n,seja capaz de imprimir todas as combinações de k elementos dos valores fornecidos.

achei dificil
*/

#include <stdio.h>
#include <stdlib.h>

void printCombinations(int* arr, int* comb, int start, int n, int k, int index);

int main() {
    int n, k;

    printf("Digite o número total de elementos n e o número de elementos para combinar k: ");
    scanf("%d %d", &n, &k);

    //Alocar o vetor de números e o vetor para armazenar a combinação
    int* arr = (int*)malloc(n * sizeof(int));
    int* comb = (int*)malloc(k * sizeof(int));

    if (arr == NULL || comb == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    //Ler os números que o usuário deseja combinar
    printf("Digite os %d números:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    //Imprimir todas as combinações
    printf("Combinacoes de %d elementos:\n", k);
    printCombinations(arr, comb, 0, n, k, 0);

    //Liberar a memória alocada
    free(arr);
    free(comb);

    return 0;
}

void printCombinations(int* arr, int* comb, int start, int n, int k, int index) {
    //Caso base: Se a combinação estiver completa
    if (index == k) {
        for (int i = 0; i < k; i++) {
            printf("%d ", comb[i]);
        }
        printf("\n");
        return;
    }

    //Tenta adicionar um número à combinação e chama recursivamente
    for (int i = start; i < n; i++) {
        comb[index] = arr[i];  // Adiciona o elemento atual à combinação
        printCombinations(arr, comb, i + 1, n, k, index + 1);  //Chama recursivamente para adicionar o próximo
    }
}
