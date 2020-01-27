#!/usr/bin/python3
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
		#la liste ED ci dessus est affecte des successeurs possible du curseur
		etat_disponible=rejet_etat_double(etat_disponible)#sert a rien normalement
		print(f'\tetat disponible: {etat_disponible}\n')
		etats_deja_visite.append(copier(curseur))#sert a rien aussi
		curseur = etat_disponible.pop(random.randrange(len(etat_disponible)))
		#on tire au sort un etat aleatoire depuis ED
		#qui est aussitot enlever d'ED par la methode pop
		nb_de_coup +=1
	print(f'>>{curseur} coup numero :{nb_de_coup}')
	print(f'fin de jeu')

def recherche_profondeur():
	#miracle ca fonctionne car bizarrement la solution est parcourue en prenant tjrs la fourche gauche
	#donc cette algo est bidon...
	curseur = etat_init
	nb_de_coup = 0
	global etat_disponible
	global etats_deja_visite
	while (curseur != etat_but):
		print(f'>>{curseur} coup numero :{nb_de_coup}')
		etat_disponible = traverse_disponible(curseur)
		etat_disponible =rejet_etat_double(etat_disponible)
		etat_disponible =rejet_etat_visite(etat_disponible)
		print(f'\tetat disponible: {etat_disponible}\n')
		curseur = etat_disponible[0]# vive la fourche gauche
		nb_de_coup +=1
		etats_deja_visite.append(copier(curseur))
	print(f'>>{curseur} coup numero :{nb_de_coup}')	
	print(f'fin de jeu')

def recherche_largeur():
	curseur = etat_init
	nb_de_coup = 0
	global etat_disponible
	global etats_deja_visite
	etat_disponible_pr_curseur = []
	while (curseur != etat_but):
		print(f'>>{curseur} coup numero :{nb_de_coup}')
		etat_disponible_pr_curseur = traverse_disponible(curseur)	
		print(f'\tetat etat_disponible_pr_curseur: {etat_disponible_pr_curseur}')	
		#EDPC ci dessus est une sorte de pile temporaire
		#ED contient tous les etats non parcourue d'une meme niveau a priori
		if(not len(etat_disponible_pr_curseur)):
			#si on trouve pas d'etat successeur on reviens vers ED pour prendre un autre curseur
			curseur = etat_disponible[0]
		elif(len(etat_disponible_pr_curseur)==1):
			#le cas ou il n'y a qu'un seul succeusseur
			#on peut donc mettre le curseur dans le bac des visite, pour qui soit sortie de ED
			etats_deja_visite.append(copier(curseur))
			curseur = etat_disponible_pr_curseur[0]
		else:
			#si on a plusieurs successeurs on ajoute leurs successeurs dans ED
			for elem in etat_disponible_pr_curseur:
				etat_disponible += traverse_disponible(elem)
			etats_deja_visite.append(copier(curseur))
			curseur = etat_disponible[0]
		#enfin on tri le bac ED en enlevant tous les doublons et les visitees
		#et on boucle jusqu'a tomber sur la solution
		etat_disponible =rejet_etat_double(etat_disponible)
		etat_disponible =rejet_etat_visite(etat_disponible)
		print(f'\tetat disponible: {etat_disponible}\n')	
		nb_de_coup +=1

	print(f'>>{curseur} coup numero :{nb_de_coup}')	
	print(f'fin de jeu')

#recherche_profondeur()
#recherche_largeur()
recherche_aleatoire()
