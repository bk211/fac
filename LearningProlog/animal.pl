
question([E]) :-

write('Vous pensiez à '),

write(E).

question([T, R1, R2]) :-

write(T),

read(Rep),

(Rep = o, question(R1) ;

Rep = n, question(R2)).

liste([E]) :- write(E), write('\n\n').

liste([T|Q]) :-

write(T), write(', '), liste(Q).

jeu :-

Animaux = ['chat', 'chien', 'ours', 'éléphant', 'aigle', 'corbeau', 'tortue', 'lézard', 'lion'],

Questions =

['Est-ce un mammifère ?',

['Est-ce un animal domestique ?',

['Miaule-t-il ?',

['un chat'],

['un chien']

],

['Possède-t-il une fourrure ?',

['un ours'],

['un éléphant']

]

],

['Vole-t-il ?',

['A-t-il un bec orange ?',

['un merle'],

['un corbeau']

],

['A-t-il une carapace ?',

['une tortue'],

['un lézard']

]

]

],

write('Choisissez un animal parmi : '),

liste(Animaux),

question(Questions).




/*********************execution*****************/
/*?- jeu.*/
/*Choisissez un animal parmi : chat, chien, ours, éléphant, aigle, corbeau, tortue, lézard, lion*/

/*Est-ce un mammifère ?o.*/
/*Est-ce un animal domestique ?o.*/
/*Miaule-t-il ?o.*/
/*Vous pensiez à un chat*/
/*true .*/
/**********************/
/****?- jeu.*/
/*Choisissez un animal parmi : chat, chien, ours, éléphant, aigle, corbeau, tortue, lézard, lion*/

/*Est-ce un mammifère ?n.*/
/*Vole-t-il ?n.*/
/*A-t-il une carapace ?o.*/
/*Vous pensiez à une tortue*/
/*true .*/


