/*
https://www.hackerrank.com/challenges/java-anagrams/problem

Contributed by Bhushan Borole (https://github.com/bhushan-borole)
*/

public static boolean isAnagram(String s, String t){

        return checkHashMaps(characterCount(s), characterCount(t));
    }
public static java.util.HashMap<Character, Integer> characterCount(String inputString)
    {
        //Creating a HashMap containing char as a key and occurrences as  a value

        java.util.HashMap<Character, Integer> charCountMap = new java.util.HashMap<>();

        //Converting given string to char array

        char[] strArray = inputString.toCharArray();

        //checking each char of strArray

        for (char c : strArray)
        {
            if(charCountMap.containsKey(c))
            {
                //If char is present in charCountMap, incrementing it's count by 1

                charCountMap.put(Character.toLowerCase(c), charCountMap.get(c)+1);
            }
            else
            {
                //If char is not present in charCountMap,
                //putting this char to charCountMap with 1 as it's value

                charCountMap.put(Character.toLowerCase(c), 1);
            }
        }

        //Printing the charCountMap
        return charCountMap;

    }

    public static boolean checkHashMaps(java.util.HashMap<Character, Integer> map1, java.util.HashMap<Character, Integer> map2){
        try{
            for (char k : map2.keySet())
            {
                if (!map2.get(k).equals(map1.get(k))) {
                    return false;
                }
            }
            for (char y : map1.keySet())
            {
                if (!map2.containsKey(y)) {
                    return false;
                }
            }
        } catch (NullPointerException np) {
            return false;
        }

        return true;
    }