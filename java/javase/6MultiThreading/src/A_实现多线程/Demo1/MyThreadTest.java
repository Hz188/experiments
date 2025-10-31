package A_实现多线程.Demo1;
//1.定义一个类MyThread继承Thread类
//2.在MyThread类中重写run()方法
//3.创建MyThread类的对象
//4.启动线程.
public class MyThreadTest {
    public static void main(String[] args) {
//        MyThread t1 = new MyThread();
//        MyThread t2 = new MyThread();
//        t1.setName("飞机");
//        t2.setName("高铁");
        MyThread t1 = new MyThread("飞机");
        MyThread t2 = new MyThread("高铁");
        t1.start();
        t2.start();

        System.out.println(Thread.currentThread().getName());
    }
}
