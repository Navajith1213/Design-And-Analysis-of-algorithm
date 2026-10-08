#include <iostream>
using namespace std;

const int MAXN = 100;

struct Node {
    int data;
    Node *left, *right;
};

class InorderTree {
    Node *root;
    int total;

    void destroy(Node *p) {
        if (p == NULL) return;
        destroy(p->left);
        destroy(p->right);
        delete p;
    }

    void inorder(Node *p) {
        if (p == NULL) return;
        inorder(p->left);
        cout << p->data << " ";
        inorder(p->right);
    }

public:
    InorderTree() { root = NULL; total = 0; }
    ~InorderTree() { destroy(root); }

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

    void inorderRecursive() {
        if (root == NULL) {
            cout << "Tree is empty.\n";
            return;
        }
        cout << "In-order (recursive): ";
        inorder(root);
        cout << "\n";
    }

    void inorderIterative() {
        if (root == NULL) {
            cout << "Tree is empty.\n";
            return;
        }
        Node *st[MAXN];
        int top = -1;
        Node *cur = root;
        cout << "In-order (iterative): ";
        while (cur != NULL || top >= 0) {
            while (cur != NULL) {
                st[++top] = cur;
                cur = cur->left;
            }
            cur = st[top--];
            cout << cur->data << " ";
            cur = cur->right;
        }
        cout << "\n";
    }
};

int main() {
    InorderTree tree;
    int choice, val;
    while (true) {
        cout << "\nMenu:\n1. Insert\n2. In-order traversal (recursive)\n";
        cout << "3. In-order traversal (iterative)\n4. Quit\n";
        cout << "Enter your choice: ";
        if (!(cin >> choice)) break;
        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                if (tree.insert(val)) cout << "Inserted " << val << ".\n";
                else cout << "Tree is full.\n";
                break;
            case 2: tree.inorderRecursive(); break;
            case 3: tree.inorderIterative(); break;
            case 4: cout << "Exiting program.\n"; return 0;
            default: cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}