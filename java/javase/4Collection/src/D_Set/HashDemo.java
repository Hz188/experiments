package D_Set;

public class HashDemo {
    public static void main(String[] args) {
        Student s1 = new Student("林青霞",30);

        //同一个对象hash值相同
        System.out.println(s1.hashCode()); //1239731077
        System.out.println(s1.hashCode()); //1239731077

        Student s2 = new Student("林青霞",30);
        //不同对象hash值不相同
        System.out.println(s2.hashCode()); //557041912
        System.out.println("----------");


        System.out.println("hello".hashCode()); //99162322
        System.out.println("world".hashCode()); //113318802
        System.out.println("java".hashCode()); //3254818
        System.out.println("world".hashCode()); //113318802
        System.out.println("----------");


        System.out.println("重地".hashCode()); //1179395
        System.out.println("通话".hashCode()); //1179395
        System.out.println("中国".hashCode()); //642672
        System.out.println("洛阳".hashCode()); //904312


    }
}
