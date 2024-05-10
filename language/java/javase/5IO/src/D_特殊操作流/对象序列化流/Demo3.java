package D_特殊操作流.对象序列化流;

import java.io.*;
/*
    Exception in thread "main" java.io.InvalidClassException:
        异常的描述 见API doc
    D_特殊操作流.对象序列化流.Student;
    local class incompatible: stream classdesc serialVersionUID = -2534224565753862592,
        serialVersionUID 描述见 Serializable API doc
    local class serialVersionUID = -5967087657305586718
        类文件被修改了 序列化版本ID就改了，不匹配了 异常了
*/
//几个问题解释 具体问题见笔记
public class Demo3 {

    public static void main(String[] args) throws IOException, ClassNotFoundException {
//        write();
        read();
    }

    private static void  write() throws IOException {
        ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream("IO\\src\\D_特殊操作流\\对象序列化流\\oos.txt"));
        Student s = new Student("林青霞",30);
        oos.writeObject(s); //NotSerializableException
        oos.close();
    }
    private static void  read() throws IOException, ClassNotFoundException {
        ObjectInputStream ois = new ObjectInputStream(new FileInputStream("IO\\src\\D_特殊操作流\\对象序列化流\\oos.txt"));
        Object obj = ois.readObject();

        Student s = (Student)obj;
        System.out.println(s);

        ois.close();
    }
}
