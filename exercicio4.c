/*
Implemente a função recursiva chamada inverte. Um dos parâmetros que essa função
irá receber é char word[]. Você pode passar outros parâmetros se sentir necessidade. Como resul
tado, essa função deve inverter a palavra recebida, i.e., se a word armazenar a palavra “abobora”, após
 a execução da função, ela armazenará a palavra “aroboba”.
*/

#include <stdio.h>
#include <string.h>

void inverte(char word[], int start, int end);

int main() {
    char word[100];


    scanf("%s", word);

    int length = strlen(word);


    inverte(word, 0, length - 1);

    printf("%s\n", word);

    return 0;
}

void inverte(char word[], int start, int end) {
    if (start >= end) { //Caso base: quando os índices se encontram ou cruzam, a inversão está concluída
        return;
    }

    //Troca os caracteres nas posições start e end
    char temp = word[start];
    word[start] = word[end];
    word[end] = temp;

    //Chamada recursiva com os próximos índices
    inverte(word, start + 1, end - 1);
}
