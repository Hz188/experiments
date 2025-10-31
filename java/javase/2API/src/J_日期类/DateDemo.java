package J_日期类;

import java.util.Date;

public class DateDemo {
    public static void main(String[] args) {
        Date d1 = new Date();
        System.out.println(d1);
        Date d2 = new Date(1000 * 60 * 60L);
        System.out.println(d2);

        System.out.println(d1.getTime() * 1.0 / 1000 / 60 / 60 / 24 / 365);
        System.out.println(System.currentTimeMillis());

        d1.setTime(1000 * 60 * 60L);
        System.out.println(d1);
    }
}
