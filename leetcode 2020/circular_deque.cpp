#include<bits/stdc++.h>
#define pi 3.1415926535898
#define INF 1000000000000
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;

class Deque {
public:
    int *arr;
    int size;
    int front = -1;
    int rear = -1;
    Deque(int k) {
        arr = new int[k];
        this->size = k;
    }
    
    int insertFront(int value) {
        if(isFull())
            return -1;
        if(rear == -1) {
            rear++;
            front++;
            arr[front] = value;
        } else {
            if(front == 0)
                front = this->size-1;
            else
                front = front-1;
            arr[front] = value;
        }
        return front;
    }
    
    int insertLast(int value) {
        if(isFull())
            return -1;
        if(rear == -1) {
            rear++;
            front++;
            arr[front] = value;
        } else {
            if(rear == this->size-1)
                rear = 0;
            else
                rear = rear+1;
            arr[rear] = value;
        }
        return rear;
    }
    
    bool deleteFront() {
        if(front == -1)
            return false;
        if(front == rear) {
            front = -1;
            rear = -1;
            return true;
        }
        if(front == this->size-1)
            front = 0;
        else
            front = front+1;
        return true;
    }
    
    bool deleteLast() {
        if(rear == -1)
            return false;
        if(front == rear) {
            front = -1;
            rear = -1;
            return true;
        }
        if(rear == 0)
            rear = this->size-1;
        else
            rear = rear-1;
        return true;
    }
    
    int getFront() {
        if(front == -1)
            return -1;
        return this->arr[front];
    }
    
    int getRear() {
        if(rear == -1)
            return -1;
        return this->arr[rear];
    }
    
    bool isEmpty() {
        if(rear == -1)
            return true;
        return false;
    }

    bool isFull() {
        if(front<rear) {
            if((abs(rear-front) + 1) == size)
                return true;
            return false;
        }
        return ((size-front+rear+1) == size);
        
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 0)
            return {};
        if(n<k)
            return {};
        if(k == 0)
            return {};
        if(k == 1)
            return nums;
        int total = n-k+1;
        vector<int> ans(total);
        int index = 0;
        map<int,int> s;
        for(int i=0;i<k;i++) {
            s[nums[i]]++;
        }
        for(int i=k;i<n;i++) {
            ans[index++] = (s.rbegin())->first;
            s[nums[i-k]]--;
            if(s[nums[i-k]] == 0){
                s.erase(nums[i-k]);
            }
            if(s.count(nums[i]) == 0)
                s.insert({nums[i],1});
            else 
                s[nums[i]]++;
        }
        ans[index++] = (s.rbegin())->first;
        return ans;
        
    }
};