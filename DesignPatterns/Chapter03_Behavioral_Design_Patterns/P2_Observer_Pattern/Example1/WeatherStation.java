package DesignPatterns.Chapter03_Behavioral_Design_Patterns.P2_Observer_Pattern.Example1;

import java.util.ArrayList;
import java.util.List;

// WeatherStation -- Subject
public class WeatherStation implements Subject {

    private int pressure;
    private int temperature;
    private int humidity;
    private List<Observer> observerList;

    public WeatherStation() {
        this.observerList = new ArrayList<>();
    }

    @Override
    public void addObserver(Observer o) {
        this.observerList.add(o);
    }

    @Override
    public void removeObserver(Observer o) {
        this.observerList.remove(o);
    }

    @Override
    public void notifyAllObservers() {
        // iterate all observers and update accordingly
        for (Observer o : this.observerList) {
            o.update(pressure, temperature, humidity);
        }
    }

    public void setPressure(int pressure) {
        this.pressure = pressure;
        notifyAllObservers();
    }

    public void setTemperature(int temperature) {
        this.temperature = temperature;
        notifyAllObservers();
    }

    public void setHumidity(int humidity) {
        this.humidity = humidity;
        notifyAllObservers();
    }

}
