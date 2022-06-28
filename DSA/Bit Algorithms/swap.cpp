#include<bits/stdc++.h>
using namespace std;

void swap(int& a, int& b) {
    if(a == b)
        return;
    a = a^b;
    b = a^b;
    a = a^b;
}