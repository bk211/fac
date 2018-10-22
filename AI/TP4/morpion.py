#!usr/bin/env python
import copy
from math import inf as inf
#CAI Chaolei
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

cas1= [1,1,-1,
        0,1,0,
        -1,0,-1]

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


def fonction_decision_H(tableau, joueur):

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

def nbAlign(p,J,i):
#le nombre i d'alignement realisable par le joueur J pour un etat p où il y a deja i symboles poses
    compteur = 0
    resultat = 0

    #alignement en ligne
    for k in range(longeur):
        for j in range(largeur):
            if p[k*longeur+j] == J:
                compteur+=1
            elif p[k*longeur+j] == -1*J:
                compteur = -inf
        if compteur == i:
            resultat+=1
        compteur = 0

    #alignement en colonne
    for k in range(longeur):
        for j in range(largeur):
            if p[k+j*longeur] == J:
                compteur+=1
            elif p[k+j*longeur] == -1*J:
                compteur = -inf
        if compteur == i:
            resultat+=1
        compteur = 0

    #alignement en diagonale1
    for k in range(longeur) :
        if p[k*longeur+k] == J:
            compteur+=1
        elif p[k*longeur+k] == -1*J:
            compteur = -inf
    if compteur == i:
            resultat+=1
    compteur = 0

    #alignement en diagonale2
    for k in range(1,longeur+1):
        if p[k*longeur-k] == J:
            compteur+=1
        elif p[k*longeur-k] == -1*J:
            compteur = -inf
    if compteur == i:
            resultat+=1
    compteur = 0

    return resultat

def fonction_evaluation_F(p):
    if fonction_decision_H(p,1):
        resultat = inf
    elif (fonction_decision_H(p,-1)):
        resultat = -inf
    else:
        resultat = (3* nbAlign(p,+1,2) + nbAlign(p,+1,1)) - (3* nbAlign(p,-1,2)+ nbAlign(p,-1,1))
    return resultat

def minimax(n,p,joueur):
#evaluation de p a une profondeur n pour le joueur
    #si l'etat est terminale, alors il n'a que 3 possibilité
    #soit {-inf, 0, +inf}
    if fonction_decision_H(p,1):
        return inf
    elif (fonction_decision_H(p,-1)):
        return -inf
    elif(not n):
        #cas où il n'a pas de gagnant et que la profondeur est 0
        return 0
        #match nul

    else:
        successeurs = genese_successeurs(p,joueur)
        pile = []
        for successeur in successeurs:
            pile.append(fonction_evaluation_F(successeur))

        if joueur == 1:
            return max(pile)
        else :
            return min(pile)




#afficher(cas1)
#print(fonction_decision_H(cas1))
#print(cases_vides(cas1))
#print("\n")
print(minimax(3,cas1,+1))
#print(fonction_evaluation_F(cas1))


'''

afficher(tableau_initial)
#print(fonction_decision_H(tableau_initial))
#print(cases_vides(tableau_initial))
#print("\n")
print(minimax(9,tableau_initial,+1))
'''