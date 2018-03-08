''' #Ex1
a = int(input("le nombre a?"))
b = int(input("le nombre b?"))
maximum = max(a,b)
print(f"le maximum est {maximum}")
'''

'''#Ex2
a = int(input("le nombre a?"))
b = int(input("le nombre b?"))
minimum = min(a,b)
print(f"le minimum est {minimum}")
'''

'''#Ex3
x = int(input("un nombre ?"))
somme=0
for y in range(1,x+1):
	somme += y*y
print(somme)
'''

'''#Ex3
a = int(input("le nombre a?"))
b = int(input("le nombre b?"))
c = int(input("le nombre c?"))
if ( a < b and b < c ):
	print("oui")
else:
	print("non")
'''

'''#Ex4
import math
Ax = int(input("Coordonnee Ax?"))
Ay = int(input("Coordonnee Ay?"))
Bx = int(input("Coordonnee Bx?"))
By = int(input("Coordonnee By?"))
X=Bx-Ax
Y=By-Ay
Distance= math.sqrt( X ** 2+ Y ** 2)
print(f"la Distance entre A({Ax},{Bx}) et B({Bx},{By}) est {Distance}")
'''

'''#Ex5
_list=[]
for x in range(0,3):
	_list.append(int(input("un nombre ?")))
print(sorted(_list))	

_list=[]
for x in range(0,3):
	_list.append(int(input("un nombre ?")))
print(sorted(_list,reverse=True))
'''

'''#Ex7
import random
_list=[]
for x in range(0,4):
	_list.append(random.uniform(0.0,1.0))
print(_list)
somme=0
for x in _list:
	somme += x
moyenne=somme/4
print("moyenne : ",{moyenne})	
'''
'''#Ex8
import random
_list=[]
for x in range(0,50):
	_list.append(random.uniform(0.0,1.0))
print(_list)
somme=0
for x in _list:
	somme += x
moyenne=somme/50
print("moyenne : ",{moyenne})	
#print(len(_list))
'''

#Ex8

#from turtle import *
#a)rectangle
'''
for x in range(0,2):
	forward(200)
	left(90)
	forward(100)
	left(90)
'''
#b)triangle
'''
for x in range(0,3):
	forward(100)
	left(120)
'''
#c)hexagone
'''
for x in range(0,6):
	right(60)
	forward(100)
'''
#d) double triangles
'''
for x in range(0,2):
	for x in range(0,3):
		pendown()
		left(120)
		forward(100)
	penup()
	goto(120,0)
'''

#e)etoile
'''
for i in range(0,6):
	forward(50)
	left(60)
	forward(50)
	right(120)

#f)
#exitonclick()

#ex9
'''
from tkinter import *
fen1 =Tk()
tex1 = Label(fen1, text='Bonjour ',fg='red')
tex1.pack()
bou1= Button(fen1, text='Quitter',command=fen1.destroy)
bou1.pack()
fen1.mainloop()
