class Solution {
/*
 1. Why n + m?

Suppose:

num1 = "123"
num2 = "45"

There are 3 digits and 2 digits.

The result can have at most:

3 + 2 = 5 digits

For example:

  999
×  99
-----
98901

So:

vector<int> res(n + m, 0);

creates:

res = [0, 0, 0, 0, 0]

Think of this as the places where the answer will eventually go:

res:  [0][0][0][0][0]
        ↑  ↑  ↑  ↑  ↑
       10⁴ 10³ 10² 10¹ 10⁰
2. The important part: positions

Take:

num1 = "123"
num2 = "45"

Indices are:

num1:  1   2   3
        0   1   2

num2:  4   5
        0   1

Now consider multiplying:

3 × 5

These are at indices:

i = 2
j = 1

Their product belongs near the right side of the result.

We calculate:

pos1 = i + j;
pos2 = i + j + 1;

Therefore:

pos1 = 2 + 1 = 3
pos2 = 2 + 1 + 1 = 4

So:

res = [0, 0, 0, 0, 0]
                 ↑  ↑
               pos1 pos2

The product 3 × 5 = 15 gives:

1 → carry
5 → current digit

So we put:

res[3] += 1
res[4] = 5

giving:

res = [0, 0, 0, 1, 5]
3. Why i + j and i + j + 1?

This is the trickiest part.

Suppose:

num1 = 123
num2 = 45

Normal multiplication is:

       1 2 3
   ×     4 5
   -----------
       6 1 5       ← 123 × 5
     4 9 2         ← 123 × 4, shifted
   -----------
     5 5 3 5

Every pair of digits has a specific decimal position.

If digits are at indices i and j, their product affects positions around:

i + j
i + j + 1

That's why we calculate:

int pos1 = i + j;
int pos2 = i + j + 1;

Think of:

pos1 = carry position
pos2 = digit position
 
 
 */   
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";

        int n = num1.size();
        int m = num2.size();

        vector<int> res(n + m, 0);

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {

                int a = num1[i] - '0';
                int b = num2[j] - '0';

                int product = a * b;

                int pos1 = i + j;
                int pos2 = i + j + 1;

                int sum = product + res[pos2];

                res[pos2] = sum % 10;
                res[pos1] += sum / 10;
            }
        }

        string ans;

        int i = 0;

        while (i < res.size() && res[i] == 0)
            i++;

        while (i < res.size())
            ans.push_back('0' + res[i++]);

        return ans;
    }
};