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

void limparproduto (struct produto *produto){
	limparInt(&produto->codigoProduto);
    limparChar(produto->nomeProduto,50);
	limparFloat(&produto->preco);
}

void mostrarErro (int codigo, char* mERRO){
	switch(codigo){
		case ERRO_CODIGO:
			strcpy(mERRO, "Código do cliente inválido.");
			break;
		case ERRO_NOMECLIENTE:
			strcpy(mERRO, "Nome do cliente inválido.");
			break;
		case ERRO_EMAIL:
			strcpy(mERRO, "E-mail inválido.");
			break;
		case ERRO_SEXOCLIENTE:
			strcpy(mERRO, "Sexo inválido.");
			break;
		case ERRO_CPF:
			strcpy(mERRO, "CPF inválido.");
			break;
		case ERRO_DATADIA:
			strcpy(mERRO, "Data inválida.");
			break;
		case ERRO_DATAMES:
			strcpy(mERRO, "Mês inválido.");
			break;
		case ERRO_DATAANO:
			strcpy(mERRO, "Ano inválido.");
			break;
		case ERRO_PETNOME:
			strcpy(mERRO, "Nome do animal inválido.");
			break;
		case ERRO_PETRACA:
			strcpy(mERRO, "Raça do animal inválida.");
			break;
		case ERRO_PETIDADE:
			strcpy(mERRO, "Idade do animal inválida.");
			break;
		case ERRO_TELEFONEDDD:
		strcpy(mERRO, "DDD inválido.");
			break;
		case ERRO_NUMEROTELEFONE:
			strcpy(mERRO, "Número do telefone inválido.");
			break;
		case ERRO_TELEFONETIPO:
			strcpy(mERRO, "Tipo de telefone inválido.");
			break;
		case ERRO_RUA:
			strcpy(mERRO, "Nome da rua inválido.");
			break;
		case ERRO_COMPLEMENTO:
			strcpy(mERRO, "Complemento inválido.");
			break;
		case ERRO_BAIRRO:
			strcpy(mERRO, "Bairro inválido.");
			break;
		case ERRO_CIDADE:
			strcpy(mERRO, "Cidade inválida.");
			break;
		case ERRO_ESTADO:
			strcpy(mERRO, "Estado inválido.");
			break;
		case ERRO_CEP:
			strcpy(mERRO, "CEP inválido.");
			break;
		case ERRO_NUMEROENDERECO:
			strcpy(mERRO, "Número de endereço inválido.");
			break;
	}
	
}

