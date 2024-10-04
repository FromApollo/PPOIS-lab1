#include "cantor_set.h"

CantorSet::CantorSet(const string& input) : Set(input) {}

CantorSet::Tree::Tree(const vector <string>& name) : name(name), left(nullptr), right(nullptr) {}

CantorSet::Tree::~Tree() {
    delete left;
    delete right;
}



void CantorSet::viewCantorTree() {
    Tree* root = createCantorTree(elements);
    if (root) {
        viewTree(root, 0);
    }
    else {
        cout << "Tree is not available due to invalid input.\n";
    }
}

void CantorSet::viewTree(Tree* root, int lvl) {
    if (root) {
        viewTree(root->right, lvl + 1);
        for (int i = 0; i < lvl; i++) {
            cout << "\t";
        }
        for (const auto& elem : root->name) {
            cout << elem << " ";
        }
        cout << "\n";
        viewTree(root->left, lvl + 1);
    }
}

void CantorSet::splitSetIntoParts(const vector <string>& setString,
                                  vector <string>& left,
                                  vector <string>& middle,
                                  vector <string>& right) const {

    int size = setString.size();
    int third = size / 3;
    int remainder = size % 3;

    if (remainder == 0) {
        left = vector<string>(setString.begin(), setString.begin() + third);
        middle = vector<string>(setString.begin() + third, setString.begin() + 2 * third);
        right = vector<string>(setString.begin() + 2 * third, setString.end());
    }
    else if (remainder == 1) {
        left = vector<string>(setString.begin(), setString.begin() + third + 1);
        middle = vector<string>(setString.begin() + third + 1, setString.begin() + 2 * third + 1);
        right = vector<string>(setString.begin() + 2 * third + 1, setString.end());
    }
    else if (remainder == 2) {
        left = vector<string>(setString.begin(), setString.begin() + third + 1);
        middle = vector<string>(setString.begin() + third + 1, setString.begin() + 2 * third + 2);
        right = vector<string>(setString.begin() + 2 * third + 2, setString.end());
    }
}

CantorSet::Tree* CantorSet::createCantorTree(const vector <string>& setString) {
    if (setString.size() < 3) {
        return setString.empty() ? nullptr : new Tree(setString);
    }

    vector <string> left, middle, right;
    splitSetIntoParts(setString, left, middle, right);

    Tree* node = new Tree(setString);
    node->left=createCantorTree(left);
    node->right=createCantorTree(right);

    return node;
}







