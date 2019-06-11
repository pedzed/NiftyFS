#include <iostream>
#include <string>

#include "TreeNode.h"

using namespace std;

int main()
{
    cout << "Program started." << endl;

    TreeNode rootTree("🎄");

        TreeNode homeDirectory("home");
        rootTree.addChild(&homeDirectory);

            TreeNode pedDirectory("ped");
            homeDirectory.addChild(&pedDirectory);

                TreeNode documentsDirectory("documents");
                pedDirectory.addChild(&documentsDirectory);

                TreeNode imagesDirectory("images");
                pedDirectory.addChild(&imagesDirectory);

        TreeNode optDirectory("opt");
        rootTree.addChild(&optDirectory);

        TreeNode varDirectory("var");
        rootTree.addChild(&varDirectory);

        TreeNode binDirectory("bin");
        rootTree.addChild(&binDirectory);

    cout << rootTree.getName();

    cout << "/" << rootTree.getChild()->getName();
    cout << "/" << rootTree.getChild()->getChild()->getName();
    cout << "/" << rootTree.getChild()->getChild()->getChild()->getName();

    return 0;
}
