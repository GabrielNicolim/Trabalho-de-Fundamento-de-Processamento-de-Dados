//Arquivo fonte para funções de desenhos do programa como a borda e os icones de:
// - Disquete, Logo, Lupa, CPU, GPU, RAM, Mobo, HDD	

// Definição de cores 
#define cor_fundo 3
#define cor_borda 1
#define cor_texto 15
#define cor_destaque 0
#define RED 12

//Lembrar esse arquivo das funções conio
void gotoxy(int x, int y);
void textcolor(int newcolor);
void textbackground(int newcolor);

//Desenhos vão ficar todos aqui
void borda() 
{
	textbackground(cor_fundo); // Define cor do fundo
	system("cls"); 		//limpa sempre a tela quando é chamada
	
	textcolor(cor_borda);
	for (int i=2; i <= 33; i++) // Borda esquerda e direita
	{
		gotoxy(9,i);printf("%c%c                                                                                                                                            %c%c",219,219,219,219);
	}
	
	for (int i = 9; i <= (160 - 8); i++) // Parte de cima da borda
	{
		gotoxy(i,2);printf("%c",219);
	}
	for (int i = 9; i <= (160 - 8); i++) // Parte de baixo da borda 
	{
		gotoxy(i,33);printf("%c",219);
	}
			
	textcolor(cor_texto); // Define cor do texto
	
}

void disquete(int coluna, int linha)
{
	// Linha 1 => Borda de cima
	textcolor(cor_destaque);
	gotoxy(coluna, linha); 
	for(int i = 0; i < 20; i++) putchar(219);
	
	// Linha 2  - tracinho
	gotoxy(coluna, (linha+1));
	textcolor(cor_destaque);
	printf("%c", 219);
	textcolor(9);
	for(int i = 0; i < 18; i++) putchar(219);
	textcolor(cor_destaque);
	printf("%c", 219);
	
	// Linha 3  - tracinho
	gotoxy(coluna, (linha+2));
	textcolor(cor_destaque);
	printf("%c", 219);
	textcolor(9);
	for(int i = 0; i < 18; i++) putchar(219);
	textcolor(cor_destaque);
	printf("%c", 219);

	//detalhes internos
	textbackground(7);
	textcolor(cor_destaque);
	gotoxy(coluna+3, linha+1); printf("  %c%c          ",219,219);
	gotoxy(coluna+3, linha+2); printf("  %c%c          ",219,219);
	
	// Linha 4
	
	gotoxy(coluna, (linha+3));
	
	printf("%c", 219);
	textcolor(9);
	for(int i = 0; i < 18; i++) putchar(219);
	textcolor(cor_destaque);
	printf("%c", 219);
	
	// Linha 5
	
	gotoxy(coluna, (linha+4));
	printf("%c", 219);
	textcolor(9);

	for(int i = 0; i < 18; i++) putchar(219);
	textcolor(cor_destaque);
	printf("%c", 219);
	
	//Linha 6 - rodelinha com tracin
	
	gotoxy(coluna, (linha+5));
	
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
	textcolor(cor_destaque);
	printf("%c", 219);
	
	//Linha 7 - rodelinha 
	
	gotoxy(coluna, (linha+6));
	
	printf("%c", 219);
	for(int i = 0; i < 18; i++) 
	{	
		if(i>6 && i <11) textcolor(7);
		else textcolor(9);
		putchar(219);
		
	}
	textcolor(cor_destaque);
	printf("%c", 219);
	
	// Linha 8
	
	gotoxy(coluna, (linha+7));
	
	printf("%c", 219);
	textcolor(9);
	for(int i = 0; i < 18; i++) putchar(219);
	textcolor(cor_destaque);
	printf("%c", 219);
	
	// Linha 9
	
	gotoxy(coluna, (linha+8));
	
	printf("%c", 219);
	textcolor(9);
	for(int i = 0; i < 18; i++) putchar(219);
	textcolor(cor_destaque);
	printf("%c", 219);
	
	// Linha 10 => Borda de baixo
	textcolor(cor_destaque);
	gotoxy(coluna, (linha+9)); 
	for(int i = 0; i < 20; i++) putchar(219);
	textbackground(cor_fundo);
}

