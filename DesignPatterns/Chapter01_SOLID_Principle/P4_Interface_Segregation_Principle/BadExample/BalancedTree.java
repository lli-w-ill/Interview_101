package DesignPatterns.Chapter01_SOLID_Principle.P4_Interface_Segregation_Principle.BadExample;

public class BalancedTree implements Tree {

    @Override
    public void delete() {
        System.out.println("Removing a new item...");
    }

    @Override
    public void insert() {
        System.out.println("Inserting a new item...");
    }

    @Override
    public void traverse() {
        System.out.println("In-order traversing a new item...");
    }

    @Override
    public void leftRotation() {
        System.out.println("Left rotation...");
    }

    @Override
    public void rightRotation() {
        System.out.println("Right rotation...");
    }
    
}
