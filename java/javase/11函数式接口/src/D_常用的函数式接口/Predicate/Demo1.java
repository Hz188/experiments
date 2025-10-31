package D_常用的函数式接口.Predicate;

import java.util.function.Predicate;

public class Demo1 {
    public static void main(String[] args) {
        boolean b1 = checkString("hello", s -> s.length() > 8);
        System.out.println(b1);

        boolean b2 = checkString("helloworld", s -> s.length() > 8);
        System.out.println(b2);
    }

    private static boolean checkString(String s, Predicate<String> pre) {
        return pre.test(s);
//        return !pre.test(s);等价于下面这个
//        return pre.negate().test(s);
    }
}
