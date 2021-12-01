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
	char cidade[50];
	int idade;
};

Cliente setCliente(int id,int idade,char primeiroNome[50],char segundoNome[50],char cidade[50]){
	Cliente C;
	C.id = id;
	C.primeiroNome[50] = primeiroNome[50];
	C.segundoNome[50] = segundoNome[50];
	C.idade = idade;
	C.cidade[50] = cidade[50];
	strcpy(C.primeiroNome,primeiroNome);
	strcpy(C.segundoNome,segundoNome);
	strcpy(C.cidade,cidade);
	FILE *cliente;
	cliente = fopen("Clientes.txt","a");
	if(cliente == NULL){
		printf("Cadastro falhou!");
	}else{
		fprintf(cliente,"%s %s %s %d %d\n",C.primeiroNome,C.segundoNome,C.cidade,C.idade,C.id);
	};
	fclose(cliente);
	return C;
}

struct Produto{
	int id;
	char nomeProduto[50];
	float precoUnitario;
	int estoque;
};

Produto setProduto(int id,char nomeProduto[50],float precoUnitario,int estoque){
	Produto P;
	P.id = id;
	P.nomeProduto[50] = nomeProduto[50];
	P.precoUnitario = precoUnitario;
	P.estoque = estoque;
	strcpy(P.nomeProduto,nomeProduto);
	FILE *produto;
	produto = fopen("Produtos.txt","a");
	if(produto == NULL){
		printf("Cadastro falhou!");
	}else{
		fprintf(produto,"%s %f %d %d\n",P.nomeProduto,P.precoUnitario,P.estoque,P.id);
	};
	fclose(produto);
	return P;
}

struct  CompraVenda{
	int id;
	int quantidade;
	int idCliente;
	int idProduto;
};

CompraVenda setCv(int id,int quantidade, int idCliente,int idProduto){
	CompraVenda V;
	V.id = id;
	V.idCliente = idCliente;
	V.idProduto = idProduto;
	V.quantidade = quantidade;
	FILE *vendas;
	vendas=fopen("Vendas.txt","a");
	if(vendas == NULL){
		printf("Erro no registro da venda!");
	}
	else{
		fprintf(vendas,"%d %d %d %d\n",V.id,V.idCliente,V.idProduto,V.quantidade);
	}
	fclose(vendas);
	return V;
}

int idCliente(){
	int i,aux,idade,id=0;
	char primeiroNome[50],segundoNome[50],cidade[50];
	FILE *cliente;
	cliente = fopen("Clientes.txt","r");
	if(cliente == NULL){
		printf("Erro no gerenciamento dos clientes");
	}
	else{
		i=1;
		aux = fscanf(cliente, "%s %s %s %d %d\n",&primeiroNome,&segundoNome,&cidade,&idade,&id);
		while(aux!= EOF){
			i = i+1;
			aux = fscanf(cliente, "%s %s %s %d %d\n",&primeiroNome,&segundoNome,&cidade,&idade,&id);
			}
		}
	id++;
	fclose(cliente);
		system("cls");
		return id;
	};

int idProdutos(){
	FILE *produto;
	produto = fopen("Produtos.txt","r");
	int i,aux,id=0,estoque;
	float precoUnitario;
	char nomeProduto[50];
	if(produto== NULL){
		printf("Erro na listagem dos clientes!");
	}
	else{
		i=1;
		aux = fscanf(produto, "%s %f %d %d",&nomeProduto,&precoUnitario,&estoque,&id);
		while(aux!= EOF){
			i = i+1;
			aux = fscanf(produto, "%s %f %d %d",&nomeProduto,&precoUnitario,&estoque,&id);
			}
		}
	id++;
	fclose (produto);
		system("cls");
		return id;	
		
	return id;
};

