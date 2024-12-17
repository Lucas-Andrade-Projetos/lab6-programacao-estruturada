/*
Implemente a função recursiva
double power(double a, int b);
Essa função recursiva retorna o valor de a elevado a potência b, isto é, o valor retornado é a^b
*/

#include <stdio.h>

double power(double a, int b);

int main() {
    double base;
    int exp;
	scanf("%lf %d", &base, &exp);
    printf("%.2lf\n", power(base, exp)); // Mostra o resultado com 6 casas decimais
    return 0;
}


double power(double a, int b) {
    if (b == 0) { //Caso base: qualquer número elevado a 0 é 1
        return 1.0;
    } else if (b > 0) { //Potência positiva
        return a * power(a, b - 1); //Multiplica 'a' por ele mesmo (b - 1) vezes
    } else { //Potência negativa
        return 1 / power(a, -b); //Converte para uma potência positiva e calcula o inverso
    }
}