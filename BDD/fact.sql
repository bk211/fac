create or replace function facto(x number) return number is
begin
     if x=0 then
        return(1);
     else
         return(facto(x-1)*x);
     end if;
end;
/
prompt tapez un entier
accept nbre
declare factor number;
begin
      factor:=facto(&nbre);
      dbms_output.put_line(&nbre||'='||factor);
end;
/