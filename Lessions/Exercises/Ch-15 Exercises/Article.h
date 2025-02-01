// ----------------------------------------------------
// article.h
// Defines a simple class, Article.
// ----------------------------------------------------
#ifndef _ARTICLE_H_
#define _ARTICLE_H_

#include <string>
#include <iostream>
#include <iomanip>

// Global counter for the objects:
// int count = 0;

class Article
{
private:
    long nr;     // Article number
    std::string name; // Article name
    double sp;   // Selling price
    static int count ; // Static counter of the object.
public:
    Article(long nr = 0, const std::string &name = "noname", double sp = 0.0);
    
    /*
    * Define a copy constructor that also increments the object counter by 1
    * and issues a message. This ensures that the counter will always be accurate.     
    */
    Article(Article &s) :  nr(s.nr), name(s.name), sp(s.sp) { if(count++){ std::cout << "Counter is increased."; } }
    
    ~Article();
    void print();
    const std::string &getName() const { return name; }
    long getNr() const { return nr; }
    double getSP() const { return sp; }
    bool setName(const std::string &s)
    {
        if (s.size() < 1) // No empty name
            return false;
        name = s;
        return true;
    }
    void setNr(long n) { nr = n; }
    void setSP(double v)
    { // No negative price
        sp = v > 0.0 ? v : 0.0;
    }
    /*
    * Declare a static access method called getCount() for the Article class.
    * The method returns the current number of objects.
    */
    int getcount() const { return count; }


};

/*
* Use a static data member instead of a global variable to count the current
* number of objects.
 */
int Article::count = 0;

// ------------------------------------------------------
// Define constructor and destructor:
Article::Article(long nr, const std::string &name, double sp)
{
    setNr(nr);
    setName(name);
    setSP(sp);
    ++count;
    std::cout << "Created object for the article "<< name << ".\n This is the " << count << ". articles!\n";
}

Article::~Article()
{
    std::cout << "Cleaned up object for the article " << name << ".\n There are still " << count << " articles!\n";
}

// ------------------------------------------------------
// The method print() outputs an article.
void Article::print()
{
    std::ios_base::fmtflags savedFlags = std::cout.flags(); // To mark the flags of cout.
    std::cout << std::fixed << std::setprecision(2)
         << "-----------------------------------------\n"
         << "Article data:\n"
         << "  Number ....:  " << nr << '\n'
         << "  Name   ....:  " << name << '\n'
         << "  Sales price:  " << sp << '\n'
         << "  Count  ....:  " << count << '\n'
         << "-----------------------------------------"
         << std::endl;
    std::cout.flags(savedFlags); // To restore
    // old flags.
    std::cout << "  --- Go on with return --- ";
    std::cin.get();
}
#endif // _ARTICLE_
