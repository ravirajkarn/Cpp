// ----------------------------------------------------
// article.h
// Defines a simple class, Article.
// ----------------------------------------------------
#ifndef _ARTICLE_H_
#define _ARTICLE_H_

#include <string>
#include <fmt/core.h>
#include <fmt/color.h>

using namespace std;

// Global counter for the objects:
int count = 0;

class Article
{
private:
    long nr;     // Article number
    string name; // Article name
    double sp;   // Selling price
public:
    Article(long nr = 0, const string &name = "noname",
            double sp = 0.0);
    ~Article();
    void print();
    const string &getName() const { return name; }
    long getNr() const { return nr; }
    double getSP() const { return sp; }
    bool setName(const string &s)
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
};

// ------------------------------------------------------
// Define constructor and destructor:
Article::Article(long nr, const string &name, double sp)
{
    setNr(nr);
    setName(name);
    setSP(sp);
    ++count;
    fmt::print("Created object for the article {0}.\n This is the {1}. articles!\n", name, count);
}

Article::~Article()
{
    fmt::print("Cleaned up object for the article {0}.\n There are still {1} articles!\n", name, --count);
}

// ------------------------------------------------------
// The method print() outputs an article.
void Article::print()
{
    std::ios_base::fmtflags savedFlags = cout.flags(); // To mark the
    // flags of cout.
    cout << fixed << setprecision(2)
         << "-----------------------------------------\n"
         << "Article data:\n"
         << "  Number ....:  " << nr << '\n'
         << "  Name   ....:  " << name << '\n'
         << "  Sales price:  " << sp << '\n'
         << "-----------------------------------------"
         << endl;
    cout.flags(savedFlags); // To restore
    // old flags.
    cout << "  --- Go on with return --- ";
    cin.get();
}
#endif // _ARTICLE_
