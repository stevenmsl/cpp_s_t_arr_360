#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol360;

string toString(vector<int> input)
{
  string result = "[";
  for (auto e : input)
  {
    result += to_string(e);
    result += ",";
  }
  /* remove the last comma */
  if (result.size() > 1)
    result.pop_back();
  result += "]";
  return result;
}

/*
Input: nums = [-4,-2,2,4], a = 1, b = 3, c = 5
Output: [3,9,15,33]
*/
tuple<vector<int>, vector<int>, vector<int>> testFixture1()
{
  return make_tuple<vector<int>, vector<int>, vector<int>>(
      {-4, -2, 2, 4}, {1, 3, 5}, {3, 9, 15, 33});
}

/*
Input: nums = [-4,-2,2,4], a = -1, b = 3, c = 5
Output: [-23,-5,1,7]
*/
tuple<vector<int>, vector<int>, vector<int>> testFixture2()
{
  return make_tuple<vector<int>, vector<int>, vector<int>>(
      {-4, -2, 2, 4}, {-1, 3, 5}, {-23, -5, 1, 7});
}

void test1()
{
  auto f = testFixture1();
  cout << "Test 1 - exepct to see " << toString(get<2>(f)) << endl;
  auto coefficents = get<1>(f);
  auto result = Solution::sortTA(
      get<0>(f), coefficents[0], coefficents[1], coefficents[2]);
  cout << "result: " << toString(result) << endl;
}

void test2()
{
  auto f = testFixture2();
  cout << "Test 1 - exepct to see " << toString(get<2>(f)) << endl;
  auto coefficents = get<1>(f);
  auto result = Solution::sortTA(
      get<0>(f), coefficents[0], coefficents[1], coefficents[2]);
  cout << "result: " << toString(result) << endl;
}

main()
{
  test1();
  test2();

  return 0;
}