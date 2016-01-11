/**
 * \brief An Array is an Object which stores multiple values in a single variable.
 *
 * An Array is an Object which stores multiple values in a single variable in a list-like object. It has several methods
 * to manipulate and otherwise interact with the values inside. The length of an Array can grow or shrink during its
 * lifetime.
 *
 * ### Create an Array
 *
 * \include arrays/create_array.muse
 *
 * ### Access (index into) an Array item
 *
 * \include arrays/array_access.muse
 *
 * ### Create 2 dimensional arrays
 *
 * \include arrays/create_2d_array.muse
 */
class Array : public Object {
public:
    Number length; //!< length of the array

    /**
     * \brief Pushes a new value at the end of the array
     *
     * \param value value to push at the end of the array
     */
    void push(Object value);

    /**
     * \brief Removes the last element from the array and returns it
     *
     * \returns the last element from the array
     */
    void pop();
};