#include <iostream>
using namespace std;

template <class T>
class Node
{
public:
  T getVal();
  Node<T> *getNext();
  Node();
  Node(T);
  Node(T, Node<T> *);
  void setVal(T);
  void setNext(Node<T> *);

private:
  T val;
  Node<T> *next;
};

template <class T>
Node<T>::Node() : val(-1), next(NULL) {}

template <class T>
Node<T>::Node(T v) : val(v), next(NULL) {}

template <class T>
Node<T>::Node(T v, Node<T> *n) : val(v), next(n) {}

template <class T>
T Node<T>::getVal() { return val; }

template <class T>
Node<T> *Node<T>::getNext() { return next; }

template <class T>
void Node<T>::setVal(T v) { val = v; }

template <class T>
void Node<T>::setNext(Node<T> *n) { next = n; }

template <class T>
class LinkedList
{
private:
  Node<T> *head;
  int size;

public:
  LinkedList();
  LinkedList(T);
  LinkedList(LinkedList<T> &);
  void addFirst(T);
  void addLast(T);
  bool add(int, T);
  void deleteFirst();
  void deleteLast();
  void del(int);
  bool isEmpty();
  int deleteAll();
  bool change(int, int);
  Node<T> *get(int);
  Node<T> *set(T, int);
  int getSize();
  void reverse();
  void print();
  bool operator==(LinkedList<T> &);
  void operator+=(T);
  void operator+=(LinkedList<T> &);
  void shift(int);
};

template <class T>
int LinkedList<T>::deleteAll()
{
  int s = size;

  if (size == 1)
  {
    deleteFirst();
    head = NULL;
    return 1;
  }

  Node<T> *prev = head;
  Node<T> *curr = prev->getNext();

  while (curr)
  {
    delete prev;
    prev = curr;
    curr = curr->getNext();
  }

  size = 0;
  head = NULL;
  return s;
}

template <class T>
void LinkedList<T>::shift(int v)
{
  if (v < 0)
    v = size + v;

  v %= size;

  if (v == 0)
    return;
  int i = 1;
  Node<T> *curr = head, *prev = head;

  Node<T> *oldHead = head;

  while (i++ != size - v + 1)
  {
    prev = curr;
    curr = curr->getNext();
  }
  prev->setNext(NULL);
  head = curr;

  while (curr->getNext())
    curr = curr->getNext();

  curr->setNext(oldHead);
}

template <class T>
void LinkedList<T>::operator+=(LinkedList<T> &l2)
{
  Node<T> *curr = head;
  Node<T> *c2 = l2.get(0);

  while (curr->getNext())
    curr = curr->getNext();

  while (c2)
  {
    curr->setNext(new Node<T>(c2->getVal()));
    curr = curr->getNext();
    c2 = c2->getNext();
    ++size;
  }
}

template <class T>
Node<T> *LinkedList<T>::get(int k)
{

  if (k >= size)
    return NULL;

  int i = 0;

  Node<T> *curr = head;

  while (i++ < k)
    curr = curr->getNext();

  return curr;
}

template <class T>
bool LinkedList<T>::change(int a, int b)
{

  if (a >= size || b >= size)
    return false;

  Node<T> *n1 = get(a);
  Node<T> *n2 = get(b);

  int temp = n1->getVal();

  n1->setVal(n2->getVal());
  n2->setVal(temp);

  return true;
}

template <class T>
void LinkedList<T>::reverse()
{
  Node<T> *curr = head;
  Node<T> *prev = NULL;
  Node<T> *temp;

  while (curr)
  {
    temp = curr->getNext();
    curr->setNext(prev);
    prev = curr;
    curr = temp;
  }

  head = prev;
}

template <class T>
void LinkedList<T>::operator+=(T val)
{
  Node<T> *toAdd = new Node<T>(val);
  Node<T> *curr = head;
  ++size;
  if (!head)
  {
    head = toAdd;
    return;
  }

  while (curr->getNext())
    curr = curr->getNext();

  curr->setNext(toAdd);
}

