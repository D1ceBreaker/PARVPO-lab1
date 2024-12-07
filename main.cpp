#include <iostream>
#include <omp.h>
#include <vector>
#include <random>


using std::vector, std::cin, std::cout;


void _shellSort(vector<int>& data, int gap, int offset) {
    for (int i = offset + gap; i < data.size(); i += gap){
        int j = i;
        int cur = data[i];
        while (j >= gap && data[j - gap] > cur){
            data[j] = data[j - gap];
            j -= gap;
        }
        data[j] = cur;
    }
}

void shellSortParallel(vector<int>& data, int threads) {
    int partitions = (int) data.size() / 2;
    while (partitions > 0){
        #pragma omp parallel num_threads(threads) shared(data, partitions) default(none)
        {
            #pragma omp for
            for (int i = 0; i < partitions; i++) {
                _shellSort(data, partitions, i);
            }
        }
        partitions = (int) (partitions / 2);
    }

}

vector<int> generate_random(int size){
    auto distribution = vector<int>(size, 0);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, INT_MAX - 1);
    for (int i = 0; i < size; i++){
        distribution[i] = dis(gen);
    }
    return distribution;
}

int main(){
    auto t0 = omp_get_wtime();
    auto vec = generate_random(100000000);
    shellSortParallel(vec, omp_get_num_procs());
    auto t1 = omp_get_wtime();
    cout << t1 - t0 << " seconds\n";
    return 0;
}