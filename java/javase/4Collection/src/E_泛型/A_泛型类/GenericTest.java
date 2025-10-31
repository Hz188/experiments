package E_泛型.A_泛型类;

public class GenericTest {
    public static void main(String[] args) {
        Generic<String> g1 = new Generic<>();
        g1.setT("haohze");
        System.out.println(g1.getT());

        Generic<Integer> g2 = new Generic<>();
        g2.setT(100);
        System.out.println(g2.getT());

    }
}
