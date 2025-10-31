package F_Map;

import java.util.Collection;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;

public class Demo3 {
    public static void main(String[] args) {
        Map<String, String> map = new HashMap<>();

        map.put("张无忌", "赵敏");
        map.put("郭靖", "黄蓉");
        map.put("杨过","小龙女");

        System.out.println("map.get(\"张无忌\") = " + map.get("张无忌"));
        System.out.println("map.get(\"张三丰\") = " + map.get("张三丰"));

        Set<String> keySet = map.keySet();
        for (String s : keySet) {
            System.out.println(s);
        }

        Collection<String> values = map.values();
        for (String value : values) {
            System.out.println(value);
        }




    }
}
