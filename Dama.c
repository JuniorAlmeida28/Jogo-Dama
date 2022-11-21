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
    int fColuna;    // fColuna posição para onde a peça será movida.
    int fLinha;     // fLinha posição para onde a peça será movida.
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



    while(pretas != 0 && brancas != 0){

        while (1){
            
            printf("\n\nJogador 1 \n");
		    scanf("%d %d", &iColuna, &iLinha);
		    scanf("%d %d", &fColuna, &fLinha);


        // Movimento da peça
        if( ((((((fLinha == iLinha+1) || (fLinha == iLinha-1)) && (( fLinha >= 0 ) && (fLinha < 10))) &&  ((fColuna == iColuna+1) && (( fColuna >= 0 ) && (fColuna < 10)))) && tab[fLinha][fColuna]==46) && tab[iLinha][iColuna] == 49) )

		 {
		    tab[iLinha][iColuna] = 46;
            tab[fLinha][fColuna] = 49;
            break;
        }
        else
        {
          printf("movimento invalido");
          continue;
        }
        }
        system("CLS");

        //VERIFICA SE VIROU DAMA:
        for(iLinha=0;iLinha<10;iLinha++)
        {
		 	if(tab[iLinha][9]==49)
		 	{
				tab[iLinha][9]=51;
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
