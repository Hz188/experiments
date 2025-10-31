import java.util.*;
import java.util.stream.Stream;

public class Demo2 {
    public static void main(String[] args) {

        //1.Collection体系集合直接生成流
        List<String> list = new ArrayList<>();
        Stream<String> listStream = list.stream();

        Set<String> set = new HashSet<>();
        Stream<String> setStream = set.stream();

        //2.Map体系集合间接生成流
        Map<String, Integer> map = new HashMap<>();
        Stream<String> keyStream = map.keySet().stream();
        Stream<Integer> valueSteram = map.values().stream();
        Stream<Map.Entry<String, Integer>> entryStream = map.entrySet().stream();

        //3.数组 通过Stream静态方法
        String[] strArray = {"hello", "world", "java"};
        Stream<String> strStream = Stream.of(strArray);
        Stream<String> strStream2 = Stream.of("hello", "world", "java");
        Stream<Integer> intStream = Stream.of(10, 20, 30);


    }
}
