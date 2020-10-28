#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

// Vers�o 1.7
#define versao 1.7

// Defini��o de cores 
#define cor_fundo 3
#define cor_borda 1
#define cor_texto 15
#define cor_destaque 0

text_info vActual = {0, 0, 79, 24, WHITE, WHITE, C80, 120, 40, 1, 1}; // Define os limites para linha (35) e coluna (80)

// Fun��es conio.c
void textcolor(int newcolor);
void textbackground(int newcolor);
void gotoxy(int x, int y);
void cursor (int x);
void clreol(int x);

// Fun��es de constru��o do programa

// Apresenta o menu e a vers�o
void loading();
// Apresenta tela de inicio
void inicio(); 
// Fun��o utilizada para a borda
void borda(); 

// Fun��o utilizada para criar o disquete
void disquete(int ic, int il); // (coluna de inicio, linha de inicio)
// Fun��o para criar a logo GoTech
void logo(int ic, int il);
// Fun��o utilizada para criar uma lupinha
void lupa(int ic, int il); // (coluna de inicio, linha de inicio)
// Fun��o para gera��o de cpu
void cpu(int ic, int il);
// Fun��o de gera��o da gpu
void gpu(int ic, int il);
// Fun��o para gera��o da mem�ria ram
void ram(int ic, int il);
// Fun��o de gera��o da placa m�e
void mobo(int ic, int il);

// Fun��o para fazer a consulta dos dados j� salvos
void consulta_geral();
// Fun��o para apagar dados do .bin por id
void apaga_dados();
// Fun��o para gerar uma tabela
void gera_tabela(int li);  //
//Fun��o para colocar os dados na tabela
void completa_tabela(int linha);
// Fun��o para gerar tabela de tipo 
void tipo_tabela();
// Fun��o utilizada para navegar com setasem menus
int navegar_menu(int ini, int fim, int p); // Recebe inicio e fim do menu e a posi��o do cursor

// Menu 

// Fu��o de constru��o do menu da tela inicial
void menu_ini();

// Fun��o para gerar a parte visual do cadastro 
void cadastro_visual();
// Recebe os dados de registro
void cadastro_recebimento();

/* Fun��es do submenu */
void consulta_id(); // Encontra o produto pelo id

// Fun��o para gerar o sub menu de pesquisa
void sub_menu();

// Fun��o para apresentar as Informa��es do Sistema
void info_de_sistema();

// Fun��o que finaliza a execu��o do programa no menu
void sair();

// Fun��es de checagem

// Fun��o para validar c�digo consultado
int valida_id_consulta(int *id_final);

// Fun��es de valida��o => Valida��es + Registro

// Valida id no registro
void valida_id_recebimento();
// Valida quantidade no registro
void valida_quantidade_recebimento();
// Valida nome no registro
void valida_nome_recebimento();
// Valida tipo digitado
void valida_tipo_recebimento();
// Valida pre�o digitado
void valida_preco_recebimento();

FILE *fp; //Ponteiro para arquivo

int random_menu; // Var que armazena numero aleat�rio ente 0 e 4 para gerar um menu diferente 

void abrir_arquivo()
{
	if((fp = fopen("estoque.bin", "ab+")) == NULL) 
	{
		gotoxy(18,11);printf("Erro na abertura do arquivo"); //caso haja um problema com o arquivo
		exit(1);
	}
}

int abrir_arquivo_alterar()
{
	if((fp = fopen("estoque.bin", "rb+")) == NULL) 
	{
		gotoxy(18,11);printf("Nao foram encontrados dados, cadastre algo!");
		getch();
		return 1;
	}
	else
		return 0;
}

struct estrutura
{
	long id;
	char nome[50];
	int quantidade;
	char tipo;
	float preco_unitario;
	bool excluido;
	
}produto;


main()
{
	SetConsoleTitle("GoTech"); 		   // Define o nome do console
    system("mode con:cols=120 lines=40");  // Define o tamanho do console
    
	srand(time(NULL));
	random_menu = rand() % 4; // Escolhe o menu que ser� exibido ao usu�rio
	
    loading();
	inicio(); // Fun��o de constru��o da tela inicial
}

void loading()
{
	borda(); 
	cursor(0);
	
	// Apresenta��o de vers�o 
	
	textcolor(cor_texto);
	gotoxy(38, 10); printf("Aguarde, estamos preparando tudo para voce!");
	gotoxy(15, 30); printf("GoTech");
	gotoxy(99, 30); printf("Versao %.1f", versao);
	
	textcolor(RED); // Loading vermelho
	for(int i = 0; i <= 52; i++)
	{
		gotoxy(32+i, 20);printf("%c", 219);
		Sleep(10);
	}
	textcolor(cor_texto);
	gotoxy(38, 10); printf("       Tudo pronto! Podemos iniciar                               ");
	Sleep(2000);
}

void inicio() // Apresenta tela de inicio
{	
	borda(); 
	
	switch(random_menu) // Menu aleatorio
	{
		case 0:
			disquete(18, 6); // Disquete + logo
			logo(48, 8);
			break;
		case 1:				// cpu + logo
			cpu(18, 6); 	
			logo(48, 8);
			break;	
		case 2:				// logo
			logo(32, 8); 	
			break;
		case 3:				// Ram + logo
			ram(37, 4); 	
			logo(32, 10);
			break;
		case 4:				// Ram + logo
			mobo(83, 6); 		
			logo(20, 8);
			break;		
	}
	
	menu_ini();
}

void menu_ini()
{	
	int inic = 50, inil = 19; // Se deseja mudar a posi��o do texto no menu basta alterar uma das variaveis 
	
	// Menu 
	textcolor(cor_texto);
	gotoxy(inic, inil); 	printf("Cadastro");
	gotoxy(inic, (inil+2)); printf("Pesquisa");
	gotoxy(inic, (inil+4)); printf("Info do Sistema");
	gotoxy(inic, (inil+6)); printf("Sair");
	
	// Chama navega��o com setas
	int escolha;
	escolha = navegar_menu(inil, (inil + 6), (inic - 2));
	
	switch(escolha)
	{
		case 0:
			cadastro_visual();
			break;
		case 1:
			sub_menu();
			break;
		case 2:
			info_de_sistema();
			break;
		case 3:
			sair();
			break;
	}
}

void cadastro_visual()
{
	int x = 20, y = 8;
	char dnv = 'n';
	
	abrir_arquivo();
	
	cursor(1);
	
	do{
		
		borda();
		tipo_tabela();
		gotoxy(20,31); printf("Digite 0 no campo de ID para retornar ao menu");
		
		textcolor(cor_destaque);
		gotoxy(50, 4); printf("Cadastro de Produtos"); // Mensagem em destaque no meio da tela
		
		// Posicionado a esquerda => Perguntas
		gotoxy(x, y); 	  printf("Id do produto....: ");				
		gotoxy(x, y + 2); printf("Nome do Produto..: ");		
		gotoxy(x, y + 4); printf("Quantidade.......: ");			
		gotoxy(x, y + 6); printf("Tipo.............: ");					
		gotoxy(x, y + 8); printf("Preco Unitario...: ");		
		
		textcolor(cor_texto);	
		cadastro_recebimento(); // Recebe as respostas do usu�rio
		
		textcolor(cor_destaque);
		gotoxy(x, y + 20); printf("Deseja realizar mais um cadastro? (S/N): ");
	
		do{
			fflush(stdin);
			dnv = getche();
			
			if(dnv != 'n' && dnv != 'N' && dnv != 's' && dnv != 'S')
			{
				Sleep(100);
				gotoxy(x, y + 20); clreol(70); printf("Valor invalido! digite novamente (S/N): ");
				Sleep(50); gotoxy(60, y + 20); clreol(1);
			}
				
		}while(dnv != 'n' && dnv != 'N' && dnv != 's' && dnv != 'S');
		
		system("cls");
		
	}while(dnv == 's' || dnv == 'S');
	
	system("cls");
	
	inicio();
}

