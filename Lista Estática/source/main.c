#include "lista.h"
#include <stdio.h>

int main()
{
	Lista* li;
	li = cria_lista();
	struct aluno l1, l2;
	struct aluno* dados_aluno;
	l1.matricula = 123;
	l2.matricula = 124;


	//printf("%d\n", vazia_lista(li));
	//printf("%d\n", cheia_lista(li));
	//inserir_lista(li, 5);
	//insere_final_lista(li, al);
	//insere_final_lista(li, 124);
	insere_inicio_lista (li, l1);
	insere_final_lista (li, l2);

	//remove_inicio_lista(li);
	//remove_final_lista(li); 
	//remove_lista(li, 123);
	//remove_lista(li, 124);
	
	
	printf("%d\n", tamanho_lista(li));

	
	libera_lista(li);


	return 0;
}
