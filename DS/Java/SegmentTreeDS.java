import java.util.*;
class SegmentTree{
	int segment[];
	int n;
	int arr[];
	int arr_size;
	int int_max=Integer.MAX_VALUE, int_min=Integer.MIN_VALUE;

	public SegmentTree(int size, int[] l){
		int temp_size=nearest_power_2(size);
		//System.out.println("temp_size = "+temp_size);
		int temp_arr[]=new int[temp_size];
		arr=new int[size];
		n=2*temp_size-1;
		arr_size=temp_size;
		segment=new int[n];
		for(int i=0;i<size;i++){
			temp_arr[i]=l[i];
			arr[i]=l[i];
		}
		for(int i=size;i<temp_size;i++){
			temp_arr[i]=0;			//change this to int_max for min_range query and int_min for max_range query
			//temp_arr[i]=int_max;
			//temp_arr[i]=int_min;
		}
		
		construct_sum(temp_arr,0,temp_size-1,0);
		//construct_min(temp_arr,0,temp_size-1,0);
		//construct_max(temp_arr,0,temp_size-1,0);
	}

	//------------------------------------------------------------------------------

	public void construct_sum(int[] arr, int low, int high, int pos){
		if(low==high){
			segment[pos]=arr[low];
		}
		else{
			int mid=(low+high)/2;
			construct_sum(arr,low,mid,2*pos+1);
			construct_sum(arr,mid+1,high,2*pos+2);
			segment[pos]=segment[2*pos+1]+segment[2*pos+2];
		}
	}

	public int sum_query(int left, int right){
		return sum_query(left,right,0,arr_size-1,0);
	}

	public int sum_query(int l, int r, int low, int high, int pos){
		if(l<=low && r>=high){		//total overlap
			return segment[pos];
		}
		else if(r<low || l>high){	//no overlap
			return 0;
		}
		else{						//partial overlap
			int mid=(low+high)/2;
			return sum_query(l,r,low,mid,2*pos+1)+sum_query(l,r,mid+1,high,2*pos+2);
		}
	}

	public void update_sum(int i, int new_val){
		update_sum(i,new_val,0,arr_size-1,0);
	}

	public void update_sum(int i, int x, int low, int high, int pos){
		if(low<=i && i<=high){
			if(low!=high){
				int mid=(low+high)/2;
				update_sum(i,x,low,mid,2*pos+1);
				update_sum(i,x,mid+1,high,2*pos+2);
				segment[pos]=segment[2*pos+1]+segment[2*pos+2];
			}
			else{
				arr[low]=x;
				segment[pos]=x;
			}
		}
	}

	//-----------------------------------------------------------------------------------

	public void construct_min(int[] arr, int low, int high, int pos){
		if(low==high){
			segment[pos]=arr[low];
		}
		else{
			int mid=(low+high)/2;
			construct_min(arr,low,mid,2*pos+1);
			construct_min(arr,mid+1,high,2*pos+2);
			segment[pos]=Math.min(segment[2*pos+1],segment[2*pos+2]);
		}
	}

	public int min_query(int left, int right){
		return min_query(left,right,0,arr_size-1,0);
	}

	public int min_query(int l, int r, int low, int high, int pos){
		if(l<=low && r>=high){		//total overlap
			return segment[pos];
		}
		else if(r<low || l>high){	//no overlap
			return int_max;
		}
		else{						//partial overlap
			int mid=(low+high)/2;
			return Math.min(min_query(l,r,low,mid,2*pos+1),min_query(l,r,mid+1,high,2*pos+2));
		}
	}

	public void update_min(int i, int new_val){
		update_min(i, new_val,0,arr_size-1,0);
	}

	public void update_min(int i, int x, int low, int high, int pos){
		if(low<=i && i<=high){
			if(low!=high){
				int mid=(low+high)/2;
				update_min(i,x,low,mid,2*pos+1);
				update_min(i,x,mid+1,high,2*pos+2);
				segment[pos]=Math.min(segment[2*pos+1],segment[2*pos+2]);
			}
			else{
				arr[i]=x;
				segment[pos]=x;
			}
		}
	}

	//---------------------------------------------------------------------------------------

	public void construct_max(int[] arr, int low, int high, int pos){
		if(low==high){
			segment[pos]=arr[low];
		}
		else{
			int mid=(low+high)/2;
			construct_max(arr,low,mid,2*pos+1);
			construct_max(arr,mid+1,high,2*pos+2);
			segment[pos]=Math.max(segment[2*pos+1],segment[2*pos+2]);
		}
	}

	public int max_query(int left, int right){
		return max_query(left,right,0,arr_size-1,0);
	}

	public int max_query(int l, int r, int low, int high, int pos){
		if(l<=low && r>=high){		//total overlap
			return segment[pos];
		}
		else if(r<low || l>high){	//no overlap
			return int_min;
		}
		else{						//partial overlap
			int mid=(low+high)/2;
			return Math.max(max_query(l,r,low,mid,2*pos+1),max_query(l,r,mid+1,high,2*pos+2));
		}
	}

	public void update_max(int i, int new_val){
		update_max(i, new_val,0,arr_size-1,0);
	}

	public void update_max(int i, int x, int low, int high, int pos){
		if(low<=i && i<=high){
			if(low!=high){
				int mid=(low+high)/2;
				update_max(i,x,low,mid,2*pos+1);
				update_max(i,x,mid+1,high,2*pos+2);
				segment[pos]=Math.max(segment[2*pos+1],segment[2*pos+2]);
			}
			else{
				arr[i]=x;
				segment[pos]=x;
			}
		}
	}

	//-----------------------------------------------------------------------------------------

	public int nearest_power_2(int x){
		int ans=1;
		while(ans<x){
			ans*=2;
		}
		return ans;
	}
}
public class SegmentTreeDS{
	public static void main(String[] args) {
		int arr[]={3,1,2,5,-1};
		SegmentTree s1=new SegmentTree(5,arr);
		for(int i=0;i<5;i++){
			for(int j=i;j<5;j++){
				System.out.println(i+" "+j+" "+s1.sum_query(i,j));
			}
		}
		System.out.println();
		s1.update_sum(0,-100);
		for(int i=0;i<5;i++){
			for(int j=i;j<5;j++){
				System.out.println(i+" "+j+" "+s1.sum_query(i,j));
			}
		}
	}
}