import java.util.*;
import java.util.Scanner;
import java.io.*;

class Process /*implements Comparable<Process>*/
{
	int arr_t, bur_t, comp_t, tat, wait_t, flag, bur_t2, st_t;
	int pro_id;

	public Process(int pro_id , int arr_t, int bur_t){
		this.pro_id = pro_id;
		this.arr_t = arr_t;
		this.bur_t = bur_t;
		this.flag=0;
		this.bur_t2 = this.bur_t;
	}

	/*public int compareTo(Process m) 
    { 
        return this.arr_t - m.arr_t; 
    } */

	public int getArrTime() { return arr_t; } 

	public int getStartTime() { return st_t; } 
}

class Order
{
	int pro_id, st_t, end_t;

	public Order(int pro_id , int st_t, int end_t){
		this.pro_id = pro_id;
		this.st_t = st_t;
		this.end_t = end_t;
	}
}

class ArrTimeCompare implements Comparator<Process> 
{ 
    public int compare(Process p1, Process p2) 
    { 
        if (p1.getArrTime() < p2.getArrTime()) return -1; 
        if (p1.getArrTime() > p2.getArrTime()) return 1; 
        else return 0; 
    } 
} 

class StartTimeCompare implements Comparator<Process> 
{ 
    public int compare(Process p1, Process p2) 
    { 
        if (p1.getStartTime() < p2.getStartTime()) return -1; 
        if (p1.getStartTime() > p2.getStartTime()) return 1; 
        else return 0; 
    } 
}

public class sjf
{
	static void nonPreEmptive(List<Process> p, int n){
		System.out.println("Non-preemptive version");
		//boolean a = true;
		int st=0, tot=0;
		float avgwt=0, avgta=0;
		while(true)
		{
			int c=n, min=999;
			if (tot == n) // total no of process = completed process loop will be terminated
				break;
			
			for (int i=0; i<n; i++)
			{
				Process curP = p.get(i);
				/*
				 * If i'th process arrival time <= system time and its flag=0 and burst<min 
				 * That process will be executed first 
				 */ 
				if ((curP.arr_t <= st) && (curP.flag == 0) && (curP.bur_t < min))
				{
					min=curP.bur_t;
					c=i;
				}
			}
			
			/* If c==n means c value can not updated because no process arrival time< system time so we increase the system time */
			if (c==n) 
				st++;
			else
			{
				Process P = p.get(c);
				P.st_t = st;
				P.comp_t = st + P.bur_t;
				st += P.bur_t;
				P.tat = P.comp_t - P.arr_t;
				P.wait_t = P.tat - P.bur_t;
				P.flag = 1;
				tot++;
			}
		}
		
		System.out.println("\nPID  Arrival  Burst  Completion  TurnAround  Waiting");
		for(int i=0; i<n; i++)
		{
			Process P = p.get(i);
			avgwt += P.wait_t;
			avgta += P.tat;
			System.out.println(" " + P.pro_id + "\t" + P.arr_t + "\t" + P.bur_t + "\t" + P.comp_t + "\t\t" + P.tat + "\t" + P.wait_t);
		}
		System.out.println ("\nAverage Turn Around Time is " + (float)(avgta/n));
		System.out.println ("Average Waiting Time is " + (float)(avgwt/n));
		StartTimeCompare stTimeCompare = new StartTimeCompare();
		Collections.sort(p, stTimeCompare);
		System.out.println("------------------------------------------GANTT CHART----------------------------------------------");
		System.out.print("||\t");
		for(int i=0;i<n;i++){
			Process P = p.get(i);
			System.out.print(P.comp_t - P.bur_t + " -P" + P.pro_id + "- " + P.comp_t);
			System.out.print("\t||\t"); 
		}
		System.out.println("\n---------------------------------------------------------------------------------------------------");
		System.out.println("\n");
	}

