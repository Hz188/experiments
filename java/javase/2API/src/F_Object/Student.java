package F_Object;

import java.util.Objects;

public class Student {
    private int age;
    private String name;

    public Student() {
    }

    public Student(int age, String name) {
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
                "age=" + age +
                ", name='" + name + '\'' +
                '}';
    }

    @Override
    public boolean equals(Object o) {
        //比较地址是否相同，若同直接返回
        if (this == o) return true;
        //是null就没必要比 || 若不是一个类，就没必要比
        if (o == null || getClass() != o.getClass()) return false;
        //到这里 肯定就是一个类了  向下转型
        Student student = (Student) o;
        //比较成员变量是否相同，若同就true
        if (age != student.age) return false;
        return name != null ? name.equals(student.name) : student.name == null;
    }


}
