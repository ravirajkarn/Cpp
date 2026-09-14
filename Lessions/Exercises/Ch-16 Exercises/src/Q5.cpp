/**
 * @file Q3.cpp
 * @author Sumit Kumar (ravirajkarn21@gmail.com)
 * @brief
 * @details
 * The sample class TelList was introduced in this chapter; however, some
 * methods still need to be implemented and tested.
 * ■ Implement the TelList class methods shown opposite.
 * The name is used as an unambiguous key.This means the append()
 * method can only be used to append an entry provided the name is nei-
 * ther blank nor already in use.
 * The method erase() deletes an array element.The position of the ele-
 * ment to be deleted is first located using the search() method. If the ele-
 * ment does not exist, erase() returns a value of false. In any other case,
 * the last element in the array is used to overwrite the element that is to
 * be deleted and the counter count is decremented.
 * The search() method finds the position in the array that contains the
 * search name. If the search operation is unsuccessful, the value PSEUDO is
 * returned.
 * The print method without parameters outputs all available entries.You
 * can pass the first letter or letters of a name to the second method to
 * output any entries beginning with these letters. Use the method compare()
 * from the string class to help you with this task.
 *
 * Example:     str1.compare(0, 5, str2) == 0
 *
 * This expression is true if the five characters subsequent to position 0 in
 * the strings str1 and str2 are identical.
 * The getNewEntries() method is used to read new phone list entries
 * from the keyboard. Each new entry is appended using the append()
 * method. Reading should be terminated if the user types an empty string.
 * The method returns the number of new entries.
 * Write an application program that creates a phone list of type TelList
 * and displays the menu shown on the opposite page.
 * ■ The menu must be placed in a function of your own that can return the
 * command input.The menu must be called in the main loop of the pro-
 * gram. Depending on the command input, one of the methods defined in
 * the class TelList should be called. If the menu item “Erase” or “Search”
 * is chosen, you must also read a name or the first letters of a name from
 * the keyboard.
 *
 * @version 0.1
 * @date 2025-06-15
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <telList.hpp>


