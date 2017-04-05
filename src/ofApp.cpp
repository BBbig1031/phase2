#include "ofApp.h"

ofPoint p0, p1;		// for line drawing
ofPoint t;		// for translating
float rX, rY, rZ;	// for rotation

vector<Line>Lines;

Line::Line(){
    
}

void Line::setup(){
    int m = ofRandom(0, ofGetWidth()/2);
    int n = ofRandom(0, ofGetHeight()/2);
    P[0] = ofPoint(m+2,n-2);
    P[1] = ofPoint(-1*m,n+5);
    P[2] = ofPoint(m,n+10);
    P[3] = ofPoint(-5*m,n+10);
    
    t =ofPoint(ofGetWidth()/3,ofGetHeight()/3,0);
    fallSpeed = ofRandom(0.1,0.9);
    fallWiggle =ofRandom(6,10);
    
    r= 232;
    g =83;
    b =81;
    
    r2 = 232;
    g2 = 81;
    b2 =145;
    
    
    //Circle
    P0 = ofPoint(10,10);
    dim = 20;
    P1 = ofPoint(0,10);
    P2 = ofPoint(10,0);
}

void Line::update(){
    r2 = 232;
    g2 = 81;
    b2 = 145;
    
    float time = ofGetElapsedTimef();
    rX = ofSignedNoise(time * 0.5) * 180.0;
        rY = ofSignedNoise(time * 0.5) * 180.0;
//    rY= 0;
    //    rZ = ofSignedNoise(time * 0.2) * 180.0;
    rZ = 0;
    
    rX2 = ofSignedNoise(time * 0.2) * 360.0;
    rY2 = ofSignedNoise(time * 0.3) * 360.0;
    rZ2 = ofSignedNoise(time * 0.1) * 360.0;
    
    rX3 = ofSignedNoise(time * 0.9) * 180.0;
    rY3 = ofSignedNoise(time * 0.3) * 180.0;
    
    //    float x = ofMap(ofSignedNoise(time * 0.2), -1, 1, 0, ofGetWidth());
    //    float y = ofMap(ofSignedNoise(time * 0.3), -1, 1, 0, ofGetHeight());
    float z = ofMap(ofSignedNoise(time * 0.2), -1, 1, -800, 800);
    t = ofPoint(ofGetWidth()/2, ofGetHeight()/2, z);
    float x2 = ofMap(ofSignedNoise(time * 0.2), -1, 1, 0, ofGetWidth());
    float y2 = ofMap(ofSignedNoise(time * 0.3), -1, 1, 0, ofGetHeight());
    float z2 = ofMap(ofSignedNoise(time * 0.2), -1, 1, -800, 800);
    t2 = ofPoint(x2, y2, z2);
    fallSpeed = ofSignedNoise(time * 0.5)*ofRandom(0.1,0.5);
    fallWiggle = ofSignedNoise(time * 0.3)*ofRandom(2,10);
    
    for(int i = 0; i<4; i++) {
        if(i%4 == 0) {
            P[i].x += fallWiggle;
            P[i].y += fallSpeed * ofRandom(0,3);
            
        }else if(i%4==1){
            P[i].x += fallWiggle;
            P[i].y += fallSpeed;
            
        }else if(i%4==2){
            P[i].x += fallWiggle;
            P[i].y += fallSpeed * ofRandom(-3,0);
        }else {
            P[i].x += fallWiggle;
            P[i].y += fallSpeed;
            
        }
        
        //        if(P[i].y >ofGetHeight() || P[i].y< 0) P[i].y = 0;
        
        //        else if(P[i].x > ofGetWidth() || P[i].x < 0) P[i].x = 0;
        
    }
    
    
    
    P0.x += fallWiggle * ofRandom(-1,0);
    dim = ofMap(ofSignedNoise(time * 0.5), -1, 1, 0, 20);
    P1.x += fallWiggle * ofRandom(0,1);
    P2.x += fallWiggle * ofRandom(-1,1);
}

void Line::move(){
    
    ofTranslate(t);
    ofRotateX(rX);
    ofRotateY(rY);
    ofRotateZ(rZ);
}



void Line::move2(){
    ofTranslate(t);
    ofRotateX(rX);
    ofRotateY(rY);
    ofRotateZ(rZ);
}



void Line::move3(){
    ofTranslate(t2);
    ofRotateX(rX3);
    ofRotateY(rY3);
}



void Line::move4(){
    ofTranslate(t2);
    ofRotateX(rX3);
    ofRotateY(rY3);
}



void Line::draw(){
    ofPushMatrix();
    move();
    ofPushStyle();
    ofSetColor(r2,g2,b2);
    ofDrawLine(P[2], P[3]);
    ofPopStyle();
    ofPopMatrix();
}



void Line::draw2(){
    ofPushMatrix();
    move2();
    ofPushStyle();
    ofSetColor(r2,g2,b2);
    ofDrawLine(P[0], P[1]);
    ofPopStyle();
    ofPopMatrix();
}



void Line::draw3(){
    ofPushMatrix();
    move3();
    ofPushStyle();
    ofSetColor(232,83,81);
    ofDrawCircle(P1,dim);
    ofPopStyle();
    ofPopMatrix();
}



void Line::draw4(){
    ofPushMatrix();
    move4();
    ofPushStyle();
    ofSetColor(255,170,69);
    ofDrawCircle(P2,dim);
    ofPopStyle();
    ofPopMatrix();
}



void Line::draw5(){
    ofPushMatrix();
    move4();
    ofPushStyle();
    ofSetColor(112,102,255);
    ofDrawCircle(P0,dim);
    ofPopStyle();
    ofPopMatrix();
}


ofFbo fbo;
ofColor black(0,0,0);

void ofApp::add(ofPoint l1,ofPoint l2){
    Line newLine;
    newLine.P0 = l1;
    newLine.P1 = l2;
    Lines.push_back(newLine);
}
//--------------------------------------------------------------
void ofApp::setup(){
    p0 = ofPoint(-20, 0);
    p1 = ofPoint( 20, 0);
    t = ofPoint(ofGetWidth()/3, ofGetHeight()/3, 0);
    
    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F);
    //fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F_ARB);
    
    fbo.begin();
    ofClear(255,255,255, 0);
    fbo.end();
    
    ofSetBackgroundColor(159,86,255);
}

//--------------------------------------------------------------
void ofApp::update(){
    myLine.update();
    myLine2.update();
    myCircle.update();
    myCircle2.update();
    myCircle3.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    fbo.begin();
    ofPushStyle();
    ofSetColor(0,0,0,1);  // alpha fade it
    ofDrawRectangle(0,0,ofGetWidth(),ofGetHeight());
    ofPopStyle();
    
    myLine.draw();
    myLine2.draw2();
    myCircle.draw3();
    myCircle2.draw4();
    myCircle3.draw5();
    
    
    fbo.end();
    
    fbo.draw(0,0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
    
}
