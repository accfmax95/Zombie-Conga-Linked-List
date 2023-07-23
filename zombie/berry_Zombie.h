/*
  Author: Maxwell Berry
  Date: July 6, 2021
  Description: This is the Zombie header. The purpose of this file is to initialize the functions and variables used
               within the Zombie class.
*/

#include <iostream>

using namespace std;

#ifndef berry_Zombie_h
#define berry_Zombie_h

class Zombie {

    private:
        // Member variables
        char color;

    public:
        // Constructors
        Zombie();
        Zombie(char color);

        // Destructor
        ~Zombie();

        // Overloads
        friend std::ostream& operator << (std::ostream& out, const Zombie&);
        bool operator == (const Zombie& Zombie) const;
        bool operator != (const Zombie& zombie) const;
};


#endif