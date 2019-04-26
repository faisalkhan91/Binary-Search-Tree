#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstring>

#include "TreeType.h"
#include "tools.hpp"

using namespace std;

void MakeTree(TreeType& tree, int info[],int toIndex,int fromIndex);
void AddElements(TreeType &tree, int info[], int toIndex, int fromIndex);
int Count(TreeType& tree, ItemType value);

int menuSelection(void);

int main()
{
    banner(); // Call to banner

    int item;
    TreeType tree;
    bool found;
    int * info;

    int select;
    string option;

    ofstream outFile;      // file containing output
    string outFileName = "out";
    string outputLabel = "Tree";
    outFile.open(outFileName.c_str(), ios::out | ios::app);
    outFile << "\n[" << outputLabel << "]" << endl << endl;

    do{
        select = menuSelection();
        switch(select)
        {
            // Case to run the ancestor function (iterative)
            case 1:
                do{
                    cout << "Input the element whose ancestors are to be displayed: " << endl;
                    // Get the node for which ancestor is to be printed
                    cin >> item;

                    tree.GetItem(item, found);

                    if (found)
                    {
                        outFile << "The ancestors for " << item << " are: " << endl;
                        cout << "The ancestors for " << item << " are: " << endl;
                        // Function call to ancestor
                        tree.Ancestors(item, found, outFile);
                    }
                    else
                    {
                        outFile << "Element not present in the tree." << endl;
                        cout << "Element not present in the tree." << endl;
                    }

                    cout << "\n -> Do you want to print ancestors of another element? [Y/N]";
                    getline(cin>>ws, option);

                    }while(option == "Y" || option == "y" || option == "Yes");
                break;
            // Case to insert elements
            case 2:
                do{
                    cout << "Please enter the element to be inserted: " << endl;
                    cin >> item;
                    // Function call to putitem
                    tree.PutItem(item);
                    outFile << item << " is inserted" << endl;
                    cout << item << " is inserted" << endl;

                    cout <<"\n -> Do you want to insert another element? [Y/N]";
                    getline(cin>>ws, option);

                    }while(option == "Y" || option == "y" || option == "Yes");
                break;
            // Case to delete elements
            case 3:
                do{
                    cout << "Please enter the element to be deleted: " << endl;
                    cin >> item;
                    // Function call to deleteitem
                    tree.DeleteItem(item);
                    outFile << item << " is deleted" << endl;
                    cout << item << " is deleted" << endl;

                    cout <<"\n -> Do you want to delete another element? [Y/N]";
                    getline(cin>>ws, option);

                    }while(option == "Y" || option == "y" || option == "Yes");
                break;
            // Case to run the ancestor function recursively and print the ancestors
            case 4:
                do{
                    cout << "Input the element whose ancestors are to be displayed: " << endl;
                    cin >> item;
                    // Function call to getitem
                    tree.GetItem(item, found);

                    if (found)
                    {
                        outFile << "The ancestors for " << item << " are: " << endl;
                        cout << "The ancestors for " << item << " are: " << endl;
                        // Function call to Ancestors function to print in reverse
                        tree.AncestorsReverse(item, found, outFile);
                    }
                    else
                    {
                        outFile << "Element not present in the tree." << endl;
                        cout << "Element not present in the tree." << endl;
                    }

                    cout << "\n -> Do you want to print ancestors of another element? [Y/N]";
                    getline(cin>>ws, option);

                    }while(option == "Y" || option == "y" || option == "Yes");
                break;
            // Case to run the Make tree function
            case 5:
                {
                    int length;
                    cout << "Enter the number of elements you want to insert: " << endl;
                    cin >> length;
                    info = new int[length];

                    for(int j = 0; j < length; j++)
                    {
                        cout << "Insert element: " << endl;
                        cin >> info[j];
                    }
                    length--;
                    // Function call to Maketree function
                    MakeTree(tree, info, length, 0);
                }
                break;
            // Case to print tree elements
            case 6:
                do{
                    // function call to print function
                    tree.Print(outFile);

                    cout <<"\n -> Do you want to print again? [Y/N]";
                    getline(cin>>ws, option);

                    }while(option == "Y" || option == "y" || option == "Yes");
                break;
            //Case to print the leaf nodes of the tree
            case 7:
                do{
                    int leaves = 0;
                    // function call to leafcount function
                    leaves = tree.LeafCount(leaves);

                    outFile << "Leaf count of tree is " << leaves << endl;
                    cout << "Leaf count of tree is " << leaves << endl;

                    cout <<"\n -> Do you want to print again? [Y/N]";
                    getline(cin>>ws, option);

                    }while(option == "Y" || option == "y" || option == "Yes");
                break;
            // Case to run function to print the single parents in a tree
            case 8:
                do{
                    int spcount = 0;
                    // function call to single parent count function
                    spcount = tree.SingleParentCount(spcount);

                    outFile << "Single Parent count of tree is " << spcount << endl;
                    cout << "Single Parent count of tree is " << spcount << endl;

                    cout <<"\n -> Do you want to print again? [Y/N]";
                    getline(cin>>ws, option);

                    }while(option == "Y" || option == "y" || option == "Yes");
                break;
            case 9:
                do{
                    int value;

                    cout << "Enter a value:" << endl;
                    cin >> value;
                    // function call to count function
                    value = Count(tree, value);

                    outFile << "Node count of values less than parameter is " << value << endl;
                    cout << "Node count of values less than parameter is " << value << endl;

                    cout <<"\n -> Do you want to print again? [Y/N]";
                    getline(cin>>ws, option);

                    }while(option == "Y" || option == "y" || option == "Yes");
                break;
            // Case to display a message and quit the program.
            case 10:
                cout<<"\nGood Bye!!!"<<endl;
                break;

            default:
                cout << "Error: Invalid selection. Please try again!" << endl;
        }
    }while(select !=10);

    outFile.close();

    bye();

    return 0;
}

