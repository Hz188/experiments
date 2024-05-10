import java.util.ArrayList;

public class Demo1 {
    public static void main(String[] args) {

        ArrayList<String> arr = new ArrayList<>();

        arr.add("林青霞");
        arr.add("张曼玉");
        arr.add("王祖贤");
        arr.add("柳岩");
        arr.add("张敏");
        arr.add("张无忌");

        //把 张 开头的 存在一个新的集合
        ArrayList<String> zhangArr = new ArrayList<>();
        for (String s : arr) {
            if (s.startsWith("张")) {
                zhangArr.add(s);
            }
        }
        System.out.println(zhangArr);

        //张 里 长度为3 的存到一个新集合
        ArrayList<String> threeArr = new ArrayList<>();
        for (String s : zhangArr) {
            if (s.length() == 3) {
                threeArr.add(s);
            }
        }
        System.out.println(threeArr);

        System.out.println("----------");

        //上述过滤操作过于繁琐，所以有了如下方式

        arr.stream().filter(s -> s.startsWith("张")).filter(s -> s.length()==3).forEach(System.out::println);

    }
}
