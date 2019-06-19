#include <iostream>
#include "FilesystemToTree.h"

FilesystemToTree::FilesystemToTree(string path)
{
    rootTree = new TreeNode(path);
    populateTreeNodes(rootTree, path);
}

FilesystemToTree::~FilesystemToTree()
{
    // depopulateTreeNodes(rootTree);
    delete rootTree;
}

void FilesystemToTree::populateTreeNodes(TreeNode *node, string path)
{
    for (auto &file : fs::directory_iterator(path)) {
        string fileName = file.path().filename().string();
        string directoryPath = file.path().string();

        TreeNode *childNode = new TreeNode(fileName);
        node->addChild(childNode);

        if (fs::is_directory(file)) {
            populateTreeNodes(childNode, directoryPath);
        }
    }
}

// void FilesystemToTree::depopulateTreeNodes(TreeNode *node)
// {
//     // TODO
// }

TreeNode *FilesystemToTree::getTree()
{
    return rootTree;
}
