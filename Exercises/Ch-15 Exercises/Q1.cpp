/**
 * @brief Exercise 1
 * In the first exercise of the last chapter you defined a simple class called
 * Article. This involved using a global counter to log object creation and
 * destruction. Improve and extend the Article class as follows:
 * ■ Use a static data member instead of a global variable to count the current
 * number of objects.
 * ■ Declare a static access method called getCount() for the Article class.
 * The method returns the current number of objects.
 * ■ Define a copy constructor that also increments the object counter by 1
 * and issues a message. This ensures that the counter will always be accurate.
 * Tip: Use member initializers.
 * ■ Test the new version of the class. To do so, call the function test() by
 * passing an article type object to the function. 
 * 
 */
