#pragma once

#include "TreeNode.h"

class TreeVisitor
{
    private:
        TreeNode *node;

    public:
        TreeVisitor(TreeNode *startingNode);
        ~TreeVisitor();

        void setNode(TreeNode *node);
        TreeNode *getNode();
        bool isOnNode(TreeNode *node);

        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();
};
