prompt tapez le nom de dept
accept userinput
declare
	cursor c is select distinct EMP.NoDEPT, DEPT.NomDEPT from EMP, DEPT where EMP.NoDEPT = DEPT.NoDEPT;
	x dept.nodept%type;
	y dept.NomDEPT%type;

begin
	open c;
	loop
		fetch c into x, y;
		exit when c%notfound;
		if y = &userinput then 
			dbms_output.put_line('Le departement '|| x||' existe ');
		end if;
	end loop;
	close c;
end;
/
    
