prompt tapez le numero de dept
accept userinput
declare
	cursor c is select emp.SAL, emp.ENAME, dept.Nodept, dept.NomDEPT from emp,dept where SAL > 1400 and emp.NoDEPT = dept.Nodept and emp.NoDEPT = &userinput;
	x emp.SAL%type;
	y emp.ENAME%type;
	z dept.Nodept%type;
	w dept.NomDEPT%type;
begin
	open c;
	loop
		fetch c into x, y, z,w;
		exit when c%notfound;
			dbms_output.put_line('L employe '|| y ||' du departement '|| w|| ' a un salaire de '|| x );
	end loop;
	close c;
end;
/
    
