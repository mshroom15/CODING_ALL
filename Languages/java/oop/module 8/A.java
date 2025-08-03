import java.util.Scanner;
public class A {
    private int ax;
    public A(int ax) {
        this.ax = ax;
    }
    class B {
        private int bx;
        public B(int bx) {
            this.bx = bx;
        }
        public int sum() {
            return ax + bx;
        }
    }
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter ax: ");
        int ax = input.nextInt();
        System.out.print("Enter bx: ");
        int bx = input.nextInt();
        A outer = new A(ax);
        A.B inner = outer.new B(bx);
        System.out.println("Sum of ax and bx: " + inner.sum());
        input.close();
    }
}