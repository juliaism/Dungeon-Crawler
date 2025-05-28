#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>

// Declaração de variáveis
char numero, tecla;
char faseum, fasedois, fasetres;
int i, j, y = 8, x = 1; // Vila
int l, k, u = 8, t = 1; // Fase 1
int m, n, p_inicial = 8, o_inicial = 1, p, o; // Fase 2
int b, r, q_inicial = 8, z_inicial = 1, q, z; // Fase 3
char mapavila[10][10];
char mapaum[10][10];
char mapadois[20][20];
char mapatres[40][40];
int vidas = 3; // Contagem de vidas

// Posicao monstro 1 e teleportes
int inimigo_x = 17, inimigo_y = 8;
int tp1_q = 5, tp1_z = 7;
int tp2_q = 37, tp2_z = 35;
int v_q = 20, v_z = 20;
void menu();
void vila();

// Fases do jogo
void fase1();
void fase2();
void fase3();


// Reiniciar fases
void reiniciarFaseD() 
{
    p = p_inicial;
    o = o_inicial;
    inimigo_x = 17;
    inimigo_y = 8;
}

void reiniciarFaseT()
{
    q = q_inicial;
    z = z_inicial;
    v_q = 20;
    v_z = 20;
}

//Monstro  2
int podeMoverMonstro(int x, int y)
{
    return (mapatres[x][y] != '*' && mapatres[x][y] != '>' && mapatres[x][y] != '@' &&
            mapatres[x][y] != '#' && mapatres[x][y] != 'D' && mapatres[x][y] != '=' && mapatres[x][y] != 'O');
}

void moverMonstro()
{
    mapatres[v_q][v_z] = ' ';
    if (q > v_q && podeMoverMonstro(v_q + 1, v_z)) v_q++;
    else if (q < v_q && podeMoverMonstro(v_q - 1, v_z)) v_q--;
    else if (z > v_z && podeMoverMonstro(v_q, v_z + 1)) v_z++;
    else if (z < v_z && podeMoverMonstro(v_q, v_z - 1)) v_z--;
    mapatres[v_q][v_z] = 'V';
}

// Monstro 1
void moverInimigo()
{
    int direcao = rand() % 4;
    mapadois[inimigo_x][inimigo_y] = ' ';
    switch (direcao)
    {
        case 0: if (inimigo_x > 1) inimigo_x--; break;
        case 1: if (inimigo_x < 18) inimigo_x++; break;
        case 2: if (inimigo_y > 1) inimigo_y--; break;
        case 3: if (inimigo_y < 18) inimigo_y++; break;
    }
    mapadois[inimigo_x][inimigo_y] = 'X';
}

// Menu Principal
void menu()
{
    system("cls");
    printf("**********************************************************\n");
    printf("**********************************************************\n");
    printf("***                   DUNGEON CRAWLER                  ***\n");
    printf("**********************************************************\n");
    printf("**********************************************************\n\n");
    printf("1) Jogar\n");
    printf("2) Crédito\n");
    printf("3) Sair\n");
    printf("\nInsira a opção desejada --> ");
    scanf(" %c", &numero);

    switch (numero)
    {
        case '1': 
            vila(); // Agora chama a Vila antes da Fase 1
            break;
        case '2':
            system("cls");
            printf("\n=======================================================================\n");
            printf("==================   Feito por: Júlia Labad Jatene   ==================\n");
            printf("=======================================================================\n");
            printf("\n\nPressione qualquer tecla para voltar ao menu principal...\n\n");
            getch();
            menu(); // Retorna ao menu
            break;
        case '3':
            system("cls");
            printf("**********************************************************\n");
            printf("**********************************************************\n");
            printf("***                 OBRIGADA POR JOGAR                 ***\n");
            printf("**********************************************************\n");
            printf("**********************************************************\n\n");
            exit(0);
            break;
    }
}