void cadastro_recebimento()
{
	int x = 39, y = 8;
	
	gotoxy(x, y);   valida_id_recebimento();		 // Recebe id
	gotoxy(x, y+2); valida_nome_recebimento();		 // Recebe nome
	gotoxy(x, y+4); valida_quantidade_recebimento(); // Recebe quantidade
	gotoxy(x, y+6); valida_tipo_recebimento();		 // Recebe tipo
	gotoxy(x, y+8); valida_preco_recebimento();	 	 // Recebe preco
	produto.excluido = false;						 // Define excluido
	
	char conf; // variavel de confirma��o do loop seguinte
	
	textcolor(cor_destaque);
	gotoxy(20, y+14); printf("Deseja salvar os dados? (S/N): ");
	
	do{
		fflush(stdin);
		conf = getche();
		
		if(conf != 's' && conf != 'S'	&& conf != 'n' && conf != 'N')    //verifica��o de valores
		{			
			Sleep(100);
			gotoxy(20, y+14); printf("Valor invalido! digite novamente (S/N): ");
			Sleep(50); gotoxy(60, y + 14); clreol(1);
		}
		
   	}while( conf != 's' && conf != 'S'	&& conf != 'n' && conf != 'N' );
   	
   	if( conf == 's' || conf == 'S' )
   	{
		if(fwrite(&produto, sizeof(produto), 1, fp) != 1) 
		{
			textcolor(RED);
			gotoxy(x+50,y+14); printf("Erro na escrita do arquivo");
			textcolor(cor_texto);
		}
		else
		{
			fflush( fp );
			//fclose(fp);  
			system("cls");
			borda();
			textcolor(cor_destaque);
			gotoxy(18,11); printf("Dados salvos com sucesso!");
		}
		
		cursor(0);
		Sleep(2000);
		cursor(1);
	}
}

void valida_id_recebimento() // Recebe e valida id
{
	char id[30];
	int tam;			// Armazena tamanho da string
	int k, c;	// Auxiliares
	
	do
	{
		fflush(stdin);
		
		k = 1;
		c = 0;
		
		gets(id); 			// Recebe id
		tam = strlen(id);	// recebe tamanho da string
		
		if(tam == 0)	// Se nada foi digitado
		{
			gotoxy(39,8);	// Retorna a posi��o de inicio e pergunta novamente
			k = 0;
		} 
		else if(id[0] == '0')	// Se o primeiro digito de id for igual a 0 
		{
			cursor(0);
			textbackground(12);
			gotoxy(52, 35); // Apresenta mensagem a baixo da borda
			printf("Voltando ao menu");
			Sleep(2500);
			inicio();	// Retorna ao inicio
		} 	
		else 
		{
			for(int i = 0; i < tam; i++) 
			{
				// Confere se � num�rico
				if(id[i] != '0' && id[i] != '1' && id[i] != '2' && id[i] != '3' && id[i] != '4' && id[i] != '5' && id[i] != '6' && id[i] != '7' && id[i] != '8' && id[i] != '9') 
				{
					c = 1; // Se n�o for num�rico apresenta erro e pergunta novamente o id
					break;
				}
				else // Se for num�rico 
				{
					k = 1;	// Sai do la�o de repeti��o
					c = 0; // N�o apresenta erro
				} 
			}	
			
			if(c == 1)	// Erro 
			{
				k = 0;
				
				textbackground(cor_fundo);
				gotoxy(39, 8); clreol(72);
				textbackground(12);
				gotoxy(39, 8); printf("[ERRO] ID invalido");
				Sleep(1000); // tempo de erro na tela
				textbackground(cor_fundo);
				gotoxy(39, 8); clreol(72);
				gotoxy(39,8);
				
			}
		}
		
	}while(k == 0);
	
	produto.id = atoi(id); // Atoi => Tranforma o id (aux) em inteiro 
}

void valida_nome_recebimento() // Recebe e valida nome
{
	char aux[50], aux_string_final[50]; 
	
	// Aux => serve para o recebimento da string 
	// aux_string_final => Serve para armazenar a string sem espa�amento (final)
	
	int tam, c, k, cont, cont_aux_final; // Variaveis auxiliares
	
	do
	{
		cont = 0;
		c = 0;
		cont_aux_final = 0;
		k = 0;
		
		gets(aux);
		tam = strlen(aux);
		
		if(tam == 0) gotoxy(39, 10);	
		else
		{
			for(int i = 0; i < tam; i++)
			{
				if(k == 0)
				{
					if(aux[i] != char(32))
					{
						aux_string_final[cont_aux_final] = aux[i];
						c = 1;
						cont_aux_final++;
						k = 1;
					} 
					else
					{
						c = 0;
						cont++;
					}	 
				}
				else 
				{
					aux_string_final[cont_aux_final] = aux[i];
					c = 1;
					cont_aux_final++;
				}			
			}	
		}
		
		if(c == 1) break;
		else gotoxy(39, 10);	
		
	}while(true);
	
	for(int i = 0; i < strlen(aux_string_final); i++)
	if((aux_string_final[i] < char(48) || aux_string_final[i] > char(57) ) && (aux_string_final[i] < char(65) || aux_string_final[i] > char(90))  && (aux_string_final[i] < char(97) || aux_string_final[i] > char(122))) aux_string_final[i] = ' ';
	
	gotoxy(39, 10); clreol((cont + tam));
	strcpy(produto.nome, aux_string_final); 
	gotoxy(39, 10); printf("%s", produto.nome);
}

void valida_quantidade_recebimento() // Recebe e valida quantidade
{
	char aux[50];
	
	int tam;
	int k, c; // Auxiliares
	
	do
	{
		fflush(stdin);
		
		k = 1;
		c = 0;
		
		gets(aux);
		tam = strlen(aux); // Tamanho da string
		
		if(tam == 0)	// Se nada for digitado pergunta novamente
		{
			gotoxy(39, 12);
			k = 0;
		} 
		else 
		{
			for(int i = 0; i < tam; i++) 
			{
				if(aux[i] != '0' && aux[i] != '1' && aux[i] != '2' && aux[i] != '3' && aux[i] != '4' && aux[i] != '5' && aux[i] != '6' && aux[i] != '7' && aux[i] != '8' && aux[i] != '9') 
				{ // Se n�o � num�rico 
					c = 1;	// Apresenta erro
					break;
				}
				else // Se � num�rico
				{
					k = 1;
					c = 0;
				} 
			}	
			
			if(c == 1) // Erro
			{
				k = 0;	// Repete a pergunta
				
				textbackground(cor_fundo);
				gotoxy(39, 12); clreol(72);
				textbackground(12);
				gotoxy(39, 12); printf("[ERRO] Quantidade invalida");
				Sleep(1000); // tempo de erro na tela
				textbackground(cor_fundo);
				gotoxy(39, 12); clreol(72);
				gotoxy(39, 12);
			}
		}
	}while(k == 0);
	
	produto.quantidade = atoi(aux); // Retorna quantidade inteira 
}

