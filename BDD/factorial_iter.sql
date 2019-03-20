DECLARE 
   num number;
   factorial number;  
   i number;   


FUNCTION fact(x number) 
RETURN number  
IS 
   f number; 
BEGIN 

   f := 1;
   IF x <=1 THEN
      RETURN f;
   ELSE 
      FOR i in 1 .. x LOOP
         --dbms_output.put_line(i);
         f := f * i;
         dbms_output.put_line(f);
         
      END LOOP;
   END IF; 
RETURN f; 
END;  

BEGIN 
   num := &num; 
   factorial := fact(num); 
   dbms_output.put_line(' Factorial of '|| num || ' is ' || factorial); 
END; 
/