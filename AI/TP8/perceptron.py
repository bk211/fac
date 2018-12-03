import numpy as np

X = np.array([
    [-2,4,-1],
    [4,1,-1],
    [1, 6, -1],
    [2, 4, -1],
    [6, 2, -1],

])

y = np.array([-1,-1,1,1,1])

def perceptron_sgd(X, Y):
    w = np.zeros(len(X[0]))
    eta = 1 #coefficient d'apprentissage
    epochs = 1 # nb de loop d'apprentissage
    for t in range(epochs):

        for i, x in enumerate(X):
            print("\ncase: ",i,"\nx= ",x)
            print("Weigths",w)
            print("W * X = ",np.dot(X[i],w))
            print("*Y = ",np.dot(X[i],w) *Y[i])
            if (np.dot(X[i], w)*Y[i]) <= 0:
                print("error,w++  ",w)
                print("+++  ",eta*X[i]*Y[i] )
                w = w + eta*X[i]*Y[i]
                print(w)

    return w

w = perceptron_sgd(X,y)
print(w)
#print(X)