package B_Lambda练习.practice2;

//抽象方法 带参数 无返回值
public class FlyableDemo {
    public static void main(String[] args) {
        method1();
        method2();
    }

    private static void useFlyable(Flyable f) {
        f.fly("风和日丽，晴空万里");
    }

    //匿名内部类
    private static void method1() {
        useFlyable(new Flyable() {
            @Override
            public void fly(String s) {
                System.out.println(s);
                System.out.println("飞机自驾游");
            }
        });
    }

    //Lambda
    private static void method2() {
        useFlyable((s) -> {
            System.out.println(s);
            System.out.println("飞机自驾游");
        });
    }


}
