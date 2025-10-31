package A_Collection;

import java.util.ArrayList;
import java.util.Collection;

public class Demo1 {
    public static void main(String[] args) {
        Collection<String> c = new ArrayList<>();
        c.add("hello");
        c.add("world");
        c.add("java");
        System.out.println(c);

        c.remove("hello");
        System.out.println(c);

        System.out.println(c.contains("hello"));

        c.clear();
        System.out.println(c);
        System.out.println("c.isEmpty() = " + c.isEmpty());
    }
}
