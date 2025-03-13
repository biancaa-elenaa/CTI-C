class Main{
    public static void main(String[] args){
	Angajat a1 = new Angajat("Ana",1300);
	Angajat a2 = new Angajat("Mara",2200);
	Angajat a3 = new Angajat("Ionut",3000);

	Firma f = new Firma("AAAA",8000);

	f.adaugaAngajat(a1);
	f.adaugaAngajat(a2);
	f.adaugaAngajat(a3);
	System.out.println(f.adaugaAngajat(a1));

	System.out.println(f);
        f.platesteSalarii();
	

    }
}

class Angajat{
    private String nume;
    private int salariu;

    public Angajat(String nume,int salariu)
    {
	this.nume= nume;
	this.salariu = salariu;
    }

    public boolean equals(Object o)
    {
	if(o instanceof Angajat)
	    {
		Angajat a = (Angajat)o;
		return this.salariu == a.salariu && this.nume.equals(nume);
	    }
	return false;
    }

    public String toString(){
	return "Angajat: <" + this.nume + "> - <" + this.salariu + ">\n";
    }

    public int getSalariu()
    {
	return this.salariu;
    }
    
}

class Firma{
    private String nume;
    private int buget;
    private Angajat[] angajati = new Angajat[30];
    private int nrAngajati=0;

    public Firma(String nume,int buget){
	this.nume=nume;
	this.buget=buget;
    }

    public boolean adaugaAngajat(Angajat a){
	if(nrAngajati < 30)
	    {
		for(int i=0;i<nrAngajati;i++)
		    if(angajati[i].equals(a))
			return false;
		angajati[nrAngajati++]=a;
		return true;
		
	    }
	return false;
    }

    public String toString(){
	String res = "Nume firma: " + this.nume + " ";
	for(int i=0;i<nrAngajati;i++)
	    res += angajati[i].toString();
	return res;
    }

    public void platesteSalarii(){
	for(int i=0;i<nrAngajati;i++)
	    {
		this.buget -= angajati[i].getSalariu();
		
	    }
	System.out.println("Bugetul ramas dupa plata salariilor este: " + this.buget);
    }

}
