/*
    * Ho Chi Minh City University of Technology
    * Faculty of Computer Science and Engineering
    * Initial code for Assignment 0
    * Programming Fundamentals Spring 2022
    * Author: Tran Huy
    * Date: 06.01.2022
*/

//The library here is concretely set, students are not allowed to include any other libraries.
#ifndef studyInPink_h
#define studyInPink_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

////////////////////////////////////////////////////////////////////////
///STUDENT'S ANSWER BEGINS HERE
///Complete the following functions
///DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

// limit function  
void limitEXP(int& EXP) {
    if (EXP < 0) EXP = 0;
    if (EXP > 900) EXP = 900;
}
void limitHP(int& HP) {
    if (HP < 0) HP = 0;
    if (HP > 999) HP = 999;
}
void limitM(int& M) {
    if (M < 0) M = 0;
    if (M > 2000) M = 2000;
}

// Task 1
int firstMeet(int& EXP1, int& EXP2, const int& E1){
    //Complete this function to gain point on task 1
    if (E1 < 0 || E1>999)
    {
        return -999;
    }

    limitEXP(EXP1);
    limitEXP(EXP2);
   

    if (E1 >= 0 && E1 <= 399)
    {
        //find EXP2
        if (E1 <= 49)  EXP2 += 25;
        else if (E1 <= 99)  EXP2 += 50;
        else if (E1 <= 149) EXP2 += 85;
        else if (E1 <= 199) EXP2 += 75;
        else if (E1 <= 249) EXP2 += 110;
        else if (E1 <= 299) EXP2 += 135;
        else EXP2 += 160;

        //find EXP1
        if (E1 % 2) EXP1 = ceil(EXP1 + E1 * 1.0 / 10);
        else        EXP1 = ceil(EXP1 - E1 * 1.0 / 5);
    }

    else if (E1 >= 400 && E1 <= 999)
    {
        //find EXP2
        if (E1 <= 499) EXP2 = ceil(EXP2 + E1 * 1.0 / 7 + 9);
        else if (E1 <= 599) EXP2 = ceil(EXP2 + E1 * 1.0 / 9 + 11);
        else if (E1 <= 699) EXP2 = ceil(EXP2 + E1 * 1.0 / 5 + 6);
        else if (E1 <= 799)
        {
            EXP2 = ceil(EXP2 + E1 * 1.0 / 7 + 9);
            if (EXP2 > 200) EXP2 = ceil(EXP2 + E1 * 1.0 / 9 + 11);
        }
        else
        {
            EXP2 = ceil(EXP2 + E1 * 1.0 / 7 + 9);
            EXP2 = ceil(EXP2 + E1 * 1.0 / 9 + 11);
            if (EXP2 > 600) {
                EXP2 = ceil(EXP2 + E1 * 1.0 / 5 + 6);
                EXP2 = ceil(EXP2 * 1.15);
            }
        }

        //find EXP1
        EXP1 = ceil(EXP1 - 0.1 * E1);
    }

    //limit
    limitEXP(EXP1);
    limitEXP(EXP2);

    return EXP1 + EXP2;
}

//Task 2
int investigateScene(int& EXP1, int& EXP2, int& HP2, int& M2, const int& E2){
    //Complete this function to gain point on task 2
    if (E2 < 0 || E2>999)
    {
        return -999;
    }

    limitEXP(EXP1);
    limitEXP(EXP2);
    limitHP(HP2);
    limitM(M2);
    

    float d;
    //find EXP1,EXP2
    if (E2 >= 0 && E2 <= 299)
    {
        d = E2 * 1.0 / 9 + 10;
        EXP2 = ceil(EXP2 + d);
        EXP1 = ceil(EXP1 + d * 1.0 / 3);
    }
    else if (E2 >= 300 && E2 <= 499)
    {
        d = E2 * 1.0 / 9 + 10;
        EXP2 = ceil(EXP2 + d);
        EXP1 = ceil(EXP1 + d * 1.0 / 3);
        limitEXP(EXP1);
        limitEXP(EXP2);
        d = 0.35 * E2;
        EXP2 = ceil(EXP2 + d);
        EXP1 = ceil(EXP1 + d * 1.0 / 3);
    }
    else if (E2 >= 500 && E2 <= 999) {
        d = E2 * 1.0 / 9 + 10;
        EXP2 = ceil(EXP2 + d);
        EXP1 = ceil(EXP1 + d * 1.0 / 3);
        limitEXP(EXP1);
        limitEXP(EXP2);
        d = 0.35 * E2;
        EXP2 = ceil(EXP2 + d);
        EXP1 = ceil(EXP1 + d * 1.0 / 3);
        limitEXP(EXP1);
        limitEXP(EXP2);
        d = (E2 * 1.0 / 9 + 10 + 0.35 * E2) * 0.17;
        EXP2 = ceil(EXP2 + d);
        EXP1 = ceil(EXP1 + d * 1.0 / 3);
    }

    //find HP2
    HP2 = ceil(HP2 - pow(E2, 3) * 1.0 / pow(2, 23));

    //find M2
    if (!(E2 % 2)) M2 = ceil(M2 + E2 * E2 * 1.0 / 50);

    //limit 
    limitEXP(EXP1);
    limitEXP(EXP2);
    limitHP(HP2);
    limitM(M2);

    return EXP1 + EXP2 + HP2 + M2;
}

