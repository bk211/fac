#!/usr/bin/env python
import copy
etat_init= [0,0,0,0] # Fermier, Poule, Renard, Grains
etat_final = [1,1,1,1]
etat_usee =[];
etat_disponible = []

etat = etat_init;

def genese_etat_interdit(liste):
	pass


def traverse(etat, indice):
	if(etat[indice]):
		etat[indice] = 0
	else:
		etat[indice] = 1

def tri_interdit(etat):
	# renard[2] et poule[1] 
	# poule[1] et grains[3]
	for elem in etat:
		if(elem[2] == elem[1])

def goBack(etat):
	return copy.copy(etat)
def traverse_seul(etat):
	traverse(etat,0)

def traverse_disponible(etat, etats_interdit):

	resultat = []
	temp = goBack(etat)#rest

	traverse_seul(temp)
	if temp not in resultat:
		resultat.append(copy.copy(temp))

	for x in range(1,4):
		if(not temp[0] == temp[x]):
			traverse(temp,x)
			if(temp not in resultat):
				resultat.append(copy.copy(temp))
		temp = goBack(etat)
		traverse_seul(temp)
		

	return resultat

etat_disponible = traverse_disponible(etat_init,etats_interdit)
print(etat_disponible)
#print([1,0,1,0] in etats_interdit)
#print(etat_disponible in etats_interdit)
