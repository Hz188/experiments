package B_Lambda练习.practice1;

//抽象方法 无参数 无返回值
public class EatableDemo {
    public static void main(String[] args) {
        method1();
        method2();
        method3();
    }

    private static void useEatable(Eatable e) {
        e.eat();
    }


    //实现接口方式
    private static void method1() {
        EatableImpl ei = new EatableImpl();
        useEatable(ei);
    }

    //匿名内部类方式
    private static void method2() {
        useEatable(new Eatable() {
            @Override
            public void eat() {
                System.out.println("An apple a day, keep the doctor away.");
            }
        });
    }

    //Lambda表达式方式
    private static void method3() {
        useEatable(() -> {
            System.out.println("An apple a day, keep the doctor away.");
        });
    }

}
