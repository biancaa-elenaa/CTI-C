select * from student

select distinct an from student

select nume, an from student where an<>2 

select nume from student where nume like '% M%'

select * from student order by an 

select * from student order by an desc

select * from student order by an desc, nume

select lower('AAAAbbbbCCCC') from dual

select upper('AAAAbbbbCCCC') from dual

select substr('ana are mere',5,3) from dual

select * from student where media between 5 and 10

select nvl(null,'este null') from dual

select * from student where nume like '% %u'

select substr(nume,1,instr(nume, ' ')-1) as Prenume,
       substr(nume,instr(nume, ' ')+1) as NumeFamilie,
       an 
from student

select nume,
       substr(nume,1,instr(nume, ' ')-1) as Prenume,
       length(substr(nume,1,instr(nume, ' ')-1)) as lungime
from student
    where 
        length(substr(nume,1,instr(nume, ' ')-1)) >= 7


select * from student


select nume,an,datan
from student
    where (extract(year from sysdate) - extract(year from datan)) = 20

select * from student
    where ( extract(month from sysdate) like extract(month from datan) )

select * from student
    where bursa is null 

select * from student
    where bursa is null or bursa=0

select nume, an, nvl(cnp,'CNP necompletat') from student where an=2

select nume, cnp, an from student where cnp like '2%'

select nume, cnp, an from student where cnp like '1%'

select nume, cnp, an from student where mod(to_number(substr(cnp,1,1)),2) = 1

select nume, an,
    case when mod(to_number(substr(cnp,1,1)),2) = 1 then 'baiat'
         when mod(to_number(substr(cnp,1,1)),2) = 0 then 'fata'
         else 'altceva'
    end as grup
from student

select 5/2 from dual
select round(5/2) from dual







