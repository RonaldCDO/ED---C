#include "lista.h"
#include <stdio.h>

int main()
{
	Lista* li;
	li = cria_lista();
	Aluno al;
	al.matricula = 123;

	insere_inicio(li, al);
	insere_final(li, al);
	insere_ord (li, al);
	printf("%i\n",tamanho_lista(li));
	libera_lista(li);

	return 0;
}