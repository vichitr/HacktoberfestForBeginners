/* ************************************************************************** */
/* --------------------------- begin locked code ---------------------------- */
import java.util.*;
import java.io.*;

class BiCycle{
	String define_me(){
		return "a vehicle with pedals.";
	}
}

class MotorCycle extends BiCycle{
	String define_me(){
		return "a cycle with an engine.";
	}

	MotorCycle(){
		System.out.println("Hello I am a motorcycle, I am "+ define_me());
/* ---------------------------- end locked code ----------------------------- */
/* ************************************************************************** */

		String temp = super.define_me();

/* ************************************************************************** */
/* --------------------------- begin locked code ---------------------------- */
		System.out.println("My ancestor is a cycle who is "+ temp );
	}

}
class Solution{
	public static void main(String []args){
		MotorCycle M=new MotorCycle();
	}
}
/* ---------------------------- end locked code ----------------------------- */
/* ************************************************************************** */
