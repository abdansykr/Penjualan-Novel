#ifndef BinaryTreeRekomen_
#define BinaryTreeRekomen_

#include "novel.h"
#include <iostream>

class BinarySearchTreeRekomen {

  struct node {
    Novel value;
    struct node *right;
    struct node *left;
  };

public:
  BinarySearchTreeRekomen();
  ~BinarySearchTreeRekomen();
  void add(Novel val);
  void printPreOrder();
  void printInOrder();
  void printPostOrder();
  int size();
  bool lookup(Novel val);

private:
  struct node *root;
  int treeSize;
  void add(struct node **node, Novel val);
  bool lookup(struct node *node, Novel val);
  void printPreOrder(struct node *node);
  void printInOrder(struct node *node);
  void printPostOrder(struct node *node);
  void deleteTree(struct node *node);
};

BinarySearchTreeRekomen::BinarySearchTreeRekomen() {
  this->root = NULL;
  this->treeSize = 0;
}

BinarySearchTreeRekomen::~BinarySearchTreeRekomen() { deleteTree(this->root); }

int BinarySearchTreeRekomen::size() { return this->treeSize; }

void BinarySearchTreeRekomen::add(Novel val) { add(&(this->root), val); }

void BinarySearchTreeRekomen::add(struct node **node, Novel val) {

  if (*node == NULL) {
    struct node *tmp = new struct node;
    tmp->value = val;
    tmp->left = NULL;
    tmp->right = NULL;
    *node = tmp;

    this->treeSize++;
  } else {
    if (val.idNovel > (*node)->value.idNovel) {
      add(&(*node)->right, val);
    } else {
      add(&(*node)->left, val);
    }
  }
}

void BinarySearchTreeRekomen::printInOrder() {
  printInOrder(this->root);
  std::cout << std::endl;
}

void BinarySearchTreeRekomen::printInOrder(struct node *node) {
  if (node != NULL) {
    printInOrder(node->left);
    std::cout << node->value << endl;
    printInOrder(node->right);
  }
}

void BinarySearchTreeRekomen::printPreOrder() {
  printPreOrder(this->root);
  std::cout << std::endl;
}

void BinarySearchTreeRekomen::printPreOrder(struct node *node) {
  if (node != NULL) {
    std::cout << node->value << endl;
    printInOrder(node->left);
    printInOrder(node->right);
  }
}

void BinarySearchTreeRekomen::printPostOrder() {
  printPostOrder(this->root);
  std::cout << std::endl;
}

void BinarySearchTreeRekomen::printPostOrder(struct node *node) {
  if (node != NULL) {
    printInOrder(node->left);
    printInOrder(node->right);
    std::cout << node->value << endl;
  }
}

void BinarySearchTreeRekomen::deleteTree(struct node *node) {
  if (node != NULL) {
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
  }
}

bool BinarySearchTreeRekomen::lookup(Novel val) { return lookup(this->root, val); }

bool BinarySearchTreeRekomen::lookup(struct node *node, Novel val) {
  if (node == NULL) {
    return false;
  } else {
    if (val.idNovel == node->value.idNovel) {
      return true;
    }

    if (val.idNovel > node->value.idNovel) {
      return lookup(node->right, val);
    } else {
      return lookup(node->left, val);
    }
  }
}

#endif
