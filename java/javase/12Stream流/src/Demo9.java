import java.util.ArrayList;
import java.util.stream.Stream;

public class Demo9 {
    public static void main(String[] args) {
        /*
            两个ArrayList集合，分别存6男6女 演员
            男演员要求名字为三个字的前三人
            女演员只要姓林的，并且不要第一个
            把过滤后的男人演员合并在一起
            把上一步操作后的元素作为构造方法的参数，创建演员对象，遍历数据
            演员类Actor已提供，里面有一个成员变量，一个带参构造方法，对应的get/set方法
         */
        ArrayList<String> man = new ArrayList<>();

        man.add("周润发");
        man.add("成龙");
        man.add("刘德华");
        man.add("吴京");
        man.add("周星驰");
        man.add("李连杰");

        ArrayList<String> woman = new ArrayList<>();

        woman.add("林心如");
        woman.add("张曼玉");
        woman.add("林青霞");
        woman.add("柳岩");
        woman.add("林志玲");
        woman.add("王祖贤");

        //分开写
//        Stream<String> manStream = man.stream().filter(s -> s.length() == 3).limit(3);
//        Stream<String> womanStream = woman.stream().filter(s -> s.startsWith("林")).skip(1);
//
//        Stream<String> stream = Stream.concat(manStream, womanStream);
//
//        stream.map(Actor::new).forEach(p-> System.out.println(p.getName()));

        //合并写
        Stream.concat(man.stream().filter(s -> s.length() == 3).limit(3),
                woman.stream()  .filter(s -> s.startsWith("林")).skip(1))
                .map(Actor::new)
                .forEach(p-> System.out.println(p.getName()));



    }
}
