package A_Collection;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Iterator;

public class IteratorDemo {
    public static void main(String[] args) {
        Collection<String> c = new ArrayList<>();
        c.add("hello");
        c.add("world");
        c.add("java");
        System.out.println(c);

        Iterator<String> it = c.iterator();
        while (it.hasNext()) {
            System.out.println("删除前" + c);
            System.out.println(it.next());
            it.remove();
            System.out.println("删除后" + c);
        }

    }
}
