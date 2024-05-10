package L_返回值.demo1;

public class Main {
    public static void main(String[] args) {
        CatOperator co = new CatOperator();
        co.useCat(new Cat());
        Cat cat = co.getCat();
        cat.eat();
    }
}
