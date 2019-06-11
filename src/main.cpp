#include <iostream>
#include <string>

#include <chrono>
#include <thread>

#include "TreeNode.h"

using namespace std;
using namespace std::this_thread;
using namespace std::chrono_literals;

int main()
{
    TreeNode rootTree("🎄");

    TreeNode homeDirectory("home");
    rootTree.setChild(&homeDirectory);

        TreeNode pedDirectory("ped");
        homeDirectory.setNext(&pedDirectory);

            TreeNode documentsDirectory("documents");
            pedDirectory.setNext(&documentsDirectory);

            TreeNode imagesDirectory("images");
            documentsDirectory.setNext(&imagesDirectory);

    TreeNode optDirectory("opt");
    homeDirectory.setChild(&optDirectory);

    TreeNode varDirectory("var");
    optDirectory.setChild(&varDirectory);

    TreeNode binDirectory("bin");
    varDirectory.setChild(&binDirectory);

    cout << rootTree.getName();

    cout << "/" << rootTree.getChild()->getName();
    cout << "/" << rootTree.getChild()->getNext()->getName();
    cout << "/" << rootTree.getChild()->getNext()->getNext()->getName();

    // while (true) {
    //     sleep_for(500ms);
    // }

    return 0;
}
