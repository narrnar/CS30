//Daren Sathasivam
//CS30, 0171
//Homework #2
//Create out own smart pointer type which containts a reference count. Various other functions will also be implemented to display raw pointer's abilities.
/*
#include <iostream>
#include <stdexcept>
#include "smart_ptr.h"
using namespace std;

struct Point { int x = 2; int y = -5; };

int main()
{
    int* p { new int { 42 } };
    smart_ptr<int> sp1 { p };
     
    // Ref Count is 1
    cout << "Ref count is " << sp1.ref_count() << endl;
    {
       smart_ptr<int> sp2 { sp1 };
       // Ref Count is 2
       cout << "Ref count is " << sp1.ref_count() << endl;
       // Ref Count is 2
       cout << "Ref count is " << sp2.ref_count() << endl;
    }
     
    // Ref Count is 1
    cout << "Ref count is " << sp1.ref_count() << endl;
         
    smart_ptr<int> sp3;
     
    // Ref Count is 0
    cout << "Ref count is " << sp3.ref_count() << endl;
         
    sp3 = sp1;
     
    // Ref Count is 2
    cout << "Ref count is " << sp1.ref_count() << endl;
    // Ref Count is 2
    cout << "Ref count is " << sp3.ref_count() << endl;
     
    smart_ptr<int> sp4 = std::move(sp1);
     
    cout << *sp4 << " " << *sp3 << endl;        // prints 42 42
    

    smart_ptr<Point> sp { new Point };
    cout << sp->x << " " << sp->y << endl;   // prints 2 -5
     
    
    smart_ptr<double> dsp1 { new double {3.14} };
    smart_ptr<double> dsp2, dsp3;
         
    dsp3 = dsp2 = dsp1;
     
    cout << dsp1.ref_count() << " " << dsp2.ref_count() << " "
         << dsp3.ref_count() << endl; // prints 3 3 3
    // prints 3.14 3.14 3.14
    cout << *dsp1 << " " << *dsp2 << " " << *dsp3 << endl;
     
    dsp1.clone();        // returns true
     
    cout << dsp1.ref_count() << " " << dsp2.ref_count() << " "
         << dsp3.ref_count() << endl; // prints 1 2 2
    // prints 3.14 3.14 3.14
    cout << *dsp1 << " " << *dsp2 << " " << *dsp3 << endl;
     
    cout << *sp1 << endl;   // throws null_ptr_exception
    
    return 0;
}
*/
