package C_字符流;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class IOExceptionDemo1 {
    public static void main(String[] args) {

    }

    //try...catch...finally
    public static void method1() {
        FileReader fr = null;
        FileWriter fw = null;
        try {
            fr = new FileReader("IO\\src\\D_IO异常处理\\fr.txt");
            fw = new FileWriter("IO\\src\\D_IO异常处理\\fw.txt");


        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            try {
                if (fr != null) {
                    fr.close();
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
            try {
                if (fw != null) {
                    fw.close();
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    //jdk7 improve
    public static void method2() {
        try (
                FileReader fr = new FileReader("IO\\src\\D_IO异常处理\\fr.txt");
                FileWriter fw = new FileWriter("IO\\src\\D_IO异常处理\\fw.txt");) {
            char[] chs = new char[1024];
            int len;
            while ((len = fr.read(chs)) != -1) {
                fw.write(chs);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    //jdk9 improve
    public static void method3() throws IOException{
        FileReader fr = new FileReader("IO\\src\\D_IO异常处理\\fr.txt");
        FileWriter fw = new FileWriter("IO\\src\\D_IO异常处理\\fw.txt");
        try (fr;fw){
            char[] chs = new char[1024];
            int len;
            while ((len = fr.read(chs)) != -1) {
                fw.write(chs);
            }
        } catch (IOException e){
            e.printStackTrace();
        }
    }
}
