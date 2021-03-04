// i3doa-hashmap-app.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "../i3doa-hashmap/OAHashMap.h"
#include "FileTokenizer.h"
#include "Stopwatch.h"

#define MAP_SZ 8849
#define NUM_WORDS 6000

inline int zeroHash(string key, int map_size)
{
    return 0;
}

int main()
{
    FileTokenizer ft;
    Stopwatch sw;
    OAHashMap <string, string>my_map(MAP_SZ, zeroHash);

    //Indl�s ordene fra words.txt
    ft.read("words.txt", 10);
    int counter = 0;
    size_t size = ft.getSize();

    //Inds�t i hashmap
    while (counter <= size)
    {
        my_map.insert(ft.next(), "value");
    }
    
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