// Função da Vila
void vila()
{
    system("cls");
    printf("**********************************************************\n");
    printf("**********************************************************\n");
    printf("***                 Bem-vindo à VILA                   ***\n");
    printf("**********************************************************\n");
    printf("**********************************************************\n");
    printf("\nPressione qualquer tecla para continuar...\n\n");
    getch();

    system("cls");

    // Inicializa o mapa da Vila
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            if (i == 0 || j == 0 || i == 9 || j == 9) {
                mapavila[i][j] = '*';
            } else {
                mapavila[i][j] = ' ';
            }
        }
    }

    // Adiciona objetos no mapa
    mapavila[1][1] = 'P';
    mapavila[1][5] = 'P';
    mapavila[5][9] = 'D';
    mapavila[8][8] = '@';

    y = 8;
    x = 1;
    mapavila[y][x] = '&'; // Posiciona o jogador

    while (1) {
        system("cls"); // Limpa a tela antes de redesenhar

        // Imprime o mapa atualizado
        for (i = 0; i < 10; i++) {
            for (j = 0; j < 10; j++) {
                printf("%c ", mapavila[i][j]);
            }
            printf("\n");
        }

        tecla = getch(); // Captura a entrada do jogador

        // Apaga a posição anterior do jogador
        mapavila[y][x] = ' ';

        // Movimentação
        if (tecla == 'w' && mapavila[y - 1][x] != '*' && mapavila[y - 1][x] != 'P') y--;
        if (tecla == 'a' && mapavila[y][x - 1] != '*' && mapavila[y][x - 1] != 'P') x--;
        if (tecla == 's' && mapavila[y + 1][x] != '*' && mapavila[y + 1][x] != '@') y++;
        if (tecla == 'd' && mapavila[y][x + 1] != '*' && mapavila[y][x + 1] != 'D' && mapavila[y][x + 1] != '@' && mapavila[y][x + 1] != 'P') x++;

        // Atualiza a posição do jogador no mapa
        mapavila[y][x] = '&';

        // Interações com NPCs e elementos
        if (tecla == 'i') {
            if ((x == 4 && y == 1) || (x == 6 && y == 1) || (x == 5 && y == 2)) {
                printf("NPC_2: Fuja dos monstros, desvie dos espinhos e colete as chaves para vencer!");
                Sleep(2500);
            }
            if ((x == 7 && y == 8) || (x == 8 && y == 7)) {
                mapavila[5][9] = '=';
            }
            if ((x == 1 && y == 2) || (x == 2 && y == 1)) {
                printf("NPC_1: Use as teclas 'A','W','S','D' para se movimentar e 'i' para interagir!");
                Sleep(2500);
            }
        }

        // Transição para Fase 1
        if (x == 9 && y == 5) {
            fase1(); // Agora chama a Fase 1 corretamente
        }
    }
}
// Fase 1 
void fase1()
{
    system("cls");
    printf("**********************************************************\n");
    printf("**********************************************************\n");
    printf("***                 Bem-vindo à FASE 1                 ***\n");
    printf("**********************************************************\n");
    printf("**********************************************************\n");
    printf("\n\nPressione qualquer tecla para continuar...\n\n");
   	    getch();

    // Código da fase 1...
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
    	system("cls");
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
        
        if (tecla == 'i')
		{
			if (u == 3 && t == 5)
				{
				mapaum[7][9] = '=';
				}
		}
		mapaum[u][t] = '&';

    if (u == 7 && t == 9)
	 {
        fase2(); // Agora chama Fase 2 corretamente
      }
	}
}

