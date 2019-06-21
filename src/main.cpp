#include <iostream>
#include <string>

#include "TreeNode.h"
#include "FilesystemToTree.h"
#include "TreeDumper.h"

using namespace std;

int main()
{
    cout << "Program started." << endl;

    while (true) {
        string path = "";

        cout << "Start directory: ";
        getline(cin, path);

        if (path.empty()) {
            cout << "No path entered. Default directory chosen." << endl;
            path = "/www/repos/niftyfs/bin";
        }

        try {
            FilesystemToTree filesystemToTree(path);
            TreeNode *rootTree = filesystemToTree.getTree();

            TreeDumper treeDumper(rootTree);
            treeDumper.dump();
        } catch (const fs::filesystem_error &e) {
            cerr << "Uh oh! Error '" << e.code() << "'. " << e.what() << endl;
        }
    }

    return 0;
}
