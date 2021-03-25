package DesignPatterns.Chapter02_Creational_Design_Patterns.P3_Builder_Pattern.Example2;

public class Example2 {
    
    public static void main(String[] args) {
        
        Student student = new Student.Builder("Kevin", "Peking University").build();
        System.out.println(student);

        Student student2 = new Student.Builder("Will", "UBC").setAge(28).build();
        System.out.println(student2);
        
    }

}
