#include "function6.h"
#include <vector>
using namespace std;

vector<int> findMode(int arr[], int size) {
    vector<int> modes;
    if (arr == nullptr || size <= 0) {
        return modes;
    }
    int maxCount = 0;
    for (int i = 0; i < size; i++) {
        int count = 0;
        for (int j = 0; j < size; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
        }
    }
    for (int i = 0; i < size; i++) {
        int count = 0;
        for (int j = 0; j < size; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        if (count == maxCount) {
            bool alreadyAdded = false;
            for (int k = 0; k < modes.size(); k++) {
                if (modes[k] == arr[i]) {
                    alreadyAdded = true;
                    break;
                }
            }
            if (!alreadyAdded) {
                modes.push_back(arr[i]);
            }
        }
    }
    return modes;
}