package DesignPatterns.Chapter04_Structural_Design_Patterns.P4_Adapter_Pattern.Example2;

public class Example2 {
    
    public static void main(String[] args) {

        CSVParser realEstate = new RealEstateMarketDataParser();
        CSVParser machineLearnig = new MachineLearningDataParser();
        // CSVParser stockMarket = new StockMarketDataParser();    // error
        CSVParser stockMarket = new StockMarketAdapter(new StockMarketDataParser());

        realEstate.parseCSV();
        machineLearnig.parseCSV();
        stockMarket.parseCSV();     // actuall parse XML

    }

}
