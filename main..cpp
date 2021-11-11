#include <iostream>
#include <stdlib.h> 
#include <locale.h> 
#include <stdio.h> 
#include <string.h>
#include <conio.h>

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
	printf("ID=%d  Nome=%s %s   Idade=%d  Cpf=%d  Estado=%s",C.id,C.primeiroNome,C.segundoNome,C.idade,C.cpf,C.estado);
}

void impProduto(Produto P){
	printf("ID=%d  Produto=%s  Preço=%d  Quantidade=%d",P.id,P.nomeProduto,P.preco,P.quantidade);
}

void fileCliente(){
	printf("\t\t _____________________________\n");
	printf("\t\t|      Cadastro Cliente       |\n");
	printf("\t\t|                             |\n");
	printf("\t\t|                             |\n");
	printf("\t\t|                             |\n");
	FILE *cliente;
	cliente = fopen("Cliente.txt","a");
	if(cliente == NULL){
		printf("Erro na abertura do sistema!Tecle algo para voltar.");
	}else{
		fprintf(cliente,"teste");
	};
};


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
							char primeiroNome[50],segundoNome[50],estado[50];
							int id,cpf,idade;
							Cliente novo;
							fileCliente();
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
