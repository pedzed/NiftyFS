#pragma once

#include <string>
#include <boost/filesystem.hpp>

#include "TreeNode.h"

using string = std::string;
namespace fs = boost::filesystem;

class FilesystemToTree
{
    private:
        TreeNode *rootTree;

        void populateTreeNodes(TreeNode *node, string path);
        void depopulateTreeNodes(TreeNode *node);

    public:
        FilesystemToTree(string path);
        ~FilesystemToTree();

        TreeNode *getTree();
};
