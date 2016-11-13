#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<windows.h>
#include<locale.h>
#include "jsmn.h"
#include "validacoetechvet.h"

#define ESC 27
#define CODIGOCLIENTE 1
#define ERRO_CODIGO 1
#define ERRO_NOMECLIENTE 2
#define ERRO_EMAIL 3
#define ERRO_SEXOCLIENTE 4
#define ERRO_CPF 5
#define ERRO_DATADIA 6
#define ERRO_DATAMES 7
#define ERRO_DATAANO 8
#define ERRO_PETNOME 9
#define ERRO_PETRACA 10
#define ERRO_PETSEXO 11
#define ERRO_PETIDADE 12
#define ERRO_TELEFONEDDD 13
#define ERRO_NUMEROTELEFONE 14
#define ERRO_TELEFONETIPO 15
#define ERRO_RUA 16
#define ERRO_COMPLEMENTO 17
#define ERRO_BAIRRO 18
#define ERRO_CIDADE 19
#define ERRO_ESTADO 20
#define ERRO_CEP 21
#define ERRO_NUMEROENDERECO 22

void salvar(struct cliente* cliente);
void leitura();
void lerCliente(char[],struct cliente*);

struct endereco{
	char rua[30], complemento[20], bairro[20], cidade[20], estado[20], cep[20];
	int numeroEndereco;
};
struct animal{
	char nomeAnimal[20], raca[20], sexoAnimal;
	int idade;
};
struct nascimento{
	int dia, mes, ano;
};
struct telefone{
	int ddd, numeroTelefone, tipo;
};
struct cliente{
	int codigoCliente;
	char nomeCliente[20], email[20], sexoCliente;
	long long int cpf;
	struct nascimento data;
	struct animal pet[10];
	struct telefone contato[10];
	struct endereco endereco;
	int totalAnimais;
	int totalTelefones;
};
struct produto{
	int codigoProduto;
	char  nomeProduto[50];
	float preco;
};

int main(){
	
	setlocale(LC_ALL,"Portuguese");
	int menu1=1,menu2,menu3,quant_animal,quant_telefone;
	struct cliente cliente;
	
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
							limparCliente(&cliente);
							printf("********CADASTRAR UM NOVO CLIENTE********\n\n");
							printf("\nINFORMAÇÕES PESSOAIS DO CLIENTE:\n");
							printf("Insira o código do cliente:\n");
							gets(cliente.codigocliente);
							fflush(stdin);
							printf("Informe o nome:\n");
							gets(cliente.nome);
							fflush(stdin);
							printf("Informe o e-mail:\n");
							gets(cliente.email);
							fflush(stdin);
							printf("Informe o sexo:\n");
							gets(cliente.sexo);
							fflush(stdin);
							printf("Insira o CPF:\n");
							scanf("%d", &cliente.cpf);
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
							scanf("%d", &cliente.endereco.numero);
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
									gets(cliente.pet[cliente.totalAnimais].nome);
									fflush(stdin);
									printf("Informe a raça do animal:\n");
									gets(cliente.pet[cliente.totalAnimais].raca);
									fflush(stdin);
									printf("Informe o sexo do animal:\n");
									gets(cliente.pet[cliente.totalAnimais].sexo);
									fflush(stdin);
									printf("Informe a idade do animal:\n");
									scanf("%d", &cliente.pet[cliente.totalAnimais].idade);
									fflush(stdin);
									cliente.totalAnimais=cliente.totalAnimais+1;
								}
							}
							while(quant_animal == 1);
							salvar(NULL);
							system("cls");
						break;
						case '2' :
							printf("*********LISTAR TODOS OS CLIENTES CADASTRADOS********\n\n");
							printf("DADOS CADASTRADOS:\n\n");
							printf("-------------------------------------------------\n");
							printf("Código do cliente: %s\n", cliente.codigocliente);
							printf("Nome do proprietário:%s \n", cliente.nome);
							printf("E-mail: %s\n", cliente.email);
							printf("Sexo: %s\n", cliente.sexo);
							printf("Data de nascimento: %d/%d/%d\n", cliente.data.dia, cliente.data.mes, cliente.data.ano);
							printf("CPF:\n", cliente.cpf);
							printf("DADOS RESIDENCIAIS:\n\n");
							printf("Rua:%s\n", cliente.endereco.rua);
							printf("Número:%d\n", cliente.endereco.numero);
							printf("Complemento:%s\n", cliente.endereco.complemento);
							printf("Bairro:%s\n", cliente.endereco.bairro);
							printf("Cidade: %s\n", cliente.endereco.cidade);
							printf("Estado: %s\n", cliente.endereco.estado);
							printf("CEP: %d\n", cliente.endereco.cep);
							printf("INFORMAÇÕES DE CONTATO:\n");
							for(i=0;i<cliente.totalTelefones;i++){
								printf("DDD %d\n", cliente.contato[i].ddd) 
								printf("Telefone: %d\n",cliente.contato[i].numeroTelefone);
								if(cliente.contato.tipo == 0){
									printf("Tipo: fixo\n");
								}else if(cliente.contato.tipo == 1){
									printf("Tipo: celular\n");
								}else {
									printf("Tipo: comercial\n");
								}
							}
							for(i=0;i<cliente.totalAnimais;i++){
								printf("INFORMAÇÕES DO ANIMAL:\n\n");
								printf("Nome:%s \n", cliente[i].pet.nome);
								printf("Raça:%s \n", cliente[i].pet.raca);
								printf("Sexo:%s \n", cliente[i].pet.sexo);
								printf("Idade:%d \n", cliente[i].pet.idade);
							}
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
							printf("LISTAR TODOS OS PRODUTOS CADASTRADOS\n\n");
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