void valida_tipo_recebimento() // Recebe e valida tipo 
{
 	char aux;
 	
 	fflush(stdin);
 	
 	do
 	{
 		aux = getche();
		
		// Verifica se � um dos tipos listados
		if(aux == 'p' || aux == 'P' || aux == 'g' || aux == 'G' || aux == 'c' || aux == 'C' || aux == 'm' || aux == 'M' || aux == 'f' || aux == 'F' || aux == 'w' || aux == 'W' || aux == 'a' || aux == 'A' || aux == 'r' || aux == 'R' || aux == 'o' || aux == 'O') break;
		else // Apresenta erro
		{
			textbackground(cor_fundo);
			gotoxy(39, 14); clreol(72);
			textbackground(12);
			gotoxy(39, 14); printf("[ERRO] Tipo invalido");			
			Sleep(1000); // tempo de erro na tela
			textbackground(cor_fundo);
			gotoxy(39, 14); clreol(72);
			gotoxy(39, 14);
		}
		
	}while(true);
	
	produto.tipo = aux;
}

void valida_preco_recebimento() // Recebe pre�o e valida
{
	char aux[30];
	int tam;
	char* end; // Ponteiro de convers�o 
	float num;
	int k;
	
	do
	{	
		fflush(stdin);
		
		gets(aux);
		
		tam = strlen(aux); // Recebe tamanho da string
		
		k = 0;
		
		if(tam == 0) gotoxy(39, 16); // Se nada for digitado
		else
		{
			for(int i = 0; i < tam; i++)
			{
				if((aux[i] < '0' || aux[i] > '9') && aux[i] != '.') // Verifica se � num�rico
				{ 
					// Erro
					
					k = 1;
						
					textbackground(cor_fundo);
					gotoxy(39, 16); clreol(72);
					textbackground(12);
					gotoxy(39, 16); printf("[ERRO] Valor invalido");			
					Sleep(1000); // Tempo de erro
					textbackground(cor_fundo);
					gotoxy(39, 16); clreol(72);
					gotoxy(39, 16);	
					
					break;
				}
			}			
			
			if(k == 0) // Se valor for num�rico
			{
				num = strtod(aux, &end); // Converte para float
				
				if(num > -1) break; // Se valor positivo
				else // Se valor negativo 
				{
					// Erro
					textbackground(cor_fundo);
					gotoxy(39, 16); clreol(72);
					textbackground(12);
					gotoxy(39, 16); printf("[ERRO] Valor invalido");			
					Sleep(1000);
					textbackground(cor_fundo);
					gotoxy(39, 16); clreol(72);
					gotoxy(39, 16);	
				}
			}
		}
	}while(true);
	
	produto.preco_unitario = num; 
}

// Revis�o prim�ria => 28/10/2020 

/* 
	- Fun��es de recebimento e valida��o alteradas
	- Tempo das mensagens de erro reduzido
	- Erros l�gicos resolvidos
	- Ainda a revisar: valida_nome_recebimento()
*/

void consulta_geral()
{
	int ir_proxima=0, sair, linha = 7;
	
	abrir_arquivo();
	
	rewind(fp); // seta a leitura do arquivo na posi��o inicial do arquivo ("1� linha e coluna")
	
	gera_tabela(5);
	
	do
	{
		if(fread(&produto, sizeof(produto), 1, fp) == 1) {
			if(produto.excluido == false) {
				ir_proxima++;
				completa_tabela(linha);
				linha+=2;
				if(ir_proxima == 12)
				{
					ir_proxima = 0;
					textcolor(0);
					gotoxy(20, 31); printf("Deseja ir para a proxima pagina (S-Sim/N-Nao): ");
					char pag = '0';
					while(pag != 'S' && pag != 's' && pag != 'N' && pag != 'n' && pag != '\r')
					{
						if(pag != 'S' && pag != 's' && pag != 'N' && pag != 'n' && pag != '\r')
						{
							gotoxy(20,32); printf("Digite um valor v�lido!");
						}
						gotoxy(68,31); clreol(2); pag = getche();
					}
					if(pag == 's' || pag == 'S')
					{
						system("cls");
						linha = 6;
						gera_tabela(5);
					}
					else
					{
						system("cls");
						break;
					}
				}
			}
		}
	}while ( !feof(fp) );
	
	gotoxy(20,31); printf("Pressione 0 para voltar ao menu de pesquisa");
	char tecla;
	
	do
	{
		fflush(stdin);
		tecla = getch();
			
	}while(tecla != '0');
		
	sub_menu();
}

void gera_tabela(int li)
{
	int ci=20;
	system("cls");
	borda();
	tipo_tabela();
		
	textcolor(15);
	gotoxy(ci,4);	printf ("+---------------------------------------------------------------------------------+");
	gotoxy(ci,5);	printf ("|   ID   |      Nome         |  Pre�o Unit�rio  |    Quantidade   |     Tipo      |");
	gotoxy(ci,6);	printf ("|---------------------------------------------------------------------------------|");
	gotoxy(ci,7);	printf ("|        |                   |                  |                 |               |");
	gotoxy(ci,8);	printf ("|---------------------------------------------------------------------------------|");
	gotoxy(ci,9);	printf ("|        |                   |                  |                 |               |");
	gotoxy(ci,10);	printf ("|---------------------------------------------------------------------------------|");
	gotoxy(ci,11);	printf ("|        |                   |                  |                 |               |");
	gotoxy(ci,12);	printf ("|---------------------------------------------------------------------------------|");
	gotoxy(ci,13);	printf ("|        |                   |                  |                 |               |");
	gotoxy(ci,14);	printf ("|---------------------------------------------------------------------------------|");
	gotoxy(ci,15);	printf ("|        |                   |                  |                 |               |");
	gotoxy(ci,16);	printf ("|---------------------------------------------------------------------------------|");
	gotoxy(ci,17);	printf ("|        |                   |                  |                 |               |");
	gotoxy(ci,18);	printf ("|---------------------------------------------------------------------------------|");
	gotoxy(ci,19);	printf ("|        |                   |                  |                 |               |");
	gotoxy(ci,20);	printf ("|---------------------------------------------------------------------------------|");
	gotoxy(ci,21);	printf ("|        |                   |                  |                 |               |");
	gotoxy(ci,22);	printf ("|---------------------------------------------------------------------------------|");
	gotoxy(ci,23);	printf ("|        |                   |                  |                 |               |");
	gotoxy(ci,24);	printf ("|---------------------------------------------------------------------------------|");
	gotoxy(ci,25);	printf ("|        |                   |                  |                 |               |");
	gotoxy(ci,26);	printf ("|---------------------------------------------------------------------------------|");
	gotoxy(ci,27);	printf ("|        |                   |                  |                 |               |");
	gotoxy(ci,28);	printf ("|---------------------------------------------------------------------------------|");
	gotoxy(ci,29);	printf ("|        |                   |                  |                 |               |");
	gotoxy(ci,30);	printf ("+---------------------------------------------------------------------------------+");
	
//	gotoxy(20,35); printf("1 - hbihw 2 - 3ijosgubiowsb 3 - bviwbsodbnobn 4- pnaoedbniobwsiocbow 5 - nbsaovbnwso");
//	gotoxy(20,36); printf("1 - hbihw 2 - 3ijosgubiowsb 3 - bviwbsodbnobn 4- pnaoedbniobwsiocbow 5 - nbsaovbnwso");
}

