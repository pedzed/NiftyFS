#include <iostream>
#include <string>
#include <boost/process.hpp>

#include "ProcessRunner.h"

using std::string;

void ProcessRunner::run(ProcessType processType, File file)
{
    string processString;

    switch (processType) {
        case ProcessType::VSCODE:
            processString = "code " + file.getAbsolutePath();
        break;

        default:
            std::cerr << "No valid process selected." << std::endl;
    }

    std::cout << "Running: '" << processString << "'." << std::endl;

    boost::process::ipstream output;
    boost::process::child process(processString, boost::process::std_out > output);
    process.wait();
}
