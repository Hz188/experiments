package H_modifier.状态修饰符;

/**
 * static 静态
 *      可以修饰成员变量 成员方法
 *      被类的所有对象共享
 *      建议通过类名访问
 *      同时静态只能访问静态成员
 *      非静态方法 静态和非静态成员都可访问
 */
public class StaticDemo {
    public static void main(String[] args) {

        Student.university = "LGfZ";

        Student s = new Student();
        s.age = 19;
        s.name = "Hz";
//        s.university = "LGFZ";  不推荐

        s.show();

        Student s2 = new Student();
        s2.age = 19;
        s2.name = "Zy";
//        s2.university = "LGFZ";
//        s1 s2 都有 -> 类成员
        s2.show();

        Student.show1();
    }
}

class Student {
    public String name;
    public int age;
    public static String university;

    public void show(){
        System.out.printf("%s %d %s\n",name,age,university);
    }

    public static void show1(){
        System.out.println(university);
    }
}