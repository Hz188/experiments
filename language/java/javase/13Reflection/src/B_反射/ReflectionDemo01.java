package B_反射;

import java.lang.reflect.Constructor;
import java.lang.reflect.InvocationTargetException;

/**
 * 通过反射获取构造方法并使用
 */
public class ReflectionDemo01 {
    public static void main(String[] args) throws ClassNotFoundException, NoSuchMethodException,
            IllegalAccessException, InvocationTargetException, InstantiationException {
        //1. get .class file
        Class<?> c = Class.forName("B_反射.Student");

        //2. get Constructor
        Constructor<?>[] cons = c.getConstructors(); // 所有 public 构造方法
//        Constructor<?>[] cons = c.getDeclaredConstructors(); //所有构造
        for (Constructor<?> con : cons) {
            System.out.println(con);
        }

        //获取单个构造方法
        //参数：要获取的构造方法的参数类型的个数和class字节码文件对像
        Constructor<?> con = c.getConstructor();
        Constructor<?> con1 = c.getConstructor(String.class, int.class, String.class);
        System.out.println(con);
        System.out.println(con1);

        // 使用此构造方法对象去创建该对象的新实例 Person p = new Person()
        Object o = con.newInstance();
        System.out.println(o);

    }
}
