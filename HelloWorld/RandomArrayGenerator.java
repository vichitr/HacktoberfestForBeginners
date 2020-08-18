import java.util.concurrent.ThreadLocalRandom;

// Generate a random Java int array with ThreadLocalRandom.  Specify the minimum value, maximum value, and desired length of the array.
public class RandomArrayGenerator {
  public static int[] randomArrayGenerator(int minValue, int maxValue, int arrayLength) {
    int[] arr = new int[arrayLength];
    for (int i = 0; i < arrayLength; i++) {
      int randomInt = ThreadLocalRandom.current().nextInt(minValue, maxValue);
      arr[i] = randomInt;
    }
    return arr;
  }
}