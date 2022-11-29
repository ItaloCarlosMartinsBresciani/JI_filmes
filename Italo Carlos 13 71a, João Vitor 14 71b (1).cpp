/*
CTI-2020
14- João Vitor M. Duque, 71B
13-Italo Carlos Martins Bresciani, 71A

email: ariane.scarelli@unesp.br
senha: nota10
*/

//bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>
#include <iostream>
#include<string.h>

static int __BACKGROUND = 1;
static int __FOREGROUND = LIGHTGRAY;

//Estrutura
struct stCanal
{
	int codigo;
	char nome_canal[50];
	struct stData
	{
		int dia;
    	int mes;
    	int ano;
	}criacao;

	char genero[25];
	int num_videos;
	char exclusao;
	char redes_sociais[25];
	char frequencia_videos[20];
}JI_filmes; //nome da plataforma

//Ponteiro
FILE *JIp;

//Cabeçalhos
void gotoxy(int, int);
void textcolor (int, int);
int som(int);
void login(char[], char[]);
void abrir_arquivo(char[]);
void cadastro();
void menu();
void HideCursor(int);
void carregamento();
void logo();
int gera_codigo();
void salvamento();
void entrada_consistencia();
void menu_pesquisa();
void info_sistema();
void tabela_geral();
void pesquisa_canal();
void mostra_dados(int lin);
void tabela_canal();
void mascara();
void pesquisa_cod();
void pesquisa_genero();

main()
{
	setlocale(LC_ALL, "Portuguese");
	char senha_correta[50] = "nota10";
	char email_correto[50] = "ariane.scarelli@unesp.br"; 
	login(senha_correta, email_correto); //rotina de login para entrar no menu
	menu();
	
}

//Funções
void gotoxy(int x, int y) //função gotoxy
{
  COORD c;
  c.X = x - 1;
  c.Y = y - 1;
  SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void textcolor (int letras, int fundo) //função textcolor (muda a cor das letras)
{
	__FOREGROUND = letras;
    __BACKGROUND = fundo;
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),
    letras + (__BACKGROUND << 4));
}

void HideCursor(int aux)
{
	switch (aux) {
		case 0: {//ocultar cursor
			CONSOLE_CURSOR_INFO cursor = {1, FALSE};
			SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
			break;
		}
		case 1: {//apresentar cursor
			CONSOLE_CURSOR_INFO cursor = {1, TRUE};
			SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
			break;
		}
	}
}


void menu_pesquisa()
{
		HideCursor(0);
		textcolor(4,15); 
		system("cls");
		logo();
		textcolor(4,15); 
		char p;
		int linha=13;
		int sair;
		do{
		
		sair=1;
		gotoxy(40,1); printf("-----------MENU DE OPÇÕES DA PESQUISA-----------");
		gotoxy(40,13);  printf("Todos os dados da pesquisa");        
		gotoxy(40,15);  printf("Pesquisa por código");
		gotoxy(40,17);  printf("Pesquisa por canal");
		gotoxy(40,19);  printf("Pesquisa por gênero");
		gotoxy(40,21);  printf("Voltar");
		gotoxy(39,linha); printf("%c", 62);          
		p=getch();
		gotoxy(39,linha); printf(" ");
		
			switch(p)
		{
			case 72 :                              //setinha up
				linha-=2;
				if(linha<13)
				{
					linha=21;	
				}
				gotoxy(39,linha); printf("%c", 62);
				break;
			case 80 :                              //setinha down
				linha+=2;
				if(linha>21)
				{
					linha=13;
				}
				gotoxy(39,linha); printf("%c", 62);
				break;
		}
			switch(p)
		{
			case 13: // caso aperte enter
				if(linha==13)
				{
					gotoxy(39,23);printf("Você optou por ver todos os dados da pesquisa!");          
				//	Sleep(2000);
					carregamento();	
					tabela_geral();				
				}
				else
				if(linha==15)
				{
					gotoxy(39,23);printf("Você optou para pesquisar por código!");
				//	Sleep(2000);
					carregamento();
					pesquisa_cod();
				}
				else
				if(linha==17)
				{
					gotoxy(39,23);printf("Você optou para pesquisar por canal!");
					Sleep(2000);
					carregamento();	
					pesquisa_canal();
					system("cls");
					logo();
					textcolor(4,15);
					HideCursor(0);
					
				}
				else
				if(linha==19)
				{
					gotoxy(39,23);printf("Você optou para pesquisar por gênero!");
					Sleep(2000);
					carregamento();	
				    pesquisa_genero();
				    system("cls");
					logo();
					textcolor(4,15);
					HideCursor(0);
					
				}
				else
				if(linha==21)
				{
					system("cls");
					Sleep(2000);
					sair=0;
					system("cls");
					carregamento();
					logo();
					textcolor(4,15);
				}
		}
	}while (sair);
	
}
	
		



