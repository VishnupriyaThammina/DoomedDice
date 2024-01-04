#include <iostream>
#include <vector>
#include <unordered_map>
#include <iomanip>
using namespace std;

int TotalCombinations(int SizeofDie1, int SizeofDie2)
{
  return SizeofDie1 * SizeofDie2;
}
pair<vector<int>, vector<int>> transform(vector<int> die_a, vector<int> die_b)
{
  vector<int> new_a = die_a;
  vector<int> new_b = die_b;
  for (int i = 0; i < die_a.size(); i++)
  {
    if (die_a[i] > 4)
    {
      new_a[i] = 4;
    }
  }
  return {new_a, new_b};
}

int main()
{
  int SizeD1 = 6;
  int SizeD2 = 6;

  int tc = TotalCombinations(SizeD1, SizeD2);
  cout << "Part A" << endl;
  cout << "Question 1" << endl;
  //   if a = 6 and b = 6 and we have two spots to be filled
  //   spot1 is occupied by a choices and spot2 is occupied by b choices
  cout << "Total Combinations possible: " << tc << endl;

  cout << "Question 2" << endl;
  // 6 by 6 matrix
  vector<vector<pair<int, int>>> matrix(6, vector<pair<int, int>>(6));
  unordered_map<int, vector<pair<int, int>>> mp;
  cout << "All possible ccombinations: " << endl;
  cout << "(A ,B)";
  for (int i = 1; i <= 6; ++i)
  {
    cout << "  B=" << i << " ";
  }
  cout << endl;

  // Filling the matrix with pairs and displaying Die A values
  for (int i = 0; i < 6; i++)
  {
    cout << " A=" << i + 1 << ": ";
    for (int j = 0; j < 6; j++)
    {
      matrix[i][j] = make_pair(i + 1, j + 1);
      int sum = matrix[i][j].first + matrix[i][j].second;
      mp[sum].push_back({matrix[i][j].first, matrix[i][j].second});
      cout << "(" << matrix[i][j].first << "," << matrix[i][j].second << ") ";
    }
    cout << endl;
  }

  cout << "Question : 3" << endl;
  unordered_map<int, int> probs;
  int count = 0;
  int sum = 0;
  for (auto i : mp)
  {
    sum = i.first;
    for (auto j : i.second)
    {
      count++;
    }
    cout << endl;
    probs[sum] = count;
    cout << "P(sum : " << i.first << ") = " << count << "/36  " << fixed << setprecision(2) << (double)count / 36 << endl;
    cout << i.first << "=>";
    for (auto j : i.second)
    {

      cout << "(" << j.first << "," << j.second << ")";
    }
    count = 0;
    cout << endl;
  }
  cout << endl;

  cout << "Part B " << endl;
  // as per the conditions
  vector<int> die_a = {1, 2, 3, 4, 5, 6};
  vector<int> die_b = {1, 2, 3, 4, 5, 6};
  pair<vector<int>, vector<int>> n = transform(die_a, die_b);
  for (auto i : n.first)
  {
    cout << i << " ";
  }
  cout << endl;
  for (auto i : n.second)
  {
    cout << i << " ";
  }
    cout <<endl;
    for (auto a : n.first) {
        for (auto b : n.second) {
            cout << "(" << a << ", " << b << ") ";
        }
        cout << endl;
    }
  return 0;
}