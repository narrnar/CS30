//
//  removeBad.cpp
//  Project#2
//
//  Created by Daren Sivam on 10/27/22.
/*
//The four functions. Functions are implemented in test cases below too.
//Part a.
void removeOdds(list<int>& li)
{
    list<int>:: iterator it = li.begin();
    while(it != li.end())
    {
        if(*it %2 != 0)
        {
            it = li.erase(it);
        }
        else
        {
            it++;
        }
    }
}
//Part b.
void removeOdds(vector<int>& v)
{
     vector<int>:: iterator it = v.begin();
     while(it != v.end())
     {
         if(*it %2 != 0)
         {
             it = v.erase(it);
         }
         else
         {
             it++;
         }
     }
}
//Part c.
void removeBad(list<Movie*>& li)
{
    list<Movie*>:: iterator it = li.begin();
    while(it != li.end())
    {
        if((*it)->rating() < 50)
        {
            destroyedOnes.push_back((*it)->rating());
            it = li.erase(it);
        }
        else
        {
            it++;
        }
    }
}
//Part d.
void removeBad(vector<Movie*>& v)
{
     vector<Movie*>:: iterator it = v.begin();
     while(it != v.end())
     {
         if((*it)->rating() < 50)
         {
             destroyedOnes.push_back((*it)->rating());
             it = v.erase(it);
         }
         else
         {
             it++;
         }
     }
} */

