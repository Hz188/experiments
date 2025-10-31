package B_线程同步.利用锁;

import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class SellTickets implements Runnable {

    private int tickets = 100;
    private Lock lock = new ReentrantLock();

    @Override
    public void run() {


        while (true) {
            try {
                lock.lock();
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
            } finally {
                lock.unlock();
            }


        }
    }
}