int idCv(){
	int i,aux,idCliente,idProduto,quantidade,id=0;
	FILE *vendas;
	vendas = fopen("Vendas.txt","r");
	if(vendas == NULL){
		printf("Erro no gerenciamento das vendas");
	}
	else{
		i = 1;
		aux = fscanf(vendas, "%d %d %d %d",&id,&idCliente,&idProduto,&quantidade);
		while(aux != EOF){
			i = i+1;
			aux = fscanf(vendas, "%d %d %d %d",&id,&idCliente,&idProduto,&quantidade);
		}
	}
	id++;
	fclose(vendas);
	system("cls");
	return id;
}

int idDeletar(){
	printf("\t\t _____________________________\n");
	printf("\t\t|         Deletar id          |\n");
	printf("\t\t|                             |\n");
	printf("\t\t Qual id deletar: ");
	int idDeletar;
	scanf("%d",&idDeletar);
	return idDeletar;
}

void deleteCliente(int idClienteSelect){
	int id,idNew=1,idade,i,aux1;
	char primeiroNome[50],segundoNome[50],cidade[50];
	FILE *cliente;
	FILE *reup;
	cliente = fopen("Clientes.txt","r");
	reup = fopen("Cliente.txt","w");
	if(cliente == NULL){
		printf("Erro para atualizar arquivo");
	}
	else{
		i=1;
		aux1 = fscanf(cliente,"%s %s %s %d %d\n",&primeiroNome,&segundoNome,&cidade,&idade,&id);
		while( aux1 != EOF){
			if(idClienteSelect!=i){
				fprintf(reup,"%s %s %s %d %d\n",primeiroNome,segundoNome,cidade,idade,idNew);
			}
			else{
				printf("Linha deletada com sucesso!");
		        idNew--;
			}
			idNew++;
			i=i+1;
			aux1 = fscanf(cliente,"%s %s %s %d %d\n",&primeiroNome,&segundoNome,&cidade,&idade,&id);
			
		}
		fclose(cliente);
		fclose(reup);
		remove("Clientes.txt");
		rename("Cliente.txt","Clientes.txt");
	}
	
}

void deleteProduto(int idProdutoSelect){
	int id,idNew=1,estoque,i,aux1;
	float precoUnitario;
	char nomeProduto[50];
	FILE *produto;
	FILE *reup;
	produto = fopen("Produtos.txt","r");
	reup = fopen("Produto.txt","w");
	if(produto == NULL){
		printf("Erro para atualizar arquivo");
	}
	else{
		i=1;
		aux1 = fscanf(produto,"%s %f %d %d\n",&nomeProduto,&precoUnitario,&estoque,&id);
		while( aux1 != EOF){
			if(idProdutoSelect!=i){
				fprintf(reup,"%s %f %d %d\n",nomeProduto,precoUnitario,estoque,idNew);
			}
			else{
				printf("Linha deletada com sucesso!");
		        idNew--;
			}
			idNew++;
			i=i+1;
			aux1 = fscanf(produto,"%s %f %d %d\n",&nomeProduto,&precoUnitario,&estoque,&id);
			
		}
		fclose(produto);
		fclose(reup);
		remove("Produtos.txt");
		rename("Produto.txt","Produtos.txt");
	}
	
}

void deleteCv(int idCvSelect){
	int id,idNew=1,idCliente,i,aux1,quantidade,idProduto;
	FILE *cv;
	FILE *reup;
	cv = fopen("Vendas.txt","r");
	reup = fopen("Venda.txt","w");
	if(cv == NULL){
		printf("Erro para atualizar arquivo");
	}
	else{
		i=1;
		aux1 = fscanf(cv,"%d %d %d %d\n",&id,&idCliente,&idProduto,&quantidade);
	}
		while( aux1 != EOF){
			if(idCvSelect!=i){
				fprintf(reup,"%d %d %d %d\n",idNew,idCliente,idProduto,quantidade);
			}
			else{
				printf("Linha deletada com sucesso!");
		        idNew--;
			}
			idNew++;
			i=i+1;
			aux1 = fscanf(cv,"%d %d %d %d\n",&id,&idCliente,&idProduto,&quantidade);
			
		}
		fclose(cv);
		fclose(reup);
		remove("Vendas.txt");
		rename("Venda.txt","Vendas.txt");
	}
	

