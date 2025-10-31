package E_泛型.E_可变参数;

import java.util.Arrays;
import java.util.List;
import java.util.Set;

public class Demo2 {
    public static void main(String[] args) {
//        List<String> list = Arrays.asList("hello", "world", "java");
////        list.add("javaee"); //UnsupportedOperationException
////        list.remove("world") //UnsupportedOperationException
//        list.set(1,"javaee");
//        System.out.println(list);

//        List<String> list2 = List.of("hello", "world", "java");
//        list2.add("javaee"); //UnsupportedOperationException
//        list2.remove("java") //UnsupportedOperationException
//        list2.set(1,"java"); //UnsupportedOperationException
//        System.out.println(list2);

//        Set<String> set = Set.of("hello", "world", "java","world"); //IllegalArgumentException
        Set<String> set = Set.of("hello", "world", "java"); //
//        set.add("javaee"); //UnsupportedOperationException
//        set.remove("java") //UnsupportedOperationException
        System.out.println(set);

    }
}
