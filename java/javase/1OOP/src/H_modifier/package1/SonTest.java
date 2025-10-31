package H_modifier.package1;

public class SonTest {
    public static void main(String[] args) {

        Father f = new Father();
//        不能用private
        f.show2();
        f.show3();
        f.show4();
//      不能用private
        Son s = new Son();
        s.show2();
        s.show3();
        s.show4();
    }
}
