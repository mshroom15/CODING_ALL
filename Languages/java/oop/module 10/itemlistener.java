import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class itemlistener implements ItemListener {
    JFrame frame;
    JComboBox<String> comboBox;
    JLabel label;

    itemlistener() {
        frame = new JFrame("ItemListener Example");
        frame.setLayout(new FlowLayout());
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(400, 200);

        String[] items = {"--Select--", "Java", "Python", "C++"};
        comboBox = new JComboBox<>(items);
        comboBox.addItemListener(this);

        label = new JLabel("Please select a language.");

        frame.add(comboBox);
        frame.add(label);
        frame.setVisible(true);
    }

    @Override
    public void itemStateChanged(ItemEvent e) {
        // Check if an item has been selected
        if (e.getStateChange() == ItemEvent.SELECTED) {
            String selectedItem = e.getItem().toString();
            
            switch (selectedItem) {
                case "Java":
                    label.setText("You selected Java. It's great for enterprise apps.");
                    break;
                case "Python":
                    label.setText("You selected Python. It's popular in data science.");
                    break;
                case "C++":
                    label.setText("You selected C++. It's powerful for game development.");
                    break;
                default:
                    label.setText("Please select a language.");
                    break;
            }
        }
    }

    public static void main(String[] args) {
        // Run the GUI code on the Event Dispatch Thread
        SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                new itemlistener();
            }
        });
    }
}