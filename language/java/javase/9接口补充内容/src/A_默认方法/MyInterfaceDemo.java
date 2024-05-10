package A_默认方法;

public class MyInterfaceDemo {
    public static void main(String[] args) {
        MyInterface m  = new MyInterfaceImplOne();
        m.show1();
        m.show2();
        m.show3();
        m = new MyInterfaceImplTwo();
        m.show1();
        m.show2();
        m.show3();
    }
}
