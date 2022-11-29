#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

void imprimeTab(char tab[8][8])
{
    // IMPRESSãO DO TABULEIRO:
    printf("    0   1   2   3   4   5   6   7\n");
    printf("  |---|---|---|---|---|---|---|---|\n");
    for (int i = 0; i < 8; i++)
    {
        printf("%d ", i);
        for (int j = 0; j < 8; j++)
        {

            printf("| %c ", tab[j][i]);

            if (j == 7)
            {
                printf("|%d \n", i);
            }
        }

        printf("  |---|---|---|---|---|---|---|---|\n");
    }
    printf("    0   1   2   3   4   5   6   7");
}

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

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

    for (iLinha = 5; iLinha < 8; iLinha++)
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
    imprimeTab(tab);

    while (pretas != 0 && brancas != 0)
    {

        while (1)
        {

            printf("\n\n                 ---Jogador 1--- \n");
            printf("Digite as coordenadas de origem da sua peca: (Linha e Coluna)\n");
            scanf("%d %d", &iLinha, &iColuna);
            printf("Digite as coordenadas de destino da sua peca: (Linha e Coluna)\n");
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

            // MOVIMENTO DAMA

            if ((tab[iColuna][iLinha] == 51) && ((abs(iLinha - fLinha) >= 1) && (abs(iColuna - fColuna) >= 1)))
            {
                if ((iLinha < fLinha) && (iColuna < fColuna)) // MOVIMENTO DIREITA INFERIOR
                {
                    int caminhoLivre = 1;
                    int x, y;
                    for (y = iLinha + 1, x = iColuna + 1; y < fLinha, x < fColuna; y++, x++)
                    {
                        if (tab[x][y] != 32)
                        {
                            caminhoLivre = 0;
                            break;
                        }
                    }
                    if (caminhoLivre)
                    {
                        tab[iColuna][iLinha] = 32;
                        tab[fColuna][fLinha] = 51;

                        break;
                    }
                    else
                    {
                        if ((tab[x][y] != 32) && ((tab[x][y] == 50) || (tab[x][y] == 52)))
                        {

                            tab[x][y] = 32;

                            tab[iColuna][iLinha] = 32;
                            tab[fColuna][fLinha] = 51;

                            // VERIFICA SE AINDA EXISTE PEÇAS A SEREM CAPTURADAS
                            // VERIFICA PARA BAIXO E PARA DIREITA
                            if (((tab[fColuna + 1][fLinha + 1] == 50) || (tab[fColuna + 1][fLinha + 1] == 52)) && ((fLinha + 2 >= 0) && (fLinha + 2 < 8)) && ((fColuna + 2 >= 0) && (fColuna + 2 < 8)) && (tab[fColuna + 2][fLinha + 2] == 32))
                            {
                                system("CLS");
                                //  IMPRESSãO DO TABULEIRO:
                                imprimeTab(tab);
                                printf("\nAinde existem pecas a serem capturadas e a captura e obrigatoria!");

                                pLinha = fLinha;
                                cColuna = fColuna;

                                continue;
                            }
                            // VERIFICA PARA CIMA E PARA DIREITA
                            if (((tab[fColuna + 1][fLinha - 1] == 50) || (tab[fColuna + 1][fLinha - 1] == 52)) && ((fLinha - 2 >= 0) && (fLinha - 2 < 8)) && ((fColuna + 2 >= 0) && (fColuna + 2 < 8)) && (tab[fColuna + 2][fLinha - 2] == 32))
                            {
                                system("CLS");
                                //  IMPRESSãO DO TABULEIRO:
                                imprimeTab(tab);
                                printf("\nAinde existem pecas a serem capturadas e a captura e obrigatoria!");

                                pLinha = fLinha;
                                cColuna = fColuna;
                                continue;
                            }

                            // VERIFICA PARA ESQUERDA E PARA BAIXO
                            if (((tab[fColuna - 1][fLinha + 1] == 50) || (tab[fColuna - 1][fLinha + 1] == 52)) && ((fLinha + 2 >= 0) && (fLinha + 2 < 8)) && ((fColuna - 2 >= 0) && (fColuna - 2 < 8)) && (tab[fColuna - 2][fLinha + 2] == 32))
                            {
                                system("CLS");
                                //  IMPRESSãO DO TABULEIRO:
                                imprimeTab(tab);
                                printf("\nAinde existem pecas a serem capturadas e a captura e obrigatoria!");

                                pLinha = fLinha;
                                cColuna = fColuna;
                                continue;
                            }

                            // VERIFICA PARA ESQUERDA E PARA CIMA
                            if (((tab[fColuna - 1][fLinha - 1] == 50) || (tab[fColuna - 1][fLinha - 1] == 52)) && ((fLinha - 2 >= 0) && (fLinha - 2 < 8)) && ((fColuna - 2 >= 0) && (fColuna - 2 < 8)) && (tab[fColuna - 2][fLinha - 2] == 32))
                            {
                                system("CLS");
                                //  IMPRESSãO DO TABULEIRO:
                                imprimeTab(tab);
                                printf("\nAinde existem pecas a serem capturadas e a captura e obrigatoria!");

                                pLinha = fLinha;
                                cColuna = fColuna;
                                continue;
                            }

                            break;
                        }
                        else
                        {
                            printf("\nExiste uma peca no meio do caminho:\nLinha %d\nColuna %d\n", y, x);
                            continue;
                        }
                    }
                }

                if ((iLinha > fLinha) && (iColuna < fColuna)) // MOVIMENTO DIREITA SUPERIOR
                {
                    int caminhoLivre = 1;
                    int x, y;
                    for (y = iLinha - 1, x = iColuna + 1; y < fLinha, x < fColuna; y--, x++)
                    {
                        if (tab[x][y] != 32)
                        {
                            caminhoLivre = 0;
                            break;
                        }
                    }
                    if (caminhoLivre)
                    {
                        tab[iColuna][iLinha] = 32;
                        tab[fColuna][fLinha] = 51;

                        break;
                    }
                    else
                    {
                        if ((tab[x][y] != 32) && ((tab[x][y] == 50) || (tab[x][y] == 52)))
                        {

                            tab[x][y] = 32;

                            tab[iColuna][iLinha] = 32;
                            tab[fColuna][fLinha] = 51;

                            // VERIFICA SE AINDA EXISTE PEÇAS A SEREM CAPTURADAS
                            // VERIFICA PARA BAIXO E PARA DIREITA
                            if (((tab[fColuna + 1][fLinha + 1] == 50) || (tab[fColuna + 1][fLinha + 1] == 52)) && ((fLinha + 2 >= 0) && (fLinha + 2 < 8)) && ((fColuna + 2 >= 0) && (fColuna + 2 < 8)) && (tab[fColuna + 2][fLinha + 2] == 32))
                            {
                                system("CLS");
                                //  IMPRESSãO DO TABULEIRO:
                                imprimeTab(tab);
                                printf("\nAinde existem pecas a serem capturadas e a captura e obrigatoria!");

                                pLinha = fLinha;
                                cColuna = fColuna;

                                continue;
                            }
                            // VERIFICA PARA CIMA E PARA DIREITA
                            if (((tab[fColuna + 1][fLinha - 1] == 50) || (tab[fColuna + 1][fLinha - 1] == 52)) && ((fLinha - 2 >= 0) && (fLinha - 2 < 8)) && ((fColuna + 2 >= 0) && (fColuna + 2 < 8)) && (tab[fColuna + 2][fLinha - 2] == 32))
                            {
                                system("CLS");
                                //  IMPRESSãO DO TABULEIRO:
                                imprimeTab(tab);
                                printf("\nAinde existem pecas a serem capturadas e a captura e obrigatoria!");

                                pLinha = fLinha;
                                cColuna = fColuna;
                                continue;
                            }

                            // VERIFICA PARA ESQUERDA E PARA BAIXO
                            if (((tab[fColuna - 1][fLinha + 1] == 50) || (tab[fColuna - 1][fLinha + 1] == 52)) && ((fLinha + 2 >= 0) && (fLinha + 2 < 8)) && ((fColuna - 2 >= 0) && (fColuna - 2 < 8)) && (tab[fColuna - 2][fLinha + 2] == 32))
                            {
                                system("CLS");
                                //  IMPRESSãO DO TABULEIRO:
                                imprimeTab(tab);
                                printf("\nAinde existem pecas a serem capturadas e a captura e obrigatoria!");

                                pLinha = fLinha;
                                cColuna = fColuna;
                                continue;
                            }

                            // VERIFICA PARA ESQUERDA E PARA CIMA
                            if (((tab[fColuna - 1][fLinha - 1] == 50) || (tab[fColuna - 1][fLinha - 1] == 52)) && ((fLinha - 2 >= 0) && (fLinha - 2 < 8)) && ((fColuna - 2 >= 0) && (fColuna - 2 < 8)) && (tab[fColuna - 2][fLinha - 2] == 32))
                            {
                                system("CLS");
                                //  IMPRESSãO DO TABULEIRO:
                                imprimeTab(tab);
                                printf("\nAinde existem pecas a serem capturadas e a captura e obrigatoria!");

                                pLinha = fLinha;
                                cColuna = fColuna;
                                continue;
                            }

                            break;
                        }
                        else
                        {
                            printf("\nExiste uma peca no meio do caminho:\nLinha %d\nColuna %d\n", y, x);
                            continue;
                        }
                    }
                }
                if ((iLinha < fLinha) && (iColuna > fColuna)) // MOVIMENTO ESQUERDA INFERIOR
                {
                    int caminhoLivre = 1;
                    int x, y;
                    for (y = iLinha + 1, x = iColuna - 1; y<fLinha, x> fColuna; y++, x--)
                    {
                        if (tab[x][y] != 32)
                        {
                            caminhoLivre = 0;
                            break;
                        }
                    }
                    if (caminhoLivre)
                    {
                        tab[iColuna][iLinha] = 32;
                        tab[fColuna][fLinha] = 51;

                        break;
                    }
                    else
                    {
                        if ((tab[x][y] != 32) && ((tab[x][y] == 50) || (tab[x][y] == 52)))
                        {

                            tab[x][y] = 32;

                            tab[iColuna][iLinha] = 32;
                            tab[fColuna][fLinha] = 51;

                            // VERIFICA SE AINDA EXISTE PEÇAS A SEREM CAPTURADAS
                            // VERIFICA PARA BAIXO E PARA DIREITA
                            if (((tab[fColuna + 1][fLinha + 1] == 50) || (tab[fColuna + 1][fLinha + 1] == 52)) && ((fLinha + 2 >= 0) && (fLinha + 2 < 8)) && ((fColuna + 2 >= 0) && (fColuna + 2 < 8)) && (tab[fColuna + 2][fLinha + 2] == 32))
                            {
                                system("CLS");
                                //  IMPRESSãO DO TABULEIRO:
                                imprimeTab(tab);
                                printf("\nAinde existem pecas a serem capturadas e a captura e obrigatoria!");

                                pLinha = fLinha;
                                cColuna = fColuna;

                                continue;
                            }
                            // VERIFICA PARA CIMA E PARA DIREITA
                            if (((tab[fColuna + 1][fLinha - 1] == 50) || (tab[fColuna + 1][fLinha - 1] == 52)) && ((fLinha - 2 >= 0) && (fLinha - 2 < 8)) && ((fColuna + 2 >= 0) && (fColuna + 2 < 8)) && (tab[fColuna + 2][fLinha - 2] == 32))
                            {
                                system("CLS");
                                //  IMPRESSãO DO TABULEIRO:
                                imprimeTab(tab);
                                printf("\nAinde existem pecas a serem capturadas e a captura e obrigatoria!");

                                pLinha = fLinha;
                                cColuna = fColuna;
                                continue;
                            }

                            // VERIFICA PARA ESQUERDA E PARA BAIXO
                            if (((tab[fColuna - 1][fLinha + 1] == 50) || (tab[fColuna - 1][fLinha + 1] == 52)) && ((fLinha + 2 >= 0) && (fLinha + 2 < 8)) && ((fColuna - 2 >= 0) && (fColuna - 2 < 8)) && (tab[fColuna - 2][fLinha + 2] == 32))
                            {
                                system("CLS");
                                //  IMPRESSãO DO TABULEIRO:
                                imprimeTab(tab);
                                printf("\nAinde existem pecas a serem capturadas e a captura e obrigatoria!");

                                pLinha = fLinha;
                                cColuna = fColuna;
                                continue;
                            }

                            // VERIFICA PARA ESQUERDA E PARA CIMA
                            if (((tab[fColuna - 1][fLinha - 1] == 50) || (tab[fColuna - 1][fLinha - 1] == 52)) && ((fLinha - 2 >= 0) && (fLinha - 2 < 8)) && ((fColuna - 2 >= 0) && (fColuna - 2 < 8)) && (tab[fColuna - 2][fLinha - 2] == 32))
                            {
                                system("CLS");
                                //  IMPRESSãO DO TABULEIRO:
                                imprimeTab(tab);
                                printf("\nAinde existem pecas a serem capturadas e a captura e obrigatoria!");

                                pLinha = fLinha;
                                cColuna = fColuna;
                                continue;
                            }

                            break;
                        }
                        else
                        {
                            printf("\nExiste uma peca no meio do caminho:\nLinha %d\nColuna %d\n", y, x);
                            continue;
                        }
                    }
                }
                if ((iLinha > fLinha) && (iColuna > fColuna)) // MOVIMENTO ESQUERDA SUPERIOR
                {
                    int caminhoLivre = 1;
                    int x, y;
                    for (y = iLinha - 1, x = iColuna - 1; y > fLinha, x > fColuna; y--, x--)
                    {
                        if (tab[x][y] != 32)
                        {
                            caminhoLivre = 0;
                            break;
                        }
                    }
                    if (caminhoLivre)
                    {
                        tab[iColuna][iLinha] = 32;
                        tab[fColuna][fLinha] = 51;

                        break;
                    }
                    else
                    {
                        if ((tab[x][y] != 32) && ((tab[x][y] == 50) || (tab[x][y] == 52)))
                        {

                            tab[x][y] = 32;

                            tab[iColuna][iLinha] = 32;
                            tab[fColuna][fLinha] = 51;

                            // VERIFICA SE AINDA EXISTE PEÇAS A SEREM CAPTURADAS
                            // VERIFICA PARA BAIXO E PARA DIREITA
                            if (((tab[fColuna + 1][fLinha + 1] == 50) || (tab[fColuna + 1][fLinha + 1] == 52)) && ((fLinha + 2 >= 0) && (fLinha + 2 < 8)) && ((fColuna + 2 >= 0) && (fColuna + 2 < 8)) && (tab[fColuna + 2][fLinha + 2] == 32))
                            {
                                system("CLS");
                                //  IMPRESSãO DO TABULEIRO:
                                imprimeTab(tab);
                                printf("\nAinde existem pecas a serem capturadas e a captura e obrigatoria!");

                                pLinha = fLinha;
                                cColuna = fColuna;

                                continue;
                            }
                            // VERIFICA PARA CIMA E PARA DIREITA
                            if (((tab[fColuna + 1][fLinha - 1] == 50) || (tab[fColuna + 1][fLinha - 1] == 52)) && ((fLinha - 2 >= 0) && (fLinha - 2 < 8)) && ((fColuna + 2 >= 0) && (fColuna + 2 < 8)) && (tab[fColuna + 2][fLinha - 2] == 32))
                            {
                                system("CLS");
                                //  IMPRESSãO DO TABULEIRO:
                                imprimeTab(tab);
                                printf("\nAinde existem pecas a serem capturadas e a captura e obrigatoria!");

                                pLinha = fLinha;
                                cColuna = fColuna;
                                continue;
                            }

                            // VERIFICA PARA ESQUERDA E PARA BAIXO
                            if (((tab[fColuna - 1][fLinha + 1] == 50) || (tab[fColuna - 1][fLinha + 1] == 52)) && ((fLinha + 2 >= 0) && (fLinha + 2 < 8)) && ((fColuna - 2 >= 0) && (fColuna - 2 < 8)) && (tab[fColuna - 2][fLinha + 2] == 32))
                            {
                                system("CLS");
                                //  IMPRESSãO DO TABULEIRO:
                                imprimeTab(tab);
                                printf("\nAinde existem pecas a serem capturadas e a captura e obrigatoria!");

                                pLinha = fLinha;
                                cColuna = fColuna;
                                continue;
                            }

                            // VERIFICA PARA ESQUERDA E PARA CIMA
                            if (((tab[fColuna - 1][fLinha - 1] == 50) || (tab[fColuna - 1][fLinha - 1] == 52)) && ((fLinha - 2 >= 0) && (fLinha - 2 < 8)) && ((fColuna - 2 >= 0) && (fColuna - 2 < 8)) && (tab[fColuna - 2][fLinha - 2] == 32))
                            {
                                system("CLS");
                                //  IMPRESSãO DO TABULEIRO:
                                imprimeTab(tab);
                                printf("\nAinde existem pecas a serem capturadas e a captura e obrigatoria!");

                                pLinha = fLinha;
                                cColuna = fColuna;
                                continue;
                            }

                            break;
                        }
                        else
                        {
                            printf("\nExiste uma peca no meio do caminho:\nLinha %d\nColuna %d\n", y, x);
                            continue;
                        }
                    }
                }
            }

            // CAPTURA PEÇA NORMAL

            // Captura para direita E PARA BAIXO

            if ((((fColuna == iColuna + 2) && ((fColuna >= 0) && (fColuna < 8))) && ((fLinha == iLinha + 2) && ((fLinha >= 0) && (fLinha < 8)))) && (tab[iColuna][iLinha] == 49 && tab[fColuna][fLinha] == 32))
            {

                if ((tab[iColuna + 1][iLinha + 1] == 50) || (tab[iColuna + 1][iLinha + 1] == 52))
                {
                    tab[iColuna + 1][iLinha + 1] = 32;
                }
                else
                {
                    printf("Movimento invalido");
                    continue;
                }

                tab[iColuna][iLinha] = 32;
                tab[fColuna][fLinha] = 49;

                // VERIFICA SE AINDA EXISTE PEÇAS A SEREM CAPTURADAS
                // VERIFICA PARA BAIXO E PARA DIREITA
                if (((tab[fColuna + 1][fLinha + 1] == 50) || (tab[fColuna + 1][fLinha + 1] == 52)) && ((fLinha + 2 >= 0) && (fLinha + 2 < 8)) && ((fColuna + 2 >= 0) && (fColuna + 2 < 8)) && (tab[fColuna + 2][fLinha + 2] == 32))
                {
                    system("CLS");
                    //  IMPRESSãO DO TABULEIRO:
                    imprimeTab(tab);
                    printf("\nAinde existem pecas a serem capturadas e a captura e obrigatoria!");

                    pLinha = fLinha;
                    cColuna = fColuna;

                    continue;
                }
                // VERIFICA PARA CIMA E PARA DIREITA
                if (((tab[fColuna + 1][fLinha - 1] == 50) || (tab[fColuna + 1][fLinha - 1] == 52)) && ((fLinha - 2 >= 0) && (fLinha - 2 < 8)) && ((fColuna + 2 >= 0) && (fColuna + 2 < 8)) && (tab[fColuna + 2][fLinha - 2] == 32))
                {
                    system("CLS");
                    //  IMPRESSãO DO TABULEIRO:
                    imprimeTab(tab);
                    printf("\nAinde existem pecas a serem capturadas e a captura e obrigatoria!");

                    pLinha = fLinha;
                    cColuna = fColuna;
                    continue;
                }

                // VERIFICA PARA ESQUERDA E PARA BAIXO
                if (((tab[fColuna - 1][fLinha + 1] == 50) || (tab[fColuna - 1][fLinha + 1] == 52)) && ((fLinha + 2 >= 0) && (fLinha + 2 < 8)) && ((fColuna - 2 >= 0) && (fColuna - 2 < 8)) && (tab[fColuna - 2][fLinha + 2] == 32))
                {
                    system("CLS");
                    //  IMPRESSãO DO TABULEIRO:
                    imprimeTab(tab);
                    printf("\nAinde existem pecas a serem capturadas e a captura e obrigatoria!");

                    pLinha = fLinha;
                    cColuna = fColuna;
                    continue;
                }

                // VERIFICA PARA ESQUERDA E PARA CIMA
                if (((tab[fColuna - 1][fLinha - 1] == 50) || (tab[fColuna - 1][fLinha - 1] == 52)) && ((fLinha - 2 >= 0) && (fLinha - 2 < 8)) && ((fColuna - 2 >= 0) && (fColuna - 2 < 8)) && (tab[fColuna - 2][fLinha - 2] == 32))
                {
                    system("CLS");
                    //  IMPRESSãO DO TABULEIRO:
                    imprimeTab(tab);
                    printf("\nAinde existem pecas a serem capturadas e a captura e obrigatoria!");

                    pLinha = fLinha;
                    cColuna = fColuna;
                    continue;
                }

                break;
            }

            // Captura para direita E PARA CIMA
            if ((((fColuna == iColuna + 2) && ((fColuna >= 0) && (fColuna < 8))) && ((fLinha == iLinha - 2) && ((fLinha >= 0) && (fLinha < 8)))) && (tab[iColuna][iLinha] == 49 && tab[fColuna][fLinha] == 32))
            {

                if ((tab[iColuna + 1][iLinha - 1] == 50) || (tab[iColuna + 1][iLinha - 1] == 52))
                {
                    tab[iColuna + 1][iLinha - 1] = 32;
                }
                else
                {
                    printf("Movimento invalido");
                    continue;
                }

                tab[iColuna][iLinha] = 32;
                tab[fColuna][fLinha] = 49;

                // VERIFICA SE AINDA EXISTE PEÇAS A SEREM CAPTURADAS
                // VERIFICA PARA BAIXO E PARA DIREITA

                if (((tab[fColuna + 1][fLinha + 1] == 50) || (tab[fColuna + 1][fLinha + 1] == 52)) && ((fLinha + 2 >= 0) && (fLinha + 2 < 8)) && ((fColuna + 2 >= 0) && (fColuna + 2 < 8)) && (tab[fColuna + 2][fLinha + 2] == 32))
                {
                    system("CLS");
                    // IMPRESSãO DO TABULEIRO:
                    imprimeTab(tab);

                    pLinha = fLinha;
                    cColuna = fColuna;
                    continue;
                }
                // VERIFICA PARA CIMA E PARA DIREITA

                if (((tab[fColuna + 1][fLinha - 1] == 50) || (tab[fColuna + 1][fLinha - 1] == 52)) && ((fLinha - 2 >= 0) && (fLinha - 2 < 8)) && ((fColuna + 2 >= 0) && (fColuna + 2 < 8)) && (tab[fColuna + 2][fLinha - 2] == 32))
                {
                    system("CLS");
                    // IMPRESSãO DO TABULEIRO:
                    imprimeTab(tab);
                    printf("\nAinde existem pecas a serem capturadas e a captura e obrigatoria!");

                    pLinha = fLinha;
                    cColuna = fColuna;
                    continue;
                }

                // VERIFICA PARA ESQUERDA E PARA BAIXO

                if (((tab[fColuna - 1][fLinha + 1] == 50) || (tab[fColuna - 1][fLinha + 1] == 52)) && ((fLinha + 2 >= 0) && (fLinha + 2 < 8)) && ((fColuna - 2 >= 0) && (fColuna - 2 < 8)) && (tab[fColuna - 2][fLinha + 2] == 32))
                {
                    system("CLS");
                    // IMPRESSãO DO TABULEIRO:
                    imprimeTab(tab);
                    printf("\nAinde existem pecas a serem capturadas e a captura e obrigatoria!");

                    pLinha = fLinha;
                    cColuna = fColuna;
                    continue;
                }

                // VERIFICA PARA ESQUERDA E PARA CIMA

                if (((tab[fColuna - 1][fLinha - 1] == 50) || (tab[fColuna - 1][fLinha - 1] == 52)) && ((fLinha - 2 >= 0) && (fLinha - 2 < 8)) && ((fColuna - 2 >= 0) && (fColuna - 2 < 8)) && (tab[fColuna - 2][fLinha - 2] == 32))
                {
                    system("CLS");
                    // IMPRESSãO DO TABULEIRO:
                    imprimeTab(tab);
                    printf("\nAinde existem pecas a serem capturadas e a captura e obrigatoria!");

                    pLinha = fLinha;
                    cColuna = fColuna;
                    continue;
                }

                break;
            }

            // Captura para esqueda E PARA BAIXO

            if ((((fColuna == iColuna - 2) && ((fColuna >= 0) && (fColuna < 8))) && ((fLinha == iLinha + 2) && ((fLinha >= 0) && (fLinha < 8)))) && (tab[iColuna][iLinha] == 49 && tab[fColuna][fLinha] == 32))
            {

                if ((tab[iColuna - 1][iLinha + 1] == 50) || (tab[iColuna - 1][iLinha + 1] == 52))
                {
                    tab[iColuna - 1][iLinha + 1] = 32;
                }
                else
                {
                    printf("Movimento invalido");
                    continue;
                }

                tab[iColuna][iLinha] = 32;
                tab[fColuna][fLinha] = 49;

                // VERIFICA SE AINDA EXISTE PEÇAS A SEREM CAPTURADAS
                // VERIFICA PARA BAIXO E PARA DIREITA

                if (((tab[fColuna + 1][fLinha + 1] == 50) || (tab[fColuna + 1][fLinha + 1] == 52)) && ((fLinha + 2 >= 0) && (fLinha + 2 < 8)) && ((fColuna + 2 >= 0) && (fColuna + 2 < 8)) && (tab[fColuna + 2][fLinha + 2] == 32))
                {
                    system("CLS");
                    // IMPRESSãO DO TABULEIRO:
                    imprimeTab(tab);
                    printf("\nAinde existem pecas a serem capturadas e a captura e obrigatoria!");

                    pLinha = fLinha;
                    cColuna = fColuna;

                    continue;
                }
                // VERIFICA PARA CIMA E PARA DIREITA

                if (((tab[fColuna + 1][fLinha - 1] == 50) || (tab[fColuna + 1][fLinha - 1] == 52)) && ((fLinha - 2 >= 0) && (fLinha - 2 < 8)) && ((fColuna + 2 >= 0) && (fColuna + 2 < 8)) && (tab[fColuna + 2][fLinha - 2] == 32))
                {
                    system("CLS");
                    // IMPRESSãO DO TABULEIRO:
                    imprimeTab(tab);
                    printf("\nAinde existem pecas a serem capturadas e a captura e obrigatoria!");

                    pLinha = fLinha;
                    cColuna = fColuna;
                    continue;
                }

                // VERIFICA PARA ESQUERDA E PARA BAIXO

                if (((tab[fColuna - 1][fLinha + 1] == 50) || (tab[fColuna - 1][fLinha + 1] == 52)) && ((fLinha + 2 >= 0) && (fLinha + 2 < 8)) && ((fColuna - 2 >= 0) && (fColuna - 2 < 8)) && (tab[fColuna - 2][fLinha + 2] == 32))
                {
                    system("CLS");
                    // IMPRESSãO DO TABULEIRO:
                    imprimeTab(tab);
                    printf("\nAinde existem pecas a serem capturadas e a captura e obrigatoria!");

                    pLinha = fLinha;
                    cColuna = fColuna;
                    continue;
                }

                // VERIFICA PARA ESQUERDA E PARA CIMA

                if (((tab[fColuna - 1][fLinha - 1] == 50) || (tab[fColuna - 1][fLinha - 1] == 52)) && ((fLinha - 2 >= 0) && (fLinha - 2 < 8)) && ((fColuna - 2 >= 0) && (fColuna - 2 < 8)) && (tab[fColuna - 2][fLinha - 2] == 32))
                {
                    system("CLS");
                    // IMPRESSãO DO TABULEIRO:
                    imprimeTab(tab);
                    printf("\nAinde existem pecas a serem capturadas e a captura e obrigatoria!");

                    pLinha = fLinha;
                    cColuna = fColuna;
                    continue;
                }

                break;
            }

            // Captura para esqueda E PARA CIMA

            if ((((fColuna == iColuna - 2) && ((fColuna >= 0) && (fColuna < 8))) && ((fLinha == iLinha - 2) && ((fLinha >= 0) && (fLinha < 8)))) && (tab[iColuna][iLinha] == 49 && tab[fColuna][fLinha] == 32))
            {

                if ((tab[iColuna - 1][iLinha - 1] == 50) || (tab[iColuna - 1][iLinha - 1] == 52))
                {
                    tab[iColuna - 1][iLinha - 1] = 32;
                }
                else
                {
                    printf("Movimento invalido");
                    continue;
                }

                tab[iColuna][iLinha] = 32;
                tab[fColuna][fLinha] = 49;

                // VERIFICA SE AINDA EXISTE PEÇAS A SEREM CAPTURADAS
                // VERIFICA PARA BAIXO E PARA DIREITA

                if (((tab[fColuna + 1][fLinha + 1] == 50) || (tab[fColuna + 1][fLinha + 1] == 52)) && ((fLinha + 2 >= 0) && (fLinha + 2 < 8)) && ((fColuna + 2 >= 0) && (fColuna + 2 < 8)) && (tab[fColuna + 2][fLinha + 2] == 32))
                {
                    system("CLS");
                    // IMPRESSãO DO TABULEIRO:
                    imprimeTab(tab);
                    printf("\nAinde existem pecas a serem capturadas e a captura e obrigatoria!");

                    pLinha = fLinha;
                    cColuna = fColuna;
                    continue;
                }
                // VERIFICA PARA CIMA E PARA DIREITA

                if (((tab[fColuna + 1][fLinha - 1] == 50) || (tab[fColuna + 1][fLinha - 1] == 52)) && ((fLinha - 2 >= 0) && (fLinha - 2 < 8)) && ((fColuna + 2 >= 0) && (fColuna + 2 < 8)) && (tab[fColuna + 2][fLinha - 2] == 32))
                {
                    system("CLS");
                    // IMPRESSãO DO TABULEIRO:
                    imprimeTab(tab);
                    printf("\nAinde existem pecas a serem capturadas e a captura e obrigatoria!");

                    pLinha = fLinha;
                    cColuna = fColuna;
                    continue;
                }

                // VERIFICA PARA ESQUERDA E PARA BAIXO

                if (((tab[fColuna - 1][fLinha + 1] == 50) || (tab[fColuna - 1][fLinha + 1] == 52)) && ((fLinha + 2 >= 0) && (fLinha + 2 < 8)) && ((fColuna - 2 >= 0) && (fColuna - 2 < 8)) && (tab[fColuna - 2][fLinha + 2] == 32))
                {
                    system("CLS");
                    // IMPRESSãO DO TABULEIRO:
                    imprimeTab(tab);
                    printf("\nAinde existem pecas a serem capturadas e a captura e obrigatoria!");

                    pLinha = fLinha;
                    cColuna = fColuna;
                    continue;
                }

                // VERIFICA PARA ESQUERDA E PARA CIMA

                if (((tab[fColuna - 1][fLinha - 1] == 50) || (tab[fColuna - 1][fLinha - 1] == 52)) && ((fLinha - 2 >= 0) && (fLinha - 2 < 8)) && ((fColuna - 2 >= 0) && (fColuna - 2 < 8)) && (tab[fColuna - 2][fLinha - 2] == 32))
                {
                    system("CLS");
                    // IMPRESSãO DO TABULEIRO:
                    imprimeTab(tab);
                    printf("\nAinde existem pecas a serem capturadas e a captura e obrigatoria!");

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
                    printf("Movimento invalido");
                    continue;
                }
            }
        }
        // VOLTA A VALER 10
        pLinha = 10;
        cColuna = 10;
        system("CLS");

        // VERIFICA SE VIROU DAMA:
        for (iColuna = 0; iColuna < 9; iColuna++)
        {
            if (tab[iColuna][7] == 49)
            {
                tab[iColuna][7] = 51;
            }
        }

        // IMPRESSãO DO TABULEIRO:
        imprimeTab(tab);

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

                printf("\n\n                 ---Jogador 2--- \n");
                printf("Digite as coordenadas de origem da sua peca: (Linha e Coluna)\n");
                scanf("%d %d", &iLinha, &iColuna);
                printf("Digite as coordenadas de destino da sua peca: (Linha e Coluna)\n");
                scanf("%d %d", &fLinha, &fColuna);

                if (pLinha != iLinha && cColuna != iColuna || pLinha == iLinha && cColuna != iColuna || pLinha != iLinha && cColuna == iColuna)
                {
                    if (pLinha != 10 || cColuna != 10)
                    {
                        printf("\nA captura %c obrigatoria na Linha %d Coluna %d\n", 130, pLinha, cColuna);
                        continue;
                    }
                }

                // MOVIMENTO DAMA

                if ((tab[iColuna][iLinha] == 52) && ((abs(iLinha - fLinha) >= 1) && (abs(iColuna - fColuna) >= 1)))
                {
                    if ((iLinha < fLinha) && (iColuna < fColuna)) // MOVIMENTO DIREITA INFERIOR
                    {
                        int caminhoLivre = 1;
                        int x, y;
                        for (y = iLinha + 1, x = iColuna + 1; y < fLinha, x < fColuna; y++, x++)
                        {
                            if (tab[x][y] != 32)
                            {
                                caminhoLivre = 0;
                                break;
                            }
                        }
                        if (caminhoLivre)
                        {
                            tab[iColuna][iLinha] = 32;
                            tab[fColuna][fLinha] = 52;

                            break;
                        }
                        else
                        {
                            if ((tab[x][y] != 32) && ((tab[x][y] == 49) || (tab[x][y] == 51)))
                            {

                                tab[x][y] = 32;

                                tab[iColuna][iLinha] = 32;
                                tab[fColuna][fLinha] = 52;

                                // VERIFICA SE AINDA EXISTE PEÇAS A SEREM CAPTURADAS
                                // VERIFICA PARA BAIXO E PARA DIREITA
                                if (((tab[fColuna + 1][fLinha + 1] == 49) || (tab[fColuna + 1][fLinha + 1] == 51)) && ((fLinha + 2 >= 0) && (fLinha + 2 < 8)) && ((fColuna + 2 >= 0) && (fColuna + 2 < 8)) && (tab[fColuna + 2][fLinha + 2] == 32))
                                {
                                    system("CLS");
                                    //  IMPRESSãO DO TABULEIRO:
                                    imprimeTab(tab);
                                    printf("\nAinde existem pecas a serem capturadas e a captura e obrigatoria!");

                                    pLinha = fLinha;
                                    cColuna = fColuna;

                                    continue;
                                }
                                // VERIFICA PARA CIMA E PARA DIREITA
                                if (((tab[fColuna + 1][fLinha - 1] == 49) || (tab[fColuna + 1][fLinha - 1] == 51)) && ((fLinha - 2 >= 0) && (fLinha - 2 < 8)) && ((fColuna + 2 >= 0) && (fColuna + 2 < 8)) && (tab[fColuna + 2][fLinha - 2] == 32))
                                {
                                    system("CLS");
                                    //  IMPRESSãO DO TABULEIRO:
                                    imprimeTab(tab);
                                    printf("\nAinde existem pecas a serem capturadas e a captura e obrigatoria!");

                                    pLinha = fLinha;
                                    cColuna = fColuna;
                                    continue;
                                }

                                // VERIFICA PARA ESQUERDA E PARA BAIXO
                                if (((tab[fColuna - 1][fLinha + 1] == 49) || (tab[fColuna - 1][fLinha + 1] == 51)) && ((fLinha + 2 >= 0) && (fLinha + 2 < 8)) && ((fColuna - 2 >= 0) && (fColuna - 2 < 8)) && (tab[fColuna - 2][fLinha + 2] == 32))
                                {
                                    system("CLS");
                                    //  IMPRESSãO DO TABULEIRO:
                                    imprimeTab(tab);
                                    printf("\nAinde existem pecas a serem capturadas e a captura e obrigatoria!");

                                    pLinha = fLinha;
                                    cColuna = fColuna;
                                    continue;
                                }

                                // VERIFICA PARA ESQUERDA E PARA CIMA
                                if (((tab[fColuna - 1][fLinha - 1] == 49) || (tab[fColuna - 1][fLinha - 1] == 51)) && ((fLinha - 2 >= 0) && (fLinha - 2 < 8)) && ((fColuna - 2 >= 0) && (fColuna - 2 < 8)) && (tab[fColuna - 2][fLinha - 2] == 32))
                                {
                                    system("CLS");
                                    //  IMPRESSãO DO TABULEIRO:
                                    imprimeTab(tab);
                                    printf("\nAinde existem pecas a serem capturadas e a captura e obrigatoria!");

                                    pLinha = fLinha;
                                    cColuna = fColuna;
                                    continue;
                                }

                                break;
                            }
                            else
                            {
                                printf("\nExiste uma peça no meio do caminho:\nLinha %d\nColuna %d\n", y, x);
                                continue;
                            }
                        }
                    }

                    if ((iLinha > fLinha) && (iColuna < fColuna)) // MOVIMENTO DIREITA SUPERIOR
                    {
                        int caminhoLivre = 1;
                        int x, y;
                        for (y = iLinha - 1, x = iColuna + 1; y < fLinha, x < fColuna; y--, x++)
                        {
                            if (tab[x][y] != 32)
                            {
                                caminhoLivre = 0;
                                break;
                            }
                        }
                        if (caminhoLivre)
                        {
                            tab[iColuna][iLinha] = 32;
                            tab[fColuna][fLinha] = 52;

                            break;
                        }
                        else
                        {
                            if ((tab[x][y] != 32) && ((tab[x][y] == 49) || (tab[x][y] == 51)))
                            {

                                tab[x][y] = 32;

                                tab[iColuna][iLinha] = 32;
                                tab[fColuna][fLinha] = 52;

                                // VERIFICA SE AINDA EXISTE PEÇAS A SEREM CAPTURADAS
                                // VERIFICA PARA BAIXO E PARA DIREITA
                                if (((tab[fColuna + 1][fLinha + 1] == 49) || (tab[fColuna + 1][fLinha + 1] == 51)) && ((fLinha + 2 >= 0) && (fLinha + 2 < 8)) && ((fColuna + 2 >= 0) && (fColuna + 2 < 8)) && (tab[fColuna + 2][fLinha + 2] == 32))
                                {
                                    system("CLS");
                                    //  IMPRESSãO DO TABULEIRO:
                                    imprimeTab(tab);
                                    printf("\nAinde existem pecas a serem capturadas e a captura e obrigatoria!");

                                    pLinha = fLinha;
                                    cColuna = fColuna;

                                    continue;
                                }
                                // VERIFICA PARA CIMA E PARA DIREITA
                                if (((tab[fColuna + 1][fLinha - 1] == 49) || (tab[fColuna + 1][fLinha - 1] == 51)) && ((fLinha - 2 >= 0) && (fLinha - 2 < 8)) && ((fColuna + 2 >= 0) && (fColuna + 2 < 8)) && (tab[fColuna + 2][fLinha - 2] == 32))
                                {
                                    system("CLS");
                                    //  IMPRESSãO DO TABULEIRO:
                                    imprimeTab(tab);
                                    printf("\nAinde existem pecas a serem capturadas e a captura e obrigatoria!");

                                    pLinha = fLinha;
                                    cColuna = fColuna;
                                    continue;
                                }

                                // VERIFICA PARA ESQUERDA E PARA BAIXO
                                if (((tab[fColuna - 1][fLinha + 1] == 49) || (tab[fColuna - 1][fLinha + 1] == 51)) && ((fLinha + 2 >= 0) && (fLinha + 2 < 8)) && ((fColuna - 2 >= 0) && (fColuna - 2 < 8)) && (tab[fColuna - 2][fLinha + 2] == 32))
                                {
                                    system("CLS");
                                    //  IMPRESSãO DO TABULEIRO:
                                    imprimeTab(tab);
                                    printf("\nAinde existem pecas a serem capturadas e a captura e obrigatoria!");

                                    pLinha = fLinha;
                                    cColuna = fColuna;
                                    continue;
                                }

                                // VERIFICA PARA ESQUERDA E PARA CIMA
                                if (((tab[fColuna - 1][fLinha - 1] == 49) || (tab[fColuna - 1][fLinha - 1] == 51)) && ((fLinha - 2 >= 0) && (fLinha - 2 < 8)) && ((fColuna - 2 >= 0) && (fColuna - 2 < 8)) && (tab[fColuna - 2][fLinha - 2] == 32))
                                {
                                    system("CLS");
                                    //  IMPRESSãO DO TABULEIRO:
                                    imprimeTab(tab);
                                    printf("\nAinde existem pecas a serem capturadas e a captura e obrigatoria!");

                                    pLinha = fLinha;
                                    cColuna = fColuna;
                                    continue;
                                }

                                break;
                            }
                            else
                            {
                                printf("\nExiste uma peça no meio do caminho:\nLinha %d\nColuna %d\n", y, x);
                                continue;
                            }
                        }
                    }
                    if ((iLinha < fLinha) && (iColuna > fColuna)) // MOVIMENTO ESQUERDA INFERIOR
                    {
                        int caminhoLivre = 1;
                        int x, y;
                        for (y = iLinha + 1, x = iColuna - 1; y<fLinha, x> fColuna; y++, x--)
                        {
                            if (tab[x][y] != 32)
                            {
                                caminhoLivre = 0;
                                break;
                            }
                        }
                        if (caminhoLivre)
                        {
                            tab[iColuna][iLinha] = 32;
                            tab[fColuna][fLinha] = 52;

                            break;
                        }
                        else
                        {
                            if ((tab[x][y] != 32) && ((tab[x][y] == 49) || (tab[x][y] == 51)))
                            {

                                tab[x][y] = 32;

                                tab[iColuna][iLinha] = 32;
                                tab[fColuna][fLinha] = 52;

                                // VERIFICA SE AINDA EXISTE PEÇAS A SEREM CAPTURADAS
                                // VERIFICA PARA BAIXO E PARA DIREITA
                                if (((tab[fColuna + 1][fLinha + 1] == 49) || (tab[fColuna + 1][fLinha + 1] == 51)) && ((fLinha + 2 >= 0) && (fLinha + 2 < 8)) && ((fColuna + 2 >= 0) && (fColuna + 2 < 8)) && (tab[fColuna + 2][fLinha + 2] == 32))
                                {
                                    system("CLS");
                                    //  IMPRESSãO DO TABULEIRO:
                                    imprimeTab(tab);
                                    printf("\nAinde existem pecas a serem capturadas e a captura e obrigatoria!");

                                    pLinha = fLinha;
                                    cColuna = fColuna;

                                    continue;
                                }
                                // VERIFICA PARA CIMA E PARA DIREITA
                                if (((tab[fColuna + 1][fLinha - 1] == 49) || (tab[fColuna + 1][fLinha - 1] == 51)) && ((fLinha - 2 >= 0) && (fLinha - 2 < 8)) && ((fColuna + 2 >= 0) && (fColuna + 2 < 8)) && (tab[fColuna + 2][fLinha - 2] == 32))
                                {
                                    system("CLS");
                                    //  IMPRESSãO DO TABULEIRO:
                                    imprimeTab(tab);
                                    printf("\nAinde existem pecas a serem capturadas e a captura e obrigatoria!");

                                    pLinha = fLinha;
                                    cColuna = fColuna;
                                    continue;
                                }

                                // VERIFICA PARA ESQUERDA E PARA BAIXO
                                if (((tab[fColuna - 1][fLinha + 1] == 49) || (tab[fColuna - 1][fLinha + 1] == 51)) && ((fLinha + 2 >= 0) && (fLinha + 2 < 8)) && ((fColuna - 2 >= 0) && (fColuna - 2 < 8)) && (tab[fColuna - 2][fLinha + 2] == 32))
                                {
                                    system("CLS");
                                    //  IMPRESSãO DO TABULEIRO:
                                    imprimeTab(tab);
                                    printf("\nAinde existem pecas a serem capturadas e a captura e obrigatoria!");

                                    pLinha = fLinha;
                                    cColuna = fColuna;
                                    continue;
                                }

                                // VERIFICA PARA ESQUERDA E PARA CIMA
                                if (((tab[fColuna - 1][fLinha - 1] == 49) || (tab[fColuna - 1][fLinha - 1] == 51)) && ((fLinha - 2 >= 0) && (fLinha - 2 < 8)) && ((fColuna - 2 >= 0) && (fColuna - 2 < 8)) && (tab[fColuna - 2][fLinha - 2] == 32))
                                {
                                    system("CLS");
                                    //  IMPRESSãO DO TABULEIRO:
                                    imprimeTab(tab);
                                    printf("\nAinde existem pecas a serem capturadas e a captura e obrigatoria!");

                                    pLinha = fLinha;
                                    cColuna = fColuna;
                                    continue;
                                }

                                break;
                            }
                            else
                            {
                                printf("\nExiste uma peça no meio do caminho:\nLinha %d\nColuna %d\n", y, x);
                                continue;
                            }
                        }
                    }
                    if ((iLinha > fLinha) && (iColuna > fColuna)) // MOVIMENTO ESQUERDA SUPERIOR
                    {
                        int caminhoLivre = 1;
                        int x, y;
                        for (y = iLinha - 1, x = iColuna - 1; y > fLinha, x > fColuna; y--, x--)
                        {
                            if (tab[x][y] != 32)
                            {
                                caminhoLivre = 0;
                                break;
                            }
                        }
                        if (caminhoLivre)
                        {
                            tab[iColuna][iLinha] = 32;
                            tab[fColuna][fLinha] = 52;

                            break;
                        }
                        else
                        {
                            if ((tab[x][y] != 32) && ((tab[x][y] == 49) || (tab[x][y] == 51)))
                            {

                                tab[x][y] = 32;

                                tab[iColuna][iLinha] = 32;
                                tab[fColuna][fLinha] = 52;

                                // VERIFICA SE AINDA EXISTE PEÇAS A SEREM CAPTURADAS
                                // VERIFICA PARA BAIXO E PARA DIREITA
                                if (((tab[fColuna + 1][fLinha + 1] == 49) || (tab[fColuna + 1][fLinha + 1] == 51)) && ((fLinha + 2 >= 0) && (fLinha + 2 < 8)) && ((fColuna + 2 >= 0) && (fColuna + 2 < 8)) && (tab[fColuna + 2][fLinha + 2] == 32))
                                {
                                    system("CLS");
                                    //  IMPRESSãO DO TABULEIRO:
                                    imprimeTab(tab);
                                    printf("\nAinde existem pecas a serem capturadas e a captura e obrigatoria!");

                                    pLinha = fLinha;
                                    cColuna = fColuna;

                                    continue;
                                }
                                // VERIFICA PARA CIMA E PARA DIREITA
                                if (((tab[fColuna + 1][fLinha - 1] == 49) || (tab[fColuna + 1][fLinha - 1] == 51)) && ((fLinha - 2 >= 0) && (fLinha - 2 < 8)) && ((fColuna + 2 >= 0) && (fColuna + 2 < 8)) && (tab[fColuna + 2][fLinha - 2] == 32))
                                {
                                    system("CLS");
                                    //  IMPRESSãO DO TABULEIRO:
                                    imprimeTab(tab);
                                    printf("\nAinde existem pecas a serem capturadas e a captura e obrigatoria!");

                                    pLinha = fLinha;
                                    cColuna = fColuna;
                                    continue;
                                }

                                // VERIFICA PARA ESQUERDA E PARA BAIXO
                                if (((tab[fColuna - 1][fLinha + 1] == 49) || (tab[fColuna - 1][fLinha + 1] == 51)) && ((fLinha + 2 >= 0) && (fLinha + 2 < 8)) && ((fColuna - 2 >= 0) && (fColuna - 2 < 8)) && (tab[fColuna - 2][fLinha + 2] == 32))
                                {
                                    system("CLS");
                                    //  IMPRESSãO DO TABULEIRO:
                                    imprimeTab(tab);
                                    printf("\nAinde existem pecas a serem capturadas e a captura e obrigatoria!");

                                    pLinha = fLinha;
                                    cColuna = fColuna;
                                    continue;
                                }

                                // VERIFICA PARA ESQUERDA E PARA CIMA
                                if (((tab[fColuna - 1][fLinha - 1] == 49) || (tab[fColuna - 1][fLinha - 1] == 51)) && ((fLinha - 2 >= 0) && (fLinha - 2 < 8)) && ((fColuna - 2 >= 0) && (fColuna - 2 < 8)) && (tab[fColuna - 2][fLinha - 2] == 32))
                                {
                                    system("CLS");
                                    //  IMPRESSãO DO TABULEIRO:
                                    imprimeTab(tab);
                                    printf("\nAinde existem pecas a serem capturadas e a captura e obrigatoria!");

                                    pLinha = fLinha;
                                    cColuna = fColuna;
                                    continue;
                                }

                                break;
                            }
                            else
                            {
                                printf("\nExiste uma peça no meio do caminho:\nLinha %d\nColuna %d\n", y, x);
                                continue;
                            }
                        }
                    }
                }

                // CAPTURA PEÇA NORMAL
                // Captura para direita E PARA BAIXO

                if ((((fColuna == iColuna + 2) && ((fColuna >= 0) && (fColuna < 8))) && ((fLinha == iLinha + 2) && ((fLinha >= 0) && (fLinha < 8)))) && (tab[iColuna][iLinha] == 50 && tab[fColuna][fLinha] == 32))
                {

                    if ((tab[iColuna + 1][iLinha + 1] == 49) || (tab[iColuna + 1][iLinha + 1] == 51))
                    {
                        tab[iColuna + 1][iLinha + 1] = 32;
                    }
                    else
                    {
                        printf("Movimento invalido");
                        continue;
                    }

                    tab[iColuna][iLinha] = 32;
                    tab[fColuna][fLinha] = 50;

                    // VERIFICA SE AINDA EXISTE PEÇAS A SEREM CAPTURADAS
                    // VERIFICA PARA BAIXO E PARA DIREITA
                    if (((tab[fColuna + 1][fLinha + 1] == 49) || (tab[fColuna + 1][fLinha + 1] == 51)) && ((fLinha + 2 >= 0) && (fLinha + 2 < 8)) && ((fColuna + 2 >= 0) && (fColuna + 2 < 8)) && (tab[fColuna + 2][fLinha + 2] == 32))
                    {
                        system("CLS");
                        //  IMPRESSãO DO TABULEIRO:
                        imprimeTab(tab);
                        printf("\nAinde existem pecas a serem capturadas e a captura e obrigatoria!");

                        pLinha = fLinha;
                        cColuna = fColuna;

                        continue;
                    }
                    // VERIFICA PARA CIMA E PARA DIREITA
                    if (((tab[fColuna + 1][fLinha - 1] == 49) || (tab[fColuna + 1][fLinha - 1] == 51)) && ((fLinha - 2 >= 0) && (fLinha - 2 < 8)) && ((fColuna + 2 >= 0) && (fColuna + 2 < 8)) && (tab[fColuna + 2][fLinha - 2] == 32))
                    {
                        system("CLS");
                        //  IMPRESSãO DO TABULEIRO:
                        imprimeTab(tab);
                        printf("\nAinde existem pecas a serem capturadas e a captura e obrigatoria!");

                        pLinha = fLinha;
                        cColuna = fColuna;
                        continue;
                    }

                    // VERIFICA PARA ESQUERDA E PARA BAIXO
                    if (((tab[fColuna - 1][fLinha + 1] == 49) || (tab[fColuna - 1][fLinha + 1] == 51)) && ((fLinha + 2 >= 0) && (fLinha + 2 < 8)) && ((fColuna - 2 >= 0) && (fColuna - 2 < 8)) && (tab[fColuna - 2][fLinha + 2] == 32))
                    {
                        system("CLS");
                        //  IMPRESSãO DO TABULEIRO:
                        imprimeTab(tab);
                        printf("\nAinde existem pecas a serem capturadas e a captura e obrigatoria!");

                        pLinha = fLinha;
                        cColuna = fColuna;
                        continue;
                    }

                    // VERIFICA PARA ESQUERDA E PARA CIMA
                    if (((tab[fColuna - 1][fLinha - 1] == 49) || (tab[fColuna - 1][fLinha - 1] == 51)) && ((fLinha - 2 >= 0) && (fLinha - 2 < 8)) && ((fColuna - 2 >= 0) && (fColuna - 2 < 8)) && (tab[fColuna - 2][fLinha - 2] == 32))
                    {
                        system("CLS");
                        //  IMPRESSãO DO TABULEIRO:
                        imprimeTab(tab);
                        printf("\nAinde existem pecas a serem capturadas e a captura e obrigatoria!");

                        pLinha = fLinha;
                        cColuna = fColuna;
                        continue;
                    }

                    break;
                }

                // Captura para direita E PARA CIMA
                if ((((fColuna == iColuna + 2) && ((fColuna >= 0) && (fColuna < 8))) && ((fLinha == iLinha - 2) && ((fLinha >= 0) && (fLinha < 8)))) && (tab[iColuna][iLinha] == 50 && tab[fColuna][fLinha] == 32))
                {

                    if ((tab[iColuna + 1][iLinha - 1] == 49) || (tab[iColuna + 1][iLinha - 1] == 51))
                    {
                        tab[iColuna + 1][iLinha - 1] = 32;
                    }
                    else
                    {
                        printf("Movimento invalido");
                        continue;
                    }

                    tab[iColuna][iLinha] = 32;
                    tab[fColuna][fLinha] = 50;

                    // VERIFICA SE AINDA EXISTE PEÇAS A SEREM CAPTURADAS
                    // VERIFICA PARA BAIXO E PARA DIREITA

                    if (((tab[fColuna + 1][fLinha + 1] == 49) || (tab[fColuna + 1][fLinha + 1] == 51)) && ((fLinha + 2 >= 0) && (fLinha + 2 < 8)) && ((fColuna + 2 >= 0) && (fColuna + 2 < 8)) && (tab[fColuna + 2][fLinha + 2] == 32))
                    {
                        system("CLS");
                        // IMPRESSãO DO TABULEIRO:
                        imprimeTab(tab);
                        printf("\nAinde existem pecas a serem capturadas e a captura e obrigatoria!");

                        pLinha = fLinha;
                        cColuna = fColuna;
                        continue;
                    }
                    // VERIFICA PARA CIMA E PARA DIREITA

                    if (((tab[fColuna + 1][fLinha - 1] == 49) || (tab[fColuna + 1][fLinha - 1] == 51)) && ((fLinha - 2 >= 0) && (fLinha - 2 < 8)) && ((fColuna + 2 >= 0) && (fColuna + 2 < 8)) && (tab[fColuna + 2][fLinha - 2] == 32))
                    {
                        system("CLS");
                        // IMPRESSãO DO TABULEIRO:
                        imprimeTab(tab);
                        printf("\nAinde existem pecas a serem capturadas e a captura e obrigatoria!");

                        pLinha = fLinha;
                        cColuna = fColuna;
                        continue;
                    }

                    // VERIFICA PARA ESQUERDA E PARA BAIXO

                    if (((tab[fColuna - 1][fLinha + 1] == 49) || (tab[fColuna - 1][fLinha + 1] == 51)) && ((fLinha + 2 >= 0) && (fLinha + 2 < 8)) && ((fColuna - 2 >= 0) && (fColuna - 2 < 8)) && (tab[fColuna - 2][fLinha + 2] == 32))
                    {
                        system("CLS");
                        // IMPRESSãO DO TABULEIRO:
                        imprimeTab(tab);
                        printf("\nAinde existem pecas a serem capturadas e a captura e obrigatoria!");

                        pLinha = fLinha;
                        cColuna = fColuna;
                        continue;
                    }

                    // VERIFICA PARA ESQUERDA E PARA CIMA

                    if (((tab[fColuna - 1][fLinha - 1] == 49) || (tab[fColuna - 1][fLinha - 1] == 51)) && ((fLinha - 2 >= 0) && (fLinha - 2 < 8)) && ((fColuna - 2 >= 0) && (fColuna - 2 < 8)) && (tab[fColuna - 2][fLinha - 2] == 32))
                    {
                        system("CLS");
                        // IMPRESSãO DO TABULEIRO:
                        imprimeTab(tab);
                        printf("\nAinde existem pecas a serem capturadas e a captura e obrigatoria!");

                        pLinha = fLinha;
                        cColuna = fColuna;
                        continue;
                    }

                    break;
                }

                // Captura para esqueda E PARA BAIXO

                if ((((fColuna == iColuna - 2) && ((fColuna >= 0) && (fColuna < 8))) && ((fLinha == iLinha + 2) && ((fLinha >= 0) && (fLinha < 8)))) && (tab[iColuna][iLinha] == 50 && tab[fColuna][fLinha] == 32))
                {

                    if ((tab[iColuna - 1][iLinha + 1] == 49) || (tab[iColuna - 1][iLinha + 1] == 51))
                    {
                        tab[iColuna - 1][iLinha + 1] = 32;
                    }
                    else
                    {
                        printf("Movimento invalido");
                        continue;
                    }

                    tab[iColuna][iLinha] = 32;
                    tab[fColuna][fLinha] = 50;

                    // VERIFICA SE AINDA EXISTE PEÇAS A SEREM CAPTURADAS
                    // VERIFICA PARA BAIXO E PARA DIREITA

                    if (((tab[fColuna + 1][fLinha + 1] == 49) || (tab[fColuna + 1][fLinha + 1] == 51)) && ((fLinha + 2 >= 0) && (fLinha + 2 < 8)) && ((fColuna + 2 >= 0) && (fColuna + 2 < 8)) && (tab[fColuna + 2][fLinha + 2] == 32))
                    {
                        system("CLS");
                        // IMPRESSãO DO TABULEIRO:
                        imprimeTab(tab);
                        printf("\nAinde existem pecas a serem capturadas e a captura e obrigatoria!");

                        pLinha = fLinha;
                        cColuna = fColuna;

                        continue;
                    }
                    // VERIFICA PARA CIMA E PARA DIREITA

                    if (((tab[fColuna + 1][fLinha - 1] == 49) || (tab[fColuna + 1][fLinha - 1] == 51)) && ((fLinha - 2 >= 0) && (fLinha - 2 < 8)) && ((fColuna + 2 >= 0) && (fColuna + 2 < 8)) && (tab[fColuna + 2][fLinha - 2] == 32))
                    {
                        system("CLS");
                        // IMPRESSãO DO TABULEIRO:
                        imprimeTab(tab);
                        printf("\nAinde existem pecas a serem capturadas e a captura e obrigatoria!");

                        pLinha = fLinha;
                        cColuna = fColuna;
                        continue;
                    }

                    // VERIFICA PARA ESQUERDA E PARA BAIXO

                    if (((tab[fColuna - 1][fLinha + 1] == 49) || (tab[fColuna - 1][fLinha + 1] == 51)) && ((fLinha + 2 >= 0) && (fLinha + 2 < 8)) && ((fColuna - 2 >= 0) && (fColuna - 2 < 8)) && (tab[fColuna - 2][fLinha + 2] == 32))
                    {
                        system("CLS");
                        // IMPRESSãO DO TABULEIRO:
                        imprimeTab(tab);
                        printf("\nAinde existem pecas a serem capturadas e a captura e obrigatoria!");

                        pLinha = fLinha;
                        cColuna = fColuna;
                        continue;
                    }

                    // VERIFICA PARA ESQUERDA E PARA CIMA

                    if (((tab[fColuna - 1][fLinha - 1] == 49) || (tab[fColuna - 1][fLinha - 1] == 51)) && ((fLinha - 2 >= 0) && (fLinha - 2 < 8)) && ((fColuna - 2 >= 0) && (fColuna - 2 < 8)) && (tab[fColuna - 2][fLinha - 2] == 32))
                    {
                        system("CLS");
                        // IMPRESSãO DO TABULEIRO:
                        imprimeTab(tab);
                        printf("\nAinde existem pecas a serem capturadas e a captura e obrigatoria!");

                        pLinha = fLinha;
                        cColuna = fColuna;
                        continue;
                    }

                    break;
                }

                // Captura para esqueda E PARA CIMA

                if ((((fColuna == iColuna - 2) && ((fColuna >= 0) && (fColuna < 8))) && ((fLinha == iLinha - 2) && ((fLinha >= 0) && (fLinha < 8)))) && (tab[iColuna][iLinha] == 50 && tab[fColuna][fLinha] == 32))
                {

                    if ((tab[iColuna - 1][iLinha - 1] == 49) || (tab[iColuna - 1][iLinha - 1] == 51))
                    {
                        tab[iColuna - 1][iLinha - 1] = 32;
                    }
                    else
                    {
                        printf("Movimento invalido");
                        continue;
                    }

                    tab[iColuna][iLinha] = 32;
                    tab[fColuna][fLinha] = 50;

                    // VERIFICA SE AINDA EXISTE PEÇAS A SEREM CAPTURADAS
                    // VERIFICA PARA BAIXO E PARA DIREITA

                    if (((tab[fColuna + 1][fLinha + 1] == 49) || (tab[fColuna + 1][fLinha + 1] == 51)) && ((fLinha + 2 >= 0) && (fLinha + 2 < 8)) && ((fColuna + 2 >= 0) && (fColuna + 2 < 8)) && (tab[fColuna + 2][fLinha + 2] == 32))
                    {
                        system("CLS");
                        // IMPRESSãO DO TABULEIRO:
                        imprimeTab(tab);
                        printf("\nAinde existem pecas a serem capturadas e a captura e obrigatoria!");

                        pLinha = fLinha;
                        cColuna = fColuna;
                        continue;
                    }
                    // VERIFICA PARA CIMA E PARA DIREITA

                    if (((tab[fColuna + 1][fLinha - 1] == 49) || (tab[fColuna + 1][fLinha - 1] == 51)) && ((fLinha - 2 >= 0) && (fLinha - 2 < 8)) && ((fColuna + 2 >= 0) && (fColuna + 2 < 8)) && (tab[fColuna + 2][fLinha - 2] == 32))
                    {
                        system("CLS");
                        // IMPRESSãO DO TABULEIRO:
                        imprimeTab(tab);
                        printf("\nAinde existem pecas a serem capturadas e a captura e obrigatoria!");

                        pLinha = fLinha;
                        cColuna = fColuna;
                        continue;
                    }

                    // VERIFICA PARA ESQUERDA E PARA BAIXO

                    if (((tab[fColuna - 1][fLinha + 1] == 49) || (tab[fColuna - 1][fLinha + 1] == 51)) && ((fLinha + 2 >= 0) && (fLinha + 2 < 8)) && ((fColuna - 2 >= 0) && (fColuna - 2 < 8)) && (tab[fColuna - 2][fLinha + 2] == 32))
                    {
                        system("CLS");
                        // IMPRESSãO DO TABULEIRO:
                        imprimeTab(tab);
                        printf("\nAinde existem pecas a serem capturadas e a captura e obrigatoria!");

                        pLinha = fLinha;
                        cColuna = fColuna;
                        continue;
                    }

                    // VERIFICA PARA ESQUERDA E PARA CIMA

                    if (((tab[fColuna - 1][fLinha - 1] == 49) || (tab[fColuna - 1][fLinha - 1] == 51)) && ((fLinha - 2 >= 0) && (fLinha - 2 < 8)) && ((fColuna - 2 >= 0) && (fColuna - 2 < 8)) && (tab[fColuna - 2][fLinha - 2] == 32))
                    {
                        system("CLS");
                        // IMPRESSãO DO TABULEIRO:
                        imprimeTab(tab);
                        printf("\nAinde existem pecas a serem capturadas e a captura e obrigatoria!");

                        pLinha = fLinha;
                        cColuna = fColuna;
                        continue;
                    }

                    break;
                }

                // Movimento da peça
                if (pLinha == 10 && cColuna == 10)
                {
                    if ((((fColuna == iColuna + 1) || (fColuna == iColuna - 1)) && ((fColuna >= 0) && (fColuna < 8))) && ((fLinha == iLinha - 1) && ((fLinha >= 0) && (fLinha < 8))) && (tab[fColuna][fLinha] == 32 && tab[iColuna][iLinha] == 50))
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
        imprimeTab(tab);

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