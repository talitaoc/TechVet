#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<windows.h>
#include<locale.h>


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


