#!/usr/bin/env python3
# CAI Chaolei 17812776
import copy
import random
etat_init= [0,0,0,0] # Fermier, Poule, Renard, Grains
etat_but = [1,1,1,1]
etats_interdit = [[0,1,1,0], [0,1,0,1], [0,1,1,1],[1,0,0,1], [1,0,1,0], [1,0,0,0] ]
etats_deja_visite = []
etat_disponible = []
curseur = etat_init

def rejet_etat_interdit(liste):
	#prend une liste d'etat et rejete tous les etats interdits
	liste = [elem for elem in liste if(elem not in etats_interdit)]
	return liste

def rejet_etat_visite(liste):
	#prend une liste d'etat et rejete tous les etats deja visite
	liste = [elem for elem in liste if(elem not in etats_deja_visite)]
	return liste

def rejet_etat_double(liste):
	tmp =[]
	for elem in liste:
		if elem not in tmp:
			tmp.append(elem)
	return tmp	

def copier(etat):
	return copy.deepcopy(etat)

def traverse(etat, indice):
	if(etat[indice]):
		etat[indice] = 0
	else:
		etat[indice] = 1
def traverse_disponible(etat):
	#prend en parametre 1 etat et retourne une liste qui contient les etats disponible
	resultat = []
	traverse(etat,0)
	temp = copier(etat)
	if(temp not in resultat):
				resultat.append(copier(temp))

	for i in range(1,4):
		if((not temp[0]) == temp[i]):
			traverse(temp,i)
			if(temp not in resultat):
				resultat.append(copier(temp))
			temp = copier(etat)
	resultat = rejet_etat_interdit(resultat)
	traverse(etat,0)
	return resultat


def recherche_profondeur(etat_disponible):
	curseur = etat_disponible[len(etat_disponible)-1]
	liste_etats_fils = traverse_disponible(curseur)
	for etat_fils in liste_etats_fils:
		if etat_fils in etat_disponible:
			continue

		etat_disponible.append(etat_fils)

		if(etat_but == etat_fils):
			print("obj atteint")
			print(etat_disponible)
		else:
			recherche_profondeur(etat_disponible)
		etat_disponible.pop()

recherche_profondeur([[0,0,0,0]])