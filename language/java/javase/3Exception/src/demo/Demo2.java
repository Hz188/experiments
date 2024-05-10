package demo;

public class Demo2 {
    public static void main(String[] args) {
        System.out.println("start");
        method();
        System.out.println("end");
    }

    public static void method() {
        try {
            int[] arr = {1, 2, 3};
//        System.out.println(arr[1]);
            System.out.println(arr[3]);
            // new ArrayIndexOutOfBoundsException();
        } catch (ArrayIndexOutOfBoundsException e) {
//            System.out.println("你访问的数组的索引不存在");
//            System.out.println(e.getMessage());
            e.printStackTrace();
//            System.out.println(e.toString());
        }
    }

}
