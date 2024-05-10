package D_常用的函数式接口.Predicate;

import java.util.function.Predicate;

public class Demo2 {
    public static void main(String[] args) {
        boolean b1 = checkString("hello", s -> s.length() > 8);
        System.out.println(b1);

        boolean b2 = checkString("helloworld", s -> s.length() > 8);
        System.out.println(b2);

        boolean b3 = checkString("hello", s -> s.length() > 8, s -> s.length()<15);
        System.out.println(b3);
        boolean b4 = checkString("helloworld", s -> s.length() > 8, s -> s.length()<15);
        System.out.println(b4);
    }

    //同一个字符串，给出两个不同的判断条件，最后进行逻辑与作为最终的结果
    private static boolean checkString(String s, Predicate<String> pre1, Predicate<String> pre2) {
//        boolean b1 = pre1.test(s);
//        boolean b2 = pre2.test(s);
//        boolean b = b1 && b2;
//        return b;
        return pre1.and(pre2).test(s);
//        return pre1.or(pre2).test(s);
    }
    private static boolean checkString(String s, Predicate<String> pre) {
        return pre.test(s);
    }
}
