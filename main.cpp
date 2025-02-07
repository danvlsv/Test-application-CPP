// TestTaskC++.cpp: определяет точку входа для приложения.
//

#include "main.h"
#include "Figures/figures.h"

using namespace std;


bool FigureComp(const std::shared_ptr<Figure>& a, const std::shared_ptr<Figure>& b) {
	return a->GetArea() < b->GetArea();
}

void PrintResult(vector<std::shared_ptr<Figure>>& arr, string msg)
{
    string result = "\n\n"+msg+"\n";
    for (const auto& figure : arr) {
        result += (to_string(figure->GetArea()) + " ");
    }
    cout << result;
}


void merge(vector<std::shared_ptr<Figure>>& arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<std::shared_ptr<Figure>> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i]->GetArea() <= R[j]->GetArea()) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort(vector<std::shared_ptr<Figure>>& arr, int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    MergeSort(arr, left, mid);
    MergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
    
}

void StartMergeSort(vector<std::shared_ptr<Figure>> arr)
{
    MergeSort(arr, 0, arr.size() - 1);
    PrintResult(arr, "Merge Sort");
}




void BubbleSort(vector<std::shared_ptr<Figure>> figures)
{
	int n = figures.size();
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (!FigureComp(figures[j], figures[j + 1]))
				swap(figures[j], figures[j + 1]);
		}
	}
    PrintResult(figures, "Bubble Sort");

}



int partition(vector<std::shared_ptr<Figure>>& arr, int low, int high) {

    
    std::shared_ptr<Figure> pivot = arr[high];

    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j]->GetArea() < pivot->GetArea()) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void QuickSort(vector<std::shared_ptr<Figure>>& arr, int low, int high) {

    if (low < high) {

        // pi is the partition return index of pivot
        int pi = partition(arr, low, high);

        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high);
    }
}

void StartQuickSort(vector<std::shared_ptr<Figure>> arr)
{
    QuickSort(arr, 0, (arr.size() - 1)/2);
    PrintResult(arr, "Quick Sort");
}



int main()
{
    bool correctInit = true;
	vector<std::shared_ptr<Figure>> figures;
    try {
        figures.push_back(std::make_shared<Circle>(36));
        figures.push_back(std::make_shared<Triangle>(34, 25, 17));
        figures.push_back(std::make_shared<Rectangle>(340, 25));
        figures.push_back(std::make_shared<Triangle>(123.67, 146.43, 170.92));
        figures.push_back(std::make_shared<Circle>(250));
    }
    catch(...){
        cout << "Incorrectly initialized Figures";
        correctInit = false;
    }
    if (correctInit) {
        cout << "Threads started";
        boost::thread t1(&StartMergeSort, figures);
        boost::thread t2(&BubbleSort, figures);
        boost::thread t3(&StartQuickSort, figures);
        
        t1.join();
        t2.join();
        t3.join();
    }
	
	cout << "\n\n";
	return 0;
}
