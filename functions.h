//
// Created by VadimAlg on 29.09.2022.
//

#ifndef SORTC_FUNCTIONS_H
#define SORTC_FUNCTIONS_H

#include <cstdlib>

using namespace std;
int key = -1;
int head = 0;
int tail = 0;
int flagPush = 0;
int flagPop = 0;

void printArray(int mass[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << mass[i] << ' ';
    }

}

void fillArray(int mass[], int n) {
    for (int i = 0; i < n; ++i) {
        cin >> mass[i];
    }
}


void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}


void bublesort(int mass[], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (mass[i] > mass[j]) {
                swap(&mass[i], &mass[j]);
            }
        }
    }
}


void merge(int mass[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int leftm[n1];
    int rightm[n2];
    for (int i = 0; i < n1; ++i) {
        leftm[i] = mass[left + i];
    }
    for (int i = 0; i < n2; ++i) {
        rightm[i] = mass[mid + 1 + i];
    }
    int i = 0;
    int j = 0;
    int k = left;
    while (i < n1 && j < n2) {
        if (leftm[i] <= rightm[j]) {
            mass[k] = leftm[i];
            ++i;
        } else {
            mass[k] = rightm[j];
            ++j;
        }
        k++;
    }
    while (i < n1) {
        mass[k] = leftm[i];
        ++i;
        ++k;
    }
    while (j < n2) {
        mass[k] = leftm[j];
        ++j;
        ++k;
    }

}


void mergesort(int mass[], int const left, int const right) {
    if (left >= right) {
        return;
    }
    int mid = left + (right - left) / 2;
    mergesort(mass, left, mid);
    mergesort(mass, mid + 1, right);
    merge(mass, left, mid, right);


}


int partition(int mass[], int left, int right) {
    int pivot = mass[(left + right) / 2];
    int i = left;
    int j = right;
    while (i <= j) {
        while (mass[i] < pivot) {
            ++i;
        }
        while (mass[j] > pivot) {
            --j;
        }
        if (i >= j) {
            break;
        }
        swap(mass[i++], mass[j--]);

    }
    return j;
}

void quicksort(int mass[], int left, int right) {
    if (left < right) {
        int konraz = partition(mass, left, right);
        quicksort(mass, left, konraz);
        quicksort(mass, konraz + 1, right);
    }
}


void CountingSort(int mass[], int minel, int maxel, int n) {
    int diap = maxel - minel + 1;
    int flag = 0;
    if (minel < 0) {
        flag = 1;
    }
    int c[diap + 1];
    for (int i = 0; i < diap + 1; ++i) {
        c[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        ++c[mass[i] - minel * flag];
    }
    for (int i = 1; i < diap + 1; ++i) {
        c[i] += c[i - 1];
    }
    int b[n];
    for (int i = n - 1; i >= 0; --i) {
        b[c[mass[i] - minel * flag] - 1] = mass[i];
        --c[mass[i] - minel * flag];
    }
    memcpy(mass, b, sizeof(int) * n);
}


int popS(int mass[]) {
    if (key >= 0) {
        return (mass[key--]);
    } else {
        cout << "Stack is empty" << endl;
    }
    return -1;
}

void pushS(int mass[], int n, int el) {
    if (key + 1 < n) {
        mass[++key] = el;
    } else {
        cout << "Stack is full" << endl;
    }
}

void pushQ(int mass[], int n, int el) {
    flagPop = 1;
    if (flagPush == 0) {
        mass[tail++] = el;
    } else {
        cout << "Queue is full" << endl;
    }

    if (tail == n) {
        tail = 0;
    }
    if (tail == head) {
        flagPush = 1;
    }
}

int popQ(int mass[], int n) {
    if (flagPop == 1) {
        int c = mass[head];
        head++;
        if (head > tail) {
            flagPop = 0;
        }
        if (head == n) {
            head = 0;
        }
        flagPush = 0;
        return c;
    } else {
        cout << "Queue if empty" << endl;
        return -1;
    }
}
    int binpoiskF(int mass[], int left, int right, int isk) {
        int l = left;
        int r = right;
        while (l < r - 1) {
            int m = (l + r) / 2;
            if (mass[m] < isk) {
                l = m;
            } else {
                r = m;
            }
        }
        return r;
    }

    int binpoiskL(int mass[], int left, int right,int isk,int bf){
    if (bf == 0){
        left = binpoiskF(mass,left,right,isk);
    }
    int l = left;
    int r = right;
    while (l < r-1) {
        int m = (l+r)/2;
        if (mass[m] == isk){
            l = m;
        } else {
            r = m;
        }
    }
    return r-1;
}



#endif //SORTC_FUNCTIONS_H
