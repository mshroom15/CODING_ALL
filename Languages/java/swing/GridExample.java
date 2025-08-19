import java.awt.GridLayout;
import javax.swing.*;

public class GridExample {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Grid Example");
        frame.setLayout(new GridLayout(3, 3)); // rows, columns

        for (int i = 1; i <= 9; i++) {
            frame.add(new JButton("Seat " + i));
        }

        frame.setSize(400, 300);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}
