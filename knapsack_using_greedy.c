#include <stdio.h>

int main() {
    int n, i, j;
    float capacity, totalProfit = 0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int weight[n], profit[n];
    float ratio[n];

    for(i = 0; i < n; i++) {
        printf("Enter weight and profit of item %d: ", i + 1);
        scanf("%d %d", &weight[i], &profit[i]);
        ratio[i] = (float)profit[i] / weight[i];
    }

    printf("Enter knapsack capacity: ");
    scanf("%f", &capacity);

    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(ratio[i] < ratio[j]) {
                float temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                int tempW = weight[i];
                weight[i] = weight[j];
                weight[j] = tempW;

                int tempP = profit[i];
                profit[i] = profit[j];
                profit[j] = tempP;
            }
        }
    }

    printf("\nSelected items:\n");

    for(i = 0; i < n; i++) {
        if(capacity >= weight[i]) {
            capacity -= weight[i];
            totalProfit += profit[i];
            printf("Item %d -> Fully selected (W=%d, P=%d)\n", i + 1, weight[i], profit[i]);
        } else {
            float fraction = capacity / weight[i];
            totalProfit += profit[i] * fraction;
            printf("Item %d -> %.2f fraction selected (W=%d, P=%d)\n", i + 1, fraction, weight[i], profit[i]);
            break;
        }
    }

    printf("\nMaximum Profit = %.2f\n", totalProfit);

    return 0;
}