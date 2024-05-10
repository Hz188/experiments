package D_常用的函数式接口.Predicate;

import java.util.ArrayList;
import java.util.function.Predicate;

public class PredicatePractice {
    public static void main(String[] args) {
        String[] arr = {"林青霞,30", "张曼玉,35", "王祖贤,33", "柳岩,34", "貂蝉,31"};
        ArrayList<String> filter = myFilter(arr, s -> s.split(",")[0].length() > 2,
                s -> Integer.parseInt(s.split(",")[1]) > 33);
        for (String s : filter) {
            System.out.println(s);
        }
    }

    private static ArrayList<String> myFilter(String[] arr, Predicate<String> pre1, Predicate<String> pre2) {
        ArrayList<String> res = new ArrayList<>();
        for (String s : arr) {
            if (pre1.and(pre2).test(s)) {
                res.add(s);
            }
        }

        return res;
    }
}
