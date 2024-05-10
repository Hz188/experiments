import java.util.Random;
public class Main
{
    // Test the time required to run opCount dequeue and dequeue operations with q, unit: second
    private static double testQueue(Stack<Integer> stack, int opCount)
    {
        long statTime = System.nanoTime();

        //...
        Random random = new Random();
        for (int i = 0; i < opCount; i++)
        {
            stack.push(random.nextInt(Integer.MAX_VALUE));
        }
        for (int i = 0; i < opCount; i++)
        {
            stack.pop();
        }

        long endTime = System.nanoTime();

        return (endTime - statTime) / 1000000000.0;
    }


    public static void main(String[] args)
    {
        int opCount = 100000;
        ArrayStack<Integer> stack1 = new ArrayStack<>();
        double time1 = testQueue(stack1, opCount);

        System.out.println("time1 = " + time1 + "s");

        LinkedListStack<Integer> stack2 = new LinkedListStack<>();
        double time2 = testQueue(stack2, opCount);
        System.out.println("time2 = " + time2 + "s");

//        这个时间比较其实很复杂，因为LinkedListStack里有很多new操作
    }
}
