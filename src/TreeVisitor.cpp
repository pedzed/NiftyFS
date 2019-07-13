#include "TreeVisitor.h"

TreeVisitor::TreeVisitor(TreeNode *startingNode)
    : node(startingNode)
{
    //
}

TreeVisitor::~TreeVisitor()
{
    //
}

void TreeVisitor::setNode(TreeNode *node)
{
    this->node = node;
}

TreeNode *TreeVisitor::getNode()
{
    return node;
}

bool TreeVisitor::isOnNode(TreeNode *node)
{
    return (getNode() == node);
}

void TreeVisitor::moveUp()
{
    if (node->hasPrevious()) {
        node = node->getPrevious();
    }
}

void TreeVisitor::moveDown()
{
    if (node->hasNext()) {
        node = node->getNext();
    }
}

void TreeVisitor::moveLeft()
{
    if (node->hasParent()) {
        node = node->getParent();
    }
}

void TreeVisitor::moveRight()
{
    if (node->hasChild() && node->isExpanded()) {
        node = node->getChild();
    }
}
