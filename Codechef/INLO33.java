//author:somya
//problem:INLO33 

//package algo;
import java.util.*;

public class Main {
public static int distance[] = new int[300];
public static int cost[][] = new int[300][300];
public static int t[] = new int[300];


public static int wait(int distofminpos,int minpos,int k) {

	int next_signal=t[minpos];
	while(distofminpos>next_signal)
		{next_signal+=t[minpos];
	
		}

	return (next_signal-distofminpos);
		
	
}

public static void calc(int n, int s) {
int flag[] = new int[n + 1];
int i, minpos = 1, k, c, minimum;
for (i = 1; i <= n; i++) {
flag[i] = 0;
distance[i] = cost[s][i];
}
c = 2;
while (c <= n) {
minimum = 999;
for (k = 1; k <= n; k++) {
if (distance[k] < minimum && flag[k] != 1) {
minimum = distance[k];

minpos = k;
}
}
flag[minpos] = 1;
c++;
for (k = 1; k <= n; k++) {

if ( distance[minpos]+wait(distance[minpos],minpos,k) +  cost[minpos][k] <  distance[k] && flag[k] != 1)
 distance[k] =  distance[minpos] +cost[minpos][k]+wait(distance[minpos],minpos,k);
}
}
}

public static void main(String args[]) {
	int n,m, source,dest,x, i,j;

Scanner in = new Scanner(System.in);

source = in.nextInt();
dest = in.nextInt();
n = in.nextInt();
m = in.nextInt();
for( x=1;x<=n;++x)
	{t[x]=in.nextInt();
	
	
	}

	
//enter cost matrix by edges
for( x=0;x<m;++x)
{ i= in.nextInt();
j = in.nextInt();
cost[i][j]=in.nextInt();
cost[j][i]=cost[i][j];

	}
for( x=1;x<=n;++x)
	for( int y=1;y<=n;++y)
if (cost[x][y]==0)
	cost[x][y]=cost[y][x]=999;




 calc(n, source);

System.out.println(distance[dest]);
in.close();
}
}
