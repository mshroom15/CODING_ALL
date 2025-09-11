import java.awt.TextField;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPasswordField;

public class topic1 {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Login Form");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(300, 250);
        frame.setLayout(null);

        JLabel login = new JLabel("Login:");
        login.setBounds(50, 20, 80, 30);
        frame.add(login);

        TextField user = new TextField();
        user.setBounds(50, 50, 200, 30);
        frame.add(user);

        JLabel password = new JLabel("Password:");
        password.setBounds(50, 90, 80, 30);
        frame.add(password);

        JPasswordField passwordField = new JPasswordField();
        passwordField.setBounds(50, 120, 200, 30);
        frame.add(passwordField);

        JButton close = new JButton("Close");
        close.setBounds(170, 170, 80, 30);
        close.addActionListener(e -> frame.dispose());
        frame.add(close);

        JButton submit = new JButton("Submit");
        submit.setBounds(50, 170, 80, 30);
        submit.addActionListener(e -> {
            String username = user.getText();
            String password1 = new String(passwordField.getPassword());
            System.out.println("Username: " + username);
            System.out.println("Password: " + password1);
        });
        frame.add(submit);
        submit.addActionListener(e -> {
            String username = user.getText();
            String passstr = new String(passwordField.getPassword());
            if ("admin".equals(username) && "12345678".equals(passstr)) {
            JOptionPane.showMessageDialog(frame, "Login Successful");
        } else {
            JOptionPane.showMessageDialog(frame, "Login Failed");
            }
        });

        frame.setLocationRelativeTo(null);
        frame.setResizable(false);
        
        frame.setVisible(true);
    }
}
