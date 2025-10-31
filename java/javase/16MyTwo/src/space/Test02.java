package space;

import space.hzzy.MyService;

import java.util.ServiceLoader;

public class Test02 {
    public static void main(String[] args) {
        //加载服务
        ServiceLoader<MyService> myService = ServiceLoader.load(MyService.class);
        for (MyService service : myService) {
            service.service();
        }
    }
}
