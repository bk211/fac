"""
#ex1
print("hello world")
#ex2
for i in range(2000,2041):
	print(i)
#ex3
for i in range(1,31):
	print(f" 8 * {i}={8*i}")
#ex4
for x in range(1,8):
	print("*" * x)
#ex5
y=int(input("votre nombre?\n"))
print("double du cube = ",(y**3)*2)	
#ex6
y=int(input("votre nombre?"))
if y%2==0:
	print("nombre paire")
else:
	print("nombre impaire")	
	"""
#ex7
"""
x=int(input("votre nombre?(côté le plus gd)\n"))
y=int(input("votre nombre?\n"))
z=int(input("votre nombre?\n"))
if (x**2==(y**2+z**2)):
	print("triangle rectangle")
else:
	print("triangle pas rectangle")	

"""
#ex8
"""
import math
y=int(input("votre nombre?\n"))
z=int(input("votre nombre?\n"))
print("hypothenuse = %f"%math.sqrt(y**2+z**2))

#ex9
import math
x=int(input("votre nombre?\n"))
y=int(input("votre nombre?\n"))
z=int(input("votre nombre?\n"))
perimetre=x+y+z
demi_perimetre=(x+y+z)/2.0
Aire=math.sqrt(demi_perimetre*(demi_perimetre-x)
				*(demi_perimetre-y)*(demi_perimetre-z))
print("perimetre = ",perimetre)
print("aire = ",Aire)
"""
#ex10
import math
from cmath import sqrt

print("ax^2+bx+c")
a=int(input("votre nombre a?\n"))
b=int(input("votre nombre b?\n"))
c=int(input("votre nombre c?\n"))
discriminant = b**2 - 4 * a * c
if discriminant<0:
	x1=(-b+sqrt(discriminant))/(2.0*a)
	x2=(-b-sqrt(discriminant))/(2.0*a)
	print(f"les solutions sont :{x1},et {x2}")
elif discriminant ==0:
	solution = -b / (2.0 * a)	
	print("solution = ",solution)
else:
	x1=(-b+math.sqrt(discriminant))/(2.0*a)
	x2=(-b-math.sqrt(discriminant))/(2.0*a)
	print(f"les solutions sont :{x1},et {x2}")
"""
#ex11
a=int(input("votre nombre?\n"))
resultat=0
for x in range(1,a+1):
	resultat+=x
print(f"resultat={resultat}")	

#ex12
from turtle import *
a = 0
while a < 12:
	a = a + 1 
	forward(150)
	left(150)
exitonclick()	"""