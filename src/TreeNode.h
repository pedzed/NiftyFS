#pragma once

#include <string>

using std::string;

class TreeNode
{
    private:
        string name;

        TreeNode *parent;
        TreeNode *child;
        TreeNode *previous;
        TreeNode *next;

    public:
        TreeNode(string name);
        ~TreeNode();

        string getName();

        void setParent(TreeNode *);
        TreeNode *getParent();

        void setChild(TreeNode *);
        TreeNode *getChild();

        void setPrevious(TreeNode *);
        TreeNode *getPrevious();

        void setNext(TreeNode *);
        TreeNode *getNext();
};
