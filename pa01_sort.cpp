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

void quickSort(int* numbers, int left, int right, int k) { // right는 N-1
    if (left >= right) return;

    int pivot = left;
    int lStart = left + 1;
    int rStart = right;
    static int goToK = 0;

    while (lStart <= rStart) {
        while (numbers[pivot] >= numbers[lStart] && lStart <= right) {
            lStart++;
        }
        while (numbers[pivot] <= numbers[rStart] && rStart > left) {
            rStart--;
        }


        //if (lStart >= rStart && numbers[pivot] > numbers[rStart]) { // 딱 지나친 순간임
        //    swap(numbers[pivot], numbers[rStart]);
        //    goToK++;
        //    if (goToK == k) {
        //        for (int i = 0; i < 500; i++) {
        //            cout << numbers[i] << endl;
        //        }
        //        cout << "here" << endl;
        //    }
        //}
        //else {
        //    swap(numbers[lStart], numbers[rStart]);
        //}
        if (lStart > rStart && numbers[pivot] > numbers[rStart]) {
            swap(numbers[pivot], numbers[rStart]);
            goToK++;
            if (goToK == k) {
                 for (int i = 0; i < 500; i++) {
                    cout << numbers[i] << endl;
                 }
                cout << "here" << endl;
            }
        }
        else {
            swap(numbers[lStart], numbers[rStart]);
        }

    }

    if (goToK != k) {
        quickSort(numbers, left, rStart - 1, k);
        quickSort(numbers, rStart + 1, right, k);
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
        quickSort(numbers, 0, N - 1, k);
        for (int i = 0; i < N; i++) {
            cout << numbers[i] << endl;
        }
        break;
    }

    delete numbers;
}

