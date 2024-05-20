#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <unistd.h>
#include <time.h>

void repeticao1 (int intervalo1,int intervalo2,char mapa1[][10]){
	for(intervalo1=0;intervalo1<10;intervalo1++){
		for(intervalo2=0;intervalo2<10;intervalo2++){
			printf(" %c",mapa1[intervalo1][intervalo2]);
		}
		printf("\n");
	}
}
void repeticao2 (int intervalo1,int intervalo2,char mapa1[][20]){
	for(intervalo1=0;intervalo1<20;intervalo1++){
		for(intervalo2=0;intervalo2<20;intervalo2++){
			printf(" %c",mapa1[intervalo1][intervalo2]);
		}
		printf("\n");
	}
}


int main(int argc, char *argv[]) {
	srand(time(NULL));
	
	int Escolha;
	int i;

    printf("BEM VINDO AO DUNGEON CRAWLER!\n");
    system("pause");
    system("cls");
    
    for(Escolha=0;Escolha!=3;Escolha){
    	
    	printf("              ,---------------------------,\n");
    	printf("              | /---------------------\ |\n");
    	printf("              | | | |\n");
    	printf("              | | 1- TUTORIAL  | |\n");
    	printf("              | | 2- INICIAR | |\n");
    	printf("              | | 3- SAIR   | |\n");
    	printf("              | | | |\n");
    	printf("              | \_____________________/ |\n");
    	printf("              |___________________________|\n");
    	printf("            ,---\_____ [] _______/------,\n");
    	printf("          / /______________\ /|\n");
    	printf("        /___________________________________ / | ___\n");
    	printf("        | | | )\n");
    	printf("        | _ _ _ [-------] | | (\n");
    	printf("        | ooo [-------] | / _)_\n");
    	printf("        |__________________________________ |/ / /\n");
    	printf("    /-------------------------------------/| ( )/\n");
    	printf("  //-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/ /\n");
    	printf("//-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/ /\n");
    	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

        scanf("%d",&Escolha);
        system("cls");
        
        if(Escolha==1){
        	printf("\n");
        	printf("&: Simbolo que representa o jogador.\n");
            printf("*: Simbolo que representa uma parede.\n");
            printf("@: Simbolo que representa a chave para abrir a porta para finalizar a fase.\n");
            printf("D: Simbolo que representa a porta fechada.\n");
            printf("=: Simbolo que representa a porta aberta.\n");
            printf("O: Simbolo que representa um botao interativo, o botao fica no chao e voce  deve ficar em cima dele para poder interagir.\n");
            printf("#: Simbolo que representa um espinho. Se voce tocar no espinho a fase e reiniciada, caso  seja reiniciada tres vezes, o jogo volta para o menu principal.\n");
            printf(">;: Simbolo que representa um teletransporte.\n");
            printf("X: Simbolo que representa o monstro nivel 1.\n");
            printf("V: Simbolo que representa o monstro nivel 2.\n\n"); 
            system("pause");
            system("cls");
		}
		else if(Escolha==2){
			printf("\n");
        	printf("BEM VINDO A FASE 1!\nSeu objetivo e pegar a chave para poder abrir a porta e passar de fase.\n Aperte a tecla I para poder pegar a chave e tambem para abrir a porta.\nAperte W A S D para se movimentar.\n\n");
        	system("pause");
        	system("cls");
			
			char mapa1[10][10] = {
		
		{'*','*','D','*','*','*','*','*','*','*'},
		{'*',' ',' ',' ',' ',' ',' ','*','@','*'},
		{'*',' ',' ',' ',' ',' ',' ','*',' ','*'},
		{'*',' ',' ',' ',' ',' ',' ',' ',' ','*'},
		{'*',' ',' ',' ',' ',' ',' ',' ',' ','*'},
		{'*',' ',' ',' ',' ',' ',' ',' ',' ','*'},
		{'*',' ',' ',' ',' ',' ',' ',' ',' ','*'},
		{'*',' ',' ',' ',' ',' ',' ',' ',' ','*'},
		{'*',' ',' ',' ',' ',' ',' ',' ',' ','*'},
		{'*','*','*','*','*','*','*','*','*','*'}
	};
	
	int intervalo1;
	int intervalo2;
	
	// posicao do jogador.
	int px = 2;
	int py = 2;
	
	// Y vertical e X horizontal.
	
	//    Y  X  eh. compliquei kaskakaksask
	mapa1[py][px] = '&';
	
	repeticao1(intervalo1,intervalo2,mapa1);
	
	char input;
	int chave=0;
	int Cmapa=0;
	int vid=3;
	
	while(1){
		input = getch();
		if(vid==0){
			system("cls");
			break;
		}
		if (input == 'w' || input == 'W'){
			if (mapa1[py-1][px] != '*' && mapa1[py-1][px] != 'D' && mapa1[py-1][px] != '@'){
				py--;
				mapa1[py][px]='&';
				mapa1[py+1][px]=' ';
			}
			system("cls");
			repeticao1(intervalo1,intervalo2,mapa1);
		}
		if (input == 's' || input == 'S'){
			if (mapa1[py+1][px] != '*' && mapa1[py+1][px] != 'D' && mapa1[py+1][px] != '@'){
				py++;
				mapa1[py][px]='&';
				mapa1[py-1][px]=' ';
			}
			system("cls");
			repeticao1(intervalo1,intervalo2,mapa1);
		}
		if (input == 'd' || input == 'D'){
			if (mapa1[py][px+1] != '*' && mapa1[py][px+1] != 'D' && mapa1[py][px+1] != '@'){
				px++;
				mapa1[py][px]='&';
				mapa1[py][px-1]=' ';
			}
			system("cls");
			repeticao1(intervalo1,intervalo2,mapa1);
		}
		if (input == 'a' || input == 'A'){
			if (mapa1[py][px-1] != '*' && mapa1[py][px-1] != 'D' && mapa1[py][px-1] != '@'){
				px--;
				mapa1[py][px]='&';
				mapa1[py][px+1]=' ';
			}
			system("cls");
			repeticao1(intervalo1,intervalo2,mapa1);
		}
		if (input == 'i' || input == 'I'){
			if (mapa1[py-1][px] == '@'){
				mapa1[py-1][px]=' ';
				chave=1;
				Cmapa=chave;
			}
			else if (mapa1[py+1][px] == '@'){
				mapa1[py+1][px]=' ';
				chave=1;
				Cmapa=chave;
			}
			else if (mapa1[py][px+1] == '@'){
				mapa1[py][px+1]=' ';
				chave=1;
				Cmapa=chave;
			}
			else if (mapa1[py][px-1] == '@'){
				mapa1[py][px-1]=' ';
				chave=1;
				Cmapa=chave;
			}
			else if (mapa1[py-1][px] == 'D' && chave==1 || mapa1[py+1][px] == 'D' && chave==1 || mapa1[py][px+1] == 'D' && chave==1 || mapa1[py][px-1] == 'D' && chave==1){
				if(mapa1[py-1][px] == 'D'){
					mapa1[py-1][px]='=';
					chave=0;
				}
				else if(mapa1[py+1][px] == 'D'){
					mapa1[py+1][px]='=';
					chave=0;
				}
				else if(mapa1[py][px+1] == 'D'){
					mapa1[py][px+1]='=';
					chave=0;
				}
				else if(mapa1[py][px-1] == 'D'){
					mapa1[py][px-1]='=';
					chave=0;
				}
			}
			system("cls");
			repeticao1(intervalo1,intervalo2,mapa1);
		}
		if (Cmapa==1){
		char novoM[10][10] = {
		
		{'*','*','D','*','*','*','*','*','*','*'},
		{'*','*',' ','*',' ',' ',' ','*',' ','*'},
		{'*',' ',' ','*',' ','*',' ','*',' ','*'},
		{'*',' ','*','*',' ','*',' ','*',' ','*'},
		{'*',' ',' ','*',' ','*',' ','*',' ','*'},
		{'*','*',' ','*',' ','*',' ','*',' ','*'},
		{'*',' ',' ','*',' ','*',' ','*',' ','*'},
		{'*',' ','*','*',' ','*',' ','*',' ','*'},
		{'*',' ',' ',' ',' ','*',' ',' ',' ','*'},
		{'*','*','*','*','*','*','*','*','*','*'}
	};
		for(intervalo1=0;intervalo1<10;intervalo1++){
			for(intervalo2=0;intervalo2<10;intervalo2++){
				mapa1[intervalo1][intervalo2]=novoM[intervalo1][intervalo2];
			}
		}
		Cmapa=0;
		}
		if (mapa1[0][2] == '&'){ //Tem como fazer essa parte mais otimizado, mas nao consegui, o plano era tentar fazer que quando o jogador tocasse no =, terminasse a fase, MAS
		//o codigo entende que se o jogador tocar em uma certa regiao do mapa, a fase finaliza, infelizmente, esse eh o jeito mais facil de fazer.
		system("cls");
		char mensagem[] = 
						"******----------*----------******----------*----------******----******----*-------*----******\n"
						"*----*---------*-*---------*----*---------*-*---------*----*----*---------*-*-----*----*\n"
						"*----*--------*---*--------******--------*---*--------*----*----*---------*--*----*----*\n"
						"******-------*-----*-------*-*----------*-----*-------******----******----*---*---*----******\n"
						"*-----------*********------*--*--------*********------******----*---------*----*--*---------*\n"
						"*----------*---------*-----*---*------*---------*-----*----*----*---------*-----*-*---------*\n"
						"*---------*-----------*----*----*----*-----------*----*----*----*---------*------**---------*\n"
						"*--------*-------------*---*-----*--*-------------*---******----******----*-------*----******\n"
						"VOCE CONCLUIU A PRIMEIRA FASE!";
						int i = 0;
						while(mensagem[i] != '\0'){
							putchar(mensagem[i]);
							Sleep(1);
							i++;
							
						}
		
			printf("\n");
			system("pause");
			system("cls");
			
			
			
			//A PARTIR DAQUI � TUDO FASE 2
			
			printf("BEM VINDO A FASE 2!\nNesta fase alem de pegar a chave voce tem que tomar cuidado com o monstro nivel 1 e os espinhos.\nA chave esta protegida mas um botao pode resolver seu problema.\nOBS:Lembre que voce so tem 3 vidas. \n");
			system("pause");
			system("cls");
			
			char mapa2ret[20][20] = {
		
		{'*','*','*','D','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'},
		{'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
		{'*',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ','*'},
		{'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
		{'*',' ','#',' ',' ','#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
		{'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ','*'},
		{'*',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ','*'},
		{'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
		{'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ','*'},
		{'*',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
		{'*',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
		{'*',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ','*'},
		{'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ','*'},
		{'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
		{'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},				
		{'*',' ',' ','#',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ','#','#','#','#','*'},		
		{'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ','#',' ',' ',' ','*'},
		{'*',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ','#',' ','@',' ','*'},
		{'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ','*'},
		{'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'},
		
	    };
			
			char mapa2[20][20] = {
		
		{'*','*','*','D','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'},
		{'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
		{'*',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ','*'},
		{'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
		{'*',' ','#',' ',' ','#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
		{'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ','*'},
		{'*',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ','*'},
		{'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
		{'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ','*'},
		{'*',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
		{'*',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
		{'*',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ','*'},
		{'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ','*'},
		{'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
		{'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},				
		{'*',' ',' ','#',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ','#','#','#','#','*'},		
		{'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ','#',' ',' ',' ','*'},
		{'*',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ','#',' ','@',' ','*'},
		{'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ','*'},
		{'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'},
		
	    };
	    
	    int px = 2;
	    int py = 2;
	    int mx = 13;
	    int my = 13;
	    int ox = 14;
	    int oy = 14;
	    
	    mapa2[py][px] = '&';
	    mapa2[my][mx] = 'X';
	    mapa2[oy][ox] = 'O';
	    
	    chave=0;
	    Cmapa=0;
		
		repeticao2(intervalo1,intervalo2, mapa2);
		
		while(1){
		
		input = getch();
		
		if (input == 'w' || input == 'W'){
			if(mapa2[py-1][px] == '#' || mapa2[py-1][px] == 'X'){
					
					mapa2[my][mx] = ' ';
					mapa2[py][px] = ' ';
					
					for(intervalo1=0;intervalo1<20;intervalo1++){
			for(intervalo2=0;intervalo2<20;intervalo2++){
				mapa2[intervalo1][intervalo2]=mapa2ret[intervalo1][intervalo2];
			}
		}
					chave=0;
					px=2;
					py=2;
					mx=13;
					my=13;
					ox=14;
					oy=14;
					
					mapa2[py][px] = '&';
					mapa2[my][mx] = 'X';
					mapa2[oy][ox] = 'O';
					
					vid--;
				}
			if (mapa2[py-1][px] != '*' && mapa2[py-1][px] != 'D' && mapa2[py-1][px] != '@' && mapa2[py-1][px] != '#' && mapa2[py-1][px] != 'X'){
				
				py--;
				mapa2[py][px]='&';
				mapa2[py+1][px]=' ';
				if (mapa2[py-1][px] =='X' || mapa2[py-1][px] =='#'){
					
				}
			
			}
			system("cls");
			repeticao2(intervalo1,intervalo2,mapa2);
		}
		if (input == 's' || input == 'S'){
			if(mapa2[py+1][px] == '#' || mapa2[py+1][px] == 'X'){
				
					mapa2[my][mx] = ' ';
					mapa2[py][px] = ' ';
					
					for(intervalo1=0;intervalo1<20;intervalo1++){
			for(intervalo2=0;intervalo2<20;intervalo2++){
				mapa2[intervalo1][intervalo2]=mapa2ret[intervalo1][intervalo2];
			}
		}
					chave=0;
					px=2;
					py=2;
					mx=13;
					my=13;
					ox=14;
					oy=14;
					
					mapa2[py][px] = '&';
					mapa2[my][mx] = 'X';
					mapa2[oy][ox] = 'O';
					
					vid--;
			}
			if (mapa2[py+1][px] != '*' && mapa2[py+1][px] != 'D' && mapa2[py+1][px] != '@' && mapa2[py+1][px] != '#' && mapa2[py+1][px] != 'X'){
				py++;
				mapa2[py][px]='&';
				mapa2[py-1][px]=' ';
				
			}
			system("cls");
			repeticao2(intervalo1,intervalo2,mapa2);
		}
		if (input == 'd' || input == 'D'){
			if(mapa2[py][px+1] == '#' || mapa2[py][px+1] == 'X'){
					
					mapa2[my][mx] = ' ';
					mapa2[py][px] = ' ';
					
					for(intervalo1=0;intervalo1<20;intervalo1++){
			for(intervalo2=0;intervalo2<20;intervalo2++){
				mapa2[intervalo1][intervalo2]=mapa2ret[intervalo1][intervalo2];
			}
		}
					chave=0;
					px=2;
					py=2;
					mx=13;
					my=13;
					ox=14;
					oy=14;
					
					mapa2[py][px] = '&';
					mapa2[my][mx] = 'X';
					mapa2[oy][ox] = 'O';
					
					vid--;
			}
			if (mapa2[py][px+1] != '*' && mapa2[py][px+1] != 'D' && mapa2[py][px+1] != '@' && mapa2[py][px+1] != '#' && mapa2[py][px+1] != 'X'){
				px++;
				mapa2[py][px]='&';
				mapa2[py][px-1]=' ';
			}
			system("cls");
			repeticao2(intervalo1,intervalo2,mapa2);
		}
		if (input == 'a' || input == 'A'){
			if(mapa2[py][px-1] == '#' || mapa2[py][px-1] == 'X'){
				
					mapa2[my][mx] = ' ';
					mapa2[py][px] = ' ';
					
					for(intervalo1=0;intervalo1<20;intervalo1++){
			for(intervalo2=0;intervalo2<20;intervalo2++){
				mapa2[intervalo1][intervalo2]=mapa2ret[intervalo1][intervalo2];
			}
		}
					chave=0;
					px=2;
					py=2;
					mx=13;
					my=13;
					ox=14;
					oy=14;
					
					mapa2[py][px] = '&';
					mapa2[my][mx] = 'X';
					mapa2[oy][ox] = 'O';
					
					vid--;
			}
			if (mapa2[py][px-1] != '*' && mapa2[py][px-1] != 'D' && mapa2[py][px-1] != '@' && mapa2[py][px-1] != '#' && mapa2[py][px-1] != 'X'){
				px--;
				mapa2[py][px]='&';
				mapa2[py][px+1]=' ';
				
				
			}
			system("cls");
			repeticao2(intervalo1,intervalo2,mapa2);
			
		}
		if (input == 'i' || input == 'I'){
			if (mapa2[py-1][px] == '@'){
				mapa2[py-1][px]=' ';
				chave=1;
				Cmapa=chave;
			}
			else if (mapa2[py+1][px] == '@'){
				mapa2[py+1][px]=' ';
				chave=1;
				Cmapa=chave;
			}
			else if (mapa2[py][px+1] == '@'){
				mapa2[py][px+1]=' ';
				chave=1;
				Cmapa=chave;
			}
			else if (mapa2[py][px-1] == '@'){
				mapa2[py][px-1]=' ';
				chave=1;
				Cmapa=chave;
			}
			else if (mapa2[py-1][px] == 'D' && chave==1 || mapa2[py+1][px] == 'D' && chave==1 || mapa2[py][px+1] == 'D' && chave==1 || mapa2[py][px-1] == 'D' && chave==1){
				if(mapa2[py-1][px] == 'D'){
					mapa2[py-1][px]='=';
					chave=0;
				}
				else if(mapa2[py+1][px] == 'D'){
					mapa2[py+1][px]='=';
					chave=0;
				}
				else if(mapa2[py][px+1] == 'D'){
					mapa2[py][px+1]='=';
					chave=0;
				}
				else if(mapa2[py][px-1] == 'D'){
					mapa2[py][px-1]='=';
					chave=0;
					
				}
			}
			system("cls");
			repeticao2(intervalo1,intervalo2,mapa2);
		}
		if(mapa2[oy][ox] == '&'){
			mapa2[oy][ox] = ' ';
			mapa2[18][15] = ' ';
			mapa2[17][15] = ' ';
			mapa2[16][15] = ' ';
			mapa2[15][15] = ' ';
			mapa2[15][16] = ' ';
			mapa2[15][17] = ' ';
			mapa2[15][18] = ' ';	
		}
		
		
		if (input == 'w' || input == 'W' || input == 's' || input == 'S' || input == 'd' || input == 'D' || input == 'a' || input == 'A' || input == 'i' || input == 'I'){
			srand(time(0));
			
			if(((rand() % 4) + 1) == 1 && mapa2[my-1][mx] != '*' && mapa2[my-1][mx] != 'D' && mapa2[my-1][mx] != '@' && mapa2[my-1][mx] != '#' && mapa2[my-1][mx] != '&' && mapa2[my-1][mx] != 'O'){
				if(mapa2[my-1][mx] == '&'){
									
					mapa2[my][mx] = ' ';
					mapa2[py][px] = ' ';
					
					for(intervalo1=0;intervalo1<20;intervalo1++){
			for(intervalo2=0;intervalo2<20;intervalo2++){
				mapa2[intervalo1][intervalo2]=mapa2ret[intervalo1][intervalo2];
			}
		}
					chave=0;
					px=2;
					py=2;
					mx=13;
					my=13;
					ox=14;
					oy=14;
					
					mapa2[py][px] = '&';
					mapa2[my][mx] = 'X';
					mapa2[oy][ox] = 'O';
					
					vid--;
				}
				my--;
				mapa2[my][mx]='X';
				mapa2[my+1][mx]=' ';
			}
			
			else if(((rand() % 4) + 1) == 2 && mapa2[my+1][mx] != '*' && mapa2[my+1][mx] != 'D' && mapa2[my+1][mx] != '@' && mapa2[my+1][mx] != '#' && mapa2[my+1][mx] != '&' && mapa2[my+1][mx] != 'O'){
				if(mapa2[my+1][mx] == '&'){
									
					mapa2[my][mx] = ' ';
					mapa2[py][px] = ' ';
					
					for(intervalo1=0;intervalo1<20;intervalo1++){
			for(intervalo2=0;intervalo2<20;intervalo2++){
				mapa2[intervalo1][intervalo2]=mapa2ret[intervalo1][intervalo2];
			}
		}
					chave=0;
					px=2;
					py=2;
					mx=13;
					my=13;
					ox=14;
					oy=14;
					
					mapa2[py][px] = '&';
					mapa2[my][mx] = 'X';
					mapa2[oy][ox] = 'O';
					
					vid--;
				}
				my++;
				mapa2[my][mx]='X';
				mapa2[my-1][mx]=' ';
			}
			
			else if(((rand() % 4) + 1) == 3 && mapa2[my][mx+1] != '*' && mapa2[my][mx+1] != 'D' && mapa2[my][mx+1] != '@' && mapa2[my][mx+1] != '#' && mapa2[my][mx+1] != '&' && mapa2[my][mx+1] != 'O'){
				if(mapa2[my][mx+1] == '&'){
									
					mapa2[my][mx] = ' ';
					mapa2[py][px] = ' ';
					
					for(intervalo1=0;intervalo1<20;intervalo1++){
			for(intervalo2=0;intervalo2<20;intervalo2++){
				mapa2[intervalo1][intervalo2]=mapa2ret[intervalo1][intervalo2];
			}
		}
					chave=0;
					px=2;
					py=2;
					mx=13;
					my=13;
					ox=14;
					oy=14;
					
					mapa2[py][px] = '&';
					mapa2[my][mx] = 'X';
					mapa2[oy][ox] = 'O';
					
					vid--;
				}
				mx++;
				mapa2[my][mx]='X';
				mapa2[my][mx-1]=' ';
			}
			
			else if(((rand() % 4) + 1) == 4 && mapa2[my][mx-1] != '*' && mapa2[my][mx-1] != 'D' && mapa2[my][mx-1] != '@' && mapa2[my][mx-1] != '#' && mapa2[my][mx-1] != '&' && mapa2[my][mx-1] != 'O'){
				if(mapa2[my][mx-1] == '&'){
									
					mapa2[my][mx] = ' ';
					mapa2[py][px] = ' ';
					
					for(intervalo1=0;intervalo1<20;intervalo1++){
			for(intervalo2=0;intervalo2<20;intervalo2++){
				mapa2[intervalo1][intervalo2]=mapa2ret[intervalo1][intervalo2];
			}
		}
					chave=0;
					px=2;
					py=2;
					mx=13;
					my=13;
					ox=14;
					oy=14;
					
					mapa2[py][px] = '&';
					mapa2[my][mx] = 'X';
					mapa2[oy][ox] = 'O';
					
					vid--;
				}
				mx--;
				mapa2[my][mx]='X';
				mapa2[my][mx+1]=' ';
			}

		}
		
		
		if (vid==0){
			system("cls");
			printf(" _________    _____   ____     _______  __ ___________\n");
            printf(" / ___\\__  \\  /     \\_/ __ \\   /  _ \\  \\/ // __ \\_  __ \\\n");
            printf("/ /_/  > __ \\|  Y Y  \\  ___/  (  <_> )   /\\  ___/|  | \\/\n");
            printf("\\___  (____  /__|_|  /\\___  >  \\____/ \\_/  \\___  >__|   \n");
            printf("/_____/     \\/      \\/     \\/                   \\/       \n");
			                   
			printf("\n");
			printf("Aperte uma tecla para voltar ao menu.");
			break;
		}
		if (mapa2[0][3] == '&'){
			system("cls");
				char mensagem[] = 
						"******----------*----------******----------*----------******----******----*-------*----******\n"
						"*----*---------*-*---------*----*---------*-*---------*----*----*---------*-*-----*----*\n"
						"*----*--------*---*--------******--------*---*--------*----*----*---------*--*----*----*\n"
						"******-------*-----*-------*-*----------*-----*-------******----******----*---*---*----******\n"
						"*-----------*********------*--*--------*********------******----*---------*----*--*---------*\n"
						"*----------*---------*-----*---*------*---------*-----*----*----*---------*-----*-*---------*\n"
						"*---------*-----------*----*----*----*-----------*----*----*----*---------*------**---------*\n"
						"*--------*-------------*---*-----*--*-------------*---******----******----*-------*----******\n";
						
						int i = 0;
						while(mensagem[i] != '\0'){
							putchar(mensagem[i]);
							Sleep(1);
							i++;
							
						}
			
			printf("VOCE CONCLUIU A SEGUNDA FASE!\n");
			printf("Voce recuperou toda sua vida.\n");
			vid=3;
			printf("\n");
			system("pause");
			
			return 0; //basta tirar para come�ar a criar a terceira fase.
			//while(1)
		}
		

		
		
	}
		
	}
    	
	}
			
		}
		else if(Escolha == 3){
			
			printf("\n");
			printf("Ate mais! :)");
            return 0;
            
		}else{
			
			printf("Por favor, evite de digitar outra coisa. Reinicie o jogo.\n\n");
            return 0;
			
		}
		         
    	
    
	
	
	//perto do final ksk
	
}
return 0;
}
