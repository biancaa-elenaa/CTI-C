/*
  2 clase: Studenti + Cursuri
  Student : nrmatricol, medie gen ,nume
 */

class Main{
    public static void mainr(String[] args){

    }
}

class Student{
    private String nume;
    private int nrMatricol;
    private double medieGenerala;

    public Student(String nume, int nrMatricol, double medieGenerala){
	this.nume = nume;
	this.nrMatricol = nrMatricol;
	this.medieGenerala = medieGenerala;
    }

    public boolean equals(Object o)
    {
	if(o instanceof Student)
	    return ((Student)o).getNrMatricol() == this.nrMatricol;

	return false;
    }

    public int getNrMatricol(){
	return this.nrMatricol;
    }

    public double getMedie()
    {
	return this.medieGenerala;
    }

    public String toString(){
	return "Nume: " + this.nume + ", Nr Matricol:  " + this.nrMatricol + ", Medie: " + this.medieGenerala + " ";
    }


}

class Cursuri{

    private String nume;
    private Student[] studenti = new Studenti[10];
    private int nrStudenti;

    public boolean 

}