// Fase 2 (Mapadois)
void fase2()
{
    reiniciarFaseD();
    system("cls");
    printf("**********************************************************\n");
    printf("***                 Bem-vindo à FASE 2                 ***\n");
    printf("**********************************************************\n");
    printf("\nPressione qualquer tecla para continuar...\n\n");
    getch();
    system("cls");

    // Inicialização do mapa
    for (m = 0; m < 20; m++) {
        for (n = 0; n < 20; n++) {
            if (m == 0 || n == 0 || m == 19 || n == 19) {
                mapadois[m][n] = '*';
            } else {
                mapadois[m][n] = ' ';
            }
        }
    }

    // Posicionando objetos
    mapadois[18][15] = '*'; // Obstáculo
    mapadois[19][15] = 'D'; // Porta para a próxima fase
    mapadois[12][6] = '@';  // Chave especial
    mapadois[10][10] = '#'; // Espinho
    mapadois[15][5] = '#';  // Espinho
    mapadois[5][15] = '#';  // Espinho
    mapadois[7][8] = '#';   // Espinho
    mapadois[3][17] = 'O';  // Botão especial

    // Posicionando o jogador e inimigo
    p = p_inicial;
    o = o_inicial;
    mapadois[p][o] = '&';
    mapadois[inimigo_x][inimigo_y] = 'X';

    while (1) {
        system("cls"); // Limpa a tela antes de redesenhar

        // Imprime o mapa atualizado
        for (m = 0; m < 20; m++) {
            for (n = 0; n < 20; n++) {
                printf("%c ", mapadois[m][n]);
            }
            printf("\n");
        }

        // Captura a entrada do jogador
        tecla = getch();
        mapadois[p][o] = ' ';  // Apaga posição anterior

      if (mapadois[p][o] == '#') {
    vidas--;

    system("cls");
    printf("Você pisou nos espinhos! Vidas restantes: %d\n", vidas);
    getch();
    Sleep(1725);
    reiniciarFaseD();
    fase2();

    if (vidas <= 0) {
        system("cls");
        printf("**********************************************************\n");
        printf("***                    GAME OVER                       ***\n");
        printf("**********************************************************\n");
        printf("\nPressione qualquer tecla para voltar ao menu principal...\n");
        getch();
        vidas = 3; // Reinicia vidas para um novo jogo
        menu(); // Volta ao menu principal
    } else {
        reiniciarFaseD(); // Se ainda houver vidas, reinicia fase 2
    }
}


        // Movimentação do jogador
        if (tecla == 'w' && mapadois[p-1][o] != '*' && mapadois[p-1][o] != '@') p--;
        if (tecla == 'a' && mapadois[p][o-1] != '*' && mapadois[p][o-1] != '@') o--;
        if (tecla == 's' && mapadois[p+1][o] != '*' && mapadois[p+1][o] != 'D' && mapadois[p+1][o] != '@') p++;
        if (tecla == 'd' && mapadois[p][o+1] != '*' && mapadois[p][o+1] != '@') o++;

        // Atualiza posição do jogador no mapa
        mapadois[p][o] = '&';

        // ?? Verifica se o monstro pegou o jogador ANTES de permitir qualquer ação
if (p == inimigo_x && o == inimigo_y) {
    vidas--;

    system("cls");
    printf("O monstro te pegou! Vidas restantes: %d\n", vidas);
    getch();
    Sleep(1725);

    if (vidas <= 0) {
        system("cls");
        printf("**********************************************************\n");
        printf("***                    GAME OVER                       ***\n");
        printf("**********************************************************\n");
        printf("\nPressione qualquer tecla para voltar ao menu principal...\n");
        getch();
        vidas = 3; // Reinicia vidas para um novo jogo
        menu(); // Volta ao menu principal
    } else {
        reiniciarFaseD(); // Se ainda houver vidas, reinicia fase 2
    }
}

// ?? Move o monstro após verificar morte
moverInimigo();
        moverInimigo();

        // ?? Interação com a chave (@) para abrir a porta (=)
        if (tecla == 'i' && (p == 12 && o == 7 ||p == 12 && o == 8 || p == 11 && o == 6  || p == 13 && o == 6  )) {
            mapadois[19][15] = '='; // Porta aberta
        }

        // ?? Interação com o botão (O) para remover obstáculos
        if (p == 2 && o == 17) {
            mapadois[18][15] = ' '; 
           
        }

        // ?? Transição para fase 3 se o jogador alcançar a porta
        if (p == 19 && o == 15) {
            fase3(); // Agora chama Fase 3 corretamente
        }
    }
}




