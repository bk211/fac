#!/usr/bin/env python
# CAI Chaolei 17812776
import copy
import random
etat_init= [0,0,0,0] # Fermier, Poule, Renard, Grains
etat_but = [1,1,1,1]
etats_interdit = [[0,1,1,0], [0,1,0,1], [0,1,1,1],[1,0,0,1], [1,0,1,0], [1,0,0,0] ]

def rejet_etat_interdit(liste):
	#prend une liste d'etat et rejete tous les etats interdits
	liste = [elem for elem in liste if(elem not in etats_interdit)]
	return liste

def rejet_etat_visite(liste,liste2):
	#prend une liste d'etat et rejete tous les etats deja visite
	liste = [elem for elem in liste if(elem not in liste2)]
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

def print_arbre(liste):
	
	for x in range(1,len(liste)):
		if(liste[-x] not in traverse_disponible(liste[-x-1])):
			del liste[x+1]

	print("voici l'arbre\n")
	for x in liste:
		print(x,"\n") 


def recherche_profondeur():
	curseur = etat_init
	etat_disponible = [] 
	arbre = []
	pile_non_fini = []
	etat_fini = [] #etat qui ne dispose plus de successeurs
	n = 0
	while(curseur != [1,1,1,1]):
		print(">>",curseur)
		etat_disponible = traverse_disponible(curseur)
		etat_disponible = rejet_etat_visite(etat_disponible,etat_fini)
		
		if(len(etat_disponible)== 0):
			print("changement branche")
			curseur = pile_non_fini[-1]
		if(len(etat_disponible)== 1):
			#cas branche unique,le curseur n'est plus utile
			etat_fini.append(copier(curseur))
			arbre.append(copier(curseur))
			curseur = etat_disponible[0]
		else:
			arbre.append(copier(curseur))
			etat_fini.append(copier(curseur))
			pile_non_fini += copier(etat_disponible)
			rejet_etat_double(pile_non_fini)
			curseur = etat_disponible[0]
		print("etat_disponible:",etat_disponible)
		print("pile a traiter:",pile_non_fini)
		print("etat finis:",etat_fini,"fin slide\n")
		
	print_arbre(arbre)
recherche_profondeur()