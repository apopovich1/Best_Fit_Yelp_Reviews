#include "Sorter.h"

// Quick Sort Code referenced the Lecture 6 Slides.
string QuickSort(vector<Restaurant>& restaurants) {
    QuickSort_Helper(restaurants, 0, static_cast<int>(restaurants.size() -1));
    Restaurant chosen_restaurant = restaurants[restaurants.size()-1];
    return chosen_restaurant.name;
}

void QuickSort_Helper(vector<Restaurant>& restaurants, int low, int high) {
    if (low < high) {
        int pivot = partition(restaurants, low, high);
        QuickSort_Helper(restaurants, low, pivot - 1);
        QuickSort_Helper(restaurants, pivot + 1, high);
    }
}

int partition(vector<Restaurant>& restaurants, int low, int high) {
    // Sets the pivot star as the rating of the restaurant at the pivot position.
    float pivot_star = restaurants[low].stars;
    int up = low;
    int down = high;

    while (up < down) {
        // Increment the up pointer until the vector at the up index is larger than the vector at the pivot index.
        while (up < high && restaurants[up].stars <= pivot_star) {
            up++;
        }

        // Decrement the down pointer until the vector at the down index is smaller than the vector at the pivot index.
        while (down > low && restaurants[down].stars >= pivot_star) {
            down--;
        }

        // If the down pointer has surpassed the up pointer, swap the restaurant at the up index with the down index.
        if (up < down) {
            std::swap(restaurants[up], restaurants[down]);
        }
    }

    // Swap the restaurant at the low index with the down index.
    std::swap(restaurants[low], restaurants[down]);
    // Returns the down index.
    return down;
}

// Referenced from lecture slides.
void heapify_down(vector<Restaurant>& restaurants, int size, int child) {
    // Sets the left and right child accordingly and the lowest rated restaurant as the child restaurant.
    int left = 2 * child + 1;
    int right = 2 * child + 2;
    int lowest = child;

    // Checks if the left and right child are in bounds of the heap.
    if (left < size && right < size) {
        // Two if statements for choosing the smaller child out of the left and right.
        // Will favor the left child if both left and right restaurants have the same reviews.
        if (restaurants[left].stars < restaurants[lowest].stars) {
            lowest = left;
        }

        else if (restaurants[right].stars < restaurants[lowest].stars) {
            lowest = right;
        }
    }

    // If the lowest rated restaurant is not the child restaurant, swaps the child with the lowest and heapify down.
    if (lowest != child) {
        std::swap(restaurants[child], restaurants[lowest]);
        heapify_down(restaurants, size, lowest);
    }
}

string HeapSort(vector<Restaurant>& restaurants) {
    // Creates a size variable for the heap sort.
    int size = static_cast<int>(restaurants.size());

    // Builds the heap using heapify down.
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify_down(restaurants, size, i);
    }

    for (int i = size - 1; i >= 0; i --) {
        // Swaps the root restaurant to the end of the heap.
        std::swap(restaurants[0], restaurants[i]);
        heapify_down(restaurants, i, 0);
    }

    // Outputs the root restaurant name.
    return restaurants[0].name;
}
