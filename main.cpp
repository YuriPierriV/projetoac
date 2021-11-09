#include <iostream>
#include <stdlib.h> 
#include <locale.h> 
#include <stdio.h> 
#include <string.h>
#include <conio.h>

struct Cliente{
	char id[5];
	char primeiroNome[50];
	char segundoNome[50];
	int idade;
	char cpf[11];
	char estado[50];
};

Cliente setClient(char id[5],char primeiroNome[50],char segundoNome[50],int idade,char cpf[11],char estado[50]){
	Cliente C;
	C.id[5] = id;
	C.primeiroNome = primeiroNome;
	C.segundoNome = segundoNome;
	C.idade = idade;
	C.cpf = cpf;
	C.estado = estado;
	return C;
}

struct Produto{
	char id[5];
	char nomeProduto;
	int quantidade;
};

Produto setProduto(char id[5],char nomeProduto,int quantidade){
	Produto P;
	P.id[5] =
}

void logo(){
	
	
};

int tabelaInicial(int opcao){
	printf("\t\t _____________________________\n");
	printf("\t\t|       Sistema de dados      |\n");
	printf("\t\t|                             |\n");
	printf("\t\t|   1  ->    Clientes         |\n");
	printf("\t\t|                             |\n");
	printf("\t\t|   2  ->    Produtos         |\n");
	printf("\t\t|                             |\n");
	printf("\t\t|   3  ->  Compra/Vendas      |\n");
	printf("\t\t|                             |\n");
	printf("\t\t|           Opção: ");
	scanf("%d",opcao);
	printf("%d",opcao);
	system("cls");
	return opcao;
};

int subTabelaClientes(int opcao){
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
	printf("\t\t|           Opção: ");
	scanf("%d",opcao);
	printf("%d",opcao);
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
	printf("\t\t|           Opção: ");
	scanf("%d",opcao);
	printf("%d",opcao);
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
	printf("\t\t|           Opção: ");
	scanf("%d",opcao);
	system("cls");
	return opcao;
	
};

int main(){
	setlocale(LC_ALL,"portuguese");
	
	
	
	
	
}
