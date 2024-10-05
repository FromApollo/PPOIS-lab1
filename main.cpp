#include <iostream>
#include "Set.h"
#include "CantorSet.h"

void displayMenu();

int main() {
    Set mySet;
    CantorSet myCantorSet("");

    while (true) {
        displayMenu();
        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            string elements;
            cout << "Enter elements to add (comma-separated): ";
            cin.ignore();
            getline(cin, elements);
            vector <string> elementList = mySet.splitStringIntoElements(elements);
            for (const auto& elem : elementList) {
                mySet.addElement(elem);
            }
            break;
        }
        case 2: {
            string element;
            cout << "Enter element to remove: ";
            cin.ignore();
            getline(cin, element);
            mySet.deleteElement(element);
            break;
        }
        case 3: {
            mySet.printSet();
            break;
        }
        case 4: {
            string input;
            cout << "Enter elements for the second set (comma-separated): ";
            cin.ignore();
            getline(cin, input);
            Set otherSet(input);
            Set unionSet = mySet + otherSet;
            unionSet.printSet();
            break;
        }
        case 5: {
            string input;
            cout << "Enter elements for the second set (comma-separated): ";
            cin.ignore();
            getline(cin, input);
            Set otherSet(input);
            Set intersectionSet = mySet * otherSet;
            intersectionSet.printSet();
            break;
        }
        case 6: {
            string input;
            cout << "Enter elements for the second set (comma-separated): ";
            cin.ignore();
            getline(cin, input);
            Set otherSet(input);
            Set differenceSet = mySet - otherSet;
            differenceSet.printSet();
            break;
        }
        case 7: {
            if (mySet.isEmpty()) {
                cout << "The set is empty.\n";
            }
            else {
                cout << "The set is not empty.\n";
            }
            break;
        }
        case 8: {
            mySet.printBoolean();
            break;
        }
        case 9: {
            string input;
            cout << "Enter elements for the Cantor set (comma-separated): ";
            cin.ignore();
            getline(cin, input);
            myCantorSet = CantorSet(input);
            myCantorSet.viewCantorTree();
            break;
        }
        case 10: {
            cout << "Cardinality of the set: " << mySet.cardinality() << "\n";
            break;
        }
        case 11: {
            string element;
            cout << "Enter element to check membership: ";
            cin.ignore();
            getline(cin, element);
            if (mySet[element]) {
                cout << "Element " << element << " is in the set.\n";
            }
            else {
                cout << "Element " << element << " is NOT in the set.\n";
            }
            break;
        }
        case 0:
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
}

void displayMenu() {
    cout << "1. Add element to the set\n";
    cout << "2. Remove element from the set\n";
    cout << "3. Display set elements\n";
    cout << "4. Union of sets\n";
    cout << "5. Intersection of sets\n";
    cout << "6. Difference of sets\n";
    cout << "7. Check if set is empty\n";
    cout << "8. Display boolean algebra\n";
    cout << "9. Display Cantor set\n";
    cout << "10. Check cardinality of the set\n";
    cout << "11. Check membership of an element\n";
    cout << "0. Exit\n";
}
