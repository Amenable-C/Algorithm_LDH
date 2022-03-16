#include <iostream>
#include <limits>
using namespace std;

void swap(int* a, int* b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

void Heapify(int* numbers, int parent, int size) {
    int tempParent = parent;
    int leftChild = parent * 2 + 1;
    int rightChild = parent * 2 + 2;


    if (rightChild < size && numbers[tempParent] > numbers[rightChild])
        tempParent = rightChild;

    if (leftChild < size && numbers[tempParent] > numbers[leftChild])
        tempParent = leftChild;



    if (parent != tempParent) {
        swap(numbers[parent], numbers[tempParent]);
        Heapify(numbers, tempParent, size);
    }
}

void quickSort(int* numbers, int left, int right, int k, int N) { // right는 N-1
    if (left >= right) return;

    int pivot = left;
    int lStart = left + 1;
    int rStart = right;
    static int goToK = 0;

    while (lStart <= rStart) { // 처음 빼고는 같은 경우 존재X
        while (numbers[pivot] >= numbers[lStart] && lStart <= right) {  // 넘어가도 rStart로 swap이라서 상관X
            lStart++;
        }
        while (numbers[pivot] < numbers[rStart] && rStart > left) { 
            rStart--;
        }
        
        if (lStart >=rStart) {
            swap(numbers[pivot], numbers[rStart]);
            // pivot 자신끼리 바꾸는 경우도 존재
            // i 가 right 넘어가는 경우도 존재  
        }
        else {
            swap(numbers[lStart], numbers[rStart]);
        }

    }
    // 위의 while문에서 나오면 하나의 pivot이 자기 자리를 찾은 경우
    goToK++;
    if (goToK == k) {

        for (int i = 0; i < N; i++)
            cout << numbers[i] << endl;
    }

    if(goToK < k){
        quickSort(numbers, left, rStart - 1, k, N);
        quickSort(numbers, rStart + 1, right, k, N);
    }

}

int main()
{
    int sortingMethod, k;
    cin >> sortingMethod >> k;

    int N;
    cin >> N;

    int* numbers = new int[N];
    for (int i = 0; i < N; i++)
        cin >> numbers[i];


    switch (sortingMethod) {
    case 1:


        for (int i = 0; i < k; i++) {
            int smallestIndex = i;
            for (int j = i + 1; j < N; j++) {
                if (numbers[smallestIndex] > numbers[j]) {
                    smallestIndex = j;
                }
            }
            swap(numbers[i], numbers[smallestIndex]);
        }

        for (int i = 0; i < N; i++) {
            cout << numbers[i] << endl;
        }


        break;

    case 2:

        for (int i = N / 2 - 1; i >= 0; i--)
            Heapify(numbers, i, N);

        /*cout << "minimum Heap" << endl;
        for (int i = 0; i < N; i++)
            cout << numbers[i] << endl;*/

        for (int i = N - 1; i > N - k - 1; i--) {
            swap(numbers[0], numbers[i]);
            Heapify(numbers, 0, i);
        }

        for (int i = 0; i < N - k; i++) {
            cout << numbers[i] << endl;
        }
        break;

    case 3:
        int goToK = 0;
        quickSort(numbers, 0, N - 1, k, N);
        break;
    }

    delete numbers;
}

