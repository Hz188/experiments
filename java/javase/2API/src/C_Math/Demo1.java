package C_Math;

public class Demo1 {
    public static void main(String[] args) {
        float f = 3.00f;

        System.out.println(Math.nextUp(f));
        System.out.println(Math.nextUp(f) - f);
        System.out.println(Math.ulp(f));

        System.out.println(Math.random());
        System.out.println(Math.abs(-1));
        System.out.println(Math.ceil(1.5));
        System.out.println(Math.floor(1.5));
        System.out.println(Math.round(1.5));
        System.out.println(Math.round(1.4));
        System.out.println(Math.max(1, 2));
        System.out.println(Math.min(1, 2));
        System.out.println(Math.pow(2.0,3));
    }
}
