#include <iostream>
using namespace std;

const int MAXN = 100;

struct Node {
    int data;
    Node *left, *right;
};

class BinaryTree {
    Node *root;
    int total;

    Node *newNode(int v) {
        Node *p = new Node;
        p->data = v;
        p->left = p->right = NULL;
        return p;
    }

    void destroy(Node *p) {
        if (p == NULL) return;
        destroy(p->left);
        destroy(p->right);
        delete p;
    }

    int height(Node *p) {
        if (p == NULL) return 0;
        int lh = height(p->left), rh = height(p->right);
        return 1 + (lh > rh ? lh : rh);
    }

public:
    BinaryTree() { root = NULL; total = 0; }
    ~BinaryTree() { destroy(root); }

    bool insert(int v) {
        if (total == MAXN) return false;
        Node *p = newNode(v);
        total++;
        if (root == NULL) {
            root = p;
            return true;
        }
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

    void levelOrder() {
        if (root == NULL) {
            cout << "Tree is empty.\n";
            return;
        }
        Node *q[MAXN];
        int front = 0, rear = 0;
        q[rear++] = root;
        cout << "Level-order: ";
        while (front < rear) {
            Node *cur = q[front++];
            cout << cur->data << " ";
            if (cur->left) q[rear++] = cur->left;
            if (cur->right) q[rear++] = cur->right;
        }
        cout << "\n";
    }

    bool search(int key) {
        if (root == NULL) return false;
        Node *q[MAXN];
        int front = 0, rear = 0;
        q[rear++] = root;
        while (front < rear) {
            Node *cur = q[front++];
            if (cur->data == key) return true;
            if (cur->left) q[rear++] = cur->left;
            if (cur->right) q[rear++] = cur->right;
        }
        return false;
    }

    int height() { return height(root); }
    int count() { return total; }
};

int main() {
    BinaryTree tree;
    int choice, val;
    while (true) {
        cout << "\nMenu:\n1. Insert\n2. Display (level-order)\n3. Search\n";
        cout << "4. Height of tree\n5. Count nodes\n6. Quit\n";
        cout << "Enter your choice: ";
        if (!(cin >> choice)) break;
        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                if (tree.insert(val)) cout << "Inserted " << val << ".\n";
                else cout << "Tree is full.\n";
                break;
            case 2: tree.levelOrder(); break;
            case 3:
                cout << "Enter value to search: ";
                cin >> val;
                if (tree.search(val)) cout << val << " found in the tree.\n";
                else cout << val << " not found.\n";
                break;
            case 4: cout << "Height of tree: " << tree.height() << "\n"; break;
            case 5: cout << "Number of nodes: " << tree.count() << "\n"; break;
            case 6: cout << "Exiting program.\n"; return 0;
            default: cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}