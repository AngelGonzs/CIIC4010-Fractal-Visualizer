#include "FractalMode.h"
#include <vector>
class DM2: public Fractal{
    public:
        DM2(bool, int);
        void draw(float,float,float,int);
        void randomize(int);


    private:
        int n;
        vector<int> randDegrees;
};