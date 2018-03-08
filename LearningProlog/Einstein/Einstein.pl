personne(['anglais','suedois','danois','norvegien','allemand']).
maison(['rouge','verte','bleue','jaune','blanche']).
boit(['the','eau','cafe','lait','biere']).
fume(['pallmall','dunhill','blend','bluemaster','prince']).
animal(['poisson','chat','chien','cheval','oiseau']).
numero(1,2,3,4,5).


vit_maison('anglais','rouge').

a_animal('suidois','chien').

qui_boit('danois','the').

a_gauche(X,Y):-vit_maison(X,'verte'),vit_maison(Y,'blanche').

qui_boit(_,'cafe'):-vit_maison(_,'verte').

qui_fume(_,'pallmall'):-a_animal(_,'oiseau').

vit_maison(_,'jaune'):-qui_fume(_,'dunhill').

vit_au_centre(_):-qui_boit(_,'lait'),a_gauche(X),a_droite(Y).

vit_au_premier('norvegien'):-a_gauche('rien'),a_droite(_).

voisin(X,Y):-a_gauche(X,Y);a_droite(X,Y).
qui_fume(_,'blend'):-voisin(_,X),a_animal(X,'chat').

a_animal(X,'cheval'):-voisin(X,Y),qui_fume(Y,'dunhill').

qui_fume(_,'bluemaster'):-qui_boit(_,'biere').

qui_fume('allemand','prince').

voisin(_,'norvegien'):-vit_maison(_,'bleue').

qui_fume(_,'blend'):-voisin(_,X),qui_boit(X,'eau').

persons(0, []) :- !.
persons(N, [(_Men,_Color,_Drink,_Smoke,_Animal)|T]) :- N1 is N-1, persons(N1,T).
person(1, [H|_], H) :- !.
person(N, [_|T], R) :- N1 is N-1, person(N1, T, R).

indice1([('anglais','rouge',_, _, _)|_]).
indice1([_|Tete]) :- indice1(Tete).

indice2([('suedois',_,_,_,'chien')|_]).
indice2([_|Tete]) :- indice2(Tete).

indice3([('danois',_,'the',_,_)|_]).
indice3([_|Tete]) :- indice3(Tete).

indice4([(_,'verte',_,_,_),(_,'blanche',_,_,_)|_]).
indice4([_|Tete]) :- indice4(Tete).

indice5([(_,'verte','cafe',_,_)|_]).
indice5([_|Tete]) :- indice5(Tete).

indice6([(_,_,_,'pallmall','oiseau')|_]).
indice6([_|Tete]) :- indice6(Tete).

indice7([(_,'jaune',_,'dunhill',_)|_]).
indice7([_|Tete]) :- indice7(Tete).

indice8(Persons) :- person(3, Persons, (_,_,'lait',_,_)).

indice9(Persons) :- person(1, Persons, ('norvegien',_,_,_,_)).

indice10([(_,_,_,'blend',_),(_,_,_,_,'chat')|_]).
indice10([(_,_,_,_,'chat'),(_,_,_,'blend',_)|_]).
indice10([_|Tete]) :- indice10(Tete).

indice11([(_,_,_,'dunhill',_),(_,_,_,_,'cheval')|_]).
indice11([(_,_,_,_,'cheval'),(_,_,_,'dunhill',_)|_]).
indice11([_|Tete]) :- indice11(Tete).

indice12([(_,_,'biere','bluemaster',_)|_]).
indice12([_|Tete]) :- indice12(Tete).

indice13([(german,_,_,prince,_)|_]).
indice13([_|Tete]) :- indice13(Tete).

indice14([('norvegien',_,_,_,_),(_,blue,_,_,_)|_]).
indice14([(_,blue,_,_,_),('norvegien',_,_,_,_)|_]).
indice14([_|Tete]) :- indice14(Tete).

indice15([(_,_,_,'blend',_),(_,_,'eau',_,_)|_]).
indice15([(_,_,'eau',_,_),(_,_,_,'blend',_)|_]).
indice15([_|Tete]) :- indice15(Tete).

question([(_,_,_,_,'poisson')|_]).
question([_|T]) :- question(T).