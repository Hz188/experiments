package A_File;

import java.io.File;
import java.util.Collections;

public class Demo4 {
    public static void main(String[] args) {
        File f1 = new File("G:\\JavaIO\\java.txt");
        System.out.println(f1.isFile());

        //2.
        File f2 = new File("G:\\JavaIO\\JavaSE");
        System.out.println(f2.isDirectory());

        //3.
        File f3 = new File("G:\\JavaIO\\JavaWeb\\HTML");
        System.out.println(f3.exists());
        System.out.println(f3.getName());//文件名
        System.out.println(f3.getAbsolutePath());//绝对路径
        System.out.println(f3.getPath()); // 封装的路径

        //4.
        File f4 = new File("G:\\JavaIO");
        String[] list = f4.list();
        for (String s : list) {
            System.out.println(s);
        }
        File[] files = f4.listFiles();
        for (File file : files) {
            System.out.println(file);
        }
    }
}
