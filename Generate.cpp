#include <bits/stdc++.h>
using namespace std;

int main(int num_args, char * args[]){
    // n = Number of Dimensions, N = Number of data points
    int n,N ;
    // assert that we have gotten two command line arguments n and N
    assert(num_args == 3);
    n = stoi(string(args[1]));
    N = stoi(string(args[2]));
    // cout<<n << N<<endl;

    fstream file ;
    file.open("dat_"+string(args[1])+"_dimensions_"+string(args[2]) + "_entries.txt" , ios::out);
    file<<n<<" "<<N<<endl;
    file.close();
    return 0;
}