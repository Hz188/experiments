package C_practice1;

public class ConverterDemo {
    public static void main(String[] args) {
        //1.
        useConverter(s -> Integer.parseInt(s));
        //2.
        useConverter(Integer::parseInt);

        //Lambda表达式被类方法替代的时候，它的形式参数全部传递给静态方法作为参数
    }

    private static void useConverter(Converter c){
        int x = c.convert("666");
        System.out.println(x);
    }
}
/*
    最初
    1. 接口的实现类
        class ConvertImpl{
            @Override
            int convert(String s){
                return Integer.parseInt(s);
            }
        }


    2. 匿名内部类
        new Converter(){
            @Override
            int convert(String s){
                return Integer.parseInt(s);
            }
        }

    3.Lambda
        s -> Integer.parseInt(s)

    4.method reference
        Integer::parseInt(s)

 */