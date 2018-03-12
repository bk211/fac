personnes(0,[]):-!.
personnes(N,[(_,_,_,_,_)|T]):-N1 is N-1,personnes(N1,T).

get_personne(1,[H|_],H):-!.
get_personne(N,[_|T],R):-N1 is N-1,get_personne(N1,T,R).

indice1([(anglais,rouge,_,_,_)|_]).
indice1([_|T]):-indice1(T).

indice2([(suedois,_,_,_,chiens)|_]).
indice2([_|T]):-indice2(T).


indice3([(danois,_,the,_,_)|_]).
indice3([_|T]):-indice3(T).

indice4([(_,verte,_,_,_),(_,blanche,_,_,_)|_]).
indice4([_|T]):-indice4(T).

indice5([(_,verte,cafe,_,_)|_]).
indice5([_|T]):-indice5(T).

indice6([(_,_,_,pallmall,oiseaux)|_]).
indice6([_|T]):-indice6(T).

indice7([(_,jaune,_,dunhill,_)|_]).
indice7([_|T]):-indice7(T).

indice8(Personnes):-get_personne(3,Personnes,(_,_,lait,_,_)).

indice9(Personnes):-get_personne(1,Personnes,(norvegien,_,_,_,_)).

indice10([(_,_,_,blend,_),(_,_,_,_,chat)|_]).
indice10([(_,_,_,_,chat),(_,_,_,blend,_)|_]).
indice10([_|T]):-indice10(T).

indice11([(_,_,_,dunhill,_),(_,_,_,_,horse)|_]).
indice11([(_,_,_,_,horse),(_,_,_,dunhill,_)|_]).
indice11([_|T]):-indice11(T).

indice12([(_,_,biere,bluemaster,_)|_]).
indice12([_|T]):-indice12(T).

indice13([(allemand,_,_,prince,_)|_]).
indice13([_|T]):-indice13(T).

indice14([(norvegien,_,_,_,_),(_,blue,_,_,_)|_]).
indice14([(_,blue,_,_,_),(norvegien,_,_,_,_)|_]).
indice14([_|T]):-indice14(T).

%ThemanwhosmokesBlendshasaneighbourwhodrinkseau
indice15([(_,_,_,blend,_),(_,_,eau,_,_)|_]).
indice15([(_,_,eau,_,_),(_,_,_,blend,_)|_]).
indice15([_|T]):-indice15(T).

%Thequestion:Whoownsthefish?
question([(_,_,_,_,fish)|_]).
question([_|T]):-question(T).

solution(Personnes):-
personnes(5,Personnes),
indice1(Personnes),
indice2(Personnes),
indice3(Personnes),
indice4(Personnes),
indice5(Personnes),
indice6(Personnes),
indice7(Personnes),
indice8(Personnes),
indice9(Personnes),
indice10(Personnes),
indice11(Personnes),
indice12(Personnes),
indice13(Personnes),
indice14(Personnes),
indice15(Personnes),
question(Personnes).