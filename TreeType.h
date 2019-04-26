#include <string>
#include <fstream>

typedef int ItemType;
struct TreeNode;
#include "QueType.h"

enum OrderType {PRE_ORDER, IN_ORDER, POST_ORDER};

class TreeType
{
public:
  TreeType();                    // constructor
 ~TreeType();                    // destructor
  TreeType(const TreeType& originalTree);
  void operator=(const TreeType& originalTree);
  // copy constructor
  void MakeEmpty();
  bool IsEmpty() const;
  bool IsFull() const;
  int GetLength() const;
  ItemType GetItem(ItemType item, bool& found);
  void PutItem(ItemType item);
  void DeleteItem(ItemType item);
  void ResetTree(OrderType order);
  ItemType GetNextItem(ItemType& item, OrderType order, bool& finished);
  void Print(std::ofstream& outFile) const;
  // Exercise 6
  ItemType Ancestors(ItemType item, bool& found, std::ofstream& outFile);
  ItemType AncestorsReverse(ItemType item, bool& found, std::ofstream& outFile);
  ItemType LeafCount(int leaves);
  ItemType SingleParentCount(int spcount);

private:
  TreeNode* root;
  QueType preQue;
  QueType inQue;
  QueType postQue;
};
