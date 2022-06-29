#include<bits/stdc++.h>
using namespace std;

// setting the nth bit in a num
int set(int num, int pos) {
    return num | (1 << pos);
}

// clearing the nth bit in a num
int clear(int num, int pos) {
    return num & (~(1 << pos));
}

// complement the nth bit
int toggle(int num, int pos) {
    return num ^ (1 << pos);
}

// check if nth bit is set or clear
bool at_position(int num, int pos) {
    return num & (1 << pos);
}

// one's complement
int ones_compliment(int num) {
    return ~num;
}

// two's compliment
int twos_compliment(int num) {
    return ~num + 1; // or return -n;
}

// stripping the lowest set bit
int strip_last_set_bit(int num) {
    return num & num-1;
}

// getting lowest set bit
int lowest_set_bit(int num) {
    return num & -num;
}

// you can divide and multiply by 2 by using right shift operator and left shift operator resp.

void swap(int& a, int& b) {
    if(a == b)
        return;
    a = a^b;
    b = a^b;
    a = a^b;
}

