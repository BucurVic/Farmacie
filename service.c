#include "service.h"
#include "string.h"
#include "stdlib.h"

int addMedicament(Lista* l, int cod_unic, char* nume, int concentratie, int cantitate){
    TElem* med = creeazaMedicament(cod_unic, nume, concentratie, cantitate);
    int ok = valideaza(med);
    if (ok != 0) {
        free(med);
        return ok;
    }
    add(l, med);
    return 0;
}

int modifMedicament(Lista* l, int cod_unic, char* nume, int concentratie, int cantitate){
    TElem* med = creeazaMedicament(cod_unic, nume, concentratie, cantitate);
    int ok = valideaza(med);
    if (ok != 0) {
        free(med);
        return ok;
    }
    return modif(l, med);
}

int stergeMedicament(Lista* l, int id){
    return stergere(l, id);
}

void ordonareMedicament(Lista* l){
    for (int i=0;i<l->lungime-1;i++)
        for (int j=i+1;j<l->lungime;j++)
            if (strcmp(l->elemente[i]->nume, l->elemente[j]->nume) > 0 ||
            (strcmp(l->elemente[i]->nume, l->elemente[j]->nume) == 0 &&
            l->elemente[i]->cantitate > l->elemente[j]->cantitate)) {
                TElem* element = l->elemente[i];
                l->elemente[i] = l->elemente[j];
                l->elemente[j] = element;
            }
}

void filtrareMedicament(Lista* l, Lista* auxiliar, char litera, int cantitate_mai_mica){
    auxiliar->lungime = 0;
    auxiliar->elemente = malloc(sizeof(Medicament) * l->capacitate);
    if (litera == '0') {
        for (int i = 0; i < l->lungime; i++)
            if (l->elemente[i]->cantitate < cantitate_mai_mica) {
                auxiliar->elemente[i] = l->elemente[i];
                auxiliar->lungime++;
            }
    }
    else if (cantitate_mai_mica <= 0) {
                for (int i = 0; i < l->lungime; i++)
                    if (l->elemente[i]->nume[0] == litera) {
                        auxiliar->elemente[i] = l->elemente[i];
                        auxiliar->lungime++;
                    }
    }
    else {
        for (int i = 0; i < l->lungime; i++)
            if (l->elemente[i]->nume[0] == litera) {
                auxiliar->elemente[i] = l->elemente[i];
                auxiliar->lungime++;
            }
    }
}