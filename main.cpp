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
	char id[5];
	char nomeProduto;
	int quantidade;
};

Produto setProduto(char id[5],char nomeProduto,int quantidade){
	Produto P;
	P.id[5] = id[5];
	P.nomeProduto = nomeProduto;
	P.quantidade = quantidade;
	return P;
}

void logo(){
	
	
};

void impCliente(Cliente C){
	printf("ID=%d  Nome=%s %s   Idade=%d  Cpf=%d  Estado=%s",C.id,C.primeiroNome,C.segundoNome,C.idade,C.cpf,C.estado);
}
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
	
	getch();
	
	
	
	
}
