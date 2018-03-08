recherche(X, [X|R]):-!.
recherche(X, [Y|R]):-recherche(X,R).