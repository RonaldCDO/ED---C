#include "lista.h"
#include <stdio.h>

int main()
{
	Lista* li;
	struct aluno al;
	al.matricula = 124;
	struct aluno amz;
	li = cria_lista();
	insere_inicio_lista(li, al);
	insere_final_lista(li, al);
	
	remove_final_lista(li);
	printf("%d\n", tamanho_lista(li));
	
	printf("%d\n", consulta_lista_pos(li, 2, &amz));
	printf("%d\n", consulta_lista_mat(li, 124, &amz));

	libera_lista(li);



	return 0;
}	