#pragma once

#include "File.h"

enum class ProcessType
{
    VSCODE,
};

class ProcessRunner
{
    public:
        void run(ProcessType, File);
};
