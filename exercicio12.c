/*
O MergeSort é um algoritmo de ordenação que segue o paradigma dividir para conquistar.
O algoritmo funcionada seguinte forma:
 1. Dividir:O vetor original com n elementos é divido em dois subvetores, um de tamanho⌈n/2⌉ e outro de tamanho⌊n/2⌋.
 2. Conquistar: Os subvetores são ordenados recursivamente.
 3. Combinar: Os subvetores ordenados são combinados(intercalados) em um único vetor ordenado
*/

#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int left, int mid, int right);
void mergeSort(int arr[], int left, int right);

int main() {
    int n;

    scanf("%d", &n);

    //Alocação dinâmica para o vetor
    int* arr = (int*)malloc(n * sizeof(int));

    //Verifica se a alocação foi bem-sucedida
    if (arr == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);

    return 0;
}

//Função para combinar (merge) dois subvetores ordenados
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;  
    int n2 = right - mid;     

    //Alocação dinâmica dos vetores temporários
    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    //Copiando os dados para os vetores temporários
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    //Índices para iterar nos subvetores e no vetor principal
    int i = 0, j = 0, k = left;

    //Combinação dos dois subvetores em ordem crescente
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    //Copia os elementos restantes do subvetor esquerdo, se houver
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    //Copia os elementos restantes do subvetor direito, se houver
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    //Liberação da memória alocada
    free(L);
    free(R);
}

//Função recursiva do MergeSort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        //Encontra o ponto médio
        int mid = left + (right - left) / 2;

        //Ordena a primeira metade do vetor
        mergeSort(arr, left, mid);

        //Ordena a segunda metade do vetor
        mergeSort(arr, mid + 1, right);

        //Combina os subvetores ordenados
        merge(arr, left, mid, right);
    }
}