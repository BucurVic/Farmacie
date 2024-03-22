#pragma once
#include "Medicament.h"

//typedef void* TElem;

typedef Medicament TElem;

typedef struct {
    TElem** elemente;
    int lungime;
    int capacitate;
}Lista;

/*
 Creeaza o lista goala
 */
Lista* creeazaEmpty();

/*
 Distruge lista creata
 */
void destroyLista(Lista* l);

TElem* get_elem(Lista* l, int pozitie);

TElem* set_elem(Lista* l, int pozitie, TElem* elem);

int get_size(Lista* l);

void add(Lista* l, TElem* elem);

int modif(Lista* l, TElem* elem);

int stergere(Lista* l, int id);