#include <iostream>
using namespace std;

class Node {
    public:
        char l;
        int no;
        Node *rt;       // right node
        Node *lt;       // left node
    public:
        Node(char l) : l(l), no(0), rt(nullptr), lt(nullptr) {};
        Node() : l('\0'), no(0), rt(nullptr), lt(nullptr) {};
};

typedef Node *Link;

class BTree {
    public:
        Link rtNode;
        static int node_no;
    public:
        BTree() : rtNode(nullptr) {};
        void add_node(char l);
};

void inorder(Link tree);
void preorder(Link tree);
void postorder(Link tree);

const int INORDER   = 1;
const int PREORDER  = 2;
const int POSTORDER = 3;
void show(Link tree, int mode);

int searchNode(Link tree, char letter);

void test_arg(BTree bt, int count);
int BTree::node_no = 1;
int main(void) {
    char data[] = {'D', 'B', 'F', 'A', 'C', 'E', 'G'};
    
    BTree bt;

    int count = 7;
    // cout << "Please enter data: ";
    // cin >> count;
    for (size_t i = 0; i < count; i++)
    {
        /* code */
        bt.add_node(data[i]);
    }
    
    test_arg(bt, count);

    cout << endl;

    show(bt.rtNode, INORDER);
    show(bt.rtNode, PREORDER);
    show(bt.rtNode, POSTORDER);

    char letter = 'A';
    // cout << "Please enter search letter: ";
    // cin >> letter;
    int node_no = searchNode(bt.rtNode, letter);
    cout << "Found out: " << letter << ", Node: " << node_no << endl; 
    // cout << bt.rtNode->l << ' ';
    // cout << bt.rtNode->lt->l << ' ';
    // cout << bt.rtNode->lt->lt->l << ' ';
    // cout << bt.rtNode->lt->rt->l << ' ';
    // cout << bt.rtNode->rt->l << ' ';
    // cout << bt.rtNode->rt->lt->l << ' ';
    // cout << bt.rtNode->rt->rt->l << ' ';
    cout << endl;
    return 0;
};

void test_arg(BTree bt, int count) {
    switch (count)
    {
    case 1:
        cout << bt.rtNode->no           << ":" << bt.rtNode->l << ' ';
        break;
    case 2:
        cout << bt.rtNode->no           << ":" << bt.rtNode->l << ' ';
        cout << bt.rtNode->lt->no       << ":" << bt.rtNode->lt->l << ' ';
        break;
    case 3:
        cout << bt.rtNode->no           << ":" << bt.rtNode->l << ' ';
        cout << bt.rtNode->lt->no       << ":" << bt.rtNode->lt->l << ' ';
        cout << bt.rtNode->rt->no       << ":" << bt.rtNode->rt->l << ' ';
        break;
    case 4:
        cout << bt.rtNode->no           << ":" << bt.rtNode->l << ' ';
        cout << bt.rtNode->lt->no       << ":" << bt.rtNode->lt->l << ' ';
        cout << bt.rtNode->rt->no       << ":" << bt.rtNode->rt->l << ' ';
        cout << bt.rtNode->lt->lt->no   << ":" << bt.rtNode->lt->lt->l << ' ';
        break;
    case 5:
        cout << bt.rtNode->no           << ":" << bt.rtNode->l << ' ';
        cout << bt.rtNode->lt->no       << ":" << bt.rtNode->lt->l << ' ';
        cout << bt.rtNode->rt->no       << ":" << bt.rtNode->rt->l << ' ';
        cout << bt.rtNode->lt->lt->no   << ":" << bt.rtNode->lt->lt->l << ' ';
        cout << bt.rtNode->lt->rt->no   << ":" << bt.rtNode->lt->rt->l << ' ';
        break;
    case 6:
        cout << bt.rtNode->no           << ":" << bt.rtNode->l << ' ';
        cout << bt.rtNode->lt->no       << ":" << bt.rtNode->lt->l << ' ';
        cout << bt.rtNode->rt->no       << ":" << bt.rtNode->rt->l << ' ';
        cout << bt.rtNode->lt->lt->no   << ":" << bt.rtNode->lt->lt->l << ' ';
        cout << bt.rtNode->lt->rt->no   << ":" << bt.rtNode->lt->rt->l << ' ';
        cout << bt.rtNode->rt->lt->no   << ":" << bt.rtNode->rt->lt->l << ' ';
        break;
    case 7:
        cout << bt.rtNode->no           << ":" << bt.rtNode->l << ' ';
        cout << bt.rtNode->lt->no       << ":" << bt.rtNode->lt->l << ' ';
        cout << bt.rtNode->rt->no       << ":" << bt.rtNode->rt->l << ' ';
        cout << bt.rtNode->lt->lt->no   << ":" << bt.rtNode->lt->lt->l << ' ';
        cout << bt.rtNode->lt->rt->no   << ":" << bt.rtNode->lt->rt->l << ' ';
        cout << bt.rtNode->rt->lt->no   << ":" << bt.rtNode->rt->lt->l << ' ';
        cout << bt.rtNode->rt->rt->no   << ":" << bt.rtNode->rt->rt->l << ' ';
        break;
    }
}

void BTree::add_node(char l) {
    if (nullptr == rtNode) {
        rtNode = new Node(l);
        rtNode->no = BTree::node_no;
        BTree::node_no++;
    }
      
    else {
        Link crNode = rtNode;
        bool isSet = false;

        while (!isSet) {
            if (crNode->l != '\0')
            {
                /* code */
                if (crNode->l < l) {
                    if (crNode->rt == '\0') {
                        crNode->rt = new Node(l);
                        crNode->rt->no = BTree::node_no;
                        BTree::node_no++;
                        isSet = true;
                    } else {
                        crNode = crNode->rt;
                    }
                } else {
                    if (crNode->lt == '\0') {
                        crNode->lt = new Node(l);
                        crNode->lt->no = BTree::node_no;
                        BTree::node_no++;
                        isSet = true;
                    } else {
                        crNode = crNode->lt;
                    }
                }
                
            }
            
        }
        
    }
    
}

void inorder(Link tree) {
    if (tree->l != '\0')
    {
        if (tree->lt != nullptr)
            inorder(tree->lt);

        cout << tree->l << ' ';

        if (tree->rt != nullptr)
            inorder(tree->rt);
    }
}

void preorder(Link tree) {
    if (tree->l != '\0')
    {
        cout << tree->l << ' ';

        if (tree->lt != nullptr)
            preorder(tree->lt);

        if (tree->rt != nullptr)
            preorder(tree->rt);
    } 
}

void postorder(Link tree) {
    if (tree->l != '\0')
    {
        if (tree->lt != nullptr)
            postorder(tree->lt);

        if (tree->rt != nullptr)
            postorder(tree->rt);

        cout << tree->l << ' ';
    } 
}

void show(Link tree, int mode) {

    switch (mode)
    {
    case INORDER:
        // answer: ABCDEFG
        cout << "Inorder: ";
        inorder(tree);
        cout << endl;
        break;
    case PREORDER:
        // answer: DBACFEG
        cout << "Preorder: ";
        preorder(tree);
        cout << endl;
        break;
    case POSTORDER:
        // answer: ACBEGFD
        cout << "Postorder: ";
        postorder(tree);
        cout << endl;
        break;
    }
}

int searchNode(Link tree, char letter) {
    while (true)
    {
        /* code */
        if (letter == tree->l) {
            return tree->no;
        } else if (letter > tree->l) {
            tree = tree->rt;
        } else if (letter < tree->l) {
            tree = tree->lt;
        }
        
    }
    
}