void quadroCadastroCliente(){
	
	printf("\t\t _____________________________\n");
	printf("\t\t|      Cadastro Cliente       |\n");
	printf("\t\t|                             |\n");
	
}

void quadroCadastroProdutoExt(){
	
	printf("\t\t ________________________________________\n");
	printf("\t\t|            Cadastro Produto            |\n");
	printf("\t\t|                                        |\n");
	
}

void quadroCadastroProduto(){
	
	printf("\t\t _____________________________\n");
	printf("\t\t|      Cadastro Produto       |\n");
	printf("\t\t|                             |\n");
	
}

void quadroCadastroCv(){
	
	printf("\t\t _____________________________\n");
	printf("\t\t|    Cadastro Compra/Venda    |\n");
	printf("\t\t|                             |\n");
	
}

void quadroCadastroCvExt(){
	
	printf("\t\t _____________________________________________________________\n");
	printf("\t\t|                  Cadastro Compra/Venda                      |\n");
	printf("\t\t|                                                             |\n");
	
}

int idadeCal(int anoNascimento){
	int idade;
	idade = 2021-anoNascimento;
	return idade;
}

void listarClientes(){
	int i,aux,idade,id;
	char primeiroNome[50],segundoNome[50],cidade[50];
	FILE *cliente;
	cliente = fopen("Clientes.txt","r");
	if(cliente== NULL){
		printf("Erro na listagem dos clientes!");
	}
	else{
		i=1;
		aux = fscanf(cliente,"%s %s %s %d %d\n",&primeiroNome,&segundoNome,&cidade,&idade,&id);
		while(aux!= EOF){
			i = i+1;
			printf("\t\t|_____________________________________________________________|\n");
			printf("\t\t|Nome:%s %s |Idade:%d | Cidade:%s | ID:%d|\n",primeiroNome,segundoNome,idade,cidade,id);
			printf("\t\t|_____________________________________________________________|\n");
			aux = fscanf(cliente,"%s %s %s %d %d\n",&primeiroNome,&segundoNome,&cidade,&idade,&id);
			}
			fclose(cliente);
		}
		fclose(cliente);
	};

void listarProdutos(){
	int i,id,quantidade,aux;
	float preco;
	char nomeProduto[50];
	FILE *produto;
	produto = fopen("Produtos.txt","r");
	if(produto== NULL){
		printf("Erro na listagem dos clientes!");
	}
	else{
		i=1;
		aux = fscanf(produto,"%s %f %d %d",&nomeProduto,&preco,&quantidade,&id);
		while(aux!= EOF){
			i = i+1;
			printf("\t\t|_____________________________________________________________|\n");
			printf("\t\t|Produto=%s | Preço(R$)=%.2f | Estoque=%d | ID=%d|\n",nomeProduto,preco,quantidade,id);
			printf("\t\t|_____________________________________________________________|\n");
			aux = fscanf(produto,"%s %f %d %d",&nomeProduto,&preco,&quantidade,&id);
			}
			fclose(produto);
		}
}

void listarCv(){
	int i,id,idCliente,idProduto,quantidade,aux;
	FILE *vendas;
	vendas = fopen("Vendas.txt","r");
	if(vendas == NULL){
		printf("Erro na listagem das Compras/Vendas");
		}
	else{
		i=1;
		aux = fscanf(vendas,"%d %d %d %d",&id,&idCliente,&idProduto,&quantidade);
		while(aux != EOF){
			i = i+1;
			printf("\t\t|___________________________________________________________________________|\n");
			printf("\t\t|ID cliente:%d | ID produto:%d | Quantidade Comprada:%d | ID compra:%d|\n",idCliente,idProduto,quantidade,id);
			printf("\t\t|___________________________________________________________________________|\n");
			aux = fscanf(vendas,"%d %d %d %d",&id,&idCliente,&idProduto,&quantidade);
		}
		fclose(vendas);
	}
	}

