/*
Escreva um programa recursivo capaz de encontrar a saída de um labirinto. O mapa do
labirinto segue o seguinte formato:
 • A entrada do labirinto está no canto superior esquerdo.
 • A saída do labirinto está no canto inferior direito.
 • As paredes do labirinto são marcadas como caractere #.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printMaze(char **maze, int rows, int cols);
bool solveMaze(char **maze, int x, int y, int rows, int cols);
char **allocateMaze(int rows, int cols);
void freeMaze(char **maze, int rows);
int loadMaze(const char *filename, char ***maze, int *rows, int *cols);

int main() {
    char **maze;
    int rows, cols;

    //Carregar o labirinto do arquivo
    if (loadMaze("input.txt", &maze, &rows, &cols) != 0) {
        return 1;
    }

    printf("Labirinto inicial:\n");
    printMaze(maze, rows, cols);

    if (solveMaze(maze, 0, 0, rows, cols)) {
        printf("Caminho encontrado:\n");
        printMaze(maze, rows, cols);
    } else {
        printf("Nenhum caminho encontrado.\n");
    }

    //Liberar memória alocada para o labirinto
    freeMaze(maze, rows);

    return 0;
}

//Função para imprimir o labirinto
void printMaze(char **maze, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

//Função recursiva para resolver o labirinto
bool solveMaze(char **maze, int x, int y, int rows, int cols) {
    //Caso base: se chegarmos ao canto inferior direito
    if (x == rows - 1 && y == cols - 1) {
        maze[x][y] = '.';
        return true;
    }

    //Verificar se a posição atual é válida
    if (x >= 0 && x < rows && y >= 0 && y < cols && maze[x][y] == ' ') {
        maze[x][y] = '.'; // Marca a posição atual como parte do caminho

        //Tenta mover para baixo
        if (solveMaze(maze, x + 1, y, rows, cols)) return true;

        //Tenta mover para a direita
        if (solveMaze(maze, x, y + 1, rows, cols)) return true;

        //Tenta mover para cima
        if (solveMaze(maze, x - 1, y, rows, cols)) return true;

        //Tenta mover para a esquerda
        if (solveMaze(maze, x, y - 1, rows, cols)) return true;

        maze[x][y] = ' '; //Desfaz a marcação (backtracking)
    }

    return false; //Não há caminho possível
}

//Função para alocar o labirinto dinamicamente
char **allocateMaze(int rows, int cols) {
    char **maze = (char **)malloc(rows * sizeof(char *));
    for (int i = 0; i < rows; i++) {
        maze[i] = (char *)malloc(cols * sizeof(char));
    }
    return maze;
}

//Função para liberar a memória alocada para o labirinto
void freeMaze(char **maze, int rows) {
    for (int i = 0; i < rows; i++) {
        free(maze[i]);
    }
    free(maze);
}

//Função para carregar o labirinto de um arquivo
int loadMaze(const char *filename, char ***maze, int *rows, int *cols) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Erro ao abrir o arquivo %s\n", filename);
        return -1;
    }

    char line[1024]; //Buffer para leitura das linhas
    int maxCols = 0;

    //Determinar número de linhas e colunas
    *rows = 0;
    while (fgets(line, sizeof(line), file)) {
        int len = 0;
        while (line[len] != '\n' && line[len] != '\0') {
            len++;
        }
        if (len > maxCols) {
            maxCols = len;
        }
        (*rows)++;
    }
    *cols = maxCols;

    //Voltar para o início do arquivo para leitura do conteúdo
    rewind(file);

    //Alocar memória para o labirinto
    *maze = allocateMaze(*rows, *cols);

    //Ler o conteúdo do arquivo para o labirinto
    int row = 0;
    while (fgets(line, sizeof(line), file)) {
        for (int col = 0; col < *cols; col++) {
            if (line[col] == '\n' || line[col] == '\0') {
                (*maze)[row][col] = ' '; //Preenche espaços vazios
            } else {
                (*maze)[row][col] = line[col];
            }
        }
        row++;
    }

    fclose(file);
    return 0;
}
