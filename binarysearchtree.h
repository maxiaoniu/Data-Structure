#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "node.h"

class BinarySearchTree
{
public:
    BinarySearchTree();
    ~BinarySearchTree();

    int size() const {return m_size;}
    bool isEmpty() const { return !m_root;}

    std::shared_ptr<Node>& search(int value);
    std::shared_ptr<Node>& insert(int value);
private:
    int m_size;
    std::shared_ptr<Node> m_root;
    std::shared_ptr<Node> m_hot;//the target's parent
};

#endif // BINARYSEARCHTREE_H
