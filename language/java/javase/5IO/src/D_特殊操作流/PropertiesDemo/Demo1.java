package D_特殊操作流.PropertiesDemo;

import java.util.Properties;
import java.util.Set;

//作为Map的使用
public class Demo1 {
    public static void main(String[] args) {
        //不支持泛型
        Properties prop = new Properties();
        prop.put("001","demo1");
        prop.put("002","demo2");
        prop.put("003","demo3");
        Set<Object> set = prop.keySet();
        for (Object key : set) {
            Object value = prop.get(key);
            System.out.println(key + " : " + value);
        }

    }
}
