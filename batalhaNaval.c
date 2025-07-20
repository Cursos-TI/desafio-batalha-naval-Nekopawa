#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    int tabuleiro[10][10];
    char verticalIndex = 'A';
    int horizontalIndex = 0;

    //preenche cada posição do tabuleiro com 0
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }        
    }

    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    //navio vertical
    int navio1[3][2] = {
        {1, 2},
        {2, 2},
        {3, 2}
    };
    
    //navio horizontal
    int navio2[3][2] = {
        {5, 4},
        {5, 5},
        {5, 6}
    };

    //mudar posição do tabuleiro para 3 quando tem um navio
    //navio 1
    for (int i = 0; i < 3; i++) {
        int navioX = navio1[i][0];
        int navioY = navio1[i][1];

        //valida coordenadas do navio
        if ((navioX >= 0 && navioY <= 10) && (navioY >= 0 && navioY <= 10)) {
            tabuleiro[navioX][navioY] = 3;
        } else {
            printf("\nCoordenadas do navio 1 inválidas");
            return 0;
        }
    }
    
    //navio 2
    for (int i = 0; i < 3; i++) {
        int navioX = navio2[i][0];
        int navioY = navio2[i][1];

        //evitar sobreposição
        if (tabuleiro[navioX][navioY] == 0) {
            //valida coordenadas do navio
            if ((navioX >= 0 && navioY <= 10) && (navioY >= 0 && navioY <= 10)) {
                tabuleiro[navioX][navioY] = 3;
            } else {
                printf("\nCoordenadas do navio 2 inválidas");
                return 0;
            }
            tabuleiro[navioX][navioY] = 3;
        } else {
            printf("Sobreposição de navios.\n");
            return 0;
        }
    }

    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.
    printf("\n");

    for (int i = 0; i < 10; i++) {

        //imprimir as letras das posições verticais (A - J)
        if (i == 0) {
            //adiciona três caracteres de espaço no começo da linha, para ficarem alinhados
            printf("%*c", 3, ' ');
            for (int k = 0; k < 10; k++, verticalIndex++) {
                printf("%c ", (char) verticalIndex);
            }            
            printf("\n");
        }

        //imprimir o valor de cada posição do tabuleiro
        //acessar cada posição dentro da linha horizontal
        for (int j = 0; j < 10; j++) {
            
            //imprimir índice das posições horizontais (1 - 10) na primeira coluna
            if (j == 0) {
                //adiciona um caractere de espaço antes do índice, exceto 10, para ficarem alinhados
                if (i < 9) {
                    printf("%*c", 1, ' ');
                }
                printf("%d ", ++horizontalIndex);
            }

            //imprimir valor da posição no tabuleiro
            printf("%d ", tabuleiro[i][j]);
        } 

        printf("\n");  
    }
    
    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

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

    return 0;
}
