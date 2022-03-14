#include <iostream>
#include <limits>
using namespace std;

void swap(int* a, int* b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

void Heapify(int* numbers, int parent, int size) {
    int temp_parent = parent;
    int left_child = parent * 2 + 1;
    int right_child = parent * 2 + 2;


    if (right_child < size && numbers[temp_parent] > numbers[right_child])
        temp_parent = right_child;

    if (left_child < size && numbers[temp_parent] > numbers[left_child])
        temp_parent = left_child;

    

    if (parent != temp_parent) {
        swap(numbers[parent], numbers[temp_parent]);
        Heapify(numbers, temp_parent, size);
    }
}

void quickSort(int* numbers, int left, int right, int k) {
    if (left >= right) return;

    int pivot = left;
    int lStart = left + 1;
    int rStart = right;
    static int goToK = 0; // k번째 어떻게 할건지 다시 고려

    while (lStart <= rStart) {
        while (numbers[pivot] >= numbers[lStart] && lStart <= right) {
            lStart++;
        }
        while (numbers[pivot] <= numbers[rStart] && rStart > left) {
            rStart--;
        }

        if (lStart > rStart) {
            swap(numbers[pivot], numbers[rStart]);
        }
        else {
            swap(numbers[lStart], numbers[rStart]);
        }
        
    }
    goToK++;
    if(goToK == k){
        return;
    }

    quickSort(numbers, left, rStart - 1, k);
    quickSort(numbers, rStart + 1, right, k);

   

}

int main()
{
    int sortingMethod, k;
    cin >> sortingMethod >> k;

    int N;
    cin >> N;

    //case 1
    int* numbers = new int[N];
    for (int i = 0; i < N; i++)
        cin >> numbers[i];

    ////case2
    //int* numbers = new int[N + 1];
    //for (int i = 1; i < N + 1; i++)
    //    cin >> numbers[i];


    switch (sortingMethod){
        case 1:

            for (int i = 0; i < k; i++) {
                int smallestIndex = i + 1;
                for (int j = i + 1; j < N; j++) {
                    if (numbers[j] < numbers[smallestIndex]) {
                        smallestIndex = j;
                    }
                }
                swap(numbers[i], numbers[smallestIndex]);
            }

            for (int i = 0; i < N; i++)
                cout << numbers[i] << endl;

            
            break;

        case 2:
            
            for (int i = N / 2 - 1; i >= 0; i--)
                Heapify(numbers, i, N);

            cout << "minimum Heap" << endl;
            for (int i = 0; i < N; i++)
                cout << numbers[i] << endl;
            
            for (int i = N - 1; i > N - k - 1; i--) {
                swap(numbers[0], numbers[i]);
                Heapify(numbers, 0, i);

                /*cout << N - i << ": result" << endl;
                for (int i = 0; i < N; i++)
                    cout << numbers[i] << endl;*/
            }

            cout << "FINAL" << endl;

            for (int i = 0; i < N - k; i++)
                cout << numbers[i] << endl;

            break;
        case 3:
            quickSort(numbers, 0, N - 1, k);

            cout << "result" << endl;
            for (int i = 0; i < N; i++) {
                cout << numbers[i] << endl;
            }

            break;
    }

    delete numbers;

    

}

