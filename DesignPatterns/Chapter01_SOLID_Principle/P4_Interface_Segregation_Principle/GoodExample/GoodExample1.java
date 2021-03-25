package DesignPatterns.Chapter01_SOLID_Principle.P4_Interface_Segregation_Principle.GoodExample;

public class GoodExample1 {
    
    public static void main(String[] args) {
        Tree tree = new BinarySearchTree();

        tree.insert();
        tree.delete();
        tree.traverse();

        RotationTree balance = new BalancedTree();

        balance.insert();
        balance.delete();
        balance.traverse();
        balance.leftRotation();
        balance.rightRotation();
        
    }

}
