#pragma once

#include "File.h"

class TreeNode
{
    private:
        File file;

        bool isExpanded_;

        TreeNode *parent;
        TreeNode *child;
        TreeNode *previous;
        TreeNode *next;

    public:
        TreeNode(File);
        ~TreeNode();

        File getFile();

        void expand();
        bool isExpanded();

        void collapse();
        bool isCollapsed();

        void toggleExpandAndCollapse();

        void setParent(TreeNode *);
        bool hasParent();
        TreeNode *getParent();

        void addChild(TreeNode *);
        void setChild(TreeNode *);
        bool hasChild();
        TreeNode *getChild();

        void setPrevious(TreeNode *);
        bool hasPrevious();
        TreeNode *getPrevious();

        void setNext(TreeNode *);
        bool hasNext();
        TreeNode *getNext();

        bool isRoot();
        bool isLast();
};
