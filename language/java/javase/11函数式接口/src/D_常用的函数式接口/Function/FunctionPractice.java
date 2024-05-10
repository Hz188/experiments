package D_常用的函数式接口.Function;

import java.util.function.Function;

public class FunctionPractice {
    public static void main(String[] args) {
        String s = "林青霞,30";
        convert(s, ss -> ss.split(",")[1], Integer::parseInt, x -> x + 70);
    }

    private static void convert(String s, Function<String, String> f1, Function<String, Integer> f2, Function<Integer, Integer> f3) {
        Integer res = f1.andThen(f2).andThen(f3).apply(s);
        System.out.println(res);
    }
}