void carregamento()
{
	HideCursor(0);
	system("cls");
	gotoxy(42,16); printf("Loading.");
	Sleep(100);
	gotoxy(51,16); printf(".");
	Sleep(100);
	gotoxy(53,16); printf(".");
	Sleep(100);
	system("cls");
	HideCursor(1);
}
void logo()
{
	textcolor(4,4); //Yt
	
	gotoxy(20,3); printf("xxxxxxxxxxxxxxxx");
	gotoxy(20,4); printf("xxxxxxxxxxxxxxxx");
	
	gotoxy(20,5); printf("xxxxx");
	gotoxy(28,5); printf("xxxxxxxx");
	
	gotoxy(20,6); printf("xxxxx");
	gotoxy(30,6); printf("xxxxxx");
	
	gotoxy(20,7); printf("xxxxx");
	gotoxy(30,7); printf("xxxxxx");
	
	gotoxy(20,8); printf("xxxxx");
	gotoxy(28,8); printf("xxxxxxxx");
	
	gotoxy(20,9); printf("xxxxxxxxxxxxxxxx");
	gotoxy(20,10); printf("xxxxxxxxxxxxxxxx");
	
	textcolor(0,0);
	
	gotoxy(41,3); printf("----------");  //J
	gotoxy(45,4); printf("xx");
	gotoxy(45,5); printf("xx");
	gotoxy(45,6); printf("xx");
	gotoxy(45,7); printf("xx");
	gotoxy(45,8); printf("xx");
	gotoxy(45,9); printf("xx");
	gotoxy(44,9); printf("xx");
	gotoxy(43,9); printf("xx");
	gotoxy(42,9); printf("xx");
	gotoxy(41,9); printf("xx");
	gotoxy(41,8); printf("xx");
	
	gotoxy(49,9); printf("xx");// .
	
	gotoxy(54,4); printf("xx");// I
	gotoxy(54,5); printf("xx");
	gotoxy(54,6); printf("xx");
	gotoxy(54,7); printf("xx");
	gotoxy(54,8); printf("xx");
	gotoxy(54,9); printf("xx");
	gotoxy(54,2); printf("xx");
	
	gotoxy(58,9); printf("xx");// .
	
	gotoxy(66,9); printf("xx"); //F
	gotoxy(66,8); printf("xx");
	gotoxy(66,7); printf("xx");
	gotoxy(66,6); printf("xxxxx");
	gotoxy(66,5); printf("xx");
	gotoxy(66,4); printf("xx");
	gotoxy(66,3); printf("xxxxxxxx");
	
	gotoxy(75,4); printf("xx");// I
	gotoxy(75,5); printf("xx");
	gotoxy(75,6); printf("xx");
	gotoxy(75,7); printf("xx");
	gotoxy(75,8); printf("xx");
	gotoxy(75,9); printf("xx");
	gotoxy(75,2); printf("xx");
	
	gotoxy(79,9); printf("xxxxxx"); //L
	gotoxy(79,8); printf("xx");
	gotoxy(79,7); printf("xx");
	gotoxy(79,6); printf("xx");
	gotoxy(79,5); printf("xx");
	gotoxy(79,4); printf("xx");
	gotoxy(79,3); printf("xx");
	
	gotoxy(86,9); printf("xx"); //M
	gotoxy(86,8); printf("xx");
	gotoxy(86,7); printf("xx");
	gotoxy(86,6); printf("xx");
	gotoxy(86,5); printf("xx");
	gotoxy(86,4); printf("xx");
	gotoxy(86,3); printf("xx");
	
	gotoxy(87,3); printf("xx");
	gotoxy(88,4); printf("xx");
	gotoxy(89,5); printf("xx");
	
	gotoxy(90,5); printf("xx");
	gotoxy(91,4); printf("xx");
	gotoxy(92,3); printf("xx");
	gotoxy(93,3); printf("xx");
	gotoxy(93,4); printf("xx");
	gotoxy(93,5); printf("xx");
	gotoxy(93,6); printf("xx");
	gotoxy(93,7); printf("xx");
	gotoxy(93,8); printf("xx");
	gotoxy(93,9); printf("xx");

	
	
	
	
}

int som(int f) //somzinho
{
    Beep(f,170);
    return 0;
}

