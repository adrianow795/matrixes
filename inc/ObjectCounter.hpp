#pragma once

/**
 * @class ObjectCounter
 * @brief A template class to count the number of objects created and destroyed.
 * 
 * This class provides static counters to track the number of constructor
 * and destructor calls for a specific type.
 * 
 * @tparam Child The class type for which the objects are being counted.
 */
template<class Child>
class ObjectCounter
{
    public:
    /**
     * @brief Constructor.
     * 
     * Increments the counter for objects created.
     */
    ObjectCounter()
    {
        ++c_tor_ctr;
    }

    /**
     * @brief Destructor.
     * 
     * Increments the counter for objects destroyed.
     */
    ~ObjectCounter()
    {
        ++d_tor_ctr;
    }

    static int c_tor_ctr; ///< Counter for the number of objects created.
    static int d_tor_ctr; ///< Counter for the number of objects destroyed.
};