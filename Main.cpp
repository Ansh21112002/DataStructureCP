#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int toint(string s){
//	string s="78968";
	int ans=0;
	vector<char> v(s.begin(),s.end());
	for(int i=0;i<v.size();i++){
		v[i]=v[i]-'0';
		ans=ans*10+v[i];
	}
	return ans;
}

 void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
  }

int main ()
{
    //set to the csv file location and reading input from csv file
    ifstream csv_file("E:\\Study Material\\SY-Sem2\\Data Structures\\DS_CP\\random.csv");

    if(!csv_file.is_open())
        std::cout << "File Not Open" << '\n';

    // Empty vector holding all data from csv file
    vector<int> row;
    string row_data;
    int x=0;


        while(getline(csv_file, row_data))
        {
        	x=toint(row_data);
            row.push_back(x);

        }
        
        int arr[row.size()];
        copy(row.begin(),row.end(), arr);
        heapSort(arr,row.size());
//        quickSort(arr,0,row.size()-1);

        for (int  i = 0; i < row.size(); i++)
            cout << arr[i] << '\n';
    

}