void login(char corretasenha[50], char corretoemail[50]) //função do cadastro (valida o login e senha)
{

		textcolor(4,15); 
		system("cls");
		logo();
		textcolor(4,15); 
		for(int j=500;j<3000;j+=500)
        som(j);
        
		char email[50];
		char senha[50], c;
		char apagar_senha[25] = {                         };
		
		int cont = 0;	
	do{
		logo();
		textcolor(4,15);
		gotoxy(30,14); printf("+---------------------------------------------+\n");
		gotoxy(30,16); printf("+---------------------------------------------+\n");
		gotoxy(30,18); printf("+---------------------------------------------+\n");
		gotoxy(30,15); printf("¦ Digite seu E-mail:                          ¦");                        
		gotoxy(30,17); printf("¦ Digite sua senha:                           ¦");
		gotoxy(50,15); scanf("%s", email);
		gotoxy(50,17); 
		do //oculta a senha digitada, aparecem apenas asteríscos como dígitos na tela.
		{
			fflush(stdin);
			c = getch();
			if (c == ' ' || c== '\r')
				senha[cont] = senha[cont];
			else
			{
				senha[cont] = c;
				printf("*");
			}
			cont++;
		}
		while(c != '\r' && cont <= 25);
		
		if (strcmp(email, corretoemail)!=0 || strcmp(senha, corretasenha)!=0)
		{
	
			if (strcmp(email, corretoemail)!=0)
			{
				gotoxy(80,21); printf("E-mail incorreto!\n");	
			}
			if (strcmp(senha, corretasenha)!=0) 
			{
				gotoxy(80,22);printf("Senha incorreta!");	
				cont = 0;
				strcpy(senha,apagar_senha);
			}
		}
		Sleep(1000);
		system("cls");
	
	}while(strcmp(email, corretoemail)!=0 || strcmp(senha, corretasenha)!=0);
	carregamento();
}
	void menu()
	{
		textcolor(4,15); 
		system("cls");
		logo();
		textcolor(4,15); 
		char p;
		int lin=13;
		int sair;
		
		do
	{
		
		HideCursor(0);
		sair=1;
		gotoxy(40,10); printf("+------------------+\n");
		gotoxy(40,12); printf("+------------------+\n");
		gotoxy(40,11);printf("|Menu do J.I Filmes|");
		
		gotoxy(40,13);printf("Pesquisa");        
		gotoxy(40,15);printf("Cadastro");
		gotoxy(40,17);printf("Inf. do sistema");
		gotoxy(40,19);printf("Sair");
		gotoxy(39,lin); printf("%c", 62);          
		p=getch();
		gotoxy(39,lin); printf(" ");
		
		switch(p)
		{
			case 72 :                              //setinha pra cima
				lin-=2;
				if(lin<13)
				{
					lin=19;	
				}
				gotoxy(39,lin); printf("%c", 62);
				break;
			case 80 :                              //setinha pra baixo
				lin+=2;
				if(lin>19)
				{
					lin=13;
				}
				gotoxy(39,lin); printf("%c", 62);
				break;
		}
		
		switch(p)
		{
			char sai;
			case 13: // enter
				if(lin==13)
				{
					gotoxy(39,23);printf("Você optou pela Pesquisa!");          
					//Sleep(2000);
					gotoxy(39,23);printf("                             ");
					carregamento();	
						menu_pesquisa();
						
									
				}
				else
				if(lin==15)
				{
					gotoxy(39,23);printf("Você optou pelo Cadastro!");
					//Sleep(2000);
					gotoxy(39,23);printf("                             ");
					carregamento();	
					cadastro();//página de cadastro
				}
				else
				if(lin==17)
				{
					gotoxy(39,23);printf("Você optou pela Inf. do sistema!");
					Sleep(2000);
					gotoxy(39,23);printf("                                    ");
					carregamento();	
					info_sistema();
				}
				else
				if(lin==19)
				{
					gotoxy(39,23);printf("Você escolheu Sair!");
					sair=0;
					system("cls");
					gotoxy(40,13); printf("Obrigado por usar este sitema! Dê f11 sempre!");
				}
		}

	}while(sair);
		
	}




void abrir_arquivo( const char modo[])
{
	if((JIp = fopen("JI_Filmes.bin",modo)) == NULL) 
	{
		gotoxy(18,11);printf("Erro na abertura do arquivo");
	    exit(1);
	}	
}
void cadastro()
{
	char saida;
	int aux_codigo;
	
	//criando máscara da página de cadastro
	do{
		abrir_arquivo("ab+"); //abre/cria o arquivo com uma tupla vazia
		gotoxy(40,2); printf("-----------CADASTRO DE CANAL-----------"); 
		gotoxy(10,5); printf("Código: %d",gera_codigo());
		aux_codigo = JI_filmes.codigo; // para o código ser salvo antes das consistências
		gotoxy(10,6); printf("Tecle ESC agora caso queira sair.");
		gotoxy(10,7); printf("Nome do canal:");
		gotoxy(10,8); printf("Data de criação: **/**/****");
		gotoxy(10,9); printf("Gênero:");
		gotoxy(10,10); printf("Número de vídeos:");
		gotoxy(10,11); printf("Redes sociais:");
		gotoxy(10,12); printf("Frequência de postagem:");
		
		textcolor(4,4); //Yt
	
		gotoxy(17,20); printf("xxxxxxxxxxxxxxxx");
		gotoxy(17,21); printf("xxxxxxxxxxxxxxxx");
	
		gotoxy(17,22); printf("xxxxx");
		gotoxy(25,22); printf("xxxxxxxx");
	
		gotoxy(17,23); printf("xxxxx");
		gotoxy(27,23); printf("xxxxxx");
	
		gotoxy(17,24); printf("xxxxx");
		gotoxy(27,24); printf("xxxxxx");
	
		gotoxy(17,25); printf("xxxxx");
		gotoxy(25,25); printf("xxxxxxxx");
		
		gotoxy(17,26); printf("xxxxxxxxxxxxxxxx");
		gotoxy(17,27); printf("xxxxxxxxxxxxxxxx");
		textcolor(4,15);
		//comandos de entrada de dados para os campos da struct e limpeza do buffer
		gotoxy(43,6); //rotina para caso o usuário queira sair
		saida = getch();
		if(saida == 27)
		{
			system("cls"); 
			carregamento();
			textcolor(4,15);  //máscara para o menu voltar com as cores e logo corretamente 
			system("cls");
			logo();
			textcolor(4,15);
			return;
		}
		 //entrada e consistência dos dados
		 entrada_consistencia();
		//salvamento dos dados, caso a resposta seja "sim"
		 JI_filmes.codigo = aux_codigo; // após a consistência, o valor volta corretamente para o salvamento
		salvamento();
		system("cls");
	}while(true);
}

