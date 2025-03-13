class Complex{
    private double real; //atribute
    private double imaginar;
    private static int nrAfisari = 0;

    public Complex(double real,double imaginar){
	this.real=real;
	this.imaginar=imaginar;
    }

    public double getModul(){
	return Math.sqrt(real*real + imaginar*imaginar);
    }

    public void afisare(){
	System.out.println(real +  "+i*" + imaginar );
	nrAfisari++;
    }

    public static int getNrAfisari(){
	return nrAfisari;
    }

    public Complex aduna(Complex c){
	Complex rezultat = new Complex(0,0);
	rezultat.real= c.real + this.real;
	rezultat.imaginar = c.imaginar + this.imaginar;
	return rezultat;
	
    }
}

class ClientComplex{
    public static void main(String[] args){
	Complex c1 = new Complex(2,2);
	System.out.println("Modulul este:" + c1.getModul());
	c1.afisare();
	Complex c2 = new Complex(1,2);
	//c2.afisare();
	Complex c3 = c1.aduna(c2);
	c3.afisare();
	System.out.println(Complex.getNrAfisari());
	
    }
}
