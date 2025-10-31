package L_返回值.demo2;

public class AnimalOperator {
    public void useAnimal(Animal a){
        a.eat();
    }
    public Animal getAnimal(){
        return new Dog();
    }
}
