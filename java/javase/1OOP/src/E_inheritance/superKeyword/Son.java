package E_inheritance.superKeyword;

/**
 * 本类
 *      1、this.成员变量
 *      2、this.成员方法
 *      3、构造方法 this()
 * 父类
 *      1. super.成员变量
 *      2、super.成员方法
 *      3、构造方法 super()
 */
public class Son extends Father {
    public int age = 20;
    public void method(){
        int age = 10;
        System.out.println("age = " + age);
        System.out.println("this.age = " + this.age);
        System.out.println("super.age = " + super.age);
        System.out.println("Son method.");
    }
}
