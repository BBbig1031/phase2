#pragma once

#include "ofMain.h"
#define Num 5

class Line{
public:
    Line();
    void setup();
    void update();
    
    void draw();
    void draw2();
    void draw3();
    void draw4();
    void draw5();
    
    void move();
    void move2();
    void move3();
    void move4();
    
    
    
    ofPoint P[4];
    ofPoint t;
    
    ofPoint t2;
    ofPoint P0;
    ofPoint P1;
    ofPoint P2;
    
    int r,g,b;
    int r2,g2,b2;
    int dim;
    
    
    
    float rX,rY,rZ;
    float rX2,rY2,rZ2;
    float rX3,rY3;
    float rX4,rY4;
    
    float fallSpeed;
    float fallWiggle;
    
};

class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    void add(ofPoint l1,ofPoint l2);
    
    Line myLine;
    Line myLine2;
    Line myCircle;
    Line myCircle2;
    Line myCircle3;
};
