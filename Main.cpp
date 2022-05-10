
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
  
  void heapify(int arr[], int n, int i) {
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && arr[left] > arr[largest])
      largest = left;
  
    if (right < n && arr[right] > arr[largest])
      largest = right;
  
    // Swap and continue heapifying if root is not largest
    if (largest != i) {
      swap(&arr[i], &arr[largest]);
      heapify(arr, n, largest);
    }
  }
  
  // Main function to do heap sort
  void heapSort(int arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);
  
    // Heap sort
    for (int i = n - 1; i >= 0; i--) {
      swap(&arr[0], &arr[i]);
  
      // Heapify root element to get highest element at root again
      heapify(arr, i, 0);
    }
  }

// function to find the partition position

int main ()
{
    //set to the csv file location and reading input from csv file
    ifstream csv_file("C:\\Users\\sansk\\OneDrive\\Desktop\\random.csv");

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
