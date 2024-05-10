package H_modifier.状态修饰符;

/**
 * fianl 修饰局部变量
 */
public class FinalDemo {
    public static void main(String[] args) {
        //final 修饰基本变量类型
        final int age = 20;
//        age = 30;  // error : 只能赋值一次
        System.out.println(age);

        final Son s = new Son();

//        s = new Son(); //error : 只能赋值一次 类似C++里的  指针常量 int* const p; 但是 *p可以改
            // s.age s.name 等等可以改
    }
}
