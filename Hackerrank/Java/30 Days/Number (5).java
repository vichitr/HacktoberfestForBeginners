/* ************************************************************************** */
/* --------------------------- begin locked code ---------------------------- */
import java.io.*;
import java.util.*;
/* ---------------------------- end locked code ----------------------------- */
/* ************************************************************************** */

public class Person {

    /* Inclusive limits for the defined age ranges */
    private static final int YOUNG_MAX = 12;
    private static final int TEEN_MIN = 13;
    private static final int TEEN_MAX = 17; // interesting definition of "teen"

    private int age;

    public Person(int initialAge) {
        if (initialAge < 0) {
            System.out.println("Age is not valid, setting age to 0.");
            age = 0;
        } else {
            age = initialAge;
        }
    }

    public void amIOld() {
        String answer;

        if (age <= YOUNG_MAX) {
            answer = "You are young.";
        } else if (TEEN_MIN <= age && age <= TEEN_MAX) {
            answer = "You are a teenager.";
        } else {
            answer = "You are old.";
        }

        System.out.println(answer);
    }

    public void yearPasses() {
        age++;
    }

/* ************************************************************************** */
/* --------------------------- begin locked code ---------------------------- */
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int i = 0; i < T; i++) {
            int age = sc.nextInt();
            Person p = new Person(age);
            p.amIOld();
            for (int j = 0; j < 3; j++) {
                p.yearPasses();
            }
            p.amIOld();
            System.out.println();
        }
        sc.close();
    }
}
/* ---------------------------- end locked code ----------------------------- */
/* ************************************************************************** */
