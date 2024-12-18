/*
Considere uma sequência formada pelos caracteres ‘(‘e‘)‘ . Dizemos que uma sequência de parênteses é válida se:
 1. Cada parêntese de abertura ‘(‘possui um parêntese de fechamento‘)‘correspondente.
 2. Em qualquer prefixo da sequência, o número de parênteses de fechamento‘)‘ nunca excede o número deparênteses de abertura‘(‘.
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool isValidParentheses(const char* sequence, int index, int balance);

int main() {
    int n;
    char *sequence;

    scanf("%d", &n);

    //Alocar memória dinamicamente para a sequência de parênteses
    sequence = (char*)malloc((n + 1) * sizeof(char));  //+1 para o caractere de término '\0'

    if (sequence == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    //Solicitar ao usuário para inserir a sequência de parênteses
    printf("Digite a sequência de parênteses: ");
    scanf("%s", sequence);  // Lê a sequência sem espaços

    //Verificar se a sequência é válida
    if (isValidParentheses(sequence, 0, 0)) {
        printf("A sequência '%s' é válida.\n", sequence);
    } else {
        printf("A sequência '%s' não é válida.\n", sequence);
    }

    //Liberar a memória alocada
    free(sequence);

    return 0;
}

//Função recursiva para verificar se a sequência de parênteses é válida
bool isValidParentheses(const char* sequence, int index, int balance) {
    //Caso base: Se chegamos ao fim da sequência, o balance deve ser 0
    if (sequence[index] == '\0') {
        return balance == 0;
    }

    //Verifica o caractere atual
    char current = sequence[index];
    
    if (current == '(') {
        //Incrementa o balance para parênteses de abertura
        return isValidParentheses(sequence, index + 1, balance + 1);
    } else if (current == ')') {
        //Se balance for 0, temos um parêntese de fechamento sem correspondência
        if (balance == 0) {
            return false;
        }
        //Decrementa o balance para parênteses de fechamento
        return isValidParentheses(sequence, index + 1, balance - 1);
    }

    //Se o caractere não for '(' nem ')', é inválido (opcional, caso você queira validar apenas parênteses)
    return false;
}