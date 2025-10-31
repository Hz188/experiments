package A_File;

import java.io.File;
import java.io.IOException;

public class Demo2 {
    public static void main(String[] args) throws IOException {
        //1.
        File f1 = new File("G:\\JavaIO\\java.txt");
        System.out.println(f1.createNewFile());

        //2.
        File f2 = new File("G:\\JavaIO\\JavaSE");
        System.out.println(f2.mkdir());

        //3.
        File f3 = new File("G:\\JavaIO\\JavaWeb\\HTML");
        System.out.println(f3.mkdirs());

        //4.
        File f4 = new File("G:\\JavaIO\\javaee.txt");
//        System.out.println(f4.mkdir());//创建了一个 javaee.txt的目录 而不是txt文件
        System.out.println(f4.createNewFile());
    }
}
