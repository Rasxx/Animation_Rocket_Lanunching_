#include<Windows.h>
#include <glut.h>

GLfloat i = 0; // To allow the fire start.
GLfloat MoveLaunch = 0;// Counter used to animate the Launching Base.
GLfloat MoveFire = 1; // used to move the fire in the Rocket.
GLfloat on = 0;// to strat and colse the Animation .
int OnHelper = 1; // to help indicate if spacebar clicked to open or close the Animation.

// method that is used to draw a Rocket.
void drawRocket() {

	glPushMatrix();
	glScaled(0.25, 0.25, 1); // to reduce the whole rocket

	// -- Draw the circles 
	// 1 ) big circle ( body of the rocket )
	glPushMatrix();
	// Set a matrial for the Rocket
	GLfloat amb[] = { 0.05f,0.05f,0.05f,1.0f };
	GLfloat diff[] = { 0.5f,0.5f,0.5f,1.0f };
	GLfloat spec[] = { 0.7f,0.7f,0.7f,1.0f };
	GLfloat shine = 10.0f;
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, amb);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, spec);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shine);

	glScaled(0.5, 1.2, 1);
	glRotated(90, 0, 1, 0);
	glutSolidSphere(50, 30, 30);
	glPopMatrix();

	glPushMatrix();

	GLfloat amb2[] = { 0.1f, 0.18725f, 0.1745f, 0.8f };
	GLfloat diff2[] = { 0.396f, 0.74151f, 0.69102f, 0.8f };
	GLfloat spec2[] = { 0.297254f, 0.30829f, 0.306678f, 0.8f };
	GLfloat shine2 = 12.8f;
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, amb2);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff2);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, spec2);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shine2);

	// 2) 4 small circles ( like a windoe in the rocket )
	glPushMatrix();
	glTranslated(0, 15, 60);
	glutSolidSphere(3, 30, 30);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-10, 1, 60);
	glutSolidSphere(1.5, 30, 30);
	glPopMatrix();

	glPushMatrix();
	glTranslated(10, 1, 60);
	glutSolidSphere(1.5, 30, 30);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 1, 60);
	glutSolidSphere(1.5, 30, 30);
	glPopMatrix();


	// Draw the head of the rocket
	glPushMatrix();
	glTranslated(0, 40, 30);
	glRotated(-90, 1, 0, 0);
	glutSolidCone(13.5, 20, 15, 15);
	glPopMatrix();

	// draw the fire whole
	glPushMatrix();
	glTranslated(0, -50, 35);
	glRotated(-90, 1, 0, 0);
	glutSolidCone(13.5, 15, 15, 15);
	glPopMatrix();


	// Drawing 3 wings
	glPushMatrix();
	glTranslated(0, -22, 60);
	glScaled(0.5, 6, 1);
	glutSolidCube(3.5);
	glPopMatrix();


	glPushMatrix();
	glTranslated(-15, -25, 30);
	glRotated(32, 0, 0, 1);
	glRotated(-90, 0, 1, 0);
	glutSolidCone(8, 40, 15, 15);
	glPopMatrix();

	glPushMatrix();
	glTranslated(15, -25, 30);
	glRotated(-32, 0, 0, 1);
	glRotated(90, 0, 1, 0);
	glutSolidCone(8, 40, 15, 15);
	glPopMatrix();

	glPopMatrix();

	glPopMatrix();
}

// method that is used to draw a launching base for the rocket.
void drawLauncingBase() {

	glPushMatrix();
	// if statement to check if the user want to Animate the drawing or not. 
	if (on == 1) //Animate the launching base.
	{
		glTranslated(0, -MoveLaunch, 0);// start the Animatation.
	}
	else // set MoveLaunch to 0 to be ready to animate the launching base again. hint: the user stops the animate now! .
	{
		MoveLaunch = 0;
	}

	glPushMatrix();
	glScaled(0.8, 0.8, 1); // scale the whole launching base.

	glPushMatrix();

	// set a meterial
	float amb4[] = { 0.19125f, 0.0735f, 0.0225f, 1.0f };
	float diff4[] = { 0.7038f, 0.27048f, 0.0828f, 1.0f };
	float spec4[] = { 0.256777f, 0.137622f, 0.086014f, 1.0f };
	float shine4 = 12.8f;

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, amb4);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff4);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, spec4);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shine4);

	// draw the lower body of the launching base by using a cone.
	glTranslated(0, -15, 30);
	glRotatef(90, 1, 0, 0);
	glutSolidCone(29, 29, 5, 6);
	glPopMatrix();

	glPushMatrix();
	// set anthor material
	GLfloat amb3[] = { 0.25f, 0.20725f, 0.20725f, 0.922f };
	GLfloat diff3[] = { 1.0f, 0.829f, 0.829f, 0.922f };
	GLfloat spec3[] = { 0.296648f, 0.296648f, 0.296648f, 0.922f };
	GLfloat shine3 = 11.264f;
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, amb3);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff3);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, spec3);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shine3);

	// draw the upper body of the launching base by using a cube.

	glTranslated(0, -15, 30);
	glScaled(1, 0.045, 1.40);
	glRotatef(-90, 1, 0, 0);
	glutSolidCube(55);
	glPopMatrix();


	glPopMatrix();

	// update MoveLaunch by 0.1 , for the animation.
	MoveLaunch += 0.1;
	glPopMatrix();


}

