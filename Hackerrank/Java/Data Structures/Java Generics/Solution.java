/* ************************************************************************** */
/* --------------------------- begin locked code ---------------------------- */

import java.io.IOException;
import java.lang.reflect.Method;
/* ---------------------------- end locked code ----------------------------- */
/* ************************************************************************** */

class Printer {

    static <E> void printArray(E[] array) {
        if (array == null || array.length == 0) {
            return;
        }

        for (E element : array) {
            System.out.println(element);
        }
    }

}

/* ************************************************************************** */
/* --------------------------- begin locked code ---------------------------- */
public class Solution {


    public static void main( String args[] ) {
        Printer myPrinter = new Printer();
        Integer[] intArray = { 1, 2, 3 };
        String[] stringArray = {"Hello", "World"};
        myPrinter.printArray(intArray);
        myPrinter.printArray(stringArray);
        int count = 0;

        for (Method method : Printer.class.getDeclaredMethods()) {
            String name = method.getName();

            if(name.equals("printArray"))
                count++;
        }

        if(count > 1)System.out.println("Method overloading is not allowed!");

    }
}
/* ---------------------------- end locked code ----------------------------- */
/* ************************************************************************** */
