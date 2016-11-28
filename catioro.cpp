#include<locale.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

#define VELOCIDADE 200

void andar(char *distancia){
	strcat(distancia,"  ");
}
void animar(){
	int i=0;
	char distancia[50];
	for(i=0;i<50;i++){
		distancia[i] = '\0';
	}
	i=0;
	while(i < 5){
		printf("%s               ;~~,__",distancia);
		printf("\n%s:-....,-------'`-'._.' ",distancia);
		printf("\n%s `-,,,  ,       ,'~~' ",distancia);
		printf("\n%s    ; ,'~.__; /",distancia);
		printf("\n%s     :|      :|",distancia);
		printf("\n%s    `-'     `-'",distancia);
		Sleep(VELOCIDADE);
		system("cls");
		andar(distancia);
		printf("%s              ;~~,__",distancia);
		printf("\n%s:-....,-------'`-'._.'",distancia);
		printf("\n%s`-,,,  ,       ,'~~'",distancia);
		printf("\n%s     ; ,'~.__; /--.",distancia);
		printf("\n%s     :| :|   :|``(;",distancia);
		printf("\n%s     `-'`-'  `-'",distancia);
		Sleep(VELOCIDADE);
		system("cls");
		andar(distancia);
		printf("%s              ;~~,__",distancia);
		printf("\n%s:-....,-------'`-'._.'",distancia);
		printf("\n%s`-,,,  ,       ,'~~'",distancia);
		printf("\n%s     ; ,'~.__; /--.",distancia);
		printf("\n%s     //'       ````(;",distancia);
		printf("\n%s    `-'",distancia);
		Sleep(VELOCIDADE);
		system("cls");
		andar(distancia);
		printf("%s            .--~~,__",distancia);
		printf("\n%s:-....,-------'`-'._.'",distancia);
		printf("\n%s`-,,,  ,_      ;'~U'",distancia);
		printf("\n%s_,-' ,'`-__; '--.",distancia);
		printf("\n%s(_/'~~      ''''(;",distancia);
		Sleep(VELOCIDADE);
		system("cls");
		andar(distancia);
		i = i+1;
	}
}

int main(){
	animar();
}




