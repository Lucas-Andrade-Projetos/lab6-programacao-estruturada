/*
O maior divisor comum de dois inteiros a e b, denotado por gcd(a,b), é o maior inteiro c
que divide a e b. O Algoritmo de Euclides nos apresenta uma forma simples de computar gcd(a,b):
 
gcd(a,b) = { 
a, se b =0;
gcd(b,a%b), caso contrário. }
 
Implemente o algoritmo de Euclides em C.
*/

#include <stdio.h>

int gcd(int a, int b);

int main() {
    int a, b;

    scanf("%d %d", &a, &b);

    int resultado = gcd(a, b);

    printf("%d\n", resultado);

    return 0;
}

// Função recursiva para calcular o maior divisor comum (GCD)
int gcd(int a, int b) {
    if (b == 0) { //Caso base: quando o divisor b é zero, o GCD é a
        return a;
    } else {
        return gcd(b, a % b); //Chamada recursiva: calcula o GCD com b e o resto de a/b
    }
}