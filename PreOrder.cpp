#include <iostream>
using namespace std;

const int MAXN = 100;

struct Node {
    int data;
    Node *left, *right;
};

class PreorderTree {
    Node *root;
    int total;

    void destroy(Node *p) {
        if (p == NULL) return;
        destroy(p->left);
        destroy(p->right);
        delete p;
    }

    void preorder(Node *p) {
        if (p == NULL) return;
        cout << p->data << " ";
        preorder(p->left);
        preorder(p->right);
    }

public:
    PreorderTree() { root = NULL; total = 0; }
    ~PreorderTree() { destroy(root); }

    bool insert(int v) {
        if (total == MAXN) return false;
        Node *p = new Node;
        p->data = v;
        p->left = p->right = NULL;
        total++;
        if (root == NULL) { root = p; return true; }
        Node *q[MAXN];
        int front = 0, rear = 0;
        q[rear++] = root;
        while (front < rear) {
            Node *cur = q[front++];
            if (cur->left == NULL) { cur->left = p; return true; }
            q[rear++] = cur->left;
            if (cur->right == NULL) { cur->right = p; return true; }
            q[rear++] = cur->right;
        }
        return true;
    }

    void preorderRecursive() {
        if (root == NULL) {
            cout << "Tree is empty.\n";
            return;
        }
        cout << "Pre-order (recursive): ";
        preorder(root);
        cout << "\n";
    }

    void preorderIterative() {
        if (root == NULL) {
            cout << "Tree is empty.\n";
            return;
        }
        Node *st[MAXN];
        int top = -1;
        st[++top] = root;
        cout << "Pre-order (iterative): ";
        while (top >= 0) {
            Node *cur = st[top--];
            cout << cur->data << " ";
            if (cur->right) st[++top] = cur->right;
            if (cur->left) st[++top] = cur->left;
        }
        cout << "\n";
    }
};

int main() {
    PreorderTree tree;
    int choice, val;
    while (true) {
        cout << "\nMenu:\n1. Insert\n2. Pre-order traversal (recursive)\n";
        cout << "3. Pre-order traversal (iterative)\n4. Quit\n";
        cout << "Enter your choice: ";
        if (!(cin >> choice)) break;
        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                if (tree.insert(val)) cout << "Inserted " << val << ".\n";
                else cout << "Tree is full.\n";
                break;
            case 2: tree.preorderRecursive(); break;
            case 3: tree.preorderIterative(); break;
            case 4: cout << "Exiting program.\n"; return 0;
            default: cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}