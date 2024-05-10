package M_内部类.demo5;

public class Test {
    public static void main(String[] args) {
        JumppingOperator jo = new JumppingOperator();
        jo.useJumpping(new Jumpping() {
            @Override
            public void jump() {
                System.out.println("匿名内部类跳高");
            }
        });
    }
}
