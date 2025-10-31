package C_私有方法;

public interface Inter {
    default void show1(){
        System.out.println("show1开始执行");
//        System.out.println(1);
//        System.out.println(2);
//        System.out.println(3);

//        show();
        method();
        System.out.println("show1执行结束");
    }
    default void show2(){
        System.out.println("show2开始执行");
//        System.out.println(1);
//        System.out.println(2);
//        System.out.println(3);

//        show();
        method();
        System.out.println("show2执行结束");
    }

    private void show() {
        System.out.println(1);
        System.out.println(2);
        System.out.println(3);
    }

    static void method1(){
        System.out.println("method1开始执行");
//        System.out.println(1);
//        System.out.println(2);
//        System.out.println(3);
        method();
        System.out.println("method1执行结束");
    }

    static void method2(){
        System.out.println("method2开始执行");
//        System.out.println(1);
//        System.out.println(2);
//        System.out.println(3);
        method();
        System.out.println("method2执行结束");
    }

    private static void method(){
        System.out.println(1);
        System.out.println(2);
        System.out.println(3);
    }
}
