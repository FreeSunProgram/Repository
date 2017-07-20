#include <iostream>
#include "smart_ptr.h"

using namespace std;

class TC
{
public:

    int a;

    int b;
};

void test(smart_ptr<int> si)
{

}

int main()
{
    smart_ptr<int> ss(new int(1));

    smart_ptr<int> ssa(new int(1));

    smart_ptr<TC> ptca(new TC());

    return 0;
}
