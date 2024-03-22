#include "testMedicament.h"
#include "assert.h"
#include "string.h"
#include "stdlib.h"

void testCreateDestroy(){
    char* Nume = malloc(sizeof(char) * 8);
    strcpy(Nume,"Nurofen");
    Medicament* m = creeazaMedicament(123, Nume, 20, 100);
    assert(strcmp(m->nume, "Nurofen") == 0);
    assert(m->cod_unic == 123);
    assert(m->concentratie == 20);
    assert(m->cantitate == 100);

    destroyMedicament(m);
}