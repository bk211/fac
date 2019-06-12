declare
	cursor mycur is select * from EMP;
	a emp.NoEMP%type;
	b emp.ENAME%type;
	c emp.JOB%type;
	d emp.MGR%type;
	e emp.dateEMB%type;
	f emp.SAL%type; 
	g emp.COMM%type;
 	h emp.NoDEPT%type;
 
begin
	open mycur;
	loop
		fetch mycur into a,b,c,d,e,f,g,h;
		exit when mycur%notfound;
		insert into EMPBIS values(a,b,c,d,e,f,g + g * 0.5,h);
	end loop;

	close mycur;

end;
/