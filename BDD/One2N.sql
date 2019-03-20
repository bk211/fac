CREATE OR REPLACE PROCEDURE print2(x number) IS
--num number;
BEGIN
	
	for i in 1 .. x LOOP
	dbms_output.put_line(i||', ');
	END LOOP;
	--RETURN 0;
END;
/