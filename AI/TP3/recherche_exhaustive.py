# -*- coding:latin-1 -*-
import random as rand

etat_initial=[1,1,1,1]
etat_but=[2,2,2,2]
etats_interdits=[[1,2,2,2],[1,2,1,2],[1,2,2,1],
                 [2,1,1,1],[2,1,2,1],[2,1,1,2]]

def successeurs(etat_courant):
    etats_accessibles=[]
    cote_fermier=etat_courant[0]
    if cote_fermier==1:
        autre_cote=2
    else:
        autre_cote=1
    fermier_seul=etat_courant.copy()
    fermier_seul[0]=autre_cote
    if fermier_seul not in etats_interdits:
        etats_accessibles.append(fermier_seul)
    for passager_id in range(1,len(etat_courant)):
        if cote_fermier==etat_courant[passager_id]:
            successeur=etat_courant.copy()
            successeur[0]=autre_cote
            successeur[passager_id]=autre_cote
            if successeur not in etats_interdits:
                etats_accessibles.append(successeur)
    return etats_accessibles

alea_open=[]
alea_closed=[]
alea_stack = []
acpt=0
count_alea = 0
def recherche_aleatoire(etat_courant):
    global acpt
    global alea_open
    global alea_stack
    acpt+=1
    print("--------------------------------------- Étape", acpt,
              "---------------------------------------")
    print("état courant :", etat_courant)

    if etat_courant in alea_open:
        alea_open.remove(etat_courant)
    alea_closed.append(etat_courant)

    if etat_courant==etat_but:
        return [etat_courant]

    accessibles=[successeur for successeur in successeurs(etat_courant)
                     if successeur not in alea_closed]
    print("accessible(s) depuis l'etat courant:", accessibles)
    alea_open = accessibles


    if alea_open != []:
        #cas ou les successeurs existe
        rand_next_id=rand.randrange(len(alea_open))
        successeur=alea_open.pop(rand_next_id)
        alea_stack.append(alea_open)
        print(">successeur choisi: ",successeur)

    else:
        print("branches inexploirées:",alea_stack)
        lock = 1
        while(lock):
            if alea_stack[-lock] != []:
                successeur = alea_stack[-lock][0]
                alea_stack.remove(alea_stack[-lock][0])
                print("switch branch",alea_stack[-lock][0])
                lock = -1
            lock += 1

    suite_chemin = recherche_aleatoire(successeur)

    if suite_chemin!=[]:
        suite_chemin.insert(0,etat_courant)
        return suite_chemin
    else:
        return False

def nettoyerchemin(chemin):
    '''nettoie le resultat de la fct recherche_aleatoire en retirant toutes les branches ferme
        on garde ainsi juste le chemin correcte
    '''
    curseur = -1
    while(chemin[curseur] != chemin[1]):
       if(chemin[curseur] in successeurs(chemin[curseur-1])):
            curseur -=1
       else:
           chemin.remove(chemin[curseur-1])
    return chemin


depth_closed=[]
count_depth = 0
def recherche_profondeur(etat_courant):
    global count_depth
    count_depth += 1
    print("debut >>",etat_courant)

    depth_open=[]
    if etat_courant in depth_open:
        depth_open.remove(etat_courant)

    depth_closed.append(etat_courant)

    if etat_courant==etat_but:
        return [etat_courant]
    accessibles=[successeur for successeur in successeurs(etat_courant)
                     if successeur not in depth_closed]

    depth_open=accessibles+depth_open
    for successeur in depth_open:
        print(">>>successeur:",successeur)
        suite_chemin=recherche_profondeur(successeur)
        if suite_chemin!=[]:
            suite_chemin.insert(0,etat_courant)
            return suite_chemin
        else:
            return False

count_large = 0
def recherche_largeur(etat_initial):
    global count_large
    ouvert=[]
    ferme=[]
    ouvert.append(etat_initial)
    historique=dict()
    historique[tuple(etat_initial)]=(tuple(etat_initial), None)
    print(historique)
    while ouvert:
        etat_courant=ouvert[0]
        if etat_courant==etat_but:
            #print(historique)        
            return chemin(tuple(etat_courant), historique)

        enfants=[successeur for successeur in successeurs(etat_courant)
                     if successeur not in ferme]
        
        for enfant in enfants:
            if enfant in ferme:
                print(">>enfant abandonne")
                continue
            if enfant not in ouvert:
                print(">>enfant visite:",enfant)
                historique[tuple(enfant)]=(tuple(etat_courant), tuple(enfant))
                count_large += 1
                ouvert.append(enfant)
        ouvert.remove(etat_courant)
        ferme.append(etat_courant)

def chemin(etat, historique):
    ascendance = list()
    while historique[etat][1] is not None:
        etat, parent = historique[etat]
        ascendance.append(parent)
    ascendance.append(historique[etat][0])
    ascendance.reverse()
    return ascendance

def etoileh(etat):
	resultat = 4
	for i in range(4):
		if etat[i] != 1:
			resultat -=1
	return resultat

print(etoileh([1,1,1,1]))

def notation_etoile(liste_etat,etage):
	resultat = liste_etat[0]
	gh_resultat = etoileh(liste_etat[0])+etage
	for elem in liste_etat:
		gh_elem = etoileh(elem)+etage
		if(gh_elem < gh_resultat):
			gh_resultat = gh_elem
			resultat =elem
	return resultat

etoile_open=[]
etoile_closed=[]
etoile_stack = []
acpt=0
def recherche_etoile(etat_courant):
    global acpt
    global etoile_open
    global etoile_stack
    acpt+=1
    print("--------------------------------------- Étape", acpt,
              "---------------------------------------")
    print("état courant :", etat_courant)

    if etat_courant in etoile_open:
        etoile_open.remove(etat_courant)
    etoile_closed.append(etat_courant)

    if etat_courant==etat_but:
        return [etat_courant]

    accessibles=[successeur for successeur in successeurs(etat_courant)
                     if successeur not in etoile_closed]
    print("accessible(s) depuis l'etat courant:", accessibles)
    etoile_open = accessibles


    if etoile_open != []:
        #cas ou les successeurs existe
        successeur = notation_etoile(etoile_open,acpt)
        etoile_open.remove(successeur)
        etoile_stack.append(etoile_open)
        print(">successeur choisi: ",successeur)

    else:
        print("branches inexploirées:",etoile_stack)
        lock = 1
        while(lock):
            if etoile_stack[-lock] != []:
                successeur = etoile_stack[-lock][0]
                etoile_stack.remove(etoile_stack[-lock][0])
                print("switch branch",etoile_stack[-lock][0])

                lock = -1
            lock += 1

    suite_chemin = recherche_etoile(successeur)

    if suite_chemin!=[]:
        suite_chemin.insert(0,etat_courant)
        return suite_chemin
    else:
        return False

'''
alea=recherche_aleatoire(etat_initial)
print("Recherche aléatoire chemin parcouru:\n", nettoyerchemin(alea),
          "\n-- longueur:", len(alea), "-- closed:", len(alea_closed),
          "-- open:", len(alea_open))
print(count_alea)
'''
'''
depth=recherche_profondeur(etat_initial)
print("Recherche en profondeur :", depth,
          "-- longueur:", len(depth), "-- closed:", len(depth_closed))
print("Etats parcourue :",count_depth)
'''
'''
print("Recherche en largeur :", recherche_largeur(etat_initial))
print(count_large)

'''


etoile=recherche_etoile(etat_initial)
print("Recherche en etoile :", nettoyerchemin(etoile),
          "-- longueur:", len(etoile), "-- closed:", len(etoile_closed))


