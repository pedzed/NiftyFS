#include "TreeNode.h"

TreeNode::TreeNode(string name)
    : name(name)
{
    parent = NULL;
    child = NULL;
    previous = NULL;
    next = NULL;
}

TreeNode::~TreeNode()
{
    //
}

string TreeNode::getName()
{
    return name;
}

// void TreeNode::setParent(TreeNode *node)
// {
//     parent = node;
// }

TreeNode *TreeNode::getParent()
{
    return parent;
}

void TreeNode::setChild(TreeNode *node)
{
    child = node;
    // child->parent = this;
}

TreeNode *TreeNode::getChild()
{
    return child;
}

// void TreeNode::setPrevious(TreeNode *node)
// {
//     previous = node;
// }

TreeNode *TreeNode::getPrevious()
{
    return previous;
}

void TreeNode::setNext(TreeNode *node)
{
    next = node;
    // next->previous = this;
}

TreeNode *TreeNode::getNext()
{
    return next;
}
