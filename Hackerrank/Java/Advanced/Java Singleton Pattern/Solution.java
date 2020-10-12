import java.util.Scanner;
import java.lang.reflect.*;

class Singleton {

    public String str;
    private static Singleton singleInstance = new Singleton();

    private Singleton() {}

    static Singleton getSingleInstance() {
        return singleInstance;
    }

}
