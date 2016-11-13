




int salvarProduto(struct produto *produto){
	FILE *arquivo = fopen("produtos.bd", "a+");
	char auxiliar[1024], buffer [100];
	strcpy(auxiliar,"{\"codigoProduto\":");
	if(validaInt(cliente->codigoProduto) == false){
		return ERRO_CODIGOPRODUTO; 
	}
	itoa(cliente->codigoProduto,buffer,10);
	strcat(auxiliar,buffer);
	strcat(auxiliar,",\"nomeProduto\":");
	if(validaChar(produto->nomeProduto)==false){
		return ERRO_NOMEPRODUTO;
	}
	strcat(auxiliar, ",\"precoProduto\":");
	strcat(auxiliar,produto->nomeProduto);
	sprintf(buffer, "%f", produto->preco);//conversão de float para char
	strcat(auxiliar,buffer);
	strcat(auxiliar,"}\n");
}

void lerProduto(*char dadosArquivo, struct produto *produto){
	parseDados(dadosArquivo);
	char valor[100];
	obterDado(valor, dadosArquivo, "codigoProduto");
	produto->codigoProduto = atoi(valor);
}
