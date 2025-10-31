package D_特殊操作流.对象序列化流;

import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;
//序列化流
public class Demo1 {
    public static void main(String[] args) throws IOException {
        ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream("IO\\src\\D_特殊操作流\\对象序列化流\\oos.txt"));
        Student s = new Student("林青霞",30);
        oos.writeObject(s); //NotSerializableException
        oos.close();
    }
}
