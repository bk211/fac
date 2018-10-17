#!usr/bin/env python
import copy
from math import inf 
tableau_initial = [0,0,0,
					0,0,0,
					0,0,0]

longeur = 3
largeur = 3

def afficher(tab):
	print(tab[:3])
	print(tab[3:6])
	print(tab[6:])


#afficher(tableau_initial)

joueur1 = +1 # +inf
joueur2 = -1 # -inf

cas1= [1,-1,-1,
		0,1,0,
		0,0,1]

def nb_case_vide(tab):
	compteur = 0

	for elem in tab:
		if not elem:
			compteur += 1 
	return compteur

def verifier_case_vide(tab,i):
	if not tab[i]:
		return True
	return False

def placer_piece(tab,x,joueur):
	if(verifier_case_vide(tab,x)):
		tab[x] = joueur
		return 1
	else:
		return 0

def cases_vides(tab):
	resultat = []
	for i in range(len(tab)):
		if(verifier_case_vide(tab,i)):
			resultat.append(i)
	return resultat;

def genese_successeurs(tab, joueur):
	etat_accessible = []
	cases_possible = cases_vides((tab))

	for i in cases_possible:
		temp = tab.copy()
		placer_piece(temp,i,joueur)
		etat_accessible.append(temp)


	'''
	#affiche les successeurs
	for elem in etat_accessible:
		afficher(elem)
		print("\n")
	'''
	return etat_accessible


def fonction_decision(tableau, joueur):

	cas_victoire = [
	#alignement en ligne
		[tableau[0], tableau[1], tableau[2]],
		[tableau[3], tableau[4], tableau[5]],
		[tableau[6], tableau[7], tableau[8]],
	#alignement en colonne
		[tableau[0], tableau[3], tableau[6]],
		[tableau[1], tableau[4], tableau[7]],
		[tableau[2], tableau[5], tableau[8]],
	#alignement en colonne
		[tableau[0], tableau[4], tableau[8]],
		[tableau[2], tableau[4], tableau[6]],
]

	
	if [joueur,joueur,joueur] in cas_victoire:
		return True
	return False



def minimax(n,p,joueur): #evaluation de p a une profondeur n pour le joueur

	#si l'etat est terminale, alors il n'a que 3 possibilité
	#soit {-inf, 0, +inf}
	if fonction_decision(p,joueur):
		return inf
	elif (fonction_decision(p,-1*joueur)):
		#le prochain joueur a le signe opposé
		return -inf
	elif not n:
		return 0
		#fin de jeu ssi profondeur == 0
		#match nul

	else:
		successeurs = genese_successeurs(p,joueur)
		for successeur in successeurs:
			minimax(n-1,successeur,-1*joueur)

	return fonction_decision(p,joueur)





afficher(cas1)
#print(fonction_decision(cas1))
print(cases_vides(cas1))
#print("\n")
print(minimax(4,cas1,+1))



afficher(tableau_initial)
#print(fonction_decision(tableau_initial))
print(cases_vides(tableau_initial))
#print("\n")
print(minimax(4,tableau_initial,+1))

