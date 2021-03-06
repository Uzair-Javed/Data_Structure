#include <iostream>

using namespace std;

template<typename T>
struct Node
{
public:
    Node<T> *pLeft;
    Node<T> *pRight;
    T val;

    Node<T>(T val)
    {
        this->val = val;
        pLeft = pRight = nullptr;
    }
};

template<typename T>
class Tree
{
    Node<T> *root;

    Node<T> *insert_at_sub(T i, Node<T> *p);
    void print_sub(Node<T> *p);
    int t_size = 0;

public:
    Tree ()
    {
        root = nullptr;
    }

    void populate();

    void add(T i)
    {
        ++t_size;
        root = insert_at_sub(i, root);
    }
    void print()
    {
        print_sub(root);
    };

    bool contain(T i)
    {
        return contain_sub(i, root);
    }
    bool contain_sub(T i, Node<T> *p);

    void test()
    {
        cout << root->pRight->pRight->pRight->pLeft->pRight->val << endl;
    }

    int get_size()
    {
        return t_size;
    }
};

template<typename T>
Node<T>* Tree<T>::insert_at_sub(T i, Node<T> *p) 
{
    if( ! p )
        return new Node<T>(i);
    else if (i <= p->val)
        p->pLeft = insert_at_sub(i, p->pLeft);
    else if (i > p->val)
        p->pRight = insert_at_sub(i, p->pRight);

    return p;
}

template<typename T>
void Tree<T>::print_sub(Node<T> *p)
{
    if(p)
    {
        print_sub(p->pLeft);
        cout << p->val << endl;
        print_sub(p->pRight);
    }
}

template<typename T>
bool Tree<T>::contain_sub(T i, Node<T> *p)
{
    if (!p)
        return false;
    else if(i == p->val)
        return true;
    else if (i <= p->val)
        contain_sub(i, p->pLeft);
    else
        contain_sub(i, p->pRight);
}

template<typename T>
void Tree<T>::populate()
{
    add(100);
    add(200);
    add(300);
    add(400);
    add(500);
}

int main()
{
    Tree<int> tr;
    tr.populate();
    tr.print();

    return 0;
}