template <class T>
bool LinkedList<T>::operator==(LinkedList<T> &l2)
{
  Node<T> *curr1 = head;
  Node<T> *curr2 = l2.get(0);

  if (!curr1 && !curr2)
    return true;
  else if (!curr1 || !curr2)
  {
    return false;
  }
  while (curr1 || curr2)
  {
    if (!curr1 || !curr2)
      return false;
    if (curr1->getVal() != curr2->getVal())
    {
      return false;
    }
    curr1 = curr1->getNext();
    curr2 = curr2->getNext();
  }
  return true;
}

template <class T>
Node<T> *LinkedList<T>::set(T v, int k)
{

  if (k >= size)
    return NULL;

  Node<T> *n = new Node<T>(v);

  int i = 0;

  if (k == 0)
  {
    Node<T> *nxt = head->getNext();
    head = n;
    head->setNext(nxt);
    return n;
  }

  Node<T> *prev = head;

  while (++i < k)
  {
    prev = prev->getNext();
  }

  Node<T> *next = NULL;

  if (prev->getNext())
    next = prev->getNext()->getNext();

  prev->setNext(n);
  n->setNext(next);
  return n;
}

template <class T>
LinkedList<T>::LinkedList() : size(0), head(NULL) {}

template <class T>
LinkedList<T>::LinkedList(T v) : size(1), head(new Node<T>(v)) {}

template <class T>
LinkedList<T>::LinkedList(LinkedList<T> &ll) : size(0)
{
  if (!ll.get(0))
  {
    head = NULL;
  }
  else
  {
    Node<T> *curr = ll.get(0)->getNext();
    Node<T> *prev = new Node<T>(ll.get(0)->getVal());
    head = prev;
    while (curr)
    {
      prev->setNext(new Node<T>(curr->getVal()));
      prev = prev->getNext();
      curr = curr->getNext();
      ++size;
    }
  }
}

template <class T>
bool LinkedList<T>::isEmpty() { return size == 0; }

template <class T>
void LinkedList<T>::addFirst(T v)
{
  Node<T> *newHead = new Node<T>(v);
  newHead->setNext(head);
  head = newHead;
  ++size;
}

template <class T>
void LinkedList<T>::addLast(T v)
{
  Node<T> *newLast = new Node<T>(v);
  if (!head)
  {
    head = newLast;
    ++size;
    return;
  }
  Node<T> *curr = head;

  while (curr->getNext())
  {
    curr = curr->getNext();
  }

  curr->setNext(newLast);
  ++size;
}

template <class T>
void LinkedList<T>::deleteFirst()
{
  if (head)
  {
    Node<T> *curr = head;
    head = head->getNext();
    delete curr;
    --size;
  }
}

template <class T>
void LinkedList<T>::deleteLast()
{

  if (!head)
    return;

  if (size == 1)
  {
    deleteFirst();
    --size;
    return;
  }

  Node<T> *curr = head;

  while (curr->getNext()->getNext())
  {
    curr = curr->getNext();
  }
  delete curr->getNext();
  --size;
  curr->setNext(NULL);
}

template <class T>
int LinkedList<T>::getSize() { return size; }

template <class T>
bool LinkedList<T>::add(int k, T v)
{
  Node<T> *n = new Node<T>(v);
  if (k > size)
    return false;

  if (size == 1)
  {
    addFirst(n);
    return true;
  }
  int i = 1;

  ++size;

  Node<T> *curr = head;
  Node<T> *prev = head;

  while (i++ != k)
  {
    prev = curr;
    curr = curr->getNext();
  }

  prev->setNext(n);
  n->setNext(curr);
  return true;
}

template <class T>
void LinkedList<T>::del(int k)
{

  if (k > size)
    return;

  if (k == 1)
  {
    deleteFirst();
    return;
  }

  int n = 1;
  Node<T> *curr = head;

  while (n++ != k - 1)
  {
    curr = curr->getNext();
  }
  Node<T> *toDel = curr->getNext();
  curr->setNext(toDel->getNext());
  delete toDel;
  --size;
}

template <class T>
void LinkedList<T>::print()
{
  Node<T> *curr = head;
  while (curr)
  {
    cout << curr->getVal() << "->";
    curr = curr->getNext();
  }
  cout << "NULL" << endl;
}