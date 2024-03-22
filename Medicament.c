#include "Medicament.h"
#include <string.h>
#include "stdlib.h"

Medicament* creeazaMedicament(int cod_unic, char* nume, int concentratie, int cantitate){
    Medicament* med = malloc(sizeof (Medicament));

    med->cod_unic = cod_unic;
    med->nume = nume;
    med->concentratie = concentratie;
    med->cantitate = cantitate;

    return med;
}

void destroyMedicament(Medicament* med){
    free(med->nume);
    free(med);
}

int valideaza(Medicament* med){
    if (strlen(med->nume) == 0)
        return 1;
    if (med->concentratie < 0)
        return 2;
    if (med->cantitate < 0)
        return 3;
    return 0;
}