void completa_tabela(int linha)
{
	gotoxy(24,linha);  printf("%d", produto.id);
	gotoxy(31,linha); printf("%s", produto.nome);
	//gotoxy(ci+30,li);printf("%s", produto.marca);
	gotoxy(51,linha); printf("%.2f", produto.preco_unitario);
	gotoxy(71,linha); printf("%d", produto.quantidade);
	gotoxy(89,linha); printf("%c", produto.tipo);
	gotoxy(1,60);
}

void excluir_dados() //exclusao l�gica
{
	
	system("cls");
	abrir_arquivo_alterar();
	borda();
	textcolor(15); 
	int aux_codigo,F;
	long fposicao;
	char conf;
	//gotoxy(20,15); printf("Deseja excluir apenas um dado ou o programa todo?");
	//sdsdsds
	
	do{	
	    gotoxy(20,7); printf("Digite o codigo do produto a ser excluido (digite zero para encerrar): ");
	    scanf("%d", &aux_codigo );
	    if (aux_codigo!=0)
	    {
			F = 0;
			rewind(fp);
		    do
		    {
				fread( &produto,sizeof(produto),1,fp);
				if ( produto.id == aux_codigo && produto.excluido == false ) //Se houver um produto com o id e que n�o foi exclu�do
				{
			   		F = 1;
			   		fposicao = ftell(fp); // guarda a posi��o do registro atual do arquivo
			   		gotoxy(20,4);	printf ("|   ID   |      Nome         |  Pre�o Unit�rio  |    Quantidade   |     Tipo      |");
			   		completa_tabela(5); //Apresenta-se ao usu�rio o registro a ser exclu�do
				   	gotoxy(25,22); printf("Confirma exclusao ? (S/N): ");
				   	// exclus�o � uma opera��o cr�tica, por isso, sempre ser� confirmada pelo usu�rio
					fflush(stdin);
					do 
				   	{
				    	gotoxy(54,22); conf = getche();
				   	}while( conf != 's' && conf != 'S' &&
					   conf != 'n' && conf != 'N' );
				   
				   	if( conf == 's' || conf == 'S' )
				   	{
				   		//posiciona o ponteiro do arquivo no registro a ser excluido logicamente
						fseek (fp,fposicao-(sizeof(produto)),SEEK_SET); 	//em stdio.h
																			//SEEK_SET indica o in�cio do arquivo
						produto.excluido= true; /*atribui��o de 's' para o campo exclu�do para indicar 
							 			que o registro foi exclu�do ou desativado (exclus�o l�gica) */
						if(fwrite (&produto,sizeof(produto),1,fp)==1)
						{
							fflush (fp);
							gotoxy(25,24);printf("Cadastro excluido com sucesso!");
							getch();
							system("cls");
						}	
				   	}
				}
			} while ((!F) && (!feof(fp)));  	
		} 
		if (F==0 && aux_codigo!=0)
		{
			gotoxy(20,15);printf("****** Codigo nao encontrado! Voltando ao menu! ******");
			getch();
		}
		break;
	}while(aux_codigo!=0);
	Sleep(1000);
	system("cls");
	inicio();
}

void sub_menu()
{
	borda();
	
	int inic = 45, inil = 19; // Se deseja mudar a posi��o do texto no menu basta alterar uma das variaveis 
	
	lupa(43,4);
	
	// Menu 
	textcolor(cor_texto);
	gotoxy(inic, inil); 	printf("Geral");
	gotoxy(inic, (inil+2)); printf("Pesquisa por Id (n�o feito ainda)");
	gotoxy(inic, (inil+4)); printf("Pesquisa por Nome (n�o feito ainda)");
	gotoxy(inic, (inil+6)); printf("Excluir dados");
	gotoxy(inic, (inil+8)); printf("Retornar ao Inicio");
	
	int escolha;
	escolha = navegar_menu(inil, (inil + 8), (inic - 2));
	
	switch(escolha)
	{
		case 0:
			consulta_geral();
			break;
		case 1:
			consulta_id();
			break;
		case 2:
			//pesquisa();
			break;
		case 3:
			excluir_dados();
			break;
		case 4:
			inicio();
			break;
	}
}

void consulta_id()
{	

	char op;
	int proxima_tela = 0, linha = 6, sair = 0;	
	abrir_arquivo();
	op = 'a';
	int k=0;
	






	// Constru��o visual
	borda();
	textcolor(cor_destaque);
	gotoxy(54, 4); printf("Busca por Id");
	
	int x = 20, y = 12;
	int aux = 0;
	int id_busca; // Armazena id digitado pelu usu�rio durante a busca
	
	gotoxy(x, y); printf("Digite o Id (0 para sair): ");
	
	textcolor(cor_texto);
	do
	{
		aux = valida_id_consulta(&id_busca);
		
		if(aux == 0) break;
		else if(aux == 1) // Retorna ao sub menu por conta de um erro no id digitado pelo usuario
		{
			textcolor(RED);
			gotoxy(53, 24); printf("Id invalido!");
			Sleep(3000);
			consulta_id();	
		} 
		else if(aux == 3)
		{
			while( !feof(fp) )
			{
				if(fread(&produto, sizeof(produto), 1, fp) == 1 && produto.excluido == 'n' && produto.id == id_busca)
				{					
					gera_tabela(linha);
					gotoxy(20,24);printf("Pressione uma tecla para continuar...");
					getch();
					k = 1;
					system("cls");
					break;
					
				}				
			}
			if(k == 0)
			{
				gotoxy(21,23);printf("-----> Codigo inexistente! <-----");
				gotoxy(21,24);printf("Pressione uma tecla para redigitar");
				getch();
				
			}
		}
		
	}while(true);
	
	sub_menu();
}

int valida_id_consulta(int *id_final)
{
	char id[30];
	int tam;
	
	do
	{
		gets(id);
		tam = strlen(id);
		
		if(id[0] == '0') 
		{
			if(tam > 1) return 1;
			else return 0;
		}
		else for(int i = 0; i < tam; i++) if(id[i] != '0' && id[i] != '1' && id[i] != '2' && id[i] != '3' && id[i] != '4' && id[i] != '5' && id[i] != '6' && id[i] != '7' && id[i] != '8' && id[i] != '9') return 1;
		break;	
		
	}while(true);
	
	*id_final = atoi(id);
	return 3;
}	

void tipo_tabela()
{
    textcolor(cor_texto);
    gotoxy(38,37);    printf(" P - Periferico       G - Gpu      C - Cpu");
    gotoxy(38,38);    printf(" M - Mobo             F - Fonte    W - Cabos");
    gotoxy(38,39);    printf(" A - Armazenamento    R - Ram      O - Outros");
}

