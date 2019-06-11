#include <iostream>
#include "TreeDumper.h"

using std::cout;
using std::endl;

TreeDumper::TreeDumper(TreeNode *tree)
    : tree(tree)
{
    //
}

void TreeDumper::dump()
{
    Level depth = 0;
    dumpNodeLevel(tree, depth);
}

void TreeDumper::dumpNodeLevel(TreeNode *node, Level depth)
{
    uint8_t indentSize = (depth * 4) - 4;
    string dumpIndent = string(indentSize, ' ');
    string dumpPrefix = (node->hasNext()) ? "├── " : "└── ";

    if (depth > 1) {
        cout << dumpIndent;
    }

    if (depth > 0) {
        cout << dumpPrefix;
    }

    cout << node->getName() << " (d: " << std::to_string(depth) << ")" << endl;

    if (node->hasChild()) {
        dumpNodeLevel(node->getChild(), depth + 1);
    }

    if (node->hasNext()) {
        dumpNodeLevel(node->getNext(), depth);
    }
}
