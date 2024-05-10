package B_线程同步;

public class SellTickets implements Runnable {

    private int tickets = 100;
    private Object obj = new Object();

    @Override
    public void run() {
        //1.相同票出现多次
//        while (true) {
//            //tickets = 100
//            //t1,t2,t3
//            //假设t1抢到CPU执行权
//            if (tickets > 0) {
//                try {
//                    Thread.sleep(100);
//                    //t1 sleep 100ms
//                    //t2 抢到执行权，t2线程开始执行，执行到这t2 sleep 100ms
//                    //t3 抢到执行权，t3线程开始执行，执行到这t3 sleep 100ms
//                } catch (InterruptedException e) {
//                    e.printStackTrace();
//                }
//                //假设 线程按照顺序醒来
//                //t1-> 输出 正在出售第100张票
//                System.out.println(Thread.currentThread().getName() + "正在出售第" + tickets + "票");
//                //t1 还没进行 tickets-- t2抢到了执行权
//                //t2 -> 输出 正在输出100张票
//                //t3同理 也 正在输出100张票
//                tickets--;
//                //然后如果还按顺序，这里就执行了三次 -- 操作，最终就变成了97张票
//            }
//        }
//        //2.出现了负数的票
//        while (true) {
//            //tickets = 1
//            //t1,t2,t3
//            //假设t1抢到CPU执行权
//            if (tickets > 0) {
//                try {
//                    Thread.sleep(100);
//                    //t1 sleep 100ms
//                    //t2 抢到执行权，t2线程开始执行，执行到这t2 sleep 100ms
//                    //t3 抢到执行权，t3线程开始执行，执行到这t3 sleep 100ms
//                } catch (InterruptedException e) {
//                    e.printStackTrace();
//                }
//                //假设 线程按照顺序醒来
//                //t1到执行权-> 输出 正在出售第1张票
//                //假设t1 继续拥有执行权 执行了 -- 操作 tickets = 0
//                //t2到执行权-> 输出 正在出售第0张票
//                //假设t2 继续拥有执行权 执行了 -- 操作 tickets = -1
//                //t3到执行权-> 输出 正在出售第-1张票
//                //最后执行 -- 操作 tickets = -2
//                System.out.println(Thread.currentThread().getName() + "正在出售第" + tickets + "票");
//                tickets--;
//            }
//        }


        //解决上述两种问题
        while (true) {
            //tickets = 100
            //t1,t2,t3
            //t1抢到执行权
            //t1 sleep了 t2抢到了 发现被锁起来了 也只能等着
            synchronized (obj) {
                //t1进来后就会把这段代码锁起来
                if (tickets > 0) {
                    try {
                        //t1 sleep
                        Thread.sleep(100);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                    System.out.println(Thread.currentThread().getName() + "正在出售第" + tickets + "票");
                    tickets--;
                }
            }
            //t1 出来了，这段代码的锁就被释放了
        }
    }

    //synchronized method
    //锁对象是 this 静态方法是 类.class
    public synchronized void sellTicket() {
        if (tickets > 0) {
            try {
                Thread.sleep(100);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            System.out.println(Thread.currentThread().getName() + "正在出售第" + tickets + "票");
            tickets--;
        }
    }
}

