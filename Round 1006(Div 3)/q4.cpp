#include <iostream>
#include <vector>
using namespace std;
#include<unordered_map>

int main() {
    int tc;
    cin >> tc;
    
    while (tc--) {
        int size;
        cin >> size;
        unordered_map<int, int> count;
        
        vector<int> numbers(size);
        for (int i = 0; i < size; i++) {
            cin >> numbers[i];
            count[numbers[i]]++;
        }

        int left_index = 0, right_index = 0;
        int min_difference = 0;
        
        for (int left = 0; left < size; left++) {
            int greater_count = 0, lesser_count = 0;
            
            for (int right = left + 1; right < size; right++) {
                if (numbers[right] > numbers[left]) {
                    greater_count++;
                } else if (numbers[right] < numbers[left]) {
                    lesser_count++;
                }
                
                int difference = greater_count - lesser_count;
                if (difference < min_difference) {
                    min_difference = difference;
                    left_index = left;
                    right_index = right;
                }
            }
        }

        cout << left_index + 1 << " " << right_index + 1 << "\n";
    }
    
    return 0;
}
