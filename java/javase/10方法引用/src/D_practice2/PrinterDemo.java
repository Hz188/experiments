package D_practice2;

public class PrinterDemo {
    public static void main(String[] args) {
        //1.
        usePrinter(s -> System.out.println(s.toUpperCase()));

        //2.
        PrintString ps = new PrintString();
        usePrinter(ps::printUpper);

        //Lambda表达式被对象的实例方法替代的时候，它的形式参数全部传递给该方法
    }

    private static void usePrinter(Printer p) {
        p.pritnUpperCase("HelloWorld");
    }
}
