package F_Map;

import java.util.HashMap;
import java.util.Map;

public class Demo1 {
    public static void main(String[] args) {
         Map<String, String> map = new HashMap<>();
         map.put("test001","Hz01");
         map.put("test002","Hz02");
        System.out.println(map.put("test003", "Hz03"));
        System.out.println(map.put("test003", "Hz04"));

        System.out.println(map);
    }
}
