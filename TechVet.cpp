#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<windows.h>
#include<locale.h>
#include "jsmn.h"
#include"techvet.h"
#include "validacoetechvet.h"


#define ESC 27
#define CODIGOCLIENTE 1

int salvarCliente(struct cliente* cliente);
void leituraCliente();
void lerCliente(char[],struct cliente*);


int main(){
	
	setlocale(LC_ALL,"Portuguese");
	int i,menu1=1,menu2,menu3,quant_animal,quant_telefone;
	struct cliente cliente;
	struct produto produto;
	
	while(menu1!=ESC){
		printf("\n\t*************************************************************");
		printf("\n\t*                 #  MENU PRINCIPAL  #                      *");
		printf("\n\t*                                                           *");
		printf("\n\t*                                                           *");
		printf("\n\t*        # DIGITE O NÚMERO DA OPÇÃO DESEJADA:               *");
		printf("\n\t*                                                           *");
		printf("\n\t*            1 - ÁREA DE CLIENTES;                          *");
		printf("\n\t*            2 - PRODUTOS E SERVIÇOS ;                      *");
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
							limparCliente(&cliente);
							printf("********CADASTRAR UM NOVO CLIENTE********\n\n");
							printf("\n\nINFORMAÇÕES PESSOAIS DO CLIENTE:\n");
							printf("\nInsira o código do cliente:");
							scanf("%d",&cliente.codigoCliente);
							fflush(stdin);
							printf("Informe o nome:");
							gets(cliente.nomeCliente);
							fflush(stdin);
							printf("Informe o e-mail:");
							gets(cliente.email);
							fflush(stdin);
							printf("Informe o sexo:\n");
							scanf("%c",&cliente.sexoCliente);
							fflush(stdin);
							printf("Insira o CPF:\n");
							scanf("%ll", &cliente.cpf);
							fflush(stdin);
							printf("Informe o dia de nascimento:\n");
							scanf("%d", &cliente.data.dia);
							fflush(stdin);
							printf("Informe o mês de nascimento:\n");
							scanf("%d", &cliente.data.mes);
							fflush(stdin);
							printf("Informe o ano de nascimento:\n");
							scanf("%d", &cliente.data.ano);
							fflush(stdin);
							printf("\nINFORMAÇÕES RESIDENCIAIS:\n\n");
							printf("Rua:\n");
							gets(cliente.endereco.rua);
							fflush(stdin);
							printf("Número:\n");
							scanf("%d", &cliente.endereco.numeroEndereco);
							fflush(stdin);
							printf("Complemento:\n");
							gets(cliente.endereco.complemento);
							fflush(stdin);
							printf("Bairro:\n");
							gets(cliente.endereco.bairro);
							fflush(stdin);
							printf("Cidade:\n");
							gets(cliente.endereco.cidade);
							fflush(stdin);
							printf("Estado:\n");
							gets(cliente.endereco.estado);
							fflush(stdin);
							printf("CEP:\n");
							scanf("%d", &cliente.endereco.cep);
							fflush(stdin);
							printf("\nINFORMAÇÕES DE CONTATO:\n\n");
							do{
								printf("Digite 1 para inserir os números telefones:\n");
								printf("Digite 0 para sair:\n");
								scanf("%d", &quant_telefone);
								fflush(stdin);
								if(quant_telefone==1){
									printf("DDD:\n");
									scanf("%d",&cliente.contato[cliente.totalTelefones].ddd);
									fflush(stdin);
									printf("Telefone:\n");
									scanf("%d",&cliente.contato[cliente.totalTelefones].numeroTelefone);
									fflush(stdin);
									printf("Tipo: (0-fixo 1-celular 2-comercial)\n");
									scanf("%d",&cliente.contato[cliente.totalTelefones].tipo);
									cliente.totalTelefones=cliente.totalTelefones+1;
								}
							}while(quant_telefone==1);
							printf("\nINFORMAÇÕES DO ANIMAL:\n\n");
							do{
								printf("Digite 1 para inserir os dados no animal:\n");
								printf("Digite 0 para sair:\n");
								scanf("%d", &quant_animal);
								fflush(stdin);
								if(quant_animal==1){
									printf("Digite o nome do animal:\n");
									gets(cliente.pet[cliente.totalAnimais].nomeAnimal);
									fflush(stdin);
									printf("Informe a raça do animal:\n");
									gets(cliente.pet[cliente.totalAnimais].raca);
									fflush(stdin);
									printf("Informe o sexo do animal:\n");
									scanf("%c",&cliente.pet[cliente.totalAnimais].sexoAnimal);
									fflush(stdin);
									printf("Informe a idade do animal:\n");
									scanf("%d", &cliente.pet[cliente.totalAnimais].idade);
									fflush(stdin);
									cliente.totalAnimais=cliente.totalAnimais+1;
								}
							}
							while(quant_animal == 1);
							salvarCliente(&cliente);
							system("cls");
						break;
						case '2' :
							printf("*********LISTAR TODOS OS CLIENTES CADASTRADOS********\n\n");
							printf("DADOS CADASTRADOS:\n\n");
							printf("-------------------------------------------------\n");
							printf("Código do cliente: %d\n", cliente.codigoCliente);
							printf("Nome do proprietário: %s \n", cliente.nomeCliente);
							printf("E-mail: %s\n", cliente.email);
							printf("Sexo: %c\n", cliente.sexoCliente);
							printf("Data de nascimento: %d/%d/%d\n", cliente.data.dia, cliente.data.mes, cliente.data.ano);
							printf("CPF: %ll\n", cliente.cpf);
							printf("DADOS RESIDENCIAIS:\n\n");
							printf("Rua: %s\n", cliente.endereco.rua);
							printf("Número: %d\n", cliente.endereco.numeroEndereco);
							printf("Complemento: %s\n", cliente.endereco.complemento);
							printf("Bairro: %s\n", cliente.endereco.bairro);
							printf("Cidade: %s\n", cliente.endereco.cidade);
							printf("Estado: %s\n", cliente.endereco.estado);
							printf("CEP: %d\n", cliente.endereco.cep);
							printf("INFORMAÇÕES DE CONTATO:\n");
							for(i=0;i<cliente.totalTelefones;i++){
								printf("DDD: %d\n", cliente.contato[i].ddd); 
								printf("Telefone: %d\n",cliente.contato[i].numeroTelefone);
								if(cliente.contato[i].tipo == 0){
									printf("Tipo: fixo\n");
								}else if(cliente.contato[i].tipo == 1){
									printf("Tipo: celular\n");
								}else {
									printf("Tipo: comercial\n");
								}
							}
							printf("INFORMAÇÕES DO ANIMAL:\n\n");
							for(i=0;i<cliente.totalAnimais;i++){
								printf("Nome: %s \n", cliente.pet[i].nomeAnimal);
								printf("Raça: %s \n", cliente.pet[i].raca);
								printf("Sexo: %s \n", cliente.pet[i].sexoAnimal);
								printf("Idade: %d \n", cliente.pet[i].idade);
							}
							leituraCliente();
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
					printf("\n\t*            2 - LISTAR TODOS OS PRODUTOS CADASTRADOS ;     *");
					printf("\n\t*            3 - CONSULTAR PRODUTOS CADASTRADOS NO SISTEMA; *");
					printf("\n\t*            4 - REMOVER PRODUTOS CADASTRADOS ;             *");
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
							printf("*****CADASTRAR PRODUTOS PARA VENDA******\n\n");
							printf("Digite o código de barras do produto:\n");
							scanf("%d",&produto.codigoProduto);
							fflush(stdin);
							printf("Informe o nome do produto:\n");
							gets(produto.nomeProduto);
							fflush(stdin);
							printf("Preço do produto R$:\n");
							scanf("%f",&produto.preco);
							fflush(stdin);
							break;
						case '2' :
							printf("*****LISTAR TODOS OS PRODUTOS CADASTRADOS*****\n\n");
							printf("------------------------------------------\n\n");
							printf("Código do produto: %d \n", produto.codigoProduto);
							printf("Nome do produto: %s\n", produto.nomeProduto);
							printf("Preço do produto: R$ %.2f\n",produto.preco);
							break;
						case '3' :
							printf("CONSULTAR PRODUTOS CADASTRADOS NO SISTEMA\n\n");
							break;
						case '4' :
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

int salvarCliente(struct cliente* cliente){ //FILE é um tipo, uma struct.
	FILE *arquivo = fopen("techvet.bd","a+"); //fopen cria um arquivo e devolve o endereço de memória de onde está o arquivo. Tem que ser o tipo ponteiro por devolver um endereço.
	char auxiliar[1024],buffer[100];
	int i;
	strcpy(auxiliar,"{\"codigoCliente\":");
	if(validaInt(cliente->codigoCliente) == false){
		return ERRO_CODIGO; 
	}
	itoa(cliente->codigoCliente,buffer,10);
	strcat(auxiliar, buffer); //função itoa transforma int em array de char. json só lê char.
	strcat(auxiliar,",\"nomeCliente\":");
	if(validaChar(cliente->nomeCliente)== false){
		return ERRO_NOMECLIENTE;
	}
	strcat(auxiliar,cliente->nomeCliente);
	strcat(auxiliar,",\"email\":");
	if(validaChar(cliente->email) == false){
		return ERRO_EMAIL; 
	}
	strcat(auxiliar,cliente->email);
	strcat(auxiliar,",\"sexoCliente\":");
	if(validaChar(cliente->sexoCliente) == false){
		return ERRO_SEXOCLIENTE; 
	}
	strcat(auxiliar,&cliente->sexoCliente);
	strcat(auxiliar,",\"cpf\":");
	ltoa(cliente->cpf,buffer,10);
	if(validalonglongInt(cliente->cpf) == false){
		return ERRO_CPF; 
	}
	strcat(auxiliar,buffer);
	strcat(auxiliar,",\"nascimento\":");
	strcat(auxiliar,"{\"dia\":");
	itoa(cliente->data.dia,buffer,10);
	if(validaInt(cliente->data.dia) == false){
		return ERRO_DATADIA; 
	}
	strcat(auxiliar,buffer);
	strcat(auxiliar,",\"mes\":");
	itoa(cliente->data.mes,buffer,10);
	if(validaInt(cliente->data.mes) == false){
		return ERRO_DATAMES; 
	}
	strcat(auxiliar,buffer);
	strcat(auxiliar,",\"ano\":");
	itoa(cliente->data.ano,buffer,10);
	if(validaInt(cliente->data.ano) == false){
		return ERRO_DATAANO; 
	}
	strcat(auxiliar,buffer);
	strcat(auxiliar,"}");
	strcat(auxiliar,",\"totalAnimais\":");
	itoa(cliente->totalAnimais,buffer,10);
	strcat(auxiliar,buffer);
	strcat(auxiliar,",\"animal\":[");
	
	for(i=0;i<cliente->totalAnimais;i++){
		strcat(auxiliar,"{\"nomeAnimal\":");
		if(validaChar(cliente->pet[i].nomeAnimal) == false){
		return ERRO_PETNOME; 
	}
		strcat(auxiliar,cliente->pet[i].nomeAnimal);
		strcat(auxiliar,",\"raca\":");
		if(validaChar(cliente->pet[i].raca) == false){
		return ERRO_PETRACA; 
	}
		strcat(auxiliar,cliente->pet[i].raca);
		strcat(auxiliar,",\"sexoAnimal\":");
		if(validaChar(cliente->pet[i].sexoAnimal) == false){
		return ERRO_PETSEXO; 
	}
		strcat(auxiliar,&cliente->pet[i].sexoAnimal);
		strcat(auxiliar,",\"idade\":");
		itoa(cliente->pet[i].idade,buffer,10);
		if(validaInt(cliente->pet[i].idade) == false){
		return ERRO_PETIDADE; 
	}
		strcat(auxiliar,buffer);
		strcat(auxiliar,"}");
	}
	strcat(auxiliar,"]");
	strcat(auxiliar,",\"totalTelefone\":");
	itoa(cliente->totalTelefones,buffer,10);
	strcat(auxiliar,buffer);
	strcat(auxiliar,",\"telefone\":[");
	
	for(i=0;i<cliente->totalTelefones;i++){
		strcat(auxiliar,"{\"ddd\":");
		itoa(cliente->contato[i].ddd,buffer,10);
		if(validaInt(cliente->contato[i].ddd) == false){
		return ERRO_TELEFONEDDD; 
	}
		strcat(auxiliar,buffer);
		strcat(auxiliar,",\"numeroTelefone\":");
		itoa(cliente->contato[i].numeroTelefone,buffer,10);
		if(validaInt(cliente->contato[i].numeroTelefone) == false){
		return ERRO_NUMEROTELEFONE; 
	}
		strcat(auxiliar,buffer);
		strcat(auxiliar,",\"tipo\":");
		itoa(cliente->contato[i].tipo,buffer,10);
		if(validaInt(cliente->contato[i].tipo) == false){
		return ERRO_TELEFONETIPO; 
	}
		strcat(auxiliar,buffer);
		strcat(auxiliar,"}");
	}
	strcat(auxiliar,"]");
	strcat(auxiliar,",\"endereco\":");
	strcat(auxiliar,"{\"rua\":");
	if(validaChar(cliente->endereco.rua) == false){
		return ERRO_RUA; 
	}
	strcat(auxiliar, cliente->endereco.rua);
	strcat(auxiliar,",\"complemento\":");
	if(validaChar(cliente->endereco.complemento) == false){
		return ERRO_COMPLEMENTO; 
	}
	strcat(auxiliar,cliente->endereco.complemento);
	strcat(auxiliar,",\"bairro\":");
	if(validaChar(cliente->endereco.bairro) == false){
		return ERRO_BAIRRO; 
	}
	strcat(auxiliar,cliente->endereco.bairro);
	strcat(auxiliar,",\"cidade\":");
	if(validaChar(cliente->endereco.cidade) == false){
		return ERRO_CIDADE; 
	}
	strcat(auxiliar,cliente->endereco.cidade);
	strcat(auxiliar,",\"estado\":");
	if(validaChar(cliente->endereco.estado) == false){
		return ERRO_ESTADO; 
	}
	strcat(auxiliar,cliente->endereco.estado);
	strcat(auxiliar,",\"cep\":");
	itoa(cliente->endereco.cep,buffer,10);
	if(validaInt(cliente->endereco.cep) == false){
		return ERRO_CEP; 
	}
	strcat(auxiliar,buffer);
	strcat(auxiliar,",\"numeroEndereco\":");
	itoa(cliente->endereco.numeroEndereco,buffer,10);
	if(validaInt(cliente->endereco.numeroEndereco) == false){
		return ERRO_NUMEROENDERECO; 
	}
	strcat(auxiliar,buffer);
	strcat(auxiliar,"}");
	strcat(auxiliar,"},\n");
	fputs(auxiliar, arquivo); //escrever dentro do endereço criado.
	fclose(arquivo);
}
void leituraCliente(){ 
	struct cliente cliente;
	FILE *arquivo = fopen("techvet.bd","r"); 
	char dadosArquivo[1024]; //criar uma variavel pra receber o que vou ler.
    fgets(dadosArquivo, 1024, arquivo); //leitura de uma linha do arquivo.
    lerCliente(dadosArquivo, &cliente);
    printf("%d\n",cliente.codigoCliente);
	fclose(arquivo);
}

void lerCliente(char *dadosArquivo, struct cliente* cliente){ //transformar JSON em struct.
	parseDados(dadosArquivo);
	char valor[100];
	obterDado(valor, dadosArquivo, "codigoCliente");
	cliente->codigoCliente = atoi(valor);// quando a struct é ponteiro se usa "->" para acessar seus membros.
	//atoi = array to int - transformar um array char em um inteiro...um char tem 1 byte, 1 inteiro tem 4 bytes.
}
