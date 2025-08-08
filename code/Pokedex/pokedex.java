import java.awt.*;
import java.io.File;
import java.util.concurrent.Flow;

import javax.imageio.ImageIO;
import javax.swing.BorderFactory;
import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.SwingConstants;
import java.net.*;

public class pokedex {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Pokedex");
        try {
            frame.setIconImage(ImageIO.read(new File("/T:/OBS_Source/Mudkip.png")));
        } catch (Exception e) {
            System.out.println("Error");
        }

        JPanel p = new JPanel();
        JPanel pTop = createNorth();
        pTop.setBackground(Color.green);
        pTop.setPreferredSize(new Dimension(100, 100));
        // frame.setLayout(new FlowLayout());
        // title.setFont(new Font("Arial", Font.PLAIN, 24));
        // title.setLocation(frame.getWidth() / 2, frame.getHeight() - 100);

        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        frame.add(pTop, BorderLayout.NORTH);

        p.add(Box.createRigidArea(new Dimension(0, 30)));
        frame.add(p);
        frame.add(createCenter(), BorderLayout.CENTER);

        // frame.setLayout(null);
        frame.setSize(1000, 750);
        frame.setResizable(false);
        frame.setVisible(true);

    }

    public static JPanel createNorth() {
        JPanel panel = new JPanel();

        JLabel l1 = new JLabel(("POKEDEX"));
        BoxLayout boxLayout = new BoxLayout(panel, BoxLayout.Y_AXIS);
        l1.setFont(new Font("Verdana", Font.PLAIN, 70));
        l1.setVerticalAlignment(JLabel.TOP);
        l1.setBounds(430, 40, 700, 40);
        l1.setHorizontalAlignment(JLabel.CENTER);
        l1.setBorder(BorderFactory.createLineBorder(Color.black));

        panel.add(l1);
        panel.add(Box.createRigidArea(new Dimension(0, 30)));

        JTextField searchBar = new JTextField("Search", 20);
        // searchBar.setBounds(300, 80, 650, 55);
        // searchBar.setHorizontalAlignment(JTextField.CENTER);
        searchBar.setBorder(BorderFactory.createLineBorder(Color.black));

        panel.add(searchBar, boxLayout);

        return panel;
    }

    public static JPanel createCenter() {
        JButton button = new JButton();

        JPanel p = new JPanel();

        GridLayout gridLayout = new GridLayout(0, 1);
        p.setLayout(gridLayout);
        button.setIcon(new ImageIcon("img/mudkip.png"));
        button.setPreferredSize(new Dimension(30, 30));
        p.add(button);

        return p;
    }
}
