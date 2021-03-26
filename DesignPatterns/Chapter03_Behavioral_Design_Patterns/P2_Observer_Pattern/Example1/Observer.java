package DesignPatterns.Chapter03_Behavioral_Design_Patterns.P2_Observer_Pattern.Example1;

// observer is going to make updates whenever the pressure, the temperature or the humidity has changed
public interface Observer {
    
    public void update(int pressure, int temperature, int humidity);

}
