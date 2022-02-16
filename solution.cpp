#include "solution.h"
#include "util.h"
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <algorithm>
#include <string>
#include <queue>
using namespace sol360;
using namespace std;

/*takeaways
  - there is a very big assumption here, and the
    solution can only work in a very limited
    scenario
    - the axis of symmetry is x = -b/2a
    - example: [-4,-2,2,4], a = 1, b = 3, c = 5
      x = -3/2x1 = -1.5 happens to be the mid
      point of the input array so the bigger
      values are on both ends , and we can
      reach the smallest numbers at the
      mid-points
  - if the x coordinates given are not
    symmetric along the axis of symmetry
    , there is no pattern can be used and
    hence O(n) can't be achieved
*/

vector<int> Solution::sortTA(vector<int> &input, int a, int b, int c)
{
  const int n = input.size();
  auto f = [&](int x)
  {
    return a * x * x + b * x + c;
  };

  auto result = vector<int>(n);

  auto l = 0, r = n - 1;
  int indx;
  if (a > 0)
  {
    /* put the values starting from the very last element */
    indx = n - 1;
    /* bigger values on the ends */
    while (l <= r)
      /* pick the bigger one */
      result[indx--] = f(input[l]) > f(input[r]) ? f(input[l++]) : f(input[r--]);
  }
  else
  {
    /* put the values starting from the very first element */
    indx = 0;
    /* smaller values on the ends */
    while (l <= r)
      /* pick the smaller one */
      result[indx++] = f(input[l]) < f(input[r]) ? f(input[l++]) : f(input[r--]);
  }

  return result;
}