package DesignPatterns.Chapter01_SOLID_Principle.P4_Interface_Segregation_Principle.GoodExample;

public interface RotationTree extends Tree {

    /* methods related to balanced tree */

    public void leftRotation();

    public void rightRotation();
    
}
