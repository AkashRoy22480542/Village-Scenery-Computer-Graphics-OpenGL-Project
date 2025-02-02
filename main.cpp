//"Village Scenery"
//AMAERICAN INTERNATIONAL UNIVERSITY BANGLADESH
//AKASH ROY 22-48054-2
//MARUP HOSSAIN
//YEAR 2024-2025





#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <cmath>
#define PI 3.14159265358979323846



//  variables
GLfloat fanRotationAngle = 0.0f;
GLfloat sunPosition = 0.0f;
GLfloat cloudPosition = 0.0f;
GLfloat boatPosition1 = 0.0f;
GLfloat boatPosition2 = 0.0f;
GLfloat planePosition = 0.0f;


GLfloat sunSpeed = 2.0f;
GLfloat cloudSpeed = 2.0f;
GLfloat boatSpeed1 = 3.5f;
//boatSpeed 2 (left to right)
GLfloat boatSpeed2 = 3.5f;
GLfloat planeSpeed = 5.0f;
GLfloat fanRotationSpeed = 5.0f;

void Movement(int value) {
    // Sun
    sunPosition += sunSpeed;
    if (sunPosition > 750.0f) {
        sunPosition = -400.0f;
    }

    // Cloud
    cloudPosition += cloudSpeed;
    if (cloudPosition > 1000.0f) {
        cloudPosition = -1000.0f;
    }

    // Boat 1 (right to left)
    boatPosition1 -= boatSpeed1;
    if (boatPosition1 < -1000.0f) {
        boatPosition1 = 1000.0f;
    }

    // Boat 2 (left to right)
    boatPosition2 += boatSpeed2;
    if (boatPosition2 > 1000.0f) {
        boatPosition2 = -1000.0f;
    }

    // Plane (right to left)
    planePosition -= planeSpeed;
    if (planePosition < -1000.0f) {
        planePosition = 1000.0f;
    }


    // Fan rotation
    fanRotationAngle += fanRotationSpeed;
    if (fanRotationAngle >= 360.0f) {
        fanRotationAngle = 0.0f;
    }

    glutTimerFunc(100, Movement, 0); //every 100ms call movement function to update animation
    glutPostRedisplay(); //Triggers a redraw of the screen after movement updates.

}


void SpecialInput(int key, int x, int y)
{
switch(key)  //A switch statement is used to check which key was pressed.
{
case GLUT_KEY_UP:
    planeSpeed=105;
break;
case GLUT_KEY_DOWN:
    planeSpeed=5;
break;
}
}


void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-400,600,-400,350);
}


void drawCircle(GLfloat x, GLfloat y, GLfloat radius)
{
    int triangleAmount = 300;
    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}







