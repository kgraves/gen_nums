#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

void gen_nums(int n, int min, int max, int *nums) {
    int range = ((int)abs(min) + (int)abs(max));

    for (int i=0; i<n; ++i) {
        nums[i] = (rand() % range) - (int)abs(min);
    }
}

int main(int argc, char **argv) {
    // arguments:
    //     - number of values to generate
    //     - minimum possible value
    //     - maximum possible value
    if (argc != 4) {
        cout << "usage:" << endl
             << " gen_nums [NUM VALUES] [MIN VALUE] [MAX VALUE]" << endl;
        return 1;
    }

    srand( time(NULL) );

    int n = atoi(argv[1]);
    int min = atoi(argv[2]);
    int max = atoi(argv[3]);
    int *nums = new int[n];

    gen_nums(n, min, max, nums);

    for (int i=0; i<n; ++i) {
        cout << nums[i] << endl;
    }

    // clean up
    delete nums;

    return 0;
}
