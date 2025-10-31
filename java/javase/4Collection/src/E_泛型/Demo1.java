package E_泛型;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Iterator;

public class Demo1 {
    public static void main(String[] args) {
        //不指定泛型
//        Collection c = new ArrayList();
//        c.add("hello");
//        c.add("world");
//        c.add("java");
//        c.add(100);
//        for (Object o : c) {
//            //System.out.println(o);
//            String s = (String)o; //ClassCastException
//            System.out.println(s);
//        }

        //指定泛型 就可以提前检查 同时不需要强制类型转换了
        Collection<String> c = new ArrayList<>();
        c.add("hello");
        c.add("world");
        c.add("java");
        //c.add(100);//会报错了
        Iterator<String> iterator = c.iterator();
        while (iterator.hasNext()){
            System.out.println(iterator.next());
        }

    }
}