// define function 
int findk12(int* P, int n) {
    for (int i = 0; i < n; i++)
    {
        if (P[i] == 80) {
            return (i + 1);
        }
    }
    return 0;
}
int findk34(int* P, int n) {
    for (int i = n - 1; i >= 0; i--)
    {
        if (P[i] == 80) {
            return (n - i);
        }
    }
    return 0;
}
bool isSquared(int n) {
    int a = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i * i == n)
        {
            a++;
        }
    }
    if (a == 1) return true;
    else return false;
}
int sumP2(int* P2) {
    int sum = 0;
    for (int i = 0; i < 7; i++)
    {
        sum += P2[i];
    }
    return sum;
}
int findMax(int* P3) {
    int max = P3[0];
    for (int i = 0; i < 20; i++)
    {
        if (P3[i] > max)
        {
            max = P3[i];
        }
    }
    return max;
}
int findMin(int* P4) {
    int min = P4[0];
    for (int i = 0; i < 12; i++)
    {
        if (P4[i] < min)
        {
            min = P4[i];
        }
    }
    return min;
}
int findMin_idx(int* P4, int min) {
    int i = 0;
    while (P4[i] != min) {
        i++;
    }
    return i + 1;
}

// function P
void changeP1(int* P1, int E3) {
    for (int i = 0; i < 9; i++)
    {
        P1[i] = (P1[i] + E3) % 26 + 65;
    }
}
void changeP2(int* P2, int E3) {
    for (int i = 0; i < 7; i++)
    {
        P2[i] = (P2[i] + E3) % 26;
    }
}
void changeP2s(int* P2, int s, int m) {
    for (int i = 0; i < 7; i++)
    {
        P2[i] = (P2[i] + s + m) % 26 + 65;
    }
}
void inP3(int* P3, int E3) {
    int i = 0, j = 1;
    while (i < 20) {
        if (j % 2 == 0 && isSquared(j))
        {
            P3[i] = j;
            i++;
        }
        j++;
    }
    for (int i = 0; i < 20; i++)
    {
        P3[i] = (P3[i] + E3 * E3) % 113;
    }
}
void changeP3(int* P3, int E3, int max) {
    for (int i = 0; i < 20; i++)
    {
        int a = ceil((P3[i] + E3) * 1.0 / max);
        P3[i] = a % 26 + 65;
    }
}
void changeP4(int* P4, int E3) {
    for (int i = 0; i < 12; i++)
    {
        int a = ceil(E3 * 1.0 / 29);
        P4[i] = (P4[i] + a * a * a) % 9;
    }
}
void changeP4s(int* P4, int E3, int min, int min_idx) {
    for (int i = 0; i < 12; i++)
    {
        int a = ceil(min * 1.0 / min_idx);
        P4[i] = ((P4[i] + E3) * a) % 26 + 65;
    }
}

//Task 3
int traceLuggage(int& HP1, int& EXP1, int& M1, const int& E3){
    //Complete this function to gain point on task 3
    if (E3 < 0 || E3>999)
    {
        return -999;
    }
    limitEXP(EXP1);
    limitHP(HP1);
    limitM(M1);
    

    int a = 0;

    //road 1
    int P1[9] = { 1,3,5,7,9,11,13,15,17 };
    changeP1(P1, E3);
    int k = findk12(P1, 9);
    if (k != 0) {
        HP1 -= 80 * k * 2;
        EXP1 += (1000 - 80 * k) % 101;
        M1 = ceil(M1 - k * E3 * 1.0 / 9);
    }
    else {
        M1 = ceil(M1 - 9 * 9 * E3 * 1.0 / 9);
        a++;
    }
    limitEXP(EXP1);
    limitHP(HP1);
    limitM(M1);

    //road 2
    int P2[7] = { 2,3,5,7,11,13,17 };
    changeP2(P2, E3);
    int s = sumP2(P2);
    int m = ceil(s * 1.0 / 7);
    changeP2s(P2, s, m);
    k = findk12(P2, 7);
    if (k != 0) {
        HP1 -= 80 * k * 2;
        EXP1 += (1000 - 80 * k) % 101;
        M1 = ceil(M1 - k * E3 * 1.0 / 9);
    }
    else {
        M1 = ceil(M1 - 7 * 7 * E3 * 1.0 / 9);
        a++;
    }
    limitEXP(EXP1);
    limitHP(HP1);
    limitM(M1);

    //road 3
    int P3[20];
    inP3(P3, E3);
    int max = findMax(P3);
    changeP3(P3, E3, max);
    k = findk34(P3, 20);
    if (k != 0) {
        HP1 -= 80 * k * 3;
        EXP1 += (3500 - 80 * k) % 300;
        M1 = ceil(M1 - k * E3 * 1.0 / 9);
    }
    else {
        M1 = ceil(M1 - 20 * 20 * E3 * 1.0 / 9);
        a++;
    }
    limitEXP(EXP1);
    limitHP(HP1);
    limitM(M1);

    //road 4
    int P4[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    changeP4(P4, E3);
    int min = findMin(P4);
    int min_idx = findMin_idx(P4, min);
    changeP4s(P4, E3, min, min_idx);
    k = findk34(P4, 12);
    if (k != 0) {
        HP1 -= 80 * k * 4;
        EXP1 += (4500 - 80 * k) % 400;
        M1 = ceil(M1 - k * E3 * 1.0 / 9);
    }
    else {
        M1 = ceil(M1 - 12 * 12 * E3 * 1.0 / 9);
        a++;
    }
    limitEXP(EXP1);
    limitHP(HP1);
    limitM(M1);

    if (a == 4)
    {
        HP1 -= (59 * E3) % 900;
        EXP1 -= (79 * E3) % 300;
        limitEXP(EXP1);
        limitHP(HP1);
        return -1;
    }
    else return HP1 + EXP1 + M1;
}

////////////////////////////////////////////////
///END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* studyInPink_h */
