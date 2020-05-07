#include <iostream>
#include <iomanip>

#ifndef TORMENTA_STATE_HPP
#define TORMENTA_STATE_HPP

class State
{
private:
    bool m_quit;
    
public:
    State();
    virtual ~State();

    bool get_quit() const;

    void set_quit(bool t_quit);

    static int getIntChoice();

    virtual void update() = 0;
};

#endif