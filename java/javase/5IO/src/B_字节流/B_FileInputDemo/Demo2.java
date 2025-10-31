package B_字节流.B_FileInputDemo;

import java.io.FileInputStream;
import java.io.IOException;

public class Demo2 {
    public static void main(String[] args) throws IOException {
        FileInputStream fi = new FileInputStream("IO\\src\\B_字节流\\B_FileInputDemo\\fos.txt");

        /*
            hello\r\n
            world\r\n
        */
        //1. hello
        //2. \r\nwor
        //3. ld\r\nr  只读四个了 上面第二次读取的r被保留了
//        byte[] bys = new byte[5];
//        int len = fi.read(bys);
//        System.out.println("len = " + len);
//        System.out.println(new String(bys));
//
//
//        len = fi.read(bys);
//        System.out.println("len = " + len);
//        System.out.println(new String(bys));
//
//        len = fi.read(bys);
//        System.out.println(len);
//        System.out.println(new String(bys));

        byte[] bys = new byte[1024];
        int len;
        while ((len = fi.read(bys)) != -1) {
            System.out.println(len);
            System.out.println(new String(bys, 0, len));
        }
        fi.close();
    }
}
