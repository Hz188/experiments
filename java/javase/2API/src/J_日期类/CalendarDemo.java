package J_日期类;

import java.util.Calendar;
import java.util.Scanner;

public class CalendarDemo {
    public static void main(String[] args) {
        Calendar now = Calendar.getInstance();//多态
//        System.out.println(now);
        int y = now.get(Calendar.YEAR);
        int m = now.get(Calendar.MONTH) + 1;
        int d = now.get(Calendar.DATE);
        System.out.printf("%d %d %d\n", y, m, d);

        now.add(Calendar.YEAR, 1);
        now.add(Calendar.MONTH, 2);
        now.add(Calendar.DATE, 2);
        y = now.get(Calendar.YEAR);
        m = now.get(Calendar.MONTH) + 1;
        d = now.get(Calendar.DATE);
        System.out.printf("%d %d %d\n", y, m, d);


        now.set(2048, 11, 13);
        y = now.get(Calendar.YEAR);
        m = now.get(Calendar.MONTH) + 1;
        d = now.get(Calendar.DATE);
        System.out.printf("%d %d %d\n", y, m, d);

//        二元天demo
        demo();
    }

    public static void demo() {
        Scanner in = new Scanner(System.in);
        System.out.println("Please input the year number:");
        int year = in.nextInt();
        Calendar c = Calendar.getInstance();
        c.set(year, 2, 1);
        c.add(Calendar.DATE, -1);

        int d = c.get(Calendar.DATE);
        System.out.println(year + "年二月有" + d + "天");

    }
}
/*
Calendar
    为某一时刻和一组日历字段之间的转换提供了一些方法，并为操作日历字段提供了一些方法

    常用方法
        get
        add
        set


*/