longueur([],0).
longueur([X|Xs], N):-longueur(Xs,N1),
 N is N1+1.

somme([],0).
somme([X|Xs],S):-somme(Xs,Z),
 S is X+Z.

appartenir(X,[X|W]).
appartenir(X,[Y|Ys]):- 
 appartenir(X,Ys).

concat([],Z,Z).
concat([X|Xs],Y,[X|Z]):-
 concat(Xs,Y,Z).

ordonne([]).
ordonne([X,Y|Reste]):- X < Y,
 ordonne(Reste).

envers([],[Ys])
envers([X|Xs],[Y]):-
 envers(Xs,[X|Y]).

occurence(X, [], 0).
occurence(X, [Y|Ys],Z):
 !,
 occurence(X,Y,Z1),
 Z is Z1+1.

