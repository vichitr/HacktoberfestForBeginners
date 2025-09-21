
public class MultiplyTwoLargeNumbers {
    public static void main(String[] args)
    {
        String str1 = "1235421415454545454545454544";
        String str2 = "1714546546546545454544548544544545";

        if ((str1.charAt(0) == '-' || str2.charAt(0) == '-') && (str1.charAt(0) != '-' || str2.charAt(0) != '-'))
            System.out.print("-");

        if (str1.charAt(0) == '-' && str2.charAt(0) != '-')
        {
            str1 = str1.substring(1);
        }
        else if (str1.charAt(0) != '-' && str2.charAt(0) == '-')
        {
            str2 = str2.substring(1);
        }
        else if (str1.charAt(0) == '-' && str2.charAt(0) == '-')
        {
            str1 = str1.substring(1);
            str2 = str2.substring(1);
        }
        System.out.println("Product of " + str1 + " and " + str2 + " = " + multiply(str1, str2));
    }

    static String multiply(String str1, String str2)
    {
        int len1 = str1.length();
        int len2 = str2.length();
        if (len1 == 0 || len2 == 0)
            return "0";

        int result[] = new int[len1 + len2];

        int i_n1 = 0;
        int i_n2 = 0;

        for (int i = len1 - 1; i >= 0; i--)
        {
            int carry = 0;
            int n1 = str1.charAt(i) - '0';

            i_n2 = 0;

            for (int j = len2 - 1; j >= 0; j--)
            {
                int n2 = str2.charAt(j) - '0';
                int sum = n1 * n2 + result[i_n1 + i_n2] + carry;
                carry = sum / 10;
                result[i_n1 + i_n2] = sum % 10;
                i_n2++;
            }

            if (carry > 0)
                result[i_n1 + i_n2] += carry;

            i_n1++;
        }

        int i = result.length - 1;
        while (i >= 0 && result[i] == 0)
            i--;

        if (i == -1)
            return "0";

        String s = "";

        while (i >= 0)
            s += (result[i--]);

        return s;
    }
}
