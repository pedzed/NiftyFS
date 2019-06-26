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
        bool isOnNode(TreeNode *node);

        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();
};
