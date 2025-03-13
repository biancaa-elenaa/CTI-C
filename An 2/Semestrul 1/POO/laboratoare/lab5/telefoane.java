import java.io.*;
import java.util.Scanner;
import java.util.Random;

class Main{
    public static void main(String[] args){
        /*
        Telefon t1 = new Telefon("A");
        Telefon t2 = new Telefon("B");
        Telefon t3 = new Telefon("C");
        Telefon t4 = new Telefon("D");

        t2.apeleaza(t1);
        t3.apeleaza(t1);
        t4.apeleaza(t1);

        System.out.println(t1);
        System.out.println(t2);
        */
       /*
       int nrTelefoane;
        try {
                BufferedReader in_stream_char =new BufferedReader(new InputStreamReader(System.in));
                PrintStream out_stream = new PrintStream(new FileOutputStream("out.txt"));

                System.out.print("Dati numarul de intregi:");
                nrTelefoane = Integer.parseInt(in_stream_char.readLine());

                Telefon[] telefoane = new Telefon[nrTelefoane];
                for(int i=0;i<nrTelefoane;i++)
                {
                  

                }

            
            } catch(IOException e) {
                System.out.println("Eroare la operatiile de intrare-iesire!");
                System.exit(1);
            }
            */
    }
}

class Telefon{
    private String numeProprietar;

    private String[] apelanti = new String[100];
    private int nrApelanti = 0;

    public Telefon(String numeProprietar){
        this.numeProprietar = numeProprietar;
    }

    public boolean apeleaza(Telefon t){
        if(nrApelanti < 100){
            t.apelanti[t.nrApelanti++]=this.numeProprietar;
            return true;
        }
        return false;
    }

    public Integer numarDeApeluri(String nume){
        int nr = 0;
        for(int i=0;i<nrApelanti;i++)
        {
            if( apelanti[i].equals(nume) )
                nr++;
        }
        return nr;
    }

    public String toString(){
        String res = "Proprietar: " + this.numeProprietar + " Apelanti: ";
        for(int i=0;i<nrApelanti;i++)
        {
            res = res + apelanti[i] + ", ";
        }
    return res;
    }



}