#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{

    char tab[8][8]; // Tabuleiro 8X8.
    int iColuna;    // Posição inicial.
    int iLinha;     // Posição inicial.
    int aux = 0;    // Auxiliar de posição.
    int fLinha;     // fLinha posição para onde a peça será movida.
    int fColuna;    // fColuna posição para onde a peça será movida.
    int pretas = 1;
    int brancas = 1;

    // CRIAÇÃO E IMPRESSÃO DO TABULEIRO
    // UTILIZA UMA VARIÁVEL AUXILIAR PARA QUE AS PEÇAS SEJAM DISPOSTAS DE MANEIRA SIM/NAO/SIM
    // PARA ISSO É UTILIZADO SISTEMA DE PAR OU ÍMPAR

    for (iLinha = 0; iLinha < 3; iLinha++)
    {
        if (iLinha % 2 == 0)
        {
            aux = 1;
        }
        else
        {
            aux = 0;
        }
        for (iColuna = 0; iColuna < 8; iColuna++, aux++) // iMPRIME AS PRETAS
        {

            if (aux % 2 == 0)
            {
                tab[iColuna][iLinha] = 49;
            }
            else
            {
                tab[iColuna][iLinha] = 32;
            }
        }
    }
    for (iLinha = 3; iLinha < 5; iLinha++)
    {
        for (iColuna = 0; iColuna < 8; iColuna++)
        {
            tab[iColuna][iLinha] = 32;
        }
    }

    for (iLinha = 5; iLinha < 6; iLinha++)
    {
        if (iLinha % 2 == 0)
        {
            aux = 1;
        }
        else
        {
            aux = 0;
        }
        for (iColuna = 0; iColuna < 2; iColuna++, aux++) // iMPRIME AS BRANCAS
        {
            if (aux % 2 == 0)
            {

                tab[iColuna][iLinha] = 50;
            }
            else
            {
                tab[iColuna][iLinha] = 32;
            }
        }
    }
    // IMPRESSãO DO TABULEIRO:
    printf("    0   1   2   3   4   5   6   7\n");
    printf("  |---|---|---|---|---|---|---|---|\n");
    for (iLinha = 0; iLinha < 8; iLinha++)
    {
        printf("%d ", iLinha);
        for (iColuna = 0; iColuna < 8; iColuna++)
        {

            printf("| %c ", tab[iColuna][iLinha]);

            if (iColuna == 7)
            {
                printf("|%d \n", iLinha);
            }
        }

        printf("  |---|---|---|---|---|---|---|---|\n");
    }
    printf("    0   1   2   3   4   5   6   7");

    while (pretas != 0 && brancas != 0)
    {

        while (1)
        {

            printf("\n\nJogador 1 \n");
            scanf("%d %d", &iLinha, &iColuna);
            scanf("%d %d", &fLinha, &fColuna);

            // Captura dama
            //  Captura para direita e para baixo
            if (((((fColuna == iColuna + 2) && ((fColuna >= 0) && (fColuna < 8))) && ((fLinha == iLinha + 2) && ((fLinha >= 0) && (fLinha < 8)))) && tab[iColuna][iLinha] == 51) && tab[fColuna][fLinha] == 32)
            {
                printf("\n-115\n");
                if ((tab[iColuna + 1][iLinha + 1] == 50) || (tab[iColuna + 1][iLinha + 1] == 52))
                {
                    tab[iColuna + 1][iLinha + 1] = 32;
                }
                else
                {
                    printf("\n-121\n");
                    printf("movimento invalido");
                    continue;
                }

                tab[iColuna][iLinha] = 32;
                tab[fColuna][fLinha] = 51;

                break;
            }
            // Captura para esqueda e para baixo
            if (((((fColuna == iColuna - 2) && ((fColuna >= 0) && (fColuna < 8))) && ((fLinha == iLinha + 2) && ((fLinha >= 0) && (fLinha < 8)))) && tab[iColuna][iLinha] == 51) && tab[fColuna][fLinha] == 32)
            {
                printf("\n-133\n");

                if ((tab[iColuna - 1][iLinha + 1] == 50) || (tab[iColuna - 1][iLinha + 1] == 52))
                {
                    tab[iColuna - 1][iLinha + 1] = 32;
                }
                else
                {
                    printf("\n-140\n");
                    printf("movimento invalido");
                    continue;
                }

                tab[iColuna][iLinha] = 32;
                tab[fColuna][fLinha] = 51;

                break;
            }
            // Captura para direita e para cima
            if (((((fColuna == iColuna + 2) && ((fColuna >= 0) && (fColuna < 8))) && ((fLinha == iLinha - 2) && ((fLinha >= 0) && (fLinha < 8)))) && tab[iColuna][iLinha] == 51) && tab[fColuna][fLinha] == 32)
            {
                printf("\n-152\n");
                if ((tab[iColuna + 1][iLinha - 1] == 50) || (tab[iColuna + 1][iLinha - 1] == 52))
                {
                    tab[iColuna + 1][iLinha - 1] = 32;
                }
                else
                {
                    printf("\n-158\n");
                    printf("movimento invalido");
                    continue;
                }

                tab[iColuna][iLinha] = 32;
                tab[fColuna][fLinha] = 51;

                break;
            }
            // Captura para esquerda e para cima
            if (((((fColuna == iColuna - 2) && ((fColuna >= 0) && (fColuna < 8))) && ((fLinha == iLinha - 2) && ((fLinha >= 0) && (fLinha < 8)))) && tab[iColuna][iLinha] == 51) && tab[fColuna][fLinha] == 32)
            {
                printf("\n-170\n");
                if ((tab[iColuna - 1][iLinha - 1] == 50) || (tab[iColuna - 1][iLinha - 1] == 52))
                {
                    tab[iColuna - 1][iLinha - 1] = 32;
                }
                else
                {
                    printf("\n-176\n");
                    printf("movimento invalido");
                    continue;
                }

                tab[iColuna][iLinha] = 32;
                tab[fColuna][fLinha] = 51;

                break;
            }

            // Movimento dama

            if (((((((fColuna == iColuna + 1) || (fColuna == iColuna - 1)) && ((fColuna >= 0) && (fColuna < 8))) && (((fLinha == iLinha + 1) || (fLinha == iLinha - 1)) && ((fLinha >= 0) && (fLinha < 8)))) && tab[fColuna][fLinha] == 32) && tab[iColuna][iLinha] == 51))
            {
                printf("\n-190\n");
                tab[iColuna][iLinha] = 32;
                tab[fColuna][fLinha] = 51;
                break;
            }

            // CAPTURA PEÇA NORMAL

            // Captura para direita E PARA BAIXO
            if (((((fColuna == iColuna + 2) && ((fColuna >= 0) && (fColuna < 8))) && ((fLinha == iLinha + 2) && ((fLinha >= 0) && (fLinha < 8)))) && tab[iColuna][iLinha] == 49) && tab[fColuna][fLinha] == 32)
            {
                printf("\n-206\n");
                if ((tab[iColuna + 1][iLinha + 1] == 50) || (tab[iColuna + 1][iLinha + 1] == 52))
                {
                    tab[iColuna + 1][iLinha + 1] = 32;
                }
                else
                {
                    printf("\n-212\n");
                    printf("movimento invalido");
                    continue;
                }

                tab[iColuna][iLinha] = 32;
                tab[fColuna][fLinha] = 49;

                // VERIFICA SE AINDA EXISTE PEÇAS A SEREM CAPTURADAS
                // VERIFICA PARA BAIXO E PARA DIREITA
                if (((((tab[fColuna + 1][fLinha + 1] == 50) || (tab[fColuna + 1][fLinha + 1] == 52) && ((fLinha + 2 >= 0) && (fLinha + 2 < 8))) && (tab[fColuna + 2][fLinha + 2] == 32)) && (fColuna + 2 >= 0) && (fColuna + 2 < 8)))
                {
                    system("CLS");
                    // IMPRESSãO DO TABULEIRO:
                    printf("    0   1   2   3   4   5   6   7\n");
                    printf("  |---|---|---|---|---|---|---|---|\n");
                    for (iLinha = 0; iLinha < 8; iLinha++)
                    {
                        printf("%d ", iLinha);
                        for (iColuna = 0; iColuna < 8; iColuna++)
                        {

                            printf("| %c ", tab[iColuna][iLinha]);

                            if (iColuna == 7)
                            {
                                printf("|%d \n", iLinha);
                            }
                        }

                        printf("  |---|---|---|---|---|---|---|---|\n");
                    }
                    printf("    0   1   2   3   4   5   6   7");
                    printf("\nAinde existem peças a serem capturradas e a captura e obrigatoria!");

                    continue;
                }
                // VERIFICA PARA CIMA E PARA DIREITA
                if (((tab[fColuna + 1][fLinha - 1] == 50) || (tab[fColuna + 1][fLinha - 1] == 52) && ((fLinha - 2 >= 0) && (fLinha - 2 < 8))) && (tab[fColuna + 2][fLinha - 2] == 32) && (fColuna + 2 >= 0) && (fColuna + 2 < 8))
                {
                    system("CLS");
                    // IMPRESSãO DO TABULEIRO:
                    printf("    0   1   2   3   4   5   6   7\n");
                    printf("  |---|---|---|---|---|---|---|---|\n");
                    for (iLinha = 0; iLinha < 8; iLinha++)
                    {
                        printf("%d ", iLinha);
                        for (iColuna = 0; iColuna < 8; iColuna++)
                        {

                            printf("| %c ", tab[iColuna][iLinha]);

                            if (iColuna == 7)
                            {
                                printf("|%d \n", iLinha);
                            }
                        }

                        printf("  |---|---|---|---|---|---|---|---|\n");
                    }
                    printf("    0   1   2   3   4   5   6   7");
                    printf("\nAinde existem peças a serem capturradas e a captura e obrigatoria!");

                    continue;
                }

                // VERIFICA PARA ESQUERDA E PARA BAIXO
                if (((tab[fColuna - 1][fLinha + 1] == 50) || (tab[fColuna - 1][fLinha + 1] == 52) && ((fLinha + 2 >= 0) && (fLinha + 2 < 8))) && (tab[fColuna - 2][fLinha + 2] == 32) && (fColuna - 2 >= 0) && (fColuna - 2 < 8))
                {
                    system("CLS");
                    // IMPRESSãO DO TABULEIRO:
                    printf("    0   1   2   3   4   5   6   7\n");
                    printf("  |---|---|---|---|---|---|---|---|\n");
                    for (iLinha = 0; iLinha < 8; iLinha++)
                    {
                        printf("%d ", iLinha);
                        for (iColuna = 0; iColuna < 8; iColuna++)
                        {

                            printf("| %c ", tab[iColuna][iLinha]);

                            if (iColuna == 7)
                            {
                                printf("|%d \n", iLinha);
                            }
                        }

                        printf("  |---|---|---|---|---|---|---|---|\n");
                    }
                    printf("    0   1   2   3   4   5   6   7");
                    printf("\nAinde existem peças a serem capturradas e a captura e obrigatoria!");

                    continue;
                }

                // VERIFICA PARA ESQUERDA E PARA CIMA
                if (((tab[fColuna - 1][fLinha - 1] == 50) || (tab[fColuna - 1][fLinha - 1] == 52) && ((fLinha - 2 >= 0) && (fLinha - 2 < 8))) && (tab[fColuna - 2][fLinha - 2] == 32) && (fColuna - 2 >= 0) && (fColuna - 2 < 8))
                {
                    system("CLS");
                    // IMPRESSãO DO TABULEIRO:
                    printf("    0   1   2   3   4   5   6   7\n");
                    printf("  |---|---|---|---|---|---|---|---|\n");
                    for (iLinha = 0; iLinha < 8; iLinha++)
                    {
                        printf("%d ", iLinha);
                        for (iColuna = 0; iColuna < 8; iColuna++)
                        {

                            printf("| %c ", tab[iColuna][iLinha]);

                            if (iColuna == 7)
                            {
                                printf("|%d \n", iLinha);
                            }
                        }

                        printf("  |---|---|---|---|---|---|---|---|\n");
                    }
                    printf("    0   1   2   3   4   5   6   7");
                    printf("\nAinde existem peças a serem capturradas e a captura e obrigatoria!");

                    continue;
                }

                break;
            }

            // Captura para direita E PARA CIMA
            if (((((fColuna == iColuna + 2) && ((fColuna >= 0) && (fColuna < 8))) && ((fLinha == iLinha - 2) && ((fLinha >= 0) && (fLinha < 8)))) && tab[iColuna][iLinha] == 49) && tab[fColuna][fLinha] == 32)
            {
                printf("\n-224\n");
                if ((tab[iColuna + 1][iLinha - 1] == 50) || (tab[iColuna + 1][iLinha - 1] == 52))
                {
                    tab[iColuna + 1][iLinha - 1] = 32;
                }
                else
                {
                    printf("\n-1230\n");
                    printf("movimento invalido");
                    continue;
                }

                tab[iColuna][iLinha] = 32;
                tab[fColuna][fLinha] = 49;

                // VERIFICA SE AINDA EXISTE PEÇAS A SEREM CAPTURADAS
                // VERIFICA PARA BAIXO E PARA DIREITA
                if (((tab[fColuna + 1][fLinha + 1] == 50) || (tab[fColuna + 1][fLinha + 1] == 52) && ((fLinha + 2 >= 0) && (fLinha + 2 < 8))) && (tab[fColuna + 2][fLinha + 2] == 32) && (fColuna + 2 >= 0) && (fColuna + 2 < 8))
                {
                    system("CLS");
                    // IMPRESSãO DO TABULEIRO:
                    printf("    0   1   2   3   4   5   6   7\n");
                    printf("  |---|---|---|---|---|---|---|---|\n");
                    for (iLinha = 0; iLinha < 8; iLinha++)
                    {
                        printf("%d ", iLinha);
                        for (iColuna = 0; iColuna < 8; iColuna++)
                        {

                            printf("| %c ", tab[iColuna][iLinha]);

                            if (iColuna == 7)
                            {
                                printf("|%d \n", iLinha);
                            }
                        }

                        printf("  |---|---|---|---|---|---|---|---|\n");
                    }
                    printf("    0   1   2   3   4   5   6   7");
                    printf("\nAinde existem peças a serem capturradas e a captura e obrigatoria!");

                    continue;
                }
                // VERIFICA PARA CIMA E PARA DIREITA
                if (((tab[fColuna + 1][fLinha - 1] == 50) || (tab[fColuna + 1][fLinha - 1] == 52) && ((fLinha - 2 >= 0) && (fLinha - 2 < 8))) && (tab[fColuna + 2][fLinha - 2] == 32) && (fColuna + 2 >= 0) && (fColuna + 2 < 8))
                {
                    system("CLS");
                    // IMPRESSãO DO TABULEIRO:
                    printf("    0   1   2   3   4   5   6   7\n");
                    printf("  |---|---|---|---|---|---|---|---|\n");
                    for (iLinha = 0; iLinha < 8; iLinha++)
                    {
                        printf("%d ", iLinha);
                        for (iColuna = 0; iColuna < 8; iColuna++)
                        {

                            printf("| %c ", tab[iColuna][iLinha]);

                            if (iColuna == 7)
                            {
                                printf("|%d \n", iLinha);
                            }
                        }

                        printf("  |---|---|---|---|---|---|---|---|\n");
                    }
                    printf("    0   1   2   3   4   5   6   7");
                    printf("\nAinde existem peças a serem capturradas e a captura e obrigatoria!");

                    continue;
                }

                // VERIFICA PARA ESQUERDA E PARA BAIXO
                if (((tab[fColuna - 1][fLinha + 1] == 50) || (tab[fColuna - 1][fLinha + 1] == 52) && ((fLinha + 2 >= 0) && (fLinha + 2 < 8))) && (tab[fColuna - 2][fLinha + 2] == 32) && (fColuna - 2 >= 0) && (fColuna - 2 < 8))
                {
                    system("CLS");
                    // IMPRESSãO DO TABULEIRO:
                    printf("    0   1   2   3   4   5   6   7\n");
                    printf("  |---|---|---|---|---|---|---|---|\n");
                    for (iLinha = 0; iLinha < 8; iLinha++)
                    {
                        printf("%d ", iLinha);
                        for (iColuna = 0; iColuna < 8; iColuna++)
                        {

                            printf("| %c ", tab[iColuna][iLinha]);

                            if (iColuna == 7)
                            {
                                printf("|%d \n", iLinha);
                            }
                        }

                        printf("  |---|---|---|---|---|---|---|---|\n");
                    }
                    printf("    0   1   2   3   4   5   6   7");
                    printf("\nAinde existem peças a serem capturradas e a captura e obrigatoria!");

                    continue;
                }

                // VERIFICA PARA ESQUERDA E PARA CIMA
                if (((tab[fColuna - 1][fLinha - 1] == 50) || (tab[fColuna - 1][fLinha - 1] == 52) && ((fLinha - 2 >= 0) && (fLinha - 2 < 8))) && (tab[fColuna - 2][fLinha - 2] == 32) && (fColuna - 2 >= 0) && (fColuna - 2 < 8))
                {
                    system("CLS");
                    // IMPRESSãO DO TABULEIRO:
                    printf("    0   1   2   3   4   5   6   7\n");
                    printf("  |---|---|---|---|---|---|---|---|\n");
                    for (iLinha = 0; iLinha < 8; iLinha++)
                    {
                        printf("%d ", iLinha);
                        for (iColuna = 0; iColuna < 8; iColuna++)
                        {

                            printf("| %c ", tab[iColuna][iLinha]);

                            if (iColuna == 7)
                            {
                                printf("|%d \n", iLinha);
                            }
                        }

                        printf("  |---|---|---|---|---|---|---|---|\n");
                    }
                    printf("    0   1   2   3   4   5   6   7");
                    printf("\nAinde existem peças a serem capturradas e a captura e obrigatoria!");

                    continue;
                }

                break;
            }

            // Captura para esqueda E PARA BAIXO
            if (((((fColuna == iColuna - 2) && ((fColuna >= 0) && (fColuna < 8))) && ((fLinha == iLinha + 2) && ((fLinha >= 0) && (fLinha < 8)))) && tab[iColuna][iLinha] == 49) && tab[fColuna][fLinha] == 32)
            {
                printf("\n-242\n");

                if ((tab[iColuna - 1][iLinha + 1] == 50) || (tab[iColuna - 1][iLinha + 1] == 52))
                {
                    tab[iColuna - 1][iLinha + 1] = 32;
                }
                else
                {
                    printf("\n-249\n");
                    printf("movimento invalido");
                    continue;
                }

                tab[iColuna][iLinha] = 32;
                tab[fColuna][fLinha] = 49;

                // VERIFICA SE AINDA EXISTE PEÇAS A SEREM CAPTURADAS
                // VERIFICA PARA BAIXO E PARA DIREITA
                if (((tab[fColuna + 1][fLinha + 1] == 50) || (tab[fColuna + 1][fLinha + 1] == 52) && ((fLinha + 2 >= 0) && (fLinha + 2 < 8))) && (tab[fColuna + 2][fLinha + 2] == 32) && (fColuna + 2 >= 0) && (fColuna + 2 < 8))
                {
                    system("CLS");
                    // IMPRESSãO DO TABULEIRO:
                    printf("    0   1   2   3   4   5   6   7\n");
                    printf("  |---|---|---|---|---|---|---|---|\n");
                    for (iLinha = 0; iLinha < 8; iLinha++)
                    {
                        printf("%d ", iLinha);
                        for (iColuna = 0; iColuna < 8; iColuna++)
                        {

                            printf("| %c ", tab[iColuna][iLinha]);

                            if (iColuna == 7)
                            {
                                printf("|%d \n", iLinha);
                            }
                        }

                        printf("  |---|---|---|---|---|---|---|---|\n");
                    }
                    printf("    0   1   2   3   4   5   6   7");
                    printf("\nAinde existem peças a serem capturradas e a captura e obrigatoria!");

                    continue;
                }
                // VERIFICA PARA CIMA E PARA DIREITA
                if (((tab[fColuna + 1][fLinha - 1] == 50) || (tab[fColuna + 1][fLinha - 1] == 52) && ((fLinha - 2 >= 0) && (fLinha - 2 < 8))) && (tab[fColuna + 2][fLinha - 2] == 32) && (fColuna + 2 >= 0) && (fColuna + 2 < 8))
                {
                    system("CLS");
                    // IMPRESSãO DO TABULEIRO:
                    printf("    0   1   2   3   4   5   6   7\n");
                    printf("  |---|---|---|---|---|---|---|---|\n");
                    for (iLinha = 0; iLinha < 8; iLinha++)
                    {
                        printf("%d ", iLinha);
                        for (iColuna = 0; iColuna < 8; iColuna++)
                        {

                            printf("| %c ", tab[iColuna][iLinha]);

                            if (iColuna == 7)
                            {
                                printf("|%d \n", iLinha);
                            }
                        }

                        printf("  |---|---|---|---|---|---|---|---|\n");
                    }
                    printf("    0   1   2   3   4   5   6   7");
                    printf("\nAinde existem peças a serem capturradas e a captura e obrigatoria!");

                    continue;
                }

                // VERIFICA PARA ESQUERDA E PARA BAIXO
                if (((tab[fColuna - 1][fLinha + 1] == 50) || (tab[fColuna - 1][fLinha + 1] == 52) && ((fLinha + 2 >= 0) && (fLinha + 2 < 8))) && (tab[fColuna - 2][fLinha + 2] == 32) && (fColuna - 2 >= 0) && (fColuna - 2 < 8))
                {
                    system("CLS");
                    // IMPRESSãO DO TABULEIRO:
                    printf("    0   1   2   3   4   5   6   7\n");
                    printf("  |---|---|---|---|---|---|---|---|\n");
                    for (iLinha = 0; iLinha < 8; iLinha++)
                    {
                        printf("%d ", iLinha);
                        for (iColuna = 0; iColuna < 8; iColuna++)
                        {

                            printf("| %c ", tab[iColuna][iLinha]);

                            if (iColuna == 7)
                            {
                                printf("|%d \n", iLinha);
                            }
                        }

                        printf("  |---|---|---|---|---|---|---|---|\n");
                    }
                    printf("    0   1   2   3   4   5   6   7");
                    printf("\nAinde existem peças a serem capturradas e a captura e obrigatoria!");

                    continue;
                }

                // VERIFICA PARA ESQUERDA E PARA CIMA
                if (((tab[fColuna - 1][fLinha - 1] == 50) || (tab[fColuna - 1][fLinha - 1] == 52) && ((fLinha - 2 >= 0) && (fLinha - 2 < 8))) && (tab[fColuna - 2][fLinha - 2] == 32) && (fColuna - 2 >= 0) && (fColuna - 2 < 8))
                {
                    system("CLS");
                    // IMPRESSãO DO TABULEIRO:
                    printf("    0   1   2   3   4   5   6   7\n");
                    printf("  |---|---|---|---|---|---|---|---|\n");
                    for (iLinha = 0; iLinha < 8; iLinha++)
                    {
                        printf("%d ", iLinha);
                        for (iColuna = 0; iColuna < 8; iColuna++)
                        {

                            printf("| %c ", tab[iColuna][iLinha]);

                            if (iColuna == 7)
                            {
                                printf("|%d \n", iLinha);
                            }
                        }

                        printf("  |---|---|---|---|---|---|---|---|\n");
                    }
                    printf("    0   1   2   3   4   5   6   7");
                    printf("\nAinde existem peças a serem capturradas e a captura e obrigatoria!");

                    continue;
                }

                break;
            }

            // Captura para esqueda E PARA CIMA
            if (((((fColuna == iColuna - 2) && ((fColuna >= 0) && (fColuna < 8))) && ((fLinha == iLinha - 2) && ((fLinha >= 0) && (fLinha < 8)))) && tab[iColuna][iLinha] == 49) && tab[fColuna][fLinha] == 32)
            {
                printf("\n-261\n");

                if ((tab[iColuna - 1][iLinha - 1] == 50) || (tab[iColuna - 1][iLinha - 1] == 52))
                {
                    tab[iColuna - 1][iLinha - 1] = 32;
                }
                else
                {
                    printf("\n-268\n");
                    printf("movimento invalido");
                    continue;
                }

                tab[iColuna][iLinha] = 32;
                tab[fColuna][fLinha] = 49;

                // VERIFICA SE AINDA EXISTE PEÇAS A SEREM CAPTURADAS
                // VERIFICA PARA BAIXO E PARA DIREITA
                if (((tab[fColuna + 1][fLinha + 1] == 50) || (tab[fColuna + 1][fLinha + 1] == 52) && ((fLinha + 2 >= 0) && (fLinha + 2 < 8))) && (tab[fColuna + 2][fLinha + 2] == 32) && (fColuna + 2 >= 0) && (fColuna + 2 < 8))
                {
                    system("CLS");
                    // IMPRESSãO DO TABULEIRO:
                    printf("    0   1   2   3   4   5   6   7\n");
                    printf("  |---|---|---|---|---|---|---|---|\n");
                    for (iLinha = 0; iLinha < 8; iLinha++)
                    {
                        printf("%d ", iLinha);
                        for (iColuna = 0; iColuna < 8; iColuna++)
                        {

                            printf("| %c ", tab[iColuna][iLinha]);

                            if (iColuna == 7)
                            {
                                printf("|%d \n", iLinha);
                            }
                        }

                        printf("  |---|---|---|---|---|---|---|---|\n");
                    }
                    printf("    0   1   2   3   4   5   6   7");
                    printf("\nAinde existem peças a serem capturradas e a captura e obrigatoria!");

                    continue;
                }
                // VERIFICA PARA CIMA E PARA DIREITA
                if (((tab[fColuna + 1][fLinha - 1] == 50) || (tab[fColuna + 1][fLinha - 1] == 52) && ((fLinha - 2 >= 0) && (fLinha - 2 < 8))) && (tab[fColuna + 2][fLinha - 2] == 32) && (fColuna + 2 >= 0) && (fColuna + 2 < 8))
                {
                    system("CLS");
                    // IMPRESSãO DO TABULEIRO:
                    printf("    0   1   2   3   4   5   6   7\n");
                    printf("  |---|---|---|---|---|---|---|---|\n");
                    for (iLinha = 0; iLinha < 8; iLinha++)
                    {
                        printf("%d ", iLinha);
                        for (iColuna = 0; iColuna < 8; iColuna++)
                        {

                            printf("| %c ", tab[iColuna][iLinha]);

                            if (iColuna == 7)
                            {
                                printf("|%d \n", iLinha);
                            }
                        }

                        printf("  |---|---|---|---|---|---|---|---|\n");
                    }
                    printf("    0   1   2   3   4   5   6   7");
                    printf("\nAinde existem peças a serem capturradas e a captura e obrigatoria!");

                    continue;
                }

                // VERIFICA PARA ESQUERDA E PARA BAIXO
                if (((tab[fColuna - 1][fLinha + 1] == 50) || (tab[fColuna - 1][fLinha + 1] == 52) && ((fLinha + 2 >= 0) && (fLinha + 2 < 8))) && (tab[fColuna - 2][fLinha + 2] == 32) && (fColuna - 2 >= 0) && (fColuna - 2 < 8))
                {
                    system("CLS");
                    // IMPRESSãO DO TABULEIRO:
                    printf("    0   1   2   3   4   5   6   7\n");
                    printf("  |---|---|---|---|---|---|---|---|\n");
                    for (iLinha = 0; iLinha < 8; iLinha++)
                    {
                        printf("%d ", iLinha);
                        for (iColuna = 0; iColuna < 8; iColuna++)
                        {

                            printf("| %c ", tab[iColuna][iLinha]);

                            if (iColuna == 7)
                            {
                                printf("|%d \n", iLinha);
                            }
                        }

                        printf("  |---|---|---|---|---|---|---|---|\n");
                    }
                    printf("    0   1   2   3   4   5   6   7");
                    printf("\nAinde existem peças a serem capturradas e a captura e obrigatoria!");

                    continue;
                }

                // VERIFICA PARA ESQUERDA E PARA CIMA
                if (((tab[fColuna - 1][fLinha - 1] == 50) || (tab[fColuna - 1][fLinha - 1] == 52) && ((fLinha - 2 >= 0) && (fLinha - 2 < 8))) && (tab[fColuna - 2][fLinha - 2] == 32) && (fColuna - 2 >= 0) && (fColuna - 2 < 8))
                {
                    system("CLS");
                    // IMPRESSãO DO TABULEIRO:
                    printf("    0   1   2   3   4   5   6   7\n");
                    printf("  |---|---|---|---|---|---|---|---|\n");
                    for (iLinha = 0; iLinha < 8; iLinha++)
                    {
                        printf("%d ", iLinha);
                        for (iColuna = 0; iColuna < 8; iColuna++)
                        {

                            printf("| %c ", tab[iColuna][iLinha]);

                            if (iColuna == 7)
                            {
                                printf("|%d \n", iLinha);
                            }
                        }

                        printf("  |---|---|---|---|---|---|---|---|\n");
                    }
                    printf("    0   1   2   3   4   5   6   7");
                    printf("\nAinde existem peças a serem capturradas e a captura e obrigatoria!");

                    continue;
                }

                break;
            }

            // Movimento da peça

            if (((((((fColuna == iColuna + 1) || (fColuna == iColuna - 1)) && ((fColuna >= 0) && (fColuna < 8))) && (((fLinha == iLinha + 1)) && ((fLinha >= 0) && (fLinha < 8)))) && tab[fColuna][fLinha] == 32) && tab[iColuna][iLinha] == 49))
            {
                printf("\n-284\n");
                tab[iColuna][iLinha] = 32;
                tab[fColuna][fLinha] = 49;
                break;
            }
            else
            {
                printf("\n-290\n");
                printf("movimento invalido");
                continue;
            }
        }
        system("CLS");

        // VERIFICA SE VIROU DAMA:
        for (iColuna = 0; iColuna < 8; iColuna++)
        {
            if (tab[iColuna][7] == 49)
            {
                tab[iColuna][7] = 51;
            }
        }

        // IMPRESSãO DO TABULEIRO:
        printf("    0   1   2   3   4   5   6   7\n");
        printf("  |---|---|---|---|---|---|---|---|\n");
        for (iLinha = 0; iLinha < 8; iLinha++)
        {
            printf("%d ", iLinha);
            for (iColuna = 0; iColuna < 8; iColuna++)
            {

                printf("| %c ", tab[iColuna][iLinha]);

                if (iColuna == 7)
                {
                    printf("|%d \n", iLinha);
                }
            }

            printf("  |---|---|---|---|---|---|---|---|\n");
        }
        printf("    0   1   2   3   4   5   6   7");

        // VERIFICA SE AINDA EXISTEM PEÇAS DOS JOGADORES:
        for (brancas = 0, iLinha = 0; iLinha < 8; iLinha++)
        {
            for (iColuna = 0; iColuna < 8; iColuna++)
            {
                if (tab[iColuna][iLinha] == 50 || tab[iColuna][iLinha] == 52)
                {
                    brancas++;
                    continue;
                }
            }
        }

        while (1)
        {
            if (brancas != 0)
            {

                printf("\n\nJogador 2 \n");
                scanf("%d %d", &iLinha, &iColuna);
                scanf("%d %d", &fLinha, &fColuna);

                // MOVIMENTO DE CAPTURA DA DAMA

                // Captura para direita e para baixo
                if (((((fColuna == iColuna + 2) && ((fColuna >= 0) && (fColuna < 8))) && ((fLinha == iLinha + 2) && ((fLinha >= 0) && (fLinha < 8)))) && tab[iColuna][iLinha] == 52) && tab[fColuna][fLinha] == 32)
                {
                    if ((tab[iColuna + 1][iLinha + 1] == 49) || (tab[iColuna + 1][iLinha + 1] == 51))
                    {
                        tab[iColuna + 1][iLinha + 1] = 32;
                    }
                    else
                    {
                        printf("movimento invalido");
                        continue;
                    }

                    tab[iColuna][iLinha] = 32;
                    tab[fColuna][fLinha] = 52;

                    break;
                }
                // Captura para esqueda e para baixo
                if (((((fColuna == iColuna - 2) && ((fColuna >= 0) && (fColuna < 8))) && ((fLinha == iLinha + 2) && ((fLinha >= 0) && (fLinha < 8)))) && tab[iColuna][iLinha] == 52) && tab[fColuna][fLinha] == 32)
                {

                    if ((tab[iColuna - 1][iLinha + 1] == 49) || (tab[iColuna - 1][iLinha + 1] == 51))
                    {
                        tab[iColuna - 1][iLinha + 1] = 32;
                    }
                    else
                    {
                        printf("movimento invalido");
                        continue;
                    }

                    tab[iColuna][iLinha] = 32;
                    tab[fColuna][fLinha] = 52;

                    break;
                }
                // Captura para direita e para cima
                if (((((fColuna == iColuna + 2) && ((fColuna >= 0) && (fColuna < 8))) && ((fLinha == iLinha - 2) && ((fLinha >= 0) && (fLinha < 8)))) && tab[iColuna][iLinha] == 52) && tab[fColuna][fLinha] == 32)
                {
                    if ((tab[iColuna + 1][iLinha - 1] == 49) || (tab[iColuna + 1][iLinha - 1] == 51))
                    {
                        tab[iColuna + 1][iLinha - 1] = 32;
                    }
                    else
                    {
                        printf("movimento invalido");
                        continue;
                    }

                    tab[iColuna][iLinha] = 32;
                    tab[fColuna][fLinha] = 52;

                    break;
                }
                // CAPTURA PARA ESQUERDA E PARA CIMA
                if (((((fColuna == iColuna - 2) && ((fColuna >= 0) && (fColuna < 8))) && ((fLinha == iLinha - 2) && ((fLinha >= 0) && (fLinha < 8)))) && tab[iColuna][iLinha] == 52) && tab[fColuna][fLinha] == 32)
                {
                    if ((tab[iColuna - 1][iLinha - 1] == 49) || (tab[iColuna - 1][iLinha - 1] == 51))
                    {
                        tab[iColuna - 1][iLinha - 1] = 32;
                    }
                    else
                    {
                        printf("movimento invalido");
                        continue;
                    }

                    tab[iColuna][iLinha] = 32;
                    tab[fColuna][fLinha] = 52;

                    break;
                }

                // MOVIMENTO DA DAMA

                if (((((((fColuna == iColuna + 1) || (fColuna == iColuna - 1)) && ((fColuna >= 0) && (fColuna < 8))) && (((fLinha == iLinha + 1) || (fLinha == iLinha - 1)) && ((fLinha >= 0) && (fLinha < 8)))) && tab[fColuna][fLinha] == 32) && tab[iColuna][iLinha] == 52))
                {
                    tab[iColuna][iLinha] = 32;
                    tab[fColuna][fLinha] = 52;
                    break;
                }
                else

                    // CAPTURA DA PEÇA NORMAl

                    // CAPTURA PARA DIREITA E PARA CIMA
                    if (((((fColuna == iColuna + 2) && ((fColuna >= 0) && (fColuna < 8))) && ((fLinha == iLinha - 2) && ((fLinha >= 0) && (fLinha < 8)))) && tab[iColuna][iLinha] == 50) && tab[fColuna][fLinha] == 32)
                    {
                        if ((tab[iColuna + 1][iLinha - 1] == 49) || (tab[iColuna + 1][iLinha - 1] == 51))
                        {
                            tab[iColuna + 1][iLinha - 1] = 32;
                        }
                        else
                        {
                            printf("movimento invalido");
                            continue;
                        }

                        tab[iColuna][iLinha] = 32;
                        tab[fColuna][fLinha] = 50;

                        // VERIFICA SE AINDA EXISTE PEÇAS A SEREM CAPTURADAS
                        // VERIFICA PARA BAIXO E PARA DIREITA
                        if (((tab[fColuna + 1][fLinha + 1] == 49) || (tab[fColuna + 1][fLinha + 1] == 51) && ((fLinha + 2 >= 0) && (fLinha + 2 < 8))) && (tab[fColuna + 2][fLinha + 2] == 32) && (fColuna + 2 >= 0) && (fColuna + 2 < 8))
                        {
                            system("CLS");
                            // IMPRESSãO DO TABULEIRO:
                            printf("    0   1   2   3   4   5   6   7\n");
                            printf("  |---|---|---|---|---|---|---|---|\n");
                            for (iLinha = 0; iLinha < 8; iLinha++)
                            {
                                printf("%d ", iLinha);
                                for (iColuna = 0; iColuna < 8; iColuna++)
                                {

                                    printf("| %c ", tab[iColuna][iLinha]);

                                    if (iColuna == 7)
                                    {
                                        printf("|%d \n", iLinha);
                                    }
                                }

                                printf("  |---|---|---|---|---|---|---|---|\n");
                            }
                            printf("    0   1   2   3   4   5   6   7");
                            printf("\nAinde existem peças a serem capturradas e a captura e obrigatoria!");

                            continue;
                        }
                        // VERIFICA PARA CIMA E PARA DIREITA
                        if (((tab[fColuna + 1][fLinha - 1] == 49) || (tab[fColuna + 1][fLinha - 1] == 51) && ((fLinha - 2 >= 0) && (fLinha - 2 < 8))) && (tab[fColuna + 2][fLinha - 2] == 32) && (fColuna + 2 >= 0) && (fColuna + 2 < 8))
                        {
                            system("CLS");
                            // IMPRESSãO DO TABULEIRO:
                            printf("    0   1   2   3   4   5   6   7\n");
                            printf("  |---|---|---|---|---|---|---|---|\n");
                            for (iLinha = 0; iLinha < 8; iLinha++)
                            {
                                printf("%d ", iLinha);
                                for (iColuna = 0; iColuna < 8; iColuna++)
                                {

                                    printf("| %c ", tab[iColuna][iLinha]);

                                    if (iColuna == 7)
                                    {
                                        printf("|%d \n", iLinha);
                                    }
                                }

                                printf("  |---|---|---|---|---|---|---|---|\n");
                            }
                            printf("    0   1   2   3   4   5   6   7");
                            printf("\nAinde existem peças a serem capturradas e a captura e obrigatoria!");

                            continue;
                        }

                        // VERIFICA PARA ESQUERDA E PARA BAIXO
                        if (((tab[fColuna - 1][fLinha + 1] == 49) || (tab[fColuna - 1][fLinha + 1] == 51) && ((fLinha + 2 >= 0) && (fLinha + 2 < 8))) && (tab[fColuna - 2][fLinha + 2] == 32) && (fColuna - 2 >= 0) && (fColuna - 2 < 8))
                        {
                            system("CLS");
                            // IMPRESSãO DO TABULEIRO:
                            printf("    0   1   2   3   4   5   6   7\n");
                            printf("  |---|---|---|---|---|---|---|---|\n");
                            for (iLinha = 0; iLinha < 8; iLinha++)
                            {
                                printf("%d ", iLinha);
                                for (iColuna = 0; iColuna < 8; iColuna++)
                                {

                                    printf("| %c ", tab[iColuna][iLinha]);

                                    if (iColuna == 7)
                                    {
                                        printf("|%d \n", iLinha);
                                    }
                                }

                                printf("  |---|---|---|---|---|---|---|---|\n");
                            }
                            printf("    0   1   2   3   4   5   6   7");
                            printf("\nAinde existem peças a serem capturradas e a captura e obrigatoria!");

                            continue;
                        }

                        // VERIFICA PARA ESQUERDA E PARA CIMA
                        if (((tab[fColuna - 1][fLinha - 1] == 49) || (tab[fColuna - 1][fLinha - 1] == 51) && ((fLinha - 2 >= 0) && (fLinha - 2 < 8))) && (tab[fColuna - 2][fLinha - 2] == 32) && (fColuna - 2 >= 0) && (fColuna - 2 < 8))
                        {
                            system("CLS");
                            // IMPRESSãO DO TABULEIRO:
                            printf("    0   1   2   3   4   5   6   7\n");
                            printf("  |---|---|---|---|---|---|---|---|\n");
                            for (iLinha = 0; iLinha < 8; iLinha++)
                            {
                                printf("%d ", iLinha);
                                for (iColuna = 0; iColuna < 8; iColuna++)
                                {

                                    printf("| %c ", tab[iColuna][iLinha]);

                                    if (iColuna == 7)
                                    {
                                        printf("|%d \n", iLinha);
                                    }
                                }

                                printf("  |---|---|---|---|---|---|---|---|\n");
                            }
                            printf("    0   1   2   3   4   5   6   7");
                            printf("\nAinde existem peças a serem capturradas e a captura e obrigatoria!");

                            continue;
                        }

                        break;
                    }

                // CAPTURA PARA DIREITA E PARA BAIXO
                if (((((fColuna == iColuna + 2) && ((fColuna >= 0) && (fColuna < 8))) && ((fLinha == iLinha + 2) && ((fLinha >= 0) && (fLinha < 8)))) && tab[iColuna][iLinha] == 50) && tab[fColuna][fLinha] == 32)
                {
                    if ((tab[iColuna + 1][iLinha + 1] == 49) || (tab[iColuna + 1][iLinha + 1] == 51))
                    {
                        tab[iColuna + 1][iLinha + 1] = 32;
                    }
                    else
                    {
                        printf("movimento invalido");
                        continue;
                    }

                    tab[iColuna][iLinha] = 32;
                    tab[fColuna][fLinha] = 50;

                    // VERIFICA SE AINDA EXISTE PEÇAS A SEREM CAPTURADAS
                    // VERIFICA PARA BAIXO E PARA DIREITA
                    if (((tab[fColuna + 1][fLinha + 1] == 49) || (tab[fColuna + 1][fLinha + 1] == 51) && ((fLinha + 2 >= 0) && (fLinha + 2 < 8))) && (tab[fColuna + 2][fLinha + 2] == 32) && (fColuna + 2 >= 0) && (fColuna + 2 < 8))
                    {
                        system("CLS");
                        // IMPRESSãO DO TABULEIRO:
                        printf("    0   1   2   3   4   5   6   7\n");
                        printf("  |---|---|---|---|---|---|---|---|\n");
                        for (iLinha = 0; iLinha < 8; iLinha++)
                        {
                            printf("%d ", iLinha);
                            for (iColuna = 0; iColuna < 8; iColuna++)
                            {

                                printf("| %c ", tab[iColuna][iLinha]);

                                if (iColuna == 7)
                                {
                                    printf("|%d \n", iLinha);
                                }
                            }

                            printf("  |---|---|---|---|---|---|---|---|\n");
                        }
                        printf("    0   1   2   3   4   5   6   7");
                        printf("\nAinde existem peças a serem capturradas e a captura e obrigatoria!");

                        continue;
                    }
                    // VERIFICA PARA CIMA E PARA DIREITA
                    if (((tab[fColuna + 1][fLinha - 1] == 49) || (tab[fColuna + 1][fLinha - 1] == 51) && ((fLinha - 2 >= 0) && (fLinha - 2 < 8))) && (tab[fColuna + 2][fLinha - 2] == 32) && (fColuna + 2 >= 0) && (fColuna + 2 < 8))
                    {
                        system("CLS");
                        // IMPRESSãO DO TABULEIRO:
                        printf("    0   1   2   3   4   5   6   7\n");
                        printf("  |---|---|---|---|---|---|---|---|\n");
                        for (iLinha = 0; iLinha < 8; iLinha++)
                        {
                            printf("%d ", iLinha);
                            for (iColuna = 0; iColuna < 8; iColuna++)
                            {

                                printf("| %c ", tab[iColuna][iLinha]);

                                if (iColuna == 7)
                                {
                                    printf("|%d \n", iLinha);
                                }
                            }

                            printf("  |---|---|---|---|---|---|---|---|\n");
                        }
                        printf("    0   1   2   3   4   5   6   7");
                        printf("\nAinde existem peças a serem capturradas e a captura e obrigatoria!");

                        continue;
                    }

                    // VERIFICA PARA ESQUERDA E PARA BAIXO
                    if (((tab[fColuna - 1][fLinha + 1] == 49) || (tab[fColuna - 1][fLinha + 1] == 51) && ((fLinha + 2 >= 0) && (fLinha + 2 < 8))) && (tab[fColuna - 2][fLinha + 2] == 32) && (fColuna - 2 >= 0) && (fColuna - 2 < 8))
                    {
                        system("CLS");
                        // IMPRESSãO DO TABULEIRO:
                        printf("    0   1   2   3   4   5   6   7\n");
                        printf("  |---|---|---|---|---|---|---|---|\n");
                        for (iLinha = 0; iLinha < 8; iLinha++)
                        {
                            printf("%d ", iLinha);
                            for (iColuna = 0; iColuna < 8; iColuna++)
                            {

                                printf("| %c ", tab[iColuna][iLinha]);

                                if (iColuna == 7)
                                {
                                    printf("|%d \n", iLinha);
                                }
                            }

                            printf("  |---|---|---|---|---|---|---|---|\n");
                        }
                        printf("    0   1   2   3   4   5   6   7");
                        printf("\nAinde existem peças a serem capturradas e a captura e obrigatoria!");

                        continue;
                    }

                    // VERIFICA PARA ESQUERDA E PARA CIMA
                    if (((tab[fColuna - 1][fLinha - 1] == 49) || (tab[fColuna - 1][fLinha - 1] == 51) && ((fLinha - 2 >= 0) && (fLinha - 2 < 8))) && (tab[fColuna - 2][fLinha - 2] == 32) && (fColuna - 2 >= 0) && (fColuna - 2 < 8))
                    {
                        system("CLS");
                        // IMPRESSãO DO TABULEIRO:
                        printf("    0   1   2   3   4   5   6   7\n");
                        printf("  |---|---|---|---|---|---|---|---|\n");
                        for (iLinha = 0; iLinha < 8; iLinha++)
                        {
                            printf("%d ", iLinha);
                            for (iColuna = 0; iColuna < 8; iColuna++)
                            {

                                printf("| %c ", tab[iColuna][iLinha]);

                                if (iColuna == 7)
                                {
                                    printf("|%d \n", iLinha);
                                }
                            }

                            printf("  |---|---|---|---|---|---|---|---|\n");
                        }
                        printf("    0   1   2   3   4   5   6   7");
                        printf("\nAinde existem peças a serem capturradas e a captura e obrigatoria!");

                        continue;
                    }

                    break;
                }
                // CAPTURA PARA ESQUERDA E PARA CIMA
                if (((((fColuna == iColuna - 2) && ((fColuna >= 0) && (fColuna < 8))) && ((fLinha == iLinha - 2) && ((fLinha >= 0) && (fLinha < 8)))) && tab[iColuna][iLinha] == 50) && tab[fColuna][fLinha] == 32)
                {

                    if ((tab[iColuna - 1][iLinha - 1] == 49) || (tab[iColuna - 1][iLinha - 1] == 51))
                    {
                        tab[iColuna - 1][iLinha - 1] = 32;
                    }
                    else
                    {
                        printf("movimento invalido");
                        continue;
                    }

                    tab[iColuna][iLinha] = 32;
                    tab[fColuna][fLinha] = 50;

                    // VERIFICA SE AINDA EXISTE PEÇAS A SEREM CAPTURADAS
                    // VERIFICA PARA BAIXO E PARA DIREITA
                    if (((tab[fColuna + 1][fLinha + 1] == 49) || (tab[fColuna + 1][fLinha + 1] == 51) && ((fLinha + 2 >= 0) && (fLinha + 2 < 8))) && (tab[fColuna + 2][fLinha + 2] == 32) && (fColuna + 2 >= 0) && (fColuna + 2 < 8))
                    {
                        system("CLS");
                        // IMPRESSãO DO TABULEIRO:
                        printf("    0   1   2   3   4   5   6   7\n");
                        printf("  |---|---|---|---|---|---|---|---|\n");
                        for (iLinha = 0; iLinha < 8; iLinha++)
                        {
                            printf("%d ", iLinha);
                            for (iColuna = 0; iColuna < 8; iColuna++)
                            {

                                printf("| %c ", tab[iColuna][iLinha]);

                                if (iColuna == 7)
                                {
                                    printf("|%d \n", iLinha);
                                }
                            }

                            printf("  |---|---|---|---|---|---|---|---|\n");
                        }
                        printf("    0   1   2   3   4   5   6   7");
                        printf("\nAinde existem peças a serem capturradas e a captura e obrigatoria!");

                        continue;
                    }
                    // VERIFICA PARA CIMA E PARA DIREITA
                    if (((tab[fColuna + 1][fLinha - 1] == 49) || (tab[fColuna + 1][fLinha - 1] == 51) && ((fLinha - 2 >= 0) && (fLinha - 2 < 8))) && (tab[fColuna + 2][fLinha - 2] == 32) && (fColuna + 2 >= 0) && (fColuna + 2 < 8))
                    {
                        system("CLS");
                        // IMPRESSãO DO TABULEIRO:
                        printf("    0   1   2   3   4   5   6   7\n");
                        printf("  |---|---|---|---|---|---|---|---|\n");
                        for (iLinha = 0; iLinha < 8; iLinha++)
                        {
                            printf("%d ", iLinha);
                            for (iColuna = 0; iColuna < 8; iColuna++)
                            {

                                printf("| %c ", tab[iColuna][iLinha]);

                                if (iColuna == 7)
                                {
                                    printf("|%d \n", iLinha);
                                }
                            }

                            printf("  |---|---|---|---|---|---|---|---|\n");
                        }
                        printf("    0   1   2   3   4   5   6   7");
                        printf("\nAinde existem peças a serem capturradas e a captura e obrigatoria!");

                        continue;
                    }

                    // VERIFICA PARA ESQUERDA E PARA BAIXO
                    if (((tab[fColuna - 1][fLinha + 1] == 49) || (tab[fColuna - 1][fLinha + 1] == 51) && ((fLinha + 2 >= 0) && (fLinha + 2 < 8))) && (tab[fColuna - 2][fLinha + 2] == 32) && (fColuna - 2 >= 0) && (fColuna - 2 < 8))
                    {
                        system("CLS");
                        // IMPRESSãO DO TABULEIRO:
                        printf("    0   1   2   3   4   5   6   7\n");
                        printf("  |---|---|---|---|---|---|---|---|\n");
                        for (iLinha = 0; iLinha < 8; iLinha++)
                        {
                            printf("%d ", iLinha);
                            for (iColuna = 0; iColuna < 8; iColuna++)
                            {

                                printf("| %c ", tab[iColuna][iLinha]);

                                if (iColuna == 7)
                                {
                                    printf("|%d \n", iLinha);
                                }
                            }

                            printf("  |---|---|---|---|---|---|---|---|\n");
                        }
                        printf("    0   1   2   3   4   5   6   7");
                        printf("\nAinde existem peças a serem capturradas e a captura e obrigatoria!");

                        continue;
                    }

                    // VERIFICA PARA ESQUERDA E PARA CIMA
                    if (((tab[fColuna - 1][fLinha - 1] == 49) || (tab[fColuna - 1][fLinha - 1] == 51) && ((fLinha - 2 >= 0) && (fLinha - 2 < 8))) && (tab[fColuna - 2][fLinha - 2] == 32) && (fColuna - 2 >= 0) && (fColuna - 2 < 8))
                    {
                        system("CLS");
                        // IMPRESSãO DO TABULEIRO:
                        printf("    0   1   2   3   4   5   6   7\n");
                        printf("  |---|---|---|---|---|---|---|---|\n");
                        for (iLinha = 0; iLinha < 8; iLinha++)
                        {
                            printf("%d ", iLinha);
                            for (iColuna = 0; iColuna < 8; iColuna++)
                            {

                                printf("| %c ", tab[iColuna][iLinha]);

                                if (iColuna == 7)
                                {
                                    printf("|%d \n", iLinha);
                                }
                            }

                            printf("  |---|---|---|---|---|---|---|---|\n");
                        }
                        printf("    0   1   2   3   4   5   6   7");
                        printf("\nAinde existem peças a serem capturradas e a captura e obrigatoria!");

                        continue;
                    }

                    break;
                }

                // CAPTURA PARA ESQUERDA E PARA BAIXO
                if (((((fColuna == iColuna - 2) && ((fColuna >= 0) && (fColuna < 8))) && ((fLinha == iLinha + 2) && ((fLinha >= 0) && (fLinha < 8)))) && tab[iColuna][iLinha] == 50) && tab[fColuna][fLinha] == 32)
                {

                    if ((tab[iColuna - 1][iLinha + 1] == 49) || (tab[iColuna - 1][iLinha + 1] == 51))
                    {
                        tab[iColuna - 1][iLinha + 1] = 32;
                    }
                    else
                    {
                        printf("movimento invalido");
                        continue;
                    }

                    tab[iColuna][iLinha] = 32;
                    tab[fColuna][fLinha] = 50;

                    // VERIFICA SE AINDA EXISTE PEÇAS A SEREM CAPTURADAS
                    // VERIFICA PARA BAIXO E PARA DIREITA
                    if (((tab[fColuna + 1][fLinha + 1] == 49) || (tab[fColuna + 1][fLinha + 1] == 51) && ((fLinha + 2 >= 0) && (fLinha + 2 < 8))) && (tab[fColuna + 2][fLinha + 2] == 32) && (fColuna + 2 >= 0) && (fColuna + 2 < 8))
                    {
                        system("CLS");
                        // IMPRESSãO DO TABULEIRO:
                        printf("    0   1   2   3   4   5   6   7\n");
                        printf("  |---|---|---|---|---|---|---|---|\n");
                        for (iLinha = 0; iLinha < 8; iLinha++)
                        {
                            printf("%d ", iLinha);
                            for (iColuna = 0; iColuna < 8; iColuna++)
                            {

                                printf("| %c ", tab[iColuna][iLinha]);

                                if (iColuna == 7)
                                {
                                    printf("|%d \n", iLinha);
                                }
                            }

                            printf("  |---|---|---|---|---|---|---|---|\n");
                        }
                        printf("    0   1   2   3   4   5   6   7");
                        printf("\nAinde existem peças a serem capturradas e a captura e obrigatoria!");

                        continue;
                    }
                    // VERIFICA PARA CIMA E PARA DIREITA
                    if (((tab[fColuna + 1][fLinha - 1] == 49) || (tab[fColuna + 1][fLinha - 1] == 51) && ((fLinha - 2 >= 0) && (fLinha - 2 < 8))) && (tab[fColuna + 2][fLinha - 2] == 32) && (fColuna + 2 >= 0) && (fColuna + 2 < 8))
                    {
                        system("CLS");
                        // IMPRESSãO DO TABULEIRO:
                        printf("    0   1   2   3   4   5   6   7\n");
                        printf("  |---|---|---|---|---|---|---|---|\n");
                        for (iLinha = 0; iLinha < 8; iLinha++)
                        {
                            printf("%d ", iLinha);
                            for (iColuna = 0; iColuna < 8; iColuna++)
                            {

                                printf("| %c ", tab[iColuna][iLinha]);

                                if (iColuna == 7)
                                {
                                    printf("|%d \n", iLinha);
                                }
                            }

                            printf("  |---|---|---|---|---|---|---|---|\n");
                        }
                        printf("    0   1   2   3   4   5   6   7");
                        printf("\nAinde existem peças a serem capturradas e a captura e obrigatoria!");

                        continue;
                    }

                    // VERIFICA PARA ESQUERDA E PARA BAIXO
                    if (((tab[fColuna - 1][fLinha + 1] == 49) || (tab[fColuna - 1][fLinha + 1] == 51) && ((fLinha + 2 >= 0) && (fLinha + 2 < 8))) && (tab[fColuna - 2][fLinha + 2] == 32) && (fColuna - 2 >= 0) && (fColuna - 2 < 8))
                    {
                        system("CLS");
                        // IMPRESSãO DO TABULEIRO:
                        printf("    0   1   2   3   4   5   6   7\n");
                        printf("  |---|---|---|---|---|---|---|---|\n");
                        for (iLinha = 0; iLinha < 8; iLinha++)
                        {
                            printf("%d ", iLinha);
                            for (iColuna = 0; iColuna < 8; iColuna++)
                            {

                                printf("| %c ", tab[iColuna][iLinha]);

                                if (iColuna == 7)
                                {
                                    printf("|%d \n", iLinha);
                                }
                            }

                            printf("  |---|---|---|---|---|---|---|---|\n");
                        }
                        printf("    0   1   2   3   4   5   6   7");
                        printf("\nAinde existem peças a serem capturradas e a captura e obrigatoria!");

                        continue;
                    }

                    // VERIFICA PARA ESQUERDA E PARA CIMA
                    if (((tab[fColuna - 1][fLinha - 1] == 49) || (tab[fColuna - 1][fLinha - 1] == 51) && ((fLinha - 2 >= 0) && (fLinha - 2 < 8))) && (tab[fColuna - 2][fLinha - 2] == 32) && (fColuna - 2 >= 0) && (fColuna - 2 < 8))
                    {
                        system("CLS");
                        // IMPRESSãO DO TABULEIRO:
                        printf("    0   1   2   3   4   5   6   7\n");
                        printf("  |---|---|---|---|---|---|---|---|\n");
                        for (iLinha = 0; iLinha < 8; iLinha++)
                        {
                            printf("%d ", iLinha);
                            for (iColuna = 0; iColuna < 8; iColuna++)
                            {

                                printf("| %c ", tab[iColuna][iLinha]);

                                if (iColuna == 7)
                                {
                                    printf("|%d \n", iLinha);
                                }
                            }

                            printf("  |---|---|---|---|---|---|---|---|\n");
                        }
                        printf("    0   1   2   3   4   5   6   7");
                        printf("\nAinde existem peças a serem capturradas e a captura e obrigatoria!");

                        continue;
                    }

                    break;
                }

                // Movimento da peça

                if (((((((fColuna == iColuna + 1) || (fColuna == iColuna - 1)) && ((fColuna >= 0) && (fColuna < 8))) && (((fLinha == iLinha - 1)) && ((fLinha >= 0) && (fLinha < 8)))) && tab[fColuna][fLinha] == 32) && tab[iColuna][iLinha] == 50))
                {
                    tab[iColuna][iLinha] = 32;
                    tab[fColuna][fLinha] = 50;
                    break;
                }
                else
                {
                    printf("movimento invalido");
                    continue;
                }
            }
            break;
        }
        system("CLS");

        // VERIFICA SE VIROU DAMA
        for (iColuna = 0; iColuna < 8; iColuna++)
        {
            if (tab[iColuna][0] == 50)
            {
                tab[iColuna][0] = 52;
            }
        }

        // IMPRESSãO DO TABULEIRO:
        printf("    0   1   2   3   4   5   6   7\n");
        printf("  |---|---|---|---|---|---|---|---|\n");
        for (iLinha = 0; iLinha < 8; iLinha++)
        {
            printf("%d ", iLinha);
            for (iColuna = 0; iColuna < 8; iColuna++)
            {

                printf("| %c ", tab[iColuna][iLinha]);

                if (iColuna == 7)
                {
                    printf("|%d \n", iLinha);
                }
            }

            printf("  |---|---|---|---|---|---|---|---|\n");
        }
        printf("    0   1   2   3   4   5   6   7");

        // VERIFICA SE AINDA EXISTEM PEÇAS DOS JOGADORES:
        for (pretas = 0, iLinha = 0; iLinha < 8; iLinha++)
        {
            for (iColuna = 0; iColuna < 8; iColuna++)
            {
                if (tab[iColuna][iLinha] == 49 || tab[iColuna][iLinha] == 51)
                {
                    pretas++;
                    continue;
                }
            }
        }
    }

    if (brancas == 0)
    {
        printf("\nJOGADOR 1 VENCEU! PARABENS!!");
    }
    if (pretas == 0)
    {
        printf("\nJOGADOR 2 VENCEU! PARABENS!!");
    }

    getch();
    return 0;
}