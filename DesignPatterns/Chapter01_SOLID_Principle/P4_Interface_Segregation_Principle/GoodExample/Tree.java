package DesignPatterns.Chapter01_SOLID_Principle.P4_Interface_Segregation_Principle.GoodExample;

/**
 * Tree is not a "fat interface" any more
 */
public interface Tree {
    
    /* methods related to binary search tree */

    // insert data into binary search tree
    public void insert();

    // delete data in binary search tree
    public void delete();

    // traverse the binary search tree
    public void traverse();

}