int menuSelection(void)
// Function: Displays Preconditions for the program and the Switch case menu.
// Precondition: Initializes select.
// Postcondition: Return users choice.
{
    int select;

    cout << "\t Binary Search Tree Operations \n" << endl;

    // Menu choices
    cout << " MENU OPTIONS " << endl;
    cout << "1. Print ancestors(iterative)" << endl;
    cout << "2. Insert" << endl;
    cout << "3. Delete" << endl;
    cout << "4. Print ancestors(reverse)" << endl;
    cout << "5. Make Tree" << endl;
    cout << "6. Print Tree" << endl;
    cout << "7. Leaf Count" << endl;
    cout << "8. Single Parent Count" << endl;
    cout << "9. Node count with value less than parameter value" << endl;
    cout << "10. Quit" << endl;
    cout << "Select:_";
    cin >> select;

    return select;
}

// Function to call Add Elements
void MakeTree(TreeType& tree, int info[],int toIndex,int fromIndex)
{
    AddElements(tree, info, toIndex, fromIndex);
}

// Function that runs Make tree function to print elements in sorted order
void AddElements(TreeType &tree, int info[], int toIndex, int fromIndex)
{
    if(toIndex < fromIndex)
    {
        cout << "\n No more elements can be inserted" << endl;
        return;
    }
    else
    {
        tree.PutItem(info[fromIndex]);
        fromIndex++;
        MakeTree(tree,info,toIndex,fromIndex);
    }

}

typedef int ItemType;
int Count(TreeType& tree, ItemType value)
// Pre: Tree has been initialized.
// Post: Function value = the number of nodes in tree that contain values that are less than value.
{
    ItemType item;
    bool finished = false;
    int number = 0; // Sum of number of items < value

    if (tree.IsEmpty())
        return 0;
    else{
        tree.ResetTree(IN_ORDER);
        // By using an inorder traversal, the process can stop when a larger value is returned.
        while(!finished)
        {
            tree.GetNextItem(item, IN_ORDER, finished);
            if (item < value)
                number ++;
            else
                finished = true;
        }
        return number;
    }
}
