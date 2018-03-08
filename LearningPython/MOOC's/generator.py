import os
L1=['Hello','World',18,'Apple',None]
L2=[]
for elem in L1:
	if isinstance(elem,str):
		elem=elem.lower()
		L2.append(elem)
print(L2)		