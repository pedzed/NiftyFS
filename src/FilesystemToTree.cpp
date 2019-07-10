#include <iostream>
#include "FilesystemToTree.h"

FilesystemToTree::FilesystemToTree(string path)
{
    auto directoryEntry = fs::directory_entry(path);
    File file(directoryEntry);
    rootTree = new TreeNode(file);

    populateTreeNodes(rootTree, path);
}

FilesystemToTree::~FilesystemToTree()
{
    delete rootTree;
}

void FilesystemToTree::populateTreeNodes(TreeNode *node, string path)
{
    // if (!fs::exists(path)) {
    //     std::cout << "Path '" << path << "' does not exist." << std::endl;
    //     return;
    // }

    for (auto &directoryEntry : fs::directory_iterator(path)) {
        File file(directoryEntry);

        TreeNode *childNode = new TreeNode(file);
        node->addChild(childNode);

        if (file.isDirectory() && !file.isExtension(".app")) {
            string directoryPath = file.getAbsolutePath();
            populateTreeNodes(childNode, directoryPath);
        }
    }
}

TreeNode *FilesystemToTree::getTree()
{
    return rootTree;
}
