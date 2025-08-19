import java.awt.*;
import javax.swing.*;



public class newapp {
    public static void createAndShowGUI() {
        JFrame frame = new JFrame("Swing Application");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(400, 300);

        JLabel label = new JLabel("Hello, Swing!", SwingConstants.CENTER);
        frame.getContentPane().add(label, BorderLayout.CENTER);

        JButton button = new JButton("Click Me");
        button.addActionListener(e -> JOptionPane.showMessageDialog(frame, "Button Clicked!"));
        frame.getContentPane().add(button, BorderLayout.SOUTH);

        frame.setVisible(true);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(newapp::createAndShowGUI);
    }
}