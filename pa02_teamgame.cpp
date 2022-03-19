#include <iostream>
using namespace std;

void swap(long* a, long* b) {
    long temp = *b;
    *b = *a;
    *a = temp;
}

int main()
{
    long N, k;
    cin >> N >> k;

    long* num = new long[N];
    for (long i = 0; i < N; i++){
        cin >> num[i];
    }
    //
    // 정렬을 해줄건데, (k-1)번째에 해당하는 것은 맨뒤로
    // 처음부터 맨 뒤에 꺼랑 바뀌고, n-1까지 정렬하면 될듯
    if (k == 0) {
        for (long i = 0; i < N; i++) {
            long smallestIndex = i;
            for (long j = i + 1; j < N; j++) {
                if (num[smallestIndex] > num[j]) {
                    smallestIndex = j;
                }
            }
            swap(num[i], num[smallestIndex]);
        }
    }
    else {
        swap(num[k - 1], num[N - 1]);
        for (long i = 0; i < N - 1; i++) {
            long smallestIndex = i;
            for (long j = i + 1; j < N - 1; j++) {
                if (num[smallestIndex] > num[j]) {
                    smallestIndex = j;
                }
            }
            swap(num[i], num[smallestIndex]);
        }
    }

    long totalTime = 0;
    for (long i = 0; i < N; i++) {
        totalTime += num[i] * (N - i);
    }

    cout << totalTime;

    delete num;
    return 0;
}

