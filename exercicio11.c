/*
Escreva um programa recursivo capaz de encontrar a saída de um labirinto. O mapa do
labirinto segue o seguinte formato:
 • A entrada do labirinto está no canto superior esquerdo.
 • A saída do labirinto está no canto inferior direito.
 • As paredes do labirinto são marcadas como caractere #.

 mnao consegui ainda
*/
#include <stdio.h>
#include <stdlib.h>

#define N 10 // Número de linhas do labirinto
#define M 10 // Número de colunas do labirinto

// Labirinto representado como uma matriz de caracteres
char maze[N][M];

// Função para imprimir o labirinto
void print_maze() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

// Função para resolver o labirinto
int solve_maze(int x, int y) {
    // Caso base: se chegarmos na saída
    if (x == N - 1 && y == M - 1) {
        maze[x][y] = '.'; // Marca a saída
        return 1;
    }

    // Verifica se a posição atual é válida (dentro do labirinto, não é uma parede e não foi visitada)
    if (x < 0 || x >= N || y < 0 || y >= M || maze[x][y] == '#' || maze[x][y] == '.') {
        return 0;
    }

    // Marca a posição como visitada
    maze[x][y] = '.';

    // Tenta mover para baixo, direita, cima ou esquerda
    if (solve_maze(x + 1, y)) return 1; // Move para baixo
    if (solve_maze(x, y + 1)) return 1; // Move para a direita
    if (solve_maze(x - 1, y)) return 1; // Move para cima
    if (solve_maze(x, y - 1)) return 1; // Move para a esquerda

    // Se não encontrar caminho, desmarca a posição e volta
    maze[x][y] = ' '; // Marca a posição como "não visitada"
    return 0;
}

// Função para ler o labirinto de um arquivo input.txt
void read_maze_from_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    // Lê o labirinto do arquivo e armazena na matriz maze
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            fscanf(file, "%c", &maze[i][j]);
        }
        fscanf(file, "\n"); // Para capturar a quebra de linha após cada linha do labirinto
    }

    fclose(file);
}

int main() {
    // Lê o labirinto do arquivo input.txt
    read_maze_from_file("input.txt");

    // Imprimindo o labirinto original
    printf("Labirinto Original:\n");
    print_maze();

    // Tentando encontrar o caminho da entrada até a saída
    if (solve_maze(0, 0)) {
        printf("\nCaminho encontrado:\n");
        print_maze(); // Exibe o labirinto com o caminho
    } else {
        printf("\nNão foi possível encontrar o caminho!\n");
    }

    return 0;
}