// Fase 3 (Mapatres)
void fase3()
{
    reiniciarFaseT();
    system("cls");
    printf("**********************************************************\n");
    printf("**********************************************************\n");
    printf("***                 Bem-vindo à FASE 3                 ***\n");
    printf("**********************************************************\n");
    printf("**********************************************************\n");
    printf("\n\nPressione qualquer tecla para continuar...\n\n");
   	    getch();

    // Código da fase 3...
    system("cls");

    for (b = 0; b < 40; b++) {
        for (r = 0; r < 40; r++) {
            if (b == 0 || r == 0 || b == 39 || r == 39) {
                mapatres[b][r] = '*';
            } else {
                mapatres[b][r] = ' ';
            }
        }
    }

    mapatres[38][2] = '*';
    mapatres[39][2] = 'D';
    mapatres[38][12] = '@';
    mapatres[8][19] = '#';
    mapatres[37][13] = '#';
    mapatres[7][25] = '#';
    mapatres[35][14] = '#';
    mapatres[14][28] = '#';
    mapatres[2][14] = '#';
    mapatres[25][26] = '#';
    mapatres[15][17] = '#';
    mapatres[10][20] = 'O';

    mapatres[tp1_q][tp1_z] = '>';
    mapatres[tp2_q][tp2_z] = '>';

    mapatres[q][z] = '&';
    mapatres[v_q][v_z] = 'V';

    while (1) 
    {
        system("cls");

        for (b = 0; b < 40; b++) {
            for (r = 0; r < 40; r++) {
                printf("%c ", mapatres[b][r]);
            }
            printf("\n");
        }

        tecla = getch();
        mapatres[q][z] = ' ';

        if (tecla == 'w' && mapatres[q-1][z] != '*' && mapatres[q-1][z] != '@' && mapatres[q-1][z] != 'D') q--;
        if (tecla == 'a' && mapatres[q][z-1] != '*' && mapatres[q][z-1] != '@' && mapatres[q][z-1] != 'D') z--;
        if (tecla == 's' && mapatres[q+1][z] != '*' && mapatres[q+1][z] != '@' && mapatres[q+1][z] != 'D') q++;
        if (tecla == 'd' && mapatres[q][z+1] != '*' && mapatres[q][z+1] != '@' && mapatres[q][z+1] != 'D') z++;

        
            if (q == tp1_q && z == tp1_z)
            {
                q = tp2_q;
                z = tp2_z;
            }
            else if (q == tp2_q && z == tp2_z)
            {
                q = tp1_q;
                z = tp1_z;
            }
        

        if (mapatres[q][z] == 'O') 
        {
            mapatres[38][2] = ' ';
        }

        if(tecla == 'i') 
        {
            if(q == 38 && z == 11 || q == 38 && z == 13 || q == 37 && z == 12)
            {
                mapatres[39][2] = '=';
            }
        }
        
        if (mapatres[q][z] == '#' || (q == v_q && z == v_z)) 
         {
         vidas--;
         system("cls");
         printf("Você perdeu uma vida! Vidas restantes: %d\n", vidas);
         getch(); // Pausa para o jogador ver a mensagem
         Sleep(1725);
         reiniciarFaseT(); // Reinicia a fase 3
         fase3(); // Chama a fase 3 novamente
         }
         
         
         if (q == 39 && z == 2)
		{
			system("cls");
			printf("**********************************************************\n");
	        printf("**********************************************************\n");
            printf("***                                                    ***\n");
	        printf("***                     VITÓRIA                        ***\n"); 
	        printf("***                   Bom Trabalho!                    ***\n");
	        printf("**********************************************************\n");
	        printf("**********************************************************\n\n");
	        printf("\n\nPressione qualquer tecla para voltar ao menu principal...\n\n");
   	        getch();
   	        menu();
   	        
		
		}	

    if (vidas <= 0)
    {
        system("cls");
        printf("**********************************************************\n");
        printf("**********************************************************\n");
        printf("***                    GAME OVER                       ***\n");
        printf("***           Jogue melhor na próxima vez!             ***\n");
        printf("**********************************************************\n");
        printf("**********************************************************\n");
        printf("\n\nPressione qualquer tecla para voltar ao menu principal...\n\n");
        getch();
        vidas = 3;
        menu();
    }
}
}

int main()
{
    setlocale(LC_ALL, "PORTUGUESE_BRAZIL");
    srand(time(NULL));
    menu(); 
    return 0;
}








 
