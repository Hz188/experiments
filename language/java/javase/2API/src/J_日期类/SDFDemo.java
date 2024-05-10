package J_日期类;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

public class SDFDemo {
    public static void main(String[] args) throws ParseException {
        Date d = new Date();
//        SimpleDateFormat sdf = new SimpleDateFormat();
        SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");

        String s = sdf.format(d);
        System.out.println(s);

        String ss = "2020-07-17 11:11:11";
        SimpleDateFormat sdf2 = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");

        Date dd = sdf2.parse(ss);
        System.out.println(dd);
    }
}

/*
是一个具体的类，用于以区域设置敏感的方式格式化信息和解析信息，重点学习日期格式化和解析
    y 年
    M 月
    d 日
    H 时
    m 分
    s 秒
格式化
    Date -> String
        public final String format(Date d)
    String -> Date
        public Date parse(String source)
*/