// method that is used to draw a stars in the background
void stars() {
	glPushMatrix();

	glColor3f(1, 1, 1);
	glPointSize(3);
	glBegin(GL_POINTS);

	// for loop used to draw the points(stars) 
	for (int i = 0; i < 40; i++) // num of points = 40

	{
		// use rand() to set the location of the points
		glVertex2f((rand() % 100), (rand() % 100));
		glVertex2f(-(rand() % 100), (rand() % 100));
		glVertex2f(-(rand() % 100), -(rand() % 100));
		glVertex2f((rand() % 100), -(rand() % 100));
	}


	glEnd();

	glPopMatrix();

}

// method that is used to draw the fire of the rocket
void fire() {

	glPushMatrix();

	// Animation of the fire 
	glScaled(MoveFire, MoveFire, 1);
	glColor3f(0.99, 0.6666, 0.297);

	// draw the fire by uing Dodecahedron.
	glPushMatrix();
	glTranslated(0, -10.8, 60);
	glScaled(0.67, 0.67, 0.67);
	glutSolidDodecahedron();
	glPopMatrix();

	glPushMatrix();
	glTranslated(1.8, -10, 60);
	glScaled(0.67, 0.67, 0.67);
	glutSolidDodecahedron();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-1.8, -10, 60);
	glScaled(0.67, 0.67, 0.67);
	glutSolidDodecahedron();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, -12, 60);
	glScaled(0.67, 0.67, 0.67);
	glutSolidDodecahedron();
	glPopMatrix();

	glPushMatrix();
	glTranslated(2, -11.5, 60);
	glScaled(0.67, 0.67, 0.67);
	glutSolidDodecahedron();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-2, -11.5, 60);
	glScaled(0.67, 0.67, 0.67);
	glutSolidDodecahedron();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-1, -12.5, 60);
	glScaled(0.67, 0.67, 0.67);
	glutSolidDodecahedron();
	glPopMatrix();

	glPushMatrix();
	glTranslated(1, -12.5, 60);
	glScaled(0.67, 0.67, 0.67);
	glutSolidDodecahedron();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, -13, 60);
	glScaled(0.67, 0.67, 0.67);
	glutSolidDodecahedron();
	glPopMatrix();

	// if statement that is used to control the range of the fire.
	if (MoveFire > 2)
		MoveFire = 1;

	// update MoveFire to let the fire become bigger.
	MoveFire += 0.005;

	glPopMatrix();

}

// The draw method is responsible to draw and Animate the whole Scene.
void draw() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity(); // replaces the current matrix with the identity matrix.
	gluLookAt(0, 0, 150, 0, 0, 0, 0, 1, 0);
	glEnable(GL_LIGHTING);//Enable the lightening
	// Enable 3 light source
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT2);


	glPushMatrix();
	// enable the color material so we can use the original color of the objects.
	glEnable(GL_COLOR_MATERIAL);

	glPushMatrix();
	// set a position for the light ( to give more realistic feel of the fire)
	GLfloat pos[] = { 0,-50,35,0 };
	glLightfv(GL_LIGHT1, GL_POSITION, pos);

	if (on == 1) {
		fire();
	}
	glPopMatrix();


	glPushMatrix();
	// set the AMBIENT and SPECULAR of the stars to be white.
	GLfloat amb[] = { 1, 1,1,1 };
	GLfloat spec[] = { 1,1,1,1 };
	glLightfv(GL_LIGHT2, GL_AMBIENT, amb);
	glLightfv(GL_LIGHT2, GL_SPECULAR, spec);
	if (on == 1) {
		stars();
	}

	glPopMatrix();


	glPushMatrix();
	// Disable the color material so we can use anthor materials.
	glDisable(GL_COLOR_MATERIAL);


	glPushMatrix();
	drawRocket();
	glPopMatrix();

	glPushMatrix();
	drawLauncingBase();
	glPopMatrix();

	glPopMatrix();

	glutSwapBuffers();
}

// method that is responsible to the interaction with the user by using the key.
void keyboard(unsigned char key, int x, int y) {
	// if the user click on the 'esc' key then exit from the scene.
	if (key == 27) 
		exit(0);

	// if the user click on the 'spacebar' key AND OnHelper was odd number then start the animation.
	if (key == 32 && (OnHelper % 2) == 1) {
		on = 1;
		OnHelper += 1;
	}
	// else if the user click on the 'spacebar' key  again AND OnHelper was even number then stop the animation.
	else if (key == 32 && (OnHelper % 2) == 0) { 
		on = 0;
		OnHelper += 1;
	}


}

int main() {

	glutInitWindowSize(600, 600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH); // double buffer for animination
	glutCreateWindow("Rocket Launching ..");

	//Enable the depth test
	glEnable(GL_DEPTH_TEST);

	// change matrix mode to GL_PROJECTION , to set how the projection will be done
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// choose the projection type : ( ortho , perspective )
	gluPerspective(45, 1, 80, -100);

	//change matrix mode to GL_MODELVIEW , to use it to rotate, translate & scale
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	// Tell GLUT to use the method "keyboard" for key presses  
	glutKeyboardFunc(keyboard);
	// set the background to black
	glClearColor(0, 0, 0, 0);

	glutDisplayFunc(draw);
	glutIdleFunc(draw);
	glutMainLoop();
}



