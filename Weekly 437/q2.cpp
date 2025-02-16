bool comp(int a, int b) {
      return a > b;
}

class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        sort(pizzas.begin(), pizzas.end(), comp);
        int x = pizzas.size() / 4;
        x = (x + 1) / 2;
        long long sum = 0;
        for(int i = 0; i < x; i++) 
            sum += 1LL*pizzas[i];
        for(int i = x + 1, j = 0; j < pizzas.size() / 8; i += 2, j++) {
            sum += 1LL*pizzas[i];
        }
        return sum;
    }
};