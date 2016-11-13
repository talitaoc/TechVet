#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<windows.h>
#include<locale.h>

#define ESC 27

int main(){
	
	setlocale(LC_ALL,"Portuguese");
	int menu1=1,menu2,menu3;
	
	while(menu1!=ESC){
		printf("\n\t*************************************************************");
		printf("\n\t*                 #  MENU PRINCIPAL  #                      *");
		printf("\n\t*                                                           *");
		printf("\n\t*                                                           *");
		printf("\n\t*        # DIGITE O NÚMERO DA OPÇÃO DESEJADA:               *");
		printf("\n\t*                                                           *");
		printf("\n\t*            1 - PRODUTOS E SERVIÇOS ;                      *");
		printf("\n\t*            2 - ÁREA DE CLIENTES;                          *");
		printf("\n\t*          ESC - SAIR DO PROGRAMA.                          *");
		printf("\n\t*                                                           *");                                                       
		printf("\n\t*                                                           *");
		printf("\n\t*************************************************************");
		printf("\n\n");
		menu1 = getch(); 
		fflush(stdin);
		printf("\n");
		system("cls");
		
		switch(menu1){
			case '1' :
				do{
					printf("\n\t*************************************************************");
					printf("\n\t*                  #  MENU DE CLIENTE  #                    *");
					printf("\n\t*                                                           *");
					printf("\n\t*                                                           *");
					printf("\n\t*           # DIGITE O NÚMERO DA OPÇÃO DESEJADA:            *");
					printf("\n\t*                                                           *");
					printf("\n\t*            1 - CADASTRAR UM NOVO CLIENTE;                 *");
					printf("\n\t*            2 - LISTAR TODOS OS CLIENTES CADASTRADOS;      *");
					printf("\n\t*            3 - CONSULTAR CLIENTE CADASTRADO;              *");
					printf("\n\t*            4 - EXCLUIR CLIENTE CADASTRADO;                *");
					printf("\n\t*          ESC - VOLTAR AO MENU PRINCIPAL.                  *");
					printf("\n\t*                                                           *");
					printf("\n\t*                                                           *");
					printf("\n\t*************************************************************");
					printf("\n\n");
					menu2 = getch();
					fflush(stdin);
					system("cls");
					
					switch(menu2){
						case '1' :
							printf("CADASTRAR UM NOVO CLIENTE\n\n");
							break;
						case '2' :
							printf("LISTAR TODOS OS CLIENTES CADASTRADOS\n\n");
							break;
						case '3' :
							printf("CONSULTAR CLIENTE CADASTRADO\n\n");
							break;
						case '4' : 
							printf("EXCLUIR CLIENTE CADASTRADO\n\n");
							break;
						default:
							break;	
					}
					if(menu2!=ESC){
						getch();
						system("cls");
					}
				}while(menu2!=ESC);
				break;
			case '2' :
				do{
					printf("\n\t*************************************************************");
					printf("\n\t*                 # PRODUTOS E SERVIÇOS  #                  *");
					printf("\n\t*                                                           *");
					printf("\n\t*                                                           *");
					printf("\n\t*           # DIGITE O NUMERO DA OPCAO DESEJADA:            *");
					printf("\n\t*                                                           *");
					printf("\n\t*            1 - CADASTRAR PRODUTOS PARA VENDA ;            *");
					printf("\n\t*            2 - VENDA DE PRODUTOS E SERVIÇOS ;             *");
					printf("\n\t*            3 - LISTAR TODOS OS PRODUTOS CADASTRADOS ;     *");
					printf("\n\t*            4 - CONSULTAR PRODUTOS CADASTRADOS NO SISTEMA; *");
					printf("\n\t*            5 - REMOVER PRODUTOS CADASTRADOS ;             *");
					printf("\n\t*           ESC - VOLTAR AO MENU PRINCIPAL ;                *");
					printf("\n\t*                                                           *");
					printf("\n\t*                                                           *");
					printf("\n\t*************************************************************");
					printf("\n\n");
					menu3 = getch();
					fflush(stdin);
					system("cls");
					
					switch(menu3){
						case '1' :
							printf("CADASTRAR PRODUTOS PARA VENDA\n\n");
							break;
						case '2' :
							printf("VENDA DE PRODUTOS E SERVIÇOS\n\n");
							break;
						case '3' :
							printf("LISTAR TODOS OS PRODUTOS CADASTRADOS\n\n");
							break;
						case '4' :
							printf("CONSULTAR PRODUTOS CADASTRADOS NO SISTEMA\n\n");
							break;
						case '5' :
							printf("REMOVER PRODUTOS CADASTRADOS\n\n");
							break;
						default:
							break;	
					}
					if(menu2!=ESC){
						getch();
						system("cls");
					}
				}while(menu3!=ESC);
				break;
			default:
				break;
		}	
	}
}
