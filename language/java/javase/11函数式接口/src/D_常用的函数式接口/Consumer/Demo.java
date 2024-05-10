package D_常用的函数式接口.Consumer;

import java.io.StringReader;
import java.util.function.Consumer;

public class Demo {
    public static void main(String[] args) {
        useString("abc", s -> System.out.println(s));
//        useString("abc", System.out::println);
        useString("abc", s -> System.out.println(new StringBuilder(s).reverse().toString()));
        System.out.println("------");
        useStringTwice("abc",System.out::println,s -> System.out.println(new StringBuilder(s).reverse().toString()));
        }

    private static void useString(String name, Consumer<String> con) {
        con.accept(name);
    }

    //同一个字符串消费两次
    private static void useStringTwice(String name, Consumer<String> con1,Consumer<String> con2) {
        con1.andThen(con2).accept(name);
    }

}
