package D_Callable;

import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

public class TestCallable {

    public static void main(String[] args) throws ExecutionException, InterruptedException {

        //创建执行服务
        ExecutorService ser = Executors.newFixedThreadPool(3);
        //提交执行
        Future<Boolean> future = ser.submit(new MyCallable());
        Future<Boolean> future1 = ser.submit(new MyCallable());
        Future<Boolean> future2 = ser.submit(new MyCallable());
        //获取结果
        Boolean flag1 = future.get();
        Boolean flag2 = future1.get();
        Boolean flag3 = future2.get();
        System.out.println("flag1 = " + flag1);
        System.out.println("flag2 = " + flag2);
        System.out.println("flag3 = " + flag3);
        //关闭服务
        ser.shutdown();
    }
}
