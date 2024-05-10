package E_泛型.B_泛型方法;

public class Test {
    public static void main(String[] args) {
        //1.
//        Generic g = new Generic();
//        g.show("haozhe");
//        g.show(100);
//        g.show(true);

        //2.
//        Generic<String> g1 = new Generic<>();
//        g1.show("haozhe");
//        Generic<Integer> g2 = new Generic<>();
//        g2.show(100);
//
//        Generic<Boolean> g3 = new Generic<>();
//        g3.show(true);

        //3.
        Generic g = new Generic();
        g.show(100);
        g.show("hello");
        g.show(true);

    }
}
