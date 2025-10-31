package E_inheritance.overridedemo;

public class PhoneTest {
    public static void main(String[] args) {
        Phone p = new Phone();
        p.call("me");
        System.out.println("-------");
        NewPhone np = new NewPhone();
        np.call("you");
    }
}
