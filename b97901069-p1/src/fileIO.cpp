#include "fileIO.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
using namespace std;

void fileIO:: setInputFilePath(string str)
{
    input_file_path=str;
}

void fileIO:: setOutputFilePath(string str)
{
    output_file_path=str;
}


void fileIO:: readFile(){
    string line;
    ifstream inFile(input_file_path.c_str());
    int i=0;
    while(getline(inFile,line)){
	if(i==0)
	    line1=line;
	else if(i==1)
	    line2=line;
	if(i>1){
	    istringstream ss(line);
	    string word;
	    int j=1;
	    while(ss>>word){
		int n = atoi(word.c_str());
		if(j%2==0)
		    data.push_back(n);
		j++;
	    }	
	}
	i++;
    }
    inFile.close();
}

vector<int> fileIO:: getData()
{
    return data;
}

void fileIO:: coutData(string str)
{
    vector<int> ::iterator it;
    cout<<str<<endl;
    for (it = data.begin(); it < data.end(); it++) {
	cout<<*it<<" ";
    }
    cout<<endl;
}

void fileIO::outputFile()
{
    ofstream outputFile(output_file_path.c_str());
    outputFile<<line1<<endl;
    outputFile<<line2<<endl;
    for(int i=0;i<data.size();i++){
    	outputFile<<i<<" ";
	outputFile<<data[i]<<'\n';
    }
    outputFile<<endl;
    outputFile.flush();
    outputFile.close();
    
}
