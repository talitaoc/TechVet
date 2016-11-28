#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<windows.h>
#include<locale.h>


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
#define ERRO_ESPECIE 23
#define ERRO_CODIGOPRODUTO 24
#define ERRO_NOMEPRODUTO 25
#define ERRO_PRECO 26


void limparChar(char vetor[], int tamanho){
	int i;
	for(i=0; i<tamanho; i++){
		vetor[i] = '\0';
	}

}
void limparChar (char *valor){
	*valor = '\0';
}
void limparInt (int *valor){
	*valor = 0;
}

void limparFloat( float *valor){
	*valor = 0;
}

void limparlonglongInt (long long int *valor){
	*valor = 0;
}

bool validaChar (char vetor[]){
	if(vetor[0] == '\0'){
		return false;
	}
	else{
		return true;
	}
}

bool validaInt (int valor){
	if(valor == 0){
		return false;
	}
	else{
		return true;
	}
}
bool validaFloat (float valor){
	if(valor == 0){
		return false;
	}
	else{
		return true;
	}
}

bool validaChar (char valor){
	if(valor == '\0'){
		return false;
	}
	else{
		return true;
	}
}

bool validalonglongInt (long long int valor){
	if(valor == 0){
		return false;
	}
	else{
		return true;
	}
}

void limparCliente (struct cliente *cliente){
	limparInt(&cliente->codigoCliente);
	limparChar(cliente->nomeCliente,20);
	limparChar(cliente->email,20);
	limparChar(&cliente->sexoCliente);
	limparlonglongInt(&cliente->cpf);
	limparInt(&cliente->data.dia);
	limparInt(&cliente->data.mes);
	limparInt(&cliente->data.ano);
	int i;
	for(i=0; i<10; i++){
		limparChar(cliente->pet[i].nomeAnimal,20);
		limparChar(cliente->pet[i].raca,20);
		limparChar(&cliente->pet[i].sexoAnimal);
		limparChar(cliente->pet[i].especie);
		limparInt(&cliente->pet[i].idade);
		limparInt(&cliente->totalAnimais);
	}
	for(i=0; i<10; i++){
		limparInt(&cliente->contato[i].ddd);
		limparInt(&cliente->contato[i].numeroTelefone);
		limparInt(&cliente->contato[i].tipo);
	}
	limparInt(&cliente->totalTelefones);
	limparChar(cliente->endereco.rua,30);
	limparChar(cliente->endereco.complemento,20);
	limparChar(cliente->endereco.bairro,20);
	limparChar(cliente->endereco.cidade,20);
	limparInt(&cliente->endereco.cep);
	limparInt(&cliente->endereco.numeroEndereco);
}

void limparProduto (struct produto *produto){
	limparInt(&produto->codigoProduto);
    limparChar(produto->nomeProduto,50);
	limparFloat(&produto->preco);
}

void mostrarErro (int codigo, char* mERRO){
	switch(codigo){
		case ERRO_CODIGO:
			strcpy(mERRO, "C�digo do cliente inv�lido.");
			break;
		case ERRO_NOMECLIENTE:
			strcpy(mERRO, "Nome do cliente inv�lido.");
			break;
		case ERRO_EMAIL:
			strcpy(mERRO, "E-mail inv�lido.");
			break;
		case ERRO_SEXOCLIENTE:
			strcpy(mERRO, "Sexo inv�lido.");
			break;
		case ERRO_CPF:
			strcpy(mERRO, "CPF inv�lido.");
			break;
		case ERRO_DATADIA:
			strcpy(mERRO, "Data inv�lida.");
			break;
		case ERRO_DATAMES:
			strcpy(mERRO, "M�s inv�lido.");
			break;
		case ERRO_DATAANO:
			strcpy(mERRO, "Ano inv�lido.");
			break;
		case ERRO_PETNOME:
			strcpy(mERRO, "Nome do animal inv�lido.");
			break;
		case ERRO_PETRACA:
			strcpy(mERRO, "Ra�a do animal inv�lida.");
			break;
		case ERRO_PETIDADE:
			strcpy(mERRO, "Idade do animal inv�lida.");
			break;
		case ERRO_TELEFONEDDD:
			strcpy(mERRO, "DDD inv�lido.");
			break;
		case ERRO_NUMEROTELEFONE:
			strcpy(mERRO, "N�mero do telefone inv�lido.");
			break;
		case ERRO_TELEFONETIPO:
			strcpy(mERRO, "Tipo de telefone inv�lido.");
			break;
		case ERRO_RUA:
			strcpy(mERRO, "Nome da rua inv�lido.");
			break;
		case ERRO_COMPLEMENTO:
			strcpy(mERRO, "Complemento inv�lido.");
			break;
		case ERRO_BAIRRO:
			strcpy(mERRO, "Bairro inv�lido.");
			break;
		case ERRO_CIDADE:
			strcpy(mERRO, "Cidade inv�lida.");
			break;
		case ERRO_ESTADO:
			strcpy(mERRO, "Estado inv�lido.");
			break;
		case ERRO_CEP:
			strcpy(mERRO, "CEP inv�lido.");
			break;
		case ERRO_NUMEROENDERECO:
			strcpy(mERRO, "N�mero de endere�o inv�lido.");
			break;
		case ERRO_ESPECIE:
			strcpy(mERRO, "Esp�cie inv�lida.");
			break;
		case ERRO_CODIGOPRODUTO:
			strcpy(mERRO, "C�digo produto inv�lido");
			break;
		case ERRO_NOMEPRODUTO:
			strcpy(mERRO,"Nome produto inv�lido");
			break;		
		case ERRO_PRECO:
			strcpy(mERRO, "Pre�o produto inv�lido");
			break;		
	}
}

