#include <stdio.h>

// Function to print the permutation
void printPermutation(int perm[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", perm[i]);
    }
    printf("\n");
}

// Function to find the largest mobile integer
int getMobile(int perm[], int dir[], int n) {
    int mobile = 0;
    int mobileIndex = -1;

    for(int i = 0; i < n; i++) {

        // Direction LEFT = 0
        if(dir[i] == 0 && i != 0) {
            if(perm[i] > perm[i - 1] && perm[i] > mobile) {
                mobile = perm[i];
                mobileIndex = i;
            }
        }

        // Direction RIGHT = 1
        if(dir[i] == 1 && i != n - 1) {
            if(perm[i] > perm[i + 1] && perm[i] > mobile) {
                mobile = perm[i];
                mobileIndex = i;
            }
        }
    }

    return mobileIndex;
}

void johnsonTrotter(int n) {
    int perm[n], dir[n];

    // Initialize permutation and directions
    // 0 = LEFT, 1 = RIGHT
    for(int i = 0; i < n; i++) {
        perm[i] = i + 1;
        dir[i] = 0;
    }

    printPermutation(perm, n);

    while(1) {

        // Find largest mobile integer
        int mobileIndex = getMobile(perm, dir, n);

        // No mobile integer means finished
        if(mobileIndex == -1)
            break;

        int swapIndex;

        // Move LEFT
        if(dir[mobileIndex] == 0)
            swapIndex = mobileIndex - 1;

        // Move RIGHT
        else
            swapIndex = mobileIndex + 1;

        // Swap numbers
        int temp = perm[mobileIndex];
        perm[mobileIndex] = perm[swapIndex];
        perm[swapIndex] = temp;

        // Swap directions
        temp = dir[mobileIndex];
        dir[mobileIndex] = dir[swapIndex];
        dir[swapIndex] = temp;

        mobileIndex = swapIndex;

        // Reverse direction of all numbers greater than mobile
        for(int i = 0; i < n; i++) {
            if(perm[i] > perm[mobileIndex]) {
                dir[i] = 1 - dir[i];
            }
        }

        printPermutation(perm, n);
    }
}

int main() {
    int n;

    printf("Enter value of n: ");
    scanf("%d", &n);

    johnsonTrotter(n);

    return 0;
}