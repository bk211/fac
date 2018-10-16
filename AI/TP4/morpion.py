import copy

tableau_initial = [0,0,0,
					0,0,0,
					0,0,0]


def afficher(tab):
	print(tab[:3])
	print(tab[3:6])
	print(tab[6:])


#afficher(tableau_initial)

joueur1 = 'A'
joueur2 = 'B'


def victoire(tableau, joueur):

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

cas1= ['B','B','A',
		0,'A',0,
		0,0,0]


def evaluation_tableau(tab):
	if victoire(tab,joueur1):
		return 1
	elif (victoire(tab,joueur2)):
		return 2
	else:
		return 0

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

def successeurs(tab, joueur):
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





afficher(cas1)
#print(evaluation_tableau(cas1))
print(cases_vides(cas1))
print("\n")
successeurs(cas1,joueur1)