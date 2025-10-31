package D_常用的函数式接口.Function;

import java.util.function.Function;

public class Demo {
    public static void main(String[] args) {
//        convert("100",s -> Integer.parseInt(s));
        convert("100", Integer::parseInt);

        convert(100, x -> String.valueOf(x + 566));
        convert("100", Integer::parseInt, s -> String.valueOf(s + 566));
    }

    private static void convert(String s, Function<String, Integer> f) {
        Integer res = f.apply(s);
        System.out.println(res);
    }

    private static void convert(int x, Function<Integer, String> f) {
        String res = f.apply(x);
        System.out.println(res);
    }

    private static void convert(String s, Function<String, Integer> f1, Function<Integer, String> f2) {
        String res = f1.andThen(f2).apply(s);
        System.out.println(res);
    }
}
