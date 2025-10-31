package F_Map;

import java.util.HashMap;
import java.util.Map;

public class Demo2 {
    public static void main(String[] args) {
        Map<String, String> map = new HashMap<>();
        map.put("test001","Hz01");
        map.put("test002","Hz02");
        map.put("test003", "Hz03");
        System.out.println(map);

        System.out.println("map.remove(\"test001\") = " + map.remove("test001"));
        System.out.println(map);
        System.out.println("map.containsKey(\"test002\") = " + map.containsKey("test002"));
        System.out.println("map.containsValue(\"Hz03\") = " + map.containsValue("Hz03"));
        System.out.println("map.size() = " + map.size());
        System.out.println("map.isEmpty() = " + map.isEmpty());
        map.clear();
        System.out.println(map);
    }
}
