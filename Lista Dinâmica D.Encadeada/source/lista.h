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