void cadastroCliente(Cliente novo){
	char primeiroNome[50],segundoNome[50],cidade[50];
	int id,anoNs;
	system("cls");
	quadroCadastroCliente();	
	printf("\t\tNome do cliente:");
	scanf("%s",&primeiroNome);
	system("cls");
	quadroCadastroCliente();
	printf("\t\tSobrenome do cliente:");
	scanf("%s",&segundoNome);
	system("cls");
	quadroCadastroCliente();
	printf("\t\tAno de nascimento do cliente:");
	scanf("%d",&anoNs);	
	system("cls");
	quadroCadastroCliente();
	printf("\t\tCidade de residencia:");
	scanf("%s",&cidade);
	system("cls");
	id = idCliente();
	novo = setCliente(idCliente(),idadeCal(anoNs),primeiroNome,segundoNome,cidade);
	quadroCadastroCliente();
	printf("\t\t Cliente id=%d cadastrado",id);
	getch();
	system("cls");
	}

void cadastroProduto(Produto novo){
	int id,estoque;
	float precoUnitario;
	char nomeProduto[50];
	system("cls");
	quadroCadastroProdutoExt();
	printf("\t\tNome produto(separar com \"_\"):");
	scanf("%s",&nomeProduto);
	system("cls");
	quadroCadastroProduto();
	printf("\t\tPreço do produto:");
	scanf("%f",&precoUnitario);
	system("cls");
	quadroCadastroProduto();
	printf("\t\tQuantidade em estoque:");
	scanf("%d",&estoque);
	system("cls");
	id = idProdutos();
	novo = setProduto(idProdutos(),nomeProduto,precoUnitario,estoque);
	quadroCadastroProduto();
	printf("\t\t Produto id=%d cadastrado",id);
	getch();
	system("cls");
}

void cadastroCv(CompraVenda novo){
	int id,idCliente,idProduto,quantidade;
	system("cls");
	quadroCadastroCvExt();
	listarClientes();
	printf("\n\t\tID do cliente efetuando a compra:");
	scanf("%d",&idCliente);
	system("cls");
	quadroCadastroCvExt();
	listarProdutos();
	printf("\n\t\tID do produto comprado:");
	scanf("%d",&idProduto);
	system("cls");
	quadroCadastroCvExt();
	listarProdutos();
	printf("\n\t\tQuantidade de itens desejados:");
	scanf("%d",&quantidade);
	id = idCv();
	novo = setCv(idCv(),quantidade,idCliente,idProduto);
	quadroCadastroCv();
	printf("\t\tVenda id=%d cadastrada",id);
	getch();
	system("cls");
}

void quadroAtualizar(){
	printf("\t\t _____________________________________________________________\n");
	printf("\t\t|                      Atualizar dados                        |\n");
}

int quadroAtualizarClienteTal(int idCliente){
	system("cls");
	int opcao;
	printf("\t\t ___________________________________________\n");
	printf("\t\t|           Cliente %d selecionado           | \n",idCliente);
	printf("\t\t|       Selecione qual dado atualizar:      | \n");
	printf("\t\t|                                           |\n");
	printf("\t\t|      1- Nome                              |\n");
	printf("\t\t|                                           |\n");
	printf("\t\t|      2- Sobrenome                         |\n");
	printf("\t\t|                                           |\n");
	printf("\t\t|      3- Cidade                            |\n");
	printf("\t\t|                                           |\n"); 
	printf("\t\t|      4- Idade                             |\n");  
	printf("\t\t|                                           |\n");
	printf("\t\t|               Opção:");
	scanf("%d",&opcao);
	return opcao;
	
}

int quadroAtualizarProdutoTal(int idProduto){
	system("cls");
	int opcao;
	printf("\t\t ___________________________________________\n");
	printf("\t\t|           Produto %d selecionado          | \n",idProduto);
	printf("\t\t|       Selecione qual dado atualizar:      | \n");
	printf("\t\t|                                           |\n");
	printf("\t\t|      1- Nome Produto                      |\n");
	printf("\t\t|                                           |\n");
	printf("\t\t|      2- Preço Unitario                    |\n");
	printf("\t\t|                                           |\n");
	printf("\t\t|      3- Estoque                           |\n");
	printf("\t\t|                                           |\n");
	printf("\t\t|               Opção:");
	scanf("%d",&opcao);
	return opcao;
	
}

