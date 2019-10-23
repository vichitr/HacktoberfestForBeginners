// C# Program implementing 
// binary insertion sort 
using System; 

class GFG { 
	
	public static void Main() 
	{ 
		int []arr = {37, 23, 0, 17, 12, 72, 31, 
							46, 100, 88, 54 }; 

		sort(arr); 

		for(int i = 0; i < arr.Length; i++) 
			Console.Write(arr[i] + " "); 
	} 

	public static void sort(int []array) 
	{ 
		for (int i = 1; i < array.Length; i++) 
		{ 
			int x = array[i]; 

			// Find location to insert using 
			// binary search 
			int j = Math.Abs(Array.BinarySearch( 
							array, 0, i, x) + 1); 

			// Shifting array to one location right 
			System.Array.Copy(array, j, array, 
										j+1, i-j); 

			// Placing element at its correct 
			// location 
			array[j] = x; 
		} 
	} 
} 
