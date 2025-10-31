package D_特殊操作流.PropertiesDemo;

import java.util.Properties;
import java.util.Set;

//作为Map特有的方法
public class Demo2 {
    public static void main(String[] args) {
        Properties prop = new Properties();
        prop.setProperty("001","demo1");
        prop.setProperty("002","demo2");
        prop.setProperty("003","demo3");
        System.out.println(prop);

        System.out.println(prop.getProperty("001")); //demo1
        System.out.println(prop.getProperty("0011")); //null

        Set<String> names = prop.stringPropertyNames();
        for (String name : names) {
            System.out.println(name);
            System.out.println(prop.getProperty(name));
        }

    }
}
