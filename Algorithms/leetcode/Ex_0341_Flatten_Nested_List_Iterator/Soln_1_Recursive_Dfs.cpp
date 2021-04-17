#include <vector>

using std::vector;

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 */
class NestedInteger {
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested st.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single teger
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};


class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        flatten(nestedList);
        length = flattenedList.size();
        index = 0;
    }
    
    int next() {
        int res = flattenedList[index];
        index ++;
        return res;
    }
    
    bool hasNext() {
        return index < length;
    }

private:
    vector<int> flattenedList;
    int length;
    int index;

    void flatten(const vector<NestedInteger> &nestedList) {      
        for (int i = 0; i < nestedList.size(); i++) {
            if (nestedList[i].isInteger()) {
                flattenedList.push_back(nestedList[i].getInteger());
            } else {
                flatten(nestedList[i].getList());
            }
        }
    }

};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */