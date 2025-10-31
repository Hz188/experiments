package A_实现多线程.Demo3;

/*
    void setDaemon() 将此线程标记为守护线程，当运行的县城都是守护线程时，Java虚拟机将推出
 */
public class ThreadDaemonTest {
    public static void main(String[] args) {
        ThreadDaemon td1 = new ThreadDaemon();
        ThreadDaemon td2 = new ThreadDaemon();

        td1.setName("关羽");
        td2.setName("张飞");

        //设置主线程为刘备
        Thread.currentThread().setName("刘备");

        td1.setDaemon(true);
        td2.setDaemon(true);

        td1.start();
        td2.start();

        for (int i = 0; i < 10; i++) {
            System.out.println(Thread.currentThread().getName() + ":" + i);
        }
    }
}
