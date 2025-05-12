class NumArray {
public:
    int n;
    vector<int>segtree;
void build(int i, int start, int end, vector<int>&segtree, vector<int>& nums){
    if(start==end){
        segtree[i]=nums[start];
        return ;
    }

    int mid=start+(end-start)/2;

    build(2*i+1, start,mid, segtree, nums);
    build(2*i+2, mid+1, end, segtree, nums);
    segtree[i]=segtree[2*i+1]+segtree[2*i+2];
}
    void updateTree(int index, int val ,int i , int start, int end){
        if(start==end){
            segtree[i]=val;
            return;
        }
        int mid=start+(end-start)/2;
        if(index<=mid){
            updateTree(index,val, 2*i+1, start, mid);
        }
        else{
            updateTree(index,val, 2*i+2,mid+1,end);
        }
        segtree[i]=segtree[2*i+1]+segtree[2*i+2];
    }


    NumArray(vector<int>& nums) {
        n=nums.size();
        segtree.resize(4*n);
        build(0,0,n-1,segtree,nums);
        
    }
    
    void update(int index, int val) {
        updateTree(index, val, 0, 0, n-1);
        
    }

    int query(int left,int right, int i, int start, int end){
        if(start>right || end<left){
            return 0;
        }
        if(start>=left && end<=right){
            return segtree[i];
        }
        
        int mid=start+(end-start)/2;

        return query(left, right, 2*i+1, start, mid)+query(left, right, 2*i+2, mid+1,end);
    }
    
    int sumRange(int left, int right) {
        return query( left,  right, 0,0,n-1);
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */