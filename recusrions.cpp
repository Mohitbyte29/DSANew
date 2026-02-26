// #include <iostream>
// using namespace std;

// int count = 0;
// void func(int n){
//     if(count == n)
//     return;
//     count++;
//     cout<<"Mohit"<<endl;
//     func(n);
// }

// int main(){
//     int n = 5;
//     func(n);
//     return 0;
// }


// ! By backtracking

#include <iostream>
using namespace std;

int count = 0;
void func(int n){
    if(count == n)
    return;
    count++;
    func(n);
    cout<<"Mohit"<<endl;
}

int main(){
    int n = 5;
    func(n);
    return 0;
}

