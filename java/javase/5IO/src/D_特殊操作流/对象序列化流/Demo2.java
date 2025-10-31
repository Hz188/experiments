package D_特殊操作流.对象序列化流;

import java.io.FileInputStream;
import java.io.IOException;
import java.io.ObjectInputStream;

//反序列化流
public class Demo2 {
    public static void main(String[] args) throws IOException, ClassNotFoundException {
        ObjectInputStream ois = new ObjectInputStream(new FileInputStream("IO\\src\\D_特殊操作流\\对象序列化流\\oos.txt"));
        Object obj = ois.readObject();

        Student s = (Student)obj;
        System.out.println(s);

        ois.close();
    }
}
