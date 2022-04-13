#include <iostream>
#include <time.h>
#define INFINITE 100000

using namespace std;

int max(int a, int b) {
	return (a > b) ? a : b;
}

int determineMax(int a, int b, int c) {
	return max(max(a, b), c);
}

int crossMaxSum(int* arr, int start, int mid, int end) {
	int tempSum = 0;
	int leftMaxSum = -INFINITE;
	int rightMaxSum = -INFINITE;

	for (int i = mid; i >= start; i--) {
		tempSum += arr[i];
		if (tempSum > leftMaxSum)
			leftMaxSum = tempSum;
	}

	tempSum = 0;
	for (int i = mid + 1; i <= end; i++) {
		tempSum += arr[i];
		if (tempSum > rightMaxSum)
			rightMaxSum = tempSum;
	}

	return leftMaxSum + rightMaxSum;
}

int maxSum(int* arr, int start, int end) {
	if (start == end)
		return arr[start];
	else {
		int mid = (start + end) / 2;
		int leftMaxSum = maxSum(arr, start, mid);
		int rightMaxSum = maxSum(arr, mid + 1, end);
		int CrossMaxSum = crossMaxSum(arr, start, mid, end);
		return determineMax(leftMaxSum, rightMaxSum, CrossMaxSum);
	}
}


int main() {

}
