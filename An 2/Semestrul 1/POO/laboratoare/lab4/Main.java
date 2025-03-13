class Main{
    public static void main(String[] args)
    {
        /*
        Remorca r1 = new Remorca("ab45jfw"); // 10 
        Remorca r2 = new Remorca("ab4jfw"); // 11
        Remorca r3 = new Remorca(2,"ab47jfw");
        Remorca r4 = new Remorca("ab48jfw");

        System.out.println(r2.getNrCutii());
        System.out.println(r3.getNrCutii());
        System.out.println(r4.getNrCutii());
        */

       Tir t1=new Tir();
       t1.adaugaRemorca(5,"a");
       t1.adaugaRemorca(3,"b");
       System.out.println(t1.getNrRemorci());





    }
}

class Tir{
    private Remorca[] remorci =new Remorca[5];
    private static int nrRemorci=0;

    public boolean adaugaRemorca(int nrCutii,String nrInmatriculare)
    {
        if(nrRemorci < 5)
        {
            remorci[nrRemorci++]=new Remorca(nrCutii,nrInmatriculare);
            return true;
        }
        else
            return false;
    }

    public boolean adaugaRemorca(Remorca remorca)
    {
         if(nrRemorci < 5)
        {
            remorci[nrRemorci++]=remorca;
            return true;
        }
        else
            return false;
    }

    public Remorca stergeRemorca(String nrInmatriculare){
        Remorca 
    }

    public int getNrRemorci(){
        return nrRemorci;
    }
    

}

class Remorca{
    private int nrCutii;
    private String nrInmatriculare;

    private static int nrCutiiAnt = 9;

    public Remorca(int nrCutii,String nrInmatriculare)
    {
        this.nrCutii = nrCutii;
        this.nrInmatriculare = nrInmatriculare;
        nrCutiiAnt = this.nrCutii;
    }

    public Remorca(String nrInmatriculare)
    {
        this.nrCutii = nrCutiiAnt + 1;
        this.nrInmatriculare = nrInmatriculare;
        nrCutiiAnt = this.nrCutii;
    }

    public int getNrCutii()
    {
        return nrCutii;
    }
}