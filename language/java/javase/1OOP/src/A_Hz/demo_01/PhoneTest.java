package A_Hz.demo_01;

public class PhoneTest {
    public static void main(String[] args) {
        Phone p = new Phone();
        p.setName("Apple");
        p.setPrice(5000);

        System.out.println(p);
        p.call();
        p.sendMsg();
    }
}
