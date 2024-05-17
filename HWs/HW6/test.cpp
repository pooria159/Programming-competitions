#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void swap(int nums[], int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    int quickSelect(int nums[], int left, int right, int k) {
        int p = left + ((right - left) / 2);
        if (right > left) {
            int r2 = right;
            while (left != right) {
                if (left != p) {
                    if (nums[left] > nums[p]) {
                        swap(nums, left, p);
                        p = left;
                    } else {
                        left++;
                    }
                }
                if (right != p) {
                    if (nums[right] < nums[p]) {
                        swap(nums, right, p);
                        p = right;
                    } else {
                        right--;
                    }
                }
            }
            if ((sizeof(nums)/sizeof(nums[0]) - k) == p) {
                return nums[p];
            } else {
                if ((sizeof(nums)/sizeof(nums[0]) - k) < p) {
                    return quickSelect(nums, 0, p - 1, k);
                } else {
                    return quickSelect(nums, p + 1, r2, k);
                }
            }
        }
        return nums[p];
    }

    int findKthLargest(int nums[], int k) {
        return quickSelect(nums, 0, sizeof(nums)/sizeof(nums[0]) -1, k);
    }
};

int main(){
  Solution s;
  int k  = 2;
  int nums[] = {3, 2, 1, 5, 6, 4};
  cout << s.findKthLargest(nums,k);
  return 0;
}
