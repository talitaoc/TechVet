#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<windows.h>
#include<locale.h>

#define VELOCIDADE 150

struct endereco{
	char rua[30], complemento[20], bairro[20], cidade[20], estado[20];
	int numeroEndereco,cep;
};
struct animal{
	char nomeAnimal[20], raca[20], sexoAnimal,especie[50];
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

void SetConsoleColour(WORD* Attributes, DWORD Colour)
{
    CONSOLE_SCREEN_BUFFER_INFO Info;
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hStdout, &Info);
    *Attributes = Info.wAttributes;
    SetConsoleTextAttribute(hStdout, Colour);
}

void ResetConsoleColour(WORD Attributes)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Attributes);
}

//https://msdn.microsoft.com/pt-br/library/windows/desktop/ms682088(v=vs.85).aspx#_win32_character_attributes

void SetWindow(int Width, int Height, int bufferWidth, int bufferHeight) 
{ 
    _COORD coord; 
    coord.X = bufferWidth; 
    coord.Y = bufferHeight; 

    _SMALL_RECT Rect; 
    Rect.Top = 0; 
    Rect.Left = 0; 
    Rect.Bottom = Height - 1; 
    Rect.Right = Width - 1; 

    HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);      // Get Handle 
    SetConsoleScreenBufferSize(Handle, coord);            // Set Buffer Size 
    SetConsoleWindowInfo(Handle, TRUE, &Rect);            // Set Window Size 
} 

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
	andar(distancia);
	while(i < 6){
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

