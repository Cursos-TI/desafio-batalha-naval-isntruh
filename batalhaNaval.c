#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_HABILIDADE 5

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {0};

    int navioHorizontal[3] = {3, 3, 3};
    int navioVertical[3] = {3, 3, 3};

    int linhaH = 2, colunaH = 1;
    int linhaV = 0, colunaV = 4;

    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
        tabuleiro[linhaV + i][colunaV] = navioVertical[i];
    }

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    int navioDiagonal1[3] = {3, 3, 3};
    int navioDiagonal2[3] = {3, 3, 3};

    int linhaD1 = 5, colunaD1 = 5;
    int linhaD2 = 7, colunaD2 = 2;

    for (int i = 0; 1 < 3; i++) {
        if (linhaD1 + i < TAM_TABULEIRO && colunaD1 + i < TAM_TABULEIRO)
            tabuleiro[linhaD1 + i][colunaD1 + i] = navioDiagonal1[i];
        if (linhaD2 - i >= 0 && colunaD2 + i < TAM_TABULEIRO)
            tabuleiro[linhaD2 - i][colunaD2 + i] = navioDiagonal2[i];
    }
    
    printf(">>> TABULEIRO NÍVEL AVENTUREIRO <<<\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    int cone[TAM_HABILIDADE][TAM_HABILIDADE];
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE];

    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (j >= TAM_HABILIDADE / 2 - i && j <= TAM_HABILIDADE / 2 + i)
                cone[i][j] = 1;
            else
                cone[i][j] = 0;           
        }
    }

    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (i == TAM_HABILIDADE / 2 || j == TAM_HABILIDADE / 2 )
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }

    int centro = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int difI = 1 - centro;
            if (difI < 0) difI = -difI;
            int difJ = j - centro;
            if (difJ < 0) difJ = -difJ;
            if (difI + difJ <= centro)
                octaedro[i][j] = 1;
            else
                octaedro[i][j] = 0;
        }
    }

    int origemConeLinha = 4, origemConeColuna = 4;
    int origemCruzLinha = 7, origemCruzColuna = 2;
    int origemOctaedroLinha = 4, origemOctaedroColuna = 5;
    int meio = TAM_HABILIDADE / 2;

    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int linha = origemConeLinha - meio + i;
            int coluna = origemConeColuna - meio + j;
            if (linha >= 0 && linha < TAM_TABULEIRO && coluna >= 0 && coluna < TAM_TABULEIRO) {
                if (cone[i][j] == 1 && tabuleiro[linha][coluna] != 3)
                    tabuleiro[linha][coluna] = 5;
            }
        }
    }

    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int linha = origemCruzLinha - meio + i;
            int coluna = origemCruzColuna - meio + j;
            if (linha >= 0 && linha < TAM_TABULEIRO && coluna >= 0 && coluna < TAM_TABULEIRO) {
                if (cruz[i][j] == 1 && tabuleiro[linha][coluna] != 3)
                    tabuleiro[linha][coluna] = 5;
            }
        }
    }

    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int linha = origemOctaedroLinha - meio + i;
            int coluna = origemOctaedroColuna - meio + j;
            if (linha >= 0 && linha < TAM_TABULEIRO && coluna >= 0 && coluna < TAM_TABULEIRO) {
                if (octaedro[i][j] == 1 && tabuleiro[linha][coluna] != 3)
                    tabuleiro[linha][coluna] = 5;
            }
        }
    }

    printf("\n=== TABULEIRO NIVEL MESTRE ===\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}