void drawAirplane() {
    glPushMatrix();
    glTranslatef( planePosition, 0.0f, 0.0f);
    glTranslatef(100.0f, 150.0f, 0.0f); // Positioned right of the sun


       glColor3f(1.0f, 0.75f, 0.8f); //picher side pakhna
      glBegin(GL_QUADS);
    glVertex2f(170, 110);
    glVertex2f(250, 140);
    glVertex2f(240, 150);
    glVertex2f(150, 120);
    glEnd();


       glColor3f(1.0f, 0.75f, 0.8f);//samner pakhna
    glBegin(GL_QUADS);
    glVertex2f(140, 90);
    glVertex2f(260, 40);
    glVertex2f(250, 60);
    glVertex2f(170, 100);
    glEnd();


   glColor3f(0.678f, 0.847f, 0.902f);//main body
    glBegin(GL_QUADS);
    glVertex2f(100, 120);
    glVertex2f(310, 120);
    glVertex2f(300, 80);
    glVertex2f(100, 80);
    glEnd();

   glColor3f(0.678f, 0.847f, 0.902f);//last part
   glBegin(GL_QUADS);
    glVertex2f(310, 140);
    glVertex2f(300, 80);
    glVertex2f(320, 80);
    glVertex2f(330, 150);
    glEnd();


  glColor3f(0.678f, 0.847f, 0.902f);
    glBegin(GL_TRIANGLES);//samner mukh
    glVertex2f(100, 120);
    glVertex2f(100, 80);
    glVertex2f(70, 95);
    glEnd();

       glColor3f(0.0f, 0.0f, 0.0f); // Windows
    // Window 1
      glBegin(GL_QUADS);
    glVertex2f(150, 110);
    glVertex2f(160, 110);
    glVertex2f(160, 100);
    glVertex2f(150, 100);
    glEnd();

    // Window 2
        glBegin(GL_QUADS);
    glVertex2f(170, 110);
    glVertex2f(180, 110);
    glVertex2f(180, 100);
    glVertex2f(170, 100);
    glEnd();

    // Window 3
     glBegin(GL_QUADS);
    glVertex2f(190, 110);
    glVertex2f(200, 110);
    glVertex2f(200, 100);
    glVertex2f(190, 100);
    glEnd();

    // Window 4
        glBegin(GL_QUADS);
    glVertex2f(210, 110);
    glVertex2f(220, 110);
    glVertex2f(220, 100);
    glVertex2f(210, 100);
    glEnd();

    // Window 5
      glBegin(GL_QUADS);
    glVertex2f(230, 110);
    glVertex2f(240, 110);
    glVertex2f(240, 100);
    glVertex2f(230, 100);
    glEnd();

    // Window 6
    glBegin(GL_QUADS);
    glVertex2f(250, 110);
    glVertex2f(260, 110);
    glVertex2f(260, 100);
    glVertex2f(250, 100);
    glEnd();

    glPopMatrix();
}




void drawFan() {
    // Fan Stand
    glColor3ub(160, 82, 45);
    glBegin(GL_QUADS);
    glVertex2d(-190, -240);
    glVertex2d(-175, -240);
    glVertex2d(-180, -120);
    glVertex2d(-185, -120);
    glEnd();


    // Rotate entire fan mechanism
    glPushMatrix();
    glTranslatef(-182.5f, -120.0f, 0.0f);//center dhore rotate korer jonno ei translatef
    glRotatef(fanRotationAngle, 0.0f, 0.0f, 1.0f); //(z axis a rotate)

    // Fan Blades with larger dimensions
    glColor3ub(176, 3, 35);

    // First Blade (0 degrees)
    glBegin(GL_TRIANGLES);
    glVertex2d(0, 0);
    glVertex2d(0, 80);
    glVertex2d(-20, 40);
    glEnd();

    // Second Blade (90 degrees)
    glBegin(GL_TRIANGLES);
    glVertex2d(0, 0);
    glVertex2d(80, 0);
    glVertex2d(40, -20);
    glEnd();

    // Third Blade (180 degrees)
    glBegin(GL_TRIANGLES);
    glVertex2d(0, 0);
    glVertex2d(0, -80);
    glVertex2d(20, -40);
    glEnd();

    // Fourth Blade (270 degrees)
    glBegin(GL_TRIANGLES);
    glVertex2d(0, 0);
    glVertex2d(-80, 0);
    glVertex2d(-40, 20);
    glEnd();

    glPopMatrix();

    // Fan Center Circle
    glColor3ub(0, 0, 0);
    drawCircle(-182.5f, -120.0f, 5.0f);
}





