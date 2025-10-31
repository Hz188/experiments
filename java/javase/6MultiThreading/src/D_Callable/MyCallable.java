package D_Callable;

import java.util.concurrent.Callable;

/*
* Callable
*   可以定义返回值
*   可以抛出异常
* */
public class MyCallable implements Callable<Boolean> {

    @Override
    public Boolean call() throws Exception {
        for (int i = 0; i < 100; i++) {
            System.out.println(Thread.currentThread().getName() + " :" + i);
        }
        return true;
    }
}
