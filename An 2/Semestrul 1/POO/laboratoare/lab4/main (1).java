class Main{
    public static void main(String[] args)
    {
        String sir1="Unsir"; // aceelasi lucru ca si new String("Unsir")
        String sir2="Un";
        String sir3="sir";

        String sir4 = "Un" + "sir";
        String sir5 = sir2.concat(sir3);
        String sir6 = sir2 + sir3;

    /*
        System.out.println(sir1 == sir4);
        System.out.println(sir1 == sir5);
        System.out.println(sir1 == sir6);
   
        System.out.println(sir6 == sir5);

        // NU == , EQUALS !!

    */
        System.out.println(sir1.equals(sir4));
        System.out.println(sir1.equals(sir5));
        System.out.println(sir1.equals(sir6));

        /*
        primitive -> obiect

        int -> Integer
        char -> Character
        ...
        */
       //doSmth1(5); // do Smth1(mew Integer(5)) => autoboxing
       //System.out.println(doSmth2(1,2));// => unboxing

       //Tablouri

       int[] array1 = new int[10]; // tot obiecte , creem un nou obiect pe heep cu 10 camerute, nu putem depasi sau redimensiona memoria
       System.out.println(array1[0]);

       String[] array2 = new String[10]; 
       System.out.println(array2[0]);
        //array de obiecte
        // array[i] = new Student();
        
        for(int i=0;i<10;i++){
            array1[i]=new int(5);
        }
    }

    public static void doSmth1(Integer x) {
    }

    public static Integer doSmth2(int x,int y) {
        return x*y;
    }
}