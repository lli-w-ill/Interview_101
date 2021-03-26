package DesignPatterns.Chapter04_Structural_Design_Patterns.P4_Adapter_Pattern.Example2;

public class StockMarketAdapter implements CSVParser {
    
    private StockMarketDataParser stockMarketDataParser;

    public StockMarketAdapter(StockMarketDataParser stockMarketDataParser) {
        this.stockMarketDataParser = stockMarketDataParser;
    }

    @Override
    public void parseCSV() {
        this.stockMarketDataParser.parseXML();
    }

}
