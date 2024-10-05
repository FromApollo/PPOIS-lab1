#include "Set.h"


Set::Set(const string& input) {
    elements = splitStringIntoElements(input);
}

Set::Set() {}

Set::Set(const char* input) {
    string strInput(input);
    elements = splitStringIntoElements(strInput);
}

vector <vector<string>> Set::getBoolean() const {
    vector <vector<string>> boolean;
    int totalSubsets = 1 << elements.size();

    for (int i = 0; i < totalSubsets; ++i) {
        vector <string> subset;
        for (int j = 0; j < elements.size(); ++j) {
            if (i & (1 << j)) {
                subset.push_back(elements[j]);
            }
        }
        boolean.push_back(subset);
    }
    return boolean;
}

void Set::printBoolean() const {
    vector <vector<string>> bullean = getBoolean();
    cout << "Bullean:\n";
    for (const auto& subset : bullean) {
        cout << "{ ";
        for (const auto& elem : subset) {
            cout << elem << " ";
        }
        cout << "}\n";
    }
}

void Set::printSet() const {
    if (elements.empty()) {
        cout << "Set is empty.\n";
        return;
    }

    cout << "Set elements: { ";
    for (const auto& element : elements) {
        cout << element << " ";
    }
    cout << "}\n";
}

Set Set::operator+(const Set& otherSet) const {
    Set mergedSet = *this;
    for (auto& element : otherSet.elements) {
        if (!mergedSet[element]) {
            mergedSet.elements.push_back(element);
        }
    }
    return mergedSet;
}

Set& Set::operator+=(const Set& otherSet) {
    for (auto& element : otherSet.elements) {
        if (!(*this)[element]) {
            elements.push_back(element);
        }
    }
    return *this;
}

Set Set::operator*(const Set& otherSet) const {
    Set intersectedSet;
    for (const auto& element : elements) {
        if (otherSet[element]) {
            intersectedSet.elements.push_back(element);
        }
    }
    return intersectedSet;
}

Set& Set::operator*=(const Set& otherSet) {
    auto it = elements.begin();
    while (it != elements.end()) {
        if (!otherSet[*it]) {
            deleteElement(*it);
        }
        else ++it;
    }
    return *this;
}

Set Set::operator-(const Set& otherSet) const {
    Set differenceSet = *this;
    for (const auto& element : otherSet.elements) {
        if (differenceSet[element]) {
            differenceSet.deleteElement(element);
        }
    }
    return differenceSet;
}

Set& Set::operator-=(const Set& otherSet) {
    for (const auto& element : otherSet.elements) {
        if ((*this)[element]) {
            deleteElement(element);
        }
    }
    return *this;
}

vector <string> Set::splitStringIntoElements(const string& input) {
    vector <string> elements;
    string currentElement;
    int braceLevel = 0;

    for (char ch : input) {
        if (ch == '{') {
            braceLevel++;
        }
        else if (ch == '}') {
            braceLevel--;
        }

        if (ch == ',' && braceLevel == 0) {
            elements.push_back(currentElement);
            currentElement.clear();
        }
        else {
            currentElement += ch;
        }
    }

    if (!currentElement.empty()) {
        elements.push_back(currentElement);
    }

    return elements;
}


void Set::addElement(const string& elementToAdd) {
    if ((*this)[elementToAdd]) {
        cout << "Element already exists\n";
        return;
    }
    else {
        elements.push_back(elementToAdd);
    }
}

void Set::deleteElement(const string& elementToDelete) {
    for (auto it = elements.begin(); it != elements.end(); ++it) {
        if (*it == elementToDelete) {
            elements.erase(it);
            return;
        }
    }
    cout << "Element does NOT exist\n";
}

bool Set::operator[](const string& elementToCheck) const {
    for (auto element : elements) {
        if (element == elementToCheck) return true;
    }
    return false;
}

int Set::cardinality() const {
    return elements.size();
}

bool Set::isEmpty() const {
    return elements.empty();
}

