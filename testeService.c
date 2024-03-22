#include "testeService.h"
#include <assert.h>
#include "stdlib.h"
#include "string.h"


void testaddService(){
    Lista* l = creeazaEmpty();
    char* Nume1 = malloc(sizeof(char)*7);
    strcpy(Nume1, "");
    int ok = addMedicament(l, 123, Nume1, 100, 50);
    assert(ok != 0);
    assert(get_size(l) == 0);
    strcpy(Nume1, "asdasd");
    ok = addMedicament(l, -1, Nume1, -50, 50);
    assert(ok != 0);
    assert(get_size(l) == 0);
    strcpy(Nume1, "sadasd");
    ok = addMedicament(l, 16, Nume1, 100, -532);
    assert(ok != 0);
    assert(get_size(l) == 0);
    strcpy(Nume1, "hihihi");
    ok = addMedicament(l, 123, Nume1, 100, 50);
    assert(ok == 0);
    assert(get_size(l) == 1);
    destroyLista(l);
}

void testmodifService(){
    Lista* l = creeazaEmpty();
    char* Nume1 = malloc(sizeof(char)*7);
    strcpy(Nume1, "hahaha");
    int ok = modifMedicament(l, 123, Nume1, 100, 50);
    assert(ok != 0);
    strcpy(Nume1, "sadasd");
    ok = modifMedicament(l, 16, Nume1, 100, -532);

    assert(ok != 0);
    assert(get_size(l) == 0);
    strcpy(Nume1, "ioioi");
    ok = addMedicament(l, 999, Nume1, 100, 50);
    assert(ok == 0);
    assert(get_size(l) == 1);
    strcpy(Nume1, "aiaiai");
    ok = modifMedicament(l, 999, Nume1, 1, 1);
    assert(ok == 0);
    assert(get_size(l) == 1);
    destroyLista(l);
}

void teststergereService(){
    Lista* l = creeazaEmpty();
    char* Nume1 = malloc(sizeof(char)*7);
    strcpy(Nume1, "hahaha");
    int ok = addMedicament(l, 123, Nume1, 100, 50);
    assert(ok == 0);
    assert(get_size(l) == 1);

    ok = stergeMedicament(l, 999);
    assert(ok != 0);
    assert(get_size(l) == 1);

    ok = stergeMedicament(l, 123);
    assert(ok == 0);
    assert(get_size(l) == 0);
    destroyLista(l);
}

void testordonareService(){
    Lista* l = creeazaEmpty();
    char* Nume1 = malloc(sizeof(char)*8);
    strcpy(Nume1, "Nurofen");
    char* Nume2 = malloc(sizeof(char)*8);
    strcpy(Nume2, "Nurofen");
    addMedicament(l, 123, Nume1, 100, 50);
    addMedicament(l, 124, Nume2, 100, 35);
    TElem* element1 = get_elem(l, 0);
    TElem* element2 = get_elem(l, 1);
    assert(element1->cantitate == 50);
    assert(element2->cantitate == 35);

    ordonareMedicament(l);

    element1 = get_elem(l, 0);
    element2 = get_elem(l, 1);

    assert(element1->cantitate == 35);
    assert(element2->cantitate == 50);

    destroyLista(l);
}