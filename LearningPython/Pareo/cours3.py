#ex4
'''
def exo5(n):
	somme=0
	for x in range(n+1):
		somme += x ** 3
	return somme 

x= int(input("un nombre?"))
if x <0:
	print("erreur n doit etre un nb positif")
else:	
	print(f"la somme des cubes de 1 a {x} vaut {exo5(x)}")
'''

#exo6
'''
import random
def affiche_random(n):
	for x in range(0,n):
		print(random.uniform(0,1))
i=int(input("entrez un nombre positif"))
affiche_random(i)
'''

#exo7
''''
def stringlenght():
	x= input("entrez une chaine de caractere ?\n")
	longeur= len(x)
	print(f"votre chaine de caractere fait {longeur} caracteres")
	if longeur >15:
		print("la chaine de caractere est longue")
	else :
		print("la chaine de caractere est courte")	
stringlenght()
'''
#exo8
#2)
'''
def somme(n):
	if n <= 0:
		return 0
	elif n == 1:
		return 1
	else:
		return n+somme(n-1)
print(somme(4))
'''			
#3)
'''
def fib(n):
	if n == 0:
		return 1
	if n ==1 :
		return 1
	else :
		return fib(n-1)+fib(n-2)

x= int(input("entrez un nombre ? "))
print(fib(x))				
'''