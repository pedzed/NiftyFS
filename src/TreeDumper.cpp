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

    if (!node->isRoot()) {
        drawNodePrefix(node);
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

void TreeDumper::drawNodePrefix(TreeNode *node)
{
    uint8_t indentSize = 4;
    string dumpPrefix = (node->isLast()) ? "└── " : "├── ";

    for (
        TreeNode *currentParent = node->getParent();
        currentParent->hasParent();
        currentParent = currentParent->getParent()
    ) {
        if (!currentParent->hasNext()) {
            dumpPrefix = string(indentSize, ' ') + dumpPrefix;
            continue;
        }

        dumpPrefix = "│" + string(indentSize - 1, ' ') + dumpPrefix;
    }

    cout << dumpPrefix;
}
