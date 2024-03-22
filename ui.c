#include "ui.h"
#include <stdio.h>
#include "stdlib.h"

void testAll(){
    testCreateDestroy();
    testcreeazaEmpty();
    testadd();
    testmodif();
    teststergere();
    testaddService();
    testmodifService();
    teststergereService();
    testordonareService();
}

void citesteMedicamente(Lista* l, int comanda){
    printf("ID:");
    int cod_unic;
    scanf("%d",&cod_unic);
    printf("Nume:");
    char *nume = malloc(sizeof(char) * 50);
    scanf("%s", nume);
    printf("Concentratie:");
    int concentratie;
    scanf("%d",&concentratie);
    printf("Cantitate:");
    int cantitate;
    scanf("%d",&cantitate);

    if (comanda == 1) {
        int eroare = addMedicament(l, cod_unic, nume, concentratie, cantitate);
        if(eroare != 0)
            printf("Medicament invalid!\n");
        else
            printf("Medicament adaugat\n");
    }
    else{
        int eroare = modifMedicament(l, cod_unic, nume, concentratie, cantitate);
        if(eroare != 0)
            printf("Medicament invalid!\n");
        else
            printf("Medicament modificat\n");
    }
}

void stergereMedicamente(Lista* l){
    printf("ID:");
    int cod_unic;
    scanf("%d",&cod_unic);
    int eroare = stergeMedicament(l, cod_unic);
    if (eroare != 0)
        printf("Medicament invalid!\n");
    else
        printf("Medicament sters\n");
}

void ordoneazaMedicamente(Lista* l){
    if (l->lungime > 0) {
        printf("Medicamentele au fost ordondate:\n");
        ordonareMedicament(l);
    }
    else
        printf("Lista este goala!\n");
}

void filtreazaMedicamente(Lista* l){
    if (l->lungime > 0) {

        printf("Nume:");
        char litera;
        scanf(" %c", &litera);

        printf("Cantitate:");
        int cantitate_mai_mica;
        scanf("%d",&cantitate_mai_mica);

        printf("Medicamentele filtrate:\n");
        Lista* auxiliar = malloc(sizeof (TElem)*l->capacitate);
        filtrareMedicament(l, auxiliar, litera, cantitate_mai_mica);
        for (int i = 0; i < auxiliar->lungime; i++) {
            TElem* elem = get_elem(auxiliar, i);
            printf("%d %s %d %d\n", elem->cod_unic, elem->nume, elem->concentratie, elem->cantitate);
        }
        free(auxiliar->elemente);
        free(auxiliar);
    }
    else
        printf("Lista este goala!\n");
}

void afiseazaMedicamente(Lista* l){
    if (l->lungime > 0) {
        printf("Medicamentele:\n");
        for (int i = 0; i < l->lungime; i++) {
            TElem* elem = get_elem(l, i);
            printf("%d %s %d %d\n", elem->cod_unic, elem->nume, elem->concentratie, elem->cantitate);
        }
    }
    else
        printf("Lista este goala!\n");
}

void run(){
    Lista* l = creeazaEmpty();
    int ruleaza = 1;
    while(ruleaza){
        printf("1.Add\n2.Update\n3.Delete\n4.Ordonare\n5.Filtrare\n6.All\n0.Exit\nAlegeti optiunea:");
        int cmd = 0;
        scanf("%d", &cmd);
        switch (cmd) {
            case 1:
                citesteMedicamente(l, 1);
                break;
            case 2:
                citesteMedicamente(l, 2);
                break;
            case 3:
                stergereMedicamente(l);
            case 4:
                ordoneazaMedicamente(l);
                break;
            case 5:
                filtreazaMedicamente(l);
                break;
            case 6:
                afiseazaMedicamente(l);
                break;
            case 0:
                ruleaza = 0;
                break;
            default:
                printf("Comanda invalida!\n");
        }
    }
    destroyLista(l);
}