package B_List;

import java.util.ArrayList;
import java.util.List;
import java.util.ListIterator;

public class Demo3 {
    public static void main(String[] args) {
        List<String> list = new ArrayList<>();
        list.add("hello");
        list.add("world");
        list.add("java");

        ListIterator<String> it = list.listIterator();

//        while (it.hasNext()) {
//            System.out.println(it.nextIndex() + " " + it.next());
//        }
//        System.out.println("--------");
//        while (it.hasPrevious()){
//            System.out.println(it.previousIndex() + " " + it.previous());
//        }

        while (it.hasNext()){
            if (it.next().equals("world")){
                System.out.println("-------before add()---------");
                System.out.println("it.nextIndex() = " + it.nextIndex());
                System.out.println("it.previousIndex() = " + it.previousIndex());
                it.add("javaee");//会被添加在下一次next返回的元素之前
                // 因为现在next是world 下一次是java，所以添加在java之前
                System.out.println("-------after add() --------");
                System.out.println("it.nextIndex() = " + it.nextIndex());
                System.out.println("it.previousIndex() = " + it.previousIndex());
            }
        }
        System.out.println(list);
    }
}
