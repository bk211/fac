L1 = ['adam', 'LISA', 'barT']
def normalize(name):
	return name.capitalize()

L2 = list(map(normalize, L1))
print(L2)