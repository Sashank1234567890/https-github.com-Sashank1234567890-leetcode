class Solution
{
public:

    struct trieNode
    {
        trieNode* left;
        trieNode* right;

        trieNode()
        {
            left = NULL;
            right = NULL;
        }
    };

    void insert(trieNode* root, int num)
    {
        trieNode* curr = root;

        for(int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;

            if(bit == 0)
            {
                if(curr->left == NULL)
                    curr->left = new trieNode();

                curr = curr->left;
            }
            else
            {
                if(curr->right == NULL)
                    curr->right = new trieNode();

                curr = curr->right;
            }
        }
    }

    int maxXor(trieNode* root, int num)
    {
        trieNode* curr = root;
        int ans = 0;

        for(int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;

            // Want opposite bit to maximize XOR
            if(bit == 0)
            {
                if(curr->right)
                {
                    ans |= (1 << i);
                    curr = curr->right;
                }
                else
                {
                    curr = curr->left;
                }
            }
            else
            {
                if(curr->left)
                {
                    ans |= (1 << i);
                    curr = curr->left;
                }
                else
                {
                    curr = curr->right;
                }
            }
        }

        return ans;
    }

    int findMaximumXOR(vector<int>& nums)
    {
        trieNode* root = new trieNode();

        for(int x : nums)
        {
            insert(root, x);
        }

        int result = 0;

        for(int x : nums)
        {
            result = max(result, maxXor(root, x));
        }

        return result;
    }
};