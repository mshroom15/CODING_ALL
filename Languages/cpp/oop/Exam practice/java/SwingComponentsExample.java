import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.*;

public class SwingComponentsExample {
    public static void main(String[] args) {
        // Create JFrame
        JFrame frame = new JFrame("Swing Components Example");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(600, 400);
        frame.setLayout(new FlowLayout());

        // --- Radio Buttons ---
        JRadioButton radio1 = new JRadioButton("Option 1");
        JRadioButton radio2 = new JRadioButton("Option 2");
        // Group them so only one can be selected
        ButtonGroup radioGroup = new ButtonGroup();
        radioGroup.add(radio1);
        radioGroup.add(radio2);

        // --- Checkboxes ---
        JCheckBox check1 = new JCheckBox("Check A");
        JCheckBox check2 = new JCheckBox("Check B");

        // --- JTable inside JScrollPane ---
        String[] columns = {"Name", "Age", "City"};
        Object[][] data = {
                {"Alice", 25, "New York"},
                {"Bob", 30, "London"},
                {"Charlie", 22, "Paris"}
        };
        JTable table = new JTable(new DefaultTableModel(data, columns));
        JScrollPane tableScroll = new JScrollPane(table);
        tableScroll.setPreferredSize(new Dimension(400, 100));

        // --- JList inside JScrollPane ---
        String[] listItems = {"Item 1", "Item 2", "Item 3", "Item 4"};
        JList<String> list = new JList<>(listItems);
        JScrollPane listScroll = new JScrollPane(list);
        listScroll.setPreferredSize(new Dimension(100, 80));

        // --- JComboBox ---
        String[] comboItems = {"Choice 1", "Choice 2", "Choice 3"};
        JComboBox<String> comboBox = new JComboBox<>(comboItems);

        // Add components to frame
        frame.add(radio1);
        frame.add(radio2);
        frame.add(check1);
        frame.add(check2);
        frame.add(tableScroll);
        frame.add(listScroll);
        frame.add(comboBox);

        // Show frame
        frame.setVisible(true);
    }
}
