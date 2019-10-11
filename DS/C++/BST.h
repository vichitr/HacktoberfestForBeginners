#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#include <iostream>

class NodeT
{
public:
  NodeT(int data);
  void setData(int data);
  void setLeft(NodeT *left);
  void setRight(NodeT *right);
  int getData();
  NodeT *getLeft();
  NodeT *getRight();

private:
  int data;
  NodeT *left;
  NodeT *right;
};

NodeT::NodeT(int data)
{
  this->data = data;
  this->left = NULL;
  this->right = NULL;
}

void NodeT::setData(int data)
{
  this->data = data;
}

void NodeT::setLeft(NodeT *left)
{
  this->left = left;
}

void NodeT::setRight(NodeT *right)
{
  this->right = right;
}

int NodeT::getData()
{
  return data;
}

NodeT *NodeT::getLeft()
{
  return left;
}

NodeT *NodeT::getRight()
{
  return right;
}

class BST
{
public:
  BST();
  BST(const BST &);
  void add(int data);
  bool search(int data);
  void remove(int data);
  void print(int);
  int count();
  void printLeaves();
  int height();
  int heightHelper(NodeT *);
  vector<int> getAncestors(int);
  int whatLevelAmI(int);
  int levelHelper(int, int, NodeT *);
  void levelByLevel();
  int maxWidth();
  friend bool operator==(BST, BST);
  bool areEqual(NodeT *, NodeT *);
  queue<int> toQueue();
  int nearestRelative(int, int);
  NodeT *LCA(pair<NodeT *, NodeT *>, int, int);

private:
  NodeT *root;
  void reverseInorder(NodeT *, queue<int> &);
  int howManyChildren(NodeT *T);
  int pred(NodeT *r);
  int succ(NodeT *r);
  void preorder(NodeT *);
  void postorder(NodeT *);
  void inorder(NodeT *);
  void printLeavesHelper(NodeT *);
  int countHelper(NodeT *);
  NodeT *copyPreOrder(NodeT *);
};

BST::BST()
{
  root = NULL;
  int howManyChildren(NodeT * r);
}

int BST::height()
{
  return heightHelper(root);
}

int BST::heightHelper(NodeT *r)
{
  if (!r)
    return 0;
  return 1 + max(heightHelper(r->getLeft()), heightHelper(r->getRight()));
}

vector<int> BST::getAncestors(int val)
{
  vector<int> ancestors;
  NodeT *curr = root;

  while (curr)
  {
    if (curr->getData() == val)
    {
      reverse(ancestors.begin(), ancestors.end());
      return ancestors;
    }
    if (val < curr->getData())
    {
      ancestors.push_back(curr->getData());
      curr = curr->getLeft();
    }
    else
    {
      ancestors.push_back(curr->getData());
      curr = curr->getRight();
    }
  }
  return {};
}

int BST::levelHelper(int l, int v, NodeT *r)
{
  if (!r)
    return -1;
  if (r->getData() == v)
    return l;
  int leftLevel = levelHelper(l + 1, v, r->getLeft());
  int rightLevel = levelHelper(l + 1, v, r->getRight());
  return leftLevel != -1 ? leftLevel : rightLevel;
}

int BST::whatLevelAmI(int val)
{
  return levelHelper(0, val, root);
}

NodeT *BST::copyPreOrder(NodeT *from)
{
  if (!from)
    return nullptr;
  NodeT *to = new NodeT(from->getData());
  to->setLeft(copyPreOrder(from->getLeft()));
  to->setRight(copyPreOrder(from->getRight()));
  return to;
}

BST::BST(const BST &bst)
{
  NodeT *r = bst.root;
  root = copyPreOrder(r);
}

bool BST::search(int data)
{
  NodeT *curr = root;
  while (curr != NULL)
  {
    if (curr->getData() == data)
    {
      return true;
    }
    curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
  }
  return false;
}

void BST::printLeaves() { printLeavesHelper(root); }

void BST::printLeavesHelper(NodeT *r)
{
  if (!r)
    return;
  if (!r->getLeft() && !r->getRight())
    cout << r->getData() << endl;
  printLeavesHelper(r->getLeft());
  printLeavesHelper(r->getRight());
}

int BST::count() { return countHelper(root); }

int BST::countHelper(NodeT *r)
{
  if (!r)
    return 0;
  return 1 + countHelper(r->getRight()) + countHelper(r->getLeft());
}

void BST::add(int data)
{
  NodeT *curr = root;
  NodeT *father = NULL;
  while (curr != NULL)
  {
    father = curr;
    curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
  }
  if (father == NULL)
  {
    root = new NodeT(data);
  }
  else
  {
    if (father->getData() > data)
      father->setLeft(new NodeT(data));
    else
      father->setRight(new NodeT(data));
  }
}

bool areEqual(NodeT *r1, NodeT *r2)
{
  if (!r1 && !r2)
    return true;
  if ((!r1 || !r2) || (r1->getData() != r2->getData()))
    return false;
  return areEqual(r1->getLeft(), r2->getLeft()) && areEqual(r1->getRight(), r2->getRight());
}

