package B_反射;

import java.lang.reflect.Constructor;
import java.lang.reflect.InvocationTargetException;
//私有构造并使用
public class ReflectionDemo03 {
    public static void main(String[] args) throws ClassNotFoundException, NoSuchMethodException, IllegalAccessException, InvocationTargetException, InstantiationException {


        //1.get .class file object
        Class<?> c = Class.forName("B_反射.Student");
        //2.get constructor
//        Constructor cons = c.getConstructor(String.class);  //NoSuchMethodException 只能获取公共的，说明没找到对应参数的公共方法
        Constructor<?> cons = c.getDeclaredConstructor(String.class);

        //3.get a new instance
        cons.setAccessible(true); // cancel access check
        Object o = cons.newInstance("Zy"); //IllegalAccessException 直接用私有方法访问，非法访问异常
        System.out.println(o);
    }
}
