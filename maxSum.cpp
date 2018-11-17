#include<iostream>
using namespace std;
//Kadane’s algorithm

int main(void) {
    int SIZE, temp, sum, maxSum = 0;
    cin >> SIZE;
    int matrix[SIZE][SIZE];
    int sumArray[SIZE];
    //get the input
    for (int x = 0; x < SIZE; x++){
        for (int y = 0; y < SIZE; y++){
            cin >> temp;
            matrix[x][y] = temp;
            //set the value for the hole matrix
            maxSum += temp;

        }
    }
    for (int i = 0; i < SIZE; i++) {
        //clear the array for next subset
        fill_n(sumArray,SIZE,0);
        //for eath row in the subset
        for (int j = i; j < SIZE; j++) {
            //add a row
            for (int k = 0; k < SIZE; k++) {
                sumArray[k] += matrix[j][k];
            }
            //calc the bigest rektangel
            sum=0;
            for (int l = 0; l < SIZE; l++) {
                sum += sumArray[l];
                //save the largest
                maxSum = sum > maxSum ? sum : maxSum;
                //reset if rektangel not promising and luck for new
                sum = sum < 0 ? 0 : sum;
            }
        }
    }
    cout << maxSum << endl;
    return 0;
}