void info_de_sistema() // Apresenta as informa��es do sistema
{
	borda();

	
	int inix = 20, iniy = 9; // Controla o eixo x e y das informa��es
	
	// Apresenta as informa��es do sistema
	textcolor(0);
	gotoxy(54, 4);  printf("Info do Sistema");
	textbackground(cor_fundo);
	
	textcolor(cor_destaque);
	gotoxy(inix, iniy -2); printf("Empresa: ");
	textcolor(cor_texto);
	printf("GoTech");
	
	textcolor(cor_destaque);
	gotoxy(inix, iniy);  printf("Nomes: ");
	textcolor(cor_texto);
	printf("Gabriel Nicolim e Felipe Lima");
	
	textcolor(cor_destaque);
	gotoxy(inix, iniy + 2);  printf("Numeros: ");
	textcolor(cor_texto);
	printf("8 e 6");
	
	textcolor(cor_destaque);
	gotoxy(inix, iniy + 4);  printf("Turmas: ");
	textcolor(cor_texto);
	printf("71A");
	
	textcolor(cor_destaque);
	gotoxy(inix, iniy + 6);  printf("Ano: ");
	textcolor(cor_texto);
	printf("2020");
	
	textcolor(cor_destaque);
	gotoxy(inix, iniy + 8);  printf("Sobre o software: ");
	textcolor(cor_texto);
	printf("Nosso software, que hoje se encontra na versao %.1f, se destina a", versao);
	gotoxy(inix, iniy + 10); printf("simular um sistema de gerenciamento de estoque de uma loja de informatica em C/C++.");
	gotoxy(inix, iniy + 12); printf("Para a realizacao desse projeto utilizamos funcoes de cabecalho da conio.c e conio.h.");
	gotoxy(inix, iniy + 14); printf("Podem ser registrados perifericos e pecas de computador.");
	
	textcolor(cor_destaque);
	gotoxy(inix, iniy + 16); printf("Agradecimentos: ");
	textcolor(cor_texto);
	printf("Deixamos nosso agradecimento a professora Ariane Scarelli e ");
	gotoxy(inix, iniy + 18); printf("Katia Zambombon, por compartilharem conosco parte de seus conhecimentos.");
	
	gotoxy(inix, iniy + 21); printf("Pressione 0 para retornar ao menu"); 
	
	char c;
	
	while(true)
	{
		fflush(stdin); 
		c =	getch();
		
		if(c == '0') inicio(); // Retorna ao inicio se a tecla 0 for pressionada
	}
}

void sair() // Finaliza a execu��o do programa
{
	borda();
	
	textcolor(cor_texto);
	gotoxy(42, 17); printf("Obrigado por utilizar nosso programa!");
	textcolor(cor_fundo);
	fclose(fp);
	gotoxy(80, 37);
	exit(1);
}


int navegar_menu(int ini, int fim, int p)
{
	cursor(0); // Desativa o cursor
	int aux = ini; // Recebe posi��o da seta
	int c; // Armazena entrada do teclado
	
	do
	{
		gotoxy(p,aux);printf("%c", 62);	
			
		fflush(stdin); 
		c = getch();
		
		gotoxy(p,aux);printf(" ");
		
		switch(c) 
		{
			case 72: // Seta para cima
				aux -= 2;
				
				if(aux < ini) aux  = fim;

				gotoxy(p,aux);printf("%c", 62);
				break;
				
			case 80: // Seta para baixo
				aux+=2;
					
				if(aux > fim) aux = ini;
					
				gotoxy(p,aux);printf("%c", 62);
				break;	
			case 13:
			return (aux - ini)/2; // Retorna o valor da op��o seleciona => inicia em 0
			break;	
		}
		
	}while(true);
}

void borda() 
{
	int cf = cor_fundo, cb = cor_borda, lc = 120; // (cor de fundo, cor da borda, limite de coluna)
	
	textbackground(cf); // Define cor do fundo
	system("cls"); 
	
	for (int i = 9; i <= (lc - 8); i++) // Parte de cima da borda
	{
		textcolor(cb);
		gotoxy(i,2);printf("%c",219);
	}
	for (int i = 9; i <= (lc - 8); i++) // Parte de baixo da borda 
	{
		textcolor(cb);
		gotoxy(i,33);printf("%c",219);
	}
	for (int i=2; i <= 33; i++) // Borda esquerda 
	{
		textcolor(cb);
		gotoxy(10,i);printf("%c",219);
		gotoxy(9,i);printf("%c",219);
	}
	for (int i=2; i <= 33; i++) // Borda direita
	{
		textcolor(cb);
		gotoxy(112,i);printf("%c",219);
		gotoxy(111,i);printf("%c",219);
	}
	
	printf("\n\n\n\n");
}

void disquete(int ic, int il)
{
	
	// Linha 1 => Borda de cima
	textcolor(0);
	gotoxy(ic, il); 
	for(int i = 0; i < 20; i++) putchar(219);
	
	// Linha 2  - tracinho
	gotoxy(ic, (il+1));
	printf("%c", 219);
	
	for(int i = 0; i < 18; i++) 
	{
		if(i == 2 or i == 15) textcolor(8);
		if(i > 2  and i < 15) 
		{
			textcolor(7);
			if(i > 4 && i < 8) textcolor(0);
		}
		else textcolor(9);
		putchar(219);
	}
	
	textcolor(0);
	printf("%c", 219);
	
	// Linha 3  - tracinho
	gotoxy(ic, (il+2));
	printf("%c", 219);
	
	for(int i = 0; i < 18; i++) 
	{
		if(i == 2 or i == 15) textcolor(8);
		if(i > 2  and i < 15) 
		{
			textcolor(7);
			if(i > 4 && i < 8) textcolor(0);
		}
		else textcolor(9);
		putchar(219);
	}
	
	textcolor(0);
	printf("%c", 219);
	
	// Linha 4
	
	gotoxy(ic, (il+3));
	
	printf("%c", 219);
	textcolor(9);
	for(int i = 0; i < 18; i++) putchar(219);
	textcolor(0);
	printf("%c", 219);
	
	// Linha 5
	
	gotoxy(ic, (il+4));
	printf("%c", 219);
	textcolor(9);

	for(int i = 0; i < 18; i++) putchar(219);
	textcolor(0);
	printf("%c", 219);
	
	//Linha 6 - rodelinha com tracin
	
	gotoxy(ic, (il+5));
	
	printf("%c", 219);
	for(int i = 0; i < 18; i++) 
	{	
		if(i>6 && i <11) 
		{
		textcolor(7);
		if(i == 9) textcolor(8);
		}
		else textcolor(9);
		putchar(219);
		
	}
	textcolor(0);
	printf("%c", 219);
	
	//Linha 7 - rodelinha 
	
	gotoxy(ic, (il+6));
	
	printf("%c", 219);
	for(int i = 0; i < 18; i++) 
	{	
		if(i>6 && i <11) textcolor(7);
		else textcolor(9);
		putchar(219);
		
	}
	textcolor(0);
	printf("%c", 219);
	
	// Linha 8
	
	gotoxy(ic, (il+7));
	
	printf("%c", 219);
	textcolor(9);
	for(int i = 0; i < 18; i++) putchar(219);
	textcolor(0);
	printf("%c", 219);
	
	// Linha 9
	
	gotoxy(ic, (il+8));
	
	printf("%c", 219);
	textcolor(9);
	for(int i = 0; i < 18; i++) putchar(219);
	textcolor(0);
	printf("%c", 219);
	
	// Linha 10 => Borda de baixo
	textcolor(0);
	gotoxy(ic, (il+9)); 
	for(int i = 0; i < 20; i++) putchar(219);
	
}

