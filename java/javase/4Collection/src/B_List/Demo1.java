package B_List;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class Demo1 {
    public static void main(String[] args) {
        List<String> list = new ArrayList<>();

        list.add("hello");
        list.add("world");
        list.add("java");
        list.add("world");
        System.out.println(list);

        list.add(0,"zero 0");
        System.out.println(list);

        System.out.println(list.set(0, "set 0-index"));
        System.out.println(list);

        System.out.println(list.remove(0));
        System.out.println(list);

        System.out.println("list.get(0) = " + list.get(0));
//        Iterator<String> it = list.iterator();
//        while (it.hasNext()){
//            System.out.println(it.next());
//        }
    }
}
