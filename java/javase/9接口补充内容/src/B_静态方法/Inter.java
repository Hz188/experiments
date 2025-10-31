package B_静态方法;

public interface Inter {

    void show();

    default void method(){
        System.out.println("Inter中的默认方法执行了");
    }

    static void test(){
        System.out.println("Inter中的静态方法执行了");
    }
}
