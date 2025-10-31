package E_泛型.B_泛型方法;

//方式1
/*public class Generic{
    public void show(String s){
        System.out.println(s);
    }
    public void show(Integer i){
        System.out.println(i);
    }
    public void show (Boolean b) {
        System.out.println(b);
    }
}*/

//方式2 泛型类
/*public class Generic<T> {
    public void show(T t){
        System.out.println(t);
    }
}*/

//方式三 泛型方法
public class Generic{
    public <T> void show(T t){
        System.out.println(t);
    }
}