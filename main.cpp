// =================================================================
//
// File: main.cpp
// Author: Frida Bailleres González
// Date: 05/09/2022
//
// =================================================================
#include <iostream>
#include <vector>
#include "header.h"
#include <fstream>
#include "search.h"
#include "bubble.h"
#include "selection.h"
#include "insertion.h"

using namespace std;


int main(int argc, char* argv[]) {
	ifstream inputFile;
	ofstream outputFile; 

	if (argc !=3){
		cout<<"Uso: "<<argv[0]<<"Input.txt Output.txt";
		return -1;
	}

	inputFile.open(argv[1]);
	if (inputFile.fail()){
		cout<<"Error al abrir archivo de entrada";
		return -1;
	}

	outputFile.open(argv[2]);
	if(outputFile.fail()){
		cout<<"Error al abrir archivo de salida";
		return -1;
	}


	int n, n2, num; 
	inputFile>>n;


	vector<int> nums(n);

	
	for (int i=0; i<n; i++){
		inputFile>>num;
		nums[i]=num; //Guarda los numeros 
	}


	int bubble_comp, selection_comp, insertion_comp; 

	vector<int> ordered = nums;
	bubble_comp = bubbleSort(ordered);
	ordered = nums; 

	selection_comp = selectionSort(ordered);
	ordered = nums;

	insertion_comp = insertionSort(ordered);

	outputFile << bubble_comp << ' ' 
			   << selection_comp << ' ' 
			   << insertion_comp << '\n' << '\n';


	inputFile >> n2;
	std::pair<int, int> result; 
 	for (int i = 0; i < n2; i++) {
		inputFile >> num;
		result = sequentialSearch(ordered, num); 
		outputFile << result.first << ' ' << result.second << ' '; 
		result = binarySearch(ordered, num); 
		outputFile << result.second << '\n'; 
    } 

	inputFile.close();
	outputFile.close();
	
}
	
