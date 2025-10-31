package A_实现多线程.Demo2;

public class PriorityTest {
    public static void main(String[] args) {
        MyThread t1 = new MyThread();
        MyThread t2 = new MyThread();
        MyThread t3 = new MyThread();

        t1.setName("高铁");
        t2.setName("飞机");
        t3.setName("骑车");

//        System.out.println(t1.getPriority());//5
//        System.out.println(t2.getPriority());//5
//        System.out.println(t3.getPriority());//5

//        System.out.println(Thread.MAX_PRIORITY);//10
//        System.out.println(Thread.MIN_PRIORITY);//1
//        System.out.println(Thread.NORM_PRIORITY);//5

        t1.setPriority(5);
        t2.setPriority(10);
        t3.setPriority(1);
//        t1.start();
//        t2.start();
//        t3.start();
    }
}
