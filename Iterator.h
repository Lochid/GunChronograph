#ifndef Iterator_h
#define Iterator_h

class Iterator
{
private:
    unsigned int _iteration;
    unsigned int _maximalIteration;
    double _progress;
    bool _complete;

    void setProgress();
    void setComplete();

public:
    Iterator(unsigned int maximalIteration);
    unsigned int getIteration();
    double getProgress();
    bool getCompleteStatus();
    void next();
    void reset();
};

#endif //Iterator.h