void drawCloud(float xPos, float yPos, float scale) {
    int triangleAmount = 300;
    GLfloat twicePi = 2.0f * PI;

    glPushMatrix();
    glTranslatef(xPos, yPos, 0.0f);

    // Set white color for clouds
    glColor3f(1.0f, 1.0f, 1.0f);

    // left circle
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0, 0);
    for (int i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            (30.0f * scale * cos(i * twicePi / triangleAmount)),
            (30.0f * scale * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    // Right circle
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(45.0f * scale, 0);
    for (int i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            45.0f * scale + (30.0f * scale * cos(i * twicePi / triangleAmount)),
            (30.0f * scale * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    // Top middle circle
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(22.5f * scale, 30.0f * scale);
    for (int i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            22.5f * scale + (30.0f * scale * cos(i * twicePi / triangleAmount)),
            30.0f * scale + (30.0f * scale * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    glPopMatrix();
}



void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);



     //Sky

      glColor3ub(62, 112, 235);
    glBegin(GL_QUADS);
    glVertex2d(-400, -100);
    glVertex2d(600, -100);

    glColor3ub(57, 213, 255);
    glVertex2d(600, 350);
    glVertex2d(-400, 350);
     glEnd();





       // Circle (Sun)

       glPushMatrix();
    glTranslatef(0.0f, sunPosition , 0.0f);  //Imagine you want a cloud to move up the screen when cloudposition increases. If you only used cloudposition (without multiplying), the movement would be too small to notice. By multiplying it with 300, the movement becomes large enough to see.

    glColor3f(1.0f, 0.84f, 0.0f);
    drawCircle(-225, 260, 30.0f);
     glPopMatrix();


    // Ground

      glColor3ub(0, 255, 0);
    glBegin(GL_QUADS);
    glVertex2d(-400, -400);
    glVertex2d(600, -400);
    glColor3ub(60, 125, 80);
    glVertex2d(600, -100);
    glVertex2d(-400, -100);
     glEnd();





    // 1st beside jhao Tree Trunk
    glColor3ub(139, 69, 19);
    glBegin(GL_QUADS);
    glVertex2d(220, -100);
    glVertex2d(220, -40);
    glVertex2d(230, -40);
    glVertex2d(230, -100);
    glEnd();

    // Tree Leaves
    glColor3ub(0, 128, 0);
    drawCircle(210, -40, 30.0f);
    drawCircle(228, 0, 30.0f);
    drawCircle(245, -40, 30.0f);

    // Second Tree beside jhao
    glColor3ub(139, 69, 19);
    glBegin(GL_QUADS);
    glVertex2d(300, -100);
    glVertex2d(300, -40);
    glVertex2d(310, -40);
    glVertex2d(310, -100);
    glEnd();

    // Tree Leaves
    glColor3ub(0, 128, 0);
    drawCircle(290, -40, 30.0f);
    drawCircle(308, -10, 30.0f);
    drawCircle(325, -40, 30.0f);

    // last tree Third Tree beside jao
    glColor3ub(139, 69, 19);
    glBegin(GL_QUADS);
    glVertex2d(360, -100);
    glVertex2d(360, -20);
    glVertex2d(370, -20);
    glVertex2d(370, -100);
    glEnd();

    glColor3ub(0, 100, 0);
    drawCircle(350, -20, 40.0f);
    drawCircle(365, 30, 35.0f);
    drawCircle(380, -20, 40.0f);

    // 1st Leaves Between ground HILL and Trees
    glColor3ub(34, 139, 34);
    drawCircle(80, -90, 25.0f);
    drawCircle(100, -60, 20.0f);
    drawCircle(120, -90, 25.0f);

    // 2nd Leaves Between ground AKASH ROY hill and Trees
    drawCircle(130, -90, 25.0f);
    drawCircle(150, -60, 20.0f);
    drawCircle(170, -90, 25.0f);

    // River
    glColor3ub(100, 149, 237);
    glBegin(GL_QUADS);
    glVertex2d(-400, -200);
    glVertex2d(600, -200);
    glColor3ub(85, 191, 209);

    glVertex2d(600, -100);
    glVertex2d(-400, -100);
    glEnd();

    // Hills
    glColor3ub(40, 181, 6);
    glBegin(GL_TRIANGLES);
    glVertex2d(-420, -100);
    glVertex2d(-200, -100);
    glVertex2d(-300, 50);
    glEnd();

    // 1st hill inner triangles
    glColor3ub(30, 135, 5);
    glBegin(GL_TRIANGLES);
    glVertex2d(-420, -100);
    glVertex2d(-350, -100);
    glVertex2d(-300, 50);
    glEnd();

    // 2nd hill
    glColor3ub(40, 181, 6);
    glBegin(GL_TRIANGLES);
    glVertex2d(-250, -100);
    glVertex2d(-50, -100);
    glVertex2d(-150, 50);
    glEnd();

    // 2nd hill inner triangles
    glColor3ub(30, 135, 5);
    glBegin(GL_TRIANGLES);
    glVertex2d(-250, -100);
    glVertex2d(-200, -100);
    glVertex2d(-150, 50);
    glEnd();

    // 3rd hill
    glColor3ub(40, 181, 6);
    glBegin(GL_TRIANGLES);
    glVertex2d(-100, -100);
    glVertex2d(120, -100);
    glVertex2d(0, 50);
    glEnd();

    // 3rd hill inner triangles
    glColor3ub(30, 135, 5);
    glBegin(GL_TRIANGLES);
    glVertex2d(-100, -100);
    glVertex2d(-50, -100);
    glVertex2d(0, 50);
    glEnd();



        // 4th hill
    glColor3ub(40, 181, 6);
    glBegin(GL_TRIANGLES);
    glVertex2d(400, -100);
    glVertex2d(620, -100);
    glVertex2d(500, 90);
    glEnd();

    // 4th hill inner triangles
    glColor3ub(30, 135, 5);
    glBegin(GL_TRIANGLES);
    glVertex2d(400, -100);
    glVertex2d(500, 90);
    glVertex2d(450, -100);
    glEnd();


    // Hill right-side tree trunk
    glColor3ub(139, 69, 19);
    glBegin(GL_QUADS);
    glVertex2d(130, -100);
    glVertex2d(130, -30);
    glVertex2d(140, -30);
    glVertex2d(140, -100);
    glEnd();

    // 1st tree triangles
    glColor3ub(30, 135, 5);
    glBegin(GL_TRIANGLES);
    glVertex2d(110, -40);
    glVertex2d(160, -40);
    glVertex2d(135, 100);
    glEnd();

    // 2nd tree trunk
    glColor3ub(139, 69, 19);
    glBegin(GL_QUADS);
    glVertex2d(190, -100);
    glVertex2d(190, -30);
    glVertex2d(200, -30);
    glVertex2d(200, -100);
    glEnd();

    // 2nd upper triangles
    glColor3ub(30, 135, 5);
    glBegin(GL_TRIANGLES);
    glVertex2d(170, 10);
    glVertex2d(220, 10);
    glVertex2d(195, 80);
    glEnd();

    // 2nd lower triangles
    glColor3ub(30, 135, 5);
    glBegin(GL_TRIANGLES);
    glVertex2d(170, -30);
    glVertex2d(220, -30);
    glVertex2d(195, 30);
    glEnd();


    // Second Boat with New Colors

glPushMatrix();
glTranslatef(boatPosition1, 0.0f, 0.0f);

glColor3ub(139, 69, 19);  // Change to SaddleBrown for the boat body
glBegin(GL_QUADS);
glVertex2d(225, -130);
glVertex2d(300, -130);
glVertex2d(325, -100);
glVertex2d(200, -100);
glEnd();

glColor3ub(205, 133, 63);
glBegin(GL_QUADS);
glVertex2d(225, -100);
glVertex2d(300, -100);
glVertex2d(290, -70);
glVertex2d(235, -70);
glEnd();

glColor3ub(45, 105, 105);  // Change to Dim Gray for the mast
glBegin(GL_QUADS);
glVertex2d(260, -70);
glVertex2d(270, -70);
glVertex2d(270, -40);
glVertex2d(260, -40);
glEnd();

glColor3ub(255, 29, 23);  // Change to OrangeRed AKASH ROY for the sail
glBegin(GL_QUADS);
glVertex2d(235, -60);
glVertex2d(290, -60);
glVertex2d(290, 25);
glVertex2d(235, 25);
glEnd();

glPopMatrix();

    // Boat

     glPushMatrix();
    glTranslatef(boatPosition2 , 0.0f, 0.0f);
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2d(-75, -180);
    glVertex2d(0, -180);
    glVertex2d(25, -150);
    glVertex2d(-100, -150);
    glEnd();





    glColor3ub(205, 133, 63);
    glBegin(GL_QUADS);
    glVertex2d(-75, -150);
    glVertex2d(0, -150);
    glVertex2d(-10, -120);
    glVertex2d(-65, -120);
    glEnd();

    glColor3ub(160, 82, 45);
    glBegin(GL_QUADS);
    glVertex2d(-40, -120);
    glVertex2d(-30, -120);
    glVertex2d(-30, -90);
    glVertex2d(-40, -90);
    glEnd();

    glColor3ub(127, 23, 156);
    glBegin(GL_QUADS);
    glVertex2d(-65, -110);
    glVertex2d(-10, -110);
    glVertex2d(-10, -25);
    glVertex2d(-65, -25);
    glEnd();
    glPopMatrix();









    ///////////////////////////////// HOUSE   ////////////////////////////

    //Tree Trunk (Large Tree)
    glColor3ub(139, 69, 19);
    glBegin(GL_QUADS);
    glVertex2d(-350, -250);
    glVertex2d(-330, -250);
    glVertex2d(-330, -100);
    glVertex2d(-350, -100);
    glEnd();

    //Tree Leaves (Large Tree upper house tree)
    glColor3ub(0, 128, 0);
    drawCircle(-350, -75, 40.0f);
    drawCircle(-330, -75, 40.0f);
    drawCircle(-355, -45, 40.0f);
    drawCircle(-325, -45, 40.0f);
    drawCircle(-340, -15, 40.0f);

    // 2nd House choto ghor
    glColor3ub(210, 105, 30);
    glBegin(GL_QUADS);
    glVertex2d(-300, -180);
    glVertex2d(-200, -180);
    glVertex2d(-225, -130);
    glVertex2d(-270, -130);
    glEnd();

    glColor3ub(244, 164, 96);
    glBegin(GL_QUADS);
    glVertex2d(-300, -230);
    glVertex2d(-215, -230);
    glVertex2d(-215, -180);
    glVertex2d(-300, -180);
    glEnd();

    glColor3ub(160, 82, 45);
    glBegin(GL_QUADS);
    glVertex2d(-300, -230);
    glVertex2d(-210, -230);
    glVertex2d(-210, -240);
    glVertex2d(-300, -240);
    glEnd();

    // 2nd house door
    glColor3ub(160, 82, 45);
    glBegin(GL_QUADS);
    glVertex2d(-260, -230);
    glVertex2d(-235, -230);
    glVertex2d(-235, -200);
    glVertex2d(-260, -200);
    glEnd();

    // 1st House
    glColor3ub(160, 82, 45);
    glBegin(GL_QUADS);
    glVertex2d(-400, -180);
    glVertex2d(-265, -180);
    glVertex2d(-290, -130);
    glVertex2d(-375, -130);
    glEnd();

    glColor3ub(255, 222, 173);
    glBegin(GL_TRIANGLES);
    glVertex2d(-390, -180);
    glVertex2d(-350, -180);
    glVertex2d(-375, -145);
    glEnd();

    glColor3ub(255, 222, 173);
    glBegin(GL_QUADS);
    glVertex2d(-390, -250);
    glVertex2d(-350, -250);
    glVertex2d(-350, -180);
    glVertex2d(-390, -180);
    glEnd();

    glColor3ub(222, 184, 135);
    glBegin(GL_QUADS);
    glVertex2d(-350, -250);
    glVertex2d(-275, -250);
    glVertex2d(-275, -180);
    glVertex2d(-350, -180);
    glEnd();

    glColor3ub(160, 82, 45);
    glBegin(GL_QUADS);
    glVertex2d(-390, -250);
    glVertex2d(-275, -250);
    glVertex2d(-275, -260);
    glVertex2d(-390, -260);
    glEnd();

    // 1st house door and window
    glColor3ub(160, 82, 45);
    glBegin(GL_QUADS);
    glVertex2d(-325, -250);
    glVertex2d(-305, -250);
    glVertex2d(-305, -205);
    glVertex2d(-325, -205);
    glEnd();
    //window
    glColor3ub(160, 82, 45);
    glBegin(GL_QUADS);
    glVertex2d(-380, -200);
    glVertex2d(-365, -200);
    glVertex2d(-365, -225);
    glVertex2d(-380, -225);
    glEnd();





    // School
    glColor3ub(244, 138, 68);
    glBegin(GL_QUADS);
    glVertex2d(-50, -400);
    glVertex2d(160, -400);
    glVertex2d(160, -150);
    glVertex2d(-50, -150);
    glEnd();

    // School left Side Wall
    glColor3ub(176, 105, 52);
    glBegin(GL_QUADS);
    glVertex2d(-50, -400);
    glVertex2d(-50, -150);
    glVertex2d(-60, -130);
    glVertex2d(-60, -370);
    glEnd();

    // School Roof Top
    glColor3ub(128, 76, 38);
    glBegin(GL_QUADS);
    glVertex2d(-50, -150);
    glVertex2d(160, -150);
    glVertex2d(160, -130);
    glVertex2d(-60, -130);
    glEnd();

// School Roof Top Pillar Back Walls
    glColor3ub(128, 76, 38);
    for (int i = 0; i < 42; i++) {
        int x = i * 5;
        glBegin(GL_QUADS);
        glVertex2d(-60 + x, -130);
        glVertex2d(-58 + x, -130);
        glVertex2d(-58 + x, -120);
        glVertex2d(-60 + x, -120);
        glEnd();
    }

    // School Roof Top Pillar Forward Walls AKASH ROY
    glColor3ub(100, 56, 38);
    for (int i = 0; i < 42; i++) {
        int x = i * 5;
        glBegin(GL_QUADS);
        glVertex2d(-50 + x, -150);
        glVertex2d(-48 + x, -150);
        glVertex2d(-48 + x, -137);
        glVertex2d(-50 + x, -137);
        glEnd();
    }

    // School Wall Corner Design
    glColor3ub(128, 76, 38);
    glBegin(GL_QUADS);
    glVertex2d(-50, -150);
    glVertex2d(-47, -150);
    glVertex2d(-47, -400);
    glVertex2d(-50, -400);
    glEnd();

    // School Wall Divide Design Horizontal
    glColor3ub(237, 204, 125);
    for(int i = 0; i <= 4; i++) {
        int x = i * 50;
        glBegin(GL_QUADS);
        glVertex2d(-47 + x, -150);
        glVertex2d(-40 + x, -150);
        glVertex2d(-40 + x, -400);
        glVertex2d(-47 + x, -400);
        glEnd();
    }

    // School Wall Divide Design Vertical
    glColor3ub(237, 204, 125);
    for(int i = 0; i <= 4; i++) {
        int y = i * 100;
        glBegin(GL_QUADS);
        glVertex2d(-46, -150 - y);
        glVertex2d(100, -150 - y);
        glVertex2d(100, -162 - y);
        glVertex2d(-46, -162 - y);
        glEnd();
    }

    // School Windows AKASH ROY
    glColor3ub(48, 45, 77);
    for (int j = 0; j < 3; j++) {
        for (int i = 0; i <= 4; i++) {
            int y = i * 100;
            int x = j * 50;
            glBegin(GL_QUADS);
            glVertex2d(-30 + x, -210 - y);
            glVertex2d(-10 + x, -210 - y);
            glVertex2d(-10 + x, -170 - y);
            glVertex2d(-30 + x, -170 - y);
            glEnd();
        }
    }

    // School Main Gate
    glColor3ub(50, 50, 59);
    glBegin(GL_QUADS);
    glVertex2d(18, -400);
    glVertex2d(48, -400);
    glVertex2d(48, -340);
    glVertex2d(18, -340);
    glEnd();

    // School Text
    glColor3ub(63, 72, 204);
    glRasterPos2f(20, -160);  //Indicated starting position of SChool x, y
    for (int i = 0; i < 6; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, "SCHOOL"[i]);//HELV TEXT SIZE 18,     CHARACTER  NITESI
    }

     // Tube Well Wall Part
     //green
    glBegin(GL_QUADS);
    glColor3ub(0, 100, 0);
    glVertex2d(-280, -302);
    glVertex2d(-320, -342);
    glVertex2d(-260, -342);
    glVertex2d(-240, -302);
    glEnd();
//white
    glBegin(GL_QUADS);
    glColor3ub(143, 188, 143);
    glVertex2d(-275, -307);
    glVertex2d(-295, -327);
    glVertex2d(-265, -327);
    glVertex2d(-250, -307);
    glEnd();
//black
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2i(-320, -352);
    glVertex2i(-320, -342);
    glVertex2i(-260, -342);
    glVertex2i(-260, -352);
    glEnd();
//2nd black
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2d(-240, -302);
    glVertex2d(-240, -322);
    glVertex2d(-260, -352);
    glVertex2d(-260, -342);
    glEnd();


// Main Tube Well Body
glBegin(GL_QUADS);
glColor3ub(184, 134, 11);  // Golden brown color
glVertex2d(-275, -260);    // Top left
glVertex2d(-265, -260);    // Top right AKASH ROY
glVertex2d(-265, -320);    // Bottom right
glVertex2d(-275, -320);    // Bottom left
glEnd();


    // Tube Well Second Part choto triangle
    glBegin(GL_TRIANGLES);
    glColor3ub(255, 215, 0);
    glVertex2d(-275, -260);
    glVertex2d(-270, -265);
    glVertex2d(-265, -260);

    glEnd();

    // Tube Well Third Part
    glBegin(GL_QUADS);
    glColor3ub(205, 133, 63);
    glVertex2i(-272, -260);
    glVertex2i(-272, -245);
    glVertex2i(-268, -245);
    glVertex2i(-268, -260);
    glEnd();




// Water Faucet
glBegin(GL_QUADS);
glColor3ub(139, 69, 19);   // Darker brown for the spout
glVertex2d(-265, -275);    // Left top
glVertex2d(-255, -275);    // Right top
glVertex2d(-255, -282);    // Right bottom
glVertex2d(-265, -282);    // Left bottom
glEnd();




// Handle Bar
glBegin(GL_QUADS);
glColor3ub(139, 69, 19);
glVertex2d(-282, -242);    // Top left
glVertex2d(-258, -242);    // Top right
glVertex2d(-258, -245);    // Bottom right
glVertex2d(-282, -245);    // Bottom left
glEnd();



    // School Flag Stand
    glBegin(GL_QUADS);
    glColor3ub(205, 133, 63);
    glVertex2i(165, -400);
    glVertex2i(170, -400);
    glVertex2i(170, -115);
    glVertex2i(165, -115);
    glEnd();

    // School Flag
    glBegin(GL_QUADS);
    glColor3ub(0, 100, 0);
    glVertex2d(170, -180);
    glVertex2d(230, -180);
    glVertex2d(230, -115);
    glVertex2d(170, -115);
    glEnd();

    // School Flag Circle
    glColor3ub(255, 27, 27);
    drawCircle(195, -145, 13.0f);




// Apply Translation
glPushMatrix();

glTranslatef(190,130,0);

// School Bus - Main Body
glBegin(GL_POLYGON);
glColor3ub(255, 216, 0);  // School bus yellow
glVertex2i(100, -300);    // Top left
glVertex2i(400, -300);    // Top right
glVertex2i(400, -400);    // Bottom right
glVertex2i(100, -400);    // Bottom left
glEnd();



// Headlights on front side
glBegin(GL_QUADS);
glColor3ub(221, 232, 229);  // Light yellow color for headlights

// Left headlight (lower)
glVertex2i(90, -375);    // Top left
glVertex2i(100, -375);   // Top right
glVertex2i(100, -385);   // Bottom right
glVertex2i(90, -385);    // Bottom left

// Right headlight (upper)
glVertex2i(90, -340);    // Top left
glVertex2i(100, -340);   // Top right
glVertex2i(100, -350);   // Bottom right
glVertex2i(90, -350);    // Bottom left
glEnd();






// Windows
glBegin(GL_QUADS);
glColor3ub(135, 206, 235);  // Light blue for windows


// Passenger windows (4 windows AKASH ROY)
// First window
glVertex2i(150, -310);
glVertex2i(200, -310);
glVertex2i(200, -330);
glVertex2i(150, -330);

// Second window
glVertex2i(210, -310);
glVertex2i(260, -310);
glVertex2i(260, -330);
glVertex2i(210, -330);

// Third window
glVertex2i(270, -310);
glVertex2i(320, -310);
glVertex2i(320, -330);
glVertex2i(270, -330);

// Fourth window
glVertex2i(330, -310);
glVertex2i(380, -310);
glVertex2i(380, -330);
glVertex2i(330, -330);
glEnd();

// bus Wheels

glColor3ub(0, 0, 0);  // Black for wheels
drawCircle(170, -385, 20);    // Front wheel  call the draw circle global function
drawCircle(340, -385, 20);    // Back wheel - x, y, radius



// Door
glBegin(GL_QUADS);
glColor3ub(200, 200, 200);  // Grey for door
glVertex2i(110, -330);    // Top left
glVertex2i(140, -330);    // Top right
glVertex2i(140, -400);    // Bottom right
glVertex2i(110, -400);    // Bottom left
glEnd();




// PlayGround
glBegin(GL_LINE_STRIP);
glColor3ub(0, 0, 0);
glVertex2i(101, -468);
glVertex2i(101, -430);
glVertex2i(76, -443);
glVertex2i(76, -470);
glEnd();

// **Connect left post top**
glBegin(GL_LINES);
glColor3ub(0, 0, 0);
glVertex2i(101, -430);  // Top of left post
glVertex2i(96, -460);   // Connecting to second left post
glEnd();

glBegin(GL_LINE_STRIP);
glColor3ub(0, 0, 0);
glVertex2i(96, -498);
glVertex2i(96, -460);
glVertex2i(71, -473);
glVertex2i(71, -500);
glEnd();

// Goal Post Right
glBegin(GL_LINE_STRIP);
glColor3ub(0, 0, 0);
glVertex2i(299, -468);
glVertex2i(299, -430);
glVertex2i(324, -443);
glVertex2i(324, -470);
glEnd();

// **Connect right post top**
glBegin(GL_LINES);
glColor3ub(0, 0, 0);
glVertex2i(299, -430);  // Top of right post AKASH ROY
glVertex2i(304, -460);  // Connecting to second right post
glEnd();

glBegin(GL_LINE_STRIP);
glColor3ub(0, 0, 0);
glVertex2i(304, -498);
glVertex2i(304, -460);
glVertex2i(329, -473);
glVertex2i(329, -500);
glEnd();

// Boundary
glBegin(GL_LINE_LOOP);
glColor3ub(255, 255, 255);
glVertex2i(80, -420);
glVertex2i(318, -420);
glVertex2i(335, -520);
glVertex2i(69, -520);
glEnd();

// Mid line
glBegin(GL_LINES);
glColor3ub(255, 255, 255);
glVertex2i(200, -420);
glVertex2i(200, -520);
glEnd();

// Center Circle
glColor3ub(255, 255, 255);
drawCircle(200, -470, 10.0f);



  // School Text
    glColor3ub(63, 72, 204);
    glRasterPos2f(220, -370);  //Indicated starting position of SChool x, y
    for (int i = 0; i < 10; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, "SCHOOL BUS"[i]);//HELV TEXT SIZE 18,     CHARACTER  NITESI
    }

glPopMatrix();  // Restore the original matrix



 glPushMatrix();
glTranslatef(cloudPosition , 0.0f, 0.0f);
drawCloud(-300, 250, 0.5f);    // First cloud
drawCloud(-150, 220, 0.8f);    // Second cloud
drawCloud(-220, 280, 0.6f);    // Third cloud
drawCloud(100, 240, 0.7f);     // Fourth cloud
drawCloud(0, 260, 0.5f);       // Fifth cloud
glPopMatrix();


glEnd();
drawFan();
drawAirplane(); // Draw the airplane
glutSwapBuffers();
glFlush();


}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(900, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Village Scenery");
    init();
    glutSpecialFunc(SpecialInput);
    glutDisplayFunc(display);
    glutTimerFunc(100, Movement, 0);
    glutMainLoop();
    return 0;
}
