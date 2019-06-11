#include <iostream>
#include <string>

#include "TreeNode.h"
#include "TreeDumper.h"

using namespace std;

int main()
{
    cout << "Program started." << endl;

    TreeNode rootTree("/");

        TreeNode homeDirectory("/home");
        rootTree.addChild(&homeDirectory);

            TreeNode pedDirectory("/ped");
            homeDirectory.addChild(&pedDirectory);

                TreeNode documentsDirectory("/documents");
                pedDirectory.addChild(&documentsDirectory);

                TreeNode imagesDirectory("/images");
                documentsDirectory.addNext(&imagesDirectory);

                TreeNode videosDirectory("/videos");
                documentsDirectory.addNext(&videosDirectory);

        TreeNode optDirectory("/opt");
        homeDirectory.addNext(&optDirectory);

        TreeNode varDirectory("/var");
        homeDirectory.addNext(&varDirectory);

        TreeNode binDirectory("/bin");
        homeDirectory.addNext(&binDirectory);

    TreeDumper treeDumper(&rootTree);
    treeDumper.dump();

    return 0;
}
