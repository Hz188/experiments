package B_反射;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.util.ArrayList;

public class ArrayListDemo {
    public static void main(String[] args) throws InvocationTargetException, IllegalAccessException, NoSuchMethodException {
        ArrayList<Integer> arr = new ArrayList<>();
        //泛型是给编译器看的，源码中都是object类型
//        arr.add(10); //success
//        arr.add("hello"); //fail

        Class<? extends ArrayList> c = arr.getClass();
        Method add = c.getDeclaredMethod("add", Object.class);

        add.invoke(arr,"hello");
        add.invoke(arr,"world");
        add.invoke(arr,"java");

        System.out.println(arr);
    }
}
