import java.util.*;
class Heap{
	int[] arr;
	int n;
	int maxn=500000;
	public Heap(int[] a, int size){
		n=size;
		arr=new int[maxn];
		for(int i=0;i<n;i++){
			arr[i]=a[i];
		}
		heapify();
	}

	public Heap(){
		arr=new int[maxn];
		n=0;
	}

	public void heapify(int idx){
		int temp=idx;
		int left=2*idx+1;
		int right=2*idx+2;
		if(left<n && arr[left]<arr[temp]){
			temp=left;
		}
		if(right<n && arr[right]<arr[temp]){
			temp=right;
		}
		if(temp!=idx){
			int pp=arr[idx];
			arr[idx]=arr[temp];
			arr[temp]=pp;
			heapify(temp);	
		}
	}

	public void heapify(){
		int max=(n/2)-1;
		for(int i=max;i>=0;i--){
			heapify(i);
		}
	}

	public int extractmin(){
		int temp=arr[0];
		arr[0]=arr[n-1];
		n--;
		heapify(0);
		return temp;
	}

	public void insert(int num){
		arr[n]=num;
		int idx=n;
		n++;
		int temp;
		while(arr[idx]<arr[(idx-1)/2]){
			temp=arr[idx];
			arr[idx]=arr[(idx-1)/2];
			arr[(idx-1)/2]=temp;
			idx=(idx-1)/2;
		}
	}
}

public class HeapDS{
	public static void main(String[] args) {
		/*PriorityQueue<Integer> pq = new PriorityQueue<Integer>();
		//PriorityQueue<Integer> pq = new PriorityQueue<Integer>(Collections.reverseOrder()); //for max-Heap
		pq.add(30);
		pq.add(10);
		pq.add(20);
		for(Integer i:pq){
			System.out.println(i);
		}
		System.out.println(pq.poll());
		System.out.println(pq.poll());
		System.out.println(pq.poll());*/
		Heap h1=new Heap();
		h1.insert(5);
		h1.insert(0);
		h1.insert(3);
		h1.insert(4);
		h1.insert(1);
		h1.insert(6);
		h1.insert(2);
		for(int i=0;i<7;i++){
			System.out.println(h1.extractmin());
		}
		int[] arr={0,3,6,4,5,1,2};
		Heap h2=new Heap(arr,7);
		for(int i=0;i<7;i++){
			System.out.println(h2.extractmin());
		}
	}
}