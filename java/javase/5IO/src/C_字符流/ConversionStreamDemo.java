package C_字符流;

import java.io.*;

/* Reader && Writer
    |           |-> OutputStreamWriter
    |                   |-> FileWriter
    |-> InputStreamReader
           |-> FileReader
    二者是 字符流和字节流之间的桥梁
    因为名字过长，有一个封装的子类
    FileReader
    FileWriter 基本方法就看API 文档了，不再演示
    同样也有缓冲流 基本方法就看API 文档了，不再演示
    BufferedReader
    BufferedWriter
*/
public class ConversionStreamDemo {
    public static void main(String[] args) throws IOException {
//        public OutputStreamWriter(OutputStream out)
//        public OutputStreamWriter(OutputStream out, String charsetName)
        FileOutputStream fo = new FileOutputStream("IO\\src\\C_字符流\\osw.txt");
//        OutputStreamWriter osw = new OutputStreamWriter(fo); // new FileOutputStream 两步可以合并
//        OutputStreamWriter osw = new OutputStreamWriter(fo,"UTF-8");
        OutputStreamWriter osw = new OutputStreamWriter(fo,"GBK");

        osw.write("中国");
        osw.close();

//        InputStreamReader isr = new InputStreamReader(new FileInputStream("IO\\src\\C_字符流\\osw.txt"));
        InputStreamReader isr = new InputStreamReader(new FileInputStream("IO\\src\\C_字符流\\osw.txt"),"GBK");

        int ch;
        while ((ch = isr.read())!=-1){
            System.out.println((char)ch);
        }
        isr.close();
    }
}
