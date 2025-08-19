import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import javax.swing.*;

public class visuals {
    public static void main(String[] args) {
        JFrame frame060 =new JFrame("E-Ticket App");
        JPanel driver060 = new JPanel(new BorderLayout());
        driver060.add(new JButton("Driver"), BorderLayout.EAST);
        driver060.setPreferredSize(new java.awt.Dimension(500, 50));
        frame060.add(driver060, BorderLayout.NORTH);
        int row060=8;
        int col060=4;
        JPanel seatplan060 = new JPanel(new GridLayout(row060, col060, 10, 10));
        String[] rows = {"A","B","C","D","E","F","G","H"};

        JButton[][] seatbuttons = new JButton[row060][col060-1];
        boolean[][] select = new boolean[row060][col060-1];
        boolean[][] booked = new boolean[row060][col060-1];
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
                    final int i1=i;
                    final int j1=newj;
                    seatbuttons[i][newj]= new JButton(seatname);
                    seatbuttons[i][newj].addActionListener(new ActionListener() {
                        @Override
                        public void actionPerformed(ActionEvent e) {
                            JButton click = (JButton) e.getSource();
                            if (booked[i1][j1]) {
                                return;
                            }
                            if (select[i1][j1]) {
                                click.setBackground(null);
                                select[i1][j1] = false;
                            } else {
                                click.setBackground(Color.GREEN);
                                select[i1][j1] = true;
                            }
                            click.setOpaque(true);
                        }
                    });
                    
                    seatplan060.add(seatbuttons[i][newj]);
                }
            }
        }
        
        frame060.add(seatplan060, BorderLayout.CENTER);
        JPanel booked060 = new JPanel(new BorderLayout());
        JButton confirm = new JButton("Confirm");
        booked060.add(confirm, BorderLayout.EAST);
        booked060.setPreferredSize(new java.awt.Dimension(500, 50));
         confirm.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                for (int i = 0; i < row060; i++) {
                    for (int j = 0; j < col060-1; j++) {
                        if (select[i][j]) {
                            seatbuttons[i][j].setBackground(Color.GRAY);
                            seatbuttons[i][j].setOpaque(true);
                            select[i][j] = false;
                            booked[i][j] = true;
                        }
                    }
                }
                try (BufferedWriter writer = new BufferedWriter(new FileWriter("seatplan.txt"))) {
                    writer.write("Booked:");
                    writer.newLine();
                    for (int i = 0; i < row060; i++) {
                        for (int j = 0; j < col060 - 1; j++) {
                            if (booked[i][j]) {
                                String seatName = rows[i] + (j + 1);
                                writer.write(seatName);
                                writer.newLine();
                            }
                        }
                    }
                } catch (IOException ioException) {
                    ioException.printStackTrace();
                    JOptionPane.showMessageDialog(frame060, "Failed! ","error", JOptionPane.ERROR_MESSAGE);
                }
            }
        });
        frame060.add (booked060, BorderLayout.SOUTH);
        frame060.setSize(500, 800);
        frame060.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame060.setVisible(true);
    }
}

