package B_字节流.A_FileOutputDemo;

import java.io.FileOutputStream;
import java.io.IOException;

//1、实现换行
//2、追加写入
public class Demo2 {
    public static void main(String[] args) throws IOException {
//     1.换行
//        FileOutputStream fo = new FileOutputStream("IO/src/B_字节流/A_FileOutputDemo/fos.txt");
//        for (int i = 0; i < 10; i++) {
//            fo.write("hello".getBytes());
//            fo.write("\r\n".getBytes());
//        }
//      2.追加写入
        FileOutputStream fo = new FileOutputStream("IO\\src\\B_字节流\\A_FileOutputDemo\\fos.txt",true);
        for (int i = 0; i < 10; i++) {
            fo.write("hello".getBytes());
            fo.write("\r\n".getBytes());
        }
        fo.close();
    }
}
