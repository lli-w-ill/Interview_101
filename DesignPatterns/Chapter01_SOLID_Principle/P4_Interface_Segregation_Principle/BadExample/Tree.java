package DesignPatterns.Chapter01_SOLID_Principle.P4_Interface_Segregation_Principle.BadExample;

/**
 * Tree is a "fat interface"
 */
public interface Tree {
    
    /* methods related to binary search tree */

    // insert data into binary search tree
    public void insert();

    // delete data in binary search tree
    public void delete();

    // traverse the binary search tree
    public void traverse();


    /* methods related to balanced tree */

    public void leftRotation();

    public void rightRotation();

}
