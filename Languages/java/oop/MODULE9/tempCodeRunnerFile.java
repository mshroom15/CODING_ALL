import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
class LoginForm extends JFrame implements ActionListener {
    private final Container container;
    private final JLabel userLabel;
    private final JLabel passwordLabel;
    private final JTextField userTextField;
    private final JPasswordField passwordField;
    private final JButton loginButton;

    public LoginForm() {
        setTitle("Login Form");
        setBounds(10, 10, 370, 250);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setResizable(false);

        container = getContentPane();
        container.setLayout(null);

        userLabel = new JLabel("Username");
        userLabel.setBounds(50, 50, 100, 30);
        container.add(userLabel);

        passwordLabel = new JLabel("Password");
        passwordLabel.setBounds(50, 100, 100, 30);
        container.add(passwordLabel);

        userTextField = new JTextField();
        userTextField.setBounds(150, 50, 150, 30);
        container.add(userTextField);

        passwordField = new JPasswordField();
        passwordField.setBounds(150, 100, 150, 30);
        container.add(passwordField);

        loginButton = new JButton("Login");
        loginButton.setBounds(150, 150, 90, 30);
        container.add(loginButton);
        loginButton.addActionListener(this);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        String username = userTextField.getText();
        String password = new String(passwordField.getPassword());

        if (username.equals("admin") && password.equals("password")) {
            JOptionPane.showMessageDialog(this, "Login Successful");
        } else {
            JOptionPane.showMessageDialog(this, "Invalid Username or Password");
        }
    }

    public static void main(String[] a) {
        LoginForm frame = new LoginForm();
        frame.setVisible(true);
    }
}
