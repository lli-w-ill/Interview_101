package DesignPatterns.Chapter03_Behavioral_Design_Patterns.P4_Iterator_Pattern.Example1;

public class Example1 {
    
    public static void main(String[] args) {

        NameRepository nameRepository = new NameRepository();

        for (Iterator iter = nameRepository.getIterator(); iter.hashNext();) {
            String name = (String) iter.next();
            System.out.println(name);
        }
        
    }

}
