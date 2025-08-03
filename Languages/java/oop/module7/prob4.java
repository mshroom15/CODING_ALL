
import java.util.Arrays;
import java.util.Scanner;

public class prob4 {
    public static void main(String[] args) {
        int a[]= new int[10];
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter 10 integers:");
        for(int i = 0; i < 10; i++) {
            a[i] = sc.nextInt();
        }
            int sortedValue = sort(a);
            System.out.println("Smallest number so far: " + sortedValue);
            System.out.println("Highest number so far: " + a[9]);
            System.out.println("Average: " + average(a));

        sc.close();

        

    }
    static int sort(int[] arr) {
        Arrays.sort(arr);
        return arr[0];
    }
    static int average(int arr[]) {
        int sum = 0;
        for (int num : arr) {
            sum += num;
        }
        int avg= sum / arr.length;
        return avg;
    }
}