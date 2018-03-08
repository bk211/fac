cube :- 
display('veuillez saisir un nbr : '),
read(C), calcule(C).

calcule('stop'):- !.
calcule(X):- N is X*X*X, display('élévé à la puissance 3 donne : '), write(N), nl,
cube.



/*********************************/

p(X):- q(X), not(r(X)).
r(X):- w(X), not(s(X)).
q(a). q(b). q(c).
s(a). s(c).
w(a). w(b).

