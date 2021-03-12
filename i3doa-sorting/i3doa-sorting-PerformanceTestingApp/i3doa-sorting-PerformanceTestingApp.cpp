// i3doa-sorting-PerformanceTestingApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "FileTokenizer.h"
#include "Stopwatch.h"
#include "../i3doa-sorting/Quicksort.h"

void sort_words(void) {
	FileTokenizer ft;
	Stopwatch sw;

	const int num_words = 6000;
	string words[num_words];
	int words_read = ft.read("Words.txt", num_words);
	for (int j = 0; j < num_words; j++)
		words[j] = ft.next();

	sw.start();
	quicksort<string>(words, num_words);
	sw.stop();
	std::cout << "sorted " << num_words << " in " << sw.getDuration() << " us" << std::endl;

	ofstream txtoutfile("Words_sorted.txt");
	for (int j = 0; j < num_words; j++)
		txtoutfile << words[j] << ", ";
	txtoutfile << endl;
	txtoutfile.close();
}


int main()
{
	sort_words();
	return 0;
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
