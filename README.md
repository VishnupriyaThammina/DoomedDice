# DoomedDice

Part-A (15-20 Minutes):
1. How many total combinations are possible? Show the math along with the code!
   we have two dice 
(_,_ ) two positions to be filled as the die values can also have repetitions from the knowledge i have upon permutations and combinations it is 6*6 with is 36

![image](https://github.com/VishnupriyaThammina/DoomedDice/assets/89837239/6c000f4e-7aec-460b-9ccf-4e1d3b1c8af9)


2. Calculate and display the distribution of all possible combinations that can be
obtained when rolling both Die A and Die B together. Show the math along with
the code!
Hint: A 6 x 6 Matrix.
as we need a 6*6 matrix
when two dice are rolled together these are possible combinations which is straight forward
and the probability to get the results for and pair of the following is 1/36 as there are 36 different combinations
![image](https://github.com/VishnupriyaThammina/DoomedDice/assets/89837239/2da6e519-3b22-4979-941d-7aa02cb46eba)

4. Calculate the Probability of all Possible Sums occurring among the number of
combinations from (2).
Example: P(Sum = 2) = 1/X as there is only one combination possible to obtain
Sum = 2. Die A = Die B = 1.
As mentioned
sum = 2 =>(1,1)
I used unordered_map to store the probabilities and calculated the counts in an efficient manner
where my unordered_map<sum, vector of pairs> sum is a+b and pair is (a,b) key value sum, I pushed all of the pairs into the vector, count the number of pairs present in each key value, and get respective probability
![image](https://github.com/VishnupriyaThammina/DoomedDice/assets/89837239/39666ef3-12ff-4efe-b445-c1a5ba93611a)

Part B:
Input:
● Die_A = [1, 2, 3, 4, 5, 6] & Die B = Die_A = [1, 2, 3, 4, 5, 6]
Output:
● A Transform Function undoom_dice that takes (Die_A, Die_B) as input &
outputs New_Die_A = [?, ?, ?, ?, ?, ?],New_Die_B = [?, ?,
?, ?, ?, ?] where,
● No New_Die A[x] > 4

![image](https://github.com/VishnupriyaThammina/DoomedDice/assets/89837239/c8a09af7-9e41-46ba-88f2-922ec7db0b90)

`Part b:`

we are generating all combinations possible from [1,2,3,4] on rolling a dice
and we are generating all combinations possible on rolling dice with digigts from 1 to 8
because 8+4=12 the as we are removing 5,6 the highest number that can be considered is 8
now we find all combinations possible for 8
these combinations are combinations of faces on dice
now we take set of faces that can be possible 
as such two dice
and we try to calculate the probability 
if the prob vectors match 
that is the perfect dice combinations

![image](https://github.com/VishnupriyaThammina/DoomedDice/assets/89837239/d4666581-be00-4b18-a758-eecbca376a3f)


