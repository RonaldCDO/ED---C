#pragma once

struct aluno{

	int matricula;
	char nome[30];
	float n1, n2, n3;
};

typedef struct aluno Aluno;

typedef struct elemento* Lista;

Lista* cria_lista();

void libera_lista(Lista* li);

int tamanho_lista(Lista* li);

int vazia_lista(Lista* li);

int insere_inicio(Lista* li, Aluno al);

int insere_final(Lista* li, Aluno al);

int insere_ord(Lista* li, Aluno al);

int remove_inicio(Lista* li);

int remove_final(Lista* li);

int remove_ord (Lista* li, int mat);

int consulta_pos(Lista* in, int pos, struct aluno *al);

int consulta_mat (Lista *li, int mat, struct aluno *al);

void echo(Lista* li);
