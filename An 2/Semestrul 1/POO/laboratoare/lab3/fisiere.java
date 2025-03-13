public class Main{
    public static void main(String[] argv)
    {
	Fisier f1=new Fisier("file1","AGFGFeafr");
	Fisier f2=new Fisier("file2","32424");
	f1.concateneaza(f2);
    }
}

class Fisier{
    private String nume;
    private String continut;
    private int id=0;

    public static int idCount=0;

    private Fisier fisierAnterior;

    public Fisier(String nume,String continut)
    {
	this.nume=nume;
	this.continut=continut;
	this.id=idCount++;
	this.fisierAnterior=null;	
    }

    public void salveazaVersiune()
    {
	String numeNou = this.nume + "bak"; 
	Fisier fisierNou=new Fisier (numeNou,this.continut);
	fisierNou.fisierAnterior = this.fisierAnterior;
	this.fisierAnterior=fisierNou;
    }

    public void concateneaza(Fisier altFisier){
	this.salveazaVersiune();
	this.continut = this.continut + altFisier.continut;
    }
}
