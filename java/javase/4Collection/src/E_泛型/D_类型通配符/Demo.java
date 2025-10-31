package E_泛型.D_类型通配符;

import java.util.ArrayList;
import java.util.List;

public class Demo {
    public static void main(String[] args) {
        // <?>
        List<?> list = new ArrayList<Object>();
        List<?> list1 = new ArrayList<Number>();
        List<?> list2 = new ArrayList<Integer>();

        // <? extends Number>
//        List<? extends Number> list3 = new ArrayList<Object>();//error
        List<? extends Number> list4 = new ArrayList<Number>();
        List<? extends Number> list5 = new ArrayList<Integer>();
        List<? extends Number> list6 = new ArrayList<Byte>();

        // <? super Number>
        List<? super Number> list7 = new ArrayList<Number>();
        List<? super Number> list8 = new ArrayList<Object>();
//        List<? super Number> list9 = new ArrayList<Integer>(); //error

    }
}
