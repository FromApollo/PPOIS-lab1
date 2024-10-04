#ifndef CANTORSET_H
#define CANTORSET_H

#include "Set.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class CantorSet : public Set {
private:
    struct Tree {
        vector<string> name;
        Tree* left;
        Tree* right;

        Tree(const vector<string>& name);

        ~Tree();
    };

    Tree* createCantorTree(const vector<string>& setString);


    void splitSetIntoParts(const vector<string>& setString,
        vector<string>& left,
        vector<string>& middle,
        vector<string>& right) const;

    void viewTree(Tree* root, int lvl);

public:

    CantorSet(const string& input);

    void viewCantorTree();
};

#endif


