import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class Demo10 {
    public static void main(String[] args) {
        ArrayList<String> list = new ArrayList<>();

        list.add("林青霞");
        list.add("张曼玉");
        list.add("王祖贤");
        list.add("柳岩");

//        //1. 三个字名字
//        Stream<String> listStream = list.stream().filter(s -> s.length() == 3);
//        //2.收集到List中
//        List<String> names = listStream.collect(Collectors.toList());
//        //3.traverse
//        for (String name : names) {
//            System.out.println(name);
//        }


        Set<Integer> set = new HashSet<>();
        set.add(10);
        set.add(20);
        set.add(30);
        set.add(33);
        set.add(35);
//        // >25
//        Stream<Integer> setStream = set.stream().filter(age -> age > 25);
//        Set<Integer> ages = setStream.collect(Collectors.toSet());
//        for (Integer age : ages) {
//            System.out.println(age);
//        }

        String[] strArray = {"林青霞,30","张曼玉,35","王祖贤,33","柳岩,25"};
        //年龄大于28的
        Stream<String> arrayStream = Stream.of(strArray).filter(s -> Integer.parseInt(s.split(",")[1]) > 28);
        //收集到Map中 姓名为key 年龄为value
        Map<String, Integer> map = arrayStream.collect(Collectors.toMap(s -> s.split(",")[0], s -> Integer.parseInt(s.split(",")[1])));
        for (String key : map.keySet()) {
            System.out.println(key + "=" + map.get(key));
        }
    }
}
