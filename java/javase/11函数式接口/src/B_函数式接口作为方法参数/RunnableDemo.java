package B_函数式接口作为方法参数;

public class RunnableDemo {
    public static void main(String[] args) {

        //匿名内部类
        startThread(new Runnable() {
            @Override
            public void run() {
                System.out.println(Thread.currentThread().getName() + "线程启动了");
            }
        });

        //Lambda
        startThread(() -> System.out.println(Thread.currentThread().getName() + "线程启动了"));
    }

    private static void startThread(Runnable r) {
        new Thread(r).start();
    }
}
