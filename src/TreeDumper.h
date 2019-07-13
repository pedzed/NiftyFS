#pragma once

#include "TreeNode.h"
#include "TreeVisitor.h"

class TreeDumper
{
    private:
        using Level = uint8_t;
        TreeNode *rootTree;
        TreeVisitor *treeVisitor;

    public:
        TreeDumper(TreeNode *, TreeVisitor *);
        void dump();
        void dumpNodeLevel(TreeNode *, Level);
        void drawNodePrefix(TreeNode *);
};
