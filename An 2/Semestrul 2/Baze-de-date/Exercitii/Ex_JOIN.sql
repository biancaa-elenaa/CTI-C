--1 nume profesori,nume cursuri pe care le predau in sali cu minim 
--50 locuri si maxim 250 locuri
--inregistrarea 2: Ciprian Porumbescu  Sisteme web
 --si 5: Cristina Papura  Logica fuzzy

select p.nume,c.titlu,s.nrlocuri
    from profesor p
    join Curs c on p.pid=c.pid
    join sala s on c.sala=s.cods
    where s.nrlocuri>=50 and s.nrlocuri<=250

---2. sid + titlu curs care sunt in sali de la etajul 2 si 3
--inregistrarea 3:SAC002	Psihologia copilului
-- inregistrarea 5: SAC004	Logica digitala

select s.sid,cu.titlu,sl.etaj
    from Student s
    join Contract c on s.sid=c.sid
    join Curs cu on c.cid=cu.cid
    join Sala sl on cu.sala=sl.cods
    where sl.etaj=2 or sl.etaj=3
    order by s.sid

--3. pid profesori + telefon facultatea la care predau 
--pt profesorii ar caror nume nu incep cu 'C' 
--inreg 2:PSC001	0256-404011
--inreg 4:PET001	0256-403381

select p.pid,f.tel,p.nume
    from Profesor p
    join Facultate f on p.fid=f.fid
    where p.nume not like 'C%'

--4. sid + nume studenti care au curs cu profesorul cu PID='PAC001'
--INREG 1: SAC006	Florian Belu
--INREG 4: SAC004	Nadia Olaru

select s.sid, s.nume
    from Student s
    join contract c on s.sid=c.sid
    join curs cu on c.cid=cu.cid 
    join profesor p on cu.pid=p.pid
    where p.pid='PAC001'

--5 sid + nume discipline pentru care NU se sustin cursuri Luni si Vineri
--SME010	Programare	ing2
--SMP005	Relatii publice ing3
select s.sid,cu.titlu,cu.zi
    FROM student s
    JOIN contract c on s.sid=c.sid
    JOIN curs cu on c.cid=cu.cid
    where cu.zi<>'Luni' and cu.zi not like 'Vineri'

--6.nume student si nume facultate la care sunt inscrisi 
--pt studentii care au bursa strict maai mare de 500
--Rodica Tudoran	Electrotehnica
--Grigore Toma	Mecanica

select s.nume,f.nume
    from Student s 
    join Facultate f on s.fid=f.fid
    where s.bursa > 500

