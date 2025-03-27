CREATE TABLE masina(
    NrInregistrare NUMBER(5) NOT NULL, 
    Proprietar CHAR(6),
    NrInmatriculare CHAR(9),
    Culoare VARCHAR2(10) not null,
    Vportbagaj NUMBER(5,2) NOT NULL,
    NrKm number(9,2) default 0 not null,
    AnFabricatie number(4) not null,
    CONSTRAINT NrInreg_pk PRIMARY KEY(NrInregistrare),
    CONSTRAINT Proprietar_pk FOREIGN KEY(Proprietar) references Profesor(pid),
    CONSTRAINT vport_pk check (Vportbagaj >= 0 AND Vportbagaj <= 300),
    constraint km_ck check (NrKm >= 0)
);

alter table masina
    add constraint MS_ANF_CK
    check(AnFabricatie >= 1980 AND AnFabricatie <= 2024);

insert into masina values (19082,'PMEC01','TM01ABC','rosu',100,12000,2021);
insert into masina values (23062,'PET002','TM02ABD','rosu',100,19000,2021);
insert into masina values (33912,'PAC001','TM40PPT','rosu',100,8000,2023);


update masina set NrKm=34000 WHERE NrInregistrare=33912;

update masina set NrKm=NrKm+1250;

DELETE from masina WHERE NrKm > 20000;

DROP TABLE masina;
