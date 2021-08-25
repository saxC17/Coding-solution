class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProduct = INT_MIN;
        int currMin = 1, currMax = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                currMax = currMax * nums[i];
                currMin = min(1, currMin * nums[i]);
                maxProduct = max(currMax, maxProduct);
            }
            else if (nums[i] < 0) {
                int temp = currMax;
                if (currMin < 0) {
                    currMax = currMin * nums[i];
                    maxProduct = max(maxProduct, currMax);

                }
                else {
                    currMax = 1;
                }
                currMin = temp * nums[i];
                maxProduct = max(maxProduct, currMin);

            }
            else {
                currMax = 1; currMin = 1;
                maxProduct = max(0, maxProduct);
            }
        }
        return maxProduct;
    }
};