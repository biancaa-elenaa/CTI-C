class Student{
    public String nume;
    private int nrMatricol;
    private double medie;

    private static int nrStudenti = 0;

    public Student(String nume, int nrMatricol, double medie) // constructor, nu are return type si se executa doar o data cand e creata
    {
	this.nume = nume;
	this.medie = medie;
	this.nrMatricol = nrMatricol;
	nrStudenti++;
    }

    public static int getStudenti()
    {
	return nrStudenti;
    }

    public static void setStudent()
    {
	nrStudenti = 4;
    }

    public double  getMedie(){
	return medie; // this.medie de catre compilator
    }

    public void setMedie(double medie){
	this.medie=medie;
    }

    public int getnrMatricol()
    {
	return nrMatricol;
    }
    

    public void invata() //metode
    {
	System.out.println("Learning");
    }

    public void afisare()
    {
	System.out.println(nume + " " + nrMatricol + " " + medie);
	//System.out.println(nume);
	//System.out.println(nrMatricol);
	//System.out.println(medie);
	
    }
}

class MyProgram{
    public static void main(String[] argv)
    {
	Student stud1= new Student("Jhon",12300,9.5);
	System.out.println(stud1.getMedie());
	stud1.setMedie(8.0);
       	System.out.println(stud1.getMedie());
	System.out.println(stud1.getnrMatricol());
	//stud1.invata();
	System.out.println(Student.getStudenti());
	

	Student stud2 = new Student("Marry",545,10);
	System.out.println(stud2.getMedie());
	System.out.println(stud2.getnrMatricol());
	System.out.println(Student.getStudenti());
	Student.setStudent();
	System.out.println(Student.getStudenti());

	stud1.afisare(); // renuntam la toate apelurile din main cu ajutorul functiei
    }
}
