#include <iostream>
#include "TreeDumper.h"

using std::cout;
using std::endl;

TreeDumper::TreeDumper(TreeNode *rootTree, TreeVisitor *treeVisitor)
    : rootTree(rootTree),
    treeVisitor(treeVisitor)
{
    //
}

void TreeDumper::dump()
{
    Level depth = 0;
    dumpNodeLevel(rootTree, depth);
}

void TreeDumper::dumpNodeLevel(TreeNode *node, Level depth)
{
    cout << endl;

    uint8_t indentSize = (depth * 4) - 4;
    string dumpIndent = string(indentSize, ' ');
    string dumpPrefix = (node->hasNext()) ? "├── " : "└── ";

    if (depth > 1) {
        cout << dumpIndent;
    }

    if (depth > 0) {
        cout << dumpPrefix;
    }

    if (treeVisitor->isOnNode(node)) {
        cout << "[";
    }

    cout << node->getFile().getName();

    if (treeVisitor->isOnNode(node)) {
        cout << "]";
    }

    cout << " (d: " << std::to_string(depth) << ")";

    if (node->hasChild()) {
        if (node->isCollapsed()) {
            cout << " <<Collapsed>>";
        } else {
            dumpNodeLevel(node->getChild(), depth + 1);
        }
    }

    if (node->hasNext()) {
        dumpNodeLevel(node->getNext(), depth);
    }
}
