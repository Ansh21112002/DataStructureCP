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
int getMax(int array[], int n) {
  int max = array[0];
  for (int i = 1; i < n; i++)
    if (array[i] > max)
      max = array[i];
  return max;
}

// Using counting sort to sort the elements in the basis of significant places
void countingSort(int array[], int size, int place) {
  int output[size + 1];
  int max = (array[0] / place) % 10;

  for (int i = 1; i < size; i++) {
    if (((array[i] / place) % 10) > max)
      max = array[i];
  }
  int count[max + 1];

  for (int i = 0; i < max; ++i)
    count[i] = 0;

  // Calculate count of elements
  for (int i = 0; i < size; i++)
    count[(array[i] / place) % 10]++;
    
  // Calculate cumulative count
  for (int i = 1; i < 10; i++)
    count[i] += count[i - 1];

  // Place the elements in sorted order
  for (int i = size - 1; i >= 0; i--) {
    output[count[(array[i] / place) % 10] - 1] = array[i];
    count[(array[i] / place) % 10]--;
  }

  for (int i = 0; i < size; i++)
    array[i] = output[i];
}

// Main function to implement radix sort
void radixsort(int array[], int size) {
  // Get maximum element
  int max = getMax(array, size);

  // Apply counting sort to sort elements based on place value.
  for (int place = 1; max / place > 0; place *= 10)
    countingSort(array, size, place);
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
