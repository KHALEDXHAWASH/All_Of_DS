//
// Created by frndas on 05/06/2025.
//
#include "bits/stdc++.h"

using namespace std;
template<class T>
void printarray(T arr[],int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
template<class T>
class SortingSystem {
public:
    SortingSystem(int n) : m_size(n) {
        m_data = new T[n];
        std::cout << "enter array\n";
        for (int i = 0; i < m_size; i++)
            std::cin >> m_data[i];
    }

    ~SortingSystem() {
        delete[] m_data;
    }

    T *getData() {
        return m_data;
    }

    void insertionSort() {
        insertionSort(m_data, m_size);
    }

    void selectionSort() {
        for (int i = 0; i < m_size; i++) {
            int index = i;
            for (int j = i + 1; j < m_size; j++) {
                if (m_data[index] > m_data[j]) {
                    index = j;
                }
            }
            std::swap(m_data[i], m_data[index]);
        }
    }

    void bubbleSort() {
        for (int i = 0; i < m_size; i++) {
            for (int j = m_size - 1; j > i; j--) {
                if (m_data[j - 1] > m_data[j])
                    std::swap(m_data[j - 1], m_data[j]);
            }
        }
    }

    void shellSort() {
        for (int gap = m_size / 2; gap > 0; gap /= 2) {
            for (int i = gap; i < m_size; i++) {
                T temp = m_data[i];
                int j;
                for (j = i; j >= gap && m_data[j - gap] > temp; j -= gap) {
                    m_data[j] = m_data[j - gap];
                }
                m_data[j] = temp;
            }
        }
    }

    void mergeSort() {
        if (m_size > 1)
            mergeSort(0, m_size - 1);
    }

    void quickSort() {
        if (m_size > 1)
            quickSort(0, m_size - 1);
    }

    void countSort() {
        if (m_size == 0)
            return;

        T maxVal = m_data[0];
        for (int i = 1; i < m_size; i++) {
            if (m_data[i] > maxVal)
                maxVal = m_data[i];
        }

        int countSize = maxVal + 1;
        int *count = new int[countSize]();
        T *output = new T[m_size];

        for (int i = 0; i < m_size; i++)
            count[m_data[i]]++;
        for (int i = 1; i <= maxVal; i++)
            count[i] += count[i - 1];
        for (int i = m_size - 1; i >= 0; i--) {
            output[count[m_data[i]] - 1] = m_data[i];
            count[m_data[i]]--;
        }
        for (int i = 0; i < m_size; i++)
            m_data[i] = output[i];

        delete[] count;
        delete[] output;
    }

    void radixSort() {
        T max = getMax();
        for (int place = 1; max / place > 0; place *= 10)
            countSort(place);
    }

    void bucketSort() {
        if (m_size == 0)
            return;

        int bucketsNum = std::sqrt(m_size);
        if (bucketsNum < 1)
            bucketsNum = 1;

        T **buckets = new T *[bucketsNum];
        int *bucketSizes = new int[bucketsNum]();
        int *bucketCapacities = new int[bucketsNum];

        for (int i = 0; i < bucketsNum; i++) {
            bucketCapacities[i] = m_size;
            buckets[i] = new T[bucketCapacities[i]];
        }

        T minV = m_data[0], maxV = m_data[0];
        for (int i = 1; i < m_size; i++) {
            minV = min(minV, m_data[i]);
            maxV = max(maxV, m_data[i]);
        }

        if (minV == maxV) {
            for (int i = 0; i < bucketsNum; i++)
                delete[] buckets[i];
            delete[] buckets;
            delete[] bucketSizes;
            delete[] bucketCapacities;
            return;
        }

        for (int i = 0; i < m_size; i++) {
            int bi = (bucketsNum * (m_data[i] - minV)) / (maxV - minV + 1);
            if (bi >= bucketsNum)
                bi = bucketsNum - 1;

            if (bucketSizes[bi] == bucketCapacities[bi]) {
                T *newBucket = new T[bucketCapacities[bi] * 2];
                for (int j = 0; j < bucketSizes[bi]; j++)
                    newBucket[j] = buckets[bi][j];
                delete[] buckets[bi];
                buckets[bi] = newBucket;
                bucketCapacities[bi] *= 2;
            }
            buckets[bi][bucketSizes[bi]++] = m_data[i];
        }

        int idx = 0;
        for (int i = 0; i < bucketsNum; i++) {
            insertionSort(buckets[i], bucketSizes[i]);
            for (int j = 0; j < bucketSizes[i]; j++) {
                m_data[idx++] = buckets[i][j];
            }
            delete[] buckets[i];
        }

        delete[] buckets;
        delete[] bucketSizes;
        delete[] bucketCapacities;
    }

private:
    int m_size;
    T *m_data;

    void merge(int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        T *l = new T[n1];
        T *r = new T[n2];
        for (int i = 0; i < n1; i++)
            l[i] = m_data[left + i];
        for (int j = 0; j < n2; j++)
            r[j] = m_data[mid + 1 + j];

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (l[i] < r[j])
                m_data[k++] = l[i++];
            else
                m_data[k++] = r[j++];
        }
        while (i < n1)
            m_data[k++] = l[i++];
        while (j < n2)
            m_data[k++] = r[j++];
        delete[] l;
        delete[] r;
    }

    int partition(int left, int right) {
        int pivot = left;
        int i = left;
        for (int j = left + 1; j <= right; j++) {
            if (m_data[j] < m_data[pivot]) {
                i++;
                std::swap(m_data[i], m_data[j]);
            }
        }
        std::swap(m_data[i], m_data[pivot]);
        return i;
    }

    void mergeSort(int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(left, mid);
            mergeSort(mid + 1, right);
            merge(left, mid, right);
        }
    }

    void quickSort(int left, int right) {
        if (left >= right)
            return;
        int mid = partition(left, right);
        quickSort(left, mid - 1);
        quickSort(mid + 1, right);
    }

    T getMax() {
        T maxVal = m_data[0];
        for (int i = 1; i < m_size; i++) {
            if (m_data[i] > maxVal)
                maxVal = m_data[i];
        }
        return maxVal;
    }

    void countSort(int place) {
        const int RANGE = 10;
        int *count = new int[RANGE]();
        T *output = new T[m_size];

        for (int i = 0; i < m_size; i++)
            count[(m_data[i] / place) % 10]++;

        for (int i = 1; i < RANGE; i++)
            count[i] += count[i - 1];

        for (int i = m_size - 1; i >= 0; i--) {
            int digit = (m_data[i] / place) % 10;
            output[--count[digit]] = m_data[i];
        }

        for (int i = 0; i < m_size; i++)
            m_data[i] = output[i];

        delete[] count;
        delete[] output;
    }

    void insertionSort(T *arr, int n) {
        for (int i = 1; i < n; i++) {
            T key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }
};

