#include <iostream>
#include <stdlib.h> 
#include <locale.h> 
#include <stdio.h> 
#include <string.h>
#include <conio.h>
#include <time.h>
#include<math.h>


struct Cliente{
	int id;
	char primeiroNome[50];
	char segundoNome[50];
	int idade;
	int cpf;
	char estado[50];
};

Cliente setCliente(int id,char primeiroNome[50],char segundoNome[50],int idade,int cpf,char estado[50]){
	Cliente C;
	C.id = id;
	C.primeiroNome[50] = primeiroNome[50];
	C.segundoNome[50] = segundoNome[50];
	C.idade = idade;
	C.cpf = cpf;
	C.estado[50] = estado[50];
	return C;
}

struct Produto{
	int id;
	char nomeProduto[50];
	int preco;
	int quantidade;
};

Produto setProduto(int id,char nomeProduto[50],int preco,int quantidade){
	Produto P;
	P.id = id;
	P.nomeProduto[50] = nomeProduto[50];
	P.preco = preco;
	P.quantidade = quantidade;
	return P;
}

void logo(){
	
	
};

void impCliente(Cliente C,char primeiroNome[50],char segundoNome[50],char estado[50]){
	strcpy(C.primeiroNome,primeiroNome);
	strcpy(C.segundoNome,segundoNome);
	strcpy(C.estado,estado);
	FILE *cliente;
	cliente = fopen("Cliente.txt","a");
	if(cliente == NULL){
		printf("Cadastro falhou!");
	}else{
		fprintf(cliente,"\n%d  Nome=%s %s   Idade=%d  Cpf=%d  Estado=%s",C.id,C.primeiroNome,C.segundoNome,C.idade,C.cpf,C.estado);
	};
	fclose(cliente);
}

void impProduto(Produto P){
	printf("%d  Produto=%s  Preço=%d  Quantidade=%d",P.id,P.nomeProduto,P.preco,P.quantidade);
}

