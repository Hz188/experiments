package F_Map;

import java.util.HashMap;
import java.util.Map;
import java.util.Set;

public class Traverse1 {
    public static void main(String[] args) {
        Map<String, String> map = new HashMap<>();

        map.put("张无忌", "赵敏");
        map.put("郭靖", "黄蓉");
        map.put("杨过","小龙女");

        Set<String> keySet = map.keySet();
        for (String s : keySet) {
            System.out.println(s + " : " + map.get(s));
        }
    }
}
