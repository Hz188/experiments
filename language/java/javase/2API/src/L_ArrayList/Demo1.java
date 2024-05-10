package L_ArrayList;

import java.util.ArrayList;

/**
 * Constructor
 *      public ArrayList()<>
 * add
 *      public boolean add(E e) 尾部插入
 *      public void add(int index, E e) 指定位置插入
 * common method
 *      public boolean remove(Object o) 删除指定元素 返回是否成功
 *      public E remove(int index)  删除指定位置元素，返回该元素
 *      public E set(int index, E e) 修改指定元素，返回被修改元素
 *      public E get(int index) 获取指定位置元素
 *      public int size() 返回集合中元素个数
 */
public class Demo1 {
    public static void main(String[] args) {
        ArrayList<String> arr = new ArrayList<>();

        arr.add("hello");
        arr.add("world");
        arr.add("java");
        System.out.println(arr);

        arr.add(0,"add(0)");
        System.out.println(arr);

        System.out.println(arr.remove("hello"));
        System.out.println(arr.remove("not exist"));
        System.out.println(arr);

        arr.remove(1);
        System.out.println(arr);

        arr.set(1,"python");
        System.out.println(arr);

        String s = arr.get(1);
        System.out.println(s);

        System.out.println("arr.size() = " + arr.size());

    }
}
