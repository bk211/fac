def P(x):
    return (2 * ( x ** 2 )- 3 * x - 2)
    

def liste_P(liste_x): 
    result = [P(variable) for variable in liste_x]
    return result

liste_P([0, 1, 2, 3, 4])
