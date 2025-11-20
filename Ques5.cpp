#include <iostream>
using namespace std;

int maxIceCream(int cost[], int n, int coins) {
    int maxCost = 0;
    for(int i = 0; i < n; i++) {
        if(cost[i] > maxCost)
            maxCost = cost[i];
    }

    int *count = new int[maxCost + 1];  

    for(int i = 0; i <= maxCost; i++)
        count[i] = 0;  

    for(int i = 0; i < n; i++)
        count[cost[i]]++;

    int bars = 0;

    for(int price = 1; price <= maxCost; price++) {
        if(count[price] == 0) continue;

        int canBuy = coins / price;    
        if(canBuy == 0) break;

        int buy = (canBuy < count[price]) ? canBuy : count[price];

        bars += buy;
        coins -= buy * price;

        if(coins <= 0) break;
    }

    delete[] count;  
    return bars;
}

int main() {
    int costs[] = {1, 3, 2, 4, 1};
    int n = 5;
    int coins = 7;

    cout << maxIceCream(costs, n, coins);
    return 0;
}