int quadroAtualizarCvTal(int idCv){
	system("cls");
	int opcao;
	printf("\t\t ___________________________________________\n");
	printf("\t\t|         Compra/Venda %d selecionado       | \n",idCv);
	printf("\t\t|       Selecione qual dado atualizar:      | \n");
	printf("\t\t|                                           |\n");
	printf("\t\t|      1- Id cliente                        |\n");
	printf("\t\t|                                           |\n");
	printf("\t\t|      2- Id produto                        |\n");
	printf("\t\t|                                           |\n");
	printf("\t\t|      3- Quantidade                        |\n");
	printf("\t\t|                                           |\n");
	printf("\t\t|               Opção:");
	scanf("%d",&opcao);
	return opcao;
	
}

void atualizarCliente(){
	char primeiroNome[50],segundoNome[50],cidade[50],newPrimeiroNome[50],newSegundoNome[50],newCidade[50];
	int id,idade,opcao,idClienteSelect,newIdade,aux1,i;
	system("cls");
	quadroAtualizar();
	listarClientes();
	printf("\t\tSelecione o id do cliente que deseja atualizar:");
	scanf("%d",&idClienteSelect);
	system("cls");
	switch(quadroAtualizarClienteTal(idClienteSelect)){
		case 1:
			quadroAtualizar();
			printf("\t\tQual o novo nome:");
			scanf("%s",&newPrimeiroNome);
			FILE *cliente1;
			FILE *reup1;
			cliente1 = fopen("Clientes.txt","r");
			reup1 = fopen("Cliente.txt","w");
			if(cliente1 == NULL){
				printf("Erro para atualizar arquivo");
			}
			else{
				i=1;
				aux1 = fscanf(cliente1,"%s %s %s %d %d\n",&primeiroNome,&segundoNome,&cidade,&idade,&id);
			while( aux1 != EOF){
				if(idClienteSelect == i){
					fprintf(reup1,"%s %s %s %d %d\n",newPrimeiroNome,segundoNome,cidade,idade,id);
				}	
				else{
					fprintf(reup1,"%s %s %s %d %d\n",primeiroNome,segundoNome,cidade,idade,id);
				}
			i=i+1;
			aux1 = fscanf(cliente1,"%s %s %s %d %d\n",&primeiroNome,&segundoNome,&cidade,&idade,&id);
			}
			fclose(cliente1);
			fclose(reup1);
			remove("Clientes.txt");
			rename("Cliente.txt","Clientes.txt");
	}
			break;
		case 2:
			quadroAtualizar();
			printf("\t\tQual o novo sobrenome:");
			scanf("%s",&newSegundoNome);
			FILE *cliente2;
			FILE *reup2;
			cliente2 = fopen("Clientes.txt","r");
			reup2 = fopen("Cliente.txt","w");
			if(cliente2 == NULL){
				printf("Erro para atualizar arquivo");
			}
			else{
				i=1;
				aux1 = fscanf(cliente2,"%s %s %s %d %d\n",&primeiroNome,&segundoNome,&cidade,&idade,&id);
			while( aux1 != EOF){
				if(idClienteSelect == i){
					fprintf(reup2,"%s %s %s %d %d\n",primeiroNome,newSegundoNome,cidade,idade,id);
				}	
				else{
					fprintf(reup2,"%s %s %s %d %d\n",primeiroNome,segundoNome,cidade,idade,id);
				}
			i=i+1;
			aux1 = fscanf(cliente2,"%s %s %s %d %d\n",&primeiroNome,&segundoNome,&cidade,&idade,&id);
			}
			fclose(cliente2);
			fclose(reup2);
			remove("Clientes.txt");
			rename("Cliente.txt","Clientes.txt");
	}
			break;
		case 3:
			quadroAtualizar();
			printf("\t\tQual a nova cidade:");
			scanf("%s",&newCidade);
			FILE *cliente3;
			FILE *reup3;
			cliente3 = fopen("Clientes.txt","r");
			reup3 = fopen("Cliente.txt","w");
			if(cliente3 == NULL){
				printf("Erro para atualizar arquivo");
			}
			else{
				i=1;
				aux1 = fscanf(cliente3,"%s %s %s %d %d\n",&primeiroNome,&segundoNome,&cidade,&idade,&id);
			while( aux1 != EOF){
				if(idClienteSelect == i){
					fprintf(reup3,"%s %s %s %d %d\n",primeiroNome,segundoNome,newCidade,idade,id);
				}	
				else{
					fprintf(reup3,"%s %s %s %d %d\n",primeiroNome,segundoNome,cidade,idade,id);
				}
			i=i+1;
			aux1 = fscanf(cliente3,"%s %s %s %d %d\n",&primeiroNome,&segundoNome,&cidade,&idade,&id);
			}
			fclose(cliente3);
			fclose(reup3);
			remove("Clientes.txt");
			rename("Cliente.txt","Clientes.txt");
			break;
	}
		case 4:
			quadroAtualizar();
			printf("\t\tQual a nova idade:");
			scanf("%d",&newIdade);
			FILE *cliente4;
			FILE *reup4;
			cliente4 = fopen("Clientes.txt","r");
			reup4 = fopen("Cliente.txt","w");
			if(cliente4 == NULL){
				printf("Erro para atualizar arquivo");
			}
			else{
				i=1;
				aux1 = fscanf(cliente4,"%s %s %s %d %d\n",&primeiroNome,&segundoNome,&cidade,&idade,&id);
			while( aux1 != EOF){
				if(idClienteSelect == i){
					fprintf(reup4,"%s %s %s %d %d\n",primeiroNome,segundoNome,cidade,newIdade,id);
				}	
				else{
					fprintf(reup4,"%s %s %s %d %d\n",primeiroNome,segundoNome,cidade,idade,id);
				}
			i=i+1;
			aux1 = fscanf(cliente4,"%s %s %s %d %d\n",&primeiroNome,&segundoNome,&cidade,&idade,&id);
			}
			fclose(cliente4);
			fclose(reup4);
			remove("Clientes.txt");
			rename("Cliente.txt","Clientes.txt");
			break;
		}
	}
}

