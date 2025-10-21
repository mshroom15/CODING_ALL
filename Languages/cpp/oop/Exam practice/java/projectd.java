import java.awt.event.*;
import javax.swing.*;

public class projectd extends JFrame implements ActionListener
{
    JLabel l1,l2;
        JTextField t1;
        JPasswordField P1;
        JButton b1;

    public projectd() {
        setTitle("login form");
        l1 = new JLabel("Username");
        l1.setBounds(50, 50, 100, 30);
        l2 = new JLabel("Password");
        l2.setBounds(50, 100, 100, 30);
        t1 = new JTextField();
        t1.setBounds(150, 50, 100, 30);
        P1 = new JPasswordField();
        P1.setBounds(150, 100, 100, 30);
        b1 = new JButton("Login");
        b1.setBounds(100, 150, 80, 30);
        b1.addActionListener(this);
        add(l1);
        add(l2);
        add(t1);
        add(P1);
        add(b1);
        setLayout(null);
        setSize(400, 400);
        setVisible(true);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == b1) {
            String username = t1.getText();
            String password = new String(P1.getPassword());
            if (username.equals("admin") && password.equals("password")) {
                JOptionPane.showMessageDialog(this, "Login Successful");
            } else {
                JOptionPane.showMessageDialog(this, "Invalid Credentials");
            }
        }
        
    }
    public static void main(String args[]) {
        new projectd();
    }
}
