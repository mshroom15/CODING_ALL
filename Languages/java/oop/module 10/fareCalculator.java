import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class fareCalculator {
     public static void main(String [] args){
        int [][] d={
               {0,50,100,150,230},
               {50,0,50,100,180},
               {100,50,0,50,130},
               {150,100,50,0,80},
               {230,180,130,80,0}
          };

          String [] s={"Rajshahi","Iswardi","Ullapara","Tangail","Dhaka"};

          JFrame f=new JFrame();
          f.setTitle("Fare Calculator");
          f.setSize(420,300);
          f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
          f.setLayout(null);
          f.setLocationRelativeTo(null);

          JPanel p = new JPanel();
          p.setLayout(null);
          p.setBounds(10, 10, 380, 240);
          f.add(p);

          JLabel l1=new JLabel("Source:");
          l1.setBounds(40,30,80,30);
          p.add(l1);

          JComboBox<String> c1=new JComboBox<>(s);
          c1.setBounds(160,30,180,30);
          c1.setSelectedIndex(-1);
          p.add(c1);

          JLabel l2=new JLabel("Destination:");
          l2.setBounds(40,70,80,30);
          p.add(l2);

          JComboBox<String> c2=new JComboBox<>(s);
          c2.setBounds(160,70,180,30);
          c2.setSelectedIndex(-1);
          p.add(c2);

          JCheckBox ac=new JCheckBox("AC Coach");
          ac.setBounds(155,110,120,30);
          p.add(ac);

          JLabel lab=new JLabel("Fare: Tk 0.0");
          lab.setFont(new Font("Arial",Font.BOLD,16));
          lab.setBounds(160,150,200,30);
          p.add(lab);

          JButton btn=new JButton("Calculate Fare");
          btn.setBounds(130,200,150,30);
          p.add(btn);

          btn.addActionListener(new ActionListener(){
               public void actionPerformed(ActionEvent e){
                    int src=c1.getSelectedIndex();
                    int dst=c2.getSelectedIndex();
                    if(src==-1||dst==-1){
                         JOptionPane.showMessageDialog(f,"Please select both stations!","Error",JOptionPane.ERROR_MESSAGE);
                         return;
                    }
                    if(src==dst){
                         JOptionPane.showMessageDialog(f,"Source and destination cannot be the same!","Error",JOptionPane.ERROR_MESSAGE);
                         return;
                    }
                    int dist=d[src][dst];
                    double fare=dist*3.0;
                    if(ac.isSelected()){
                         fare=fare*1.5;
                    }
                    lab.setText(String.format("Fare: Tk %.2f", fare));
               }
          });

          f.setVisible(true);
     }
}
