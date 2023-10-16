#include <bits/stdc++.h>
using namespace std;

class que;

class tree
{

    int data;
    tree *lft;
    tree *rgt;

public:
    friend class que;
    void post(tree *root);
    void pre(tree *root);
    void in(tree *root);
    void level(que *&q, tree *&root);
    void dlt(que *&q, tree *&root, int a);
    void insrt(que *&q, tree *&root, int n);
};

class que
{

    int size;
    int rr = -1;
    int fr = -1;
    tree **ptr;

public:
    friend class tree;
    int isfull(que *&ptr);
    int isempty(que *&q);
    void inque(que *&q, tree *n);
    tree *deque(que *&q);

    que()
    {
        size = 100;
        ptr = new tree *[size];
    }
};

void dummy(tree *&roots)
{
    roots = NULL;
}

int que::isfull(que *&ptr)
{

    if (ptr->rr == ptr->size - 1)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

int que::isempty(que *&q)
{

    if ((q->fr == q->rr + 1) || (q->fr == -1 && q->rr == -1))
    {
        q->rr = -1;
        q->fr = -1;
        return 1;
    }

    else
    {
        return 0;
    }
}

void que::inque(que *&q, tree *n)
{

    if (q->isfull(q))
    {
        cout << "Q is full" << endl;
    }
    else
    {

        if (q->fr == -1)
        {
            q->fr++;
        }

        q->rr++;
        q->ptr[q->rr] = n;
    }
}

tree *que::deque(que *&q)
{

    if (q->isempty(q))
    {
        cout << "Q is empty" << endl;
        q->rr = -1;
        q->fr = -1;
    }

    else
    {

        tree *ptr2;
        ptr2 = q->ptr[q->fr];
        q->fr++;

        return ptr2;
    }
    tree *ptr;
    return ptr;
}

void tree::post(tree *root)
{

    tree *temp;
    temp = root;

    if (temp != NULL)
    {
        post(temp->lft);
        post(temp->rgt);
        cout << temp->data << " ";
    }
    cout << endl;
}

void tree::pre(tree *root)
{

    tree *temp;
    temp = root;

    if (temp != NULL)
    {

        cout << temp->data << " ";
        pre(temp->lft);
        pre(temp->rgt);
    }
    cout << endl;
}

void tree::in(tree *root)
{

    tree *temp;
    temp = root;

    if (temp != NULL)
    {

        in(temp->lft);
        cout << temp->data << " ";
        in(temp->rgt);
    }
    cout << endl;
}

void tree::level(que *&q, tree *&root)
{

    while (!q->isempty(q))
    {
        tree *ptr = q->deque(q);
    }

    tree *ptr;
    ptr = root;

    q->inque(q, ptr);

    while (!q->isempty(q))
    {

        tree *ptr;
        ptr = q->deque(q);
        cout << ptr->data << " ";
        if (ptr->lft != NULL)
        {
            q->inque(q, ptr->lft);
        }
        if (ptr->rgt != NULL)
        {
            q->inque(q, ptr->rgt);
        }
    }

    cout << endl;
}

void tree::dlt(que *&q, tree *&roots, int a)
{

    if (roots == NULL)
    {
        cout << "The tree is empty" << endl;
    }

    else if (roots->lft == NULL && roots->rgt == NULL)
    {
        if (roots->data == a)
        {
            roots = NULL;
            cout << "The tree is now EMPTY" << endl;
        }
        else
        {
            cout << "Given element is not present in TREE" << endl;
        }
    }

    else
    {
        int p = 0;
        tree *ptr;
        ptr = roots;

        q->inque(q, ptr);

        while (!q->isempty(q))
        {

            tree *ptr;
            ptr = q->deque(q);
            if (ptr->data == a)
            {

                p = 1;

                int val;
                tree *temp;
                temp = roots;

                while (temp->rgt != NULL)
                {

                    temp = temp->rgt;
                }

                if (temp->lft != NULL)
                {

                    tree *abc;
                    abc = temp;
                    temp = temp->lft;

                    while (temp->rgt != NULL || temp->lft != NULL)
                    {

                        while (temp->rgt == NULL)
                        {
                            if (temp->lft == NULL)
                            {
                                break;
                            }
                            temp = temp->lft;
                        }

                        if (temp->lft == NULL || temp->rgt == NULL)
                        {
                            break;
                        }

                        while (temp->rgt != NULL)
                        {
                            temp = temp->rgt;
                        }
                    }

                    while (abc->rgt != temp || abc->lft != temp)
                    {

                        while (abc->rgt == NULL)
                        {
                            if (abc->lft == temp || abc->rgt == temp)
                            {
                                break;
                            }

                            abc = abc->lft;
                        }

                        if (abc->lft == temp || abc->rgt == temp)
                        {
                            break;
                        }

                        while (abc->rgt != temp)
                        {
                            if (abc->lft == temp || abc->rgt == temp)
                            {
                                break;
                            }

                            abc = abc->rgt;
                        }
                    }

                    val = temp->data;

                    if (abc->rgt == temp)
                    {
                        abc->rgt = NULL;
                    }
                    else if (abc->lft == temp)
                    {
                        abc->lft = NULL;
                    }

                    ptr->data = val;
                }

                else
                {

                    tree *prev;
                    prev = roots;

                    while (prev->rgt != temp)
                    {
                        prev = prev->rgt;
                    }

                    prev->rgt = NULL;

                    val = temp->data;

                    free(temp);

                    ptr->data = val;
                }

                break;
            }

            if (ptr->lft != NULL)
            {
                q->inque(q, ptr->lft);
            }
            if (ptr->rgt != NULL)
            {
                q->inque(q, ptr->rgt);
            }
        }

        if (p == 0)
        {
            cout << "Given Element is not present in TREE" << endl;
        }

        cout << endl;

        while (!q->isempty(q))
        {
            tree *ptr = q->deque(q);
        }
    }
}

void tree::insrt(que *&q, tree *&root, int n)
{
    if (root == NULL)
    {
        tree *t1;
        t1 = new tree();
        t1->data = n;
        t1->lft = NULL;
        t1->rgt = NULL;
        root = t1;
        q->inque(q, t1);
    }

    else
    {
        tree *ptr;
        ptr = root;

        q->inque(q, ptr);

        while (!q->isempty(q))
        {

            tree *temp;
            temp = q->deque(q);

            if (temp->lft == NULL)
            {

                tree *obj;
                obj = new tree();

                (obj)->data = n;

                temp->lft = obj;

                while (!q->isempty(q))
                {
                    tree *tp;
                    tp = q->deque(q);
                }

                break;
            }

            else
            {

                q->inque(q, temp->lft);
            }

            if (temp->rgt == NULL)
            {

                tree *obj;
                obj = new tree();

                (obj)->data = n;

                temp->rgt = obj;

                while (!q->isempty(q))
                {
                    tree *tp;
                    tp = q->deque(q);
                }

                break;
            }

            else
            {

                q->inque(q, temp->rgt);
            }
        }
    }
}

int main()
{

    que *q;

    tree *root;

    root = NULL;

    q = new que();

    char z = 'n';
    cout << "Enter y if you want to do operations on tree else enter n" << endl;
    cin >> z;

    while (z != 'n' && z != 'y')
    {
        cout << "Enter valid INPUT" << endl;
        cin >> z;
    }

    int n;

    while (z == 'y')
    {
        cout << endl
             << "---------------#####---------------" << endl;
        cout << "Enter 1 to insert the element in tree" << endl;
        cout << "Enter 2 to delete the element in tree" << endl;
        cout << "Enter 3 to traversal of tree in POST order" << endl;
        cout << "Enter 4 to traversal of tree in PRE order" << endl;
        cout << "Enter 5 to traversal of tree in IN order" << endl;
        cout << "Enter 6 to traversal of tree in LEVEL order" << endl;
        cout << "Enter 7 to exit" << endl;
        cout << "---------------#####---------------" << endl;

        cin >> n;
        cout << endl
             << endl;
        switch (n)
        {
        case 1:
            int a;
            cout << "Enter the element you want to insert" << endl;
            cin >> a;

            root->insrt(q, root, a);

            break;

        case 2:
            int c;
            cout << "Enter the element you want to delete" << endl;
            cin >> c;

            root->dlt(q, root, c);

            break;

        case 3:
            if (root == NULL)
            {
                cout << "The tree is empty" << endl;
            }
            else
            {
                root->post(root);
            }

            break;

        case 4:
            if (root == NULL)
            {
                cout << "The tree is empty" << endl;
            }
            else
            {
                root->pre(root);
            }

            break;

        case 5:
            if (root == NULL)
            {
                cout << "The tree is empty" << endl;
            }
            else
            {
                root->in(root);
            }

            break;

        case 6:
            if (root == NULL)
            {
                cout << "The tree is empty" << endl;
            }
            else
            {
                root->level(q, root);
            }

            break;

        case 7:
            z = 'n';

            break;
        }
    }

    return 0;
}