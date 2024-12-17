/*
Escreva a seguinte função recursiva:
void list_all_bit_strings(int n);
Essa função imprime todas as sequências com n bits(sem repetição). A ordem em que as cadeias de
bits são impressas não importa, apenas tome cuidado para não imprimir a mesma cadeia mais de uma
vez. O exemplo abaixo mostra uma das saídas possíveis para quando n=3.
*/

#include <stdio.h>

void list_all_bit_strings(int n);
void generate_bits(int index);

int main() {
    int n;

    scanf("%d", &n);

    list_all_bit_strings(n);

    return 0;
}

//Função recursiva para imprimir todas as sequências de bits de comprimento n
void list_all_bit_strings(int n) {
    //Vetor para armazenar a sequência de bits
    int bit_string[n];

    //Função auxiliar recursiva para gerar as sequências
    void generate_bits(int index){
        //Caso base: Se o índice atingir o comprimento n, imprime a sequência
        if (index == n) {
            for (int i = 0; i < n; i++) {
                printf("%d", bit_string[i]);
            }
            printf("\n");
            return;
        }

        //Coloca 0 na posição atual e chama recursão para o próximo bit
        bit_string[index] = 0;
        generate_bits(index + 1);

        //Coloca 1 na posição atual e chama recursão para o próximo bit
        bit_string[index] = 1;
        generate_bits(index + 1);
    }

    //Chama a função auxiliar para gerar as sequências a partir do índice 0
    generate_bits(0);
}