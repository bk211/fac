#! /usr/bin/env python
# coding: utf-8

'''
Auteur: CAI Chaolei L1 Informatique Grp Y
à excecuter sous python 3.X à cause des hints
La base 32 utilisé ici est celui de Douglas Crockford
Faire attention aux types d'arguments prise en compte par les fcts
'''

from sys import argv
def bin2dec(nombre: str, base = 2 ) -> int:
	# TODO:
	# on s'assure que le nombre est sous forme d'une chaine de caractères
	# on récupère la valeur du 1er caractère à gauche : valeur <- a_{n−1}
	# pour i allant de n−2 à 0 faire
	# valeur <- valeur × b + a_i
    valeur = 0
    for i in range(len(nombre)):
        valeur = valeur * base + int(nombre[i])    
    return valeur


def value(charactere: str, base: int) -> int:
    digits = {"0": 0, "1": 1, "2": 2, "3": 3, "4": 4, "5": 5, "6":6,"7": 7,"8": 8,"9": 9, 
            "A": 10, "B":11, "C": 12, "D": 13, "E": 14, "F": 15,"G": 16,"H": 17,"J": 18,"K": 19,
            "M": 20,"N": 21,"P": 22,"Q": 23,"R" :24,"S": 25,"T": 26,"V": 27,"W": 28,"X": 29,"Y": 30,"Z":31}
    digits_keys="0123456789ABCDEFGHJKMNPQRSTVWXYZ"

#Série de vérification,s'il y a une erreur le programme leve une exception avec un msg d'erreur
#vérifie la base
    if base < 2 or base > 32:
        raise Exception("base invalide")
    
#vérifie si le char est valable
    elif charactere not in digits:
        raise Exception("le charactere n'est pas disponible ds le dict")
    
#vérifie si le char est dans la base
#les dictionnaire sont normalement sans ordre alors autant passer par une autre str keys
    elif charactere not in digits_keys[:base]:
        raise Exception("le charactere est trop gd pour la base")

#ttes les test ont été validé, on donne la valeur.   
    return digits[charactere]
    

def base2dec(nombre: str, base: int) -> str:
    valeur = 0
    for i in range(len(nombre)):
        valeur = valeur * base + value(nombre[i], base)   
    return valeur

def value_reverse(charactere: int, base: int) -> str:
#de la meme maniere que value(),on fait le check et on retourne la valeur si tt se passe bien
    digits = ["0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F",
            "G","H","J","K","M","N","P","Q","R","S","T","V","W","X","Y","Z"]
    
    if base < 2 or base > 32:
        raise Exception("base invalide")
#les 2 tests suivants sont inutiles, tant que la base est valide et que charcatere est bien un INT, la conversion se fait        
    elif charactere not in range(len(digits)):
        raise Exception("le charactere n'est pas disponible ds le dict")
    elif charactere not in range(base):
        raise Exception("le charactere est trop gd pour la base")    
    return digits[charactere]

def reponse(liste):
#ici on inverse les resultat de la conversion et on colle le tout pour avoir une str
    liste.reverse()
    return ''.join(liste)

def dec2base(nombre: int, base: int) -> str:
    resultat = []
    while nombre >= base:
        resultat.append(value_reverse(nombre%base, base))
        nombre = nombre // base
    resultat.append(value_reverse(nombre,base))    
    return reponse(resultat)

# récupération des arguments et lancement de la fonction

'''
#serie de test a faire, je ne maitrise pas encore argv
print(bin2dec('1111',2))    #15
print(base2dec('11110',2))  #30
print(base2dec('21',8))     #17
print(base2dec('1E0',16))   #480
print(base2dec('1GF',16))   #erreur charactere
print(dec2base(10,2))       #1010   
print(dec2base(30,4))       #132
print(dec2base(58,8))       #72
print(dec2base(76,16))      #4C
print(dec2base(31,32))      #Z
print(dec2base(34,32))      #12
print(dec2base(10,1))        #erreur base invalide 
'''
if __name__ == '__main__':
    if len(argv)<2:
        print('Ce programme attend un nombre a convertir')

    print(bin2dec(argv[1])

