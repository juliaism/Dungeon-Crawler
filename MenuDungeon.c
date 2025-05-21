#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <conio.h>


char numero;
char tecla;
int i, j;
char mapavila[10][10];
char mapaum[10][10];
char mapadois[20][20];
char mapatres[40][40];
int y = 8;
int x = 1;
char interagir;
int D;


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
            }
            if (i == 0 || j == 0 || i == 9 || j == 9)
			{
                mapavila[1][1] = 'P';
            }
            if (i == 0 || j == 0 || i == 9 || j == 9)
			{
                mapavila[5][9] = 'D';
            }
            if (i == 0 || j == 0 || i == 9 || j == 9)
			{
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
            if (mapavila[y+1][x] != '*' && mapavila[y+1][x] != '@' )
			{
                y++;
            }
        }

        if (tecla == 'd')
		{
            if (mapavila[y][x+1] != '*' && mapavila[y][x+1] != 'D' && mapavila[y][x+1] != '@')
			{
                x++;
            }
        }
        
		
		{
			if (tecla == 'i')
			{
				if (x == 7 && y == 6 || x == 6 && y == 7)
				{
				mapavila[5][9] = '=';
				}
			}
		}

        mapavila[y][x] = '&';
        system("cls");
        
    }
   	    
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
	
	case '4':
	{
		system("cls");
		 for (i = 0; i < 20; i++)
			{
              for(j = 0; j < 20; j++)
		       {
                 if (i == 0 || j == 0 || i == 19 || j == 19)
			      {
                  mapadois[i][j] = '*';
                  }
			     else 
			      {
                   mapadois[i][j] = ' ';
                  }
               }
            }

     mapadois[y][x] = '&';

      while (1)
     {
        for (i = 0; i < 20; i++)
		{
            for(j = 0; j < 20; j++)
			{
                printf("%c ", mapadois[i][j]);
            }
            printf("\n");
        }
        tecla = getch();

        mapadois[y][x] = ' ';
        if (tecla == 'w')
		{  
            if (mapadois[y-1][x] != '*' )
			{
                y--;
            }
        }

        if (tecla == 'a')
		{
            if (mapadois[y][x-1] != '*' )
			{
                x--;
            }
        }

        if (tecla == 's')
		{
            if (mapadois[y+1][x] != '*' )
			{
                y++;
            }
        }

        if (tecla == 'd')
		{
            if (mapadois[y][x+1] != '*' )
			{
                x++;
            }
        }
			

        mapadois[y][x] = '&';
        system("cls");
	 }
	

   }
     break;
     

  }
    return 0;
}
