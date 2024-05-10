package C_函数式接口作为方法的返回值;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class ComparatorDemo {
    public static void main(String[] args) {
//        定义集合存储字符串
        ArrayList<String> list = new ArrayList<>();

        list.add("cccc");
        list.add("aa");
        list.add("b");
        list.add("ddd");

        System.out.println("排序前" + list);

        Collections.sort(list, getComparator());

        System.out.println("排序后" + list);

    }

    private static Comparator<String> getComparator() {
        //匿名内部类
//        return new Comparator<String>() {
//            @Override
//            public int compare(String o1, String o2) {
//                return o1.length() - o2.length();
//            }
//        };

        //Lambda
        return (s1, s2) -> s1.length() - s2.length();
//        return Comparator.comparingInt(String::length);

    }
}
