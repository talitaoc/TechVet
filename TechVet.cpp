#include "jsmn.h"
#include "techvet.h"
#include "validacoestechvet.h"


#define ESC 27
#define CODIGOCLIENTE 1

//Declaração de todas as funções
int salvarCliente(struct cliente* cliente);
void listarTodosClientes(struct cliente *cliente);
void lerCliente(char*, struct cliente*);
int obterProximoCodigoCliente();
void buscarClienteEncontrado(char *buscarCliente);
int salvarProduto(struct produto *produto);
void listarTodosProdutos(struct produto *produto);
void lerProduto(char*, struct produto*);
int obterProximoCodigoProduto();
void buscarProdutosEncontrados(char *buscarProduto);
int excluirCliente(int codigo);
int excluirProduto(int codigo);
void separacao();
void printarCliente (struct cliente *cliente);


int main(){
	/*
	 * Codigos: https://msdn.microsoft.com/pt-br/library/windows/desktop/dd317756(v=vs.85).aspx
	 * 28591 é o código da codificação ISO-8859-1 (ou Latin-1) TABELA ASCII http://www.ascii-code.com/
	 * SetConsoleOutputCP: usa a codificação Latina para imprimir os caracteres no DOS
	 * SetConsoleCP: usa a codificação latina para ler os caracteres no DOS
	 */
	SetConsoleOutputCP( 28591 );	
	SetConsoleCP( 28591 );
	//tamanho console - função techvet.h
	SetWindow(77, 30, 77, 1000);
	
	setlocale(LC_ALL,"Portuguese");
	int i,menu1=1,menu2,menu3,quant_animal,quant_telefone;
	int codigoErro;
	struct cliente cliente;
	struct produto produto;
	WORD Attributes = 0;
	
	animar();
	system("cls");
	while(menu1!=ESC){
		printf("\n\n\n");
		printf("\n\t*************************************************************");
		printf("\n\t*                         TECHVET                           *");
		printf("\n\t*                 /)-_-(\\        /)-_-(\\                    *");
		printf("\n\t*                  (o o)          (o o)                     *");
		printf("\n\t*          .-----__/\\o/            \\o/\\__-----.             *");
		printf("\n\t*         /  __      /              \\      __  \\            *");
		printf("\n\t*     \\__/\\ /  \\_\\ |/                \\| /_/  \\ /\\__/        *");
		printf("\n\t*          \\\\     ||                  ||      \\\\            *");
		printf("\n\t*          //     ||                  ||      //            *");
		printf("\n\t*          |\\     |\\                  /|     /|             *");
		printf("\n\t*                   #  MENU PRINCIPAL  #                    *");
		printf("\n\t*                                                           *");
		printf("\n\t*                                                           *");
		printf("\n\t*            # DIGITE O NÚMERO DA OPÇÃO DESEJADA            *");
		printf("\n\t*                                                           *");
		printf("\n\t*            1 - ÁREA DE CLIENTES;                          *");
		printf("\n\t*            2 - PRODUTOS E SERVIÇOS;                       *");
		printf("\n\t*          ESC - SAIR DO PROGRAMA.                          *");
		printf("\n\t*                                                           *");                                                       
		printf("\n\t*                                                           *");
		printf("\n\t*************************************************************");
		printf("\n\n");
		menu1 = getch(); //leitura da opção escolhida como char - ex: 1 equivale a 49 na tabela ascii
		fflush(stdin);
		printf("\n");
		system("cls");
		
		switch(menu1){
			case '1' :
				do{
					printf("\n\n\n\n");
                    printf("                                  |\\__/,|   (`\\                   "); 
                    printf("\n                                _.|o o  |_   ) )                    ");				
					printf("\n\t************************(((***(((****************************");
					printf("\n\t*                                                           *");
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
							limparCliente(&cliente); //limpar toda a struct - está na biblioteca validacoestechvet
							SetConsoleColour(&Attributes, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
							printf("\n\t*************************************************************");
							printf("\n\t*               CADASTRAR UM NOVO CLIENTE                   *");
							printf("\n\t*************************************************************");
							ResetConsoleColour(Attributes);
							printf("\n\n\tINFORMAÇÕES PESSOAIS DO CLIENTE\n");
							cliente.codigoCliente = obterProximoCodigoCliente(); //obtenção do codigo sequencial
							printf("\n\tInforme o nome: ");
							gets(cliente.nomeCliente);
							fflush(stdin);
							printf("\tInforme o e-mail: ");
							gets(cliente.email);
							fflush(stdin);
							printf("\tInforme o sexo: ");
							scanf("%c",&cliente.sexoCliente);
							fflush(stdin);
							printf("\tInsira o CPF: ");
							scanf("%lld", &cliente.cpf); //leitura de long long int
							fflush(stdin);
							printf("\tInforme o dia de nascimento: ");
							scanf("%d", &cliente.data.dia);
							fflush(stdin);
							printf("\tInforme o mês de nascimento: ");
							scanf("%d", &cliente.data.mes);
							fflush(stdin);
							printf("\tInforme o ano de nascimento: ");
							scanf("%d", &cliente.data.ano);
							fflush(stdin);
							
							system("cls");
							SetConsoleColour(&Attributes, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
							printf("\n\t*************************************************************");
							printf("\n\t*               CADASTRAR UM NOVO CLIENTE                   *");
							printf("\n\t*************************************************************");
							ResetConsoleColour(Attributes);
							printf("\n\tINFORMAÇÕES RESIDENCIAIS:\n");
							printf("\n\tRua: ");
							gets(cliente.endereco.rua);
							fflush(stdin);
							printf("\tNúmero: ");
							scanf("%d", &cliente.endereco.numeroEndereco);
							fflush(stdin);
							printf("\tComplemento: ");
							gets(cliente.endereco.complemento);
							fflush(stdin);
							printf("\tBairro: ");
							gets(cliente.endereco.bairro);
							fflush(stdin);
							printf("\tCidade: ");
							gets(cliente.endereco.cidade);
							fflush(stdin);
							printf("\tEstado: ");
							gets(cliente.endereco.estado);
							fflush(stdin);
							printf("\tCEP: ");
							scanf("%d", &cliente.endereco.cep);
							fflush(stdin);
							
							system("cls");
							SetConsoleColour(&Attributes, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
							printf("\n\t*************************************************************");
							printf("\n\t*               CADASTRAR UM NOVO CLIENTE                   *");
							printf("\n\t*************************************************************");
							ResetConsoleColour(Attributes);
							printf("\n\tINFORMAÇÕES DE CONTATO:\n");
							do{
								printf("\n\t1 - Inserir números telefones\n");
								printf("\t0 - para sair ");
								quant_telefone=getch();
								fflush(stdin);
								if(quant_telefone=='1'){
									system("cls");
									SetConsoleColour(&Attributes, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
									printf("\n\t*************************************************************");
									printf("\n\t*               CADASTRAR UM NOVO CLIENTE                   *");
									printf("\n\t*************************************************************");
									ResetConsoleColour(Attributes);
									printf("\n\tDDD: ");
									scanf("%d",&cliente.contato[cliente.totalTelefones].ddd);
									fflush(stdin);
									printf("\tTelefone: ");
									scanf("%d",&cliente.contato[cliente.totalTelefones].numeroTelefone);
									fflush(stdin);
									printf("\tTipo: (1-fixo 2-celular 3-comercial) ");
									scanf("%d",&cliente.contato[cliente.totalTelefones].tipo);
									cliente.totalTelefones=cliente.totalTelefones+1;
								}
							}while(quant_telefone=='1');
							system("cls");
							SetConsoleColour(&Attributes, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
							printf("\n\t*************************************************************");
							printf("\n\t*               CADASTRAR UM NOVO CLIENTE                   *");
							printf("\n\t*************************************************************");
							ResetConsoleColour(Attributes);
							printf("\n\tINFORMAÇÕES DO ANIMAL:\n");
							do{
								printf("\n\t1 - Inserir Animal\n");
								printf("\t0 - para sair ");
								quant_animal=getch();
								fflush(stdin);
								if(quant_animal=='1'){
									system("cls");
									SetConsoleColour(&Attributes, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
									printf("\n\t*************************************************************");
									printf("\n\t*               CADASTRAR UM NOVO CLIENTE                   *");
									printf("\n\t*************************************************************");
									ResetConsoleColour(Attributes);
									printf("\n\tDigite o nome do animal: ");
									gets(cliente.pet[cliente.totalAnimais].nomeAnimal);
									fflush(stdin);
									printf("\tInforme a raça do animal: ");
									gets(cliente.pet[cliente.totalAnimais].raca);
									fflush(stdin);
									printf("\tInforme o sexo do animal: ");
									scanf("%c",&cliente.pet[cliente.totalAnimais].sexoAnimal);
									fflush(stdin);
									printf("\tInforme a idade do animal: ");
									scanf("%d", &cliente.pet[cliente.totalAnimais].idade);
									fflush(stdin);
									printf("\tInforme a espécie do animal: ");
									gets(cliente.pet[cliente.totalAnimais].especie);
									fflush(stdin);
									cliente.totalAnimais=cliente.totalAnimais+1;
								}
							}
							while(quant_animal == '1');
							codigoErro = salvarCliente(&cliente);
							if(codigoErro != 0){ //mensagem de erro - se salvar codigoErro recebe 0. caso não consiga salvar mostra a msg de erro
								char mErro [50];
								mostrarErro(codigoErro, mErro); //insere na varial mErro a string correspondente a codigoErro - verificar lib validacoestechvet
								printf("%s\n",mErro);
							}
							else{
								SetConsoleColour(&Attributes, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
								printf("\n\n\t>Cliente cadastrado com sucesso<\n");
								ResetConsoleColour(Attributes);
							}			
						break;
						case '2' :
							listarTodosClientes(&cliente);
							break;
						case '3' :
							SetConsoleColour(&Attributes, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
							printf("\n\t*************************************************************");
							printf("\n\t*               CONSULTAR CLIENTE CADASTRADO                *");
							printf("\n\t*************************************************************");
							ResetConsoleColour(Attributes);
							char buscarCliente[100];
							printf("\n\n\tInforme alguma informação do cliente: ");
							gets(buscarCliente); //codigo que quer buscar
							fflush(stdin);
							buscarClienteEncontrado(buscarCliente); 
							break;
						case '4' : 
							SetConsoleColour(&Attributes, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
							printf("\n\t*************************************************************");
							printf("\n\t*               EXCLUIR CLIENTE CADASTRADO                  *");
							printf("\n\t*************************************************************");
							ResetConsoleColour(Attributes);
							int excluirCodigoCliente;
							printf("\n\n\tInforme o código do produto a ser excluido: ");
							scanf("%d",&excluirCodigoCliente); //digitar qual codigo quer excluir
							fflush(stdin);
							if(excluirCliente(excluirCodigoCliente) == 0){ //caso função retornar 0 quer dizer que o cliente foi excluido, caso contrario não achou o codigo
								SetConsoleColour(&Attributes, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
								printf("\n\n\t>Cliente excluido com sucesso<\n\n");
								ResetConsoleColour(Attributes);
							}else{
								SetConsoleColour(&Attributes, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
								printf("\n\n\t>Não foi possível excluir cliente<\n\n\t>Cliente Inexistente<\n\n");
								ResetConsoleColour(Attributes);
							}
							break;
						default:
							break;	
					}
					if(menu2!=ESC){ //caso não seja ESC a tela vai ser segurada para poder mostrar a msg. lembrar que ESC é equivalente ao 27 (tabela ascii)
						printf("\n\n\t>Pressione ENTER para voltar< ");
						getch();
						system("cls");
					}
				}while(menu2!=ESC);
				break;
			case '2' :
				do{
					printf("\n\n\n\n");
                    printf("                                  |\\__/,|   (`\\                   "); 
                    printf("\n                                _.|o o  |_   ) )                    ");				
					printf("\n\t************************(((***(((****************************");
					printf("\n\t*                                                           *");
					printf("\n\t*                 # PRODUTOS E SERVIÇOS  #                  *");
					printf("\n\t*                                                           *");
					printf("\n\t*                                                           *");
					printf("\n\t*           # DIGITE O NÚMERO DA OPÇÃO DESEJADA             *");
					printf("\n\t*                                                           *");
					printf("\n\t*            1 - CADASTRAR PRODUTOS PARA VENDA;             *");
					printf("\n\t*            2 - LISTAR TODOS OS PRODUTOS CADASTRADOS;      *");
					printf("\n\t*            3 - CONSULTAR PRODUTOS CADASTRADOS;            *");
					printf("\n\t*            4 - REMOVER PRODUTOS CADASTRADOS;              *");
					printf("\n\t*           ESC - VOLTAR AO MENU PRINCIPAL.                 *");
					printf("\n\t*                                                           *");
					printf("\n\t*                                                           *");
					printf("\n\t*************************************************************");
					printf("\n\n");
					menu3 = getch();
					fflush(stdin);
					system("cls");
					
					switch(menu3){
						case '1' :
							limparProduto(&produto);
							SetConsoleColour(&Attributes, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
							printf("\n\t*************************************************************");
							printf("\n\t*             CADASTRAR PRODUTOS PARA VENDA                 *");
							printf("\n\t*************************************************************");
							ResetConsoleColour(Attributes);
							produto.codigoProduto = obterProximoCodigoProduto();
							fflush(stdin);
							printf("\n\n\tInforme o nome do produto: ");
							gets(produto.nomeProduto);
							fflush(stdin);
							printf("\tPreço do produto R$: ");
							scanf("%f",&produto.preco);
							fflush(stdin);
							
							codigoErro = salvarProduto(&produto);
							if(codigoErro != 0){
								char mErro [50];
								mostrarErro(codigoErro, mErro);
								printf("\t%s\n",mErro);
							}
							else{
								SetConsoleColour(&Attributes, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
								printf("\n\t>Produto cadastrado com sucesso<\n\n");
								ResetConsoleColour(Attributes);
							}	
							break;
						case '2' :
							listarTodosProdutos(&produto);
							break;
						case '3' :
							char buscarProduto[100];
							limparChar(buscarProduto,100);
							SetConsoleColour(&Attributes, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
							printf("\n\t*************************************************************");
							printf("\n\t*        CONSULTAR PRODUTOS CADASTRADOS NO SISTEMA          *");
							printf("\n\t*************************************************************");
							ResetConsoleColour(Attributes);
							printf("\n\n\tInforme o Nome do Produto desejado: ");
							gets(buscarProduto);
							fflush(stdin);
							buscarProdutosEncontrados(buscarProduto);
							break;
						case '4' :
							SetConsoleColour(&Attributes, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
							printf("\n\t*************************************************************");
							printf("\n\t*               REMOVER PRODUTOS CADASTRADOS                *");
							printf("\n\t*************************************************************");
							ResetConsoleColour(Attributes);
							int excluirCodigoProduto;
							printf("\n\n\tInforme o código do produto a ser excluido: ");
							scanf("%d",&excluirCodigoProduto);
							fflush(stdin);
							if(excluirProduto(excluirCodigoProduto) == 0){
								SetConsoleColour(&Attributes, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
								printf("\n\n\t>Produto excluido com sucesso<\n\n");
								ResetConsoleColour(Attributes);
							}else{
								SetConsoleColour(&Attributes, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
								printf("\n\n\t>Não foi possível excluir produto<\n\t>Produto Inexistente<\n\n");
								ResetConsoleColour(Attributes);
							}
							break;	
						default:
							break;	
					}
					if(menu3!=ESC){
						printf("\n\n\tPressione ENTER para voltar ");
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
/*Salvar cliente em JSON
Foi usado o json (java script object notation) para salvar em arquivo. O json possui um tipo especifico de notação.
um ex da notação: {"codigoProduto":1,"nomeProduto":"Antibiótico Amoxicilina 250mg","precoProduto":75,00},
Cada linha do arquivo equivale a um cliente ou um produto, portanto na parte de salvar cliente precisei abrir arquivo e separar cada parte para poder adicionar os valores desejados.
abre um arquivo na pasta onde está o programa.*/
int salvarCliente(struct cliente* cliente){ //FILE é um tipo, uma struct.
	FILE *arquivo = fopen("techvet.bd","a+"); //fopen cria um arquivo e devolve o endereço de memória de onde está o arquivo. Tem que ser o tipo ponteiro por devolver um endereço.
	char auxiliar[1024],buffer[100]; //auxiliares pra poder salvar cada parte depois juntar tudo.
	int i;
	//cada parte do json equivale a um token, ex: primeiro token: {"codigoProduto": essa parte vai ser adc no auxiliar, pra poder juntar depois e listar em uma linha do txt.
	strcpy(auxiliar,"{\"codigoCliente\":");
	if(validaInt(cliente->codigoCliente) == false){ //validações na lib validacoestechvet da fran.
		return ERRO_CODIGO; 
	}
	itoa(cliente->codigoCliente,buffer,10); //função itoa transforma int em array de char. json só lê char!!! adicionamos o valor da struct no buffer (outro auxiliar) 10 é a base (decimal)
	strcat(auxiliar, buffer); //concatena o buffer com auxiliar ou seja, teremos por fim: {"codigoProduto": 1  =>conseguimos unir o nosso token com a struct que foi preenchida pelo usuário
	strcat(auxiliar,",\"nomeCliente\":");//faz essa sequencia em todos os tokens, em todas as partes do json pra adicionar valores.
	if(validaChar(cliente->nomeCliente)== false){
		return ERRO_NOMECLIENTE;
	}
	strcat(auxiliar,"\"");
	strcat(auxiliar,cliente->nomeCliente); 
	strcat(auxiliar,"\"");
	strcat(auxiliar,",\"email\":");//aqui o txt ja está {"codigoProduto": 1,"nomeCliente":"Talita", - ai começa a colocar "email" e por ae vai....
	if(validaChar(cliente->email) == false){
		return ERRO_EMAIL; 
	}
	strcat(auxiliar,"\"");
	strcat(auxiliar,cliente->email);
	strcat(auxiliar,"\"");
	strcat(auxiliar,",\"sexoCliente\":");
	if(validaChar(cliente->sexoCliente) == false){
		return ERRO_SEXOCLIENTE; 
	}
	strcat(auxiliar,"\"");
	strcat(auxiliar,&cliente->sexoCliente);
	strcat(auxiliar,"\"");
	strcat(auxiliar,",\"cpf\":");
	lltoa(cliente->cpf,buffer,10); //maldito c!!!
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
		strcat(auxiliar,"\"");
		strcat(auxiliar,cliente->pet[i].nomeAnimal);
		strcat(auxiliar,"\"");
		strcat(auxiliar,",\"raca\":");
		if(validaChar(cliente->pet[i].raca) == false){
			return ERRO_PETRACA; 
		}
		strcat(auxiliar,"\"");
		strcat(auxiliar,cliente->pet[i].raca);
		strcat(auxiliar,"\"");
		strcat(auxiliar,",\"sexoAnimal\":");
		if(validaChar(cliente->pet[i].sexoAnimal) == false){
			return ERRO_PETSEXO; 
		}
		strcat(auxiliar,"\"");
		strcat(auxiliar,&cliente->pet[i].sexoAnimal);
		strcat(auxiliar,"\"");
		strcat(auxiliar,",\"idade\":");
		itoa(cliente->pet[i].idade,buffer,10);
		if(validaInt(cliente->pet[i].idade) == false){
			return ERRO_PETIDADE; 
		}
		strcat(auxiliar,buffer);
		strcat(auxiliar,",\"especie\":");
		if(validaChar(cliente->pet[i].especie) == false){
			return ERRO_ESPECIE; 
		}
		strcat(auxiliar,"\"");
		strcat(auxiliar,cliente->pet[i].especie);
		strcat(auxiliar,"\"");
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
	strcat(auxiliar,"\"");
	strcat(auxiliar, cliente->endereco.rua);
	strcat(auxiliar,"\"");
	strcat(auxiliar,",\"complemento\":");
	if(validaChar(cliente->endereco.complemento) == false){
		return ERRO_COMPLEMENTO; 
	}
	strcat(auxiliar,"\"");
	strcat(auxiliar,cliente->endereco.complemento);
	strcat(auxiliar,"\"");
	strcat(auxiliar,",\"bairro\":");
	if(validaChar(cliente->endereco.bairro) == false){
		return ERRO_BAIRRO; 
	}
	strcat(auxiliar,"\"");
	strcat(auxiliar,cliente->endereco.bairro);
	strcat(auxiliar,"\"");
	strcat(auxiliar,",\"cidade\":");
	if(validaChar(cliente->endereco.cidade) == false){
		return ERRO_CIDADE; 
	}
	strcat(auxiliar,"\"");
	strcat(auxiliar,cliente->endereco.cidade);
	strcat(auxiliar,"\"");
	strcat(auxiliar,",\"estado\":");
	if(validaChar(cliente->endereco.estado) == false){
		return ERRO_ESTADO; 
	}
	strcat(auxiliar,"\"");
	strcat(auxiliar,cliente->endereco.estado);
	strcat(auxiliar,"\"");
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
	strcat(auxiliar,buffer); //concatena todos, cria a escrita final do arquivo
	strcat(auxiliar,"}");
	strcat(auxiliar,"},\n");
	fputs(auxiliar, arquivo); //escrever dentro do endereço criado.
	fclose(arquivo);
	return 0;
}
//mostrar cliente 
//necessário abrir o arquivo txt para leitura.
void listarTodosClientes(struct cliente *cliente){ 
	FILE *arquivo = fopen("techvet.bd","r"); 
	char dadosArquivo[1024]; //criar uma variavel pra receber o que vou ler.
	int i;
	int retorno = -1;
	WORD Attributes = 0; //mudança de cor
	SetConsoleColour(&Attributes, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
    printf("\n\t*************************************************************");
	printf("\n\t*           LISTA DE TODOS CLIENTES CADASTRADOS             *");
	printf("\n\t*************************************************************\n");
	ResetConsoleColour(Attributes);
    if(arquivo != NULL){
    	while(fgets(dadosArquivo, 1024, arquivo) != NULL){//fgets lê a linha do arquivo txt e adiciona na variavel auxiliar como um char
		 	limparCliente(cliente); //lib validacoestechvet.h
			lerCliente(dadosArquivo, cliente); //função de leitura, explicada mais pra baixo
			printarCliente(cliente); //printar cliente. tinha muita coisa e foi colocado como funçao
			ResetConsoleColour(Attributes);
			retorno=0;
		}
	}
	if(retorno == -1){
		SetConsoleColour(&Attributes, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
		printf("\n\n\t>Não existe clientes cadastrados<");
		ResetConsoleColour(Attributes);
	}	
	fclose(arquivo);
}
//printar todas as informações do cliente 
void printarCliente (struct cliente *cliente){
	int i;
	WORD Attributes = 0;
	separacao();
	SetConsoleColour(&Attributes, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	printf("\n\t*                    DADOS CADASTRADOS                      *");
	separacao();
	ResetConsoleColour(Attributes);
	printf("\n\tCódigo do cliente: %d\n", cliente->codigoCliente);
	printf("\tNome do proprietário: %s \n", cliente->nomeCliente);
	printf("\tE-mail: %s\n", cliente->email);
	printf("\tSexo: %c\n", cliente->sexoCliente);
	printf("\tData de nascimento: %d/%d/%d\n", cliente->data.dia, cliente->data.mes, cliente->data.ano);
	printf("\tCPF: %lld\n", cliente->cpf);
	separacao();
	printf("\n\tDADOS RESIDENCIAIS\n");
	printf("\n\tRua: %s\n", cliente->endereco.rua);
	printf("\tNúmero: %d\n", cliente->endereco.numeroEndereco);
	printf("\tComplemento: %s\n", cliente->endereco.complemento);
	printf("\tBairro: %s\n", cliente->endereco.bairro);
	printf("\tCidade: %s\n", cliente->endereco.cidade);
	printf("\tEstado: %s\n", cliente->endereco.estado);
	printf("\tCEP: %d\n", cliente->endereco.cep);
	separacao();
	printf("\n\tINFORMAÇÕES DE CONTATO\n");
	for(i=0;i<cliente->totalTelefones;i++){
		printf("\n\tDDD: %d\n", cliente->contato[i].ddd); 
		printf("\tTelefone: %d\n",cliente->contato[i].numeroTelefone);
		if(cliente->contato[i].tipo == 1){
			printf("\tTipo: fixo\n");
		}else if(cliente->contato[i].tipo == 2){
			printf("\tTipo: celular\n");
		}else {
			printf("\tTipo: comercial\n");
		}
	}
	separacao();
	printf("\n\tINFORMAÇÕES DO ANIMAL\n");
	for(i=0;i<cliente->totalAnimais;i++){
		printf("\n\tNome: %s \n", cliente->pet[i].nomeAnimal);
		printf("\tRaça: %s \n", cliente->pet[i].raca);
		printf("\tSexo: %c \n", cliente->pet[i].sexoAnimal);
		printf("\tIdade: %d \n", cliente->pet[i].idade);
		printf("\tEspécie: %s \n",cliente->pet[i].especie);
	}
}
//Ler cliente do arquivo json
//função lerCliente recebe como parametro um ponteiro pro auxiliar que possui a linha do txt e o ponteiro do cliente (que é uma struct)
void lerCliente(char *dadosArquivo, struct cliente* cliente){ //transformar JSON em struct.
	parseDados(dadosArquivo); //parsedados recebe a linha do txt e gera todos os tokens desejados lá na lib jsmn (nao precisamos explicar o processo, só saber o que faz)
	int i;
	char valor[100]; //valor é mais uma auxiliar
	// quando a struct é ponteiro se usa "->" para acessar seus membros.
	 //obterDado é uma função da lib jsmn que achamos na internet, basicamente pega o token que preciso, gerado pelo parseDados, indico: ex "codigoCliente", pega o dado equivalente ao token, no caso do codigoCliente ele pega o numero do codigo
	obterDado(valor, 100, dadosArquivo, "codigoCliente"); //faz isso com todos os tokens da linha. adiciona na variavel valor.
	cliente->codigoCliente = atoi(valor);//atoi = array to int - transformar um array char em um inteiro...um char tem 1 byte, 1 inteiro tem 4 bytes. pega o int e coloca na struct
	obterDado(valor, 100, dadosArquivo, "nomeCliente");
	strcpy(cliente->nomeCliente,valor); //quando precisamos de um char, não precisa transformar, só passar o valor para struct com strcpy.
	obterDado(valor, 100, dadosArquivo, "email");//essa sequencia segue por todos os tokens.
	strcpy(cliente->email,valor);
	obterDado(valor, 100, dadosArquivo, "sexoCliente");
	cliente->sexoCliente = valor[0]; //so um caracter, pegar a primeira posicao do vetor
	obterDado(valor, 100, dadosArquivo, "cpf");
	cliente->cpf = atoll(valor);
	obterDado(valor, 100, dadosArquivo, "dia");
	cliente->data.dia = atoi(valor);
	obterDado(valor, 100, dadosArquivo, "mes");
	cliente->data.mes = atoi(valor);
	obterDado(valor, 100, dadosArquivo, "ano");
	cliente->data.ano = atoi(valor);
	obterDado(valor, 100, dadosArquivo, "totalAnimais");
	cliente->totalAnimais = atoi(valor);
	for(i=0;i<cliente->totalAnimais;i++){
		obterDado(valor, 100, dadosArquivo, "nomeAnimal");
		strcpy(cliente->pet[i].nomeAnimal,valor);
		obterDado(valor, 100, dadosArquivo, "raca");
		strcpy(cliente->pet[i].raca,valor);
		obterDado(valor, 100, dadosArquivo, "sexoAnimal");
		cliente->pet[i].sexoAnimal = valor[0];
		obterDado(valor, 100, dadosArquivo, "idade");
		cliente->pet[i].idade = atoi(valor);
		obterDado(valor, 100, dadosArquivo, "especie");
		strcpy(cliente->pet[i].especie, valor);
	}
	obterDado(valor, 100, dadosArquivo, "totalTelefone");
	cliente->totalTelefones = atoi(valor);
	for(i=0;i<cliente->totalTelefones;i++){
		obterDado(valor, 100, dadosArquivo, "ddd");
		cliente->contato[i].ddd = atoi(valor);
		obterDado(valor, 100, dadosArquivo, "numeroTelefone");
		cliente->contato[i].numeroTelefone = atoi(valor);
		obterDado(valor, 100, dadosArquivo, "tipo");
		cliente->contato[i].tipo = atoi(valor);
	}
	obterDado(valor, 100, dadosArquivo, "rua");
	strcpy(cliente->endereco.rua,valor);
	obterDado(valor, 100, dadosArquivo, "complemento");
	strcpy(cliente->endereco.complemento,valor);
	obterDado(valor, 100, dadosArquivo, "bairro");
	strcpy(cliente->endereco.bairro,valor);
	obterDado(valor, 100, dadosArquivo, "cidade");
	strcpy(cliente->endereco.cidade,valor);
	obterDado(valor, 100, dadosArquivo, "estado");
	strcpy(cliente->endereco.estado,valor);
	obterDado(valor, 100, dadosArquivo, "cep");
	cliente->endereco.cep = atoi(valor);
	obterDado(valor, 100, dadosArquivo, "numeroEndereco");
	cliente->endereco.numeroEndereco = atoi(valor);
}
//obter codigo sequencial
int obterProximoCodigoCliente(){
	FILE *arquivo = fopen("techvet.bd","r");
	char linhaLida[1024]; //linha lida do txt, 1024 foi escolhido como tamanho maximo de uma linha (contamos os caracteres e deu umas 500).
	char auxiliar[1024];//auxiliar
	char buffer[100]; //auxiliar
	int ultimoCodigo=0; //inicializa com 0.
	if(arquivo != NULL){ //se o arquivo existir ele entra no if se não não faz nada.
		while(fgets(linhaLida,1024,arquivo) != NULL){ //fgets lê uma linha do arquivo que foi aberto e se for final do arquivo retorna NULL (acabou o arquivo)
			limparChar(auxiliar,1024);
			strcpy(auxiliar,linhaLida); //pego a ultima linha do arquivo e adc no auxiliar. while vai loopar todas as linhas e no final vai ficar salvo só a ultima que é a que eu quero pra obter o proximo codigo
		}
		parseDados(auxiliar); //parseDados vai pegar os token dessa ultima linha salva no while
		obterDado(buffer, 100, auxiliar, "codigoCliente"); //obterDado vai pegar so o token codigoCliente que é o que eu preciso e vai adicionar no buffer
		ultimoCodigo = atoi (buffer); //função atoi transforma char em int pra adcionar na variavel ultimoCodigo 
	}
	fclose(arquivo);
	return ultimoCodigo+1; //retorno ultimoCodigo +1 porque quero gerar codigo sequencial :)
}
//busca de cliente no arquivo txt
void buscarClienteEncontrado(char *buscarCliente){ //buscarcliente receve um ponteiro char que aponta para o char que a pessoa inserir no teclado...ele acha qlqr valor (txt é todo char)
	FILE *arquivo = fopen("techvet.bd","r"); //abro arquivo
	char linhaLida[1024]; //linha lida
	int i;
	WORD Attributes = 0;
	int retorno=-1;
	struct cliente cliente; //declaracao da struct que vai ser usada na funcao
	if(arquivo != NULL){ //se o arquivo existir ele entra no if
		while(fgets(linhaLida,1024,arquivo) != NULL){ //lê uma linha do txt em cada passada do while
			if(strstr(linhaLida,buscarCliente) != NULL){ // procura na linha o que usuário digitou na busca
				limparCliente(&cliente); //limpa a struct (validacoestechvet.h)
				lerCliente(linhaLida,&cliente); //voltar na função lerCliente
				printarCliente(&cliente); //função printarCliente mais a cima.
				retorno = 0;
			}
		}
		
	}
	if(retorno == -1){
		SetConsoleColour(&Attributes, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
		printf("\n\n\t>Cliente NÃO encontrado<\n");
		ResetConsoleColour(Attributes);
	}
}
//excluir cliente no txt
//para excluir um cliente do txt precisamos criar um outro arquivo auxiliar, para que salve os clientes/linhas que eu quero que se mantenha.
//basicamente copia as linhas que eu não quero excluir no txt auxiliar. Apos isso limpa o txt base e depois copia o que tava no txt auxiliar no base. E por fim deleta o auxiliar.
//meio complicado mas é assim que deleta kkkk :)
int excluirCliente(int codigo){
	FILE *arquivo = fopen("techvet.bd","r"); //r de read
	FILE *arquivo2 = fopen("techvet.temp","w"); //w de write
	char linhaLida[1024];
	char excluir[10]; //auxiliar - é pelo codigo que é feita a exclusão
	int retorno=-1;
	struct cliente cliente;
	if(arquivo != NULL){	
		while(fgets(linhaLida,1024,arquivo) != NULL){ //le uma linha
    			limparCliente(&cliente);
				parseDados(linhaLida); //separa os tokens
				obterDado(excluir, 10, linhaLida, "codigoCliente"); //pega o token codigo
				cliente.codigoCliente = atoi(excluir); // transforma pra int
				if(codigo != cliente.codigoCliente){ //se o codigo digitado for diferente do codigo da linha 
					fputs(linhaLida,arquivo2); //escreve no arquivo, pega a linha e coloca no arquivo2 auxiliar.
				}else{
					retorno = 0; //caso ache o codigo
				}
		}
		fclose(arquivo2); //sempre tem que fechar o arquivo!!!
		fclose(arquivo);
		arquivo = fopen("techvet.bd","w"); //abre como escrita
		arquivo2 = fopen("techvet.temp","r"); //abre como leitura
		if(arquivo != NULL){
			while(fgets(linhaLida,1024,arquivo2) != NULL){ //le a linha do arquivo2 auxiliar
				fputs(linhaLida,arquivo);  //escreve no arquivo base
			}
		}	
	}
	fclose(arquivo2);
	fclose(arquivo);
	remove("techvet.temp"); //deleta o arquivo auxiliar
	return retorno; //pra ver se deletou ou nao 
	// basicamente o arquivo techvet.bd vai ser sobrescrito sem o codigo que eu quero deletar
}

//tudo se repete nas funções pro produto!!!!!


//salvar produto em modo json
int salvarProduto(struct produto *produto){
	setlocale(LC_ALL,"Portuguese");
	FILE *arquivo = fopen("produtos.bd", "ab+");
	char auxiliar[1024];
	char buffer [100];
	strcpy(auxiliar,"{\"codigoProduto\":");
	if(validaInt(produto->codigoProduto) == false){
		return ERRO_CODIGOPRODUTO; 
	}
	itoa(produto->codigoProduto,buffer,10);
	strcat(auxiliar,buffer);
	strcat(auxiliar,",\"nomeProduto\":");
	if(validaChar(produto->nomeProduto) == false){
		return ERRO_NOMEPRODUTO;
	}
	strcat(auxiliar,"\"");
	strcat(auxiliar,produto->nomeProduto);
	strcat(auxiliar,"\"");
	strcat(auxiliar, ",\"precoProduto\":");
	if(validaFloat(produto->preco) == false){
		return ERRO_PRECO;
	}
	sprintf(buffer, "%0.2f", produto->preco);//conversão float pra char. sprintf escreve float como char ou qualquer outro tipo.
	strcat(auxiliar,"\"");
	strcat(auxiliar,buffer);
	strcat(auxiliar,"\"");
	strcat(auxiliar,"},\n");
	fputs(auxiliar, arquivo); // finalizar a escrita no arquivo...
	fclose(arquivo);
	return 0;
}
//mostrar produto
void listarTodosProdutos(struct produto *produto){ 
	FILE *arquivo = fopen("produtos.bd","r"); 
	char dadosArquivo[1024]; //criar uma variavel pra receber o que vou ler.
	int i;
	int retorno = -1;
	WORD Attributes = 0;
	SetConsoleColour(&Attributes, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
    printf("\n\t*************************************************************");
	printf("\n\t*            LISTA TODOS PRODUTOS CADASTRADOS               *");
	printf("\n\t*************************************************************\n");
    ResetConsoleColour(Attributes);
    if(arquivo != NULL){
    	printf("\n\t*************************************************************");
		printf("\n\t*                    DADOS CADASTRADOS                      *");
		ResetConsoleColour(Attributes);
    	 while(fgets(dadosArquivo, 1024, arquivo) != NULL){//leitura de uma linha do arquivo.
		 	limparProduto(produto);
			lerProduto(dadosArquivo, produto);
			separacao();
			printf("\n\t Código do produto: %d", produto->codigoProduto);
			printf("\n\t Nome do produto: %s", produto->nomeProduto);
			printf("\n\t Preço do produto: R$ %.2f",produto->preco);
			retorno = 0;
		}
		separacao();
	}  
	if(retorno == -1){
		SetConsoleColour(&Attributes, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
		printf("\n\n\t>Não existe produto cadastrados<");
		ResetConsoleColour(Attributes);
    }
	fclose(arquivo);
}
//ler produto - json
void lerProduto(char *dadosArquivo, struct produto *produto){
	parseDados(dadosArquivo);
	char valor[100];
	obterDado(valor, 100, dadosArquivo, "codigoProduto");
	produto->codigoProduto = atoi(valor);
	obterDado(valor, 100, dadosArquivo, "nomeProduto");
	strcpy(produto->nomeProduto, valor);
	obterDado(valor, 100, dadosArquivo, "precoProduto");
	produto->preco = atof(valor);
}
//obter codigo sequencial
int obterProximoCodigoProduto(){
	FILE *arquivo = fopen("produtos.bd","r");
	char linhaLida[1024];
	char auxiliar[1024];
	char buffer[100];
	int ultimoCodigo=0;
	if(arquivo != NULL){
		while(fgets(linhaLida,1024,arquivo) != NULL){
			limparChar(auxiliar,1024);
			strcpy(auxiliar,linhaLida);
		}
		parseDados(auxiliar);
		obterDado(buffer, 100, auxiliar, "codigoProduto");
		ultimoCodigo = atoi (buffer);
	}
	fclose(arquivo);
	return ultimoCodigo+1;
}
//busca de produto no txt
void buscarProdutosEncontrados(char *buscarProduto){
	FILE *arquivo = fopen("produtos.bd","r");
	char linhaLida[1024];
	int retorno=-1;
	WORD Attributes = 0;
	struct produto produto;
	if(arquivo != NULL){	
		while(fgets(linhaLida,1024,arquivo) != NULL){
			if(strstr(linhaLida, buscarProduto) != NULL) { //compara os nomes dos produtos do arquivo de cada linha do bd ao nome digitado
    			limparProduto(&produto);
				lerProduto(linhaLida, &produto);
				separacao();
				printf("\n\tCódigo do produto: %d \n", produto.codigoProduto);
				printf("\tNome do produto: %s\n", produto.nomeProduto);
				printf("\tPreço do produto: R$ %0.2f\n",produto.preco);
				retorno=0;
			}
		}
	}
	if(retorno == -1){
		SetConsoleColour(&Attributes, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
		printf("\n\n\t>Produto NÃO encontrado<\n");
		ResetConsoleColour(Attributes);
	}
	fclose(arquivo);
}
//excluir produto no txt
int excluirProduto(int codigo){
	FILE *arquivo = fopen("produtos.bd","r");
	FILE *arquivo2 = fopen("produtos.temp","w");
	char linhaLida[1024];
	char excluir[10];
	int retorno=-1;
	struct produto produto;
	if(arquivo != NULL){	
		while(fgets(linhaLida,1024,arquivo) != NULL){
    			limparProduto(&produto);
				parseDados(linhaLida);
				obterDado(excluir, 10, linhaLida, "codigoProduto");
				produto.codigoProduto = atoi(excluir);
				if(codigo != produto.codigoProduto){
					fputs(linhaLida,arquivo2);
				}else{
					retorno = 0;
				}
		}
		fclose(arquivo2);
		fclose(arquivo);
		arquivo = fopen("produtos.bd","w");
		arquivo2 = fopen("produtos.temp","r");
		if(arquivo != NULL){
			while(fgets(linhaLida,1024,arquivo2) != NULL){
				fputs(linhaLida,arquivo);
			}
		}	
	}
	fclose(arquivo2);
	fclose(arquivo);
	remove("produtos.temp");
	return retorno;
}
void separacao(){
	WORD Attributes = 0;
	SetConsoleColour(&Attributes, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	printf("\n\t*************************************************************");
	ResetConsoleColour(Attributes);
}
