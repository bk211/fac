prompt tapez le numero de dept
accept userinput
declare
	cursor c is select nodept,nomdept, loc from dept;
	x dept.nodept%type;
	y dept.nomdept%type;
	z dept.loc%type;
begin
	open c;
	loop
		fetch c into x, y, z;
		exit when c%notfound;
		if x = &userinput then
			dbms_output.put_line('Le dept '|| y ||' se trouve a '|| z);
		end if;
	end loop;
	close c;
end;
/
    
