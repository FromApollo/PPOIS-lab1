#ifndef SET_H
#define SET_H


#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Set {
protected:
    vector<string> elements;

public:
    Set();

    Set(const string& input);

    Set(const char* input);

    vector<vector<string>> getBoolean() const;

    void printBoolean() const;

    void printSet() const;

    Set operator+(const Set& otherSet) const;

    Set& operator+=(const Set& otherSet);

    Set operator*(const Set& otherSet) const;

    Set& operator*=(const Set& otherSet);

    Set operator-(const Set& otherSet) const;

    Set& operator-=(const Set& otherSet);

    vector<string> splitStringIntoElements(const string& input);

    void addElement(const string& elementToAdd);

    void deleteElement(const string& elementToDelete);

    bool operator[](const string& elementToCheck) const;

    int cardinality() const;

    bool isEmpty() const;
};

#endif
