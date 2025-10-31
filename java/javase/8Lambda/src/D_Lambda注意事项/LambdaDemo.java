package D_Lambda注意事项;

public class LambdaDemo {
    public static void main(String[] args) {
        method1();
        method2();


    }

    private static void method1() {
        //1.使用Lambda必须有接口，且有且仅有一个抽象方法
        userInter(() -> System.out.println("好好学习，天天向上"));
    }

    private static void method2() {
        //2.必须有上下文环境，才能推导出对应的Lambda接口
//        Runnable r = () -> System.out.println("Lambda表达式");
//        new Thread(r).start();
        new Thread(() -> System.out.println("Lambda表达式")).start();
    }

    private static void method3(){

    }
    private static void userInter(Inter i) {
        i.show();
    }
}