int gera_codigo() //gera automaticamente uma chave primária para o usuário. Quanto menos ele escrever, melhor!
{
	int aux_codigo = 0;
	int cont = 0;
	rewind(JIp);
	do{
		cont++;
		aux_codigo = JI_filmes.codigo;
	}while(fread( &JI_filmes,sizeof(JI_filmes),1,JIp) == TRUE); //procura tupla com o maior número
	
	if (cont>1)
		JI_filmes.codigo = cont;
	else
		JI_filmes.codigo = cont++;
	
	return JI_filmes.codigo;
}

void salvamento()
{
	int col= 8; //essas duas variáveis serão usadas no díalogo de confirmação dos dados
	char seta;
	
	//diálogo de confirmação dos dados 
	gotoxy(10,15); printf("Deseja salvar os dados/?"); //máscara do diálogo
	gotoxy(10,17); printf("Sim");	gotoxy(20,17); printf("Não"); 
		
	do{
		HideCursor(0); //esconde o cursor
		gotoxy(col,17); printf(">");
		seta = getch();
		gotoxy(col,17); printf(" ");
				
		switch(seta)
		{
			case 75 : //setinha para a esquerda
				col-= 10; 
				if(col<8)
				{
					col=18;	
				}
				gotoxy(col,17); printf(">");
				break;
			case 77 :  //setinha para a direita
				col+=10;
				if(col>18)
				{
					col=8;
				}
				gotoxy(col,17); printf(">");
				break;
		}
	}while(seta != 13);
	//decisão de salvamento ou esquecimento
	if(col == 8)
	{
		if(fwrite(&JI_filmes, sizeof(JI_filmes), 1, JIp) != 1)
		{
			gotoxy(30,17); printf("Erro na escrita do arquivo.");
		}
		else
		{
			fflush(JIp);
			gotoxy(30,17); printf("Dados salvos com sucesso. Digite qualquer tecla para continuar.");
			fclose(JIp);
		}
	}
	else 
	{
		HideCursor(1); //liga o cursor novamente para digitar novos dados ou sair para o menu
		return;
	} 
	HideCursor(1);
	getch(); 
	
	if(fwrite(&JI_filmes, sizeof(JI_filmes), 1, JIp) != 1)
		{
			gotoxy(30,17); printf("Erro na escrita do arquivo.");
		}
		else
		{
			fflush(JIp);
			gotoxy(30,17); printf("Dados salvos com sucesso. Digite qualquer tecla para continuar.");
		}
} 

