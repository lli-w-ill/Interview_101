package DesignPatterns.Chapter01_SOLID_Principle.P4_Interface_Segregation_Principle.BadExample;

public class BinarySearchTree implements Tree {

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
        // there is no left rotation in BST
        // "design smell"
    }

    @Override
    public void rightRotation() {
        // there is no right rotation in BST
        // "design smell"
    }
    
}
