hommes(["bob","patrick","john","david","alex","dan"]).
femmes(["claire","marie","eva","julie","sarah","ines"]).
appartient_a(X,[X|_]).
appartient_a(X,[_|Queue]):-appartient_a(X,Queue).
est_homme(X):-hommes(Liste),appartient_a(X,Liste).
est_femme(X):-femmes(Liste),appartient_a(X,Liste).

succ(0).
succ(s(X)):- succ(X).

plus(_,0,_).
plus(0,_,_).
plus(s(X),Y,s(Z)):-plus(X,Y,Z).

mult(0,X,0):-succ(X).
mult(X,0,0):-succ(X).
mult(s(0),X,X):-succ(X).
mult(X,s(0),X):-succ(X).
mult(s(X),Y,Z):-mult(X,Y,Z1),plus(Y,Z1,Z).

puiss(X,0,s(0)):-succ(X).
puiss(0,X,0):-succ(X).
puiss(X,s(0),X):-succ(X).
puiss(s(0),X,s(0)):-succ(X).
puiss(X,s(Y),Z):-puiss(X,Y,Z1),mult(Z1,X,Z).

succ_to_dec(0, 0).
succ_to_dec(s(0), 1).
succ_to_dec(s(X), Y):-succ_to_dec(X, Z), Y is Z+1.

dec_to_succ(X,s(Y)):-succ_to_dec(s(Y),X).

occurence(El,[],0).
occurence(El,[El|L],N):-occurence(El,L,N1),N is N1+1.
occurence(El,[_|L],N):-occurence(E,L,N).

longueur_liste(0,[]).
longueur_liste(I,[_|R]):-longueur_liste(I1,R), I is I1+1.

n_ieme(1,Elem,[Elem|Liste]).
n_ieme(X,Elem,[_|Reste]):-n_ieme(X1,Elem,Reste),X is X1+1.

concat([],L,L).
concat([X|L],Y,[X|L1]):-concat(L,Y,L1).

ajout_nb_liste(Nombre,[Liste]):-member(Nombre,Liste).

separer([X,Y|Reste],[L1],[L2]):-member(Y,L1),-member(Reste,L2).

indice(1,E,[E|_]).
indice(I,E,[_|R]):-indice(I1,E,R),I is I1+1.

dernier(X,[X]).
dernier(X,[X|_]):

supprimer(El,[El|R],R).
supprimer(El,[_|R],[_|R1]):-supprimer(El,R,R1).

a_l_envers([],[]).
a_l_envers([Y|L],X):-a_l_envers(L,X1),concat(X1,[Y],X).