package I_多态.deom4;

public class AnimalOperator {
    public void useAnimal(Animal a){
        a.eat();
        if (a instanceof Dog){
            ((Dog) a).lookDoor();
        }
    }
}
