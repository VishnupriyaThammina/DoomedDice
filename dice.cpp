#include <iostream>
#include <vector>
#include <unordered_map>
#include <iomanip>


using namespace std;

void genCombinationsA(const vector<int> &elements, int length, vector<int> &current, vector<vector<int>> &allCombinations)
{
    if (current.size() == static_cast<size_t>(length))
    {
        allCombinations.push_back(current);
        return;
    }

    for (int element : elements) 
    {
        current.push_back(element);
       
        genCombinationsA(elements, length, current, allCombinations);
        current.pop_back();
    }
}



void genCombinationsB(const vector<int> &elements, int length, int start, vector<int> &current, vector<vector<int>> &allCombinations)
{
    if (current.size() == static_cast<size_t>(length))
    {
        allCombinations.push_back(current);
        return;
    }

    for (int i = start; i < static_cast<int>(elements.size()); ++i)
    {
        
        current.push_back(elements[i]);
        genCombinationsB(elements, length, i + 1, current, allCombinations);
        current.pop_back();
    }
}

vector<double> calculateProbSum(const vector<int> &arr1, const vector<int> &arr2)
{
    vector<double> psum1(12, 0.0);
    for (int i : arr1)
    {
        for (int j : arr2)
        {
            int k = i + j;
            psum1[k - 1] += 1.0;
        }
    }// 1st we calculate our sume

    for (double &prob : psum1)
    {
        if (prob != 0)
        {
            prob /= 36.0;
        }
    }// we calculate probs

    return psum1; // return
}

void printCombination(const vector<int> &combination)
{
    cout << "[";
    for (size_t i = 0; i < combination.size(); ++i)
    {
        cout << combination[i];
        if (i < combination.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "]";
}


// Main transformation function
void transform(const vector<int> &originalDieA, const vector<int> &originalDieB)
{
    vector<int> elementsDieA = {1, 2, 3, 4};
    int lengthDieA = 6;
    vector<int> currentDieA;
    vector<vector<int>> combinationsDieA;
    genCombinationsA(elementsDieA, lengthDieA, currentDieA, combinationsDieA);

    vector<int> elementsDieB = {1, 2, 3, 4, 5, 6, 7, 8};
    int lengthDieB = 6;
    int startDieB = 0;
    vector<int> currentDieB;
    vector<vector<int>> combinationsDieB;
    genCombinationsB(elementsDieB, lengthDieB, startDieB, currentDieB, combinationsDieB);

    vector<double> originalProbSum = {0.0, 1.0 / 36, 2.0 / 36, 3.0 / 36, 4.0 / 36, 5.0 / 36, 6.0 / 36, 5.0 / 36, 4.0 / 36, 3.0 / 36, 2.0 / 36, 1.0 / 36};

    bool flag = false;
    for (const auto &comboDieA : combinationsDieA)
    {
        for (const auto &comboDieB : combinationsDieB)
        {
            if (calculateProbSum(comboDieA, comboDieB) == originalProbSum)
            {
                cout << "\nNew dice combinations:" << endl;
                cout << "New die a: ";
                printCombination(comboDieA);
                cout << "\nNew die b: ";
                printCombination(comboDieB);
                cout << endl;
                flag = true;
                break;
            }
        }
        if (flag)
        {
            break;
        }
    }
}




int TotalCombinations(int SizeofDie1, int SizeofDie2)
{
  return SizeofDie1 * SizeofDie2;
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
  vector<vector<pair<int, int>>> matrix(6, vector<pair<int, int>>(6)); //(A,B)
  unordered_map<int, vector<pair<int, int>>> mp; // 
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
      matrix[i][j] = make_pair(i + 1, j + 1); // (1,1)
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

    vector<int> originalDieA = {1, 2, 3, 4, 5, 6}; 
    vector<int> originalDieB = {1, 2, 3, 4, 5, 6};
    transform(originalDieA, originalDieB);

  return 0;
}
