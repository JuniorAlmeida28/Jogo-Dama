#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    char tab[8][8]; // Tabuleiro 8X8.
    int iColuna;    // Posição inicial.
    int iLinha;     // Posição inicial.
    int aux = 0;    // Auxiliar de posição.
    int fLinha;     // fLinha posição para onde a peça será movida.
    int fColuna;    // fColuna posição para onde a peça será movida.
    int c;
    int p;
    int auxI;
    int auxJ;
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
        for (iColuna = 0; iColuna < 8; iColuna++, aux++)
        {
            if (aux % 2 == 0)
            {
                tab[iColuna][iLinha] = 49;
            }
            else
            {
                tab[iColuna][iLinha] = 46;
            }
        }
    }
    for (iLinha = 3; iLinha < 5; iLinha++)
    {
        for (iColuna = 0; iColuna < 8; iColuna++)
        {
            tab[iColuna][iLinha] = 46;
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
        for (iColuna = 0; iColuna < 8; iColuna++, aux++)
        {
            if (aux % 2 == 0)
            {
                tab[iColuna][iLinha] = 50;
            }
            else
            {
                tab[iColuna][iLinha] = 46;
            }
        }
    }
    // IMPRESSãO DO TABULEIRO:
    printf("    0  1  2  3  4  5  6  7");
    printf("\n  _________________________\n");
    for (iLinha = 0; iLinha < 8; iLinha++)
    {
        printf("%d |", iLinha);
        for (iColuna = 0; iColuna < 8; iColuna++)
        {
            printf(" %c ", tab[iColuna][iLinha]);
            if (iColuna == 7)
            {
                printf("|%d \n", iLinha);
            }
        }
        printf("  |                        |\n");
    }
    printf("  |________________________|\n");
    printf("    0  1  2  3  4  5  6  7");

    while (pretas != 0 && brancas != 0)
    {

        while (1)
        {

            printf("\n\nJogador 1 \n");
            scanf("%d %d", &iLinha, &iColuna);
            scanf("%d %d", &fLinha, &fColuna);

            // Captura para direita
            if (((((fColuna == iColuna + 2) && ((fColuna >= 0) && (fColuna < 10))) && ((fLinha == iLinha + 2) && ((fLinha >= 0) && (fLinha < 10)))) && tab[iColuna][iLinha] == 49) && tab[fColuna][fLinha] == 46)
            {
                if ((tab[iColuna + 1][iLinha + 1] == 50) || (tab[iColuna + 1][iLinha + 1] == 52))
                {
                    tab[iColuna + 1][iLinha + 1] = 46;
                }
                else
            {
                printf("movimento invalido");
                continue;
            }

                tab[iColuna][iLinha] = 46;
                tab[fColuna][fLinha] = 49;

                break;
            }
            // Captura para esqueda
            if (((((fColuna == iColuna - 2) && ((fColuna >= 0) && (fColuna < 10))) && ((fLinha == iLinha + 2) && ((fLinha >= 0) && (fLinha < 10)))) && tab[iColuna][iLinha] == 1) && tab[fColuna][fLinha] == 0)
            {

                if ((tab[iColuna - 1][iLinha + 1] == 2) || (tab[iColuna - 1][iLinha + 1] == 4))
                {
                    tab[iColuna - 1][iLinha + 1] = 0;
                }
                else
            {
                printf("movimento invalido");
                continue;
            }

                tab[iColuna][iLinha] = 0;
                tab[fColuna][fLinha] = 1;

                break;
                
            }else
            


            // Movimento da peça

            if (((((((fColuna == iColuna + 1) || (fColuna == iColuna - 1)) && ((fColuna >= 0) && (fColuna < 10))) && (((fLinha == iLinha + 1)) && ((fLinha >= 0) && (fLinha < 10)))) && tab[fColuna][fLinha] == 46) && tab[iColuna][iLinha] == 49))
            {
                tab[iColuna][iLinha] = 46;
                tab[fColuna][fLinha] = 49;
                break;
            }
            else
            {
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
        printf("    0  1  2  3  4  5  6  7");
        printf("\n  _________________________\n");
        for (iLinha = 0; iLinha < 8; iLinha++)
        {
            printf("%d |", iLinha);
            for (iColuna = 0; iColuna < 8; iColuna++)
            {
                printf(" %c ", tab[iColuna][iLinha]);
                if (iColuna == 7)
                {
                    printf("|%d \n", iLinha);
                }
            }
            printf("  |                        |\n");
        }
        printf("  |________________________|\n");
        printf("    0  1  2  3  4  5  6  7");

    
    }

    getch();
    return 0;
}
