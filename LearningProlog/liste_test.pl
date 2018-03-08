loc_list([apple,broccoli,crackers],kitchen).
loc_list([desk,computer],office).
loc_list([flashlight,envelope],desk).
loc_list([stamp,key],envelope).
loc_list(['washing machine'],cellar).
loc_list([nani],'washing machine').
loc_list([],hall).

membre(A,[A|B]).
membre(X,[A|B]) :-membre(X,B).

location(X,Y):-loc_list(List,Y),membre(X,List).
add_thing(NewThing,Container,NewList):-
 location(OldList,Container),
 append([NewThing],OldList,NewList).
 