#include <iostream>
#include <climits>

void removeNegativeElements(int A[], int& N) {
    int j = 0;
    for (int i = 0; i < N; ++i) {
        if (A[i] >= 0) {
            A[j++] = A[i];
        }
    }
    N = j;
}

int findFirstMaxNegative(int A[], int N, int T) {
    int maxNegativeIndex = -1;
    int maxNegative = INT_MIN;

    for (int i = 0; i < N; ++i) {
        if (A[i] < 0 && A[i] > maxNegative && A[i] < T) {
            maxNegative = A[i];
            maxNegativeIndex = i;
        }
    }

    return maxNegativeIndex;
}

int main() {
    const int maxSize = 100;
    int A[maxSize];
    int N;

    std::cout << "Enter array size: ";
    std::cin >> N;
    std::cout << "Enter array elements: ";
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }

    removeNegativeElements(A, N);

    int T;
    std::cout << "Enter value of T: ";
    std::cin >> T;

    int index = findFirstMaxNegative(A, N, T);

    if (index == -1) {
        std::cout << "No maximum negative element before the first element equal to T found.\n";
    }
    else {
        std::cout << "Index of the first maximum negative value: " << index << std::endl;
    }

    return 0;
}
