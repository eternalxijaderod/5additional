#include <iostream>
#include "Functions.hpp"


void MoveRightAllAfterI(int array[size], int a, int fullness)
{
    for (int i = fullness*2; i > a-1; i--)
    {
        array[i+1] = array[i];
        ts::ArrayWriteToConsole(array, fullness);
    }
}

int main()
{
    int array[size];
    int fullness = 0;
    fullness = ts::FileReadToArray(filenameOfInputFile, array, fullness);
    if (fullness == -1)
        return -1;
    ts::ArrayWriteToConsole(array, fullness);
    for (int i = 0; i < fullness; ++i)
    {
        if (ts::IsPrime(array[i]))
        {
            std::cout << "prime: " << array[i] << std::endl;
        }
    }
    int c = 0;
    int fullnessBefore = fullness;
    for (int i = 0; i < fullnessBefore; i++)
    {
        if (ts::IsPrime(array[i]))
            fullness--;
        if (!ts::IsPrime(array[i]))
        {
            array[c] = array[i];
            c++;
        }
    }
    std::cout << fullness << std::endl;
    fullnessBefore = fullness*2;
    for (int i = 0; i < fullnessBefore; i+=2)
        if (!ts::IsPrime(array[i]))
        {
            //std::cout << "NEW NUMBER!" << std::endl;
            MoveRightAllAfterI(array, i, fullness);
            fullness++;
        }
    std::cout << "After:\n";
    ts::ArrayWriteToConsole(array, fullness);
    ts::ArrayWriteToFile(filenameOfOutputFile, array, fullness);
}