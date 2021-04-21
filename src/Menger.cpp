#include "Menger.h"

Menger::Menger(float x, float y, float z, float size){
    this->x = x;
    this->y = y;
    this->z = z;
    position.set(x,y,z);

    this->size = size;
}

void Menger::draw(){
    ofPushMatrix();
    ofTranslate(position.x, position.y, position.z);
    ofDrawBox(position.x, position.y, position.z, size);
    ofPopMatrix();
    //pop and push are used to not mess up the ofTranslate
    //since that will be constantly changing
    //it just returns it to its original state when pop is called
}

vector<Menger> Menger::creator(){
    /*so each cube in a menger sponge can be divided into 
    another 3^3 (27) cubes or 3 sections of 9 cubes.

    Out of these, the cubes located at (0,0,0) [considering the intervals -1 to 1] 
    will be removed always... and for the middle secting, cubes in a formation
    of a plus(+) sign will be removed. So in a sense it will be like 2 plus
    signs crossed each other and created that thingy that you used to have 
    when playing jacks (apparently they're called knucklebones)

    anyways that was a really bad explanation, just look up online
    what im doing, this thing is called a menger sponge and it is 
    very cool
    */

   //storing all the cubes
    vector<Menger> cubes;
    for(int i = -1; i < 2; i++){
    for(int j = -1; j < 2; j++){
    for(int k = -1; k < 2; k++){

        int sum = abs(i) + abs(j) + abs(k);
        float tempSize = size/3; //new cube has to be 3 times smaller ofc
        if(sum > 1){
                Menger temp(position.x+i*(tempSize/2), position.y+j*(tempSize/2), position.z+k*(tempSize/2), tempSize);
                //altering the postions by moving them by the size/6
                cubes.push_back(temp);
                }
            }
        }
    }
    return cubes;
}