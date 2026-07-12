class KthLargest {
private:
priority_queue<int, vector<int>, greater<int>> minHeap;
int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->minHeap=priority_queue<int, vector<int>, greater<int>>(nums.begin(), nums.end());
        this->k=k;
        while(minHeap.size()>k){
            this->minHeap.pop();
        }
    }
    
    int add(int val) {
        this->minHeap.push(val);
        while(minHeap.size()>this->k){
            this->minHeap.pop();
        }
        return this->minHeap.top();
    }
};
