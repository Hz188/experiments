package H_modifier.状态修饰符;

/**
 *  final
 *  修饰方法 让子类无法重写
 *  修饰类 最终类 无法被继承
 *  修饰成员变量 只能赋值一次 为常量值
 */
public /*final*/ class Father {

    private /*final*/ int age = 40;

    public /*final*/ void method(){
        System.out.println(age);
        System.out.println("Father method");
    }

}
