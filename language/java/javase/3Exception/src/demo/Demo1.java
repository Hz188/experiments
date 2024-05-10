package demo;

public class Demo1 {
    public static void main(String[] args) {
        System.out.println("start");
        method();
        System.out.println("end");
    }

    public static void method() {
        int[] arr = {1, 2, 3};
//        System.out.println(arr[1]);
        System.out.println(arr[3]);
    }

}
/*
start
Exception in thread "main" java.lang.ArrayIndexOutOfBoundsException: Index 3 out of bounds for length 3
	at demo.demo1.method(demo1.java:13)
	at demo.demo1.main(demo1.java:6)

*/