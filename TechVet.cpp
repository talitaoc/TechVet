#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<windows.h>
#include<locale.h>
#include "jsmn.h"

#define ESC 27

void salvar(struct cliente* cliente);
void leitura();
void lerCliente(char[],struct cliente*);

struct endereco{
	char rua[30], complemento[20], bairro[20], cidade[20], estado[20], cep[20];
	int numero;
};
struct animal{
	char nome[20], raca[20], sexo[1];
	int idade;
};
struct nascimento{
	int dia, mes, ano;
};
struct telefone{
	int ddd, numero, tipo;
};
struct cliente{
	char codigoCliente[10], nome[20], email[20], sexo;
	long long int cpf;
	struct nascimento data;
	struct animal pet;
	struct telefone contato;
	struct endereco endereco;
};

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
							salvar(NULL);
							break;
						case '2' :
							printf("LISTAR TODOS OS CLIENTES CADASTRADOS\n\n");
							leitura();
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
	return 0;
}

void salvar(struct cliente* cliente){ //FILE é um tipo, uma struct.
	FILE *arquivo = fopen("techvet.bd","w"); //fopen cria um arquivo e devolve o endereço de memória de onde está o arquivo. Tem que ser o tipo ponteiro por devolver um endereço.
	char auxiliar[1024];
	strcpy(auxiliar,"{\"codigoCliente\":");
	strcat(auxiliar,"1");
	strcat(auxiliar,",\"nome\":");
	strcat(auxiliar,"\"Talita Orlando\"");
	strcat(auxiliar,",\"email\":");
	strcat(auxiliar,"\"talitaoc@gmail.com\"");
	strcat(auxiliar,",\"sexo\":");
	strcat(auxiliar,"\"f\"");
	strcat(auxiliar,",\"cpf\":");
	strcat(auxiliar,"36852346846");
	strcat(auxiliar,",\"nascimento\":");
	strcat(auxiliar,"{\"dia\":");
	strcat(auxiliar,"08");
	strcat(auxiliar,",\"mes\":");
	strcat(auxiliar,"03");
	strcat(auxiliar,",\"ano\":");
	strcat(auxiliar,"1988");
	strcat(auxiliar,"}");
	strcat(auxiliar,",\"animal\":[");
	strcat(auxiliar,"{\"nome\":");
	strcat(auxiliar,"\"lince\"");
	strcat(auxiliar,",\"raca\":");
	strcat(auxiliar,"\"SRD\"");
	strcat(auxiliar,",\"sexo\":");
	strcat(auxiliar,"\"f\"");
	strcat(auxiliar,",\"idade\":");
	strcat(auxiliar,"10");
	strcat(auxiliar,"}");
	strcat(auxiliar,"]");
	strcat(auxiliar,",\"telefone\":[");
	strcat(auxiliar,"{\"ddd\":");
	strcat(auxiliar,"41");
	strcat(auxiliar,",\"numero\":");
	strcat(auxiliar,"30226317");
	strcat(auxiliar,",\"tipo\":");
	strcat(auxiliar,"0");
	strcat(auxiliar,"}");
	strcat(auxiliar,"]");
	strcat(auxiliar,",\"endereco\":");
	strcat(auxiliar,"{\"rua\":");
	strcat(auxiliar,"\"Ponta grossa\"");
	strcat(auxiliar,",\"complemento\":");
	strcat(auxiliar,"\"Apartamento 11\"");
	strcat(auxiliar,",\"bairro\":");
	strcat(auxiliar,"\"Portão\"");
	strcat(auxiliar,",\"cidade\":");
	strcat(auxiliar,"\"Curitiba\"");
	strcat(auxiliar,",\"estado\":");
	strcat(auxiliar,"\"Paraná\"");
	strcat(auxiliar,",\"cep\":");
	strcat(auxiliar,"80610160");
	strcat(auxiliar,",\"numero\":");
	strcat(auxiliar,"249");
	strcat(auxiliar,"}");
	strcat(auxiliar,"}");
	fputs(auxiliar, arquivo); //escrever dentro do endereço criado.
	fclose(arquivo);
}
void leitura(){ 
	FILE *arquivo = fopen("techvet.bd","r"); 
	char msg[1024]; //criar uma variavel pra receber o que vou ler.
    fgets(msg, 1024, arquivo); //leitura de uma linha do arquivo.
    lerCliente(msg,NULL);
	fclose(arquivo);
}

void lerCliente(char *clienteChar, struct cliente* cliente){ //transformar JSON em struct.
	jsmn_parser p;
	jsmntok_t t[128]; /* We expect no more than 128 tokens */
	int i;
	
	jsmn_init(&p);
	int r = jsmn_parse(&p, clienteChar, strlen(clienteChar), t, sizeof(t)/sizeof(t[0]));
	if (r < 0) {
		printf("Failed to parse JSON: %d\n", r);
	}
	for (i = 1; i < r; i++) {
		if (jsoneq(clienteChar, &t[i], "codigoCliente") == 0) {
			printf("- codigoCliente: %.*s\n", t[i+1].end-t[i+1].start, clienteChar + t[i+1].start);
			i++;
		}else if (jsoneq(clienteChar, &t[i], "nome") == 0) {
			printf("- nome: %.*s\n", t[i+1].end-t[i+1].start, clienteChar + t[i+1].start);
			i++;
		} 
	}
}
