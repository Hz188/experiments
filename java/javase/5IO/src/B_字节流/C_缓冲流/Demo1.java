package B_字节流.C_缓冲流;


import java.io.*;

public class Demo1 {
    public static void main(String[] args) throws IOException {
//        BufferedOutputStream bo = new BufferedOutputStream(new FileOutputStream("IO\\src\\B_字节流\\C_缓冲流\\bos.txt"));
//        bo.write("hello\r\n".getBytes());
//        bo.write("world\r\n".getBytes());
//        bo.close();

        BufferedInputStream bi = new BufferedInputStream(new FileInputStream("IO\\src\\B_字节流\\C_缓冲流\\bos.txt"));

        //1.一次一个字节
        int by;
        while ((by = bi.read())!=-1){
            System.out.println((char)by);
        }
        //2.一次一个字节数组
        byte[] bys = new byte[1024];
        int len;
        while ((len = bi.read(bys))!=-1){
            System.out.println(new String(bys,0 ,len));
        }


        bi.close();

    }
}
