select s.sid, s.nume, s.an, f.nume as facultate
    from Student s,Facultate f
    where s.fid=f.fid and an<3;

select p.nume,p.datan,f.nume,f.adr
    from Profesor p,Facultate f 
    where p.fid=f.fid;

select p.nume,p.datan,f.nume,f.adr
     from Profesor p
     JOIN Facultate f ON p.fid=f.fid;
--2

SELECT c.titlu, c.ora,c.sala,s.cods,s.nrlocuri
    from Curs c
    JOIN Sala s ON c.sala=s.cods
    where c.ora>12;

select c.titlu, c.ora,c.sala,s.cods,s.nrlocuri
    from Curs c,Sala s
    where c.sala=s.cods and c.ora>12;

--3

SELECT c.titlu,c.sala,s.cods,s.etaj
    from Curs c
    JOIN Sala s ON c.sala=s.cods
    where s.etaj=1;

select c.titlu,c.sala,s.cods,s.etaj
    from Curs c,Sala s
    where c.sala=s.cods and s.etaj=1;

--4

select trim(convert(to_char(SYSDATE, 'Day', 'NLS_DATE_LANGUAGE = Romanian'),'US7ASCII')) from dual

select c.titlu,c.zi,c.pid,p.pid,p.nume
    from Curs c
    JOIN Profesor p on c.pid=p.pid
    where c.zi=trim(convert(to_char(SYSDATE, 'Day', 'NLS_DATE_LANGUAGE = Romanian'),'US7ASCII'));

--5. Să se listeze studenții cu informații despre cursurile (titlu si sala) la care au nota mai mică sau egală cu 8.

select s.sid,c.sid,c.cid,c.nota,cu.cid,cu.titlu,cu.sala
    from Student s
    JOIN Contract c on s.sid=c.sid
    JOIN Curs cu on c.cid=cu.cid
    WHERE c.nota <= 8;

--6.  Să se listeze toți studenții care nu au nici un contract de studii semnat, ordonați după an și nume.

select s.sid,s.an,c.sid,c.nrc
    from Student s
    LEFT OUTER JOIN Contract c on s.sid=c.sid
    WHERE c.nrc is null
    ORDER BY s.an,s.nume;

select s.nume,ct.nrc
    from student s,contract ct
    where s.sid = ct.sid(+) and ct.nrc is null
    order by s.an, s.nume

--7 Să se listeze toți studenții care au cel puțin un contract de studii semnat, ordonați după numele de familie (obs.
-- în BD sunt în format “prenume nume_familie”).
--distinct ca sa nu apara de mai multe ori, pt cate contracte are fiecare student

select distinct s.sid, substr(s.nume,instr(s.nume,' ')+1) as NumeFamilie,c.sid
    FROM Student s
    INNER JOIN Contract c on s.sid=c.sid
    order by substr(s.nume,instr(s.nume,' ')+1);

--8 Să se listeze toți studenții care au cursuri în ziua de ’Luni’.

select s.nume,s.sid,ct.sid,ct.cid,cu.cid,cu.titlu,cu.zi
    FROM Student s
    JOIN Contract ct on s.sid=ct.sid
    JOIN Curs cu on ct.cid=cu.cid
    where cu.zi='Luni'
   
---9 Să se listeze toți studenții care au cursuri într-o sală
--cu mai puțin de 200 de locuri indiferent de zi, ordonați după anul
--nașterii și nume.

select s.nume,s.sid,ct.sid,ct.cid,cu.cid,cu.sala,sl.cods,sl.nrlocuri
    FROM Student s
    JOIN Contract ct on s.sid=ct.sid
    JOIN Curs cu on ct.cid=cu.cid
    JOIN Sala sl on cu.sala=sl.cods
    where sl.nrlocuri<200
    order by extract(year from s.datan),s.nume


 select s.nume,s.datan,cu.titlu,cu.sala,sl.nrlocuri
    from Student s,Contract c, Curs cu, sala sl
    where s.sid=c.sid and c.cid=cu.cid and cu.sala=sl.cods and sl.nrlocuri<200
    order by extract(year from s.datan),s.nume 