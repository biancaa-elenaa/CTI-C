class Main{
    public static void main(String[] args)
    {
	Portofel p = new Portofel("ION");
	p.adaugaCard("1234",600);
	p.adaugaCard("5678",500);
	p.adaugaCard("1234",120);

	System.out.println(p);
	System.out.println(p.calculeazaSold());
    }
}

class Card{
    private String numar;
    private double  sold;

    public Card(String numar,double sold)
    {
	this.numar = numar;
	this.sold = sold;
	
    }

    public String toString(){
	return numar + " - " + sold + "\n";
    }

    public double  getSold()
    {
	return this.sold;
    }

    public String getNumar(){
	return this.numar;
    }
			   
    
}

class Portofel{
    private String numeProprietar;
    private Card[] carduri = new Card[6];
    private int nrCarduri = 0;

    public Portofel(String numeProprietar){
	this.numeProprietar = numeProprietar;
    }

    public boolean adaugaCard(String numar, double sold){
	if(nrCarduri < 6)
	    {
		for(int i=0;i<nrCarduri;i++)
		    {
			if(carduri[i].getNumar().equals(numar))
			    return false;
		    }
		carduri[nrCarduri++] = new Card(numar,sold);
	    }
	return false;
    }

    public String toString(){
	String rez = "Portofel " + this.numeProprietar + "\n";
	for(int i=0;i<nrCarduri;i++)
	    {
		rez += carduri[i].toString();
	    }
	return rez;
    }

    public double calculeazaSold(){
	double sold = 0;
	for(int i=0;i<nrCarduri;i++)
	    sold += carduri[i].getSold();
	return sold;
    }
}
