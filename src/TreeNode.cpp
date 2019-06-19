#include "TreeNode.h"

TreeNode::TreeNode(string name)
    : name(name)
{
    // parent = NULL;
    child = NULL;
    // previous = NULL;
    next = NULL;
}

TreeNode::~TreeNode()
{
    // delete parent;
    delete child;
    // delete previous;
    delete next;
}

string TreeNode::getName()
{
    return name;
}

// void TreeNode::setParent(TreeNode *node)
// {
//     parent = node;
// }

// bool TreeNode::hasParent()
// {
//     return (parent != NULL);
// }

// TreeNode *TreeNode::getParent()
// {
//     return parent;
// }

void TreeNode::addChild(TreeNode *node)
{
    if (!hasChild()) {
        setChild(node);
        return;
    }

    TreeNode *currentLast = child;
    for (; currentLast->hasNext(); currentLast = currentLast->getNext());

    currentLast->setNext(node);
}

void TreeNode::setChild(TreeNode *node)
{
    child = node;
    // child->parent = this;
}

bool TreeNode::hasChild()
{
    return (child != NULL);
}

TreeNode *TreeNode::getChild()
{
    return child;
}

// void TreeNode::setPrevious(TreeNode *node)
// {
//     previous = node;
// }

// bool TreeNode::hasPrevious()
// {
//     return (previous != NULL);
// }

// TreeNode *TreeNode::getPrevious()
// {
//     return previous;
// }

void TreeNode::setNext(TreeNode *node)
{
    next = node;
    // next->previous = this;
}

bool TreeNode::hasNext()
{
    return (next != NULL);
}

TreeNode *TreeNode::getNext()
{
    return next;
}