void logo(int coluna, int linha)
{
	textcolor(cor_destaque);
	
	gotoxy(coluna - 2, linha + 6); for(int i = 0; i <= 58; i++) printf("_");
		
	// Linha 1 do texto
	gotoxy(coluna+1,linha);	printf("%c%c%c%c%c%c",219,219,219,219,219,219);				gotoxy(coluna+7,linha);	printf("%c",187);
	gotoxy(coluna+10,linha);	printf("%c%c%c%c%c%c",219,219,219,219,219,219);				gotoxy(coluna+16,linha);	printf("%c",187);	
	gotoxy(coluna+18,linha);	printf("%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219);	gotoxy(coluna+25,linha);	printf("%c",187);
	gotoxy(coluna+27,linha);	printf("%c%c%c%c%c%c%c",219,219,219,219,219,219,219);		gotoxy(coluna+34,linha);	printf("%c",187);
	gotoxy(coluna+38,linha);	printf("%c%c%c%c%c%c",219,219,219,219,219,219);				gotoxy(coluna+44,linha);	printf("%c",187);
	gotoxy(coluna+46,linha);	printf("%c%c",219,219);										gotoxy(coluna+48,linha);	printf("%c",187);
	gotoxy(coluna+51,linha);	printf("%c%c",219,219);										gotoxy(coluna+53,linha);	printf("%c",187);
	
	//linha 2
	gotoxy(coluna,linha+1);	printf("%c%c",219,219);		gotoxy(coluna+2,linha+1);	printf("%c%c%c%c%c%c",201,205,205,205,205,188);
	gotoxy(coluna+9,linha+1);	printf("%c%c",219,219);		gotoxy(coluna+11,linha+1);	printf("%c%c%c%c",201,205,205,205);
	gotoxy(coluna+15,linha+1);	printf("%c%c",219,219);		gotoxy(coluna+17,linha+1);	printf("%c",187);
	gotoxy(coluna+21,linha+1);	printf("%c%c",219,219);		gotoxy(coluna+18,linha+1);	printf("%c%c%c",200,205,205);
	gotoxy(coluna+27,linha+1);	printf("%c%c",219,219);		gotoxy(coluna+23,linha+1);	printf("%c%c%c",201,205,188);
	gotoxy(coluna+37,linha+1);	printf("%c%c",219,219);		gotoxy(coluna+29,linha+1);	printf("%c%c%c%c%c%c",201,205,205,205,205,188);
	gotoxy(coluna+46,linha+1);	printf("%c%c",219,219);		gotoxy(coluna+39,linha+1);	printf("%c%c%c%c%c%c",201,205,205,205,205,188);
	gotoxy(coluna+51,linha+1);	printf("%c%c",219,219);		gotoxy(coluna+48,linha+1);	printf("%c",186);		gotoxy(coluna+53,linha+1);	printf("%c",186);
		
	//linha 3
	gotoxy(coluna,linha+2);	printf("%c%c",219,219);									gotoxy(coluna+2,linha+2);	printf("%c",186);
	gotoxy(coluna+5,linha+2);	printf("%c%c%c",219,219,219);							gotoxy(coluna+8,linha+2);	printf("%c",187);
	gotoxy(coluna+9,linha+2);	printf("%c%c",219,219);									gotoxy(coluna+11,linha+2);	printf("%c",186);
	gotoxy(coluna+15,linha+2);	printf("%c%c",219,219);									gotoxy(coluna+17,linha+2);	printf("%c",186);
	gotoxy(coluna+21,linha+2);	printf("%c%c",219,219);									gotoxy(coluna+23,linha+2);	printf("%c",186);
	gotoxy(coluna+27,linha+2);	printf("%c%c%c%c%c%c",219,219,219,219,219,219);			gotoxy(coluna+33,linha+2);	printf("%c",187);
	gotoxy(coluna+37,linha+2);	printf("%c%c",219,219);									gotoxy(coluna+39,linha+2);	printf("%c",186);
	gotoxy(coluna+46,linha+2);	printf("%c%c%c%c%c%c%c",219,219,219,219,219,219,219);	gotoxy(coluna+53,linha+2);	printf("%c",186);
	
	//linha 4
	gotoxy(coluna,linha+3);	printf("%c%c",219,219);		gotoxy(coluna+2,linha+3);	printf("%c",186);
	gotoxy(coluna+6,linha+3);	printf("%c%c",219,219);		gotoxy(coluna+8,linha+3);	printf("%c",186);
	gotoxy(coluna+9,linha+3);	printf("%c%c",219,219);		gotoxy(coluna+11,linha+3);	printf("%c",186);
	gotoxy(coluna+15,linha+3);	printf("%c%c",219,219);		gotoxy(coluna+17,linha+3);	printf("%c",186);
	gotoxy(coluna+21,linha+3);	printf("%c%c",219,219);		gotoxy(coluna+23,linha+3);	printf("%c",186);
	gotoxy(coluna+27,linha+3);	printf("%c%c",219,219);		gotoxy(coluna+29,linha+3);	printf("%c%c%c%c%c",201,205,205,205,188);
	gotoxy(coluna+37,linha+3);	printf("%c%c",219,219);		gotoxy(coluna+39,linha+3);	printf("%c",186);
	gotoxy(coluna+46,linha+3);	printf("%c%c",219,219);		gotoxy(coluna+48,linha+3);	printf("%c%c%c",201,205,205);
	gotoxy(coluna+51,linha+3);	printf("%c%c",219,219);		gotoxy(coluna+53,linha+3);	printf("%c",186);
		
	//linha 5
	gotoxy(coluna+1,linha+4);	printf("%c%c%c%c%c%c",219,219,219,219,219,219);			gotoxy(coluna,linha+4);	printf("%c",200);
	gotoxy(coluna+10,linha+4);	printf("%c%c%c%c%c%c",219,219,219,219,219,219);			gotoxy(coluna+7,linha+4);	printf("%c%c%c",201,188,200);
	gotoxy(coluna+21,linha+4);	printf("%c%c",219,219);									gotoxy(coluna+16,linha+4);	printf("%c%c",201,188);
	gotoxy(coluna+27,linha+4);	printf("%c%c%c%c%c%c%c",219,219,219,219,219,219,219);	gotoxy(coluna+23,linha+4);	printf("%c",186);
	gotoxy(coluna+38,linha+4);	printf("%c%c%c%c%c%c",219,219,219,219,219,219);			gotoxy(coluna+34,linha+4);	printf("%c",187);
	gotoxy(coluna+46,linha+4);	printf("%c%c",219,219);									gotoxy(coluna+37,linha+4);	printf("%c",200);
	gotoxy(coluna+51,linha+4);	printf("%c%c",219,219);									gotoxy(coluna+44,linha+4);	printf("%c",187);
	gotoxy(coluna+48,linha+4);	printf("%c",186);										gotoxy(coluna+53,linha+4);	printf("%c",186);
	
	//linha 6
		
	gotoxy(coluna+1,linha+5);	printf("%c%c%c%c%c%c%c",200,205,205,205,205,205,188);
	gotoxy(coluna+10,linha+5);	printf("%c%c%c%c%c%c%c",200,205,205,205,205,205,188);
	gotoxy(coluna+21,linha+5);	printf("%c%c%c",200,205,188);
	gotoxy(coluna+27,linha+5);	printf("%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,188);
	gotoxy(coluna+38,linha+5);	printf("%c%c%c%c%c%c%c",200,205,205,205,205,205,188);
	gotoxy(coluna+46,linha+5);	printf("%c%c%c",200,205,188);
	gotoxy(coluna+51,linha+5);	printf("%c%c%c",200,205,188);
}

void lupa(int coluna, int linha)
{	
	textcolor(cor_destaque);
	textbackground(cor_fundo);
	// Linha 1 - Borda Preta
	gotoxy(coluna+4, linha); 		printf("%c%c%c%c%c%c%c%c%c%c%c",220 ,220, 219, 219, 219, 219, 219, 219, 219, 220, 220);	
	// Linha 2  
	gotoxy(coluna+2, linha+1); 	printf("%c%c%c%c", 220, 219, 219, 223);
	gotoxy(coluna+13, linha+1); 	printf("%c%c%c%c", 223, 219, 219, 220);
	//linha 3
	gotoxy(coluna+1, linha+2); 	printf("%c%c", 219, 223);
	gotoxy(coluna+16, linha+2); 	printf("%c%c", 223, 219);	
	//linha 4
	gotoxy(coluna, linha+3);  		printf("%c%c", 219, 223);
	gotoxy(coluna+17, linha+3); 	printf("%c%c", 223, 219);	
	//linha 5
	gotoxy(coluna, linha+4);	 	printf("%c", 219);
	gotoxy(coluna+18, linha+4);	printf("%c", 219);	
	//linha 6
	gotoxy(coluna, linha+5);  		printf("%c%c", 219, 220);
	gotoxy(coluna+17, linha+5);	printf("%c%c", 220, 219);	
	//linha 7
	gotoxy(coluna+1, linha+6);		printf("%c%c", 219, 220);
	gotoxy(coluna+16, linha+6);	printf("%c%c", 220, 219);	
	// Linha 8  
	gotoxy(coluna+2, linha+7); 	printf("%c%c%c%c", 223, 219, 219, 220);
	gotoxy(coluna+13, linha+7); 	printf("%c%c%c%c", 220, 219, 219, 223);
	// Linha 9 
	gotoxy(coluna+4, linha+8); 	printf("%c%c%c%c%c%c%c%c%c%c%c",223 ,223, 219, 219, 219, 219, 219, 219, 219, 223, 223);		
	
	//brilhinho
	textcolor(cor_texto);
	gotoxy(coluna+3, linha+4); printf("%c", 219);
	gotoxy(coluna+4, linha+5); printf("%c%c%c", 219, 219, 220);
	gotoxy(coluna+7, linha+6); printf("%c%c", 219, 220);
	
	//cabo
	textcolor(cor_texto);
	gotoxy(coluna+18, linha+6); printf("%c%c", 219,220);
	gotoxy(coluna+16, linha+7); printf("%c%c%c%c%c%c", 219, 219, 219, 219, 219, 220);
	gotoxy(coluna+15, linha+8); printf("%c%c%c%c%c%c%c%c%c", 223, 223, 219, 219, 219, 219, 219, 219,220);
	gotoxy(coluna+18, linha+9); printf("%c%c%c%c%c%c%c%c", 223, 219, 219, 219, 219, 219, 219, 220);			//cabo
	gotoxy(coluna+20, linha+10);printf("%c%c%c%c%c%c%c%c", 223, 219, 219, 219, 219, 219, 219, 220);
	gotoxy(coluna+22, linha+11);printf("%c%c%c%c%c%c%c", 223, 219, 219, 219, 219, 219, 219);
	gotoxy(coluna+24, linha+12);printf("%c%c%c%c%c%c", 223, 219, 219, 219, 219,223);
	
	// Acabou :D
}

void cpu(int coluna, int linha)
{	
	//Quadrados básicos:
	textbackground(6);
	for(int i = 1; i < 10; i++){
		gotoxy(coluna+1, linha+i); printf("                    ");
	}
	
	textbackground(cor_destaque);
	for(int i = 0; i < 9; i++){
		gotoxy(coluna, linha+i); printf("                    ");
	}
	
	textbackground(7);
	for(int i = 1; i < 8; i++){
		gotoxy(coluna+1, linha+i); printf("                  ");
	}
	
	//escrita C P U
	textcolor(cor_destaque);
	gotoxy(coluna, linha); 
	for(int i = 0; i < 20; i++) putchar(219);
	
	// Linha 2  - tracinho
	gotoxy(coluna, (linha+1));

	printf("%c", 219);
	textcolor(7);
	for(int i = 0; i < 18; i++) putchar(219);
	textcolor(cor_destaque);
	printf("%c", 219);
	textcolor(6);
	printf("%c", 219);
	textcolor(cor_destaque);
	
	// Linha 3  - tracinho
	gotoxy(coluna, (linha+2));
	
	printf("%c", 219);
	textcolor(7);
	for(int i = 0; i < 18; i++) putchar(219);
	textcolor(cor_destaque);
	printf("%c", 219);
	textcolor(6);
	printf("%c", 219);
	textcolor(cor_destaque);
	
	// Linha 4
	
	gotoxy(coluna, (linha+3));
	
	printf("%c", 219);
	textcolor(7);
	for(int i = 0; i < 18; i++) putchar(219);
	textcolor(cor_destaque);
	printf("%c", 219);
	textcolor(6);
	printf("%c", 219);
	textcolor(cor_destaque);
	
	// Linha 5
	
	gotoxy(coluna, (linha+4));
	
	printf("%c", 219);
	textcolor(7);
	for(int i = 0; i < 18; i++) putchar(219);
	textcolor(cor_destaque);
	printf("%c", 219);
	textcolor(6);
	printf("%c", 219);
	textcolor(cor_destaque);
	
	//Linha 6 - rodelinha com tracin
	
	gotoxy(coluna, (linha+5));
	
	printf("%c", 219);
	textcolor(7);
	for(int i = 0; i < 18; i++) putchar(219);
	textcolor(cor_destaque);
	printf("%c", 219);
	textcolor(6);
	printf("%c", 219);
	textcolor(cor_destaque);
	
	//Linha 7 - rodelinha 
	
	gotoxy(coluna, (linha+6));
	
	printf("%c", 219);
	textcolor(7);
	for(int i = 0; i < 18; i++) putchar(219);
	textcolor(cor_destaque);
	printf("%c", 219);
	textcolor(6);
	printf("%c", 219);
	textcolor(cor_destaque);
	
	// Linha 8
	
	gotoxy(coluna, (linha+7));
	
	printf("%c", 219);
	textcolor(7);
	for(int i = 0; i < 18; i++) putchar(219);
	textcolor(cor_destaque);
	printf("%c", 219);
	textcolor(6);
	printf("%c", 219);
	textcolor(cor_destaque);
		
	// Linha 9 
	textcolor(cor_destaque);
	gotoxy(coluna, (linha+8)); 
	for(int i = 0; i < 20; i++) putchar(219);
	textcolor(6);
	printf("%c", 219);
	textcolor(cor_destaque);
	
	// Linha 10 => Borda de baixo
	textcolor(6);
	gotoxy((coluna+1), (linha+9)); 
	for(int i = 0; i < 20; i++) putchar(219);
	textcolor(cor_destaque);
	
	//escrever cpu
	gotoxy((coluna+3), (linha+2)); printf("%c%c%c%c",219,219,219,219);
	gotoxy((coluna+3), (linha+3)); printf("%c",219);
	gotoxy((coluna+3), (linha+4)); printf("%c",219);      //etra C
	gotoxy((coluna+3), (linha+5)); printf("%c",219);
	gotoxy((coluna+3), (linha+6)); printf("%c%c%c%c",219,219,219,219);
	
	gotoxy((coluna+8), (linha+2)); printf("%c%c%c%c",219,219,219,219);
	gotoxy((coluna+8), (linha+3)); printf("%c",219);		//Letra P
	gotoxy((coluna+11), (linha+3)); printf("%c",219);
	gotoxy((coluna+8), (linha+4)); printf("%c%c%c%c",219,219,219,219);
	gotoxy((coluna+8), (linha+5)); printf("%c",219);
	gotoxy((coluna+8), (linha+6)); printf("%c",219);
	
	gotoxy((coluna+13), (linha+2)); printf("%c",219);
	gotoxy((coluna+16), (linha+2)); printf("%c",219);
	gotoxy((coluna+13), (linha+3)); printf("%c",219);
	gotoxy((coluna+16), (linha+3)); printf("%c",219);		//Letra U
	gotoxy((coluna+13), (linha+4)); printf("%c",219);
	gotoxy((coluna+16), (linha+4)); printf("%c",219);
	gotoxy((coluna+13), (linha+5)); printf("%c",219);
	gotoxy((coluna+16), (linha+5)); printf("%c",219);
	gotoxy((coluna+13), (linha+6)); printf("%c%c%c%c",219,219,219,219);
	
	gotoxy((coluna), (linha+9)); //só pro end do programa não quebrar as coisas
	textbackground(cor_fundo);
}

void gpu(int coluna, int linha)
{	
	// Linha 1 => Borda de cima
	gotoxy(coluna, linha);
	textcolor(8);
	printf("%c%c%c", 219, 219, 219);
	textcolor(7);	
	for(int i = 0; i < 35; i++) putchar(219);
	
	// Linha 2  - começo do cooler
	gotoxy(coluna, (linha+1));
	textcolor(8);
	printf("  %c", 219);
	for(int i = 0; i < 35; i++)
	{
		textcolor(7);
		if( i>14 && i<25)
			textcolor(8);
		putchar(219);
	}
	
	//fundo principal	
	textbackground(7);
	for(int i = 0; i < 9; i++){
		gotoxy(coluna+3,linha+i); printf("                                   ");
	} 
	
	//adesivo generico
	textbackground(2);
	gotoxy(coluna+3,linha+2);	printf("                                   ");
	gotoxy(coluna+3,linha+6);	printf("                                   ");
	textbackground(10);
	gotoxy(coluna+3,linha+3);	printf("                                   ");
	gotoxy(coluna+3,linha+4);	printf("                                   ");
	gotoxy(coluna+3,linha+5);	printf("                                   ");
	
	textbackground(8); 
	textcolor(cor_destaque);
	// Linha 2  - começo do cooler	
	gotoxy(coluna+18, linha+1); printf("   %c      ",219);
	// Linha 3  
	gotoxy(coluna, (linha+2));
	
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
	
	gotoxy(coluna, (linha+3));
	
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
	gotoxy(coluna, (linha+4));
	
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
	
	gotoxy(coluna, (linha+5));
	
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
	
	gotoxy(coluna, (linha+6));
	
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
	
	gotoxy(coluna, (linha+7));
	
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
	
	gotoxy(coluna, (linha+8));
	
	textcolor(8);
	printf("  %c", 219);
	textcolor(7);	
	for(int i = 0; i < 35; i++) putchar(219);
	
	// Linha 10 => Borda de baixo
	gotoxy(coluna, (linha+9)); 
	
	textcolor(8);
	printf("  %c", 219);
	textcolor(14);	
	for(int i = 0; i < 35; i++) 
		{
			if(i==4 || i == 18)
			{
				textcolor(cor_destaque);
				putchar(219);
				textcolor(14);
			}
			if(i>3 && i<18)
			putchar(219);
			else
			printf(" ");
		}
	textcolor(cor_destaque);
	// Acabou :D
}

void ram(int coluna, int linha)
{	
	// Linha 1 => Borda de cima
	gotoxy(coluna, linha); 
	
	textcolor(cor_destaque); printf("%c", 219);
	
	textcolor(2);
	for(int i = 0; i < 41; i++) putchar(219);
	
	textcolor(cor_destaque); printf("%c", 219);
	
	// Linha 2  - tracinho
	gotoxy(coluna, (linha+1));
	
	textcolor(cor_destaque); printf(" %c", 219);
		
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
	
	textcolor(cor_destaque); printf("%c ", 219);
	
	// Linha 3  - tracinho
	gotoxy(coluna, (linha+2));
	
	textcolor(cor_destaque); printf("%c", 219);
	
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
	textcolor(cor_destaque); printf("%c", 219);
	
	// Linha 4
	
	gotoxy(coluna, (linha+3));
	
	textcolor(cor_destaque); printf(" %c", 219);
	
	textcolor(2);
	for(int i = 0; i < 39; i++) putchar(219);
	
	textcolor(cor_destaque); printf("%c ", 219);
	
	// Linha 5
	
	gotoxy(coluna, (linha+4));
	textcolor(cor_destaque); printf("%c", 219);
	
	for(int i = 0; i < 41; i++) 
	{
		textcolor(2);
		if((i+1)%2==0)
		textcolor(14);
		putchar(219);
	}
	
	textcolor(cor_destaque); printf("%c", 219);
	
	//modulos de memória
	textcolor(7);
	gotoxy(coluna+6,linha+1); printf("%c%c    %c%c    %c%c    %c%c    %c%c    %c%c",219,219,219,219,219,219,219,219,219,219,219,219);
	gotoxy(coluna+6,linha+2); printf("%c%c    %c%c    %c%c    %c%c    %c%c    %c%c",219,219,219,219,219,219,219,219,219,219,219,219);

	//e contatos
	textcolor(14);
	gotoxy(coluna+2,linha+4); printf("%c %c %c %c %c %c %c %c   %c %c %c %c %c %c %c %c %c %c %c %c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
}

void mobo(int coluna, int linha)
{
	// Construir o PCB bruto
	gotoxy(coluna, linha); 
	textcolor(cor_destaque);	
	for(int i = 0; i < 20; i++) 
	{	
		for(int j = 0; j < 10; j++)
		{
		gotoxy((coluna+i), (linha+j));
		putchar(219);
		}
	}
	
	//Construir os detalhes
	textcolor(7);
	gotoxy(coluna, (linha+1)); printf("%c%c",219,219);
	gotoxy(coluna, (linha+2)); printf("%c%c",219,219);
	gotoxy(coluna, (linha+3)); printf("%c%c",219,219);		//IO traseiro
	gotoxy(coluna, (linha+4)); printf("%c%c",219,219);
	gotoxy(coluna, (linha+5)); printf("%c%c",219,219);
	
	textcolor(7);
	gotoxy((coluna+6), (linha+2)); printf("%c",219);
	gotoxy((coluna+6), (linha+3)); printf("%c",219);
	gotoxy((coluna+9), (linha+2)); printf("%c",219);		//socket do cpu
	gotoxy((coluna+9), (linha+3)); printf("%c",219);
	textcolor(14);
	gotoxy((coluna+7), (linha+2)); printf("%c%c",219,219);
	gotoxy((coluna+7), (linha+3)); printf("%c%c",219,219);
	
	textcolor(2);
	gotoxy((coluna+13), (linha+1)); printf("%c",219);
	gotoxy((coluna+13), (linha+2)); printf("%c",219);
	gotoxy((coluna+13), (linha+3)); printf("%c",219);    //slots de ram e etc
	gotoxy((coluna+13), (linha+4)); printf("%c",219);
	gotoxy((coluna+15), (linha+1)); printf("%c",219);
	gotoxy((coluna+15), (linha+2)); printf("%c",219);
	gotoxy((coluna+15), (linha+3)); printf("%c",219);
	gotoxy((coluna+15), (linha+4)); printf("%c",219);	
	gotoxy((coluna+18), (linha+1)); printf("%c%c",219,219);
	
	textcolor(8);
	gotoxy((coluna+18), (linha+3)); printf("%c%c",219,219);    //conectores 24 pinos e etc
	gotoxy((coluna+18), (linha+4)); printf("%c%c",219,219);
	
	gotoxy((coluna+4), (linha+6)); printf("%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219);  //slots pci-e
	gotoxy((coluna+4), (linha+8)); printf("%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219);
	
	textcolor(RED);
	gotoxy((coluna+15), (linha+6)); printf("%c%c",219,219); //dissipador do chipset
	gotoxy((coluna+15), (linha+7)); printf("%c%c",219,219);
	
	textcolor(cor_texto);
	gotoxy((coluna+14), (linha+9)); printf("%c%c%c%c",219,219,219,219);
	textcolor(cor_destaque);
	
	gotoxy((coluna+10), (linha+10));	// tirar o exit do programa de perto
}

void HDD(int coluna, int linha)
{
	textcolor(cor_destaque);
	for(int i = 0; i < 21; i++) 
	{	
		for(int j = 0; j < 12; j++)
		{
		gotoxy((coluna+i), (linha+j));
		putchar(219);
		}
	}
	textbackground(cor_destaque);
	textcolor(7);
	gotoxy(coluna+6,linha+1);		printf("%c%c%c%c%c%c%c%c%c",220,220,219,219,219,219,219,220,220);
	gotoxy(coluna+4,linha+2);		printf("%c%c%c%c%c%c%c%c%c%c%c%c%c",220,219,219,219,219,219,219,219,219,219,219,219,220);
	gotoxy(coluna+4,linha+3);		printf("%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219);		//disco magnético
	gotoxy(coluna+4,linha+4);		printf("%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219);		//e parafusos
	gotoxy(coluna+5,linha+5);		printf("%c%c%c%c%c%c%c%c%c%c%c",223,219,219,219,219,219,219,219,219,219,223);
	gotoxy(coluna+8,linha+6);		printf("%c%c%c%c%c",223,223,223,223,223);
	gotoxy(coluna+1,linha);		printf("%c",220);	gotoxy(coluna+1,linha+11);		printf("%c",223);
	gotoxy(coluna+1,linha+5);		printf("%c",223);	gotoxy(coluna+19,linha+5);		printf("%c",223);
	gotoxy(coluna+19,linha);		printf("%c",220);	gotoxy(coluna+19,linha+11);	printf("%c",223);
		
	
	textcolor(2);
	gotoxy(coluna+10,linha+7);		printf("%c%c%c%c%c%c%c%c",220,220,220,220,220,220,220,220);
	gotoxy(coluna+10,linha+8);		printf("%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219); // pcb
	gotoxy(coluna+12,linha+9);		printf("%c%c%c%c%c%c",219,219,219,219,219,219);
	gotoxy(coluna+13,linha+10);	printf("%c%c%c%c%c",219,219,219,219,219);
	textcolor(8);
	gotoxy(coluna+14,linha+8);		printf("%c%c%c",219,219,219);
	gotoxy(coluna+15,linha+9);		printf("%c%c",219,219);
	
	textcolor(7);
	gotoxy(coluna+3,linha+6);		printf("%c",220);
	gotoxy(coluna+3,linha+7);		printf("%c%c%c",219,219,220);										//baia para a agulha
	gotoxy(coluna+3,linha+8);		printf("%c%c%c%c%c",219,219,219,219,220);
	gotoxy(coluna+3,linha+9);		printf("%c%c%c%c%c%c%c%c",219,219,219,219,219,219,220,220);
	gotoxy(coluna+3,linha+10);		printf("%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,220,220);
	
	textcolor(8);
	textbackground(7);
	//gotoxy(coluna+9,linha+4);		printf("%c",220);
	gotoxy(coluna+9,linha+5);		printf("%c",219);
	gotoxy(coluna+8,linha+6);		printf("%c%c",219,219);	
	gotoxy(coluna+7,linha+7);		printf("%c%c%c",219,219,219);			//agulha
	gotoxy(coluna+6,linha+8);		printf("%c%c%c",219,219,219);	
	gotoxy(coluna+5,linha+9);		printf("%c%c%c%c",219,219,219,219);
	gotoxy(coluna+6,linha+10);		printf("%c%c",223,223);	
	
	textcolor(cor_destaque);
	gotoxy(coluna+9,linha+3);		printf("%c%c%c",220,219,220);		///motor para o disco
	gotoxy(coluna+10,linha+4);		printf("%c",223);
	
	textbackground(cor_fundo);
}
