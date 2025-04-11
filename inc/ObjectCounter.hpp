#pragma once

template<class Child>
class ObjectCounter
{
    public:
    ObjectCounter()
    {
        ++c_tor_ctr;
    }

    ~ObjectCounter()
    {
        ++d_tor_ctr;
    }
    /* how many objects were craeted */
    static int c_tor_ctr;
    /* how many object were deleted */
    static int d_tor_ctr;
};