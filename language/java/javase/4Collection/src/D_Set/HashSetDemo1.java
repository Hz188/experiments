package D_Set;

import java.util.HashSet;


public class HashSetDemo1 {
    public static void main(String[] args) {
        HashSet<String> set = new HashSet<>();
        set.add("hello");
        set.add("world");
        set.add("java");
        set.add("world");
        for (String s : set) {
            System.out.println(s);
        }
    }
}
