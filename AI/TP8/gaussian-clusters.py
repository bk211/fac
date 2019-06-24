import numpy as np
import matplotlib.pyplot as plt
import time
import random
#CAI Chaolei

# On va ici utiliser des fonctions de la librairie NumPy
# (www.numpy.org) pour générer aléatoirement des données, autour d'un
# centre. Il s'agit de données générées à partir d'une distribution
# normale, soit d'une gaussienne. Les paramètres fournis à la fonction
# sont le centre, c'est à dire le point autour duquel les autres
# seront répartis, soit la moyenne de la gaussienne ; la covariance :
# la matrice diagonale d'étalement des éléments ; ainsi que le nombre
# de points à générer.

centre1=np.array([1,1])            # centre du premier cluster
centre2=np.array([10,10])          # centre du second cluster
sigma1=np.array([[1.5,0],[0,1.5]]) # matrice de covariance du premier cluster
sigma2=np.array([[1.5,0],[0,1.5]]) # matrice de covariance du second cluster
taille1=200                        # nombre de points du premier cluster
taille2=200                        # nombre de points du second cluster
cluster1=np.random.multivariate_normal(centre1,sigma1,taille1)
cluster2=np.random.multivariate_normal(centre2,sigma2,taille2)

# On utilise ici les fonctions de MatPlotLib (matplotlib.org) pour afficher les points.
# On commence par générer les listes d'abcisses, puis d'ordonnées pour chaque cluster.
plt.scatter([point[0] for point in cluster1], [point[1] for point in cluster1], color="pink")
plt.scatter([point[0] for point in cluster2], [point[1] for point in cluster2], color="blue")
plt.scatter(centre1[0], centre1[1], color="red")
plt.scatter(centre2[0], centre2[1], color="red")


def f(x,w):
    #donne y selon l'equation x*w1 + y*w2 = bias, ici elle vaut 0
    return (0-x*w[0])/w[1]  

def perceptron(Input1,Input2):
    weight = np.zeros(len(Input1[0])) #initialise les poids a zero
    coef_apprentissage = 0.1 #0.1 pcq c'est jolie 
    nb_apprentissage = 2 #car il apprend vite 
    for x in range(nb_apprentissage):
        for j in range(len(Input1)):#pour i vers N
            if 1 * np.dot(weight,Input1[j]) <= 0:#verifie les cas rose donc Y = 1
                weight = weight + coef_apprentissage * Input1[j] * 1
                #si classement incorrect, alors update le poids selon la formule 

            if -1 * np.dot(weight,Input2[j]) <= 0:#verifie les cas blue donc Y = -1
                weight = weight + coef_apprentissage * Input2[j] * -1

        #dessine le dessine a chaque fin d'apprentissage
        plt.plot([x for x in range(-7,10)],[f(x,weight) for x in range(-7,7)],label='line')
        plt.scatter([point[0] for point in cluster1], [point[1] for point in cluster1], color="pink")
        plt.scatter([point[0] for point in cluster2], [point[1] for point in cluster2], color="blue")
        plt.scatter(centre1[0], centre1[1], color="red")
        plt.scatter(centre2[0], centre2[1], color="red")
        plt.show()

    return weight


def f2(x,w):
    if not w[2]:
        w[2] = 1
    return -(w[0]+w[1]*x)/w[2]  


def perceptron2(Input1,Input2):
    coef_apprentissage = 0.1
    weight = np.array([0,0,0])
    nb_apprentissage = 2
    for i in range(300):
        Tirage = random.randint(0,1) #choisit le tas de point 1 ou 2
        numero_tire = random.randint(0,len(Input1)-1) 
        Point_tire = np.array([1,0,0])
        if(Tirage):
            Point_tire[1],Point_tire[2] = Input1[numero_tire][0],Input1[numero_tire][1]
            #tire un point dans le tas
            Y_expected = 1
        else:
            Point_tire[1],Point_tire[2] = Input2[numero_tire][0],Input2[numero_tire][1]
            Y_expected = -1
        if( Y_expected * np.dot(weight,Point_tire) <= 0):
            weight = weight + coef_apprentissage * Point_tire * Y_expected
        
        if (Y_expected * np.dot(weight,Point_tire) <= 0 ):
            weight = weight + coef_apprentissage * Point_tire * Y_expected

        if(i % 10 == 0):
            print(i)
            plt.scatter([point[0] for point in cluster1], [point[1] for point in cluster1], color ="pink")
            plt.scatter([point[0] for point in cluster2], [point[1] for point in cluster2], color ="blue")
            plt.scatter(centre1[0], centre1[1], color="red")
            plt.scatter(centre2[0], centre2[1], color="red")
            plt.scatter(Point_tire[1], Point_tire[2], color="Purple")
            plt.plot([x for x in range(-7,7)],[f2(x,weight) for x in range(-7,7)],label='line')
            print(weight)
            plt.show()
    return weight

def perceptron3(Input1,Input2):
    coef_apprentissage = 0.1
    weight = np.array([0,0,0])
    nb_apprentissage = 1


    for x in range(nb_apprentissage):
        for j in range(len(Input1)):#pour i vers N
            P1 = np.array([1,Input1[j][0],Input1[j][1]])
            P2 = np.array([1,Input2[j][0],Input2[j][1]])

            if 1 * np.dot(weight,P1) <= 0:#verifie les cas rose donc Y = 1
                weight = weight + coef_apprentissage * P1 * 1
                #si classement incorrect, alors update le poids selon la formule 

            if -1 * np.dot(weight,P2) <= 0:#verifie les cas blue donc Y = -1
                weight = weight + coef_apprentissage * P2 * -1

            if(j % 30 == 0):
                plt.scatter([point[0] for point in cluster1], [point[1] for point in cluster1], color ="pink")
                plt.scatter([point[0] for point in cluster2], [point[1] for point in cluster2], color ="blue")
                plt.scatter(centre1[0], centre1[1], color="red")
                plt.scatter(centre2[0], centre2[1], color="red")
                plt.scatter(P1[0], P1[1], color="yellow")
                plt.scatter(P2[0], P2[1], color="black")
                plt.plot([x for x in range(centre1[0]-5,centre2[0]+5)],[f2(x,weight) for x in range(centre1[0]-5,centre2[0]+5)],label='line')
                print(weight)
                plt.show()
    return weight







#w = perceptron(cluster1,cluster2)
#w = perceptron2(cluster1,cluster2)
w = perceptron3(cluster1,cluster2)
print(w);
plt.scatter([point[0] for point in cluster1], [point[1] for point in cluster1], color="pink")
plt.scatter([point[0] for point in cluster2], [point[1] for point in cluster2], color="blue")
plt.scatter(centre1[0], centre1[1], color="red")
plt.scatter(centre2[0], centre2[1], color="red")
plt.plot([x for x in range(-7,7)],[f2(x,w) for x in range(-7,7)],label='line')
plt.show()
#plt.plot([x for x in range(-7,7)],[f(x,w) for x in range(-7,7)],label='line')