package DesignPatterns.Chapter02_Creational_Design_Patterns.P3_Builder_Pattern.Example1;

public class Person {
    
    private String name;
    private String email;
    private String address;
    private int age;
    private String university;

    public Person(Builder builder) {
        // Builder propogates the info to the Person object
        this.name = builder.name;
        this.email = builder.email;
        this.address = builder.address;
        this.age = builder.age;
        this.university = builder.university;
    }
    
    // inner builder will build Person objects
    public static class Builder {
        private final String name;
        private final String email;
        private String address; // address is not compulsary, so not final 
        private int age;    // optinal
        private String university;  // optional

        public Builder(String name, String email) {
            this.name = name;
            this.email = email;
        }

        /* define setters and getters for optional parameters */
        public Builder setAddress(String address) {
            this.address = address;
            return this;    // return Builder class itself
        }

        public Builder setAge(int age) {
            this.age = age;
            return this;    // return Builder class itself
        }

        public Builder setUniversity(String university) {
            this.university = university;
            return this;
        }

        /* IMPORTANT: build a Person object */
        public Person build() {
            return new Person(this);
        }
    }

    @Override
    public String toString() {
        return this.name + "-" + this.email + "-" + this.address + "-" + this.age + "-" + this.university;
    }
}
