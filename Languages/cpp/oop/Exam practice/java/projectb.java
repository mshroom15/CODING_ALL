import java.awt.event.*;
import javax.swing.*;


public class projectb extends JFrame implements ActionListener {
    String divisions[] = {"Rajshahi", "Dhaka", "B", "C", "D", "E"};
    int index = 0;
    JLabel l1;
    JButton b1, b2;

    projectb() {
        setTitle("Divisions");
        l1 = new JLabel(divisions[index]);
        l1.setBounds(150, 50, 100, 30);
        b1 = new JButton("Next");
        b1.setBounds(200, 100, 80, 30);
        b2 = new JButton("Previous");
        b2.setBounds(50, 100, 100, 30);
        b1.addActionListener(this);
        b2.addActionListener(this);
        add(b1);
        add(b2);
        add(l1);
        setLayout(null);
        setSize(300, 200);
        setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == b1) {
            index = (index + 1) % divisions.length;
        } else if (e.getSource() == b2) {
            index = (index - 1 + divisions.length) % divisions.length;
        }
        l1.setText(divisions[index]);
    }

    public static void main(String args[]) {
        new projectb();
    }
    
}
