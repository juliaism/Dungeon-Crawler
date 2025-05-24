#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>


char numero;
char tecla;
int i, j;
int l,k;
char mapavila[10][10];
char mapaum[10][10];
char mapadois[20][20];
char mapatres[40][40];
int y = 8;
int x = 1;
int u = 8;
int t = 1;
char interagir;
int D;
char faseum;



int main()
{
   setlocale(LC_ALL, "PORTUGUESE_BRAZIL");
	
//MENU PRINCIPAL	    
menu:
system("cls");
printf("**********************************************************\n");
printf("**********************************************************\n");
printf("***                                                    ***\n");
printf("***                   DUNGEON CRAWLER                  ***\n"); 
printf("***                                                    ***\n");
printf("**********************************************************\n");
printf("**********************************************************\n\n");
printf("1) Jogar\n");
printf("2) Crédito\n");
printf("3) Sair\n");
printf("\nInsira a opção desejada --> ");
scanf("%c", &numero);
switch (numero)

 {
 	case '1':
	 {
    //VILA
	 	 	system("cls");
	printf("**********************************************************\n");
	printf("**********************************************************\n");
    printf("***                                                    ***\n");
	printf("***                 Bem-vindo à VILA                   ***\n"); 
	printf("***                                                    ***\n");
	printf("**********************************************************\n");
	printf("**********************************************************\n\n");
	printf("\n\nPressione qualquer tecla para continuar...\n\n");
   	    getch();
   	    
   	    system("cls");
   	     for (i = 0; i < 10; i++)
			{
             for(j = 0; j < 10; j++)
		     {
              if (i == 0 || j == 0 || i == 9 || j == 9)
			   {
                mapavila[i][j] = '*';
                mapavila[1][1] = 'P';
                mapavila[1][5] = 'P';
                mapavila[5][9] = 'D';
                mapavila[8][8] = '@';
               }
            
			  else 
			   {
                mapavila[i][j] = ' ';
               }
             }
            }

    mapavila[y][x] = '&';

    while (1)
    {
        for (i = 0; i < 10; i++)
		{
            for(j = 0; j < 10; j++)
			{
                printf("%c ", mapavila[i][j]);
            }
            printf("\n");
        }

        tecla = getch();

        mapavila[y][x] = ' ';
        if (tecla == 'w')
		{  
            if (mapavila[y-1][x] != '*' && mapavila[y-1][x] != 'P')
			{
                y--;
            }
        }

        if (tecla == 'a')
		{
            if (mapavila[y][x-1] != '*' && mapavila[y][x-1] != 'P')
			{
                x--;
            }
        }

        if (tecla == 's')
		{
            if (mapavila[y+1][x] != '*' && mapavila[y+1][x] != '@')
			{
                y++;
            }
        }

        if (tecla == 'd')
		{
			
            if (mapavila[y][x+1] != '*' && mapavila[y][x+1] != 'D' && mapavila[y][x+1] != '@' && mapavila[y][x+1] != 'P' )
			{
                x++;
            }
            
        }
	       if (tecla == 'i')
            {
           	if (x == 4 && y == 1 || x == 6 && y == 1 || x == 5 && y == 2)
                {
                printf("NPC_2:Fuja dos monstros, desvie dos espinhos e colete as chaves para vencer!");
                Sleep(2500);
				}
			if (x == 7 && y == 8 || x == 8 && y == 7)
				{
				mapavila[5][9] = '=';
				}
            if (x == 1 && y == 2 || x == 2 && y == 1)
                {
                printf("NPC_1:Use as teclas 'A','W','S','D' para se movinmentar e 'i' para interagir!");
                Sleep(2500);
				}
			}
	
		if (x == 9 && y == 5)
		{
			printf("Digite 'v' para avançar de fase --> ");
			Sleep(2500);
            scanf("%c", &faseum);
            switch (faseum)
            {
				case 'v':
				{
					goto mapaum;
					system("cls");
				}
				break;
					
			}
			
		}
		
      mapavila[y][x] = '&';
	  system("cls");         
	 }
	 
	 mapaum:
	system("cls");
   	     for (l= 0; l< 10; l++)
			{
        for(k = 0; k < 10; k++)
		{
            if (l== 0 || k == 0 || l== 9 || k == 9)
			{
                mapaum[l][k] = '*';
            }
            if (l== 0 || k == 0 || l== 9 || k == 9)
			{
                mapaum[7][9] = 'D';
            }
            if (l== 0 || k == 0 || l== 9 || k == 9)
			{
                mapaum[3][4] = '@';
            }
            if (l== 0 || k == 0 || l== 9 || k == 9)
			{
                mapaum[4][4] = '*';
            }
            if (l== 0 || k == 0 || l== 9 || k == 9)
			{
                mapaum[2][4] = '*';
            }
            if (l== 0 || k == 0 || l== 9 || k == 9)
			{
                mapaum[3][3] = '*';
            }
            if (l== 0 || k == 0 || l== 9 || k == 9)
			{
                mapaum[2][3] = '*';
            }
            if (l== 0 || k == 0 || l== 9 || k == 9)
			{
                mapaum[2][5] = '*';
            }
            if (l== 0 || k == 0 || l== 9 || k == 9)
			{
                mapaum[4][5] = '*';
            }
            if (l== 0 || k == 0 || l== 9 || k == 9)
			{
                mapaum[4][3] = '*';
            }
			 else 
			{
                mapaum[l][k] = ' ';
            }
        }
    }

    mapaum[u][t] = '&';

    while (1)
    {
        for (l= 0; l< 10; l++)
		{
            for(k = 0; k < 10; k++)
			{
                printf("%c ", mapaum[l][k]);
            }
            printf("\n");
        }

        tecla = getch();

        mapaum[u][t] = ' ';
        if (tecla == 'w')
		{  
            if (mapaum[u-1][t] != '*' )
			{
                u--;
            }
        }

        if (tecla == 'a')
		{
            if (mapaum[u][t-1] != '*' && mapaum[u][t-1] != '@')
			{
                t--;
            }
        }

        if (tecla == 's')
		{
            if (mapaum[u+1][t] != '*' )
			{
                u++;
            }
        }

        if (tecla == 'd')
		{
            if (mapaum[u][t+1] != '*' && mapaum[u][t+1] != 'D')
			{
                t++;
            }
        }
        
        if (tecla == i)
		{
			if (u == 5 && t == 4)
				{
				mapaum[7][9] = '=';
				}
		}
        
			

        mapaum[u][t] = '&';
        system("cls");
	 
	 }
	 break; 
 
	 case '2':
	 {
	 	system ("cls");
        printf("\n=======================================================================\n");
        printf("==================   Feito por: Júlia Labad Jatene   ==================\n");
        printf("=======================================================================\n");
        printf("\n\nPressione qualquer tecla para voltar ao menu principal...\n\n");
   	    getch();
   	    goto menu;
	 }
 	break;
 	
	 case '3':
	{
	system("cls");
	printf("**********************************************************\n");
	printf("**********************************************************\n");
	printf("***                                                    ***\n");
	printf("***                 OBRIGADA POR JOGAR                 ***\n"); 
	printf("***                                                    ***\n");
	printf("**********************************************************\n");
	printf("**********************************************************\n\n");
		exit (0);
	}
	
	
	
		
	

   }
   return 0;
  }
}
