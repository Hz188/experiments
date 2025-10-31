package L_返回值.demo3;

public class Main {
    public static void main(String[] args) {
        JumpOperator jp = new JumpOperator();
        jp.useJump(new Cat());

        Jumpping jumpping = jp.getJumpping();
        jumpping.jump();
    }
}