//a.
/*
#include <list>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>
using namespace std;
  // Remove the odd integers from li.
  // It is acceptable if the order of the remaining even integers is not
  // the same as in the original list.
void removeOdds(list<int>& li)
{
    list<int>:: iterator it = li.begin();
    while(it != li.end())
    {
        if(*it %2 != 0)
        {
            it = li.erase(it);
        }
        else
        {
            it++;
        }
    }
}

void test()
{
   int a[8] = { 2, 8, 5, 6, 7, 3, 4, 1 };
   list<int> x(a, a+8);  // construct x from the array
   assert(x.size() == 8 && x.front() == 2 && x.back() == 1);
   removeOdds(x);
   assert(x.size() == 4);
   vector<int> v(x.begin(), x.end());  // construct v from x
   sort(v.begin(), v.end());
   int expect[4] = { 2, 4, 6, 8 };
   for (int k = 0; k < 4; k++)
      assert(v[k] == expect[k]);
}
int main(){
        test();
        cout << "Passed" << endl;
        return 0;
}


//b

#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>
using namespace std;
  // Remove the odd integers from v.
  // It is acceptable if the order of the remaining even integers is not
  // the same as in the original vector.
void removeOdds(vector<int>& v)
{
     vector<int>:: iterator it = v.begin();
     while(it != v.end())
     {
         if(*it %2 != 0)
         {
             it = v.erase(it);
         }
         else
         {
             it++;
         }
     }
}

void test()
{
    int a[8] = { 2, 8, 5, 6, 7, 3, 4, 1 };
    vector<int> x(a, a+8);  // construct x from the array
    assert(x.size() == 8 && x.front() == 2 && x.back() == 1);
    removeOdds(x);
    assert(x.size() == 4);
    sort(x.begin(), x.end());
    int expect[4] = { 2, 4, 6, 8 };
    for (int k = 0; k < 4; k++)
        assert(x[k] == expect[k]);
}
int main()
{
    test();
    cout << "Passed" << endl;
}


//c

 #include <list>
  #include <vector>
  #include <algorithm>
  #include <iostream>
  #include <cassert>
  using namespace std;
  
  vector<int> destroyedOnes;
  
  class Movie
  {
    public:
 Movie(int r) : m_rating(r) {}
 ~Movie() { destroyedOnes.push_back(m_rating); }
 int rating() const { return m_rating; }
private:
 int m_rating;
};

// Remove the movies in li with a rating below 50 and destroy them.
// It is acceptable if the order of the remaining movies is not
// the same as in the original list.
void removeBad(list<Movie*>& li)
{
    list<Movie*>:: iterator it = li.begin();
    while(it != li.end())
    {
        if((*it)->rating() < 50)
        {
            destroyedOnes.push_back((*it)->rating());
            it = li.erase(it);
        }
        else
        {
            it++;
        }
    }
}

void test()
{
 int a[8] = { 85, 80, 30, 70, 20, 15, 90, 10 };
 list<Movie*> x;
 for (int k = 0; k < 8; k++)
     x.push_back(new Movie(a[k]));
 assert(x.size() == 8 && x.front()->rating() == 85 &&
x.back()->rating() == 10);
 removeBad(x);
 assert(x.size() == 4 && destroyedOnes.size() == 4);
 vector<int> v;
 for (list<Movie*>::iterator p = x.begin(); p != x.end(); p++)
 {
     Movie* mp = *p;
     v.push_back(mp->rating());
 }
 sort(v.begin(), v.end());
 int expect[4] = { 70, 80, 85, 90 };
 for (int k = 0; k < 4; k++)
     assert(v[k] == expect[k]);
 sort(destroyedOnes.begin(), destroyedOnes.end());
 int expectGone[4] = { 10, 15, 20, 30 };
 for (int k = 0; k < 4; k++)
     assert(destroyedOnes[k] == expectGone[k]);
}

int main()
{
     test();
     cout << "Passed" << endl;
     return 0;
}

//d

#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>
using namespace std;

vector<int> destroyedOnes;

class Movie
{
  public:
    Movie(int r) : m_rating(r) {}
    ~Movie() { destroyedOnes.push_back(m_rating); }
    int rating() const { return m_rating; }
  private:
    int m_rating;
}; 

  // Remove the movies in v with a rating below 50 and destroy them.
  // It is acceptable if the order of the remaining movies is not
  // the same as in the original vector.
void removeBad(vector<Movie*>& v)
{
     vector<Movie*>:: iterator it = v.begin();
     while(it != v.end())
     {
         if((*it)->rating() < 50)
         {
             destroyedOnes.push_back((*it)->rating());
             it = v.erase(it);
         }
         else
         {
             it++;
         }
     }
}

void test() {
    int a[8] = { 85, 80, 30, 70, 20, 15, 90, 10 };
    vector<Movie*> x;
    for (int k = 0; k < 8; k++)
        x.push_back(new Movie(a[k]));
    assert(x.size() == 8 && x.front()->rating() == 85 &&
x.back()->rating() == 10);
    removeBad(x);
    assert(x.size() == 4 && destroyedOnes.size() == 4);
    vector<int> v;
    for (int k = 0; k < 4; k++)
        v.push_back(x[k]->rating());
    sort(v.begin(), v.end());
    int expect[4] = { 70, 80, 85, 90 };
    for (int k = 0; k < 4; k++)
        assert(v[k] == expect[k]);
    sort(destroyedOnes.begin(), destroyedOnes.end());
    int expectGone[4] = { 10, 15, 20, 30 };
    for (int k = 0; k < 4; k++)
        assert(destroyedOnes[k] == expectGone[k]);
}
int main()
{
        test();
        cout << "Passed" << endl;
        return 0;
}

void testone(int n)
{
    switch(n)
    {
        default: {
            assert(false);
        } break; case 1: { // removeOdds(<list>&)
     int a[8] = { 2, 8, 5, 6, 7, 3, 4, 1 };
     list<int> x(a, a+8);  // construct x from the array
     assert(x.size() == 8 && x.front() == 2 && x.back() ==
1);
     removeOdds(x);
     assert(x.size() == 4);
     vector<int> v(x.begin(), x.end());  // construct v from x
     sort(v.begin(), v.end());
     int expect[4] = { 2, 4, 6, 8 };
     for (int k = 0; k < 4; k++)
         assert(v[k] == expect[k]);
 } break; case 2: { // removeOdds(<vector>&)
     int a[8] = { 2, 8, 5, 6, 7, 3, 4, 1 };
     vector<int> x(a, a+8);  // construct x from the array
     assert(x.size() == 8 && x.front() == 2 && x.back() ==
1);
     removeOdds(x);
     assert(x.size() == 4);
     sort(x.begin(), x.end());
     int expect[4] = { 2, 4, 6, 8 };
     for (int k = 0; k < 4; k++)
         assert(x[k] == expect[k]);
 } break; case 3: { // removeBad(<list>&)
     int a[8] = { 85, 80, 30, 70, 20, 15, 90, 10 };
     list<Movie*> x;
     for (int k = 0; k < 8; k++)
         x.push_back(new Movie(a[k]));
     assert(x.size() == 8 && x.front()->rating() == 85 &&
x.back()->rating() == 10);
     removeBad(x);
     assert(x.size() == 4 && destroyedOnes.size() == 4);
     vector<int> v;
     for (list<Movie*>::iterator p = x.begin(); p !=
x.end(); p++)
     {
         Movie* mp = *p;
         v.push_back(mp->rating());
     }
     sort(v.begin(), v.end());
     int expect[4] = { 70, 80, 85, 90 };
     for (int k = 0; k < 4; k++)
         assert(v[k] == expect[k]);
     sort(destroyedOnes.begin(), destroyedOnes.end());
     int expectGone[4] = { 10, 15, 20, 30 };
     for (int k = 0; k < 4; k++)
         assert(destroyedOnes[k] == expectGone[k]);
 } break; case 4: { // removeBad(<vector>&)
     int a[8] = { 85, 80, 30, 70, 20, 15, 90, 10 };
     vector<Movie*> x;
     for (int k = 0; k < 8; k++)
         x.push_back(new Movie(a[k]));
     assert(x.size() == 8 && x.front()->rating() == 85 &&
x.back()->rating() == 10);
     removeBad(x);
     assert(x.size() == 4 && destroyedOnes.size() == 4);
     vector<int> v;
     for (int k = 0; k < 4; k++)
         v.push_back(x[k]->rating());
     sort(v.begin(), v.end());
     int expect[4] = { 70, 80, 85, 90 };
     for (int k = 0; k < 4; k++)
         assert(v[k] == expect[k]);
     sort(destroyedOnes.begin(), destroyedOnes.end());
     int expectGone[4] = { 10, 15, 20, 30 };
     for (int k = 0; k < 4; k++)
         assert(destroyedOnes[k] == expectGone[k]);
 }
    }
}
 
int main()
{
    cout << "Enter test number: ";
    int n;
    cin >> n;
    testone(n);
    cout << "Passed" << endl;
} */
