package C_Lambda省略模式;

public class LambdaDemo {
    public static void main(String[] args) {
        //1.参数类型可以省略
        useAddable((x, y) -> {
            return x + y;
        });
        useFlyable((s) -> {
            System.out.println(s);
        });

        //2.如果参数只有一个，小括号可以省略
        useFlyable(s -> {
            System.out.println(s);
        });

        //3.如果代码块只有一句，可以省略大括号和分号
        useFlyable(s -> System.out.println(s));
            //如果代码块只有一句，可以省略大括号和分号若有 返回值，return也省略掉
        useAddable((x, y) -> x + y);


    }

    private static void useAddable(Addable a) {
        int sum = a.add(10, 20);
        System.out.println(sum);
    }

    private static void useFlyable(Flyable f) {
        f.fly("晴空万里，风和日丽");
    }
}
