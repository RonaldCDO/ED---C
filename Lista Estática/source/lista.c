#include "lista.h"
#include <stdlib.h>


struct lista 
{
	int qtd;
	struct aluno dados [MAX];

};

Lista* cria_lista()
{
	Lista* li;
	li = (Lista*) malloc(sizeof(struct lista));

	if (li == NULL)
	{
		li->qtd = 0;
	}
	return li;
}

void libera_lista (Lista* li)
{
	free (li);
}

int tamanho_lista (Lista* li)
{
	if (li == NULL)
		return -1;
	else 
		return (li->qtd);
}

bool vazia_lista (Lista* li)
{
	if (li == NULL)
	{
		return false;
	}	
		if (li->qtd == 0)
			return true;
		else
			return false;
}

bool cheia_lista (Lista* li)
{
	if (li == NULL)
	{
		return false;
	}
	if (li->qtd == MAX)
		return true;
	else
		return false;

}

int insere_final_lista (Lista* li, struct aluno al)
{
	if (li == NULL)
		return 0;

	if (cheia_lista(li))
		return 0;
	
	li -> dados[li->qtd] = al;
	li -> qtd++;
	return 1;
}

int insere_inicio_lista (Lista* li, struct aluno al)
{
	if (li == NULL)
		return 0;
	if (cheia_lista(li))
		return 0;
	int i;
	for(i =li->qtd-1; i >=0 ; i--)
	{
		li->dados[i + 1] = li->dados[i];
	}
	li->dados[0] = al;
	li->qtd++;
	return 1;
}

int insere_lista_ordenada(Lista * li, struct aluno al)
{
	if (li == NULL)
		return 0;
	if (cheia_lista(li))
		return 0;
	int k,i = 0;

	while(i < li->qtd && li -> dados[i].matricula < al.matricula)
	i++;
	
	for (k = li->qtd -1; k >= i; k--)
	{
		li->dados[k+1] = li->dados[k];
	}
		li->dados [i] = al;
		li->qtd++;
		return 1;
	
}

int remove_inicio_lista(Lista *li)
{
	if (li == NULL) return 0;

	if(vazia_lista(li)) return 0;	

	for(int i= 0 ; i< li->qtd-1; i++)
		li->dados[i] = li->dados[i+1];
	li ->qtd--;
	return 1; 
}

int remove_final_lista(Lista* li){

	if (li == NULL) return 0;

	if(vazia_lista(li)) return 0;

	li->qtd--; 
	return 1;			
}

int remove_lista(Lista* li, int mat)
{
	if (li == NULL) return 0;

	if(vazia_lista(li)) return 0;

	int i, k=0;

	while(k<li->qtd && li->dados[k].matricula != mat)
	k++;
	if (k == li->qtd) return 0;	

	for(i=0; i<li->qtd-1; i++)
	if(li->dados[i].matricula == mat)
		li->dados [i] = li->dados [i+1];
	li->qtd--;
	return 1;
}

int consulta_lista_pos(Lista* li, int pos , struct aluno *al)
{
	if (li == NULL || pos <=0 || pos > li->qtd) return 0;

	*al = li->dados[pos -1];
	return 1;
}

int consulta_lista_mat(Lista* li, int mat, struct aluno *al)
{
	if (li == NULL) return 0;
	if (vazia_lista(li)) return 0;

	int i = 0, k = 0;

	while(k<li->qtd && li->dados[k].matricula != mat)
		k++;
	if(i == li->qtd) return 0;
	*al = li->dados[i];
	return 1;
}
