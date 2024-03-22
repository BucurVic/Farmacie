#pragma once

typedef struct {
    int cod_unic;   ///Identificator unic
    char* nume;  ///Numele Medicamentului
    int concentratie;   ///Concentratia Medicamentului
    int cantitate;   ///Cantitatea disponibila in stoc a Medicamentului
}Medicament;

/*
 Creeaza un nou Medicament
 */
Medicament* creeazaMedicament(int cod_unic, char* nume, int concentratie, int cantitate);

/*
 Dealoca memoria utilizata de Medicament
 */
void destroyMedicament(Medicament* med);

/*
 *
 */
int valideaza(Medicament* med);