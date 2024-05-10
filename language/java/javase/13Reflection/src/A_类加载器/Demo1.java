package A_类加载器;

public class Demo1 {
    public static void main(String[] args) {
        ClassLoader c =  ClassLoader.getSystemClassLoader();
        System.out.println(c); //jdk.internal.loader.ClassLoaders$AppClassLoader@1f89ab83

        ClassLoader pc = c.getParent();
        System.out.println(pc);//jdk.internal.loader.ClassLoaders$PlatformClassLoader@7c30a502

        ClassLoader ppc = pc.getParent();
        System.out.println(ppc); //null
    }
}
