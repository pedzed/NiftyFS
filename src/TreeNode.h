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
};
