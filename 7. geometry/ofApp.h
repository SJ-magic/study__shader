/************************************************************
"GL_LINE_STRIP"などの説明
	http://openframeworks.cc/documentation/gl/ofVbo/
	
ofShader
	http://openframeworks.cc/documentation/gl/ofShader/
	
	description
		setGeometryInputType(...), setGeometryOutputType(...)
		では、指定可能なtypeに制限がある。
		http://openframeworks.cc/documentation/gl/ofShader/#show_setGeometryOutputType
		
Geometry shader input/output 指定
	http://miffysora.wikidot.com/geometry-shader
	
	description
		input
			GL_POINTS					1
			GL_LINES					2
			GL_LINES_ADJACENCY_EXT		4
			GL_TRIANGLES				3
			GL_TRIANGLES_ADJACENCY_EXT	6
			
		output
			GL_POINTS
			GL_LINE_STRIP
			GL_TRIANGLE_STRIP
			
		入力がGL_POINTSで出力がGL_TRIANGLE_STRIPなんていうのもあり。
		入力は、単に１入力プリミティブあたりに何個の頂点を送るか、だけと考えて良い。
		
Vbo.draw(int drawMode, int first, int total);
	http://openframeworks.cc/documentation/gl/ofVbo/#show_draw
	drawModeは、
		GL_POINTS
		GL_LINE_STRIP
		GL_LINE_LOOP
		GL_LINES
		GL_TRIANGLE_STRIP
		GL_TRIANGLE_FAN
		GL_TRIANGLES
		GL_QUAD_STRIP
		GL_QUADS
		GL_POLYGON 
	のみacceptableと記述があるが、shaderを使用する際は、setGeometryInputType()で指定したtype(例えば GL_LINES_ADJACENCY_EXT)を引数とする.
************************************************************/


#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
	private:
		enum{
			NUM_VERTS = 4,
		};

		ofEasyCam cam;

		ofVbo Vbo;
		ofVec3f Verts[NUM_VERTS];
		ofFloatColor Color[NUM_VERTS];

		ofShader shader;	//Shader
		
		bool b_sw;


	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
