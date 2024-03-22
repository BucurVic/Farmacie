#include <assert.h>
#include <string.h>
#include "stdlib.h"
#include "testeRepo.h"

void testcreeazaEmpty(){
    Lista* l = creeazaEmpty();
    assert(get_size(l) == 0);
    destroyLista(l);
}

void testadd() {
    Lista* l = creeazaEmpty();
    char* Nume1 = malloc(sizeof(char)*8);
    strcpy(Nume1, "Nurofen");
    TElem* medicament1 = creeazaMedicament(123, Nume1, 20, 100);
    add(l, medicament1);
    char* Nume2 = malloc(sizeof(char)*10);
    strcpy(Nume2, "Strepsils");
    TElem* medicament2 = creeazaMedicament(12, Nume2, 100, 24);
    add(l, medicament2);
    assert(get_size(l)==2);

    Medicament* med1 = get_elem(l,0);
    assert(med1->cod_unic == 123);
    assert(strcmp(med1->nume, "Nurofen") == 0);

    Medicament* med2 = get_elem(l,1);
    assert(med2->concentratie == 100);
    assert(med2->cantitate == 24);

    TElem* medicament3 = creeazaMedicament(123, Nume1, 10, 1231);

    add(l, medicament3);
    Medicament* med3 = get_elem(l,0);
    assert(med3->concentratie == 10);
    assert(med3->cantitate == 1231);

    destroyLista(l);
}

void testmodif() {
    Lista* l = creeazaEmpty();
    char* Nume1 = malloc(sizeof(char)*10);
    strcpy(Nume1, "Nurofen");
    TElem* medicament1 = creeazaMedicament(123, Nume1, 20, 100);
    add(l, medicament1);
    strcpy(Nume1, "Strepsils");
    int a = modif(l, creeazaMedicament(123, Nume1, 100, 24));
    assert(a == 0);

    Medicament* med1 = get_elem(l,0);
    assert(strcmp(med1->nume, "Strepsils") == 0);
    assert(med1->concentratie == 100);

    int b = modif(l, creeazaMedicament(1, Nume1, 100, 24));
    assert(b == -1);
    destroyLista(l);
}

void teststergere(){
    Lista* l = creeazaEmpty();
    char* Nume1 = malloc(sizeof(char)*10);
    strcpy(Nume1, "Nurofen");
    TElem* medicament1 = creeazaMedicament(123, Nume1, 20, 100);
    add(l, medicament1);
    strcpy(Nume1, "Strepsils");
    TElem* medicament2 = creeazaMedicament(12, Nume1, 100, 24);
    add(l, medicament2);
    assert(get_size(l)==2);

    int a = stergere(l, 123);
    assert(a == 0);
    assert(get_size(l) == 1);

    int b = stergere(l, 12341234);
    assert(b == -1);
    assert(get_size(l) == 1);
    destroyLista(l);
}