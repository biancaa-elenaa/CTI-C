class Main{
    public static void main(String[] args){
	Figura f1= new Figura(4.0);
	Figura f2 = new Figura(5.0);
	Figura f3 = new Figura(3.0);
	

	Desen d1 = new Desen("CASA");

	System.out.println(f1);
	d1.adaugaFigura(f1);
	d1.adaugaFigura(f2);
       	d1.adaugaFigura(f3);
	System.out.println(d1.adaugaFigura(f1));
	

	double medie = d1.medieArie();
	
	System.out.println(d1);
	System.out.println(medie);

	
    }
}

class Figura{
    private double  arie;

    public Figura(double arie){
	this.arie=arie;
    }

    public  boolean equals(Object o)
    {
	if(o instanceof Figura){
	    return ((Figura)o).getArie() == this.arie;
	}
	return false;
    }

    public double getArie(){
	return this.arie;
    }

    public String toString(){
	return "Figura - Arie : " + this.arie+ " ";
    }
}

class Desen{
    private String titlu;
    private Figura[] figuri=new Figura[1024];
    private int nrFiguri=0;

    public Desen(String titlu)
    {
	this.titlu=titlu;
    }

    public boolean adaugaFigura(Figura fig)
    {
	if(nrFiguri < 1024){
	    for(int i=0;i<nrFiguri;i++)
		if(figuri[i].equals(fig))
		    return false;
	    figuri[nrFiguri++]=fig;
	    return true;
	}
	return false;
    }

    public String toString(){
	String res = "Titlul desenului: " + titlu + ": ";
	for(int i=0;i<nrFiguri;i++)
	    {
		res = res + figuri[i].toString() + ";";
	    }
	return res;
    }

    public double medieArie(){
	double suma = 0;
	if(nrFiguri == 0)
	    return suma;
	for(int i=0;i<nrFiguri;i++)
	    {
		suma += figuri[i].getArie();
	    }
	return suma/nrFiguri;
    }

}
