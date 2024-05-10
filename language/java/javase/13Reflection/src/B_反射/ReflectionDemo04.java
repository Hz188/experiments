package B_反射;

import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.lang.reflect.InvocationTargetException;

/**
 * 通过反射获取变量并使用
 */
public class ReflectionDemo04 {
    public static void main(String[] args) throws ClassNotFoundException, NoSuchFieldException, IllegalAccessException, NoSuchMethodException, InstantiationException, InvocationTargetException {
        //1.get .class file object
        Class<?> c = Class.forName("B_反射.Student");

        //通过无参构造
        Constructor<?> cons = c.getConstructor();
        Object obj = cons.newInstance();
        System.out.println(obj);
        //2.get fields
//        Field[] fileds1 = c.getFields(); // public field
//        Field[] fields2 = c.getDeclaredFields();

        //get single field and value it
        /* simulation
            Person p = new Person()
            p.address = "Beijing"
            System.out.println(p.address)
        */

        //get address, name, age
        Field address = c.getDeclaredField("address");
        address.set(obj, "Beijing");   //给obj对象的address赋值为beijing
        System.out.println(obj);

        Field name = c.getDeclaredField("name");
        name.setAccessible(true);
        name.set(obj,"haozhe");
        System.out.println(obj);

        Field age = c.getDeclaredField("age");
        age.setAccessible(true);
        age.setInt(obj,18);
        System.out.println(obj);
        //3.get a new instance
    }
}
