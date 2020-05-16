//This code is contributed by Shreevatsa N, @vatsa287

package practice;
public class CountingValleys {
	public int getValleyCount(String s)
	{	
		int altitudeCount = 0, valleyCount = 0;
		
		for(int i=0; i<s.length(); i++)
		{
			char ch = s.charAt(i);
			if(ch == 'U')
			{
				altitudeCount++;
				if(altitudeCount == 0) 
				{
					valleyCount++;
				}
			}
			else 
			{
				altitudeCount--;
			}
		}
		return valleyCount;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String s = "UDDDUDUU";		
		CountingValleys obj = new CountingValleys();
		System.out.println("The valley count is "+obj.getValleyCount(s));
	}
}