package B_反射;

import java.lang.reflect.Constructor;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

/*
 * 获取方法 取消权限检查
 */
public class ReflectionDemo05 {
    public static void main(String[] args) throws ClassNotFoundException, NoSuchMethodException,
            IllegalAccessException, InstantiationException, InvocationTargetException {
        //1.get .class file object
        Class<?> c = Class.forName("B_反射.Student");

        //通过无参构造
        Constructor<?> cons = c.getConstructor();
        Object obj = cons.newInstance();

        //2. get methods
        //2.1 All methods
//        Method[] methods = c.getMethods(); // 获得自己的 and 父的 public
//        Method[] methods = c.getDeclaredMethods(); // 获取自己的所有
//        for (Method method : methods) {
//            System.out.println(method);
//        }

        //2.2 single method
        //getMethod(String name, Class<?>... parameters)
        Method show = c.getMethod("show");
        //invoke(Object obj, Object... args)
        show.invoke(obj);

        Method method = c.getMethod("method", String.class);
        method.invoke(obj,"hello");

        Method getString = c.getMethod("getString", String.class, int.class);
        Object retPara = getString.invoke(obj, "Hello", 18);
        System.out.println(retPara);

        //private
        Method function = c.getDeclaredMethod("function");
        function.setAccessible(true);
        function.invoke(obj);

    }
}
