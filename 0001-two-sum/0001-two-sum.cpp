class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> solution_map;
        // Decalre a variable to save the solution_map.find() result 
        // becuase it would be used several times. and declare it
        // outside the loop for saving memory.
        // intiating it with solution_map.end()
        // so the auto keyword take effect
        auto find_result = solution_map.end();

        // Iterating over nums vector.
		for (int i = 0; i < nums.size(); i++)
		{
			// I insert into the solution_map
            // the element value as a key
            // so I can search for it later
            // and the element index (i) as value
            // so I can return it when I find the solution.
			solution_map.insert({ nums[i], i });

            // assign find_result the value of
            // target - current element. If I found a value
            // then I found the solution.
			find_result = solution_map.find(target - nums[i]);

            // Checking if I found a solution, and if the solution
            // is not the same as the current element.
            // in case of [3,3] the second condition
            // will prevent the wrong solution of [0,0]
            // We can escape this issue by inserting the element
            // in solution_map after the if block
			if (
                (find_result != solution_map.end())
                &&
                (find_result->second != i)) {
                // if we found a solution, we return the current index
                // and the second elment of the find_result
                // which is the index of the other element.
				return { find_result->second,i };
			}
		}
        // We don't need this return statement because in the problem
        // they told us that there is certainly an answer
        // but I wrote it because my editor kept showing me an error.
		return { -1, -1 };
        }
    
};