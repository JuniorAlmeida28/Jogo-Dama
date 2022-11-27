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
    int pLinha = 10;  // Auxiliar para obrigação de captura
    int cColuna = 10; // Auxiliar para obrigação de captura

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
    for (iLinha = 3; iLinha < 8; iLinha++)
    {
        for (iColuna = 0; iColuna < 8; iColuna++)
        {
            tab[iColuna][iLinha] = 32;
        }
    }

    for (iLinha = 7; iLinha < 8; iLinha++)
    {
        if (iLinha % 2 == 0)
        {
            aux = 1;
        }
        else
        {
            aux = 0;
        }
        for (iColuna = 0; iColuna < 8; iColuna++, aux++) // iMPRIME AS BRANCAS
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

            // OBRIGA A CAPTURAR DEPOIS DO MOVIMENTO DE CAPTURA
            if (pLinha != iLinha && cColuna != iColuna || pLinha == iLinha && cColuna != iColuna || pLinha != iLinha && cColuna == iColuna)
            {
                if (pLinha != 10 || cColuna != 10)
                {
                    printf("\nA captura %c obrigatoria na Linha %d Coluna %d\n", 130, pLinha, cColuna);
                    continue;
                }
            }

            // Captura dama
            //  Captura para direita e para baixo
            if (((((fColuna == iColuna + 2) && ((fColuna >= 0) && (fColuna < 8))) && ((fLinha == iLinha + 2) && ((fLinha >= 0) && (fLinha < 8)))) && tab[iColuna][iLinha] == 51) && tab[fColuna][fLinha] == 32)
            {
                
                if ((tab[iColuna + 1][iLinha + 1] == 50) || (tab[iColuna + 1][iLinha + 1] == 52))
                {
                    tab[iColuna + 1][iLinha + 1] = 32;
                }
                // else
                // {
                    
                //     printf("movimento invalido");
                //     continue;
                // }

                tab[iColuna][iLinha] = 32;
                tab[fColuna][fLinha] = 51;

                break;
            }
            // Captura para esqueda e para baixo
            if (((((fColuna == iColuna - 2) && ((fColuna >= 0) && (fColuna < 8))) && ((fLinha == iLinha + 2) && ((fLinha >= 0) && (fLinha < 8)))) && tab[iColuna][iLinha] == 51) && tab[fColuna][fLinha] == 32)
            {
                

                if ((tab[iColuna - 1][iLinha + 1] == 50) || (tab[iColuna - 1][iLinha + 1] == 52))
                {
                    tab[iColuna - 1][iLinha + 1] = 32;
                }
                // else
                // {
                    
                //     printf("movimento invalido");
                //     continue;
                // }

                tab[iColuna][iLinha] = 32;
                tab[fColuna][fLinha] = 51;

                break;
            }
            // Captura para direita e para cima
            if (((((fColuna == iColuna + 2) && ((fColuna >= 0) && (fColuna < 8))) && ((fLinha == iLinha - 2) && ((fLinha >= 0) && (fLinha < 8)))) && tab[iColuna][iLinha] == 51) && tab[fColuna][fLinha] == 32)
            {
                
                if ((tab[iColuna + 1][iLinha - 1] == 50) || (tab[iColuna + 1][iLinha - 1] == 52))
                {
                    tab[iColuna + 1][iLinha - 1] = 32;
                }
                // else
                // {
                    
                //     printf("movimento invalido");
                //     continue;
                // }

                tab[iColuna][iLinha] = 32;
                tab[fColuna][fLinha] = 51;

                break;
            }
            // Captura para esquerda e para cima
            if (((((fColuna == iColuna - 2) && ((fColuna >= 0) && (fColuna < 8))) && ((fLinha == iLinha - 2) && ((fLinha >= 0) && (fLinha < 8)))) && tab[iColuna][iLinha] == 51) && tab[fColuna][fLinha] == 32)
            {
                
                if ((tab[iColuna - 1][iLinha - 1] == 50) || (tab[iColuna - 1][iLinha - 1] == 52))
                {
                    tab[iColuna - 1][iLinha - 1] = 32;
                }
                // else
                // {
                    
                //     printf("movimento invalido");
                //     continue;
                // }

                tab[iColuna][iLinha] = 32;
                tab[fColuna][fLinha] = 51;

                break;
            }

            // Movimento dama

            if(        (((tab[iColuna][iLinha]==51)  && (((fLinha+fColuna)==(iLinha+iColuna)) || ((fLinha-fColuna)==(iLinha+iColuna)) || ((fLinha+fColuna)==(iLinha-iColuna)) || (abs(fLinha-fColuna)==(abs(iLinha-iColuna)) ) || (abs(fLinha+fColuna)==(abs(iLinha-iColuna)) ) || (abs(fLinha-fColuna)==(abs(iLinha+iColuna)) ) || (abs(fLinha+fColuna)==(abs(iLinha+iColuna)) ))) && (tab[fColuna][fLinha]==32))        )
		    {printf("\n205\n");
                tab[iColuna][iLinha] = 32;
                tab[fColuna][fLinha] = 51;
                break;
            }

            /*if (((((((fColuna == iColuna + 1) || (fColuna == iColuna - 1)) && ((fColuna >= 0) && (fColuna < 8))) && (((fLinha == iLinha + 1) || (fLinha == iLinha - 1)) && ((fLinha >= 0) && (fLinha < 8)))) && tab[fColuna][fLinha] == 32) && tab[iColuna][iLinha] == 51))
            {
                
                tab[iColuna][iLinha] = 32;
                tab[fColuna][fLinha] = 51;
                break;
            }*/

            // CAPTURA PEÇA NORMAL

            // Captura para direita E PARA BAIXO
            if (((((fColuna == iColuna + 2) && ((fColuna >= 0) && (fColuna < 8))) && ((fLinha == iLinha + 2) && ((fLinha >= 0) && (fLinha < 8)))) && tab[iColuna][iLinha] == 49) && tab[fColuna][fLinha] == 32)
            {

                if ((tab[iColuna + 1][iLinha + 1] == 50) || (tab[iColuna + 1][iLinha + 1] == 52))
                {
                    tab[iColuna + 1][iLinha + 1] = 32;
                }
                else
                {
                    printf("\n231\n");
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

                    pLinha = fLinha;
                    cColuna = fColuna;

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

                    pLinha = fLinha;
                    cColuna = fColuna;
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

                    pLinha = fLinha;
                    cColuna = fColuna;
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

                    pLinha = fLinha;
                    cColuna = fColuna;
                    continue;
                }

                break;
            }

            // Captura para direita E PARA CIMA
            if (((((fColuna == iColuna + 2) && ((fColuna >= 0) && (fColuna < 8))) && ((fLinha == iLinha - 2) && ((fLinha >= 0) && (fLinha < 8)))) && tab[iColuna][iLinha] == 49) && tab[fColuna][fLinha] == 32)
            {

                if ((tab[iColuna + 1][iLinha - 1] == 50) || (tab[iColuna + 1][iLinha - 1] == 52))
                {
                    tab[iColuna + 1][iLinha - 1] = 32;
                }
                else
                {
                    printf("\n377\n");
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

                    pLinha = fLinha;
                    cColuna = fColuna;
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

                    pLinha = fLinha;
                    cColuna = fColuna;
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

                    pLinha = fLinha;
                    cColuna = fColuna;
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

                    pLinha = fLinha;
                    cColuna = fColuna;
                    continue;
                }

                break;
            }

            // Captura para esqueda E PARA BAIXO
            if (((((fColuna == iColuna - 2) && ((fColuna >= 0) && (fColuna < 8))) && ((fLinha == iLinha + 2) && ((fLinha >= 0) && (fLinha < 8)))) && tab[iColuna][iLinha] == 49) && tab[fColuna][fLinha] == 32)
            {

                if ((tab[iColuna - 1][iLinha + 1] == 50) || (tab[iColuna - 1][iLinha + 1] == 52))
                {
                    tab[iColuna - 1][iLinha + 1] = 32;
                }
                else
                {
                    printf("\n522\n");
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

                    pLinha = fLinha;
                    cColuna = fColuna;

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

                    pLinha = fLinha;
                    cColuna = fColuna;
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

                    pLinha = fLinha;
                    cColuna = fColuna;
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

                    pLinha = fLinha;
                    cColuna = fColuna;
                    continue;
                }

                break;
            }

            // Captura para esqueda E PARA CIMA
            if (((((fColuna == iColuna - 2) && ((fColuna >= 0) && (fColuna < 8))) && ((fLinha == iLinha - 2) && ((fLinha >= 0) && (fLinha < 8)))) && tab[iColuna][iLinha] == 49) && tab[fColuna][fLinha] == 32)
            {

                if ((tab[iColuna - 1][iLinha - 1] == 50) || (tab[iColuna - 1][iLinha - 1] == 52))
                {
                    tab[iColuna - 1][iLinha - 1] = 32;
                }
                else
                {
                    printf("\n668\n");
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

                    pLinha = fLinha;
                    cColuna = fColuna;
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

                    pLinha = fLinha;
                    cColuna = fColuna;
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

                    pLinha = fLinha;
                    cColuna = fColuna;
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

                    pLinha = fLinha;
                    cColuna = fColuna;
                    continue;
                }

                break;
            }

            // Movimento da peça

            if (pLinha == 10 && cColuna == 10)
            {
                
                    
                
                if (((((((fColuna == iColuna + 1) || (fColuna == iColuna - 1)) && ((fColuna >= 0) && (fColuna < 8))) && (((fLinha == iLinha + 1)) && ((fLinha >= 0) && (fLinha < 8)))) && tab[fColuna][fLinha] == 32) && tab[iColuna][iLinha] == 49))
                {

                    tab[iColuna][iLinha] = 32;
                    tab[fColuna][fLinha] = 49;
                    break;
                }
                else
                {
                    printf("817");
                    printf("movimento invalido");
                    continue;
                }
                
            }
        }
        // VOLTA A VALER 10
        pLinha = 10;
        cColuna = 10;
        system("CLS");

        // VERIFICA SE VIROU DAMA:
        for (iColuna = 0; iColuna < 8; iColuna++)
        {
            if (tab[iColuna][4] == 49)
            {
                tab[iColuna][4] = 51;
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

                if (pLinha != iLinha && cColuna != iColuna || pLinha == iLinha && cColuna != iColuna || pLinha != iLinha && cColuna == iColuna)
                {
                    if (pLinha != 10 || cColuna != 10)
                    {
                        printf("\nA captura %c obrigatoria na Linha %d Coluna %d\n", 130, pLinha, cColuna);
                        continue;
                    }
                }

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

                            pLinha = fLinha;
                            cColuna = fColuna;
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
                            pLinha = fLinha;
                            cColuna = fColuna;
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
                            pLinha = fLinha;
                            cColuna = fColuna;
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
                            pLinha = fLinha;
                            cColuna = fColuna;
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
                        pLinha = fLinha;
                        cColuna = fColuna;
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
                        pLinha = fLinha;
                        cColuna = fColuna;
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
                        pLinha = fLinha;
                        cColuna = fColuna;
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
                        pLinha = fLinha;
                        cColuna = fColuna;
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
                        pLinha = fLinha;
                        cColuna = fColuna;
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
                        pLinha = fLinha;
                        cColuna = fColuna;
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
                        pLinha = fLinha;
                        cColuna = fColuna;
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
                        pLinha = fLinha;
                        cColuna = fColuna;
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
                        pLinha = fLinha;
                        cColuna = fColuna;
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
                        pLinha = fLinha;
                        cColuna = fColuna;
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
                        pLinha = fLinha;
                        cColuna = fColuna;
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
                        pLinha = fLinha;
                        cColuna = fColuna;
                        continue;
                    }

                    break;
                }

                // Movimento da peça
                if (pLinha == 10 && cColuna == 10)
                {
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
            }
            break;
        }
        // VOLTA A VALER 10
        pLinha = 10;
        cColuna = 10;
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