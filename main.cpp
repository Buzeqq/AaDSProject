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

/*ostream& operator<<(ostream& ostream, Program& pro) {
    ostream << pro.ID;
    return ostream;
}*/

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
    int sum1 = 0, sum2 = 0, i = 0, counter = 0;
    while (true) {
        if (i >= size) break;
        if (sum1 + array[i].size < memory) {
            sum1 += array[i++].size;
            counter++;
        }
        else break;
    }
    auto* pendrive1 = new Program[counter];
    int tmp = counter;
    for (int j = 0; j < tmp; j++) {
        pendrive1[j] = array[j];
    }
    Sort(pendrive1, 0, counter - 1, CompareIDs);

    while (true) {
        if (i >= size) break;
        if (sum2 + array[i].size < memory) {
            sum2 += array[i++].size;
            counter++;
        }
        else break;
    }
    auto* pendrive2 = new Program[counter - tmp];
    for (int j = 0; j < counter - tmp; j++) {
        pendrive2[j] = array[tmp + j];
    }
    Sort(pendrive2, 0, counter - tmp - 1, CompareIDs);

    printf("%d\n1: ", counter);
    for (i = 0; i < tmp; i++) {
        // cout << pendrive1[i] << " ";
        printf("%d ", pendrive1[i].ID);
    }
    printf("\n2: ");
    for (i = 0; i < counter - tmp; i++) {
        printf("%d ", pendrive2[i].ID);
    }

    delete[] pendrive1;
    delete[] pendrive2;
}

int main() {

    int memory = 0, programs = 0;
    scanf("%d %d", &programs, &memory);
    auto* array = new Program[programs];

    for (int i = 0; i < programs; i++) {
        Program tmp;
        scanf("%d %d", &(tmp.ID), &(tmp.size));
        array[i] = tmp;
    }

    Sort(array, 0, programs - 1, CompareSizes);
    Division(array, programs, memory);

    delete[] array;
    return 0;
}