#include "lista.h"
#include <stdlib.h>

struct elemento
{
	struct aluno dados;
	struct elemento *prox;
};

typedef struct elemento Elem;

Lista* cria_lista()
{
	Lista* li = (Lista*) malloc(sizeof(Lista));
	if(li != NULL)
		*li = NULL;
	return li;
}

void libera_lista(Lista* li)
{
	if (li!= NULL){
		Elem* no;
	

	while((*li) !=NULL)
		{
		no = *li;
		*li = (*li) -> prox;
		free (no);
		}
	free (li);
	}
}

int tamanho_lista(Lista* li)
{
	if (li == NULL) return 0;
	
	Elem *no = *li;
	int cont = 0;

	while(no != NULL)
	{
		cont++;
		no = no->prox;
	}
	return cont;
}

int vazia_lista(Lista* li)
{
	if(li==NULL || *li == NULL) return 1;
	return 0;
}

int insere_inicio_lista(Lista* li, struct aluno al)
{
	if(li == NULL) return 0;  
		
		Elem* no = (Elem*) malloc(sizeof(Elem));
		if (no == NULL) return 0;
		no->dados = al;
		no ->prox = (*li);
		*li = no;
		return 1;
}

int insere_final_lista(Lista* li, struct aluno al)
{
	if (li==NULL) return 0;
	
	Elem* no = (Elem*) malloc(sizeof(Elem));
	no -> dados = al;

	if (*li == NULL)
	{
		no->prox = (*li);
		*li = no;
	} 
	else{
		Elem* aux = *li;
		while(aux->prox != NULL)
		{
			aux = aux->prox;
		}
		aux->prox = no;
	}
	return 1;	

}

int remove_inicio_lista(Lista* li)
{
	if (li == NULL || *li == NULL) return 0;

	Elem* no = *li;
	*li = no->prox;
	free(no);
	return 1;
}

int remove_meio_lista(Lista* li, int mat)
{
	if (li == NULL || *li == NULL) return 0;
	Elem *ant, *no = *li;
	while( no!=NULL && no->dados.matricula != mat)
	{
		ant = no;
		no = no->prox;

	}

	if(no->prox == NULL) return 0;

	if (no == NULL) return 0;

	if (no == *li)
		*li = no->prox;

	else
		ant->prox = no->prox;
	free(no);
	return 1;
}

int remove_final_lista(Lista* li)
{
	if (li == NULL || *li == NULL) return 0;
	Elem* ant, *no = *li;
	while( no->prox != NULL)
	{
		ant = no;
		no = no->prox;
	}

	if(no == *li)
		*li = no->prox;
	else
		ant->prox = no->prox;

	free(no);
	return 1;

}

int consulta_lista_pos(Lista *li, int pos, struct aluno *al)
{
	if (li == NULL || pos <= 0) return 0;

	Elem *no = *li;
	int i = 1;
	while ( no != NULL && i < pos)
	{
		no = no->prox;
		i++;
	}

	if (no == NULL) return 0;

	else{
		*al = no->dados;
		return 1;
	} 
}

int consulta_lista_mat (Lista *li, int mat, struct aluno *al)
{
	if (li == NULL) return 0;

	Elem *no = *li;

	while(no != NULL && no->dados.matricula != mat)
	{
		no = no->prox;
	}
	if (no == NULL) return 0;

	else
	{
	*al = no->dados;
	return 1;
	}
}