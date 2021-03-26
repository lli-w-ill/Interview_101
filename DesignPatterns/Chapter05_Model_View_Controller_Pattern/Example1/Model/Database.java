package DesignPatterns.Chapter05_Model_View_Controller_Pattern.Example1.Model;

import java.util.ArrayList;
import java.util.List;

// Model: represents an object or a class carrying data. It can also have ogic to update controller if its data changes.
public class Database {
    
    private List<Person> peopleDatabase;

    public Database() {
        this.peopleDatabase = new ArrayList<>();
    }

    public void addPerson(Person person) {
        this.peopleDatabase.add(person);
    }

    public void removePerson(Person person) {
        this.peopleDatabase.remove(person);
    }

    public List<Person> getPeopleDatabase() {
        return this.peopleDatabase;
    }

}
