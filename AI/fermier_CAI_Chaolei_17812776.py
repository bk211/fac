#!/usr/bin/env python
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
	return resultat

def recherche_aleatoire():
	curseur = etat_init
	nb_de_coup = 0
	global etat_disponible
	global etats_deja_visite
	while (curseur != etat_but):
		print(f'>>{curseur} coup numero :{nb_de_coup}')
		etat_disponible = traverse_disponible(curseur)
		etat_disponible=rejet_etat_double(etat_disponible)
		print(f'\t{etat_disponible}\n')
		curseur = etat_disponible.pop(random.randrange(len(etat_disponible)))
		nb_de_coup +=1
		etats_deja_visite.append(copier(curseur))
	print(f'>>{curseur} coup numero :{nb_de_coup}')
	print(f'fin de jeu')

def recherche_profondeur():
	curseur = etat_init
	nb_de_coup = 0
	global etat_disponible
	global etats_deja_visite
	while (curseur != etat_but):
		print(f'>>{curseur} coup numero :{nb_de_coup}')
		etat_disponible = traverse_disponible(curseur)
		etat_disponible=rejet_etat_double(etat_disponible)
		print(f'\t{etat_disponible}\n')
		curseur = etat_disponible[0]
		nb_de_coup +=1
		etats_deja_visite.append(copier(curseur))
	print(f'>>{curseur} coup numero :{nb_de_coup}')
	print(f'fin de jeu')

recherche_profondeur()

#recherche_profondeur()
#rejet_etat_interdit(etat_but)
#test = [[0,1,1,0],[1,1,1,1],[0,1,1,0],[1,0,0,1]]
#print(test)
#test = rejet_etat_interdit(test)
#print(test)

#print(etat_disponible)

#print([1,0,1,0] in etats_interdit)
#print(etat_disponible in etats_interdit)
