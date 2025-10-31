package D_特殊操作流;

import java.io.*;

public class PrintWriterDemo {
    public static void main(String[] args) throws IOException {
//        PrintWriter pw = new PrintWriter("IO\\src\\D_特殊操作流\\pw.txt");
////        pw.write("hello\r\n");
////        pw.flush();
////        pw.write("world\r\n");
////        pw.flush();
//
//        pw.println("hello");
//        pw.println("world");
//        pw.flush();


        PrintWriter pw = new PrintWriter(new FileWriter("IO\\src\\D_特殊操作流\\pw.txt"),true);
//        pw.write("hello\r\n");
//        pw.flush();
//        pw.write("world\r\n");
//        pw.flush();

        pw.println("hello");
        pw.println("world");

    }
}
