#ifndef BinaryTree_
#define BinaryTree_

#include "pelanggan.h"
#include <iostream>

class BinarySearchTree {

  struct node {
    PELANGGAN value;
    struct node *right;
    struct node *left;
  };

public:
  BinarySearchTree();
  ~BinarySearchTree();
  void add(PELANGGAN val);
  void printPreOrder();
  void printInOrder();
  void printPostOrder();
  int size();
  bool lookup(PELANGGAN val);

private:
  struct node *root;
  int treeSize;
  void add(struct node **node, PELANGGAN val);
  bool lookup(struct node *node, PELANGGAN val);
  void printPreOrder(struct node *node);
  void printInOrder(struct node *node);
  void printPostOrder(struct node *node);
  void deleteTree(struct node *node);
};

BinarySearchTree::BinarySearchTree() {
  this->root = NULL;
  this->treeSize = 0;
}

BinarySearchTree::~BinarySearchTree() { deleteTree(this->root); }

int BinarySearchTree::size() { return this->treeSize; }

void BinarySearchTree::add(PELANGGAN val) { add(&(this->root), val); }

void BinarySearchTree::add(struct node **node, PELANGGAN val) {

  if (*node == NULL) {
    struct node *tmp = new struct node;
    tmp->value = val;
    tmp->left = NULL;
    tmp->right = NULL;
    *node = tmp;

    this->treeSize++;
  } else {
    if (val.id > (*node)->value.id) {
      add(&(*node)->right, val);
    } else {
      add(&(*node)->left, val);
    }
  }
}

void BinarySearchTree::printInOrder() {
  printInOrder(this->root);
  std::cout << std::endl;
}

void BinarySearchTree::printInOrder(struct node *node) {
  if (node != NULL) {
    printInOrder(node->left);
    std::cout << node->value << endl;
    printInOrder(node->right);
  }
}

void BinarySearchTree::printPreOrder() {
  printPreOrder(this->root);
  std::cout << std::endl;
}

void BinarySearchTree::printPreOrder(struct node *node) {
  if (node != NULL) {
    std::cout << node->value << endl;
    printInOrder(node->left);
    printInOrder(node->right);
  }
}

void BinarySearchTree::printPostOrder() {
  printPostOrder(this->root);
  std::cout << std::endl;
}

void BinarySearchTree::printPostOrder(struct node *node) {
  if (node != NULL) {
    printInOrder(node->left);
    printInOrder(node->right);
    std::cout << node->value << endl;
  }
}

void BinarySearchTree::deleteTree(struct node *node) {
  if (node != NULL) {
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
  }
}

bool BinarySearchTree::lookup(PELANGGAN val) { return lookup(this->root, val); }

bool BinarySearchTree::lookup(struct node *node, PELANGGAN val) {
  if (node == NULL) {
    return false;
  } else {
    if (val.id == node->value.id) {
      return true;
    }

    if (val.id > node->value.id) {
      return lookup(node->right, val);
    } else {
      return lookup(node->left, val);
    }
  }
}

#endif
