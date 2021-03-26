package DesignPatterns.Chapter03_Behavioral_Design_Patterns.P2_Observer_Pattern.Example2;

import java.awt.BorderLayout;

import javax.swing.JPanel;
import javax.swing.JTextArea;

public class TextPanel extends JPanel {
    
    private JTextArea textArea;

    public TextPanel() {
        textArea = new JTextArea();
        setLayout(new BorderLayout());
        add(textArea, BorderLayout.CENTER);
    }

    public void addText() {
        textArea.append("Button clicked!\n");
    }
}
