#Ex1
'''
def carre(n):
	if n < 0 :
		return -1
	else:	
		return n**2 * 3

patate = int(input("entrez un nombre ?"))
print(carre(patate))
'''

#Ex2
'''
for x in range(2018,2052):
	if not x % 2 :
		print(x)
'''		

#Ex3
'''
import turtle
for x in range (0,4):
	turtle.forward(90)
	turtle.right(90)
turtle.exitonclick()
'''

#Ex4
'''
tableau = []
for x in range(1,4):
	tableau.append(int(input("entrez un nombre ? ")))
print(f'voici vos nombre {tableau}')
print(f'le maximum de vos 3 nombre est {max(tableau)}')
'''

#Ex5
'''
import random
import statistics
def pick(n,tableau):
	for x in range(0,n):
		tableau.append(random.randint(0,11))

patate = int(input("entrez un nombre ? "))
tab=[]
pick(patate, tab)

print(f'taille de votre tableau : {tab}',
	f'\nEt la moyenne de votre tableau : {statistics.mean(tab)}')
'''

#Ex6
'''
def suite(n):
	if n == 0:
		return 1
	elif n == 1 :
		return 2
	else:
		return 3 * suite(n-1) + 4 * suite(n-2)

rang= int(input('entrez un rang ? '))
print(f'U{rang} = {suite(rang)}')

temp, count = 0, 0
while temp <= 1000:
	temp = suite(count+1)
	count +=1

print(f'la suite depasse 1000 pour U{count} = {suite(count)}')
'''

