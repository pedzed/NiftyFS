#include <iostream>
#include "FilesystemToTree.h"

FilesystemToTree::FilesystemToTree(string path)
{
    rootTree = new TreeNode(path);
    populateTreeNodes(rootTree, path);
}

FilesystemToTree::~FilesystemToTree()
{
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

TreeNode *FilesystemToTree::getTree()
{
    return rootTree;
}
