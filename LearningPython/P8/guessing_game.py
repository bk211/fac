import random
def guess_the_number(patate):
	nb_essais = 0 
	reponse_joueur =- 1
	reponse=random.randint(0, patate)
	while reponse != reponse_joueur:
		reponse_joueur= int(input('entrez un nombre? '))
		nb_essais += 1
		if reponse_joueur > reponse:
			print("trop grand")
		elif reponse_joueur < reponse :
			print("trop petit")	
	print(f"felicitation, bonne reponse avec {nb_essais} tentatives")
	return nb_essais

def game_launcher(tab_resultat):
	maximum= int(input("le maximum ? "))
	if not maximum:
		print("merci, fin du prog")
	elif maximum > 0 :
		tab_resultat.append({maximum:guess_the_number(maximum)},)		

def main():
	resultat=[]
	yes_yes_yes = int(input("voulez vous lancer une partie? (1/0) ?"))
	while yes_yes_yes:
		game_launcher(resultat)
		yes_yes_yes= int(input("continuer ? (1/0) "))
	print(resultat)

def f(a, b, c):
    print(a, b, c)
L = [1, 2, 'a']

f(L[0], L[1], L[2])
f(*L)