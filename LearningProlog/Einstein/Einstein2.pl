[
(N1, C1, B1, F1, A1),
(N2, C2, B2, F2, A2),
(N3, C3, B3, F3, A3),
(N4, C4, B4, F4, A4),
(N5, C5, B5, F5, A5)
].

nationalite(p(N, _, _, _,_), N). /* cette personne a la nationalite N*/ 
couleur(p(_, C, _, _,_), C).     /* cette personne a une maison de couleur C*/
boit(p(_, _, B, _,_), B).        /* cette personne boit un boisson B */
fume(p(_, _, _, F,_), F).        /* cette personne fume une cigarette F */
eleve(p(_, _, _, _, A), A).    /* cette personne eleve un animal A */

gauche(A, B, [A, B, C, D, E]). 
gauche(B, C, [A, B, C, D, E]). 
gauche(C, D, [A, B, C, D, E]). 
gauche(D, E, [A, B, C, D, E]). 
gauche(B, A, [A, B, C, D, E]). 
gauche(C, B, [A, B, C, D, E]). 
gauche(D, C, [A, B, C, D, E]). 
gauche(E, D, [A, B, C, D, E]).
voisin(A, B, Liste):-gauche(A, B, L).
voisin(A, B, Liste):-gauche(B, A, L).
premier(A, [A, _, _, _, _]).
centre(C, [_, _, C, _, _]).

/* Resolution*/
reponse(Grandliste, Ppoisson):-
 Grandliste=[p(N1, C1, B1, F1, A1),
 p(N2, C2, B2, F2, A2),
 p(N3, C3, B3, F3, A3),
 p(N4, C4, B4, F4, A4),
 p(N5, C5, B5, F5, A5)],

/* 1.L'Anglais vit dans une maison rouge. */
 member(Indice1, Grandliste),
 couleur(Indice1, rouge),
 nationalite(Indice1, anglaise),

/* 2.Le Suédois a des chiens comme animaux domestiques. */
 member(Indice2, Grandliste),
 nationalite(Indice2, suedoise),
 eleve(Indice2, chiens),

/* 3. Le Danois boit du thé. */
 member(Indice3, Grandliste),
 nationalite(Indice3,danoise),
 boit(Indice3, the),

/* 4. La maison verte est à gauche de la maison blanche. */
 member(Pverte, Grandliste),
 couleur(Pverte, verte),
 member(Pblanche, Grandliste),
 couleur(Pblanche, blanche),
 gauche(Pverte, Pblanche, Grandliste), 

/* 5. Le propriétaire de la maison verte boit du café. */
 member(Pverte, Grandliste),
 couleur(Pverte, verte),
 boit(Pverte, cafe),

/* 6. La personne qui fume des Pall Mall a des oiseaux. */
 member(Ppallmall, Grandliste),
 fume(Ppallmall, pallmall),
 eleve(Ppallmall, oiseaux),

/* 7. Le propriétaire de la maison jaune fume des Dunhill.*/
 member(Pjaune,Grandliste),
 couleur(Pjaune,jaune),
 fume(Pjaune,dunhill),

/* 8. La personne qui vit dans la maison du centre boit du lait. */
 centre(Pcentre, Grandliste),
 boit(Pcentre, lait),


/* 9. Le Norvégien habite la première maison. */
 premier(Norvegien, Grandliste),
 nationalite(Norvegien, norvegienne),


/* 10. L'homme qui fume les Blend vit à côté de celui qui a des chats. */
 member(Pblend, Grandliste),
 fume(Pblend, blend),
 member(Pchat, Grandliste),
 member(Pchat, chat),
 voisin(Pblend, Pchat, Grandliste),

/* 11. L'homme qui a un cheval est le voisin de celui qui fume des Dunhill. */
 member(Pcheval, Grandliste),
 eleve(Pcheval, cheval),
 member(Pdunhill, Grandliste),
 fume(Pdunhill, dunhill),
 voisin(Pcheval, Pdunhill, Grandliste),

/* 12. Le propriétaire qui fume des Blue Master boit de la bière. */
 member(Pbluemaster, Grandliste),
 fume(Pbluemaster, bluemaster),
 boit(Pbluemaster, biere),

/* 13. L'Allemand fume des Prince. */
 member(Allemand, Grandliste),
 nationalite(Allemand, allemande),
 fume(Allemand, prince),

/* 14. Le Norvégien vit juste à côté de la maison bleue. */
 member(Pbleu, Grandliste),
 couleur(Pbleu,Grandliste),
 voisin(Norvegien, Pbleu, Grandliste),

/* 15. L'homme qui fume des Blend a un voisin qui boit de l'eau.*/
 member(Peau, Grandliste),
 boit(Peau, eau),
 voisin(Pblend, Peau, Grandliste),

/* Question:qui a le poisson? */
 member(Ppoisson, Grandliste),
 eleve(Ppoisson, poisson),
 write(Ppoisson).