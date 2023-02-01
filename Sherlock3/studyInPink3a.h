/*
* Ho Chi Minh City University of Technology
* Faculty of Computer Science and Engineering
* Initial code for Assignment 1
* Programming Fundamentals Spring 2022
* Author: Vu Van Tien
* Date: 15.02.2022
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

//=============================== POINT ===============================
class Point {
private:
    int x;
    int y;
public:
    Point(int x=0, int y=0);
    string toString() const;

    int distanceTo(const Point & otherPoint) const;
};

string numtostring(int n) {
    if (n == 0) {
        return "0";
    }
    else {
        string s;
        string str;
        int count = 0;
        if (n < 0) {
            str += '-';
            n = -n;
        }
        int i;
        while (n != 0) {
            i = n % 10;
            s += i + '0';
            n /= 10;
            count++;
        }
        for (int i = count - 1; i >= 0; i--)
        {
            str += s[i];
        }
        return str;
    }
}

Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}

string Point::toString() const {
    string a = "<Point[";
    a.insert(a.length(), numtostring(x));
    a += ',';
    a.insert(a.length(), numtostring(y));
    a.insert(a.length(), "]>");
    return a;
}

int Point::distanceTo(const Point& otherPoint) const {
    int d = ceil(sqrt(pow(otherPoint.x - x, 2) + pow(otherPoint.y - y, 2)));
    return d;
}





//=============================== NODE ===============================
class Node {
private:
    Point point;
    Node * next;

    friend class Path;

public:
    Node(const Point & point=Point(), Node * next=NULL);
    string toString() const;
};

Node::Node(const Point& point, Node* next) {
    this->point = point;
    this->next = next;
}

string Node::toString() const {
    string a = "<Node[";
    a.insert(a.length(), this->point.toString());
    a.insert(a.length(), "]>");
    return a;
}






//=============================== PATH ===============================
class Path {
private:
    Node * head;
    Node * tail;
    int count;
    int length;

public:
    Path();
    ~Path();

    void addPoint(int x, int y);
    string toString() const;
    Point getLastPoint() const;

    int getLength() const{
        return length;
    }
};

Path::Path() {
    this->head = NULL;
    this->tail = NULL;
    this->count = 0;
    this->length = -1;
}

Path::~Path() {
    Node* k;
    while (head != NULL) {
        k = head;
        head = head->next;
        delete k;
    }
}

void Path::addPoint(int x, int y) {
    Point a(x, y);
    Node* k = new Node;
    k->point = a;
    if (head == NULL) {
        head = tail = k;
    }
    else {
        tail->next = k;
        tail = k;
    }
    count++;
    if (head == tail)
    {
        length = 0;
    }
    else {
        Node* i = head;
        while (i->next != tail) {
            i = i->next;
        }
        length += tail->point.distanceTo(i->point);
    }
}

string Path::toString() const {
    string a = "<Path[count:";
    a.insert(a.length(), numtostring(count));
    a.insert(a.length(), ",length:");
    a.insert(a.length(), numtostring(length));
    a.insert(a.length(), ",[");
    for (Node* i = this->head; i != NULL; i = i->next) {
        a.insert(a.length(), i->toString());
        a += ',';
    }
    if (head != NULL) {
        a.pop_back();
    }
    a.insert(a.length(), "]]>");
    return a;
}

Point Path::getLastPoint() const {
    return tail->point;
}




//=============================== CHARACTER ===============================
class Character {
private:
    string name;
    Path * path;

public:
    Character(const string & name="");
    ~Character();

    string getName() const;
    void setName(const string & name);

    void moveToPoint(int x, int y);
    string toString() const;

    Path* getPath() const {
        return path;
    }

    Point getCurrentPosition() const {
        return path->getLastPoint();
    }
};

Character::Character(const string& name) {
    this->name = name;
    Path* p = new Path;
    this->path = p;
}

Character::~Character() {
    path->~Path();
    delete path;
};

string Character::getName() const {
    return this->name;
};

void Character::setName(const string& name) {
    this->name = name;
}

void Character::moveToPoint(int x, int y) {
    this->path->addPoint(x, y);
}

string Character::toString() const {
    string s = "<Character[name:";
    s.insert(s.length(), name);
    s.insert(s.length(), ",path:");
    s.insert(s.length(), path->toString());
    s.insert(s.length(), "]>");
    return s;
}




//==============================================================
bool rescueSherlock(
        const Character & chMurderer,
        const Character & chWatson,
        int maxLength,
        int maxDistance,
        int & outDistance
        ) {
    int l1 = chWatson.getPath()->getLength();
    int l2 = chMurderer.getPath()->getLength();

    if (l1 - l2 <= maxLength) {
        outDistance = chWatson.getCurrentPosition().distanceTo(chMurderer.getCurrentPosition());
        return (outDistance <= maxDistance ? true : false);
    }
    else {
        outDistance = -1;
        return false;
    }
}

////////////////////////////////////////////////
///END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* studyInPink_h */