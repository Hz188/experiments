package G_冒泡排序;

import java.util.Arrays;

public class BubbleSort {
    public static void main(String[] args) {
        int[] A = {1, 3, 2, 7, 4, 8};
        boolean flag = true;
        for (int i = 0; flag; i++) {
            flag = false;
            for (int j = A.length - 1; j > i; j--) {
                if (A[j] < A[j -1 ]){
                    int temp = A[j];
                    A[j] = A[j - 1];
                    A[j - 1] = temp;
                    flag = true;
                }
            }
        }
        System.out.println(Arrays.toString(A));
    }
}
