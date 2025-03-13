class Main{
    public static void main(String[] args)
    {
	Tir t1 = new Tir();

	t1.adaugaRemorca(4,"AAAA");
	t1.adaugaRemorca(5,"BBBB");

	Remorca r1 = new Remorca("CCCC");

	t1.adaugaRemorca(r1);

	System.out.println(t1);

	Tir t2 = new Tir();
	t2.adaugaRemorca(15,"DDDD");

	System.out.println(t2);

	System.out.println("Sunt cele doua tiruri egale?");
	System.out.println(t1.equals(t2));

	System.out.print("Stergem remorca: ");
	System.out.println(t1.stergeRemorca("BBBB"));

	System.out.println(t1);
	System.out.println(t2);

	System.out.println("Sunt cele doua tiruri egale?");
	System.out.println(t1.equals(t2));

	
	
	
    }
}

class Tir{
    private Remorca[] remorci=new Remorca[5];
    private int nrRemorci = 0;

    public boolean adaugaRemorca(int nrCutii,String nrInmatriculare)
    {
	if(nrRemorci < 5)
	    {
		remorci[nrRemorci++] = new Remorca(nrCutii,nrInmatriculare);
		return true;
	    }
	return false;
    }

    public boolean adaugaRemorca(Remorca r)
    {
	if(nrRemorci < 5)
	    {
		remorci[nrRemorci++] = r;
		return true;
	    }
	return false;
    }

    public Remorca stergeRemorca(String nrInmatriculare){
	for(int i=0;i<nrRemorci;i++)
	    {
		if(remorci[i].getNrInmatriculare().equals(nrInmatriculare))
		    {
			Remorca tmp = remorci[i];
			
			for(int j=i;j<nrRemorci-1;j++)
			    {
				remorci[j] = remorci[j+1];
			    }
			nrRemorci--;
			remorci[nrRemorci]=null;
			return tmp;
		    }
	    }
	return null;
    }

    public int getCantitateTotala()
    {
	int cnt=0;
	for(int i=0;i<nrRemorci;i++)
	    {
		cnt += remorci[i].getNrCutii();
	    }
	return cnt;
    }

    public boolean equals(Object o)
    {
	if(o instanceof Tir)
	    return ((Tir)o).getCantitateTotala() == this.getCantitateTotala();
	return false;
    }
    public String toString()
    {
	String rez = "T ";
	for(int i=0;i<nrRemorci;i++)
	    rez += "-> " + remorci[i].toString();
	return rez;
    }
    
}

class Remorca{
    private int nrCutii;
    private String nrInmatriculare;
    private static int contorCutii = 9; 

    public Remorca(int nrCutii,String nrInmatriculare){
	this.nrCutii = nrCutii;
	this.nrInmatriculare = nrInmatriculare;
	contorCutii = nrCutii;
	
    }

    public Remorca(String nrInmatriculare)
    {
	this.nrInmatriculare=nrInmatriculare;
	this.nrCutii = contorCutii + 1;
	contorCutii = this.nrCutii;
	
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
	return "R(" + nrInmatriculare + ", " + nrCutii + ")";
    }
}
