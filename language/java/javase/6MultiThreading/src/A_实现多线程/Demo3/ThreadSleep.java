package A_实现多线程.Demo3;

public class ThreadSleep extends Thread{
    @Override
    public void run() {
        for (int i = 0; i < 100; i++) {
            System.out.println(this.getName() + ":" + i);
            try {
                Thread.sleep(1000);//线程休眠
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
