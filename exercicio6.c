/*
Adapte o programa que resolve o problema da Torre de Hanoi visto em sala de aula. Ao
invés de exibir os movimentos, imprima o número de movimentos necessários para mover os n discos.
*/

#include <stdio.h>

int movimentos = 0;
void torreDeHanoi(int n, char origem, char destino, char auxiliar);

int main() {
    int n;

    scanf("%d", &n);

    printf("Solução da Torre de Hanói para %d discos:\n", n);
    torreDeHanoi(n, 'A', 'C', 'B'); //A: Origem, C: Destino, B: Auxiliar
	
	//Exibir o número total de movimentos
    printf("Número total de movimentos necessários: %d\n", movimentos);

    return 0;
}

//Função recursiva para resolver a Torre de Hanói
void torreDeHanoi(int n, char origem, char destino, char auxiliar) {
    if (n == 1) { //Caso base: mover um único disco
        printf("Mover disco 1 da torre %c para a torre %c\n", origem, destino);
		//Incrementa a contagem de movimentos
		movimentos++;
        return;
    }

    //Mover os n-1 discos da torre de origem para a torre auxiliar
    torreDeHanoi(n - 1, origem, auxiliar, destino);

    //Mover o maior disco da torre de origem para a torre de destino
    printf("Mover disco %d da torre %c para a torre %c\n", n, origem, destino);
	movimentos++; // Incrementa a contagem de movimentos

    //Mover os n-1 discos da torre auxiliar para a torre de destino
    torreDeHanoi(n - 1, auxiliar, destino, origem);
}

