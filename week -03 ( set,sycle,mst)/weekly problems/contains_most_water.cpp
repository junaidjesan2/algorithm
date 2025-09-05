#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        vector<long long> H(N);
        for (int i = 0; i < N; i++)
            cin >> H[i];

        int max1_idx = 0;
        int max2_idx = 1;

        if (H[1] > H[0])
            swap(max1_idx, max2_idx);

        for (int i = 2; i < N; i++)
        {
            if (H[i] > H[max1_idx])
            {
                max2_idx = max1_idx;
                max1_idx = i;
            }
            else if (H[i] > H[max2_idx])
            {
                max2_idx = i;
            }
        }

        cout << min(max1_idx, max2_idx) << " " << max(max1_idx, max2_idx) << "\n";
    }
    return 0;
}
