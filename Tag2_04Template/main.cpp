#include <iostream>
#include <memory>
#include "processor/FileProcessor.h"
#include "processor/CharacterCounter.h"
#include "processor/LineCounter.h"

using Processor = std::shared_ptr<processor::FileProcessor>;
int main() {
    auto cc = processor::CharacterCounter{};
    auto lc = processor::LineCounter{};

    Processor fileProcessor = std::make_shared<processor::FileProcessor>();
    fileProcessor->addHandler(cc);
    //fileProcessor->addHandler(lc);
    fileProcessor->run("..\\data\\blind.txt");


    return 0;
}
