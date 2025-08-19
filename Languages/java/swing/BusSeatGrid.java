import java.awt.*;
import javax.swing.*;

public class BusSeatGrid {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Bus Seat Plan");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(600, 400);

        // 8 rows, 5 columns (1 for 'driver', 3 seats, 1 gap at end or between seats)
        JPanel gridPanel = new JPanel(new GridLayout(8, 4, 10, 10)); // gaps: 10px
        String[] rows = {"A","B","C","D","E","F","G","H"};

        for (String r : rows) {
            gridPanel.add(new JButton(r + "1"));
            // Column 3: Smaller invisible label or a space for gap
            gridPanel.add(new JLabel(""));
            // Column 4: Seat 2
            gridPanel.add(new JButton(r + "2"));
            // Column 5: Seat 3
            gridPanel.add(new JButton(r + "3"));
        }

        // Add a row at the top or bottom for "driver" if needed
        frame.add(gridPanel, BorderLayout.CENTER);
        frame.setVisible(true);
    }
}
