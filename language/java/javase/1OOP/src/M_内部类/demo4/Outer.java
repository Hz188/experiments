package M_内部类.demo4;

public class Outer {

    public void method() {
        new Inter() {
            @Override
            public void show() {
                System.out.println("匿名内部类");
            }
        }.show();

        //若多次调用
        Inter i = new Inter() {
            @Override
            public void show() {
                System.out.println("匿名内部类");
            }
        };
        i.show();
        i.show();
    }
}
