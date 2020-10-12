/* ************************************************************************** */
/* --------------------------- begin locked code ---------------------------- */
import java.util.*;

class Person {
    protected String firstName;
    protected String lastName;
    protected int idNumber;

    // Constructor
    Person(String firstName, String lastName, int identification){
        this.firstName = firstName;
        this.lastName = lastName;
        this.idNumber = identification;
    }

    // Print person data
    public void printPerson(){
         System.out.println(
                "Name: " + lastName + ", " + firstName
            + 	"\nID: " + idNumber);
    }

}
/* ---------------------------- end locked code ----------------------------- */
/* ************************************************************************** */

class Student extends Person {

    private int[] testScores;

    Student(String firstName, String lastName, int id, int[] scores) {
        super(firstName, lastName, id);
        testScores = scores;
    }

    /* Returns a character denoting the student's grade */
    char calculate() {
        int sum = 0;
        for (int i : testScores) {
            sum += i;
        }

        double average = (double) sum / testScores.length;

        /* In a real application, cutoff scores for each grade should be saved
         * as constants elsewhere; here, it's not worth the effort */
        if (average >= 90) {
            return 'O';
        } else if (average >= 80) {
            return 'E';
        } else if (average >= 70) {
            return 'A';
        } else if (average >= 55) {
            return 'P';
        } else if (average >= 40) {
            return 'D';
        } else {
            return 'T';
        }
    }

}

/* ************************************************************************** */
/* --------------------------- begin locked code ---------------------------- */
class Solution {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String firstName = scan.next();
        String lastName = scan.next();
        int id = scan.nextInt();
        int numScores = scan.nextInt();
        int[] testScores = new int[numScores];
        for(int i = 0; i < numScores; i++){
            testScores[i] = scan.nextInt();
        }
        scan.close();

        Student s = new Student(firstName, lastName, id, testScores);
        s.printPerson();
        System.out.println("Grade: " + s.calculate());
    }
}
/* ---------------------------- end locked code ----------------------------- */
/* ************************************************************************** */
