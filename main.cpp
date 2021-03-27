#include <cstdio>

using namespace std;

struct Program {
    int ID;
    int size;
    Program() {
        ID = 0;
        size = 0;
    }
};

int CompareSizes(const Program& p1, const Program& p2) {
    if (p1.size < p2.size) return -1;
    if (p1.size == p2.size) return 0;
    if (p1.size > p2.size) return 1;
    return 0;
}

int CompareIDs(const Program& p1, const Program& p2) {
    if (p1.ID < p2.ID) return 1;
    if (p1.ID == p2.ID) return 0;
    if (p1.ID > p2.size) return -1;
    return 0;
}

template<typename F>
int Partition(Program array[], int left, int right, F function) {
    Program pivot = array[left];
    int leftI = left - 1;
    int rightI = right + 1;
    while (true) {
        while (true) {
            int result = function(pivot, array[++leftI]);
            if (result == 0 || result == -1) break;
        }
        while (true) {
            int result = function(pivot, array[--rightI]); // array <= pivot
            if (result == 0 || result == 1) break;
        }

        if (leftI < rightI) {
            Program tmp = array[leftI];
            array[leftI] = array[rightI];
            array[rightI] = tmp;
        } else {
            return rightI;
        }
    }
}

template<typename F>
void Sort(Program array[], int left, int right, F compareFunction) {
    if (left < right) {
        int pivot = Partition(array, left, right, compareFunction);
        Sort(array, left, pivot, compareFunction);
        Sort(array, pivot + 1, right, compareFunction);
    }
}

void Division(Program array[], int size, int memory) {
    int sum = 0, i = 0;
    while (i <= size - 1 && sum + array[i].size <= memory) {
        sum += array[i].size;
        i++;
    }
    int sizePen1 = i;
    auto* pendrive1 = new Program[sizePen1];
    for (int j = 0; j < sizePen1; j++) {
        pendrive1[j] = array[j];
    }

    sum = 0;
    while (i <= size - 1 && sum + array[i].size <= memory) {
        sum += array[i].size;
        i++;
    }
    int sizePen2 = i - sizePen1;
    auto* pendrive2 = new Program[sizePen2];
    for (int j = 0; j < sizePen2; j++) {
        pendrive2[j] = array[sizePen1 + j];
    }

    Sort(pendrive1, 0, sizePen1 - 1, CompareIDs);
    Sort(pendrive2, 0, sizePen2 - 1, CompareIDs);

    printf("%d\n1: ", i);
    for (int j = 0; j < sizePen1; j++) {
        printf("%d ", pendrive1[j].ID);
    }
    printf("\n2: ");
    for (int j = 0; j < sizePen2; j++) {
        printf("%d ", pendrive2[j].ID);
    }

    delete[] pendrive1;
    delete[] pendrive2;
}

int main() {

    int memory = 0, programs = 0;
    if (scanf("%d %d", &programs, &memory) != 2) return -1;
    auto* array = new Program[programs];

    for (int i = 0; i < programs; i++) {
        Program tmp;
        if (scanf("%d %d", &(tmp.ID), &(tmp.size)) != 2) return -1;
        array[i] = tmp;
    }

    Sort(array, 0, programs - 1, CompareSizes);
    Division(array, programs, memory);

    delete[] array;
    return 0;
}