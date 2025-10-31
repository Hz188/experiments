package E_泛型.C_泛型接口;

public class Test {
    public static void main(String[] args) {
        Generic<String> g1 = new GenericImpl<>();
        g1.show("hello");
        Generic<Integer> g2 = new GenericImpl<>();
        g2.show(100);
    }
}
