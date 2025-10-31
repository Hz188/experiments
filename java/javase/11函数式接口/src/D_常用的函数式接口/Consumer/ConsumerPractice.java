package D_常用的函数式接口.Consumer;

import java.util.function.Consumer;

public class ConsumerPractice {
    public static void main(String[] args) {
        String[] arr = {"林青霞,30", "张曼玉,35", "王祖贤,33"};

        printInfo(arr, s -> {
            String name = s.split(",")[0];
            System.out.print("姓名：" + name);
        }, s -> {
            int age = Integer.parseInt(s.split(",")[1]);
            System.out.println("，年龄：" + age);
        });
    }

    private static void printInfo(String[] arr, Consumer<String> con1, Consumer<String> con2) {
        for (String s : arr) {
            con1.andThen(con2).accept(s);
        }

    }
}
