public class SwapNumbers {

	public static void main(String[] args) {
		int number1 = 10;//binary = 1010
		int number2 = 15; //binary = 1111
		System.out.println("Number1 before swapping:"+number1);
		System.out.println("Number2 before swapping:"+number2);

		number1 = number1^number2; //number1 = 0101
		number2 = number1^number2; //number2 = 1010
		number1 = number1^number2; //number1 = 1111
		
		System.out.println("Number1 after swapping:"+number1);
        System.out.println("Number2 after swapping:"+number2);
        
	}

}