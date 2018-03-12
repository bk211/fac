affichage_5maisons([X|L]) :- writeln(X), affichage_5maisons(L).

personnes(0, []) :- !.
personnes(N, [(_,_,_,_,_)|T]) :- N1 is N-1, personnes(N1,T).

get_personne(1,[H|_],H):-!.
get_personne(N,[_|T],R):-N1 is N-1,get_personne(N1,T,R).


% L Anglais vit dans une maison rouge.
indice1([(anglais,rouge,_,_,_)|_]).
indice1([_|Tete]) :- indice1(Tete).

% Le Suedois a des chiens comme animaux domestiques.
indice2([(suedois,_,_,_,chiens)|_]).
indice2([_|Tete]) :- indice2(Tete).

% Le Danois boit du the.
indice3([(danois,_,the,_,_)|_]).
indice3([_|Tete]) :- indice3(Tete).

% La maison verte est a gauche de la maison blanche. 
indice4([(_,verte,_,_,_),(_,blanche,_,_,_)|_]).
indice4([_|Tete]) :- indice4(Tete).


% Le proprietaire de la maison verte boit du cafe. 
indice5([(_,verte,cafe,_,_)|_]).
indice5([_|Tete]) :- indice5(Tete).

% La personne qui fume des Pall Mall a des oiseaux. 
indice6([(_,_,_,pallmall,oiseaux)|_]).
indice6([_|Tete]) :- indice6(Tete).

% Le proprietaire de la maison jaune fume des Dunhill. 
indice7([(_,jaune,_,dunhill,_)|_]).
indice7([_|Tete]) :- indice7(Tete).

% La personne qui vit dans la maison du centre boit du lait. 
indice8(Liste):-get_personne(3, Liste,(_,_,lait,_,_)).

% Le Norvegien habite la première maison. 
indice9(Liste):-get_personne(1, Liste,(norvegien,_,_,_,_)).

% L homme qui fume les Blend vit à côte de celui qui a des chats. 
indice10([(_,_,_,blend,_),(_,_,_,_,chats)|_]).
indice10([(_,_,_,_,chats),(_,_,_,blend,_)|_]).
indice10([_|Tete]) :- indice10(Tete).

% L homme qui a un cheval est le voisin de celui qui fume des Dunhill. 
indice11([(_,_,_,dunhill,_),(_,_,_,_,cheval)|_]).
indice11([(_,_,_,_,cheval),(_,_,_,dunhill,_)|_]).
indice11([_|Tete]) :- indice11(Tete).

% Le proprietaire qui fume des Blue Master boit de la biere. 
indice12([(_,_,biere,bluemaster,_)|_]).
indice12([_|Tete]) :- indice12(Tete).

% L Allemand fume des Prince. 
indice13([(allemand,_,_,prince,_)|_]).
indice13([_|Tete]) :- indice13(Tete).

% Le Norvegien vit juste à côte de la maison bleue. 
%indice14([(norvegien,_,_,_,_),(_,bleue,_,_,_)|_]).
indice14([(norvegien,_,_,_,_),(_,bleue,_,_,_)|_]).
indice14([(_,bleue,_,_,_),(norvegien,_,_,_,_)|_]).
indice14([_|Tete]):-indice14(Tete).

% L homme qui fume des Blend a un voisin qui boit de l eau.
indice15([(_,_,_,blend,_),(_,_,eau,_,_)|_]).
indice15([(_,_,eau,_,_),(_,_,_,blend,_)|_]).
indice15([_|Tete]) :- indice15(Tete).

question([(_,_,_,_,poisson)|_]).
question([_|Tete]) :- question(Tete).

solution(Liste):-
 personnes(5,Liste),
 indice1(Liste),
 indice2(Liste),
 indice3(Liste),
 indice4(Liste),
 indice5(Liste),
 indice6(Liste),
 indice7(Liste),
 indice8(Liste),
 indice9(Liste),
 indice10(Liste),
 indice11(Liste),
 indice12(Liste),
 indice13(Liste),
 indice14(Liste),
 indice15(Liste),
 question(Liste),

