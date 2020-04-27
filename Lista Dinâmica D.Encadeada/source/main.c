#include "lista.h"
#include <stdio.h>

int main()
{	
	Lista *li = cria_lista();

	Aluno al, al2;
	al.matricula = 12;
	al2.matricula = 13;

	insere_ord (li, al);
	insere_ord (li, al2);

	remove_ord(li, 12);
	remove_ord(li, 13);
	echo(li);

	libera_lista(li);
















	/*
	Lista* li;
	li = cria_lista();
	Aluno al, al2, al3;
	al.matricula = 123;
	al2.matricula = 124;
	al3.matricula = 125;

	insere_ord(li, al);
	insere_ord(li, al2);
	insere_ord (li, al3);
	//remove_inicio(li);
	//remove_final (li);
	
	
	remove_ord (li, 124);
	echo(li);
	printf("%i\n",tamanho_lista(li));
	//libera_lista(li);	*/

	return 0;
}