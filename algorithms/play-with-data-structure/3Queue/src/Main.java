import java.util.Random;

public class Main
{
    // Test the time required to run opCount dequeue and dequeue operations with q, unit: second
    private static double testQueue(Queue<Integer> q, int opCount)
    {
        long statTime = System.nanoTime();

        //...
        Random random = new Random();
        for (int i = 0; i < opCount; i++)
        {
            q.enqueue(random.nextInt(Integer.MAX_VALUE));
        }
        for (int i = 0; i < opCount; i++)
        {
            q.dequeue();
        }

        long endTime = System.nanoTime();

        return (endTime - statTime) / 1000000000.0;
    }

    public static void main(String[] args)
    {
        // Operator Count
        int opCount = 100000;
        ArrayQueue<Integer> arrayQueue = new ArrayQueue<>();
        double time1 = testQueue(arrayQueue, opCount);
        System.out.println("time1 = " + time1 + "s");

        LoopQueue<Integer> loopQueue = new LoopQueue<>();
        double time2 = testQueue(loopQueue, opCount);
        System.out.println("time2 = " + time2 + "s");

        LinkListQueue<Integer> linkListQueue = new LinkListQueue<>();
        double time3 = testQueue(linkListQueue, opCount);
        System.out.println("time3 = " + time3 + "s");
    }
}
