#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  int a[n];

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  sort(a, a + n);
  for (int i = 0; i < n; i++)
  {
    cout << a[i] << " ";
  }
  cout << endl;

  /* Upper and Lower bound functions needed sorted inputs to work in log(n)
      Lower Bound - if element not present then element greater than
                    if element then that element
      Upper Bound - if ele present/ not, then larger
  */

  cout << endl;
  int *ptr = upper_bound(a, a + n, 9);
  // In case of vector, iterator returned
  cout << (*ptr) << endl;

  // For sets

  int n;
  cin >> n;
  set<int> s;

  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    s.insert(x);
  }

  // Since sets are sorted by default, so can be directly used
  // auto it = lower_bound(s.begin(), s.end(), 5); // O(n) for maps too
  // O(log n)
  auto it = s.lower_bound(5);
  cout << (*it) << endl;
}
