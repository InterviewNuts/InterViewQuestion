#include<iostream>
#include <memory>
using namespace std;

class Demo
{
public:
    Demo()
    {
        cout << " Demo cotr called\n";
    }
    ~Demo()
    {
        cout << " Demo DOTR  called\n";
    }
    int x = 90;
};

void show(shared_ptr<Demo> d)
{
    cout << "User count in show () =" << d.use_count() << "\n";;
}

int main()
{
    Demo* dp = new Demo();
    shared_ptr<Demo> ds = shared_ptr<Demo>(dp);
    cout << "User cound =" << ds.use_count() << "\n";
    // show(ds);
    {
        // shared_ptr<Demo> ds1 = shared_ptr<Demo>(dp);
        // cout << "User count Inside block  =" << ds1.use_count() << "\n";
    }

    //! this will be crashed as new shared pointer is created directly from raw poniter 
    //! so once the reference count = 0, dotr called for DEMO and again 
    //! it DOTR will called once againe here. as the control block points to raw pointer here and 
    //! reference count still 1 after the {} block, hence crashed. 
    //! So the rule is , not to create shared pointer directly from RAW pointer , but from another shared_pointer.
    cout << "User count after block----- =" << ds.use_count() << "\n";
    //! reset , make reference count to 0
    ds.reset();
    cout << "User count after Reset ----- =" << ds.use_count() << "\n";


    return 0;
}