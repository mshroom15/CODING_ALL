
import java.awt.event.*;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
public class projecta{
    public static void main(String args[]){
        JFrame f=new JFrame("Divisions");
        String divisions[]={"Rajshahi","Dhaka","B","C","D","E"};
        int[] index = {0};
        JLabel l1 = new JLabel(divisions[index[0]]);
        l1.setBounds(150, 50, 100, 30);
        JButton b1=new JButton("Next");
        b1.setBounds(200, 100, 80, 30);
        JButton b2=new JButton("Previous");
        b2.setBounds(50, 100, 100, 30);
        b1.addActionListener(e -> {
            index[0] = (index[0] + 1) % divisions.length;
            l1.setText(divisions[index[0]]);
        });
        b2.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                index[0] = (index[0] - 1 + divisions.length) % divisions.length;
                l1.setText(divisions[index[0]]);
            }
        });
       
        f.add(b1);
        f.add(b2);
        f.add(l1);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.setLayout(null);
        f.setSize(300, 200);
        f.setVisible(true);
    }
}