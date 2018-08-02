//
// Created by gwengww on 8/1/18.
//

#include <vector>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    vector<int> a = {4,5,6,9};
    vector<int> b = {3,7,6};
    vector<int> c = {4,4};
    vector<int> d = {4,3,5};
    cout << (a<b) << endl;
    cout << (a>c) << endl;
    cout << (c<d) << endl;
}