package G_Collections;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Demo1 {
    public static void main(String[] args) {
        List<Integer> list = new ArrayList<>();

        list.add(30);
        list.add(20);
        list.add(50);
        list.add(10);
        list.add(40);

        System.out.println(list);
        //1.
//        Collections.sort(list);
        //2.
//        Collections.reverse(list);
        //3.
        Collections.shuffle(list);

        System.out.println(list);
    }
}
