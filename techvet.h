#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<windows.h>
#include<locale.h>

struct endereco{
	char rua[30], complemento[20], bairro[20], cidade[20], estado[20];
	int numeroEndereco,cep;
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
