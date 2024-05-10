package B_静态方法;

public class InterDemo {
    public static void main(String[] args) {
        Inter i = new InterImpl();
        i.show();
        i.method();
//        i.test(); //Static method may be invoked on containing interface class only
//        InterImpl.test() //Static method may be invoked on containing interface class only
        Inter.test();

    }
}
