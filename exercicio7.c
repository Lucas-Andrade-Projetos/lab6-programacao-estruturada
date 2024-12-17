/*
Escreva a função recursiva abaixo:
void convert_to_binary(int n, char output[]);
Essa função recebe um número inteiro n como entrada e converte-o em uma representação binária na
forma de string. O resultado da conversão é armazenado na variável output.
*/
#include <stdio.h>
#include <string.h>
#define max 100

void convert_to_binary(int n, char output[]);

int main() {
    int n;
    char output[max] = ""; //Vetor para armazenar a saída binária (tamanho suficiente para números grandes)

    scanf("%d", &n);

    //Lida com números negativos (usando representação sem sinal)
    if (n < 0) {
        printf("Número negativo não suportado.\n");
        return 1;
    }

    convert_to_binary(n, output);

    // Imprime o resultado
    printf("%s\n", output);

    return 0;
}

//Função recursiva para converter um número inteiro em binário
void convert_to_binary(int n, char output[]) {
    //Caso base: número zero
    if (n == 0) {
        if (strlen(output) == 0) { //Se a string estiver vazia, insere '0'
            strcat(output, "0");
        }
        return;
    }

    //Recursão: chamada para o quociente de n / 2
    convert_to_binary(n / 2, output);

    //Adiciona o resto da divisão por 2 ao final da string
    char bit = (n % 2) + '0'; //Converte o bit (0 ou 1) para caractere
    strncat(output, &bit, 1);
}
