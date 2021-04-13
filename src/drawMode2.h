#include "FractalMode.h"
#include <vector>
class DM2: public Fractal{
    public:
        DM2(bool, int);
        void draw(int,int,int,int);
        void randomize(int);


    private:
        int n;
        vector<int> randDegrees;
};