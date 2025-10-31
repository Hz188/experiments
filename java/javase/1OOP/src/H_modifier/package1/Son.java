package H_modifier.package1;


public class Son extends Father {

    public static void main(String[] args) {
//        不能用private
        Son s = new Son();
        s.show2();
        s.show3();
        s.show4();
    }
}
