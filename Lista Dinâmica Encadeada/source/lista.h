#pragma once
struct aluno
{
	int matricula;
	char nome[30];
	float n1, n2 ,n3; 

};

typedef struct elemento* Lista;

Lista* cria_lista();

void libera_lista(Lista* li);

int tamanho_lista(Lista* li);

int vazia_lista(Lista* li);

int insere_inicio_lista(Lista* li, struct aluno al);

int insere_final_lista(Lista* li, struct aluno al);

int remove_inicio_lista(Lista*);

int remove_meio_lista(Lista* li, int mat);

int remove_final_lista(Lista* li);

int consulta_lista_pos(Lista* li, int pos, struct aluno *al);

int consulta_lista_mat (Lista *li, int mat, struct aluno *al);