int salvar(struct cliente* cliente){ //FILE é um tipo, uma struct.
	FILE *arquivo = fopen("techvet.bd","a+"); //fopen cria um arquivo e devolve o endereço de memória de onde está o arquivo. Tem que ser o tipo ponteiro por devolver um endereço.
	char auxiliar[1024];
	strcpy(auxiliar,"{\"codigoCliente\":");
	if(validaInt(cliente->codigoCliente) == false){
		return ERRO_CODIGO; 
	}
	strcat(auxiliar, itoa(cliente->codigoCliente));//função itoa transforma int em array de char. json só lê char.
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
	strcat(auxiliar,cliente->sexoCliente);
	strcat(auxiliar,",\"cpf\":");
	if(validalonglongInt(cliente->cpf) == false){
		return ERRO_CPF; 
	}
	strcat(auxiliar,cliente->cpf);
	strcat(auxiliar,",\"nascimento\":");
	strcat(auxiliar,"{\"dia\":");
	if(validaInt(cliente->data.dia) == false){
		return ERRO_DATADIA; 
	}
	strcat(auxiliar,cliente->data.dia);
	strcat(auxiliar,",\"mes\":");
	if(validaInt(cliente->data.mes) == false){
		return ERRO_DATAMES; 
	}
	strcat(auxiliar,cliente->data.mes);
	strcat(auxiliar,",\"ano\":");
	if(validaInt(cliente->data.ano) == false){
		return ERRO_DATAANO; 
	}
	strcat(auxiliar,cliente->data.ano);
	strcat(auxiliar,"}");
	strcat(auxiliar,",\"totalAnimais\":");
	strcat(auxiliar,cliente->totalAnimais);
	strcat(auxiliar,",\"animal\":[");
	
	for(i=0;i<cliente->totalAnimais;i++){
		strcat(auxiliar,"{\"nomeAnimal\":");
		if(validaChar(cliente->pet.nomeAnimal) == false){
		return ERRO_PETNOME; 
	}
		strcat(auxiliar,cliente[i]->pet.nomeAnimal);
		strcat(auxiliar,",\"raca\":");
		if(validaChar(cliente->pet.raca) == false){
		return ERRO_PETRACA; 
	}
		strcat(auxiliar,cliente[i]->pet.raca);
		strcat(auxiliar,",\"sexoAnimal\":");
		if(validaChar(cliente->pet.sexoAnimal) == false){
		return ERRO_PETSEXO; 
	}
		strcat(auxiliar,cliente[i]->pet.sexoAnimal);
		strcat(auxiliar,",\"idade\":");
		if(validaInt(cliente->pet.idade) == false){
		return ERRO_PETIDADE; 
	}
		strcat(auxiliar,cliente[i]->pet.idade);
		strcat(auxiliar,"}");
	}
	strcat(auxiliar,"]");
	strcat(auxiliar,",\"totalTelefone\":");
	strcat(auxiliar,cliente->totalTelefones);
	strcat(auxiliar,",\"telefone\":[");
	
	for(i=0;i<cliente->totalTelefones;i++){
		strcat(auxiliar,"{\"ddd\":");
		if(validaInt(cliente->contato.ddd) == false){
		return ERRO_TELEFONEDDD; 
	}
		strcat(auxiliar,cliente[i]->contato.ddd);
		strcat(auxiliar,",\"numeroTelefone\":");
		if(validaInt(cliente->contato.numeroTelefone) == false){
		return ERRO_NUMEROTELEFONE; 
	}
		strcat(auxiliar,cliente[i]->contato.numeroTelefone);
		strcat(auxiliar,",\"tipo\":");
		if(validaInt(cliente->contato.tipo) == false){
		return ERRO_TELEFONETIPO; 
	}
		strcat(auxiliar,cliente[i]->contato.tipo);
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
	strcat(auxiliar,",\"bairro\":");]
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
	if(validaInt(cliente->endereco.cep) == false){
		return ERRO_CEP; 
	}
	strcat(auxiliar,cliente->endereco.cep);
	strcat(auxiliar,",\"numeroEndereco\":");
	if(validaInt(cliente->endereco.numeroEndereco) == false){
		return ERRO_NUMEROENDERECO; 
	}
	strcat(auxiliar,cliente->endereco.numeroEndereco);
	strcat(auxiliar,"}");
	strcat(auxiliar,"},\n");
	fputs(auxiliar, arquivo); //escrever dentro do endereço criado.
	fclose(arquivo);
}
void leitura(){ 
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
