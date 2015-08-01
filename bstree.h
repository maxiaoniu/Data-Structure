#ifndef BSTREE
#define BSTREE
#include <functional>
//A map-like class backed by a Binary Search Tree
template <typename Key, typename Value, typename Comparator = std::less<Key> >
class BSTree{
public:
    //Construct a new empty binary search tree that uses the indicated comparator to
    //compare keys
    BSTree(Comparator comp = Comparator());
    ~BSTree();

    BSTree(const BSTree& other);
    BSTree& operator= (const BSTree& other);

    class iterator;
    class const_iterator;
    typedef std::reverse_iterator<iterator> reverse_iterator;
    typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

    std::pair<iterator,bool> insert(const Key& key, const Value& value);

    bool erase(const Key& key);
    iterator erase(iterator where);
    iterator find(const Key& key);
    const_iterator find(const Key &key) const;

    Value& operator[] (const Key& key);

    Value& at(const Key& key);
    const Value& at(const Key &key) const;

    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;

    reverse_iterator rbegin();
    reverse_iterator rend();
    const_reverse_iterator rbegin();
    const_reverse_iterator rend();

private:
    struct Node{
        std::pair<const Key, Value> m_value;
        Node* m_children[2];//the first is left and the second is right
        Node* m_parent;
        Node* m_next, m_prev;
        int m_height;
        Node(const Key& key, const Value& value, int height);
    };

    Node* m_head, m_tail;
    Node* m_root;
    Comparator m_comp;
    size_t m_size;
    template <typename DerivedType, typename Pointer, typename Reference>
    class IteratorBase;
    template <typename DerivedType, typename Pointer, typename Reference>
    friend class IteratorBase;

    friend class iterator;
    friend class const_iterator;

    int height(const Node* node);

    std::pair<Node*, Node*> findNode(const Key& key) const;

};

/* Comparison operators for BSTree. */
template <typename Key, typename Value, typename Comparator>
bool operator<  (const AVLTree<Key, Value, Comparator>& lhs,
                 const AVLTree<Key, Value, Comparator>& rhs);
template <typename Key, typename Value, typename Comparator>
bool operator<= (const AVLTree<Key, Value, Comparator>& lhs,
                 const AVLTree<Key, Value, Comparator>& rhs);
template <typename Key, typename Value, typename Comparator>
bool operator== (const AVLTree<Key, Value, Comparator>& lhs,
                 const AVLTree<Key, Value, Comparator>& rhs);
template <typename Key, typename Value, typename Comparator>
bool operator!= (const AVLTree<Key, Value, Comparator>& lhs,
                 const AVLTree<Key, Value, Comparator>& rhs);
template <typename Key, typename Value, typename Comparator>
bool operator>= (const AVLTree<Key, Value, Comparator>& lhs,
                 const AVLTree<Key, Value, Comparator>& rhs);
template <typename Key, typename Value, typename Comparator>
bool operator>  (const AVLTree<Key, Value, Comparator>& lhs,
                 const AVLTree<Key, Value, Comparator>& rhs);

template <typename Key, typename Value, typename Comparator>
template <typename DerivedType, typename Pointer, typename Reference>
class BSTree<Key, Value, Comparator>::IteratorBase
{
public:
    typedef typename BSTree<Key, Value, Comparator>::Node Node;

    DerivedType& operator++ ()
    {
        m_curr = m_curr->m_next();
        //downcast to our actual type
        return static_cast<DerivedType&>(*this);
    }
    const DerivedType operator++(int)
    {
        DerivedType result = static_cast<DerivedType&>(*this);

        ++*this;

        return result;
    }
    DerivedType& operator--()
    {
        if(m_curr = NULL)
        {
            m_curr = m_owner->m_tail;
        }
        else
        {
            m_curr = m_curr->m_prev;
        }
        return static_cast<DerivedType&>(*this);
     }
    DerivedType& operator--(int)
    {

    }
    };

#endif // BSTREE

