/* ************************************************************************** */
/* --------------------------- begin locked code ---------------------------- */
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

class Animal{
	void walk(){
		System.out.println("I am walking");
	}
}
/* ---------------------------- end locked code ----------------------------- */
/* ************************************************************************** */

class Bird extends Animal {

	void fly() {
		System.out.println("I am flying");
	}

    void sing() {
        System.out.println("I am singing");
    }
}

/* ************************************************************************** */
/* --------------------------- begin locked code ---------------------------- */
public class Solution{

   public static void main(String args[]){

	  Bird bird = new Bird();
	  bird.walk();
	  bird.fly();
      bird.sing();

   }
}
/* ---------------------------- end locked code ----------------------------- */
/* ************************************************************************** */