	static void preEmptive(List<Process> p, int n){
		System.out.println("Preemptive version");
		List<Order> o = new ArrayList<Order>();
		int i, st=0, tot=0;
	    float avgwt=0, avgta=0;
	    int pre_c = n;
	    int idle = 0;
	    while(true){
	    	int min = 999, c = n;
	    	if (tot == n)
	    		break;
	    	
	    	for (i=0; i<n; i++)
	    	{
	    		Process curP = p.get(i);
	    		if ((curP.arr_t <= st) && (curP.flag == 0) && (curP.bur_t < min))
	    		{	
	    			min = curP.bur_t;
	    			c=i;
	    		}
	    	}
	    	
	    	if (c==n){
	    		if(pre_c != n){
	    			idle++;
	    		}
	    		st++;
	    	}
	    	else{
	    		Process P = p.get(c);
	    		if(pre_c != c){
	    			if(pre_c != n){
	    				Order e = o.get(o.size() - 1);
	    				e.end_t = st;
	    				if(idle != 0){
	    					e.end_t = st - idle;
	    				}
	    			}
	    			o.add(new Order(P.pro_id, st, 0));
	    		}

	    		P.bur_t--;
	    		st++;
	    		if (P.bur_t == 0){
	    			P.comp_t =  st;
	    			P.flag = 1;
	    			tot++;
	    		}
	    		pre_c = c;
	    		idle = 0;
	    	}
	    }
	    o.get(o.size() - 1).end_t = st;
	    for(i=0;i<n;i++)
	    {
	    	Process P = p.get(i);
	    	P.tat = P.comp_t - P.arr_t;
	    	P.wait_t = P.tat - P.bur_t2;
	    	avgwt += P.wait_t;
	    	avgta += P.tat;
	    }
	    System.out.println("\nPID  Arrival  Burst  Completion  TurnAround  Waiting");
		for(i=0; i<n; i++)
		{
			Process P = p.get(i);
			System.out.println(" " + P.pro_id + "\t" + P.arr_t + "\t" + P.bur_t2 + "\t" + P.comp_t + "\t\t" + P.tat + "\t" + P.wait_t);
		}
	    System.out.println ("\nAverage Turn Around Time is " + (float)(avgta/n));
		System.out.println ("Average Waiting Time is " + (float)(avgwt/n));
		System.out.println("----------------------------------------------------------GANTT CHART--------------------------------------------------------------");
		System.out.print("||\t");
		for(i=0;i<o.size();i++){
			Order O = o.get(i);
			System.out.print(O.st_t + " -P" + O.pro_id + "- " + O.end_t);
			System.out.print("\t||\t"); 
		}
		System.out.println("\n-----------------------------------------------------------------------------------------------------------------------------------");
		System.out.println("\n");
	}

	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int arr, burst, pid, sel;
		System.out.print("Enter the number of process:\t");
		int n = sc.nextInt();
		List<Process> p = new ArrayList<Process>();
		//Process p[] = new Process[n];
		System.out.print("\nEnter the arrival time and burst time of each process::\n");
		for(int i=0;i<n;i++){
			System.out.print("P" + (i+1) + "\tArrival Time: ");
			arr = sc.nextInt();
			System.out.print("\tBurst Time: ");
			burst = sc.nextInt();
			pid = i+1;
			p.add(new Process(pid, arr, burst)); 
			//p[i] = new Process(pid, arr, burst);
		}
		System.out.println("Sorted by Arrival time");
		ArrTimeCompare arTimeCompare = new ArrTimeCompare();
		Collections.sort(p, arTimeCompare); 
		for (Process pr : p) 
            System.out.println(pr.pro_id + " " + 
                               pr.arr_t + " " + 
                               pr.bur_t);
		//for(int i=0;i<n;i++){
			//System.out.println(p[i].pro_id + " " + p[i].arr_t + " " + p[i].bur_t);
		//}
		
		System.out.println("Select among 1 and 2: ");
		System.out.println("1. Non-preemptive\n2. Pre-emptive");
		sel = sc.nextInt();
		if (sel==1){
			nonPreEmptive(p, n);
		}
		else if (sel==2){	
			preEmptive(p, n);
		}
	}
}