void atualizarProduto(){
	char nomeProduto[50],newNomeProduto[50];
	int id,opcao,idProdutoSelect,estoque,newEstoque,aux1,i;
	float precoUnitario,newPrecoUnitario;
	system("cls");
	quadroAtualizar();
	listarProdutos();
	printf("\t\tSelecione o id do produto que deseja atualizar:");
	scanf("%d",&idProdutoSelect);
	system("cls");
	switch(quadroAtualizarProdutoTal(idProdutoSelect)){
		case 1:
			quadroAtualizar();
			printf("\t\tQual o novo nome:");
			scanf("%s",&newNomeProduto);
			FILE *produto1;
			FILE *reup1;
			produto1 = fopen("Produtos.txt","r");
			reup1 = fopen("Produto.txt","w");
			if(produto1 == NULL){
				printf("Erro para atualizar arquivo");
			}
			else{
				i=1;
				aux1 = fscanf(produto1,"%s %f %d %d\n",&nomeProduto,&precoUnitario,&estoque,&id);
			while( aux1 != EOF){
				if(idProdutoSelect == i){
					fprintf(reup1,"%s %f %d %d\n",newNomeProduto,precoUnitario,estoque,id);
				}	
				else{
					fprintf(reup1,"%s %f %d %d\n",nomeProduto,precoUnitario,estoque,id);
				}
			i=i+1;
			aux1 = fscanf(produto1,"%s %f %d %d\n",&nomeProduto,&precoUnitario,&estoque,&id);
			}
			fclose(produto1);
			fclose(reup1);
			remove("Produtos.txt");
			rename("Produto.txt","Produtos.txt");
	}
			break;
		case 2:
			quadroAtualizar();
			printf("\t\tQual o novo preço:");
			scanf("%f",&newPrecoUnitario);
			FILE *produto2;
			FILE *reup2;
			produto2 = fopen("Produtos.txt","r");
			reup2 = fopen("Produto.txt","w");
			if(produto2 == NULL){
				printf("Erro para atualizar arquivo");
			}
			else{
				i=1;
				aux1 = fscanf(produto2,"%s %f %d %d\n",&nomeProduto,&precoUnitario,&estoque,&id);
			while( aux1 != EOF){
				if(idProdutoSelect == i){
					fprintf(reup2,"%s %f %d %d\n",nomeProduto,newPrecoUnitario,estoque,id);
				}	
				else{
					fprintf(reup2,"%s %f %d %d\n",nomeProduto,precoUnitario,estoque,id);
				}
			i=i+1;
			aux1 = fscanf(produto2,"%s %f %d %d\n",&nomeProduto,&precoUnitario,&estoque,&id);
			}
			fclose(produto2);
			fclose(reup2);
			remove("Produtos.txt");
			rename("Produto.txt","Produtos.txt");
	}
			break;
		case 3:
			quadroAtualizar();
			printf("\t\tQual o novo estoque(Quantidade completa):");
			scanf("%d",&newEstoque);
			FILE *produto3;
			FILE *reup3;
			produto3 = fopen("Produtos.txt","r");
			reup3 = fopen("Produto.txt","w");
			if(produto3 == NULL){
				printf("Erro para atualizar arquivo");
			}
			else{
				i=1;
				aux1 = fscanf(produto3,"%s %f %d %d\n",&nomeProduto,&precoUnitario,&estoque,&id);
			while( aux1 != EOF){
				if(idProdutoSelect == i){
					fprintf(reup3,"%s %f %d %d\n",nomeProduto,precoUnitario,newEstoque,id);
				}	
				else{
					fprintf(reup3,"%s %f %d %d\n",nomeProduto,precoUnitario,estoque,id);
				}
			i=i+1;
			aux1 = fscanf(produto3,"%s %f %d %d\n",&nomeProduto,&precoUnitario,&estoque,&id);
			}
			fclose(produto3);
			fclose(reup3);
			remove("Produtos.txt");
			rename("Produto.txt","Produtos.txt");
			break;
	}
	}
}
	
