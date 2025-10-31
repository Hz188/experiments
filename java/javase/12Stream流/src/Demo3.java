import java.util.ArrayList;
import java.util.stream.Stream;

public class Demo3 {
    public static void main(String[] args) {
        ArrayList<String> list = new ArrayList<>();

        list.add("林青霞");
        list.add("张曼玉");
        list.add("王祖贤");
        list.add("柳岩");
        list.add("张敏");
        list.add("张无忌");

        Stream<String> stream = list.stream();

        //1.输出张开头
        list.stream().filter(s -> s.startsWith("张")).forEach(System.out::println);
        System.out.println("----------------");
        //2.输出长度3的
        list.stream().filter(s -> s.length() == 3).forEach(System.out::println);
        System.out.println("----------------");

        //3.输出张开头，长度三的
        list.stream().filter(s -> s.startsWith("张")).filter(s -> s.length() == 3).forEach(System.out::println);
    }
}
