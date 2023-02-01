/*
* Ho Chi Minh City University of Technology
* Faculty of Computer Science and Engineering
* Initial code for Assignment 1
* Programming Fundamentals Spring 2022
* Author: Vu Van Tien
* Date: 10.02.2022
*/

//The library here is concretely set, students are not allowed to include any other libraries.
#ifndef studyInPink_h
#define studyInPink_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

////////////////////////////////////////////////////////////////////////
///STUDENT'S ANSWER BEGINS HERE
///Complete the following functions
///DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////



// FUNCTION OF NOTEBOOK 1

int strtonum(string str) {
    int num = 0;
    for (int i = 0; i < str.length(); i++)
    {
        int temp = str[i] - '0';
        if (temp < 0 || temp>9)
        {
            return 0;
            break;
        }
        num += temp;
        num *= 10;
    }
    num /= 10;
    return num;
}

void in(int* arr, int n, string d2) {
    for (int i = 0, j = 0; i < n; i++, j += 2)
    {
        arr[i] = d2[j] - '0';
    }
}

int times(int* arr, int n, int num) {
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == num) {
            count++;
        }
    }
    if (count >= 10)
    {
        return count % 10;
    }
    return count;
}

string value1_1(int* arr, int n) {
    string a;
    for (int i = 0; i <= 9; i++)
    {
        a.push_back(times(arr, n, i) + '0');
    }
    return a;
}
string notebook1(string ntb1) {
    // Complete this function to gain point
    ifstream in1(ntb1);
    string d1, d2;

    in1 >> d1;
    in1.ignore();
    getline(in1, d2);

    d1 = d1.substr(11, 3);
    int n1 = strtonum(d1);
    if (n1 < 1||d1.length()!=3) {
        return "0000000000";
    }

    int *arr = new int[n1];
    in(arr, n1, d2);

    string nb1 = value1_1(arr, n1);

    delete[]arr;

    return nb1;
}




// FUNCTION OF NOTEBOOK 2

int times2(string a) {
    int count = 0;
    string str = "ink";
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] == 'P' || a[i] == 'p')
        {
            int n = 0;
            i++;
            for (int j = 0; j < 3; j++, i++)
            {
                if (a[i] != str[j])
                {
                    n++;
                    break;
                }
            }
            if (!n) count++;
            i--;
        }
    }
    return count;
}

string value1_2(int a) {
    if (a == 0) {
        return "0999999999";
    }
    string str;
    int arr[10];
    int n = 0;
    while (a != 0)
    {
        arr[n] = a % 10;
        a /= 10;
        n++;
    }
    for (int i = 0; i < n / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
    for (int i = 0; i < 10; i++)
    {
        if (i < n)
        {
            str += arr[i] + '0';
        }
        else {
            str += '9';
        }
    }
    return str;
}

string notebook2(string ntb2) {
    // Complete this function to gain point
    ifstream in2(ntb2);
    string d1;
    in2 >> d1;
    if (d1.length()!=5)
    {
        return "1111111111";
    }

    int n2 = strtonum(d1);
    if (n2 < 5 || n2>100)
    {
        return "1111111111";
    }

    int cntP = 0;
    for (int i = 0; i < n2; i++)
    {
        string a;
        in2.ignore();
        getline(in2, a);
        cntP += times2(a);
    }
    if (cntP < 10000)
    {
        cntP *= cntP;
    }

    return value1_2(cntP);
}





// FUNCTION OF NOTEBOOK 3

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

bool isFibonacci(int n) {
    int x1 = 1, x2 = 1, x3 = 0, x4 = 0;
    while (x4 < n) {
        x3 = x1 + x2;
        x4 = x2 + x3;
        if (n == x4 || n == x3 || n == x2 || n == x1)
        {
            return 1;
            break;
        }
        x1 = x3;
        x2 = x4;
    }
    return 0;
}

int prime(int& n) {
    while (!isPrime(n)) {
        n++;
    }
    return n;
}

int fibonacci(int& n) {
    while (!isFibonacci(n)) {
        n++;
    }
    return n;
}

void arrange(int& a, int& b, int& c) {
    int temp;
    if (a > b)
    {
        temp = a;
        a = b;
        b = temp;
    }
    if (a > c) {
        temp = a;
        a = c;
        c = temp;
    }
    if (b > c) {
        temp = b;
        b = c;
        c = temp;
    }
}

void changearr(int arr[][10]) {
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (arr[i][j] < 0)
            {
                arr[i][j] = -arr[i][j];
            }
        }
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (j > i) {
                arr[i][j] = prime(arr[i][j]);
            }
            else if (j < i) {
                arr[i][j] = fibonacci(arr[i][j]);
            }
        }
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (j == 7)
            {
                arrange(arr[i][j], arr[i][j + 1], arr[i][j + 2]);
            }
        }
    }
}

int findImax(int* arr) {
    int max = arr[0];
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    for (int i = 9; i >= 0; i--)
    {
        if (arr[i] == max) {
            return i;
            break;
        }
    }
}

string value1_3(int arr[][10]) {
    string value;
    int iMax;
    for (int i = 0; i < 10; i++)
    {
        iMax = findImax(arr[i]);
        value += iMax + '0';
    }
    return value;
}

