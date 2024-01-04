# DoomedDice

Part-A (15-20 Minutes):
1. How many total combinations are possible? Show the math along with the code!

![image](https://github.com/VishnupriyaThammina/DoomedDice/assets/89837239/6c000f4e-7aec-460b-9ccf-4e1d3b1c8af9)


3. Calculate and display the distribution of all possible combinations that can be
obtained when rolling both Die A and Die B together. Show the math along with
the code!
Hint: A 6 x 6 Matrix.

![image](https://github.com/VishnupriyaThammina/DoomedDice/assets/89837239/2da6e519-3b22-4979-941d-7aa02cb46eba)

5. Calculate the Probability of all Possible Sums occurring among the number of
combinations from (2).
Example: P(Sum = 2) = 1/X as there is only one combination possible to obtain
Sum = 2. Die A = Die B = 1.

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

: I tried my level best
to discover a solution but I was unable to come up with an efficient approach 
I have an idea 
Which is like brute force
for die A : we have [1,2,3,4,x,y] case all together will give us 4!*4c2 ways let this be m
For die B: we have [1 to 9] we can 6 choose numbers as mentioned die can have more than 6 spots on the face which will lead to 9c6 ways let this be n
so I will have to check 
m*n times for each combination in m will be checked with each combination in n
by calculating probabilities just like I did in question 3 of part a
if the probabilities match that would be the new die a and die b pair
