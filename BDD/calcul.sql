create or replace function calcul(x number,y number) 
return number 
is z number;
begin
	z := 2 * x + y*y;
	return z;
end;
/
prompt tapez un entier n
accept n
prompt tapez un entier m
accept m

declare
	resultat number;

begin
      resultat := calcul(&n,&m);
      dbms_output.put_line(resultat);
end;
/