void entrada_consistencia()
{
	int flag; //flag será usada para indicar se o laço deve continuar ou não
	char aux[50];
	int auxiliar;
	
	do // nome do canal
	{
		gotoxy(25,7); gets(aux);
		if(strlen(aux) < 1)
		{
			gotoxy(40,7); printf("O nome deve conter pelo menos um caractere.");
			flag = 0;
		}
		else
			flag =1;
		rewind(JIp);
		while(fread( &JI_filmes,sizeof(JI_filmes),1,JIp) == 1) //procura tupla com nome correspondente
		{
			if(strcmp(JI_filmes.nome_canal,aux) == 0)
			{
				flag = 0;
				gotoxy(25,7); printf("                                                                                         ");
				gotoxy(40,7); printf("O nome já existente.");
			}
			else
			{
				flag =1;
			}
		}
		strcpy(JI_filmes.nome_canal,aux);	
		
							
	}while(flag == 0);
	
	do // dia de criação  
	{
		gotoxy(27,8); scanf("%d",&auxiliar); 		
		if(auxiliar<1 || auxiliar >31)
			{
				gotoxy(40,8); printf("O dia deve estar entre 1 e 31.");
				flag = 0;
			}
		else
			flag = 1;
		JI_filmes.criacao.dia = auxiliar;
	}while(flag == 0);
	
	
	do // mês de criação  
	{
		gotoxy(30,8); scanf("%d",&auxiliar);	
		if(auxiliar<1 || auxiliar >12)
			{
				gotoxy(40,8); printf("O mês deve estar entre 1 e 12.");
				flag = 0;
			}
		else
			flag = 1;
		JI_filmes.criacao.mes = auxiliar;
	}while(flag == 0);
	
	do // ano de criação  
	{
		gotoxy(33,8); scanf("%d",&auxiliar);	
		if(auxiliar<2000 || auxiliar >2020)
			{
				gotoxy(40,8); printf("O ano deve estar entre 2000 e 2020.");
				flag = 0;
			}
		else
			flag = 1;
		JI_filmes.criacao.ano = auxiliar;
	}while(flag == 0);
	
	do // gênero 
	{
		fflush(stdin);
		gotoxy(18,9); gets(aux);	
		if(strlen(aux) < 1)
			{
				gotoxy(40,9); printf("O gênero é um campo obrigatório.");
				flag = 0;
			}
		else
			flag = 1;
		strcpy(JI_filmes.genero, aux);
	}while(flag == 0);
	
	do // número de vídeos
	{
		gotoxy(28,10); scanf("%d",&auxiliar);	
		if(auxiliar <0)
			{
				gotoxy(40,10); printf("O número de vídeos não pode ser negativo ou decimal.");
				flag = 0;
			}
		else
			flag = 1;
		JI_filmes.num_videos = auxiliar;
	}while(flag == 0);

	do // redes sociais
	{
		fflush(stdin);
		gotoxy(25,11); gets(aux);	
		if(strlen(aux) < 1)
			{
				gotoxy(40,11); printf("Caso não haja redes sociais, digite \"Nenhuma\".");
				flag = 0;
			}
		else
			flag = 1;
		strcpy(JI_filmes.redes_sociais, aux);
	}while(flag == 0);

	do // frequência vídeos
	{
		fflush(stdin);
		gotoxy(34,12); gets(aux);	
		if(strlen(aux) < 1)
			{
				gotoxy(40,12); printf("Caso não vídeos, digite \"Nenhum\".");
				flag = 0;
			}
		else
			flag = 1;
		strcpy(JI_filmes.frequencia_videos, aux);
	}while(flag == 0);
	JI_filmes.exclusao = 'n';
}

void info_sistema()
{
	system("cls");
	gotoxy(50,4); printf("-----Informações do sistema-----");	
	gotoxy(25,7); printf("Nome da plataforma: J.I. Film");
	gotoxy(25,8); printf("Este programa foi desenvolvido pelos alunos João Vitor M. Duque, 71B;");
	gotoxy(25,9); printf("e Italo Carlos Martins Bresciani, 71A; para simular um programa para desenvolvedores");
	gotoxy(25,10); printf("de uma plataforma de vídeos. A professora Ariane Scarelli foi a mentora deste trabalho.");
	gotoxy(25,12); printf("Colégio Técnico Industrial \"Isaac Portal Roldán\", Bauru-SP.");
	//logo do trabalho
	textcolor(4,4); //Yt
	
	gotoxy(55,21); printf("xxxxxxxxxxxxxxxx");
	gotoxy(55,22); printf("xxxxxxxxxxxxxxxx");
	
	gotoxy(55,23); printf("xxxxx");
	gotoxy(63,23); printf("xxxxxxxx");

	gotoxy(55,24); printf("xxxxx");
	gotoxy(65,24); printf("xxxxxx");
	
	gotoxy(55,25); printf("xxxxx");
	gotoxy(65,25); printf("xxxxxx");

	gotoxy(55,26); printf("xxxxx");
	gotoxy(63,26); printf("xxxxxxxx");
		
	gotoxy(55,27); printf("xxxxxxxxxxxxxxxx");
	gotoxy(55,28); printf("xxxxxxxxxxxxxxxx");
	textcolor(4,15);
	//saída
	gotoxy(25,18); printf("Pressione qualquer tecla para sair ");
	getch();
	//máscara para o menu voltar com as cores e logo corretamente 
	system("cls"); 
	carregamento();
	textcolor(4,15);  
	system("cls");
	logo();
	textcolor(4,15);
	return;
}	

