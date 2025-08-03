import java.util.Scanner;
class Point {
    int x, y;
    Point(int x, int y) {
        this.x = x;
        this.y = y;
    }
    void display() {
        System.out.println("(" + x + ", " + y + ")");
    }
}
public class anonymousObj {
    public static Point MidPoint(Point a, Point b) {
        return new Point((a.x + b.x) / 2, (a.y + b.y) / 2);
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter x1 and y1: ");
        int x1 = sc.nextInt();
        int y1 = sc.nextInt();
        System.out.print("Enter x2 and y2: ");
        int x2 = sc.nextInt();
        int y2 = sc.nextInt();
        Point p1 = new Point(x1, y1);
        Point p2 = new Point(x2, y2);
        System.out.print("Midpoint: ");
        MidPoint(p1, p2).display();
        sc.close();
    }
}
