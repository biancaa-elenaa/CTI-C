class Main{
    public static void main(String[] args){
	Jucator j1 = new Jucator("Hagi",15);
	Jucator j2 = new Jucator("Messi",10);
	Jucator j3 = new Jucator("Ronaldo",24);
       	Jucator j4 = new Jucator("Mbape",13);
	Jucator j5 = new Jucator("Manea",11);
	Jucator j6 = new Jucator("Ronaldinio",17);

	Echipa echipa = new Echipa();
	echipa.adaugaJucatori(j1,j4);
	echipa.adaugaJucatori(j2,j5);
       	echipa.adaugaJucatori(j3,j6);
	
	System.out.println(echipa);

	echipa.efectueazaSchimbare(j1,j5);
	
	System.out.println("\n ----- \n");
	System.out.println(echipa);

	
    }
}

class Jucator{
    private String nume;
    private int numar;

    public Jucator(String nume,int numar){
	this.nume=nume;
	this.numar=numar;
    }

    public boolean equals(Object o)
    {
	if(o instanceof Jucator)
	    return ((Jucator)o).nume.equals(this.nume) && ((Jucator)o).getNumar() == this.numar;
	return false;
    }

    public String getNume()
    {
	return this.nume;
    }

    public int getNumar(){
	return this.numar;
    }

    public String toString(){
	return "<" + this.nume + "><" + this.numar + ">\n";
    }

		
}

class Echipa{
    private Jucator[] titulari=new Jucator[10];
    private Jucator[] rezerve = new Jucator[10];
    private int nrJucatori = 0;

    public void adaugaJucatori(Jucator j1,Jucator j2)
    {
	this.titulari[nrJucatori]=j1;
	this.rezerve[nrJucatori] = j2;
	this.nrJucatori ++;
    }
    
    public boolean efectueazaSchimbare(Jucator titular,Jucator rezerva)
    {
	int k=0;
	int t=0,r=0;
	for(int i=0;i<nrJucatori;i++)
	    {
		if(titulari[i].equals(titular) == true)
		    {
			k++;
			t=i;
		    }
		if(rezerve[i].equals(rezerva) == true )
		    {
			k++;
			r=i;
		    }
	    }
	if(k != 2)
	    return false;
	else{
	    Jucator tmp = titulari[t];
	    titulari[t]=rezerve[r];
	    rezerve[r]=tmp;
	    return true;
	}		
    }

    public String toString(){
	String rez = "Titulari: \n";
	for(int i=0;i<nrJucatori;i++)
	    {
		rez += titulari[i].toString();
	    }
	rez += "Rezerve: \n";
	for(int i=0;i<nrJucatori;i++)
	    {
		rez += rezerve[i].toString();
	    }
	return rez;
	
    }
    
}
