#include <iostream>
#include <string>

#include "TreeNode.h"
#include "FilesystemToTree.h"
#include "TreeDumper.h"

using namespace std;

int main()
{
    cout << "Program started." << endl;

    string path = "/www/repos/niftyfs/bin";

    FilesystemToTree filesystemToTree(path);
    TreeNode *rootTree = filesystemToTree.getTree();

    TreeDumper treeDumper(rootTree);
    treeDumper.dump();

    return 0;
}