void lupa(int ic, int il)
{
	textcolor(0);
	// Linha 1 - Borda Preta
	gotoxy(ic+6, il); printf("%c%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219);	
	// Linha 2  
	gotoxy(ic+3, il+1); printf("%c%c%c", 219, 219, 219);
	gotoxy(ic+13, il+1); printf("%c%c%c", 219, 219, 219);
	//linha 3
	gotoxy(ic+1, il+2); printf("%c%c", 219, 219);
	gotoxy(ic+16, il+2); printf("%c%c", 219, 219);	
	//linha 4
	gotoxy(ic, il+3);  printf("%c", 219);
	gotoxy(ic+18, il+3); printf("%c", 219);	
	//linha 5
	gotoxy(ic, il+4);	 printf("%c", 219);
	gotoxy(ic+18, il+4); printf("%c", 219);	
	//linha 6
	gotoxy(ic, il+5);  printf("%c", 219);
	gotoxy(ic+18, il+5); printf("%c", 219);	
	//linha 7
	gotoxy(ic+1, il+6); printf("%c%c", 219, 219);
	gotoxy(ic+16, il+6); printf("%c%c", 219, 219);	
	// Linha 8  
	gotoxy(ic+3, il+7); printf("%c%c%c", 219, 219, 219);
	gotoxy(ic+13, il+7); printf("%c%c%c", 219, 219, 219);
	// Linha 9 
	gotoxy(ic+6, il+8); printf("%c%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219);
	
	//Interior Lupa
	textcolor(3);
	gotoxy(ic+6, il+1); printf("%c%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219);
	gotoxy(ic+3, il+2); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	gotoxy(ic+1, il+3); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	gotoxy(ic+1, il+4); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	gotoxy(ic+1, il+5); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	gotoxy(ic+3, il+6); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	gotoxy(ic+6, il+7); printf("%c%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219);
	//brilhinho
	textcolor(15);
	gotoxy(ic+3, il+4); printf("%c", 219);
	gotoxy(ic+4, il+5); printf("%c%c", 219, 219);
	gotoxy(ic+7, il+6); printf("%c", 219);
	
	//cabo
	textcolor(BLACK);
	gotoxy(ic+18, il+5); printf("%c", 219);
	gotoxy(ic+18, il+6); printf("%c%c%c", 219, 219, 219);
	gotoxy(ic+16, il+7); printf("%c%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	gotoxy(ic+18, il+8); printf("%c%c%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	gotoxy(ic+21, il+9); printf("%c%c%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	gotoxy(ic+24, il+10);printf("%c%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	gotoxy(ic+26, il+10);printf("%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	gotoxy(ic+26, il+11);printf("%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	
	
	gotoxy(ic+25, il+15);
	
	// Acabou :D
}

void logo(int ic, int il)
{
	textcolor(0);
	
	gotoxy(ic - 2, il + 6); for(int i = 0; i <= 58; i++) printf("_");
		
	// Linha 1 do texto
	gotoxy(ic+1,il);	printf("%c%c%c%c%c%c",219,219,219,219,219,219);				gotoxy(ic+7,il);	printf("%c",187);
	gotoxy(ic+10,il);	printf("%c%c%c%c%c%c",219,219,219,219,219,219);				gotoxy(ic+16,il);	printf("%c",187);	
	gotoxy(ic+18,il);	printf("%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219);	gotoxy(ic+25,il);	printf("%c",187);
	gotoxy(ic+27,il);	printf("%c%c%c%c%c%c%c",219,219,219,219,219,219,219);		gotoxy(ic+34,il);	printf("%c",187);
	gotoxy(ic+38,il);	printf("%c%c%c%c%c%c",219,219,219,219,219,219);				gotoxy(ic+44,il);	printf("%c",187);
	gotoxy(ic+46,il);	printf("%c%c",219,219);										gotoxy(ic+48,il);	printf("%c",187);
	gotoxy(ic+51,il);	printf("%c%c",219,219);										gotoxy(ic+53,il);	printf("%c",187);
	
	//linha 2
	gotoxy(ic,il+1);	printf("%c%c",219,219);		gotoxy(ic+2,il+1);	printf("%c%c%c%c%c%c",201,205,205,205,205,188);
	gotoxy(ic+9,il+1);	printf("%c%c",219,219);		gotoxy(ic+11,il+1);	printf("%c%c%c%c",201,205,205,205);
	gotoxy(ic+15,il+1);	printf("%c%c",219,219);		gotoxy(ic+17,il+1);	printf("%c",187);
	gotoxy(ic+21,il+1);	printf("%c%c",219,219);		gotoxy(ic+18,il+1);	printf("%c%c%c",200,205,205);
	gotoxy(ic+27,il+1);	printf("%c%c",219,219);		gotoxy(ic+23,il+1);	printf("%c%c%c",201,205,188);
	gotoxy(ic+37,il+1);	printf("%c%c",219,219);		gotoxy(ic+29,il+1);	printf("%c%c%c%c%c%c",201,205,205,205,205,188);
	gotoxy(ic+46,il+1);	printf("%c%c",219,219);		gotoxy(ic+39,il+1);	printf("%c%c%c%c%c%c",201,205,205,205,205,188);
	gotoxy(ic+51,il+1);	printf("%c%c",219,219);		gotoxy(ic+48,il+1);	printf("%c",186);		gotoxy(ic+53,il+1);	printf("%c",186);
		
	//linha 3
	gotoxy(ic,il+2);	printf("%c%c",219,219);									gotoxy(ic+2,il+2);	printf("%c",186);
	gotoxy(ic+5,il+2);	printf("%c%c%c",219,219,219);							gotoxy(ic+8,il+2);	printf("%c",187);
	gotoxy(ic+9,il+2);	printf("%c%c",219,219);									gotoxy(ic+11,il+2);	printf("%c",186);
	gotoxy(ic+15,il+2);	printf("%c%c",219,219);									gotoxy(ic+17,il+2);	printf("%c",186);
	gotoxy(ic+21,il+2);	printf("%c%c",219,219);									gotoxy(ic+23,il+2);	printf("%c",186);
	gotoxy(ic+27,il+2);	printf("%c%c%c%c%c%c",219,219,219,219,219,219);			gotoxy(ic+33,il+2);	printf("%c",187);
	gotoxy(ic+37,il+2);	printf("%c%c",219,219);									gotoxy(ic+39,il+2);	printf("%c",186);
	gotoxy(ic+46,il+2);	printf("%c%c%c%c%c%c%c",219,219,219,219,219,219,219);	gotoxy(ic+53,il+2);	printf("%c",186);
	
	//linha 4
	gotoxy(ic,il+3);	printf("%c%c",219,219);		gotoxy(ic+2,il+3);	printf("%c",186);
	gotoxy(ic+6,il+3);	printf("%c%c",219,219);		gotoxy(ic+8,il+3);	printf("%c",186);
	gotoxy(ic+9,il+3);	printf("%c%c",219,219);		gotoxy(ic+11,il+3);	printf("%c",186);
	gotoxy(ic+15,il+3);	printf("%c%c",219,219);		gotoxy(ic+17,il+3);	printf("%c",186);
	gotoxy(ic+21,il+3);	printf("%c%c",219,219);		gotoxy(ic+23,il+3);	printf("%c",186);
	gotoxy(ic+27,il+3);	printf("%c%c",219,219);		gotoxy(ic+29,il+3);	printf("%c%c%c%c%c",201,205,205,205,188);
	gotoxy(ic+37,il+3);	printf("%c%c",219,219);		gotoxy(ic+39,il+3);	printf("%c",186);
	gotoxy(ic+46,il+3);	printf("%c%c",219,219);		gotoxy(ic+48,il+3);	printf("%c%c%c",201,205,205);
	gotoxy(ic+51,il+3);	printf("%c%c",219,219);		gotoxy(ic+53,il+3);	printf("%c",186);
		
	//linha 5
	gotoxy(ic+1,il+4);	printf("%c%c%c%c%c%c",219,219,219,219,219,219);			gotoxy(ic,il+4);	printf("%c",200);
	gotoxy(ic+10,il+4);	printf("%c%c%c%c%c%c",219,219,219,219,219,219);			gotoxy(ic+7,il+4);	printf("%c%c%c",201,188,200);
	gotoxy(ic+21,il+4);	printf("%c%c",219,219);									gotoxy(ic+16,il+4);	printf("%c%c",201,188);
	gotoxy(ic+27,il+4);	printf("%c%c%c%c%c%c%c",219,219,219,219,219,219,219);	gotoxy(ic+23,il+4);	printf("%c",186);
	gotoxy(ic+38,il+4);	printf("%c%c%c%c%c%c",219,219,219,219,219,219);			gotoxy(ic+34,il+4);	printf("%c",187);
	gotoxy(ic+46,il+4);	printf("%c%c",219,219);									gotoxy(ic+37,il+4);	printf("%c",200);
	gotoxy(ic+51,il+4);	printf("%c%c",219,219);									gotoxy(ic+44,il+4);	printf("%c",187);
	gotoxy(ic+48,il+4);	printf("%c",186);										gotoxy(ic+53,il+4);	printf("%c",186);
	
	//linha 6
		
	gotoxy(ic+1,il+5);	printf("%c%c%c%c%c%c%c",200,205,205,205,205,205,188);
	gotoxy(ic+10,il+5);	printf("%c%c%c%c%c%c%c",200,205,205,205,205,205,188);
	gotoxy(ic+21,il+5);	printf("%c%c%c",200,205,188);
	gotoxy(ic+27,il+5);	printf("%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,188);
	gotoxy(ic+38,il+5);	printf("%c%c%c%c%c%c%c",200,205,205,205,205,205,188);
	gotoxy(ic+46,il+5);	printf("%c%c%c",200,205,188);
	gotoxy(ic+51,il+5);	printf("%c%c%c",200,205,188);
}

void cpu(int ic, int il)
{	
	// Linha 1 => Borda de cima
	textcolor(0);
	gotoxy(ic, il); 
	for(int i = 0; i < 20; i++) putchar(219);
	
	// Linha 2  - tracinho
	gotoxy(ic, (il+1));

	printf("%c", 219);
	textcolor(7);
	for(int i = 0; i < 18; i++) putchar(219);
	textcolor(0);
	printf("%c", 219);
	textcolor(6);
	printf("%c", 219);
	textcolor(0);
	
	// Linha 3  - tracinho
	gotoxy(ic, (il+2));
	
	printf("%c", 219);
	textcolor(7);
	for(int i = 0; i < 18; i++) putchar(219);
	textcolor(0);
	printf("%c", 219);
	textcolor(6);
	printf("%c", 219);
	textcolor(0);
	
	// Linha 4
	
	gotoxy(ic, (il+3));
	
	printf("%c", 219);
	textcolor(7);
	for(int i = 0; i < 18; i++) putchar(219);
	textcolor(0);
	printf("%c", 219);
	textcolor(6);
	printf("%c", 219);
	textcolor(0);
	
	// Linha 5
	
	gotoxy(ic, (il+4));
	
	printf("%c", 219);
	textcolor(7);
	for(int i = 0; i < 18; i++) putchar(219);
	textcolor(0);
	printf("%c", 219);
	textcolor(6);
	printf("%c", 219);
	textcolor(0);
	
	//Linha 6 - rodelinha com tracin
	
	gotoxy(ic, (il+5));
	
	printf("%c", 219);
	textcolor(7);
	for(int i = 0; i < 18; i++) putchar(219);
	textcolor(0);
	printf("%c", 219);
	textcolor(6);
	printf("%c", 219);
	textcolor(0);
	
	//Linha 7 - rodelinha 
	
	gotoxy(ic, (il+6));
	
	printf("%c", 219);
	textcolor(7);
	for(int i = 0; i < 18; i++) putchar(219);
	textcolor(0);
	printf("%c", 219);
	textcolor(6);
	printf("%c", 219);
	textcolor(0);
	
	// Linha 8
	
	gotoxy(ic, (il+7));
	
	printf("%c", 219);
	textcolor(7);
	for(int i = 0; i < 18; i++) putchar(219);
	textcolor(0);
	printf("%c", 219);
	textcolor(6);
	printf("%c", 219);
	textcolor(0);
		
	// Linha 9 
	textcolor(0);
	gotoxy(ic, (il+8)); 
	for(int i = 0; i < 20; i++) putchar(219);
	textcolor(6);
	printf("%c", 219);
	textcolor(0);
	
	// Linha 10 => Borda de baixo
	textcolor(6);
	gotoxy((ic+1), (il+9)); 
	for(int i = 0; i < 20; i++) putchar(219);
	textcolor(0);
	
	//escrever cpu
	gotoxy((ic+3), (il+2)); printf("%c%c%c%c",219,219,219,219);
	gotoxy((ic+3), (il+3)); printf("%c",219);
	gotoxy((ic+3), (il+4)); printf("%c",219);      //etra C
	gotoxy((ic+3), (il+5)); printf("%c",219);
	gotoxy((ic+3), (il+6)); printf("%c%c%c%c",219,219,219,219);
	
	gotoxy((ic+8), (il+2)); printf("%c%c%c%c",219,219,219,219);
	gotoxy((ic+8), (il+3)); printf("%c",219);		//Letra P
	gotoxy((ic+11), (il+3)); printf("%c",219);
	gotoxy((ic+8), (il+4)); printf("%c%c%c%c",219,219,219,219);
	gotoxy((ic+8), (il+5)); printf("%c",219);
	gotoxy((ic+8), (il+6)); printf("%c",219);
	
	gotoxy((ic+13), (il+2)); printf("%c",219);
	gotoxy((ic+16), (il+2)); printf("%c",219);
	gotoxy((ic+13), (il+3)); printf("%c",219);
	gotoxy((ic+16), (il+3)); printf("%c",219);		//Letra U
	gotoxy((ic+13), (il+4)); printf("%c",219);
	gotoxy((ic+16), (il+4)); printf("%c",219);
	gotoxy((ic+13), (il+5)); printf("%c",219);
	gotoxy((ic+16), (il+5)); printf("%c",219);
	gotoxy((ic+13), (il+6)); printf("%c%c%c%c",219,219,219,219);
	
	gotoxy((ic), (il+9)); //s� pro end do programa n�o quebrar as coisas

}

void gpu(int ic, int il)
{	
	// Linha 1 => Borda de cima
	gotoxy(ic, il);
	textcolor(8);
	printf("%c%c%c", 219, 219, 219);
	textcolor(7);	
	for(int i = 0; i < 35; i++) putchar(219);
	
	// Linha 2  - come�o do cooler
	gotoxy(ic, (il+1));
	textcolor(8);
	printf("  %c", 219);
	for(int i = 0; i < 35; i++)
	{
		textcolor(7);
		if( i>14 && i<25)
			textcolor(8);
		putchar(219);
	}
	
	// Linha 3  
	gotoxy(ic, (il+2));
	
	textcolor(8);
	printf("  %c", 219);
	for(int i = 0; i < 35; i++)
	{
		textcolor(2);
		if( i>12 && i<27)
			textcolor(8);
		putchar(219);
	}
	
	// Linha 4
	
	gotoxy(ic, (il+3));
	
	textcolor(8);
	printf("  %c", 219);
	for(int i = 0; i < 35; i++)
	{
		textcolor(10);
		if( i>11 && i<28)
			textcolor(8);
		putchar(219);
	}
	
	// Linha 5	- meio do cooler
	gotoxy(ic, (il+4));
	
	textcolor(8);
	printf("  %c", 219);	
	for(int i = 0; i < 35; i++)
	{
		textcolor(10);
		if( i>10 && i<29)
			textcolor(8);
		putchar(219);
	}
	
	//Linha 6 - 
	
	gotoxy(ic, (il+5));
	
	textcolor(8);
	printf("  %c", 219);
	for(int i = 0; i < 35; i++)
	{
		textcolor(10);
		if( i>11 && i<28)
			textcolor(8);
		putchar(219);
	}
	
	//Linha 7
	
	gotoxy(ic, (il+6));
	
	textcolor(8);
	printf("  %c", 219);
	for(int i = 0; i < 35; i++)
	{
		textcolor(2);
		if( i>12 && i<27)
			textcolor(8);
		putchar(219);
	}
	
	// Linha 8 - final do cooler 
	
	gotoxy(ic, (il+7));
	
	textcolor(8);
	printf("  %c", 219);
	for(int i = 0; i < 35; i++)
	{
		textcolor(7);
		if( i>14 && i<25)
			textcolor(8);
		putchar(219);
	}
	
	// Linha 9
	
	gotoxy(ic, (il+8));
	
	textcolor(8);
	printf("  %c", 219);
	textcolor(7);	
	for(int i = 0; i < 35; i++) putchar(219);
	
	// Linha 10 => Borda de baixo
	gotoxy(ic, (il+9)); 
	
	textcolor(8);
	printf("  %c", 219);
	textcolor(14);	
	for(int i = 0; i < 35; i++) 
		{
			if(i==4 || i == 18)
			{
				textcolor(0);
				putchar(219);
				textcolor(14);
			}
			if(i>3 && i<18)
			putchar(219);
			else
			printf(" ");
		}
	textcolor(0);
	// Acabou :D
}

void ram(int ic, int il)
{	
	// Linha 1 => Borda de cima
	gotoxy(ic, il); 
	
	textcolor(0); printf("%c", 219);
	
	textcolor(2);
	for(int i = 0; i < 41; i++) putchar(219);
	
	textcolor(0); printf("%c", 219);
	
	// Linha 2  - tracinho
	gotoxy(ic, (il+1));
	
	textcolor(0); printf(" %c", 219);
		
	for(int i = 0; i < 33; i++) 
	{
		textcolor(2);
		if((i+1)%5==0) 
		{
			textcolor(7);
			putchar(219);
		}	
		putchar(219);
	}
	
	textcolor(0); printf("%c ", 219);
	
	// Linha 3  - tracinho
	gotoxy(ic, (il+2));
	
	textcolor(0); printf("%c", 219);
	
	textcolor(2);
	putchar(219);
	for(int i = 0; i < 33; i++) 
	{
		textcolor(2);
		if((i+1)%5==0) 
		{
			textcolor(7);
			putchar(219);
		}	
		putchar(219);
	}
	putchar(219);
	textcolor(0); printf("%c", 219);
	
	// Linha 4
	
	gotoxy(ic, (il+3));
	
	textcolor(0); printf(" %c", 219);
	
	textcolor(2);
	for(int i = 0; i < 39; i++) putchar(219);
	
	textcolor(0); printf("%c ", 219);
	
	// Linha 5
	
	gotoxy(ic, (il+4));
	textcolor(0); printf("%c", 219);
	
	for(int i = 0; i < 41; i++) 
	{
		textcolor(2);
		if((i+1)%2==0)
		textcolor(14);
		putchar(219);
	}
	
	textcolor(0); printf("%c", 219);
	
}

void mobo(int ic, int il)
{
	// Construir o PCB bruto
	gotoxy(ic, il); 
	textcolor(0);	
	for(int i = 0; i < 20; i++) 
	{	
		for(int j = 0; j < 10; j++)
		{
		gotoxy((ic+i), (il+j));
		putchar(219);
		}
	}
	
	//Construir os detalhes
	textcolor(7);
	gotoxy(ic, (il+1)); printf("%c%c",219,219);
	gotoxy(ic, (il+2)); printf("%c%c",219,219);
	gotoxy(ic, (il+3)); printf("%c%c",219,219);		//IO traseiro
	gotoxy(ic, (il+4)); printf("%c%c",219,219);
	gotoxy(ic, (il+5)); printf("%c%c",219,219);
	
	textcolor(7);
	gotoxy((ic+6), (il+2)); printf("%c",219);
	gotoxy((ic+6), (il+3)); printf("%c",219);
	gotoxy((ic+9), (il+2)); printf("%c",219);		//socket do cpu
	gotoxy((ic+9), (il+3)); printf("%c",219);
	textcolor(14);
	gotoxy((ic+7), (il+2)); printf("%c%c",219,219);
	gotoxy((ic+7), (il+3)); printf("%c%c",219,219);
	
	textcolor(2);
	gotoxy((ic+13), (il+1)); printf("%c",219);
	gotoxy((ic+13), (il+2)); printf("%c",219);
	gotoxy((ic+13), (il+3)); printf("%c",219);    //slots de ram e etc
	gotoxy((ic+13), (il+4)); printf("%c",219);
	gotoxy((ic+15), (il+1)); printf("%c",219);
	gotoxy((ic+15), (il+2)); printf("%c",219);
	gotoxy((ic+15), (il+3)); printf("%c",219);
	gotoxy((ic+15), (il+4)); printf("%c",219);	
	gotoxy((ic+18), (il+1)); printf("%c%c",219,219);
	
	textcolor(8);
	gotoxy((ic+18), (il+3)); printf("%c%c",219,219);    //conectores 24 pinos e etc
	gotoxy((ic+18), (il+4)); printf("%c%c",219,219);
	
	gotoxy((ic+4), (il+6)); printf("%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219);  //slots pci-e
	gotoxy((ic+4), (il+8)); printf("%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219);
	
	textcolor(RED);
	gotoxy((ic+15), (il+6)); printf("%c%c",219,219); //dissipador do chipset
	gotoxy((ic+15), (il+7)); printf("%c%c",219,219);
	
	textcolor(15);
	gotoxy((ic+14), (il+9)); printf("%c%c%c%c",219,219,219,219);
	textcolor(0);
	
	gotoxy((ic+10), (il+10));	// tirar o exit do programa de perto
}

void textcolor(int newcolor) // Define a cor do texto
{
   CONSOLE_SCREEN_BUFFER_INFO csbi;

   GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 
      (csbi.wAttributes & 0xf0) | newcolor);
   vActual.attribute = (csbi.wAttributes & 0xf0) | newcolor;
}

void textbackground(int newcolor) // Define a cor do fundo
{
   CONSOLE_SCREEN_BUFFER_INFO csbi;

   GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 
      (csbi.wAttributes & 0x0f) | (newcolor << 4));
   vActual.attribute = (csbi.wAttributes & 0x0f) | (newcolor << 4);
}

void gotoxy(int x, int y)	// Move o cursor para a coluna e linha desejada
{
  COORD c;
  c.X = x - 1;
  c.Y = y - 1;
  SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void cursor (int x) { 	// Define se o cursor ira aparecer (1) ou n�o (0)
	switch (x) {
		case 0: {
			CONSOLE_CURSOR_INFO cursor = {1, FALSE};
			SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
			break;
		}
		case 1: {
			CONSOLE_CURSOR_INFO cursor = {1, TRUE};
			SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
			break;
		}
	}
}

void clreol(int x)  //fun��o customizada e mais vers�til para o programa do clreol da conio.h
{
   for(int i=0; i < x; i++)
           printf(" ");         //preenche com "vazio/em branco" X espa�os escolhidos
       for(int i=0; i < x; i++)
           printf("\b");		//volta X vezes o cursor para tr�s para a posi��o original ap�s limpar a linha
}