void atualizarCv(){
	int id,opcao,idCvSelect,quantidade,newQuantidade,aux1,i,idCliente,newIdCliente,idProduto,newIdProduto;
	system("cls");
	quadroAtualizar();
	listarCv();
	printf("\t\tSelecione o id da Compra/Venda que deseja atualizar:");
	scanf("%d",&idCvSelect);
	system("cls");
	switch(quadroAtualizarCvTal(idCvSelect)){
		case 1:
			quadroAtualizar();
			printf("\t\tQual o novo Id CLIENTE:");
			scanf("%d",&newIdCliente);
			FILE *cv1;
			FILE *reup1;
			cv1 = fopen("Vendas.txt","r");
			reup1 = fopen("Venda.txt","w");
			if(cv1 == NULL){
				printf("Erro para atualizar arquivo");
			}
			else{
				i=1;
				aux1 = fscanf(cv1,"%d %d %d %d\n",&id,&idCliente,&idProduto,&quantidade);
			while( aux1 != EOF){
				if(idCvSelect == i){
					fprintf(reup1,"%d %d %d %d\n",id,newIdCliente,idProduto,quantidade);
				}	
				else{
					fprintf(reup1,"%d %d %d %d\n",id,idCliente,idProduto,quantidade);
				}
			i=i+1;
			aux1 = fscanf(cv1,"%d %d %d %d\n",&id,&idCliente,&idProduto,&quantidade);
			}
			fclose(cv1);
			fclose(reup1);
			remove("Vendas.txt");
			rename("Venda.txt","Vendas.txt");
	}
			break;
		case 2:
			quadroAtualizar();
			printf("\t\tQual o novo Id PRODUTO:");
			scanf("%d",&newIdProduto);
			FILE *cv2;
			FILE *reup2;
			cv2 = fopen("Vendas.txt","r");
			reup2 = fopen("Venda.txt","w");
			if(cv2 == NULL){
				printf("Erro para atualizar arquivo");
			}
			else{
				i=1;
				aux1 = fscanf(cv2,"%d %d %d %d\n",&id,&idCliente,&idProduto,&quantidade);
			while( aux1 != EOF){
				if(idCvSelect == i){
					fprintf(reup2,"%d %d %d %d\n",id,idCliente,newIdProduto,quantidade);
				}	
				else{
					fprintf(reup2,"%d %d %d %d\n",id,idCliente,idProduto,quantidade);
				}
			i=i+1;
			aux1 = fscanf(cv2,"%d %d %d %d\n",&id,&idCliente,&idProduto,&quantidade);
			}
			fclose(cv2);
			fclose(reup2);
			remove("Vendas.txt");
			rename("Venda.txt","Vendas.txt");
	}
			break;
		case 3:
			quadroAtualizar();
			printf("\t\tQual a quantidade comprada(Quantidade completa):");
			scanf("%d",&newQuantidade);
			FILE *cv3;
			FILE *reup3;
			cv3 = fopen("Vendas.txt","r");
			reup3 = fopen("Venda.txt","w");
			if(cv3 == NULL){
				printf("Erro para atualizar arquivo");
			}
			else{
				i=1;
				aux1 = fscanf(cv3,"%d %d %d %d\n",&id,&idCliente,&idProduto,&quantidade);
			while( aux1 != EOF){
				if(idCvSelect == i){
					fprintf(reup3,"%d %d %d %d\n",id,idCliente,idProduto,newQuantidade);
				}	
				else{
					fprintf(reup3,"%d %d %d %d\n",id,idCliente,idProduto,quantidade);
				}
			i=i+1;
			aux1 = fscanf(cv3,"%d %d %d %d\n",&id,&idCliente,&idProduto,&quantidade);
			}
			fclose(cv3);
			fclose(reup3);
			remove("Vendas.txt");
			rename("Venda.txt","Vendas.txt");
			break;
	}
	}
}
	
