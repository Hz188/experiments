package B_方法引用符;

public class PrintableDemo {
    public static void main(String[] args) {
        //1.
        usePrintable(x -> System.out.println(x));
        //2.
        usePrintable(System.out::println);
    }

    private static void usePrintable(Printable p) {
        p.printInt(666);
    }
}
