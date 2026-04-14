#ifndef HEADER_HPP_
#define HEADER_HPP_

class Geeks {
private:
    int private_variable;

protected:
    int protected_variable;

public:
    Geeks() {
        private_variable = 10;
        protected_variable = 99;
    }

    // friend class declaration
    friend class GFG;
    friend class header;
};

#endif // HEADER_HPP_