package D_常用的函数式接口.Supplier;

import java.util.function.Supplier;

public class Demo {
    public static void main(String[] args) {

        String s = getString(() -> "林青霞");
        System.out.println(s);

        Integer i = getInt(() -> 30);
        System.out.println(i);
    }

    private static String getString(Supplier<String> sup) {
        return sup.get();

    }

    private static Integer getInt(Supplier<Integer> sup) {
        return sup.get();
    }
}
