import os 
"""Ce programme permet d'afficher le triangle de Pascal au rang n"""
def triangles(x):
    for i in range(x):
        if i==0:
            y=[1]
        else:
            y=[1]+[y[j-1]+y[j] for j in range(1,len(y))]+[1]
        yield y
n=int(input("rang du triangle?"))
for y in triangles(n):
    print(y)
os.system("pause")