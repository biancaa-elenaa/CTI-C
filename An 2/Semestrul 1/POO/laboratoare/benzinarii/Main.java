class Main{
    public static void main(String[] args){
	Benzinarie b = new Benzinarie();
	Masina m1 = new Masina("AA",5);
	Masina m2 = new Masina("BB",10);
	Masina m3 = new Masina("CC", 15);

	b.alimenteazaMasina(m1);
	b.alimenteazaMasina(m2);
	b.alimenteazaMasina(m3);

	System.out.println(b);

	b.alimenteazaBenzinarie(15);

	System.out.println(b);
    }
    
}


class Benzinarie{
    private int litrii=0;
    private Masina[] masini = new Masina[10];
    private int  nrMasini=0;

    public boolean alimenteazaMasina(Masina m)
    {
	int cnt = m.getCantitate();
	if(this.litrii >= cnt)
	    {
		this.litrii -= cnt;
		return true;
	    }
	else
	    {
		if(nrMasini < 10)
		    {
			masini[nrMasini++]=m;
			return true;
		    }
	    }
	return false;
    }

    public String toString(){
	String res = "Coada benzinariei:\n ";
	for(int i=0;i<nrMasini;i++)
	    {
		res += masini[i].toString();
	    }
	return res;
    }

    public void alimenteazaBenzinarie(int cantitate){
	this.litrii += cantitate;
	if(nrMasini > 0)
	    {
		for(int i=0;i<nrMasini;i++)
		    {
			if(this.litrii >= masini[i].getCantitate())
			    {
				this.litrii -= masini[i].getCantitate();
				for(int j=i;j<nrMasini-1;j++)
				    masini[j]=masini[j+1];
				i--;
				nrMasini--;
			    }

			
		    }
	    }
    }
   
    
}

class Masina{
    private String nrInmatriculare;

    private int cantitate;

    public Masina(String nrInmatriculare,int cantitate)
    {
	this.nrInmatriculare = nrInmatriculare;
	this.cantitate = cantitate;
    }

    public int getCantitate(){
	return this.cantitate;
    }

    public String toString(){
	return "Nr. inmatriculare: " + this.nrInmatriculare + "-Cantitatea necesare: " + this.cantitate + "\n ";
    }
    
}
