package B_字节流.B_FileInputDemo;

import java.io.FileInputStream;
import java.io.IOException;

public class Demo1 {
    public static void main(String[] args) throws IOException {
        FileInputStream fi = new FileInputStream("IO\\src\\B_字节流\\B_FileInputDemo\\fos.txt");
//        int by = fi.read();
//        System.out.println((char)by);
//
//        by = fi.read();
//        System.out.println((char)by);

        //如果到达文件末尾， -1
        //loop
        int by;
        while ((by = fi.read()) != -1){
            System.out.print((char)by);
        }

        fi.close();
    }
}
