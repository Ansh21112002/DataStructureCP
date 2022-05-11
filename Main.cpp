#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

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

  for (int i = 0; i < size; i++)
    count[(array[i] / place) % 10]++;

  for (int i = 1; i < 10; i++)
    count[i] += count[i - 1];

  
  for (int i = size - 1; i >= 0; i--) {
    output[count[(array[i] / place) % 10] - 1] = array[i];
    count[(array[i] / place) % 10]--;
  }

  for (int i = 0; i < size; i++)
    array[i] = output[i];
}
void radixsort(int array[], int size) {
  int max = getMax(array, size);

  
  for (int place = 1; max / place > 0; place *= 10)
    countingSort(array, size, place);
}
int partition(int a[], int f, int l)
{

    int pi=f,pivot = a[f];

    int i = f, j = l + 1;

    do
    {

        do
        {
            i++;
        } while (a[i] < pivot && i < j);
        do
        {
            j--;
        } while (a[j] > pivot);

        if (i < j)
        {
        	swap(&a[i],&a[j]);
        }

    } while (i < j);
    swap(&a[j], &a[pi]);



    return j;
}

void quicksort(int a[], int f, int l)
{
	if(f<l){
		int j = partition(a, f, l);
    quicksort(a, f, j - 1);
    quicksort(a, j + 1, l);
	}
    
}

int toint(string s){

	int ans=0;
	vector<char> v(s.begin(),s.end());
	for(int i=0;i<v.size();i++){
		v[i]=v[i]-'0';
		ans=ans*10+v[i];
	}
	return ans;
}


void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && arr[left] > arr[largest])
      largest = left;
  
    if (right < n && arr[right] > arr[largest])
      largest = right;
  
    if (largest != i) {
      swap(&arr[i], &arr[largest]);
      heapify(arr, n, largest);
    }
  }
  

  void heapSort(int arr[], int n) {

    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);
  

    for (int i = n - 1; i >= 0; i--) {
      swap(&arr[0], &arr[i]);
  

      heapify(arr, i, 0);
    }
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
        quickSort(arr,0,row.size()-1);

        for (int  i = 0; i < row.size(); i++)
            cout << arr[i] << '\n';
    

}
