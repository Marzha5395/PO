#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

const int N = 86400;
unordered_map<int, int> numtoenergy;
vector<int> timeenergy(N,0);

int main() {
    numtoenergy[0] = 6;
    numtoenergy[1] = 2;
    numtoenergy[2] = 5;
    numtoenergy[3] = 5;
    numtoenergy[4] = 4;
    numtoenergy[5] = 5;
    numtoenergy[6] = 6;
    numtoenergy[7] = 3;
    numtoenergy[8] = 7;
    numtoenergy[9] = 6;

    int hour = 0, minute = 0, second = 0;
    for(int i = 0; i < N; i++){
        timeenergy[i] += numtoenergy[hour/10];
        timeenergy[i] += numtoenergy[hour%10];
        timeenergy[i] += numtoenergy[minute/10];
        timeenergy[i] += numtoenergy[minute%10];
        timeenergy[i] += numtoenergy[second/10];
        timeenergy[i] += numtoenergy[second%10];
        second++;
        if(second > 59){
            second = 0;
            minute++;
        }
        if(minute > 59){
            minute = 0;
            hour++;
        }
    }

    int n, cnt = 0, left = 0, right = 0, current = 36;
    cin >> n;
    while(right < N){
        if(n == current){
            cnt++;
            current -= timeenergy[left];
            right++;
            left++;
            current += timeenergy[right];
        }
        else if(left == right || current < n){
            right++;
            current += timeenergy[right];
        }
        else if(current > n){
            current -= timeenergy[left];
            left++;
        }
    }
    cout << cnt;

    return 0;
}