import java.util.ArrayList;
import java.util.stream.Stream;

public class Demo5 {
    public static void main(String[] args) {
        ArrayList<String> list = new ArrayList<>();

        list.add("林青霞");
        list.add("张曼玉");
        list.add("王祖贤");
        list.add("柳岩");
        list.add("张敏");
        list.add("张无忌");

        Stream<String> s1 = list.stream().limit(4);

        Stream<String> s2 = list.stream().skip(2);


//        Stream.concat(s1, s2).forEach(System.out::println);

        Stream.concat(s1, s2).distinct().forEach(System.out::println);

    }
}
