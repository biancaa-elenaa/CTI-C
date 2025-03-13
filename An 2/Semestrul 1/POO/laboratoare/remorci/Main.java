class Main{
    public static void main(String[] args){
    Remorca r1=new Remorca(3,"AA");
    Remorca r2=new Remorca("BB");

    System.out.println(r1);
    System.out.println(r2);

    Tir t = new Tir();

    t.adaugaRemorca(r1);
    t.adaugaRemorca(r2);
    t.adaugaRemorca(5,"CC");

    // System.out.println(t);

     t.stergeRemorca("BB");

    System.out.println(t);

    Tir t1 = new Tir();
    t1.adaugaRemorca(8, "DD");

    System.out.println(t1);

    System.out.println(t.equals(t1));
    
        
    }
}


class Tir{
    private Remorca[] remorci = new Remorca[5];
    private  int nrRemorci = 0;
    public boolean adaugaRemorca(int nrCutii,String nrInmatriculare)
    {
	if(nrRemorci < 5)
	    {
		remorci[nrRemorci] = new Remorca(nrCutii,nrInmatriculare);
		nrRemorci++;
		return true;
	    }
	return false;
    }

    public boolean adaugaRemorca(Remorca remorca)
    {
	if(nrRemorci < 5)
	    {
		remorci[nrRemorci] = remorca;
		nrRemorci++;
		return true;
	    }
	return false;
    }

    public Remorca stergeRemorca(String nrInmatriculare)
    {
	for(int i=0;i<nrRemorci;i++)
	    {
		if (remorci[i].getNrInmatriculare().equals(nrInmatriculare))
		    {
			for(int j=i;j<nrRemorci-1;j++)
			    remorci[j]=remorci[j+1];
			nrRemorci --;
			remorci[nrRemorci]=null;
			return this.remorci[i];
		    }
	    }
	return null;
    }

    public int getCantitate(){
	int cantitate = 0;
	for(int i=0;i<nrRemorci;i++)
	    {
		cantitate = cantitate + remorci[i].getNrCutii();
	    }
	return cantitate;
    }

    public boolean equals(Object o)
    {
	if(o instanceof Tir)
	    return ( ((Tir)o).getCantitate() == this.getCantitate() );
	else
	    return false;  
    }

    public String toString()
    {
	String res = "T  ";
	for(int i=0;i<nrRemorci;i++)
	    {
		res += "-> " + remorci[i].toString();
	    }
	return res;
    }
}

class Remorca{
    private int nrCutii;
    private String nrInmatriculare;

    private static int nrCutiiAnt = 9;

    public Remorca (int nrCutii,String nrInmatriculare)
    {
	this.nrCutii=nrCutii;
	this.nrInmatriculare = nrInmatriculare;
	nrCutiiAnt = this.nrCutii;
    }

    public Remorca( String nrInmatriculare)
    {
	this.nrCutii = 1 + nrCutiiAnt;
	this.nrInmatriculare = nrInmatriculare;
	nrCutiiAnt = this.nrCutii;
	
    }

    public boolean equals(Object o) 
    {
	if(o instanceof Remorca)
	    return (((Remorca)o).nrInmatriculare == this.nrInmatriculare);
	return false;
    }


    public String getNrInmatriculare()
    {
	return this.nrInmatriculare;
    }

    public int getNrCutii()
    {
	return this.nrCutii;
    }

    public String toString()
    {
	return "R(" + nrCutii + ", " + nrInmatriculare+ ")";
    }
}
