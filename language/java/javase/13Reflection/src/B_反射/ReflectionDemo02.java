package B_反射;

import java.lang.reflect.Constructor;
import java.lang.reflect.InvocationTargetException;

public class ReflectionDemo02 {
    public static void main(String[] args) throws ClassNotFoundException, NoSuchMethodException, IllegalAccessException, InvocationTargetException, InstantiationException {
        //带参数构造并使用

        //1.get .class file object
        Class<?> c = Class.forName("B_反射.Student");
        //2.get constructor
        Constructor<?> cons = c.getConstructor(String.class, int.class, String.class);
        //3.get a new instance
        Object o = cons.newInstance("Hz", 22, "LuoYang");
        System.out.println(o);
    }
}
