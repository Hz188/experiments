package C_生产者消费者;

public class Box {
    //表示第x瓶奶
    private int milk;
    //表示奶箱的状态 有无牛奶
    private boolean state = false;

    public synchronized void put(int milk) {
        //如果有牛奶，应该等待消费，而不是继续放奶
        if (state) {
            try {
                wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        //如果没有牛奶就生产牛奶
        this.milk = milk;
        System.out.println("送奶工将第" + this.milk + "瓶奶放入奶箱");
        //生产完毕，修改奶箱状态
        state = true;
        //唤醒其他线程
        notifyAll();
    }

    public synchronized void get() {
        //如果没有牛奶，等待生产
        if (!state) {
            try {
                wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        //如果有牛奶就消费牛奶
        System.out.println("用户拿到第" + this.milk + "瓶奶");

        //消费完毕，修改奶箱状态
        state = false;
        notifyAll();
    }
}
