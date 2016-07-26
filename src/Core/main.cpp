#include "ofApp.h"
#include "ofAppGlutWindow.h"

int main( )
{
    ofAppGlutWindow window;
    ofSetupOpenGL(&window, Const::WIDTH, Const::HEIGHT, OF_WINDOW);
    ofSetWindowPosition(Const::FIRST_SCREEN_WINDOW_WIDTH, 0);
    
#if DEBUG_MODE == 1 || DEBUG_MODE == 2
    ofSetFullscreen(true);
#endif
    
    ofRunApp(new ofApp());
}
