max(X,Y,Z):-inferieur(X,Y),!,Z=Y.
max(X,Y,Z):-Z=X.

inferieur(X,Y):-X=1,Y=2.
inferieur(X,Y):-X=1,Y=1.
inferieur(X,Y):-X=2,Y=2.

fusion([],L,L).
fusion(L,[],L).
fusion([X|Xs],[Y|Ys],[X|Zs]):-X<Y,!,fusion(Xs,[Y|Ys],Zs).
fusion([X|Xs],[X|Ys],[X,X|Zs]):-!,fusion(Xs,Ys,Zs).
fusion([X|Xs],[Y|Ys],[Y|Zs]):-!,fusion([X|Xs],Ys,Zs).