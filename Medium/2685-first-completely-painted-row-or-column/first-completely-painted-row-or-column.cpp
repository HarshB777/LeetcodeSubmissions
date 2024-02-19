class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int,int> rowIndex;
        unordered_map<int,int> colIndex;

        int r = mat.size();
        int c = mat[0].size();

        vector<vector<int>> rows(r);
        vector<vector<int>> cols(c);
        
        for (int i = 0; i < r; i++)
        {

            for(int j = 0; j < c; j++)
            {
                rowIndex[mat[i][j]] = i;
                colIndex[mat[i][j]] = j;
            }
        }

        for (int i = 0; i < arr.size(); i++)
        {
            int ele = arr[i];

            int x = rowIndex[ele];
            int y = colIndex[ele];

            rows[x].push_back(ele);

            if (rows[x].size()==c)
            {
                return i;
            }

            cols[y].push_back(ele);

            if (cols[y].size()==r)
            {
                return i;
            }
        }

        return 0;

        
    }
};