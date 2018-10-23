/*
描述
设计一个数据结构，初始为空，支持以下操作：
（1）增加一个元素，要求在log(n)时间内完成，其中n是该数据结构中当前元素的个数。注意：数据结构中允许有重复的元素。
（2）返回当前元素集合的中位数，要求在常数时间内完成。如果当前元素的个数为偶数，那么返回下中位数（即两个中位数中较小的一个）。
（3）删除中位数，要求在log(n)时间内完成。

输入
输入的第一行是一个自然数T，代表测试数据的组数((1 ≤ T ≤ 600))。每组测试数据的第一行是个自然数N，代表操作的次数，1<=N<=10000。后面的N行中的每行代表一个操作，每次操作首先输入一个单字符代表操作的类型：

I表示插入，后面跟着输入一个正整数（这是唯一带有输入数值的操作）。
Q表示查询，输出当前的中位数（这是唯一产生输出的操作）。
D表示删除当前的中位数。

输入保证是正确的：查询时集合保证不为空（即中位数是存在的），删除时保证集合中有足够可供删除的元素。
输出
每次查询操作Q时输出的中位数，每次输出单独占一行。
*/
#include<iostream>
#include<queue>
using namespace std;

class MyStruct {
public:
    priority_queue<int> max_heap;//放最小的一半
    priority_queue<int, vector<int>, greater<int> > min_heap;//放最大的另一半
    int size;
    
    MyStruct() {
        size = 0;
    }
    
    void Insert(int num_to_insert) {
        min_heap.push(num_to_insert);
        max_heap.push(min_heap.top());
        min_heap.pop();
        if (min_heap.size() < max_heap.size()) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
    }
    
    int Query() {
        if (max_heap.size() > min_heap.size()) {
            return max_heap.top();
        } else if (max_heap.size() < min_heap.size()) {
            return min_heap.top();
        } else {
            return max_heap.top();
        }
    }
    
    void Delete() {
        if (max_heap.size() > min_heap.size()) {
            max_heap.pop();
        } else if (max_heap.size() < min_heap.size()) {
            min_heap.pop();
        } else {
            max_heap.pop();
        }
    }
};

int main(){
    int T;
    cin >> T;
    while(T--) {
        MyStruct myStruct;
        int N;
        cin >> N;
        while(N--) {
            char opration_type;
            cin >> opration_type;
            switch(opration_type) {
            case 'I':
                int num;
                cin >> num;
                myStruct.Insert(num);
//                cout << "min heap size " << myStruct.min_heap.size() << "\tmax heap size " << myStruct.max_heap.size() <<  endl;
                break;
            case 'Q':
                cout << myStruct.Query() << endl;
//                cout << "min heap size " << myStruct.min_heap.size() << "\tmax heap size " << myStruct.max_heap.size() <<  endl;
                break;
            case 'D':
                myStruct.Delete();
//                cout << "min heap size " << myStruct.min_heap.size() << "\tmax heap size " << myStruct.max_heap.size() <<  endl;
                break;
            }
        }
    }
    return 0;
}
