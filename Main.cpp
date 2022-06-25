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

  void merge(int arr[], int l, int m, int r)
{
int i, j, k;
int n1 = m - l + 1;
int n2 = r - m;
int L[n1], R[n2];
for (i = 0; i < n1; i++)
L[i] = arr[l + i];
for (j = 0; j < n2; j++)
R[j] = arr[m + 1+ j];

i = 0;
j = 0;
k = l;
while (i < n1 && j < n2)
{
if (L[i] <= R[j])
{
arr[k] = L[i];
i++;
}
else
{
arr[k] = R[j];
j++;
}
k++;
}

while (i < n1)
{
arr[k] = L[i];
i++;
k++;
}

while (j < n2)
{
arr[k] = R[j];
j++;
k++;
}
}
  void mergeSort(int arr[], int l, int r)
{
if (l < r)
{
int m = l+(r-l)/2;
mergeSort(arr, l, m);
mergeSort(arr, m+1, r);
merge(arr, l, m, r);
}
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
  int linearSearch(int arr[], int x)
{
    int i, n= sizeof(arr)/sizeof(arr[0]);
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}
int binarySearch(int a[], int beg, int end, int val)    
{    
    int mid;    
    if(end >= beg)     
    {        mid = (beg + end)/2;    
/* if the item to be searched is present at middle */  
        if(a[mid] == val)    
        {                 
            return mid+1;    
        }    
            /* if the item to be searched is smaller than middle, then it can only be in left subarray */  
        else if(a[mid] < val)     
        {  
            return binarySearch(a, mid+1, end, val);    
        }    
            /* if the item to be searched is greater than middle, then it can only be in right subarray */  
        else     
        {  
            return binarySearch(a, beg, mid-1, val);    
        }          
    }    
    return -1;     
}
int main ()
{
    //set to the csv file location and reading input from csv file
    ifstream csv_file("random.csv");

    if(!csv_file.is_open())
        std::cout << "File Not Open" << '\n';


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
while(1){
	        int ch;

        	printf("Enter 1 for quick sort\nEnter 2 for heap sort \n3 for radix \n4 for merge\nEnter 5 for linearSearch\nEnter 6 for binarysearch\n");

        
        	scanf("%d",&ch);
        	switch(ch){
        		case 1:{
        			quicksort(arr,0,row.size()-1);
        			for (int  i = 0; i < row.size(); i++)
            cout << arr[i] << '\n';
            break;
        			
                 }

					
				
				case 2:{
					 heapSort(arr,row.size());
					 for (int  i = 0; i < row.size(); i++)
            cout << arr[i] << '\n';
					break;
				}
				case 3:{
					radixsort(arr, row.size());
					for (int  i = 0; i < row.size(); i++)
            cout << arr[i] << '\n';
					break;
				}
				case 4:{
					mergeSort(arr,0,row.size()-1);
					for (int  i = 0; i < row.size(); i++)
            cout << arr[i] << '\n';
					break;
				}

				case 5:{
					int e;
					printf("Enter the number you want to search\n");
					scanf("%d",&e);
					int i, n=row.size();
                    for (i = 0; i < n; i++){
                    	if (arr[i] == e){
                    	cout<<"The no is present at index "<<i<<'\n';
                    	break;	
						}
                    	cout << i << '\n';
                    	
					}
					if(i==n)printf("not found");
					break;
				}
				case 6:{
					quicksort(arr,0,row.size()-1);
					int e;
					printf("Enter the number you want to search\n");
					scanf("%d",&e);
					printf("The number is at index %d\n",binarySearch(arr,0,row.size()-1,e)); 
					break;
				}

				default:
					exit(0);
			}
		


		ofstream myfile("file.xls");
        int vsize = row.size();
        for(int n=0; n<vsize; n++){
            myfile << arr[n] << '\n';
        }
    }
}

    
