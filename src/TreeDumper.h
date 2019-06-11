#pragma once

#include "TreeNode.h"

class TreeDumper
{
    private:
        using Level = uint8_t;
        TreeNode *tree;

    public:
        TreeDumper(TreeNode *);
        void dump();
        void dumpNodeLevel(TreeNode *, Level);
};
