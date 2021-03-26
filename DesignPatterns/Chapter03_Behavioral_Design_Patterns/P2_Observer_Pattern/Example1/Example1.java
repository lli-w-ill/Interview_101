package DesignPatterns.Chapter03_Behavioral_Design_Patterns.P2_Observer_Pattern.Example1;

public class Example1 {
    
    public static void main(String[] args) {

        WeatherStation station = new WeatherStation();
        WeatherObserver observer = new WeatherObserver(station);

        station.setHumidity(100);
        station.setPressure(200);
        station.setTemperature(300);

        WeatherObserver observer2 = new WeatherObserver(station);

        station.setHumidity(400);
    }

}