int idCliente(int id){
	FILE *cliente;
	cliente = fopen("Cliente.txt","r");
	if (cliente == NULL) {
		int id = 1;
	}
	else {
		
		
	return id;
};



void quadroCadastroCliente(){
	
	printf("\t\t _____________________________\n");
	printf("\t\t|      Cadastro Cliente       |\n");
	printf("\t\t|                             |\n");
	
}

int cadastroCliente(Cliente novo){
	char primeiroNome[50],segundoNome[50],estado[50];
	int id,cpf,idade,verificao;
	quadroCadastroCliente();
	printf("\t\tNome do cliente:");
	scanf("%s",&primeiroNome);
	system("cls");
	quadroCadastroCliente();
	printf("\t\tSobrenome do cliente:");
	scanf("%s",&segundoNome);
	system("cls");
	quadroCadastroCliente();
	printf("\t\tEstado de residencia:");
	scanf("%s",&estado);
	system("cls");
	quadroCadastroCliente();
	printf("\t\tIdade do cliente:");
	scanf("%d",&idade);
	system("cls");
	quadroCadastroCliente();
	printf("\t\tCpf do cliente:");
	scanf("%d",&cpf);
	system("cls");
	
	novo = setCliente(id,primeiroNome,segundoNome,idade,cpf,estado);
	impCliente(novo,primeiroNome,segundoNome,estado);
	

	return 1;
}

int tabelaInicial(int opcao){
	printf("\t\t _____________________________\n");
	printf("\t\t|       Sistema de dados      |\n");
	printf("\t\t|                             |\n");
	printf("\t\t|   1  ->    Clientes         |\n");
	printf("\t\t|                             |\n");
	printf("\t\t|   2  ->    Produtos         |\n");
	printf("\t\t|                             |\n");
	printf("\t\t|   3  ->  Compras/Vendas     |\n");
	printf("\t\t|                             |\n");
	printf("\t\t|   4  ->  Fechar sistema     |\n");
	printf("\t\t|                             |\n");
	printf("\t\t|           Opção: ");
	scanf("%d",&opcao);
	system("cls");
	return opcao;
};

int subTabelaCliente(int opcao){
	printf("\t\t _____________________________\n");
	printf("\t\t|          Clientes           |\n");
	printf("\t\t|                             |\n");
	printf("\t\t|   1  ->    Cadastrar        |\n");
	printf("\t\t|                             |\n");
	printf("\t\t|   2  ->    Listar           |\n");
	printf("\t\t|                             |\n");
	printf("\t\t|   3  ->    Atualizar        |\n");
	printf("\t\t|                             |\n");
	printf("\t\t|   4  ->    Deletar          |\n");
	printf("\t\t|                             |\n");
	printf("\t\t|   5  ->    Voltar Menu      |\n");
	printf("\t\t|                             |\n");
	printf("\t\t|           Opção: ");
	scanf("%d",&opcao);
	system("cls");
	return opcao;
};

int subTabelaProdutos(int opcao){
	printf("\t\t _____________________________\n");
	printf("\t\t|          Produtos           |\n");
	printf("\t\t|                             |\n");
	printf("\t\t|   1  ->    Cadastrar        |\n");
	printf("\t\t|                             |\n");
	printf("\t\t|   2  ->    Listar           |\n");
	printf("\t\t|                             |\n");
	printf("\t\t|   3  ->    Atualizar        |\n");
	printf("\t\t|                             |\n");
	printf("\t\t|   4  ->    Deletar          |\n");
	printf("\t\t|                             |\n");
	printf("\t\t|   5  ->    Voltar Menu      |\n");
	printf("\t\t|                             |\n");
	printf("\t\t|           Opção: ");
	scanf("%d",&opcao);
	system("cls");
	return opcao;
};

int subTabelaCp(int opcao){
	printf("\t\t _____________________________\n");
	printf("\t\t|       Compras/vendas        |\n");
	printf("\t\t|                             |\n");
	printf("\t\t|   1  ->    Cadastrar        |\n");
	printf("\t\t|                             |\n");
	printf("\t\t|   2  ->    Listar           |\n");
	printf("\t\t|                             |\n");
	printf("\t\t|   3  ->    Atualizar        |\n");
	printf("\t\t|                             |\n");
	printf("\t\t|   4  ->    Deletar          |\n");
	printf("\t\t|                             |\n");
	printf("\t\t|   5  ->    Voltar Menu      |\n");
	printf("\t\t|                             |\n");
	printf("\t\t|           Opção: ");
	scanf("%d",&opcao);
	system("cls");
	return opcao;
	
};

int main(){
	setlocale(LC_ALL,"portuguese");
	int opcao;
	bool inicial,subs;
	inicial=true;
	subs=true;
	while(inicial){
		switch(tabelaInicial(opcao)){
			case 1:
				subs=true;
				while(subs){
					switch(subTabelaCliente(opcao)){
						case 1:
							//char primeiroNome[50],segundoNome[50],estado[50];
							//int id,cpf,idade;
							Cliente novo;
							cadastroCliente(novo);
							break;
						case 2:
							printf("Listar");
							break;
						case 3:
							printf("Atualizar");
							break;
						case 4:
							printf("Deletar");
							break;
						case 5:
							subs=false;
							break;
					};
				}
				break;
			case 2:
				subs=true;
				while(subs){
					switch(subTabelaProdutos(opcao)){
						case 1:
							printf("cadastrar");
							break;
						case 2:
							printf("Listar");
							break;
						case 3:
							printf("Atualizar");
							break;
						case 4:
							printf("Deletar");
							break;
						case 5:
							subs=false;
							break;
					};
				}
				break;
			case 3:
				subs=true;
				while(subs){
					switch(subTabelaCp(opcao)){
						case 1:
							printf("cadastrar");
							break;
						case 2:
							printf("Listar");
							break;
						case 3:
							printf("Atualizar");
							break;
						case 4:
							printf("Deletar");
							break;
						case 5:
							subs=false;
							break;
					};
				}
				break;
			case 4:
				inicial=false;
				printf("error");
				break;
		}
	}
		
	
	
	
	
	
}
