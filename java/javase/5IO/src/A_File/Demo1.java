package A_File;

import java.io.File;

public class Demo1 {
    public static void main(String[] args) {
        File f1 = new File("G:\\JavaIO\\java.txt");
        System.out.println(f1);

        File f2 = new File("G:\\JavaIO","java.txt");
        System.out.println(f2);

        File f3 = new File("G:\\JavaIO");
        File f4 = new File(f3,"java.txt");
        System.out.println(f4);
    }
}
