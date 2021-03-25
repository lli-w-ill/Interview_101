package DesignPatterns.Chapter01_SOLID_Principle.P4_Interface_Segregation_Principle.BadExample;

public class BadExample1 {
    
    public static void main(String[] args) {
        Tree tree = new BinarySearchTree();

        tree.insert();
        tree.delete();
        tree.traverse();

        // "design smell"
        tree.leftRotation();
        tree.rightRotation();


        Tree balance = new BalancedTree();

        balance.insert();
        balance.delete();
        balance.traverse();
        balance.leftRotation();
        balance.rightRotation();

    }

}
