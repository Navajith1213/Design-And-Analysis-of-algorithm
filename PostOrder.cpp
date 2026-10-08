#include <iostream>
using namespace std;

const int MAXN = 100;

struct Node {
    int data;
    Node *left, *right;
};

class PostorderTree {
    Node *root;
    int total;

    void destroy(Node *p) {
        if (p == NULL) return;
        destroy(p->left);
        destroy(p->right);
        delete p;
    }

    void postorder(Node *p) {
        if (p == NULL) return;
        postorder(p->left);
        postorder(p->right);
        cout << p->data << " ";
    }

public:
    PostorderTree() { root = NULL; total = 0; }
    ~PostorderTree() { destroy(root); }

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

    void postorderRecursive() {
        if (root == NULL) {
            cout << "Tree is empty.\n";
            return;
        }
        cout << "Post-order (recursive): ";
        postorder(root);
        cout << "\n";
    }

    void postorderIterative() {
        if (root == NULL) {
            cout << "Tree is empty.\n";
            return;
        }
        Node *s1[MAXN], *s2[MAXN];
        int t1 = -1, t2 = -1;
        s1[++t1] = root;
        while (t1 >= 0) {
            Node *cur = s1[t1--];
            s2[++t2] = cur;
            if (cur->left) s1[++t1] = cur->left;
            if (cur->right) s1[++t1] = cur->right;
        }
        cout << "Post-order (iterative): ";
        while (t2 >= 0) cout << s2[t2--]->data << " ";
        cout << "\n";
    }
};

int main() {
    PostorderTree tree;
    int choice, val;
    while (true) {
        cout << "\nMenu:\n1. Insert\n2. Post-order traversal (recursive)\n";
        cout << "3. Post-order traversal (iterative)\n4. Quit\n";
        cout << "Enter your choice: ";
        if (!(cin >> choice)) break;
        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                if (tree.insert(val)) cout << "Inserted " << val << ".\n";
                else cout << "Tree is full.\n";
                break;
            case 2: tree.postorderRecursive(); break;
            case 3: tree.postorderIterative(); break;
            case 4: cout << "Exiting program.\n"; return 0;
            default: cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}