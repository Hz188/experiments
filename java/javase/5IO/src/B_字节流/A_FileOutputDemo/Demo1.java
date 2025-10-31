package B_字节流.A_FileOutputDemo;

import java.io.FileOutputStream;
import java.io.IOException;
/*
   写入数据
 */
public class Demo1 {
    public static void main(String[] args) throws IOException {
        FileOutputStream fo = new FileOutputStream("IO\\src\\B_字节流\\A_FileOutputDemo\\fos.txt");
//        FileOutputStream fo = new FileOutputStream(new File("IO\\src\\B_字节流\\A_FileOutputDemo\\fos.txt"));
        //1.
//        fo.write(97);
//        fo.write(57);
//        fo.write(55);

        //2.
        byte[] b = {97, 57, 55};
        byte[] bytes = "abcde".getBytes();
//        fo.write(bytes);

        //3.
        fo.write(b,0,b.length);
        fo.close();
    }
}
