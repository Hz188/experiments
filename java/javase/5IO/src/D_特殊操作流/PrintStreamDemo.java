package D_特殊操作流;

import java.io.FileNotFoundException;
import java.io.PrintStream;

public class PrintStreamDemo {
    public static void main(String[] args) throws FileNotFoundException {
        PrintStream ps = new PrintStream("IO\\src\\D_特殊操作流\\ps.txt");

//        ps.write(97);

        ps.print(97);
        ps.println(97);


        ps.close();
    }
}
