package L_返回值.demo2;

public class Main {
    public static void main(String[] args) {
        AnimalOperator ao = new AnimalOperator();
        Animal a = new Dog();
        ao.useAnimal(a);
        Animal animal = ao.getAnimal();
        animal.eat();
    }
}
