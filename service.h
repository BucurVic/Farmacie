#pragma once
#include "repo.h"

/*struct {
    Lista* l;
    Lista* filtru;
}service;*/

/*
 adauga un medicament in stocul farmaciei
 */
int addMedicament(Lista* l, int cod_unic, char* nume, int concentratie, int cantitate);

/*
 modifica un medicament din stocul farmaciei
 */
int modifMedicament(Lista* l, int cod_unic, char* nume, int concentratie, int cantitate);

/*
 sterge un medicament din stocul farmaciei
 */
int stergeMedicament(Lista* l, int id);

/*
 *
 */
void ordonareMedicament(Lista* l);

/*
 *
 */
void filtrareMedicament(Lista* l, Lista* auxiliar,char litera, int cantitate_mai_mica);
