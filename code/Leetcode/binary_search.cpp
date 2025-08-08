#include<iostream>
#include<vector>

using namespace std;

int search(vector<int>& nums, int target) {
	int size = nums.size();
	int begin = 0;
	int end = size - 1;
	int mid;
	while (begin <= end){
		mid = begin + (end - begin)/2;
	
		// cout << mid << '\n';
		if((nums.at(0) > target) || (nums.at(size-1) < target)){
			return -1;
		}
		if (nums[mid] == target){
			return mid;
		} else if (nums[mid] < target){
			begin = mid + 1;
		} else if (nums[mid] > target){
			end = mid - 1;
			
		}
	}
	return -1;
}

int main(){
	vector<int> nums = {-1,0,3,5,9,12};
	cout << search(nums, 2);
	return 0;
}