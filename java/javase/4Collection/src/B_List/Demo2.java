package B_List;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class Demo2 {
    public static void main(String[] args) {
        List<String> list = new ArrayList<>();
        list.add("hello");
        list.add("world");
        list.add("java");

//        Iterator<String> it = list.iterator();
//        while (it.hasNext()) {
//            String next = it.next(); //会产生并发修改异常
//            if (next.equals("world")) {
//                list.add("javaee");
//            }
//        }
        for (int i = 0; i < list.size(); i++) {
            String s = list.get(i);
            if (s.equals("world")) {
                list.add("javaee");
            }
        }
        System.out.println(list);
    }
}
