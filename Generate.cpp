#include <bits/stdc++.h>
#include <chrono>
#include <random>
#define seed std::chrono::system_clock::now().time_since_epoch().count()
#define ran_gen mt19937
using namespace std;


void gen(fstream &file, int &n, int &N,ran_gen & generator)
{   
    int d_i_min,d_i_max,dimensions;
    while(N--){
        dimensions = n;
        while(dimensions >=2 ){
            d_i_min = generator()%20 + 1;
            d_i_max = generator()%20 + 1;
            if(d_i_min > d_i_max) swap(d_i_max,d_i_min);
            file<<d_i_min<<" "<<d_i_max<<" ";
            dimensions--;
        }
        d_i_min = generator()%20 + 1;
        d_i_max = generator()%20 + 1;
        if(d_i_min > d_i_max) swap(d_i_max,d_i_min);
        file<<d_i_min<<" "<<d_i_max<<endl;

    }
    file.close();
    return;

}

int main(int num_args, char *args[])
{

    // n = Number of Dimensions, N = Number of data points
    int n, N;

    // assert that we have gotten two command line arguments n and N
    assert(num_args == 3);

    n = stoi(string(args[1]));
    N = stoi(string(args[2]));

    ran_gen generator(seed);

    fstream file;
    string filename = "dat_" + string(args[1]) + "_dimensions_" + string(args[2]) + "_entries.txt";
    file.open(filename, ios::out);

    file << n << " " << N << endl;

    gen(file,n,N,generator);

    return 0;
}