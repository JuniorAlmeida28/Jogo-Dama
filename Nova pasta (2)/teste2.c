//JOGO DE DAMAS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>


int main(void)
{
	int tab[10][10], i, j, aux=0, a,b,c,p,auxI,auxJ,pretas=1, brancas=1; //Tabuleiro 10X10, auxiliares

   // CRIAÇÃO E IMPRESSÃO DO TABULEIRO
   // UTILIZA UMA VARIÁVEL AUXILIAR PARA QUE AS PEÇAS SEJAM DISPOSTAS DE MANEIRA SIM/NAO/SIM
   // PARA ISSO É UTILIZADO SISTEMA DE PAR OU ÍMPAR
	for(j=0;j<4;j++)
	{
		if(j%2==0)
		{
			aux=1;
		}
		else
		{
			aux=0;
		}
		for(i=0;i<10;i++,aux++)
		{
			if(aux % 2 == 0)
			{
				tab[i][j] = 1;
			}
			else
			{
				tab[i][j] = 0;
			}}}
	for(j=4;j<6;j++)
	{
		for(i=0;i<10;i++)
		{
			tab[i][j]=0;
		}}

	for(j=6;j<10;j++)
	{
		if(j%2==0)
		{
			aux=1;
		}
		else
		{
			aux=0;
		}
		for(i=0;i<10;i++, aux++)
		{
			if(aux % 2 == 0)
			{
				tab[i][j] = 2;
			}
			else
			{
				tab[i][j] = 0;
			}}}
	//IMPRESSÃO DO TABULEIRO:
    printf("    0  1  2  3  4  5  6  7  8  9");
    printf("\n  _________________________________\n");
	for(j=0;j<10;j++)
	{
        printf("%d |", j);
		for(i=0;i<10;i++)
		{
			printf(" %d ", tab[i][j]);
			if(i == 9)
			{
                 	printf("  |%d \n", j);
             }
		}
		printf("  |                                |\n");
	}
	printf("  |________________________________|\n");
    printf("    0  1  2  3  4  5  6  7  8  9");

    while(pretas != 0 && brancas != 0)
	{   

	while(1)
	{
        printf("\n\nJogador 1 \n");
		scanf("%d %d", &j, &i);
		scanf("%d %d", &b, &a);

        if( (((((a == i+2) || (a == i-2)) && (( a >= 0 ) && (a < 10))) &&  (((b == j+2)) && (( b >= 0 ) && (b < 10))))  && tab[i][j] == 1) && tab[a][b] ==0 )
		{
		    if((tab[i-1][j-1] == 2) || (tab[i-1][j-1] == 4))
            {
            	tab[i-1][j-1] =0;
            }
            if((tab[i+1][j-1] == 2) || (tab[i+1][j-1] == 4))
            {
                 tab[i+1][j-1] = 0;
            }
            if((tab[i+1][j+1] == 2) || (tab[i+1][j+1] == 4))
            {
                 tab[i+1][j+1] = 0;
            }
            if((tab[i-1][j+1] == 2) || (tab[i-1][j+1] == 4))
            {
                 tab[i-1][j+1] = 0;
            }

            tab[i][j] = 0;
            tab[a][b] = 1;

            break;
      }

        //MOVIMENTO DA DAMA CORRIGIDO
		 if( ((((((a == i+1) || (a == i-1)) && (( a >= 0 ) && (a < 10))) &&  (((b == j+1)) && (( b >= 0 ) && (b < 10)))) && tab[a][b]==0) && tab[i][j] == 1) )
		{
		//  if ((((a == i+1) &&  ((b == j+1) || (b == j-1)) && tab[a][b]==0) && tab[i][j] == 1) )
		 //{
		    tab[i][j] = 0;
            tab[a][b] = 1;
            break;
      }
      else
      {
          printf("movimento invalido");
          continue;
      }
      }
        system("CLS");

        //IMPRESSÃO DO TABULEIRO:
    printf("    0  1  2  3  4  5  6  7  8  9");
    printf("\n  _________________________________\n");
	for(j=0;j<10;j++)
	{
        printf("%d |", j);
		for(i=0;i<10;i++)
		{
			printf(" %d ", tab[i][j]);
			if(i == 9)
			{
                 	printf("  |%d \n", j);
             }
		}
		printf("  |                                |\n");
	}
	printf("  |________________________________|\n");
    printf("    0  1  2  3  4  5  6  7  8  9");
    }

    

    return 0;
}