void tabela_geral()
{
	int cont = 0; //será usado para não ultrapassar o limite de dados por tabela (12)
	int lin = 7; //usado para definir a linha de cada dado
	int col = 0; //usado para não ultrapassar as grades da tabela
	char escolha = ' '; //usado para mudar de página ou sair da tabela
	
	do{
		abrir_arquivo("rb");
		mascara();
		gotoxy(2,1);  printf("                                                   TABELA GERAL                                                       ");
		
		while( !feof(JIp))
		{
			if(fread( &JI_filmes,sizeof(JI_filmes),1,JIp))
			{
				if(lin > 29)
				{
					do{
						gotoxy(2,2); printf("Pressione ENTER para a próxima página ou ESC para sair.");
						escolha = getch();
						switch(escolha)
						{
							case 27: //ESC
							{
								system("cls"); 
								carregamento();
								textcolor(4,15);  //máscara para o menu voltar com as cores e logo corretamente 
								system("cls");
								logo();
								textcolor(4,15);
								HideCursor(0);
								return;	
							}
							case 13: //ENTER
							{
								lin = 7;
								system("cls");
								mascara();
								break;
							}
						}
					}while(escolha != 27 && escolha != 13);	
				}
					
				
				
				 //cod
				gotoxy(5,lin); printf("%d",JI_filmes.codigo);
				
				//nome, mostrado apenas seus 18 primeiros caracteres
				for(int i = 0; i < 18 && JI_filmes.nome_canal[i] != '\0'; i++) 
				{
					gotoxy( col+10,lin); printf("%c",JI_filmes.nome_canal[i]); 
					col++ ;  
				}
				col = 0;
				
				//dd/mm/aaaa
				if(JI_filmes.criacao.dia < 10)
				{
					gotoxy(31,lin); printf("0%d",JI_filmes.criacao.dia);
				}
				else
				{
					gotoxy(31,lin); printf("%d",JI_filmes.criacao.dia);
				}
				
				if(JI_filmes.criacao.mes < 10)
				{
					gotoxy(34,lin); printf("0%d",JI_filmes.criacao.mes);
				}
				else
				{
					gotoxy(34,lin); printf("%d",JI_filmes.criacao.mes);	
				}
				gotoxy(37,lin); printf("%d",JI_filmes.criacao.ano);
				
				//gênero
				for(int i = 0; i < 15 && JI_filmes.genero[i] != '\0';i++)
				{
					gotoxy(col + 46,lin); printf("%c",JI_filmes.genero[i]);
					col++;
				}
				col = 0;
				
				//Num. vídeos
				gotoxy(63,lin); printf("%d",JI_filmes.num_videos);
				
				//Redes sociais
				for(int i = 0; i < 18 && JI_filmes.redes_sociais[i] != '\0';i++)
				{
					gotoxy(col+77,lin); printf("%c",JI_filmes.redes_sociais[i]);
					col++;
				}
				col = 0;
				
				//Freq. postagem
				for(int i = 0; i < 22 && JI_filmes.frequencia_videos[i] != '\0';i++)
				{
					gotoxy(col + 97,lin); printf("%c",JI_filmes.frequencia_videos[i]);
					col++;
				}
				col = 0;
				
				lin+=2;
			}
		}
		do{
			gotoxy(2,2); printf("Fim do arquivo. Pressione ESC para voltar ao menu ou ENTER para rever a tabela geral.");
			escolha = getch();
			switch(escolha)
			{
				case 27:
					system("cls"); 
					carregamento();
					textcolor(4,15);  //máscara para o menu voltar com as cores e logo corretamente 
					system("cls");
					logo();
					textcolor(4,15);
					HideCursor(0);
					return;
				case 13:
					rewind(JIp);
					lin = 7;
					break;
			}
		}while(escolha != 13 &&  escolha != 27);
		system("cls");
	}while(true);
	
}

void pesquisa_canal()
{
	
	int linha = 7; 
	int tecla;
	char nome_pes[50]; //Para entrada de nome a ser pesquisado
	char name[50];
	
	int cont = 0; 
	
	abrir_arquivo("rb");                                 
		gotoxy(2,3);printf("Caso tenha escolhido uma opção indesejada, aperte 'ESC' para sair.\n Se quiser prosseguir para a pesquisa por canal, selecione qualquer outra tecla...  ");
		tecla=getch();
		if(tecla == 27) 
		{
			
			system("cls"); 
			carregamento();
			textcolor(4,15);  
			system("cls");
			logo();
			textcolor(4,15);
			HideCursor(0);
			return;
		}
	tabela_canal(); 
	mascara();
	gotoxy(2,2);printf("Digite o nome do canal que deseja ser pesquisado: "); gotoxy(85,2); printf("----|Pesquisa por canal|----");
	gotoxy(51,2);gets(nome_pes);
	strcpy(name,nome_pes); 
	strlwr(nome_pes); 
	
	while( !feof(JIp) ) //Enquanto não for fim de arquivo
	{
       while(fread( &JI_filmes,sizeof(JI_filmes),1,JIp) == 1 && cont<24) 
		     
		{
			if(linha > 29) 
			{
				gotoxy(2,33);printf("Pressione uma tecla para continuar ou 2 vezes 'ESC' para sair...");
				fflush(stdin);
				tecla = getch();
				if(tecla == 27) 
					break;
				linha = 7; 
				system("cls");
				mascara();
				gotoxy(13,0); printf("Canal sendo pesquisado:");
				gotoxy(37,0);printf("%s",name); 
			}
			
			strlwr(JI_filmes.nome_canal); 
			if( (strstr(JI_filmes.nome_canal, nome_pes) != NULL )  
			  &&(JI_filmes.exclusao == 'n' ) )
			{
				mostra_dados(linha);
				linha+=2;
			}
		}
	}
	if(tecla != 27)
	{
		gotoxy(2,33);printf("Fim dos dados. Pressione qualquer tecla para voltar ao menu da pesquisa!");
		tecla = getch();		
	}
	fclose(JIp);
	
}

