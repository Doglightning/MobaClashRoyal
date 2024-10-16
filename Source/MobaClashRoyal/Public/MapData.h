#pragma once

#include <string>
#include <map>
#include <vector>
#include "CoreMinimal.h"

class MOBACLASHROYAL_API MapData
{
public:
    // Define the type for the direction vectors
    using DirMap = std::map<std::string, std::vector<float>>;

    // Initialize map data directly in the class
    std::map<std::string, DirMap> mapRegistry = {
        {"ProtoType", {
            {"-4840,-360", {-0.171f, 0.985f}},
            {"-4840,-260", {-0.029f, 1.000f}},
            {"-4840,-160", {-0.029f, 1.000f}},
            {"-4840,-60", {-0.029f, 1.000f}}
        }}
    };

  
};
