package D_特殊操作流;

import java.io.PrintStream;

public class SystemOutDemo {
    public static void main(String[] args) {
//         public static final PrintStream out = null;
        PrintStream out = System.out;
        out.print("hello");
        out.print(100);
        out.print('a');

        out.println("hello");
        out.println(100);
        out.println('a');


    }
}
