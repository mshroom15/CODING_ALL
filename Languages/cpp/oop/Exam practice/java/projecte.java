import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;
public class projecte implements ActionListener {
    JLabel l1,l2;
    JTextField t1, t2;
    JButton b1;
    JFrame f;
    public projecte() {
        JFrame f = new JFrame("Convert");
        l1 = new JLabel("Foot");
        l1.setBounds(50,50, 50, 30 );
        t1 = new JTextField();
        t1.setBounds( 120, 50, 80, 30);
        b1 = new JButton("convert to inch");
        b1.setBounds(80, 100, 100, 30); 
        l2 = new JLabel("Inch");
        l2.setBounds(50,150, 50, 30 );
        t2 = new JTextField();
        t2.setBounds( 120, 150, 80, 30);
        b1.addActionListener(this);
        f.add(l1);
        f.add(l2);
        f.add(t1);
        f.add(t2);
        f.add(b1);
        f.setLayout(null);
        f.setSize(300,300);
        f.setVisible(true);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
}
public void actionPerformed(ActionEvent e){
    if(e.getSource()==b1){
        try{
        String foot = t1.getText();
        int foootvlaue = Integer.parseInt(foot);
        int inch =foootvlaue*12;
        t2.setText(String.valueOf(inch));
    } catch (Exception ex){
        JOptionPane.showMessageDialog(f, "invalid");
    } 
    }
}
public static void main(String[] args) {
    new projecte();
}
}