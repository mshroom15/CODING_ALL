public class annonymous_object {
    static class Point {
        int x, y;

        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public String toString() {
            return "Point(" + x + ", " + y + ")";
        }
    }

    /**
     * Accepts two Point objects and returns a new Point object representing their midpoint.
     * The returned object is created "anonymously" as it is instantiated and returned
     * in the same statement.
     *
     * @param p1 The first point.
     * @param p2 The second point.
     * @return The midpoint.
     */
    public static Point midPoint(Point p1, Point p2) {
        return new Point((p1.x + p2.x) / 2, (p1.y + p2.y) / 2);
    }

    public static void main(String[] args) {
        Point point1 = new Point(10, 20);
        Point point2 = new Point(30, 40);

        // The object returned by midPoint is created without a reference variable inside the method
        Point mid = midPoint(point1, point2);

        System.out.println("Midpoint is: " + mid); // Expected: Point(20, 30)
    }
}
