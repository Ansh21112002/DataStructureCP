#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main ()
{
    //set to the csv file location and reading input from csv file
    ifstream csv_file("D:\\DS\\dscp/data.csv");

    if(!csv_file.is_open())
        std::cout << "File Not Open" << '\n';

    // Empty vector holding all data from csv file
    vector<string> row;
    string row_data;


        while(getline(csv_file, row_data))
        {
            row.push_back(row_data);

        }

        sort(row.begin(), row.end());

        // Loop to print csv file
        for (size_t i = 0; i < row.size(); i++)
            cout << row[i] << '\n';
    

}
