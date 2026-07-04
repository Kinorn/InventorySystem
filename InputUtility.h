#pragma once

#include <iostream>
#include <string>
#include <limits>

namespace InputUtility {
    inline void ClearInput();
    inline void PrintSeparation();
    inline void WaitForEnter();
}

void InputUtility::PrintSeparation()
{
    std::cout<<std::string(17, '=')<<"\n\n";
}

void InputUtility::WaitForEnter()
{
    std::cout<<"Press enter to continue-";
    ClearInput();
    std::cin.get();
}

void InputUtility::ClearInput()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}