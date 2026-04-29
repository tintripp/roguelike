#ifndef STATE_H
#define STATE_H

class State{
    public:
        State *next = nullptr;

        // Without this, the destructor of derived classes won't be called.
        virtual ~State(){};

        virtual void begin(){};
        virtual void end(){};

        virtual void update(){};
        virtual void draw(){};
};

#endif