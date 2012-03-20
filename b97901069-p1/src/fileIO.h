#ifndef FILEIO_H
#define FILEIO_H

#include <vector>
#include <string>
using namespace std;

class fileIO
{
    public:
	void readFile();
	void coutData(string str);
	vector<int> getData();
	void outputFile();
        void setInputFilePath(string str);
	void setOutputFilePath(string str);	
	vector <int> data;
    private:
	string line1;
	string line2;
	string output_file_path;
	string input_file_path;
};

#endif
