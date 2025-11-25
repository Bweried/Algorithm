#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

class MedianFinder {
private:
    priority_queue<int> left;  // 大根堆
    priority_queue<int, vector<int>, greater<>> right;  // 小根堆

public:
    void addNum(int num) {
        if(left.size() == right.size()) {
            right.push(num);
            left.push(right.top());
            right.pop();
        }
        else {
            left.push(num);
            right.push(left.top());
            left.pop();
        }
    }
    
    double findMedian() {
        if(left.size() > right.size()) {
            return left.top();
        } 
        return (left.top() + right.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */