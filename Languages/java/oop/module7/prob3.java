
import java.util.Scanner;

public class prob3 {
    public static void main(String[] args) {
        int a,b;
        Scanner sc = new Scanner(System.in);
        a=sc.nextInt();
        b=sc.nextInt();
        if(a>b) {
            System.out.println(a +" is greater than "+b);
        } else if(a<b) {
            System.out.println(b +" is greater than "+a);
        } else {
            System.out.println(a +" is equal to "+b);
        }
        sc.close();
    }
}
