#include <iostream>
using namespace std;

class Node {
    public:
    int key;
    int val;
    Node *next;
    Node(int k, int v) {
        key = k;
        val = v;
        next = NULL;
    }
};

class dictionary {
    public:
    Node **table;
    int size;
    dictionary(int s) {
        size = s;
        table = new Node*[size];
        for (int i = 0; i < size; i++) {
            table[i] = new Node(-1, -1);
        }
    }
    int hashcode(int k) {
        return k % size;
    }
    void insert(int k, int v) {
        int ind = hashcode(k);
        if (table[ind] -> key == -1)
            table[ind] = new Node(k, v);
        else {
            Node *curr = table[ind];
            while (curr -> next != NULL) {
                curr = curr -> next;
            }
            curr -> next = new Node(k, v);
        }
    }
    void display() {
        int ind = 0;
        while (ind < size) {
            Node *curr = table[ind];
            if (curr -> key == -1)
                cout << "No elements in bucket " << ind << endl;
            else {
                cout << "Elements in bucket " << ind << " are: "<< endl;
                while (curr != NULL) {
                    cout << curr -> key << " mapped to " << curr -> val << endl;
                    curr = curr -> next;
                }    
            }
            ind++;
        }
    }
    Node* del(int k) {
        int ind = hashcode(k);
        if (table[ind] -> key == k) {
            Node *deleted = table[ind];
            Node *next_node = table[ind] -> next;
            if (next_node == NULL)
                table[ind] = new Node(-1, -1);
            else
                table[ind] = next_node;
            return deleted;
        }
        else {
            Node* curr = table[ind];
            while (curr -> next != NULL) {
                if (curr -> next -> key == k) {
                    Node *deleted = curr -> next;
                    Node *temp = curr -> next -> next;
                    curr -> next = temp;
                    return deleted;
                }
                curr = curr -> next;
            }
            return NULL;
        }
    }
    Node* search(int k) {
        int ind = hashcode(k);
        Node *curr = table[ind];
        while (curr != NULL) {
            if (curr -> key == k)
                return curr;
            curr = curr -> next;
        }
        return NULL;
    }
};

int main() {
    int size, opt = 0;
    cout << "Enter size: ";
    cin >> size;
    dictionary d(size);
    cout << "MENU" << endl;
    cout << "1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n\n";
    while (opt != 5) {
        cout << "Enter your option: ";
        cin >> opt;
        switch(opt) {
            case 1: {
                int k1, v1;
                cout << "Enter key: ";
                cin >> k1;
                cout << "Enter value: ";
                cin >> v1;
                d.insert(k1, v1);
                cout << "Dictionary after inserting:\n";
                d.display();
                break;    
            }
            case 2: {
                int k2;
                cout << "Enter key to delete: ";
                cin >> k2;
                Node *deleted = d.del(k2);
                if (deleted == NULL)
                    cout << "Key not found" << endl;
                else {
                    cout << "Dictionary after deleting:\n";
                    d.display();
                }
                break;
            }
            case 3: {
                int k3;
                cout << "Enter key to search: ";
                cin >> k3;
                Node *found = d.search(k3);
                if (found == NULL)
                    cout << "Key not found" << endl;
                else
                    cout << found -> key << " : " << found -> val << endl;
                break;    
            }
            case 4: {
                cout << "Dictionary:" << endl;
                d.display();
                break;    
            }
            case 5: {
                cout << "Exiting the program" << endl;
                opt = 5;
                break;    
            }
            default:
            cout << "Invalid Option" << endl;
        }
    }
}
