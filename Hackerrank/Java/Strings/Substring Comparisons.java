/*
https://www.hackerrank.com/challenges/java-string-compare/problem

Contributed by Bhushan Borole (https://github.com/bhushan-borole)
*/

public static String getSmallestAndLargest(String s, int k) {
    String [] arr = new String[s.length()-k+1];

    for (int i = 0; i <= s.length() - k; i++) {
        String substr = s.substring(i, i + k);
        if (substr.matches("[a-zA-Z]+")) { arr[i] = substr; }
    }
    boolean isSwapped = false;
    do {
        isSwapped = false;
        for(int i=0;i<arr.length-1;i++){
            if(arr[i].compareTo(arr[i+1])>0){
                String temp = arr[i+1];
                arr[i+1] = arr[i];
                arr[i] = temp;
                isSwapped = true;
            }
        }
    }while((isSwapped));

    return arr[0] + "\n" + arr[arr.length-1];
}