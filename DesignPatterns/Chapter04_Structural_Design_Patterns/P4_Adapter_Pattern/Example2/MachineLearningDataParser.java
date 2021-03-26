package DesignPatterns.Chapter04_Structural_Design_Patterns.P4_Adapter_Pattern.Example2;

public class MachineLearningDataParser implements CSVParser {

    @Override
    public void parseCSV() {
        System.out.println("Parsing a machine learning related CSV file...");
    }

}
