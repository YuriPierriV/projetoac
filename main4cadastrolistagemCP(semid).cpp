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

/*struct  compraVenda{
	int idVenda;
	
};*/

void logo(){
	
	
};

void impCliente(Cliente C,char primeiroNome[50],char segundoNome[50],char estado[50]){
	setlocale(LC_ALL,"portuguese");
	strcpy(C.primeiroNome,primeiroNome);
	strcpy(C.segundoNome,segundoNome);
	strcpy(C.estado,estado);
	printf("Nome=%s %s   Idade=%d  Cpf=%d  Estado=%s  ID=%d\n",C.primeiroNome,C.segundoNome,C.idade,C.cpf,C.estado,C.id);
}

void impProduto(Produto P,char nomeProduto[50]){
	setlocale(LC_ALL,"portuguese");
	strcpy(P.nomeProduto,nomeProduto);
	printf("Produto=%s  Preço=%d  Quantidade=%d  ID=%d\n",P.nomeProduto,P.preco,P.quantidade,P.id);
}

void cadastraCliente(Cliente C,char primeiroNome[50],char segundoNome[50],char estado[50]){
	setlocale(LC_ALL,"portuguese");
	strcpy(C.primeiroNome,primeiroNome);
	strcpy(C.segundoNome,segundoNome);
	strcpy(C.estado,estado);
	FILE *cliente;
	cliente = fopen("Cliente.txt","a");
	if(cliente == NULL){
		printf("Cadastro falhou!");
	}else{
		fprintf(cliente,"Nome=%s %s   Idade=%d  Cpf=%d  Estado=%s  ID=%d\n",C.primeiroNome,C.segundoNome,C.idade,C.cpf,C.estado,C.id);
	};
	fclose(cliente);
}

void cadastraProduto(Produto P,char nomeProduto[50]){
	setlocale(LC_ALL,"portuguese");
	strcpy(P.nomeProduto,nomeProduto);
	FILE *produto;
	produto = fopen("Produto.txt","a");
	if(produto == NULL){
		printf("Cadastro falhou!");
	}else{
		fprintf(produto,"Produto=%s  Preco=%d  Quantidade=%d  ID=%d\n",P.nomeProduto,P.preco,P.quantidade,P.id);
	};
	fclose(produto);
}

/*int idCliente(){
	FILE *cliente;
	int id,i;
	char c;
	cliente = fopen("Cliente.txt","r");
	if(cliente==NULL){
		id=1;
	}
	else{
		i=1;
		while(c!=EOF){
			c=fgetc(cliente);
			i++;
			};
		fseek(cliente,i--,SEEK_END);
		id=fscanf(cliente,"%d",&id);
		}
	
 	fclose (cliente);
		
		
	return id;
};

int idProduto(int id){
	FILE *produto;
	produto = fopen("Produto.txt","r");
 	fclose (produto);
		
		
	return id;
};*/


void quadroCadastroCliente(){
	
	printf("\t\t _____________________________\n");
	printf("\t\t|      Cadastro Cliente       |\n");
	printf("\t\t|                             |\n");
	
}

void quadroCadastroProduto(){
	
	printf("\t\t _____________________________\n");
	printf("\t\t|      Cadastro Produto       |\n");
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
	id = idCliente();
	novo = setCliente(id,primeiroNome,segundoNome,idade,cpf,estado);
	cadastraCliente(novo,primeiroNome,segundoNome,estado);
	quadroCadastroCliente();
	printf("\t\t Cliente id=%d cadastrado",id);
	getch();
	system("cls");
	return 1;
}

int cadastroProduto(Produto novo){
	int id,preco,quantidade;
	char nomeProduto[50];
	quadroCadastroProduto();
	printf("\t\tNome do produto:");
	scanf("%s",&nomeProduto);
	system("cls");
	quadroCadastroProduto();
	printf("\t\tPreço do produto:");
	scanf("%d",&preco);
	system("cls");
	quadroCadastroProduto();
	printf("\t\tQuantidade em estoque:");
	scanf("%d",&quantidade);
	system("cls");
	id = idProduto(id);
	novo = setProduto(id,nomeProduto,preco,quantidade);
	cadastraProduto(novo,nomeProduto);
	quadroCadastroProduto();
	printf("\t\t Produto id=%d cadastrado"/*,id*/);
	getch();
	system("cls");
	return 1;
}

void listarClientes(){
	int i;
	char linha[1000],*texto;
	system("cls");
	FILE *cliente;
	cliente = fopen("Cliente.txt","r");
	if(cliente== NULL){
		printf("Erro na listagem dos clientes!");
	}
	else{
		i=1;
		while(!feof(cliente)){
			texto=fgets(linha,1000,cliente);
			if(texto){
				printf("%s\n",linha);
				getch();
			}
		}
		system("cls");
	}
}

void listarProdutos(){
	int i;
	char linha[1000],*texto;
	system("cls");
	FILE *produto;
	produto = fopen("Produto.txt","r");
	if(produto== NULL){
		printf("Erro na listagem dos clientes!");
	}
	else{
		i=1;
		while(!feof(produto)){
			texto=fgets(linha,1000,produto);
			if(texto){
				printf("%s\n",linha);
				getch();
			}
		}
		system("cls");
	}
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
							Cliente novo;
							cadastroCliente(novo);
							break;
						case 2:
							listarClientes();
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
							Produto novo;
							cadastroProduto(novo);
							break;
						case 2:
							listarProdutos();
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
