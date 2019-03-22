create table EMP (NoEMP NUMBER(4),ENAME Varchar2(10),JOB VARCHAR2(9),MGR NUMBER(4), DateEMB DATE, SAL NUMBER(7,2),COMM NUMBER(7,2),NoDEPT NUMBER(4),PRIMARY KEY(NoEMP)   );

insert into EMP values(7369, 'SMITH','CLERK',7902,TO_DATE('17/12/1980', 'DD/MM/YYYY'),800,NULL,20);
insert into EMP values(7499, 'ALLEN','SALESMAN',7698,TO_DATE('20/02/1981', 'DD/MM/YYYY'),1600,300,30);
insert into EMP values(7521, 'WARD','SALESMAN',7698,TO_DATE('22/02/1981', 'DD/MM/YYYY'),1250,500,30);
insert into EMP values(7566, 'JONES','MANAGER',7839,TO_DATE('02/04/1981', 'DD/MM/YYYY'),2975,NULL,20);
insert into EMP values(7654, 'MARTIN','SALESMAN',7698,TO_DATE('28/09/1981', 'DD/MM/YYYY'),1250,1400,30);
insert into EMP values(7698, 'BLAKE','MANAGER',7839,TO_DATE('01/05/1981', 'DD/MM/YYYY'),2850,NULL,30);
insert into EMP values(7782, 'CLARK','MANAGER',7839,TO_DATE('09/06/1981', 'DD/MM/YYYY'),2450,NULL,10);
insert into EMP values(7788, 'SCOTT','ANALYST',7566,TO_DATE('09/12/1982', 'DD/MM/YYYY'),3000,NULL,20);
insert into EMP values(7839, 'KING','PRESIDENT',NULL,TO_DATE('17/11/1981', 'DD/MM/YYYY'),5000,NULL,10);
insert into EMP values(7844, 'TURNER','SALESMAN',7698,TO_DATE('08/09/1981', 'DD/MM/YYYY'),1500,0,30);
insert into EMP values(7876, 'ADAMS','CLERK',7788,TO_DATE('12/01/1983', 'DD/MM/YYYY'),1100,NULL,20);
insert into EMP values(7900, 'JAMES','CLERK',7698,TO_DATE('03/12/1981', 'DD/MM/YYYY'),950,NULL,30);
insert into EMP values(7902, 'FORD','ANALYST',7566,TO_DATE('03/12/1981', 'DD/MM/YYYY'),3000,NULL,20);
insert into EMP values(7934, 'MILEER','CLERK',7782,TO_DATE('23/01/1981', 'DD/MM/YYYY'),1300,NULL,10);

create table DEPT(NoDEPT NUMBER(2) PRIMARY KEY,NomDEPT VARCHAR2(14),LOC VARCHAR(13));
insert into DEPT values(10,'ACCOUNTING', 'NEW YORK');
insert into DEPT values(20,'REASEARCH', 'DALLAS');
insert into DEPT values(30,'SALES', 'CHICAGO');
insert into DEPT values(40,'OPERATIONS', 'BOSTON');


select * from EMP ;
select ENAME,JOB from EMP;
select * from EMP where NoDEPT = 20;
select ENAME,SAL from EMP where JOB = 'SALESMAN' and COMM IS NOT NULL;
select ENAME,SAL from EMP where JOB = 'SALESMAN' and COMM >0;
select distinct NoDEPT from EMP ;
select ENAME,SAL,COMM from EMP where JOB = 'MANAGER';
select LOC from EMP INNER JOIN DEPT ON EMP.NoDEPT = DEPT.noDEPT where ENAME = 'FORD';
select * from EMP where SAL BETWEEN 1000 and 3000;
select ENAME,JOB,SAL from EMP where SAL < 3000 ORDER BY SAL DESC;
select ENAME,JOB,SAL,NoDEPT from EMP ORDER BY NoDEPT DESC, SAL ASC ;
select ENAME,JOB,SAL,NomDEPT from EMP inner join DEPT on EMP.NoDEPT = DEPT.NoDEPT order by SAL ASC;


update EMP set SAL = SAL + 200;
insert into DEPT values(40,'KITCHEN','LA');
create table COMMISSION (NomEmp VARCHAR(10), Emploi VARCHAR(10), Salaire number(7,2),ValComm Number(4,2));
insert into COMMISSION values('aaa','bbb',10000,50);
insert into COMMISSION values('ccc','ddd',10001,50);
insert into COMMISSION values('eee','fff',10000,50);
delete from commission where NomEmp = 'aaa';
alter table commission modify ValComm Number(7,2);
insert into commission (NomEmp, Emploi, Salaire,ValComm) select ENAME as NomEmp, JOB as Emploi, SAL as Salaire, COMM as ValComm from emp where COMM >0;
truncate table commission;
drop table commission;
create table COMMISSION AS select ENAME as NomEmp, JOB as Emploi, SAL as Salaire, COMM as ValComm from emp where COMM >0;


select count(NoEMP) from emp where SAL > any(select SAL from emp);
select count(*) from emp where SAL > any(select SAL from emp);
select count(distinct NoDEPT) from emp;
select avg(SAL) from emp;
select ENAME,SAL from emp where SAL > any (select SAL from emp where NoDEPT = 30);
select ENAME from emp where NoDEPT = 10 and SAL > all (select SAL from emp where NoDEPT = 20);
select min(SAL), max(SAL),NoDEPT from emp group by NoDEPT;
select avg(SAL), job from emp group by JOB;
select min(SAL), max(SAL),NoDEPT , count(NoDEPT) from emp group by NoDEPT having count(NoDEPT) > 2;
select min(SAL),NoDEPT from emp group by NoDEPT having MIN(SAL) > (select avg(sal) from emp where JOB = 'CLERK') ;

create view EMPDEPT AS select emp.*, dept.NomDEPT, dept.LOC from emp INNER JOIN dept ON emp.NoDEPT = dept.NoDEPT;
select ENAME, LOC, SAL from EMPDEPT where SAL > 2000;
truncate table EMP;
drop table EMP;
create table EMP (NoEMP NUMBER(4),ENAME Varchar2(10),JOB VARCHAR2(9),MGR NUMBER(4), DateEMB DATE, SAL NUMBER(7,2),COMM NUMBER(7,2),NoDEPT NUMBER(2),PRIMARY KEY(NoEMP)   );
alter table EMP drop column COMM;
alter table EMP add COMM NUMBER(7,2);
alter table EMP rename column COMM TO BONUS;
alter table DEPT add EMAIL VARCHAR2(10);
