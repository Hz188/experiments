package B_反射;

public class Student {
    private String name;
    int age;
    public String address;

    public Student() {
    }

    private Student(String name) {
        this.name = name;
    }

    Student(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public Student(String name, int age, String address) {
        this.name = name;
        this.age = age;
        this.address = address;
    }

    private void function() {
        System.out.println("function");
    }

    public void show() {
        System.out.println("show");
    }

    public void method(String s) {
        System.out.println("method" + s);
    }

    public String getString(String s, int i) {
        return s + "---" + i;
    }

    @Override
    public String toString() {
        return "Person{" +
                "name='" + name + '\'' +
                ", age=" + age +
                ", address='" + address + '\'' +
                '}';
    }
}
