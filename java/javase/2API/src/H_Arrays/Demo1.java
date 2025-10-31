package H_Arrays;

import java.util.Arrays;

public class Demo1 {
    public static void main(String[] args) {
        int[] A = {1, 3, 2, 7, 4, 8};
        System.out.println(Arrays.toString(A));
        Arrays.sort(A);
        System.out.println(Arrays.toString(A));
        /*
            工具类设计思想
                构造方法用private修饰
                成员用public static 修饰
        */
    }
}
