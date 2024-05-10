package A_函数式接口注解;

public class Test {
    public static void main(String[] args) {
        MyInterface my = () -> System.out.println("show");
        my.show();
    }
}
