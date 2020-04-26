#include "lista.h"
#include "stdlib.h"
struct elemento{
	struct elemento *prox;
	Aluno dados;
	struct elemento *ant;
};

typedef struct elemento Elem;

Lista* cria_lista()
{
	Lista *li = (Lista*) malloc(sizeof(Lista));
	
	if(li != NULL)
		*li = NULL;
	return li;
}

void libera_lista(Lista* li)
{
	if(li != NULL)
	{
		Elem *aux = *li;
		while(*li != NULL)
		{
			aux = *li;
			*li = (*li)->prox;
			free(aux);
		}
		free (li);

	}
}

int tamanho_lista(Lista* li)
{
	if (li == NULL) 
		return 0;

	Elem *aux = *li;
	int cont = 0;

	while(aux!=NULL)
	{	
		cont++;
		aux = aux->prox;
	}
	return cont;
}

int vazia_lista(Lista* li)
{
	if (li == NULL) 
		return 1;
	
	if(*li == NULL) 
		return 1;
	
	return 0;
}

int insere_inicio(Lista* li, Aluno al)
{
	if (li == NULL)
		return 0;

	Elem *no = (Elem*) malloc(sizeof(Elem));


	if (no == NULL) return 0;

		no->dados = al;
		no->prox = *li;
		no->ant = NULL;
		(*li) = no;
	
	if (*li != NULL)
		
		(*li)->ant = no;
	*li = no;
	return 1;
}

int insere_final(Lista* li, Aluno al)
{
	if (li == NULL)
		return 0;

	Elem *no = (Elem*) malloc(sizeof(Elem));

	if (no == NULL)
		return 0;
	if((*li) == NULL)
	{

	
	no->dados = al;
	no->prox = NULL;
	*li = no;
	} 
	else{
		Elem *aux = *li;	
		while( aux ->prox != NULL)
			aux = aux->prox;
		
		aux->prox = no;
		no->ant = aux;
		}

		return 1;
}

int insere_ord(Lista* li, Aluno al)
{
	if (li == NULL)
		return 0;
	Elem* no = (Elem*) malloc (sizeof(Elem));
	if(no == NULL)
	no-> dados = al;
	
	if (vazia_lista(li))
	{
		no->prox = NULL;
		no->ant = NULL;
		*li = no;
		return 1;	
	}
	else
	{
		Elem *atual = *li, *ante;

		while(atual!=NULL && atual->dados.matricula < al.matricula)
		{
			ante = atual;
			atual = atual->prox;
		}
		if(atual == *li)
		{
			no->prox = *li;
			(*li)->ant = no;
			*li = no;
		}
		else
		{
			no->prox = ante->prox;
			no->ant = ante;
			ante->prox = no;
			if(atual != NULL)
			{
				atual->ant = no;
			}
		}
		return 1;
	}
}