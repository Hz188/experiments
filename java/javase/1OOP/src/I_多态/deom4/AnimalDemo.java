package I_多态.deom4;

public class AnimalDemo {
    public static void main(String[] args) {
        AnimalOperator ao = new AnimalOperator();
        ao.useAnimal(new Cat());
        ao.useAnimal(new Dog());
    }
}
