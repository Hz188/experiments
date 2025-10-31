package A_Hz.demo_01;

public class Phone {
    private int price;
    private String brand;

    public int getPrice() {
        return price;
    }

    public void setPrice(int price) {
        this.price = price;
    }

    public String getName() {
        return brand;
    }

    public void setName(String name) {
        this.brand = name;
    }

    public void call(){
        System.out.println("ring me up.");
    }

    public void sendMsg(){
        System.out.println("Send a msg.");
    }

    @Override
    public String toString() {
        return "Phone{" +
                "price=" + price +
                ", brand='" + brand + '\'' +
                '}';
    }
}