bool operator==(BST t1, BST t2)
{
  return areEqual(t1.root, t2.root);
}

int BST::howManyChildren(NodeT *r)
{
  int cont = 0;
  if (r->getLeft() != NULL)
    cont++;
  if (r->getRight() != NULL)
    cont++;
  return cont;
}

void BST::reverseInorder(NodeT *r, queue<int> &q)
{
  if (!r)
    return;
  reverseInorder(r->getRight(), q);
  q.push(r->getData());
  reverseInorder(r->getLeft(), q);
}

queue<int> BST::toQueue()
{
  queue<int> q;
  reverseInorder(root, q);
  return q;
}

void BST::remove(int data)
{
  NodeT *curr = root;
  NodeT *father = NULL;
  while (curr != NULL && curr->getData() != data)
  {
    father = curr;
    curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
  }
  if (curr == NULL)
    return;
  int c = howManyChildren(curr);
  switch (c)
  {
  case 0:
    if (father == NULL)
      root = NULL;
    else
    {
      if (father->getData() > data)
        father->setLeft(NULL);
      else
        father->setRight(NULL);
    }
    delete curr;
    break;
  case 1:
    if (father == NULL)
    {
      if (curr->getLeft() != NULL)
        root = curr->getLeft();
      else
        root = curr->getRight();
    }
    else
    {
      if (father->getData() > data)
      {
        if (curr->getLeft())
        {
          father->setLeft(curr->getLeft());
        }
        else
          father->setLeft(curr->getRight());
      }
      else
      {
        if (curr->getLeft())
        {
          father->setRight(curr->getLeft());
        }
        else
          father->setRight(curr->getRight());
      }
    }
    delete curr;
    break;
  case 2:
    int x = succ(curr);
    remove(x);
    curr->setData(x);
  }
}

void BST::preorder(NodeT *curr)
{
  if (!curr)
    return;
  cout << curr->getData() << endl;
  preorder(curr->getLeft());
  preorder(curr->getRight());
}

NodeT *BST::LCA(pair<NodeT *, NodeT *> nodes, int v1, int v2)
{
  if (!nodes.first)
  {
    return nodes.first;
  }
  if (nodes.first->getData() == v1 || nodes.first->getData() == v2)
  {
    return nodes.second;
  }
  NodeT *left = LCA({nodes.first->getLeft(), nodes.first}, v1, v2);
  NodeT *right = LCA({nodes.first->getRight(), nodes.first}, v1, v2);
  if (left && right)
  {
    return nodes.first;
  }
  if (left)
  {
    return left;
  }
  if (right)
  {
    return right;
  }
  return nullptr;
}

int BST::nearestRelative(int v1, int v2)
{
  if (!search(v1) || !search(v2))
    return -1;
  NodeT *nearestRel = LCA({root, NULL}, v1, v2);
  if (!nearestRel)
    return -1;
  return nearestRel->getData();
}

void BST::inorder(NodeT *curr)
{
  if (!curr)
    return;
  inorder(curr->getLeft());
  cout << curr->getData() << endl;
  inorder(curr->getRight());
}

void BST::postorder(NodeT *curr)
{
  if (!curr)
    return;
  postorder(curr->getLeft());
  postorder(curr->getRight());
  cout << curr->getData() << endl;
}

void BST::print(int x)
{
  switch (x)
  {
  case 1:
    preorder(root);
    break;
  case 2:
    inorder(root);
    break;
  case 3:
    postorder(root);
    break;
  case 4:
    printLeaves();
    break;
  case 5:
    levelByLevel();
    break;
  }
}

void BST::levelByLevel()
{
  queue<NodeT *> q;
  int l;
  if (!root)
    return;
  q.push(root);
  NodeT *curr;

  while (!q.empty())
  {
    l = q.size();
    while (l--)
    {
      curr = q.front();
      q.pop();
      cout << curr->getData() << " ";
      if (curr->getLeft())
        q.push(curr->getLeft());
      if (curr->getRight())
        q.push(curr->getRight());
    }
    cout << endl;
  }
}

int BST::pred(NodeT *r)
{
  NodeT *curr = r->getLeft();
  while (curr->getRight() != NULL)
  {
    curr = curr->getRight();
  }
  return curr->getData();
}

int BST::maxWidth()
{

  int maxW = 0;
  queue<NodeT *> q;
  NodeT *curr;
  if (!root)
    return 0;
  q.push(root);
  int l = 0;

  while (!q.empty())
  {
    l = q.size();
    maxW = max(l, maxW);
    while (l--)
    {
      curr = q.front();
      q.pop();
      if (curr->getLeft())
        q.push(curr->getLeft());
      if (curr->getRight())
        q.push(curr->getRight());
    }
  }

  return maxW;
}

int BST::succ(NodeT *r)
{
  NodeT *curr = r->getRight();
  while (curr->getLeft() != NULL)
  {
    curr = curr->getLeft();
  }
  return curr->getData();
}