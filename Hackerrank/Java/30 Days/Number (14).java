/* ************************************************************************** */
/* --------------------------- begin locked code ---------------------------- */
import java.util.*;

abstract class Book {
    String title;
    String author;

    Book(String title, String author) {
        this.title = title;
        this.author = author;
    }

    abstract void display();
}
/* ---------------------------- end locked code ----------------------------- */
/* ************************************************************************** */

class MyBook extends Book {

    private int price;

    MyBook(String title, String author, int price) {
        super(title, author);
        this.price = price;
    }

    void display() {
        System.out.print("Title: "  + title  + "\n"
                       + "Author: " + author + "\n"
                       + "Price: "  + price  + "\n");
    }

}

/* ************************************************************************** */
/* --------------------------- begin locked code ---------------------------- */
public class Solution {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String title = scanner.nextLine();
        String author = scanner.nextLine();
        int price = scanner.nextInt();
        scanner.close();

        Book book = new MyBook(title, author, price);
        book.display();
    }
}
/* ---------------------------- end locked code ----------------------------- */
/* ************************************************************************** */
