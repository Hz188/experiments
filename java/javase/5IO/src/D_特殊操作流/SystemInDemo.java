package D_特殊操作流;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Scanner;

public class SystemInDemo {
    public static void main(String[] args) throws IOException {
        //public static final InputStream in = null;
        InputStream is = System.in;
//读取中文不方便
//        int by ;
//        while ((by=is.read())!=-1){
//            System.out.println((char)by);
//        }

//        InputStreamReader isr = new InputStreamReader(is);
//        BufferedReader br = new BufferedReader(isr);
        //改进
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Please input a string:");
        String s = br.readLine();
        System.out.println("String you input is " + s);

        System.out.println("Please input an integer:");
        int x = Integer.parseInt(br.readLine());
        System.out.println("Integer you input is " + x);

//        上述过程过于繁琐 Java就提供了包装类 Scanner
        Scanner sc = new Scanner(System.in);
        //sc.nextXXX()
    }
}
