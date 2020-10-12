/* ************************************************************************** */
/* --------------------------- begin locked code ---------------------------- */
import java.util.*;

class Printer <T> {
/* ---------------------------- end locked code ----------------------------- */
/* ************************************************************************** */

    /* Prints each element of the specified array on a new line. */
    void printArray(T[] array) {
        for (T element : array) {
            System.out.println(element);
        }
    }

/* ************************************************************************** */
/* --------------------------- begin locked code ---------------------------- */
}

public class Generics {

    public static void main(String args[]){
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Integer[] intArray = new Integer[n];
        for (int i = 0; i < n; i++) {
            intArray[i] = scanner.nextInt();
        }

        n = scanner.nextInt();
        String[] stringArray = new String[n];
        for (int i = 0; i < n; i++) {
            stringArray[i] = scanner.next();
        }

        Printer<Integer> intPrinter = new Printer<Integer>();
        Printer<String> stringPrinter = new Printer<String>();
        intPrinter.printArray( intArray  );
        stringPrinter.printArray( stringArray );
        if(Printer.class.getDeclaredMethods().length > 1){
            System.out.println("The Printer class should only have 1 method named printArray.");
        }
    }
}
/* ---------------------------- end locked code ----------------------------- */
/* ************************************************************************** */