string notebook3(string ntb3) {
    // Complete this function to gain point
    ifstream in3(ntb3);
    int arr[10][10];

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            in3 >> arr[i][j];
            if (j != 9) {
                char x;
                in3 >> x;
            }
        }
    }

    changearr(arr);

    return value1_3(arr);
}





// FUNCTION OF PASSWORD

string g(string p1, string p2) {
    string str;
    int n;
    int k = 0;
    for (int i = 0; i < 10; i++)
    {
        n = p1[i] - '0' + p2[i] - '0' + k;
        if (n > 9) {
            k = n / 10;
            n %= 10;
        }
        else {
            k = 0;
        }
        str += n + '0';
    }
    return str;
}

string generateListPasswords(string pwd1, string pwd2, string pwd3) {
    // Complete this function to gain point
    string str;
    string g12 = g(pwd1, pwd2);
    string g13 = g(pwd1, pwd3);
    string g23 = g(pwd2, pwd3);
    str += pwd1 + ';' + pwd2 + ';' + pwd3 + ';' + g12 + ';' + g13 + ';' + g23 + ';' + g(g12, pwd3) + ';' + g(pwd1, g23) + ';' + g(g12, g13);
    return str;
}





// FUNCTION OF TAXI

struct point {
    int x;
    int y;
    int time;
};

void timetaxi(int arr[100][100], string moves) {
    int x = 0, y = 0;
    arr[0][0] = 0;
    for (int i = 0; i < moves.length(); i++)
    {
        if (moves[i] == 'U')
        {
            if (x != 0)
            {
                x -= 1;
                arr[x][y] = arr[x + 1][y] + 9;
            }
        }
        else if (moves[i] == 'D')
        {
            if (x != 99)
            {
                x += 1;
                arr[x][y] = arr[x - 1][y] + 9;
            }
        }
        else if (moves[i] == 'L')
        {
            if (y != 0)
            {
                y -= 1;
                arr[x][y] = arr[x][y + 1] + 9;
            }
        }
        else {
            if (y != 99)
            {
                y += 1;
                arr[x][y] = arr[x][y - 1] + 9;
            }
        }
    }
}

void inPoint(string points, point* sw, int& n) {
    for (int i = 1, j = 0; i < points.length(); j++)
    {
        string x, y;
        while (points[i] != ',') {
            x += points[i];
            i++;
        }
        i++;
        sw[j].x = strtonum(x);
        while (points[i] != ')') {
            y += points[i];
            i++;
        }
        sw[j].y = strtonum(y);
        n++;
        i += 3;
    }
}

int time2point(point a, point b) {
    int d = abs(a.x - b.x) + abs(a.y - b.y);
    return 14 * d;
}

void timepoint(point* sw, int n) {
    point O;
    O.x = 0;
    O.y = 0;
    sw[0].time = time2point(sw[0], O);
    for (int i = 1; i < n; i++)
    {
        sw[i].time = sw[i - 1].time + time2point(sw[i - 1], sw[i]);
    }
}

void numtostr(string& out, int num) {
    int i;
    char temp;
    string a;
    while (num != 0) {
        i = num % 10;
        a += i + '0';
        num /= 10;
    }
    for (int i = 0; i < a.length() / 2; i++)
    {
        temp = a[a.length() - i - 1];
        a[a.length() - i - 1] = a[i];
        a[i] = temp;
    }
    for (int i = 0; i < a.length(); i++)
    {
        out += a[i];
    }
}

bool value2(point* sw, int n, int arr[100][100], string& outTimes, string& outCatchUps) {
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (sw[i].time <= arr[sw[i].x][sw[i].y] || count > 0)
        {
            if (count == 0)
            {
                outCatchUps += 'Y';
                numtostr(outTimes, sw[i].time);
            }
            else {
                outCatchUps += '-';
                outTimes += '-';
            }
            count++;
        }
        else {
            numtostr(outTimes, sw[i].time);
            outCatchUps += 'N';
        }
        outTimes += ';';
        outCatchUps += ';';
    }
    outTimes.erase(outTimes.begin() + outTimes.length() - 1);
    outCatchUps.erase(outCatchUps.begin() + outCatchUps.length() - 1);
    return (count > 0 ? 1 : 0);
}

bool chaseTaxi(
    int arr[100][100],
    string points,
    string moves,
    string & outTimes,
    string & outCatchUps
) {
    // Complete this function to gain point
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            arr[i][j] = -9;
        }
    }
    timetaxi(arr, moves);
    point sw[100];
    int n = 0;
    inPoint(points, sw, n);
    timepoint(sw, n);
    return value2(sw, n, arr, outTimes, outCatchUps);
    return false;
}






string enterLaptop(string tag, string message) {
    // Complete this function to gain point
    ifstream tagIn(tag);
    string r1, r2;
    getline(tagIn, r1);
    getline(tagIn, r2);
    string email, address;
    for (int i = 7; i < r1.length(); i++)
    {
        email += r1[i];
    }
    for (int i = 9; r2[i] != ' '; i++)
    {
        address += r2[i];
    }
    int n3 = strtonum(address);
    string pwdL;
    for (int i = 0; i < n3; i++)
    {
        pwdL = pwdL.insert(pwdL.length(), message);
    }
    email += ';';
    email = email.insert(email.length(), pwdL);
    return email;
}
////////////////////////////////////////////////
///END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* studyInPink_h */
