%incremente les elements d'une liste +1,
skto([],[]).
skto([X|L],[S|R]):-
    S is X+1,
    skto(L,R).

split(L2,0,[],L2).
split([X|L],N,[X|L1],L2):-
    N>0,
    N1 is N-1,
    split(L,N1,L1,L2).

plage(X,X,[X]).
plage(X,Y,[X|R]):-
    X1 is X+1,
    plage(X1,Y,R).

transfer(X,[],[],[X]).
transfer(X,[Y|Ys],[Y|Ys],[X]):-X\==Y.
transfer(X,[X|Xs],Ys,[X|Zs]):-transfer(X,Xs,Ys,Zs).
            
cpp([],[]).
cpp([X|Xs],[Z|Zs]):-
    transfer(X,Xs,Ys,Z),
    cpp(Ys,Zs).
codage(L1,L2):-cpp(L1,L),transform(L,L2).
transform([],[]).
transform([[X|Xs]|Ys],[[N,X]|Zs]):-length([X|Xs],N),transform(Ys,Z1).

cpp2([],[]).
cpp2([],[[0,_]]).
cpp2([X|R],[[Z,X]|R1]):-cpp2(R,[[Z1,X]|R1]),Z is Z1+1.
cpp2([X|R],[[0,_],[Z,X]|R1]):-cpp2(R,[[Z1,X]|R1]),Z is Z1+1.

rot([],_,[]).
rot([X],_,[X]).
rot(L,N,X):-N>0,split(Liste,N,L1,L2),append(L2,L1).