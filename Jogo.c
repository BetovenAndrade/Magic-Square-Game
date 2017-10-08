/*
	Autor: Professor e turma do 2º Noturno/Diurno
	Objetivo: Jogo no qual a soma das linhas, colunas e diagonais devem expressar o mesmo valor
				As entradas devem ser números de 1 a 9

*/
#include <stdio.h>
#include <conio.h>
#include <conio.c>

//contantes de cursors para vomimentar-se na matriz
#define UP 119
#define DOWN 120 
#define LEFT 97
#define RIGTH 100

//auxiliares para cursor em linha e coluna
int lCursor=1;
int cCursor=1;

int matriz[3][3];
	//Funcoes
	void matrizLimpa();
	int atribuida();
	void cabecalho(int op);
	void redesenhe(int l, int c, int n);
	void cursor();

int main(){
		
	int l, c, lDes, cDes, nDes;	
		
	//for duplo para zerar a matriz 
	for(l=0; l<3; ++l){
		for(c=0; c<3; ++c){
			matriz[l][c]=0;
		}	
	}
	
	cabecalho(1);
	matrizLimpa();
	//inicia cursor em [1][1]
	gotoxy(6, 9);
	while(atribuida()==0){
		cursor();
		//printf("\nDigite os indices desejados: ");
		//scanf("%d %d", &lDes, &cDes);
		//printf("\nDigite o numero desejado: ");
		scanf("%d", &nDes);
		cursor();
		//matriz[lDes-1][cDes-1]= nDes;
		//redesenhe((lDes-1),(cDes-1),(nDes));
	}
	
	
	system("cls");
	
	getch();
	return 0;
}

void matrizLimpa(){
	
	//for duplo para impressao de uma matriz em branco
	int l, c;
	printf("     1    2    3");
	for(l=0; l<3; ++l){
		printf("\n %d", l+1);
		for(c=0; c<3; ++c){
			printf("  [ ]");
		}
	}
	printf("\nUtilize W X A D e digite o VALOR\n");
}

//funcao para averiguar se digitou numeros repetidos

//funcao para averiguar se preencheu toda a matriz, ou seja, nao existe zeros

int atribuida(){ //1 se totalmente atribuida, 0 se falso
	int result=1; int l, c;
	for(l=0; l<3; ++l){
		for(c=0; c<3; ++c){
			if(matriz[l][c]==0){
				result=0; return result;
			}
		}
	}
	return result;
}

void redesenhe(int l, int c, int n){
	system("cls");
	cabecalho(1);
	int l2, c2;
	matriz[l][c]= n;
	printf("     1    2    3");
	for(l2=0; l2<3; ++l2){
		printf("\n %d", l2+1);
		for(c2=0; c2<3; ++c2){
			if(matriz[l2][c2]!=0){
				printf("  [");	
				printf("%c[%d;%d;%dm%d%c[m", 0x1B,1,31,40,matriz[l2][c2],0x1B);
				printf("]");
				//printf("  [%d]", matriz[l2][c2]);	
			}else
			{
				printf("  [ ]");
			}
			
		}
	}
}

void cabecalho(int op){
	char vetor[]={45,218,205,205,205,205,191,45,45,218,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,191,'*',45,179,178,255,178,255,179,45,45,179,250,250,67,111,109,112,117,116,101,114,32,83,99,105,101,110,99,101,45,85,69,80,66,45,66,114,97,122,105,108,250,250,179,'*',192,179,218,205,205,191,179,217,45,192,203,191, 250,250,250,250,250,84,101,97,99,104,101,114,58,32,66,101,116,111,118,101,110,250,250,250,250,250,250,250,250,250,179,'*',45,179,192,205,205,217,179,205,205,205,217,192,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,217,'*',45,192,203,205,205,203,217,45,45,45};
	if(op==1)
		system("cls");
	
	int i; printf("\n");
	for(i=0; i<186; i++){
		if(vetor[i]=='*')
			printf("\n");
		else{
			printf("%c[%d;%d;%dm%c%c[m", 0x1B,1,32,40,vetor[i],0x1B);
		}
			//printf("%c", vetor[i]);
	}
	printf("\n\n");
	
}

void cursor(){
	int t= getch(); 
	
	while(t!=UP && t!=DOWN && t!=LEFT && t!=RIGTH)
		t= getch();	
			
	switch(t){
		case UP:
			lCursor--; if(lCursor==-1)lCursor=3;
			break;
		case DOWN:
			lCursor++; if(lCursor==4)lCursor=1;
			break;
		case LEFT:
			cCursor--; if(cCursor==-1)cCursor=3;
			break;
		case RIGTH:
			cCursor++; if(cCursor==4)cCursor=1;
			break;
	}
	
	int x, y;	
	if(lCursor==1)
		y=9;
	if(lCursor==2)
		y=10;
	if(lCursor==3)
		y=11;
	if(cCursor==1)
		x=6;
	if(cCursor==2)
		x=11;
	if(cCursor==3)
		x=16;	
	
		gotoxy(x, y);
}

/*
[06 09] [11 09] [16 09]
[06 10] [11 10] [16 10]
[06 11] [11 11] [16 11]*/
