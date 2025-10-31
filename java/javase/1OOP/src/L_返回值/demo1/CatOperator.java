package L_返回值.demo1;

public class CatOperator {
    public void useCat(Cat c){
        c.eat();
    }

    public Cat getCat(){
        Cat c = new Cat();
        return c;
    }
}
