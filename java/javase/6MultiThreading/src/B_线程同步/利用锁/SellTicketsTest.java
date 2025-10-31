package B_线程同步.利用锁;

public class SellTicketsTest {
    public static void main(String[] args) {
        SellTickets st = new SellTickets();

        Thread t1 = new Thread(st,"Window 1");
        Thread t2 = new Thread(st,"Window 2");
        Thread t3 = new Thread(st,"Window 3");


        t1.start();
        t2.start();
        t3.start();
    }
}
