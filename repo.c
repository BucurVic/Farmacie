#include "repo.h"
#include <string.h>
#include "stdlib.h"

Lista* creeazaEmpty(){
    Lista* l = malloc(sizeof(Lista));
    l->capacitate = 2;
    l->elemente = malloc(sizeof(Medicament) * l->capacitate);
    l->lungime = 0;
    return l;
}

//typedef void FunctieDist(void*);

void destroyLista(Lista* l){
    for(int i=0;i<l->lungime;i++){
        TElem* element = l->elemente[i];
        destroyMedicament(element);
    }
    l->lungime = 0;
    free(l->elemente);
    free(l);
}

TElem* get_elem(Lista* l, int pozitie){
    return l->elemente[pozitie];
}

TElem* set_elem(Lista* l, int pozitite, TElem* elem){
    TElem* rez = l->elemente[pozitite];
    l->elemente[pozitite] = elem;
    return rez;
}

int get_size(Lista* l){
    return l->lungime;
}

void add(Lista* l, TElem* element){
    int ok = 0;

    if (l->capacitate <= l->lungime){
        TElem** auxiliar = malloc(sizeof(TElem)*(l->capacitate+5));
        for(int i=0;i<l->lungime;i++)
            auxiliar[i] = l->elemente[i];
        free(l->elemente);
        l->capacitate += 5;
        l->elemente = auxiliar;
    }

    for(int i=0;i<l->lungime;i++) {
        TElem* med = l->elemente[i];
        if (med->cod_unic == element->cod_unic && strcmp(med->nume, element->nume) == 0) {
            ok = 1;
            med->concentratie = element->concentratie;
            med->cantitate = element->cantitate;
            free(element);
            break;
        }
    }
    if (ok==0) {
        l->elemente[l->lungime] = element;
        l->lungime++;
    }
}

int modif(Lista* l, TElem* element){
    for(int i=0;i<l->lungime;i++){
        TElem* med = get_elem(l, i);
        if (med->cod_unic == element->cod_unic) {
            TElem* elem = set_elem(l, i, element);
            free(elem);
            return 0;
        }
    }
    free(element);
    return -1;
}

int stergere(Lista* l, int id){
    for(int i=0;i<l->lungime;i++) {
        TElem* med = get_elem(l, i);
        if (med->cod_unic == id) {
            for (int j=i;j<l->lungime-1;j++){
                TElem* med3 = get_elem(l,j+1);
                l->elemente[j] = med3;
            }
            l->lungime--;
            if(l->lungime == 0)
                free(med->nume);
            free(med);
            return 0;
        }
    }
    return -1;
}