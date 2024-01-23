#include <iostream>
#include <vector>

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
    }

    for (double &prob : psum1)
    {
        if (prob != 0)
        {
            prob /= 36.0;
        }
    }

    return psum1;
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

int main()
{
    vector<int> originalDieA = {1, 2, 3, 4, 5, 6};
    vector<int> originalDieB = {1, 2, 3, 4, 5, 6};
    transform(originalDieA, originalDieB);

    return 0;
}
