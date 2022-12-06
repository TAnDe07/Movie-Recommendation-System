#include "movie.h"
#include "set"

class map {
private:
    struct Node {
        string key;
        movie value;
        bool redOrBlack; //Red = false, black = true;
        Node *left;
        Node *right;
        Node *parent;

        Node(string key, movie value, bool red, Node *parent, Node *left, Node *Right) : key(key), value(value),
                                                                                         redOrBlack(red),
                                                                                         parent(parent), left(nullptr),
                                                                                         right(nullptr) {}
    };

    Node *root;

    void leftRotation(Node *helperRoot,  Node* parent) {
        Node* rightChild = helperRoot->right;
        helperRoot->right = rightChild->left;

        if (rightChild->left != nullptr) {
            rightChild->left->parent = helperRoot;
        }

        rightChild->left = helperRoot;
        helperRoot->parent = rightChild;

        //replaces
        if (parent == nullptr) {
            root = rightChild;
        }
        else if (parent->left = helperRoot) {
            parent->left = rightChild;
        }
        else if (parent->right == helperRoot) {
            parent->right = rightChild;
        }

        if (rightChild != nullptr) {
            rightChild->parent = parent;
        }
    }

    void rightRotation(Node *helperRoot, Node* parent) {
        Node* leftChild = helperRoot->left;
        helperRoot->left = leftChild->right;

        if (leftChild->right != nullptr) {
            leftChild->right->parent = helperRoot;
        }

        leftChild->right = helperRoot;
        helperRoot->parent = leftChild;

        //replaces
        if (parent == nullptr) {
            root = leftChild;
        }
        else if (parent->left = helperRoot) {
            parent->left = leftChild;
        }
        else if (parent->right == helperRoot) {
            parent->right = leftChild;
        }

        if (leftChild != nullptr) {
            leftChild->parent = parent;
        }
    }


    void inorderHelperGenre(Node *helperRoot, set<string> &movies, string genre) {
        //if tree is empty
        if (movies.size() == 5 || (helperRoot == nullptr)) {
            return;
        }
        //gets reference of info inorder and stores them in vector
        inorderHelperGenre(helperRoot->left, movies, genre);
                if (helperRoot->value.genre == genre){
                    movies.insert(helperRoot->value.name);
                }
        inorderHelperGenre(helperRoot->right, movies, genre);
    }

    void inorderHelperYear(Node *helperRoot, set<string> &movies, int year) {
        //if tree is empty
        if (movies.size() == 5 || (helperRoot == nullptr)) {
            return;
        }
        //gets reference of info inorder and stores them in vector
        inorderHelperYear(helperRoot->left, movies, year);
        if (stoi(helperRoot->value.year) == year){
            movies.insert(helperRoot->value.name);
        }
        inorderHelperYear(helperRoot->right, movies, year);
    }

    void inorder(Node *helperRoot, vector<movie> & movies, string first) {
        //if tree is empty
        if ((helperRoot == nullptr)) {
            return;
        }
        //gets reference of info inorder and stores them in vector
        inorder(helperRoot->left, movies, first);
        if (helperRoot->value.name == first){
            movies.push_back(helperRoot->value);
        }
        inorder(helperRoot->right, movies, first);
    }

    Node* getParent(Node* helperRoot, string first) {
        Node* parent = nullptr;

        while (helperRoot != nullptr) {
            parent = helperRoot;
            if (helperRoot->key > first) {
                helperRoot = helperRoot->left;
            }
            else if(helperRoot->key < first) {
                helperRoot = helperRoot->right;
            }
            else if (helperRoot->key == first) {
                return nullptr;
            }
        }
        return parent;
    }

    Node* helperMapInsert(Node *helperRoot, string first, movie second, bool red, Node* parent) {

        // if tree is empty, insert at root
        if(helperRoot == nullptr) {
            return new Node(first, second, true, parent, nullptr, nullptr);
        }
            // if id is less than current id, go to left subtree
        else if (helperRoot->key > first) {
            helperRoot->left = helperMapInsert(helperRoot->left, first, second, red, parent);
        }
            // if id is greater than current id, go to right subtree
        else if (helperRoot->key < first){
            helperRoot->right = helperMapInsert(helperRoot->right, first, second, red, parent);
        }
            // if id is equal to current id, print unsuccessful, and return
        else if (helperRoot->key == first) {
            return helperRoot;
        }

        return balanced(helperRoot, getParent(helperRoot, first));
    }

    Node* helperSearch (Node *helperRoot, string first) {

        // if tree is empty, insert at root
        if(helperRoot == nullptr) {
            return helperRoot;
        }
        // if id is less than current id, go to left subtree
        else if (helperRoot->key > first) {
            helperRoot->left = helperSearch(helperRoot->left, first);
        }
            // if id is greater than current id, go to right subtree
        else if (helperRoot->key < first){
            helperRoot->right = helperSearch(helperRoot->right, first);
        }
            // if id is equal to current id, print unsuccessful, and return
        else if (helperRoot->key == first) {
            return helperRoot;
        }
    }

    Node* balanced(Node *helperRoot, Node* parent) {


        // root tree
        if (parent == nullptr) {
            helperRoot->redOrBlack = true;
            return helperRoot;
        }

        //parent black
        if (parent->redOrBlack == true) {
            return helperRoot;
        }

        Node* grandparent = parent->parent;

        if (grandparent == nullptr) {
            parent->redOrBlack = true;
            return helperRoot;
        }

        Node *uncle;
        if (grandparent->left != nullptr && grandparent->left == parent) {
            uncle = parent->parent->right;
        }
        else {
            uncle = parent->parent->left;
        }

        if (uncle != nullptr && uncle->redOrBlack == false) {
            parent->redOrBlack = true;
            uncle->redOrBlack = true;
            grandparent->redOrBlack = false;
            return balanced(helperRoot, grandparent);
        }
        if (helperRoot == parent->right && parent == grandparent->left) {
            leftRotation(helperRoot, parent);
            helperRoot = parent;
            parent = helperRoot->parent;
        }
        else if (helperRoot == parent->left && parent == grandparent->right) {
            rightRotation(helperRoot, parent);
            helperRoot = parent;
            parent = helperRoot->parent;
        }
        parent->redOrBlack = true;
        grandparent->redOrBlack = false;

        if(helperRoot) {
            rightRotation(helperRoot, parent);
        }
        else {
            leftRotation(helperRoot, parent);
        }

            return helperRoot;
    }

public:
    map() {root = nullptr; }

    set<string> mapSearch(int selection, string first) {
        vector<movie> m;
        inorder(root, m, first);
        set<string> recommended;

        recommended.insert(first);

        //genre
        if (selection == 1 && !m.empty()) {
           inorderHelperGenre(this->root, recommended, m.at(0).genre);
        }
            //year
        else if (selection == 2 && !m.empty()) {
            inorderHelperYear(this->root, recommended, stoi(m.at(0).year));
        }

        return recommended;

    }

    void mapInsert(string first, movie second, bool red) {
        Node* temp = getParent(root, first);

        root = (helperMapInsert(root, first, second, red, temp));
    }

};