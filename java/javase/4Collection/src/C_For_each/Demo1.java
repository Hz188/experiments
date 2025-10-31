package C_For_each;

import java.util.ArrayList;
import java.util.List;

public class Demo1 {
    public static void main(String[] args) {

        int[] arr = {1, 2, 3};
        for (int i : arr) {
            System.out.println(i);
        }

        List<String> list = new ArrayList<>();
        list.add("hello");
        list.add("world");
        list.add("java");
        for (String s : list) {
            System.out.println(s);
        }

        //内部原理是一个迭代器
        for (String s : list) {
            if (s.equals("world")){
                list.add("javaee");//会throw 一个 并发修改异常 ConcurrentModificationException
            }
        }
    }
}
