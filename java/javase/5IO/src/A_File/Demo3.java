package A_File;

import java.io.File;

public class Demo3 {
    public static void main(String[] args) {
        File f1 = new File("G:\\JavaIO\\java.txt");
        System.out.println(f1.delete());
    }
}
