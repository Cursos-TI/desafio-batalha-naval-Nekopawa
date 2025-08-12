#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    
    #define tamanhoTabuleiro 10
    #define tamanhoHabilidadeX 3
    #define tamanhoHabilidadeY 5
    #define tamanhoNavio 3
    #define AGUA 0
    #define NAVIO 3
    #define HABILIDADE 1

    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    int tabuleiro[10][10];
    int navioX;
    int navioY;

    //preenche cada posição do tabuleiro com 0
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = AGUA;
        }        
    }

    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    
    //navio vertical
    navioX = 1;
    navioY = 0;

    printf("\n");
    //valida coordenadas iniciais e finais do navio
    if ((navioX >= 0 && navioX < 10) && (navioX + 2 >= 0 && navioX + 2 < 10) 
        && (navioY >= 0 && navioY < 10)) {        
        for (int i = 0; i < tamanhoNavio; i++) {
            //evita sobreposição
            if (tabuleiro[navioX][navioY] == AGUA) {
                //mudar posição do tabuleiro para 3 quando tem um navio
                printf("Coordenadas navio 1: X: %d | Y: %d\n", navioX, navioY);
                tabuleiro[navioX][navioY] = NAVIO;
                navioX++;
            } else {
                printf("Sobreposição de navios.\n");
                return 0;
            }
        }
    } else {
        printf("\nCoordenadas do navio 1 inválidas");
        return 0;
    }
 
    //navio horizontal
    navioX = 5;
    navioY = 4;

    printf("\n");
    //valida coordenadas iniciais e finais do navio
    if ((navioX >= 0 && navioX < 10) 
        && (navioY >= 0 && navioY < 10) && (navioY + 2 >= 0 && navioY + 2 < 10)) {
        for (int i = 0; i < tamanhoNavio; i++) {
            //evita sobreposição
            if (tabuleiro[navioX][navioY] == AGUA) {
                //mudar posição do tabuleiro para 3 quando tem um navio
                printf("Coordenadas navio 2: X: %d | Y: %d\n", navioX, navioY);
                tabuleiro[navioX][navioY] = NAVIO;
                navioY++;
            } else {
                printf("Sobreposição de navios.\n");
                return 0;
            }
        }
    } else {
        printf("\nCoordenadas do navio 2 inválidas");
        return 0;
    }
        
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.
    
    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // navio diagonal 1
    navioX = 2;
    navioY = 2;
    
    printf("\n");
    //valida coordenadas iniciais e finais do navio
    if ((navioX >= 0 && navioX < 10) && (navioX + 2 >= 0 && navioX + 2 < 10) 
        && (navioY >= 0 && navioY < 10) && (navioY + 2 >= 0 && navioY + 2 < 10)) {
        for (int i = 0; i < tamanhoNavio; i++) {
            //valida sobreposição
            if (tabuleiro[navioX][navioY] == AGUA) {
                printf("Coordenadas navio diagonal 1: X: %d | Y: %d\n", navioX, navioY);
                tabuleiro[navioX][navioY] = NAVIO;
                navioX++;
                navioY++;
            } else {
                printf("Sobreposição de navios.\n");
                return 0;
            }    
        }
    } else {
        printf("\nCoordenadas do navio diagonal 1 inválidas");
        return 0;
    }
    
    // navio diagonal 2
    navioX = 0;
    navioY = 9;

    printf("\n");
    //valida coordenadas iniciais e finais do navio
    if ((navioX >= 0 && navioX < 10) && (navioX + 2 >= 0 && navioX + 2 < 10) 
        && (navioY >= 0 && navioY < 10) && (navioY - 2 >= 0 && navioY - 2 < 10)) {
        for (int i = 0; i < tamanhoNavio; i++) {
            //valida sobreposição
            if (tabuleiro[navioX][navioY] == AGUA) {
                printf("Coordenadas navio diagonal 2: X: %d | Y: %d\n", navioX, navioY);
                tabuleiro[navioX][navioY] = NAVIO;
                navioX++;
                navioY--;
            } else {
                printf("Sobreposição de navios.\n");
                return 0;
            }
        }
    } else {
        printf("\nCoordenadas do navio diagonal 2 inválidas");
        return 0;
    }

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.
    int metadeY = tamanhoHabilidadeY / 2;
    int metadeX = tamanhoHabilidadeX / 2;

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    printf("\nHabilidade cone:\n");
    int habilidadeCone[tamanhoHabilidadeX][tamanhoHabilidadeY];
    for (int i = 0; i < tamanhoHabilidadeX; i++) {
        for (int j = 0; j < tamanhoHabilidadeY; j++) {
            if (j >= metadeY - i && j <= metadeY + i) {
                habilidadeCone[i][j] = HABILIDADE;
            } else {
                habilidadeCone[i][j] = AGUA;
            }
            printf("%d ", habilidadeCone[i][j]);
        }
        printf("\n");
    }

    // posição da habilidade no tabuleiro
    int habilidadeX = 2;
    int habilidadeY = 2;

    for (int i = 0; i < tamanhoHabilidadeX; i++) {
        for (int j = 0; j < tamanhoHabilidadeY; j++) {
            int posicaoX = habilidadeX + i;
            int posicaoY = habilidadeY + j;
            
            //validar se está dentro do tabuleiro
            if ((posicaoX >= 0 && posicaoX < tamanhoTabuleiro)
                && (posicaoY >= 0 && posicaoY < tamanhoTabuleiro)) {
                if (habilidadeCone[i][j] == HABILIDADE && tabuleiro[posicaoX][posicaoY] == AGUA) {
                    tabuleiro[posicaoX][posicaoY] = HABILIDADE;
                }
            }
        }
    }
       
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0
    printf("\nHabilidade octaedro:\n");
    
    int habilidadeOctaedro[tamanhoHabilidadeX][tamanhoHabilidadeY];
    for (int i = 0; i < tamanhoHabilidadeX; i++) {
        for (int j = 0; j < tamanhoHabilidadeY; j++) {
            if ((j >= metadeY - i && j <= metadeY + i && i <= metadeX) 
                || (j > metadeY - tamanhoHabilidadeX + i && j < metadeY + tamanhoHabilidadeX - i && i > metadeX)) {
                    habilidadeOctaedro[i][j] = HABILIDADE;
            } else {
                habilidadeOctaedro[i][j] = AGUA;
            }
            printf("%d ", habilidadeOctaedro[i][j]);
        }
        printf("\n");
    }

    habilidadeX = 5;
    habilidadeY = 7;

    for (int i = 0; i < tamanhoHabilidadeX; i++) {
        for (int j = 0; j < tamanhoHabilidadeY; j++) {
            int posicaoX = habilidadeX + i;
            int posicaoY = habilidadeY + j;
            
            //validar se está dentro do tabuleiro
            if ((posicaoX >= 0 && posicaoX < tamanhoTabuleiro)
                && (posicaoY >= 0 && posicaoY < tamanhoTabuleiro)) {
                if (habilidadeOctaedro[i][j] == HABILIDADE && tabuleiro[posicaoX][posicaoY] == AGUA) {
                    tabuleiro[posicaoX][posicaoY] = HABILIDADE;
                }
            }
        }
    }

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0
    printf("\nHabilidade cruz:\n");
    
    int habilidadeCruz[tamanhoHabilidadeX][tamanhoHabilidadeY];
    for (int i = 0; i < tamanhoHabilidadeX; i++) {
        for (int j = 0; j < tamanhoHabilidadeY; j++) {
            if (j == metadeY || i == metadeX) {
                habilidadeCruz[i][j] = HABILIDADE;
            } else {
                habilidadeCruz[i][j] = AGUA;
            }
            printf("%d ", habilidadeCruz[i][j]);
        }
        printf("\n");        
    }

    habilidadeX = 8;
    habilidadeY = 4;

    for (int i = 0; i < tamanhoHabilidadeX; i++) {
        for (int j = 0; j < tamanhoHabilidadeY; j++) {
            int posicaoX = habilidadeX + i;
            int posicaoY = habilidadeY + j;
            
            //validar se está dentro do tabuleiro
            if ((posicaoX >= 0 && posicaoX < tamanhoTabuleiro)
                && (posicaoY >= 0 && posicaoY < tamanhoTabuleiro)) {
                if (habilidadeCruz[i][j] == HABILIDADE && tabuleiro[posicaoX][posicaoY] == AGUA) {
                    tabuleiro[posicaoX][posicaoY] = HABILIDADE;
                }
            }
        }
    }

    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.
    printf("\n");

    char verticalIndex = 'A';
    int horizontalIndex = 0;

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

    return 0;
}
