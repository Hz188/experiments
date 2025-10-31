package D_特殊操作流.对象序列化流;

import java.io.Serializable;

public class Student implements Serializable/*标识接口 无需实现方法*/ {

    private  static final long serialVersionUID = 42L;
    private String name;
//    private int age;
    transient private int age;

    public Student() {
    }

    public Student(String name,int age) {
        this.age = age;
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    @Override
    public String toString() {
        return "Student{" +
                "name='" + name + '\'' +
                ", age=" + age +
                '}';
    }


}
