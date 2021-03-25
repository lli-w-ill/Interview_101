package DesignPatterns.Chapter02_Creational_Design_Patterns.P3_Builder_Pattern.Example1;

public class Example1 {
    
    public static void main(String[] args) {
        Person person = new Person.Builder("Kevin", "kevin@gmail.com").build();

        System.out.println(person);

        Person person2 = new Person.Builder("Kevin", "kevin@gmail.com").setAge(15).setUniversity("Peking University").setAddress("Beijing").build();

        System.out.println(person2);

    }

}
