package DesignPatterns.Chapter05_Model_View_Controller_Pattern.Example1.Controller;

import java.util.List;

import DesignPatterns.Chapter05_Model_View_Controller_Pattern.Example1.Model.Database;
import DesignPatterns.Chapter05_Model_View_Controller_Pattern.Example1.Model.Person;
import DesignPatterns.Chapter05_Model_View_Controller_Pattern.Example1.View.MainFrame;

// Controller: act on both model and view. It controls the data flow into model object and updates the view whenever data changes. It keeps View and Model separate
// MODEL <------> CONTROLLER <------> VIEW
public class Controller {
    
    // Model
    private Database database;
    // View
    private MainFrame mainFrame;

    public Controller(MainFrame mainFrame) {
        this.database = new Database();
        this.mainFrame = mainFrame;
    }

    public void addPerson(String personName, String personOccupation) {
        Person person = new Person(personName, personOccupation);
        this.database.addPerson(person);
    }

    public void removePerson(Person person) {
        this.database.removePerson(person);
    }

    public List<Person> getPeopleDatabase() {
        return this.database.getPeopleDatabase();
    }

    public void refreshScreen() {
        List<Person> people = getPeopleDatabase();
        this.mainFrame.clearText();

        for (Person person : people) {
            this.mainFrame.refreshTextArea(person.getName(), person.getOccupation());
        }
    }

}
