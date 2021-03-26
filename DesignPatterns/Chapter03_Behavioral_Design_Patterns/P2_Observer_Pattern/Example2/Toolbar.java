package DesignPatterns.Chapter03_Behavioral_Design_Patterns.P2_Observer_Pattern.Example2;

import java.awt.FlowLayout;

import javax.swing.JButton;
import javax.swing.JPanel;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Toolbar extends JPanel implements ActionListener {
    
    private JButton button;
    private ClickListener listener;

    public Toolbar() {
        button = new JButton("Click");
        button.addActionListener(this);

        setLayout(new FlowLayout(FlowLayout.CENTER));

        add(button);
    }

    public void setClickListener(ClickListener listener) {
        this.listener = listener;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        listener.clicked();
    }
}