void mostra_dados(int lin)
{
	int col = 0;
	
	gotoxy(5,lin);printf("%d",JI_filmes.codigo);	
	
	for(int i = 0; i < 18 && JI_filmes.nome_canal[i] != '\0'; i++) 
	{
		gotoxy( col+10,lin); printf("%c",JI_filmes.nome_canal[i]); 
		col++ ;  
	}
	col = 0;
	
	//dd/mm/aaaa
	if(JI_filmes.criacao.dia < 10)
	{
		gotoxy(31,lin); printf("0%d",JI_filmes.criacao.dia);
	}
	else
	{
		gotoxy(31,lin); printf("%d",JI_filmes.criacao.dia);
	}
	
	if(JI_filmes.criacao.mes < 10)
	{
		gotoxy(34,lin); printf("0%d",JI_filmes.criacao.mes);
	}
	else
	{
		gotoxy(34,lin); printf("%d",JI_filmes.criacao.mes);	
	}
	gotoxy(37,lin); printf("%d",JI_filmes.criacao.ano);
	
	//gênero
	for(int i = 0; i < 15 && JI_filmes.genero[i] != '\0';i++)
	{
		gotoxy(col + 46,lin); printf("%c",JI_filmes.genero[i]);
		col++;
	}
	col = 0;
	
	//Num. vídeos
	gotoxy(63,lin); printf("%d",JI_filmes.num_videos);
	
	//Redes sociais
	for(int i = 0; i < 18 && JI_filmes.redes_sociais[i] != '\0';i++)
	{
		gotoxy(col+77,lin); printf("%c",JI_filmes.redes_sociais[i]);
		col++;
	}
	col = 0;
	
	//Freq. postagem
	for(int i = 0; i < 22 && JI_filmes.frequencia_videos[i] != '\0';i++)
	{
		gotoxy(col + 97,lin); printf("%c",JI_filmes.frequencia_videos[i]);
		col++;
	}
	col = 0;
	
}

void tabela_canal()
{
	int tecla;
	system("cls");
	gotoxy(20,1); printf("|-------------------------- Bem vindo a pesquisa por canal! --------------------------|");

	
	}
	
void mascara()
{
		system("cls");
	//máscara de tabela geral     
	 
	 gotoxy(2,3);  printf(" _____________________________________________________________________________________________________________________");
	 gotoxy(2,4);  printf("| Cód |       Canal       | Data  criação |     Gênero     | Num. vídeos |   Redes Sociais   | Frequência de postagem |");
	 gotoxy(2,5);  printf("|_____|___________________|_______________|________________|_____________|___________________|________________________|");
	 gotoxy(2,6);  printf("|     |                   |               |                |             |                   |                        |");
	 gotoxy(2,7);  printf("|_____|___________________|____/__/_______|________________|_____________|___________________|________________________|");
	 gotoxy(2,8);  printf("|     |                   |               |                |             |                   |                        |");
	 gotoxy(2,9);  printf("|_____|___________________|____/__/_______|________________|_____________|___________________|________________________|");
	 gotoxy(2,10); printf("|     |                   |               |                |             |                   |                        |");
	 gotoxy(2,11); printf("|_____|___________________|____/__/_______|________________|_____________|___________________|________________________|");
	 gotoxy(2,12); printf("|     |                   |               |                |             |                   |                        |");
	 gotoxy(2,13); printf("|_____|___________________|____/__/_______|________________|_____________|___________________|________________________|");
	 gotoxy(2,14); printf("|     |                   |               |                |             |                   |                        |");
	 gotoxy(2,15); printf("|_____|___________________|____/__/_______|________________|_____________|___________________|________________________|");
	 gotoxy(2,16); printf("|     |                   |               |                |             |                   |                        |");
	 gotoxy(2,17); printf("|_____|___________________|____/__/_______|________________|_____________|___________________|________________________|");
	 gotoxy(2,18); printf("|     |                   |               |                |             |                   |                        |");
	 gotoxy(2,19); printf("|_____|___________________|____/__/_______|________________|_____________|___________________|________________________|");
	 gotoxy(2,20); printf("|     |                   |               |                |             |                   |                        |");
	 gotoxy(2,21); printf("|_____|___________________|____/__/_______|________________|_____________|___________________|________________________|");
	 gotoxy(2,22); printf("|     |                   |               |                |             |                   |                        |");
	 gotoxy(2,23); printf("|_____|___________________|____/__/_______|________________|_____________|___________________|________________________|");
	 gotoxy(2,24); printf("|     |                   |               |                |             |                   |                        |");
	 gotoxy(2,25); printf("|_____|___________________|____/__/_______|________________|_____________|___________________|________________________|");
	 gotoxy(2,26); printf("|     |                   |               |                |             |                   |                        |");
	 gotoxy(2,27); printf("|_____|___________________|____/__/_______|________________|_____________|___________________|________________________|");
	 gotoxy(2,28); printf("|     |                   |               |                |             |                   |                        |");
	 gotoxy(2,29); printf("|_____|___________________|____/__/_______|________________|_____________|___________________|________________________|");
}
	
