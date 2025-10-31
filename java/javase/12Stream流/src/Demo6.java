import java.util.ArrayList;
import java.util.Comparator;

public class Demo6 {
    public static void main(String[] args) {
        ArrayList<String> list = new ArrayList<>();

        list.add("linqingxia");
        list.add("zhangmanyu");
        list.add("wangzuxian");
        list.add("liuyan");
        list.add("zhangmin");
        list.add("zhangwuji");

        //natural order
//        list.stream().sorted().forEach(System.out::println);

        //lambda
//        list.stream().sorted((s1, s2) -> s1.length() - s2.length()).forEach(System.out::println);
        //method reference
//        list.stream().sorted(Comparator.comparingInt(String::length)).forEach(System.out::println);



        //lambda
        list.stream().sorted((s1, s2) -> {
            int num = s1.length() - s2.length();
            return num == 0 ? s1.compareTo(s2) : num;
        }).forEach(System.out::println);
        //method reference
        list.stream().sorted(Comparator.comparingInt(String::length).thenComparing(s -> s)).forEach(System.out::println);
    }
}
