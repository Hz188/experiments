package A_体验Lambda;

//Requirement: Start a thread, output a string "Multithreading program has started"
public class Demo1 {
    public static void main(String[] args) {
        method1();
        method2();
    }

    //method1
    //实现类的方式
    public static void method1() {
        MyRunnable my = new MyRunnable();
        Thread t = new Thread(my);
        t.start();
    }

    //method2
    //匿名内部类方式
    public static void method2() {
        new Thread(new Runnable() {
            @Override
            public void run() {
                System.out.println("Multithreading program has started.");
            }
        }).start();
    }

    //lambda方式
    public static void method3() {
        new Thread( () -> {
            System.out.println("Multithreading program has started.");
        }).start();
    }
}