void pesquisa_cod()
{
	int aux_cod;
	int esc;
	int lin = 7;
	int flag = 2; // se a flag for 0, quer dizer que não foi encontrado nenhum código com este valor
	do{
		abrir_arquivo("rb");
		rewind(JIp);
		mascara();  
		gotoxy(2,1);  printf("                                                 PESQUISA CÓDIGO                                                      ");                                                                                                                                
		gotoxy(2,2); printf("                                                              ");
		gotoxy(2,2); printf("Digite o código do canal ou 0 para sair:");
		gotoxy(42,2); scanf("%d",&aux_cod);
		while(fread( &JI_filmes,sizeof(JI_filmes),1,JIp) == 1)
		{
			
			if (aux_cod == 0)
			{
				system("cls"); 
				carregamento();
				textcolor(4,15);  //máscara para o menu voltar com as cores e logo corretamente 
				system("cls");
				logo();
				textcolor(4,15);
				HideCursor(0);
				return;	
			}
			if(aux_cod == JI_filmes.codigo)
			{
				flag = 1; //achou o cód.
				mostra_dados(lin);
				do{
					flag = 1;
					gotoxy(2,2); printf("Pressione 1 para procurar outro código ou 0 para sair:    ");
					gotoxy(56,2); scanf("%d",&esc);
					if(esc== 0)
					{
						system("cls"); 
						carregamento();
						textcolor(4,15);  //máscara para o menu voltar com as cores e logo corretamente 
						system("cls");
						logo();
						textcolor(4,15);
						HideCursor(0);
						return;	
					}
					if(esc == 1)
						flag = 1;
						break;
				}while(esc != 1 && esc != 0);
			}
			else{
				if(esc == 1)
					flag = 1;
				else
					flag = 0;
			}
			
		}
		if(flag != 1)
		{
			gotoxy(42,2); printf("            Código não encontrado! Pressione qualquer tecla para continuar.");		
			getch();
		}	
		esc = 2;
	}while(true);	
}


void pesquisa_genero()
{
	
	int linha = 7; 
	int tecla;
	char genero_pes[50]; //Para entrada de nome a ser pesquisado
	char gen[50];
	
	int cont = 0; 
	
	abrir_arquivo("rb");                                 
		gotoxy(2,3);printf("Caso tenha escolhido uma opção indesejada, aperte 'ESC' para sair.\n Se quiser prosseguir para a pesquisa por Gênero, selecione qualquer outra tecla...  ");
		tecla=getch();
		if(tecla == 27) 
		{
			
			system("cls"); 
			carregamento();
			textcolor(4,15);  
			system("cls");
			logo();
			textcolor(4,15);
			HideCursor(0);
			return;
		}
	
	tabela_canal(); 
	mascara();
	gotoxy(2,2);printf("Digite o Gênero desejado para ser pesquisado: "); gotoxy(85,2); printf("----|Pesquisa por Gênero|----");
	gotoxy(47,2);gets(genero_pes);
	
	strcpy(gen,genero_pes); 
	strlwr(genero_pes); 
	
	while( !feof(JIp) ) //Enquanto não for fim de arquivo
	{
       while(fread( &JI_filmes,sizeof(JI_filmes),1,JIp) == 1 && cont<24) 
		     
		{
			if(linha > 29) 
			{
				gotoxy(2,32);printf("Pressione uma tecla para continuar ou 5 vezes 'ESC' para sair...");
				fflush(stdin);
				tecla = getch();
				if(tecla == 27) 
					break;
				linha = 7; 
				system("cls");
				mascara();
				gotoxy(13,0); printf("Gênero sendo pesquisado:");
				gotoxy(37,0);printf("%s",gen); 
			}
			
			strlwr(JI_filmes.genero); 
			if( (strstr(JI_filmes.genero, genero_pes) != NULL )  
			  &&(JI_filmes.exclusao == 'n' ) )
			{
				mostra_dados(linha);
				linha+=2;
			}
		}
	}
	if(tecla != 27)
	{
		gotoxy(2,32);printf("Fim dos dados! Pressione qualquer tecla para voltar ao menu da pesquisa...");
		tecla = getch();	
			
	}
	fclose(JIp);
	
}
