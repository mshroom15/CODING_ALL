import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;

public class SimpleWindow {
    public static void main(String[] args) {
        JFrame frame060 =new JFrame("E-Ticket App");
        JPanel driver060 = new JPanel(new BorderLayout());
        driver060.add(new JButton("Driver"), BorderLayout.EAST);
        driver060.setPreferredSize(new java.awt.Dimension(400, 50));
        frame060.add(driver060, BorderLayout.NORTH);
        int row060=8;
        int col060=4;
        JPanel seatplan060 = new JPanel(new GridLayout(row060, col060, 10, 10));
        String[] rows = {"A","B","C","D","E","F","G","H"};

        JButton[][] seatbuttons = new JButton[row060][col060-1];
        for (int i = 0; i < row060; i++) {
            for (int j = 0; j < col060; j++) {
                if (j == 1) {
                    seatplan060.add(new JLabel(""));
                } else {
                    String seatname;
                    int newj;
                    if (j == 0) {
                        seatname = rows[i] + "1";
                        newj = 0;
                    } else if (j == 2) {
                        seatname = rows[i] + "2";
                        newj = 1;
                    } else { 
                        seatname = rows[i] + "3";
                        newj = 2;
                    }
                    seatbuttons[i][newj]= new JButton(seatname);
                    
                    // Add ActionListener to each button
                    seatbuttons[i][newj].addActionListener(new ActionListener() {
                        @Override
                        public void actionPerformed(ActionEvent e) {
                            JButton clickedButton = (JButton) e.getSource();
                            
                            // Toggle button color
                            if (clickedButton.getBackground() == Color.GREEN) {
                                // Button is green, turn it white
                                clickedButton.setBackground(Color.WHITE);
                            } else {
                                // Button is white/default, turn it green
                                clickedButton.setBackground(Color.GREEN);
                            }
                            clickedButton.setOpaque(true);
                        }
                    });
                    
                    seatplan060.add(seatbuttons[i][newj]);
                }
            }
        }
        
        frame060.add(seatplan060, BorderLayout.CENTER);
        JPanel book060 = new JPanel(new BorderLayout());
        book060.add(new JButton("Confirm"), BorderLayout.EAST);
        book060.setPreferredSize(new java.awt.Dimension(500, 50));
        frame060.add (book060, BorderLayout.SOUTH);
        frame060.setSize(500, 800);
        frame060.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame060.setVisible(true);
    }
}