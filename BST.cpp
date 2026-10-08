#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

class BST {
    Node *root;
    bool done;

    Node *insert(Node *p, int v) {
        if (p == NULL) {
            Node *t = new Node;
            t->data = v;
            t->left = t->right = NULL;
            done = true;
            return t;
        }
        if (v < p->data) p->left = insert(p->left, v);
        else if (v > p->data) p->right = insert(p->right, v);
        return p;
    }

    Node *minNode(Node *p) {
        while (p != NULL && p->left != NULL) p = p->left;
        return p;
    }

    Node *remove(Node *p, int v) {
        if (p == NULL) return NULL;
        if (v < p->data) p->left = remove(p->left, v);
        else if (v > p->data) p->right = remove(p->right, v);
        else {
            done = true;
            if (p->left == NULL) {
                Node *r = p->right;
                delete p;
                return r;
            }
            if (p->right == NULL) {
                Node *l = p->left;
                delete p;
                return l;
            }
            Node *s = minNode(p->right);
            p->data = s->data;
            p->right = remove(p->right, s->data);
        }
        return p;
    }

    void inorder(Node *p) {
        if (p == NULL) return;
        inorder(p->left);
        cout << p->data << " ";
        inorder(p->right);
    }

    void destroy(Node *p) {
        if (p == NULL) return;
        destroy(p->left);
        destroy(p->right);
        delete p;
    }

public:
    BST() { root = NULL; done = false; }
    ~BST() { destroy(root); }

    bool insert(int v) {
        done = false;
        root = insert(root, v);
        return done;
    }

    bool remove(int v) {
        done = false;
        root = remove(root, v);
        return done;
    }

    bool search(int v) {
        Node *cur = root;
        while (cur != NULL) {
            if (v == cur->data) return true;
            if (v < cur->data) cur = cur->left;
            else cur = cur->right;
        }
        return false;
    }

    void inorder() {
        if (root == NULL) {
            cout << "Tree is empty.\n";
            return;
        }
        cout << "In-order: ";
        inorder(root);
        cout << "\n";
    }

    void minMax() {
        if (root == NULL) {
            cout << "Tree is empty.\n";
            return;
        }
        Node *mx = root;
        while (mx->right != NULL) mx = mx->right;
        cout << "Minimum: " << minNode(root)->data;
        cout << ", Maximum: " << mx->data << "\n";
    }
};

int main() {
    BST tree;
    int choice, val;
    while (true) {
        cout << "\nMenu:\n1. Insert\n2. Delete\n3. Search\n4. Display (in-order)\n";
        cout << "5. Find minimum and maximum\n6. Quit\n";
        cout << "Enter your choice: ";
        if (!(cin >> choice)) break;
        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                if (tree.insert(val)) cout << "Inserted " << val << ".\n";
                else cout << "Duplicate value; not inserted.\n";
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> val;
                if (tree.remove(val)) cout << "Deleted " << val << ".\n";
                else cout << "Value " << val << " not found.\n";
                break;
            case 3:
                cout << "Enter value to search: ";
                cin >> val;
                if (tree.search(val)) cout << val << " found in the tree.\n";
                else cout << val << " not found.\n";
                break;
            case 4: tree.inorder(); break;
            case 5: tree.minMax(); break;
            case 6: cout << "Exiting program.\n"; return 0;
            default: cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}