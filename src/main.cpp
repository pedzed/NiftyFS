#include <iostream>
#include <string>

#include "TreeNode.h"
#include "TreeVisitor.h"
#include "TreeDumper.h"
#include "FilesystemToTree.h"
#include "KeyEventListener.h"
#include "ProcessRunner.h"

using namespace std;

int main()
{
    cout << "Program started." << endl;

    KeyEventListener keyEventListener;

    while (true) {
        string path = "";

        // cout << "Explore directory: ";
        // getline(cin, path);

        if (path.empty()) {
            // cout << "No path entered. Default directory chosen." << endl;
            path = "/Users/pedzed/repos/niftyfs/bin";
        }

        try {
            FilesystemToTree filesystemToTree(path);

            TreeNode *rootNode = filesystemToTree.getTree();
            TreeVisitor treeVisitor(rootNode);

            TreeDumper treeDumper(rootNode, &treeVisitor);
            treeDumper.dump();

            while (true) {
                keyEventListener.update();

                cout << "\033c"; // Clear console on UNIX

                if (keyEventListener.hasPressedKeyLeft()) {
                    treeVisitor.moveLeft();
                } else if (keyEventListener.hasPressedKeyRight()) {
                    treeVisitor.moveRight();
                } else if (keyEventListener.hasPressedKeyUp()) {
                    treeVisitor.moveUp();
                } else if (keyEventListener.hasPressedKeyDown()) {
                    treeVisitor.moveDown();
                } else if (keyEventListener.hasPressedKeyE()) {
                    treeVisitor.getNode()->toggleExpandAndCollapse();
                } else if (keyEventListener.hasPressedKeySpace()) {
                    ProcessRunner processRunner;
                    processRunner.run(ProcessType::VSCODE, treeVisitor.getNode()->getFile());
                } else if (keyEventListener.hasPressedKeyEsc()) {
                    return 0;
                }

                treeDumper.dump();
            }
        } catch (const fs::filesystem_error &e) {
            cerr << "Uh oh! Error '" << e.code() << "'. " << e.what() << endl;
        }
    }

    return 0;
}
