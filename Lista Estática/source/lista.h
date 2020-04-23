#pragma once
#define MAX 100

typedef enum { false, true } bool;

struct aluno
{
	int matricula;
	char nome[30];
	float n1, n2, n3;
};

typedef struct lista Lista;

Lista* cria_lista ();

void libera_lista (Lista* li);

int tamanho_lista (Lista* li);

bool vazia_lista (Lista* li);

bool cheia_lista (Lista* li);

int insere_final_lista (Lista* li, struct aluno al);

int insere_inicio_lista (Lista* li, struct aluno al);

int insere_lista_ordenada(Lista * li, struct aluno al);

int remove_inicio_lista(Lista *li);

int remove_final_lista(Lista* li);

int remove_lista_ordenada(Lista* li);

int remove_lista(Lista* li, int mat);

int consulta_lista_pos(Lista* li, int pos , struct aluno *al);

int consulta_lista_mat(Lista* li, int mat, struct aluno *al);