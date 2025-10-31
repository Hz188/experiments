package B_字节流.A_FileOutputDemo;

import java.io.FileOutputStream;
import java.io.IOException;

/*
* 异常处理
* finally 释放资源
* */
public class Demo3 {
    public static void main(String[] args) {
        FileOutputStream fo = null;
        try {
            fo = new FileOutputStream("IO\\src\\B_字节流\\A_FileOutputDemo\\fos.txt");
            fo.write("hello".getBytes());
            fo.close();
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            try {
                fo.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}