bool controleEstoque(int idProdutoCadastro,int quantidadeComprada){
	int i,auxP,auxC,idCv,idProduto,estoque,idCliente;
	float precoUnitario;
	bool acesso;
	char nomeProduto[50];
	FILE *cv1;
	FILE *produto;
	FILE *produtochange;
	cv1 = fopen("Vendas.txt","r");
	produto = fopen("Produtos.txt","r");
	produtochange = fopen("Produto.txt","w");
	if(cv1 == NULL || produto == NULL || produtochange == NULL){
		printf("Erro na abertura do arquivo!");
	}
	else{
		i = 1;
		auxP = fscanf(produto,"%s %f %d %d\n",&nomeProduto,&precoUnitario,&estoque,&idProduto);
		while(auxP != EOF){
			if(idProduto == idProdutoCadastrado){
				acesso == true;
				
			}
			else{
				auxP = fscanf(produto,"%s %f %d %d\n",&nomeProduto,&precoUnitario,&estoque,&idProduto);
				i = i+1;
			}
			printf("Id produto inválido!");
			acesso == false;
		}
	}
	return acesso;
}

int tabelaInicial(int opcao){
	system("cls");
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
	system("cls");
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
	return opcao;
};

int subTabelaProdutos(int opcao){
	system("cls");
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
	return opcao;
};

int subTabelaCp(int opcao){
	system("cls");
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
							getch();
							break;
						case 3:
							atualizarCliente();
							break;
						case 4:
							deleteCliente(idDeletar());
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
							getch();
							break;
						case 3:
							atualizarProduto();
							break;
						case 4:
							deleteProduto(idDeletar());
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
							CompraVenda novo;
							cadastroCv(novo);
							break;
						case 2:
							listarCv();
							getch();
							break;
						case 3:
							atualizarCv();
							break;
						case 4:
							deleteCv(idDeletar());
							break;
						case 5:
							subs=false;
							break;
					};
				}
				break;
			case 4:
				inicial=false;
				break;
		}
	}
	return 0;
}
