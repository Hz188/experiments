package D_Set;

import java.util.HashSet;
import java.util.Set;

public class Demo1 {
    public static void main(String[] args) {
        Set<String> set = new HashSet<>();
        set.add("hello");
        set.add("world");
        set.add("java");
        //Set doesn't contain duplicate elements.
        set.add("world");
        //HashSet对迭代顺序不做保证
        for (String s : set) {
            System.out.println(s);
        }
    }
}
