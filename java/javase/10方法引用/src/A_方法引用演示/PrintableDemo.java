package A_方法引用演示;

public class PrintableDemo {
    public static void main(String[] args) {
        //1.
        usePrintable(s -> System.out.println(s));

        //2.我们知道打印这个方法已经存在了，不必再写一遍了
        //方法引用符 ::
        usePrintable(System.out::println);
        //一个原则：可推导的就是可省略的
    }

    private static void usePrintable(Printable p) {
        p.printString("爱生活，爱Java");
    }
}
