#include <iostream>
using namespace std;

int main()
{
    int n;
    int previousNumber = 0;
    int negativeSignCounting = 0;
    int negativePoint[2];
   
    cin >> n;
    long* num = new long[n];
    for (int i = 0; i < 5; i++) {
        
        for (int i = 0; i < n; i++) {
            cin >> num[i];
            if (previousNumber >= 0 && num[i] < 0) {
                negativeSignCounting++;
             
                if (negativeSignCounting == 1) {
                    negativePoint[0] = i;
                }
                else {
                    negativePoint[1] = i;
                }

            }
            previousNumber = num[i];
        }

        int idx = 0;

        if (negativeSignCounting == 1) { 
            int jump = 0;
            while (idx < negativePoint[0]) {
                if (((idx + 1) < negativePoint[0]) && num[idx] + 1 != num[idx + 1]) {
                    if (num[idx] < num[idx + 1]) { 
                        jump++;
                    }
                    else {
                        jump = jump + 2; 
                    }
                }
                idx++;
            }
            while (num[idx] < 0) {
                idx++;
            }
            while (idx < n) {
                if (idx + 1 < n && (num[idx] + 1 != num[idx + 1])) {
                    if (num[idx] < num[idx + 1]) { 
                        jump++;
                    }
                    else {
                        jump = jump + 2; 
                    }
                }
                idx++;
            }

            if (num[0] > 1 || jump > 1) {
                cout << "over" << endl;
            }
            else if (jump == 0) {
                cout << "one" << endl;
            }
            else if(jump == 1){
                cout << "two" << endl;
            }
        }

        else if (negativeSignCounting == 2) { 
            idx = negativePoint[0];
            int jump = 0;
            while (num[idx] < 0) {
                if (num[idx+1] < 0 && num[idx] + 1 != num[idx + 1]) {
                    jump = jump + 2; 
                }
                idx++;
            }
            while (idx < negativePoint[1]) {
                if (idx + 1 < negativePoint[1] && num[idx] + 1 != num[idx + 1]) {
                    jump = jump + 2; 
                }
                idx++;
            }
            while (num[idx] < 0) {
                if (idx < n-1 && num[idx+1] < 0 && num[idx] + 1 != num[idx + 1]) {
                    jump = jump + 2; 
                }
                idx++;
            }
            if (jump == 0) {
                cout << "two" << endl;
            }
            else {
                cout << "over" << endl;
            }
        }

        else {
            cout << "over" << endl;
        }

        previousNumber = 0;
        negativeSignCounting = 0;
    }
}

