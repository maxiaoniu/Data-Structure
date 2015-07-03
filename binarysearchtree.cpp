#include "binarysearchtree.h"

BinarySearchTree::BinarySearchTree():m_size(0)
{

}

BinarySearchTree::~BinarySearchTree()
{

}

std::shared_ptr<Node>& BinarySearchTree::search(int value)
{
    if(m_root ==nullptr || value==m_root->data )
        return m_root;
    m_hot = m_root;
    while(1)
    {
        auto& temp = (value<m_hot->data)?m_hot->lc:m_hot->rc;
        if(temp==nullptr || value == temp->data)
            return temp;
        m_hot = temp;
    }
}

std::shared_ptr<Node>& BinarySearchTree::insert(int value)
{
    std::shared_ptr<Node> &x = search(value);
    if(x)
        return x;
    x = std::make_shared<Node>(value);
    m_size++;
    return x;

}
