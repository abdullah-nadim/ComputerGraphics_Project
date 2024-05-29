#include <windows.h>
#include <iostream>
#include<GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <time.h>
#define MAX_DROPS 100

bool midnight= false;
float _movext = 0.0f;//car
float _movexx= 0.0f;//bus
float _movexxx= 0.0f;//rail
float _movexxxx= 0.0f;//cloud2
float _movexxxxx= 0.0f;//cloud1
GLfloat speed1= 4.0f; //car
GLfloat speed2= .20f; //bus
GLfloat speed3= 3.0f; //rail
GLfloat speed4= 1.0f; //cloud2
GLfloat speed5= 1.0f; //cloud1
//GLfloat speed= 2.0f; //
struct Raindrop {
    float x, y, speed;
};

Raindrop drops[MAX_DROPS];
bool isRaining = false;

void init() {
    srand(time(NULL)); // Seed the random number generator
    for (int i = 0; i < MAX_DROPS; i++) {
        drops[i].x = (float)rand() / (float)RAND_MAX * 1920;
        drops[i].y = (float)rand() / (float)RAND_MAX * 1923.4919545627597;
        drops[i].speed = (float)rand() / (float)RAND_MAX / 5.0 + 9; // Base speed
    }
}

void update1(int value) {
    for (int i = 0; i < MAX_DROPS; i++) {
        drops[i].y -= drops[i].speed * 1000; // Increase speed further
        if (drops[i].y < 0) { // Reset drop if it goes below window
            drops[i].y = 1923.4919545627597;
            drops[i].x = (float)rand() / (float)RAND_MAX * 1920;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(10, update1, 0);
}

void rain() {
    glColor3f(1, 1, 1);
    glPointSize(5.0);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);
    for (int i = 0; i < MAX_DROPS; i++) {
        float width = 5.0; // Width of the raindrop
        float height = 30.0; // Height of the raindrop (increase this value to make it longer)
        glVertex2f(drops[i].x - width / 2, drops[i].y);
        glVertex2f(drops[i].x + width / 2, drops[i].y);
        glVertex2f(drops[i].x + width / 2, drops[i].y - height);
        glVertex2f(drops[i].x - width / 2, drops[i].y - height);
    }
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glutSwapBuffers();
}
void forestday(){
    for(int j=0;j<2000;j+=150)
    {
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
            {
                glColor3ub(34, 139, 34);; // Pale yellow or white color for the moon
                float pi=3.1416;
                float A=(i*2*pi)/200;
                float r=150;
                float x = r * cos(A);
                float y = r * sin(A);
                glVertex2f(x+j,y+820 );
            }
         glEnd();
    }
}

void forestnight(){

    for(int j=0;j<2000;j+=150)
    {
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
            {
                glColor3ub(0, 100, 0);
                float pi=3.1416;
                float A=(i*2*pi)/200;
                float r=150;
                float x = r * cos(A);
                float y = r * sin(A);
                glVertex2f(x+j,y+820 );
            }
         glEnd();
    }

}


void drawBackground() {

    if(midnight)
    {
     glBegin(GL_POLYGON);
    glColor3ub(19,24,98);
    glVertex2f(0, 0);
    glVertex2f(1920, 0);
    glVertex2f(1920, 1920);
    glVertex2f(0, 1920);
    glEnd();
    forestnight();

    glBegin(GL_POLYGON);
    glColor3ub(64, 64, 64);
    glVertex2f(0, 0);
    glVertex2f(0, 400);
    glVertex2f(1920, 400);
    glVertex2f(1920, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(34, 139, 34);
    glVertex2f(0, 400);
    glVertex2f(0, 800);
    glVertex2f(1920, 800);
    glVertex2f(1920, 400);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3ub(144, 238, 144);
    glVertex2f(0, 700);
    glVertex2f(0, 800);
    glVertex2f(1920, 800);
    glVertex2f(1920, 700);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(50, 205, 50); // Slightly lighter green color for grass
    glVertex2f(0, 550);
    glVertex2f(0, 700);
    glVertex2f(1920, 700);
    glVertex2f(1920, 550);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(192, 192, 192); // Light gray color for side road
    glVertex2f(0, 400);
    glVertex2f(0, 410);
    glVertex2f(1920, 410);
    glVertex2f(1920, 400);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(139, 69, 19);
    glVertex2f(0, 465);
    glVertex2f(0, 410);
    glVertex2f(1920, 410);
    glVertex2f(1920, 465);
    glEnd();

   glBegin(GL_POLYGON);
    glColor3ub(192, 192, 192);
    glVertex2f(0, 0);
    glVertex2f(1920, 0);
    glVertex2f(1920,10);
    glVertex2f(0, 10);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(192, 192, 192);
    glVertex2f(690, 180);
    glVertex2f(600, 180);
    glVertex2f(600,220);
    glVertex2f(690, 220);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(192, 192, 192);
    glVertex2f(490, 180);
    glVertex2f(400, 180);
    glVertex2f(400,220);
    glVertex2f(490, 220);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(192, 192, 192);
    glVertex2f(290, 180);
    glVertex2f(200, 180);
    glVertex2f(200,220);
    glVertex2f(290, 220);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(192, 192, 192);
    glVertex2f(890, 180);
    glVertex2f(800, 180);
    glVertex2f(800,220);
    glVertex2f(890, 220);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(192, 192, 192);
    glVertex2f(1090, 180);
    glVertex2f(1000, 180);
    glVertex2f(1000,220);
    glVertex2f(1090, 220);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(192, 192, 192);
    glVertex2f(1290, 180);
    glVertex2f(1200, 180);
    glVertex2f(1200,220);
    glVertex2f(1290, 220);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(192, 192, 192);
    glVertex2f(1490, 180);
    glVertex2f(1400, 180);
    glVertex2f(1400,220);
    glVertex2f(1490, 220);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(192, 192, 192);
    glVertex2f(1690, 180);
    glVertex2f(1600, 180);
    glVertex2f(1600,220);
    glVertex2f(1690, 220);
    glEnd();



    glBegin(GL_POLYGON);
    glColor3ub(192, 192, 192);
    glVertex2f(490, 180);
    glVertex2f(400, 180);
    glVertex2f(400,220);
    glVertex2f(490, 220);
    glEnd();


    }
    else if(isRaining)
    {
        glBegin(GL_POLYGON);
    glColor3ub(87,128,197);
    glVertex2f(0, 0);
    glVertex2f(1920, 0);
    glVertex2f(1920, 1920);
    glVertex2f(0, 1920);
    glEnd();

    forestnight();

    glBegin(GL_POLYGON);
    glColor3ub(64, 64, 64);
    glVertex2f(0, 0);
    glVertex2f(0, 400);
    glVertex2f(1920, 400);
    glVertex2f(1920, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(34, 139, 34);
    glVertex2f(0, 400);
    glVertex2f(0, 800);
    glVertex2f(1920, 800);
    glVertex2f(1920, 400);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3ub(144, 238, 144);
    glVertex2f(0, 700);
    glVertex2f(0, 800);
    glVertex2f(1920, 800);
    glVertex2f(1920, 700);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(50, 205, 50); // Slightly lighter green color for grass
    glVertex2f(0, 550);
    glVertex2f(0, 700);
    glVertex2f(1920, 700);
    glVertex2f(1920, 550);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(192, 192, 192); // Light gray color for side road
    glVertex2f(0, 400);
    glVertex2f(0, 410);
    glVertex2f(1920, 410);
    glVertex2f(1920, 400);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(139, 69, 19);
    glVertex2f(0, 465);
    glVertex2f(0, 410);
    glVertex2f(1920, 410);
    glVertex2f(1920, 465);
    glEnd();

   glBegin(GL_POLYGON);
    glColor3ub(192, 192, 192);
    glVertex2f(0, 0);
    glVertex2f(1920, 0);
    glVertex2f(1920,10);
    glVertex2f(0, 10);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(192, 192, 192);
    glVertex2f(690, 180);
    glVertex2f(600, 180);
    glVertex2f(600,220);
    glVertex2f(690, 220);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(192, 192, 192);
    glVertex2f(490, 180);
    glVertex2f(400, 180);
    glVertex2f(400,220);
    glVertex2f(490, 220);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(192, 192, 192);
    glVertex2f(290, 180);
    glVertex2f(200, 180);
    glVertex2f(200,220);
    glVertex2f(290, 220);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(192, 192, 192);
    glVertex2f(890, 180);
    glVertex2f(800, 180);
    glVertex2f(800,220);
    glVertex2f(890, 220);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(192, 192, 192);
    glVertex2f(1090, 180);
    glVertex2f(1000, 180);
    glVertex2f(1000,220);
    glVertex2f(1090, 220);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(192, 192, 192);
    glVertex2f(1290, 180);
    glVertex2f(1200, 180);
    glVertex2f(1200,220);
    glVertex2f(1290, 220);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(192, 192, 192);
    glVertex2f(1490, 180);
    glVertex2f(1400, 180);
    glVertex2f(1400,220);
    glVertex2f(1490, 220);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(192, 192, 192);
    glVertex2f(1690, 180);
    glVertex2f(1600, 180);
    glVertex2f(1600,220);
    glVertex2f(1690, 220);
    glEnd();



    glBegin(GL_POLYGON);
    glColor3ub(192, 192, 192);
    glVertex2f(490, 180);
    glVertex2f(400, 180);
    glVertex2f(400,220);
    glVertex2f(490, 220);
    glEnd();
    }
    else{

    glBegin(GL_POLYGON);
    glColor3ub(135, 206, 235);
    glVertex2f(0, 0);
    glVertex2f(1920, 0);
    glVertex2f(1920, 1920);
    glVertex2f(0, 1920);
    glEnd();

    forestday();

    glBegin(GL_POLYGON);
    glColor3ub(64, 64, 64);
    glVertex2f(0, 0);
    glVertex2f(0, 400);
    glVertex2f(1920, 400);
    glVertex2f(1920, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(34, 139, 34);
    glVertex2f(0, 400);
    glVertex2f(0, 800);
    glVertex2f(1920, 800);
    glVertex2f(1920, 400);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3ub(144, 238, 144);
    glVertex2f(0, 700);
    glVertex2f(0, 800);
    glVertex2f(1920, 800);
    glVertex2f(1920, 700);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(50, 205, 50); // Slightly lighter green color for grass
    glVertex2f(0, 550);
    glVertex2f(0, 700);
    glVertex2f(1920, 700);
    glVertex2f(1920, 550);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(192, 192, 192); // Light gray color for side road
    glVertex2f(0, 400);
    glVertex2f(0, 410);
    glVertex2f(1920, 410);
    glVertex2f(1920, 400);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(139, 69, 19);
    glVertex2f(0, 465);
    glVertex2f(0, 410);
    glVertex2f(1920, 410);
    glVertex2f(1920, 465);
    glEnd();

   glBegin(GL_POLYGON);
    glColor3ub(192, 192, 192);
    glVertex2f(0, 0);
    glVertex2f(1920, 0);
    glVertex2f(1920,10);
    glVertex2f(0, 10);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(192, 192, 192);
    glVertex2f(690, 180);
    glVertex2f(600, 180);
    glVertex2f(600,220);
    glVertex2f(690, 220);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(192, 192, 192);
    glVertex2f(490, 180);
    glVertex2f(400, 180);
    glVertex2f(400,220);
    glVertex2f(490, 220);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(192, 192, 192);
    glVertex2f(290, 180);
    glVertex2f(200, 180);
    glVertex2f(200,220);
    glVertex2f(290, 220);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(192, 192, 192);
    glVertex2f(890, 180);
    glVertex2f(800, 180);
    glVertex2f(800,220);
    glVertex2f(890, 220);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(192, 192, 192);
    glVertex2f(1090, 180);
    glVertex2f(1000, 180);
    glVertex2f(1000,220);
    glVertex2f(1090, 220);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(192, 192, 192);
    glVertex2f(1290, 180);
    glVertex2f(1200, 180);
    glVertex2f(1200,220);
    glVertex2f(1290, 220);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(192, 192, 192);
    glVertex2f(1490, 180);
    glVertex2f(1400, 180);
    glVertex2f(1400,220);
    glVertex2f(1490, 220);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(192, 192, 192);
    glVertex2f(1690, 180);
    glVertex2f(1600, 180);
    glVertex2f(1600,220);
    glVertex2f(1690, 220);
    glEnd();



    glBegin(GL_POLYGON);
    glColor3ub(192, 192, 192);
    glVertex2f(490, 180);
    glVertex2f(400, 180);
    glVertex2f(400,220);
    glVertex2f(490, 220);
    glEnd();

    }
}

void car(){

    glMatrixMode(GL_MODELVIEW);

 glPushMatrix();
glTranslatef(_movext,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(255, 0, 0);
    glVertex2f(1130.2706081336423, 76.9294515724692);
    glVertex2f(1130.5903492014709, 110.182522626607);
    glVertex2f(1132.8285366762684, 143.4355936807448);
    glVertex2f(1539.2515855236106, 140.4809559371323);
    glVertex2f(1547.175136229711, 98.1775759151558);
    glVertex2f(1547.175136229711, 98.1775759151558);
    glVertex2f(1527.175136229711, 58.1775759151558);
    glVertex2f(1321.4757666948258, 54.2278357566637);
    glVertex2f(1233.5469730421582, 59.0239517740874);
    glVertex2f(1145.618179389398, 67.9767016732783);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 0, 0);
    //glVertex2f(1130.2706081336423, 76.9294515724692);
    //glVertex2f(1130.5903492014709, 110.182522626607);
    glVertex2f(1132.8285366762684, 143.4355936807448);
    glVertex2f(1143.3799919146004, 175.4097004635696);
    glVertex2f(1157.175136229897, 198.1775759151558);
    glVertex2f(1198.6995656710874, 209.2605669335955);
    glVertex2f(1300.195964600919, 215.5808555116489);
    glVertex2f(1349.5985070499119, 190.9039120394936);
    glVertex2f(1450.7675454308642, 150.1472796447433);
    glVertex2f(1534.4505759090289, 142.5350463680833);
    glVertex2f(1540.430782506974, 123.00721692722);
    //glVertex2f(1145.618179389398, 67.9767016732783);
    glEnd();

    glBegin(GL_POLYGON);
     glColor3ub(135, 206, 235);
    //glVertex2f(1130.2706081336423, 76.9294515724692);
    //glVertex2f(1130.5903492014709, 110.182522626607);
    glVertex2f(1301.0098051800896, 146.290026832156);
    glVertex2f(1298.2025277143334, 151.7394477951002);
    glVertex2f(1295.3952502485777, 200.1237005873015);
    glVertex2f(1324.4400389150196, 194.3440116872092);
    glVertex2f(1403.8882676016156, 158.6750744752109);
    glVertex2f(1393.980229487183, 145.8038211149894);
   // glVertex2f(1198.6995656710874, 209.2605669335955);
    //glVertex2f(1450.7675454308642, 150.1472796447433);
  //  glVertex2f(1534.4505759090289, 142.5350463680833);
    //glVertex2f(1233.5469730421582, 59.0239517740874);
    //glVertex2f(1145.618179389398, 67.9767016732783);
    glEnd();

    glBegin(GL_POLYGON);
     glColor3ub(135, 206, 235);
    //glVertex2f(1130.2706081336423, 76.9294515724692);
    //glVertex2f(1130.5903492014709, 110.182522626607);
    glVertex2f(1190.7366070390121, 145.2756947307938);
    glVertex2f(1185.1751191101084, 150.6686527224578);
    glVertex2f(1212.329906684453, 190.769581595212);
    glVertex2f(1287.1751362298419, 198.1775759151558);
    glVertex2f(1288.9895604495705, 150.5001227852183);
    glVertex2f(1282.2483629599983, 146.4554042914703);
   // glVertex2f(1198.6995656710874, 209.2605669335955);
    //glVertex2f(1450.7675454308642, 150.1472796447433);
  //  glVertex2f(1534.4505759090289, 142.5350463680833);
    //glVertex2f(1233.5469730421582, 59.0239517740874);
    //glVertex2f(1145.618179389398, 67.9767016732783);
    glEnd();

    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
	for(int i=0;i<200;i++)
        {
            glColor3f(0.0,0.0,0.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=45;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+1435,y+75 );
        }
     glEnd();

     glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
	for(int i=0;i<200;i++)
        {
            glColor3f(1.0,1.0,1.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=30;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+1435,y+75 );
        }
     glEnd();

    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
	for(int i=0;i<200;i++)
        {
            glColor3f(0.0,0.0,0.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=45;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+1205,y+77 );
        }
     glEnd();

     glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
	for(int i=0;i<200;i++)
        {
            glColor3f(1.0,1.0,1.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=30;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+1205,y+77 );
        }
     glEnd();
/*     glLineWidth(3);
     glBegin(GL_LINES);
     glColor3f(0,0,0);
     glVertex2f(1205,100);
     glVertex2f(1205,50);
     glVertex2f(1230,77);
     glVertex2f(1180,77);

     glVertex2f(1410,75 );
     glVertex2f(1460,75 );
     glVertex2f(1435,50 );
     glVertex2f(1435,100 );
     glEnd();*/
     glPopMatrix();


}

void bus(){
glMatrixMode(GL_MODELVIEW);

 glPushMatrix();
glTranslatef(_movexx,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(255, 205, 0);
    glVertex2f(900.3463617500055, 342.8764162518361);
    glVertex2f(925.780761557542, 225.5115632267804);
    glVertex2f(927.469739306791, 140.5196644444287);
    glVertex2f(350.1367880234681, 136.6299430062087);
    glVertex2f(350.1367880234681, 342.8764162518361);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(135, 206, 235);
    glVertex2f(904.2087461373768, 316.6569403852714);
    glVertex2f(925.780761557542, 225.5115632267804);
    glVertex2f(350.1367880234681, 225.5115632267804);
    glVertex2f(350.1367880234681, 316.6569403852714);
    //glVertex2f(350.1367880234681, 342.8764162518361);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(135, 206, 235);
    glVertex2f(892, 145);
    glVertex2f(892, 310);
    glVertex2f(836, 310);
    glVertex2f(836, 145);
    //glVertex2f(350.1367880234681, 342.8764162518361);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor4f(0.1f, 0.1f, 0.1f, 0.5f);
    glVertex2f(863, 145);
    glVertex2f(863, 308);

    glVertex2f(836, 310);
    glVertex2f(836, 145);


    glVertex2f(440, 310);
    glVertex2f(440, 226);

    glVertex2f(490, 310);
    glVertex2f(490, 226);


    glVertex2f(540, 310);
    glVertex2f(540, 226);


    glVertex2f(590, 310);
    glVertex2f(590, 226);



    glVertex2f(640, 310);
    glVertex2f(640, 226);



    glVertex2f(690, 310);
    glVertex2f(690, 226);


    glVertex2f(740, 310);
    glVertex2f(740, 226);


    glVertex2f(790, 310);
    glVertex2f(790, 226);





    glVertex2f(890, 310);
    glVertex2f(890, 145);

    //glVertex2f(350.1367880234681, 342.8764162518361);
    glEnd();

     glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
	for(int i=0;i<200;i++)
        {
            glColor3f(0.0,0.0,0.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=45;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+735,y+145 );
        }
     glEnd();

     glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
	for(int i=0;i<200;i++)
        {
            glColor3f(1.0,1.0,1.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=30;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+735,y+145 );
        }
     glEnd();

    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
	for(int i=0;i<200;i++)
        {
            glColor3f(0.0,0.0,0.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=45;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+500,y+145 );
        }
     glEnd();

     glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
	for(int i=0;i<200;i++)
        {
            glColor3f(1.0,1.0,1.0);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=30;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+500,y+145 );
        }
     glEnd();
/*     glLineWidth(3);
     glBegin(GL_LINES);
     glColor3f(0,0,0);
     glVertex2f(500,120);
     glVertex2f(500,170);
     glVertex2f(475,145);
     glVertex2f(525,145);

     glVertex2f(710,145);
     glVertex2f(760,145 );
     glVertex2f(735,120 );
     glVertex2f(735,170 );
     glEnd();*/
glPopMatrix();

}

void piller(){
    glBegin(GL_POLYGON);
    glColor3ub(192, 192, 192);
    glVertex2f(1150,435);
    glVertex2f(1150,900);
/*  glVertex2f(1135, 745);
    glVertex2f(1125,830);
    glVertex2f(1260,830);
    glVertex2f(1250,745);*/
    glVertex2f(1225,900);
    glVertex2f(1225,435);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(192, 192, 192);
    glVertex2f(1125, 900);
    glVertex2f(1115,1000);
    glVertex2f(1260,1000);
    glVertex2f(1250,900);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(192, 192, 192);
    glVertex2f(1275, 700);
    glVertex2f(1265,760);
    glVertex2f(1410,760);
    glVertex2f(1400,700);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(192, 192, 192);
    glVertex2f(1300,455);
    glVertex2f(1300,700);
    glVertex2f(1375,700);
    glVertex2f(1375,455);
    glEnd();

}
void tree(){
    glBegin(GL_POLYGON);
    //glColor3ub(154, 205, 50); // Yellowish-green color for the tree
    glColor3ub(160, 82, 45); // Light brown color for tree wood
    glVertex2f(1000,470);
    glVertex2f(1000,600);
    glVertex2f(1020,600);
    glVertex2f(1020,470);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(154, 205, 50);
    glVertex2f(1010,615);
    glVertex2f(1050,570);
    glVertex2f(980,570);
    //glVertex2f(1030,470);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(154, 205, 50);
    glVertex2f(1000,570);
    glVertex2f(1020,570);
    glVertex2f(1050,525);
    glVertex2f(970,525);
    //glVertex2f(1030,470);
    glEnd();



    glBegin(GL_POLYGON);
    //glColor3ub(154, 205, 50); // Yellowish-green color for the tree
    glColor3ub(160, 82, 45); // Light brown color for tree wood
    glVertex2f(900,470);
    glVertex2f(900,600);
    glVertex2f(920,600);
    glVertex2f(920,470);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(154, 205, 50);
    glVertex2f(910,615);
    glVertex2f(950,570);
    glVertex2f(880,570);
    //glVertex2f(1030,470);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(154, 205, 50);
    glVertex2f(900,570);
    glVertex2f(920,570);
    glVertex2f(950,525);
    glVertex2f(870,525);
    //glVertex2f(1030,470);
    glEnd();


    glBegin(GL_POLYGON);
    //glColor3ub(154, 205, 50); // Yellowish-green color for the tree
    glColor3ub(160, 82, 45); // Light brown color for tree wood
    glVertex2f(800,470);
    glVertex2f(800,600);
    glVertex2f(820,600);
    glVertex2f(820,470);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(154, 205, 50);
    glVertex2f(810,615);
    glVertex2f(850,570);
    glVertex2f(780,570);
    //glVertex2f(1030,470);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(154, 205, 50);
    glVertex2f(800,570);
    glVertex2f(820,570);
    glVertex2f(850,525);
    glVertex2f(770,525);
    //glVertex2f(1030,470);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(160, 82, 45); // Light brown color for tree wood
    glVertex2f(600,470);
    glVertex2f(600,600);
    glVertex2f(620,600);
    glVertex2f(620,470);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(154, 205, 50);
    glVertex2f(610,615);
    glVertex2f(650,570);
    glVertex2f(580,570);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(154, 205, 50);
    glVertex2f(600,570);
    glVertex2f(620,570);
    glVertex2f(650,525);
    glVertex2f(570,525);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(160, 82, 45); // Light brown color for tree wood
    glVertex2f(500,470);
    glVertex2f(500,600);
    glVertex2f(520,600);
    glVertex2f(520,470);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(154, 205, 50);
    glVertex2f(510,615);
    glVertex2f(550,570);
    glVertex2f(480,570);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(154, 205, 50);
    glVertex2f(500,570);
    glVertex2f(520,570);
    glVertex2f(550,525);
    glVertex2f(470,525);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(160, 82, 45); // Light brown color for tree wood
    glVertex2f(400,470);
    glVertex2f(400,600);
    glVertex2f(420,600);
    glVertex2f(420,470);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(154, 205, 50);
    glVertex2f(410,615);
    glVertex2f(450,570);
    glVertex2f(380,570);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(154, 205, 50);
    glVertex2f(400,570);
    glVertex2f(420,570);
    glVertex2f(450,525);
    glVertex2f(370,525);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(160, 82, 45); // Light brown color for tree wood
    glVertex2f(200,470);
    glVertex2f(200,600);
    glVertex2f(220,600);
    glVertex2f(220,470);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(154, 205, 50);
    glVertex2f(210,615);
    glVertex2f(250,570);
    glVertex2f(180,570);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(154, 205, 50);
    glVertex2f(200,570);
    glVertex2f(220,570);
    glVertex2f(250,525);
    glVertex2f(170,525);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(160, 82, 45); // Light brown color for tree wood
    glVertex2f(100,470);
    glVertex2f(100,600);
    glVertex2f(120,600);
    glVertex2f(120,470);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(154, 205, 50);
    glVertex2f(110,615);
    glVertex2f(150,570);
    glVertex2f(80,570);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(154, 205, 50);
    glVertex2f(100,570);
    glVertex2f(120,570);
    glVertex2f(150,525);
    glVertex2f(70,525);
    glEnd();



    glBegin(GL_POLYGON);
    glColor3ub(160, 82, 45); // Light brown color for tree wood
    glVertex2f(1600,470);
    glVertex2f(1600,600);
    glVertex2f(1620,600);
    glVertex2f(1620,470);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(154, 205, 50);
    glVertex2f(1610,615);
    glVertex2f(1650,570);
    glVertex2f(1580,570);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(154, 205, 50);
    glVertex2f(1600,570);
    glVertex2f(1620,570);
    glVertex2f(1650,525);
    glVertex2f(1570,525);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(160, 82, 45); // Light brown color for tree wood
    glVertex2f(1700,470);
    glVertex2f(1700,600);
    glVertex2f(1720,600);
    glVertex2f(1720,470);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(154, 205, 50);
    glVertex2f(1710,615);
    glVertex2f(1750,570);
    glVertex2f(1680,570);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(154, 205, 50);
    glVertex2f(1700,570);
    glVertex2f(1720,570);
    glVertex2f(1750,525);
    glVertex2f(1670,525);
    glEnd();
}
void red_building(){

    glBegin(GL_POLYGON);
    glColor3ub(139,100, 0);
    glVertex2f(0,800);
    glVertex2f(0,900);
    glVertex2f(60,920);
    glVertex2f(132,932);
    glVertex2f(205,922);
    glVertex2f(285,885);
    glVertex2f(310,860);
    glVertex2f(310,800);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(64,0, 0);
    glVertex2f(19,800);
    glVertex2f(18.5,860);
    glVertex2f(35,880);
    glVertex2f(35,800);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(64,0, 0);
    glVertex2f(65,800);
    glVertex2f(64.5,880);
    glVertex2f(70,892);
    glVertex2f(79,900);
    glVertex2f(86,895);
    glVertex2f(92,886);
    glVertex2f(92,800);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(64,0, 0);
    glVertex2f(115,800);
    glVertex2f(114.5,880);
    glVertex2f(120,892);
    glVertex2f(129,900);
    glVertex2f(136,895);
    glVertex2f(142,886);
    glVertex2f(142,800);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(64,0, 0);
    glVertex2f(165,800);
    glVertex2f(164.5,880);
    glVertex2f(170,892);
    glVertex2f(179,900);
    glVertex2f(186,895);
    glVertex2f(192,886);
    glVertex2f(192,800);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(64,0, 0);
    glVertex2f(215,800);
    glVertex2f(214.5,880);
    glVertex2f(220,892);
    glVertex2f(229,900);
    glVertex2f(236,895);
    glVertex2f(242,886);
    glVertex2f(242,800);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(64,0, 0);
    glVertex2f(269,800);
    glVertex2f(268.5,880);
    glVertex2f(285,860);
    glVertex2f(285,800);
    glEnd();


}

void circle(float radius, float xC, float yC, float r, float g, float b)
{
   glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    for(int i=0;i<200;i++)
        {
            glColor3ub(r,g,b);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=radius;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+xC,y+yC);
        }

    glEnd();
}

void square(float x,float y,int r,int g,int b){

glBegin(GL_POLYGON);
glColor3ub(r,g,b);
glVertex2f(x,y);
glVertex2f(x+10,y);
glVertex2f(x+10,y+7);
glVertex2f(x,y+7);
glEnd();

}


void square2(float x,float y,int r,int g,int b){

glBegin(GL_POLYGON);
glColor3ub(r,g,b);
glVertex2f(x,y);
glVertex2f(x+2,y);
glVertex2f(x+2,y+2);
glVertex2f(x,y+2);
glEnd();

}
void grass(){
///Grass(houseSide)
glBegin(GL_POLYGON);
glColor3ub(12,23,32);
glVertex2i(200,34);
glVertex2i(200,50);
glVertex2i(0,50);
glVertex2i(0,34);
glEnd();
}

void lamppost(){
    glBegin(GL_POLYGON);
    glColor3ub(0,0, 0);
    glVertex2f(735,405);
    glVertex2f(735,550);
    glVertex2f(750,550);
    glVertex2f(750,405);
    glEnd();

    glBegin(GL_POLYGON);
    //glColor3ub(255, 255, 204);
    glColor3ub(255, 255, 0);
    glVertex2f(725,550);
    glVertex2f(720,580);
    glVertex2f(745,595);
    glVertex2f(765,580);
    glVertex2f(760,550);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(0,0, 0);
    glVertex2f(1035,405);
    glVertex2f(1035,550);
    glVertex2f(1050,550);
    glVertex2f(1050,405);
    glEnd();

    glBegin(GL_POLYGON);
    //glColor3ub(255, 255, 204);
    glColor3ub(255, 255, 0);
    glVertex2f(1025,550);
    glVertex2f(1020,580);
    glVertex2f(1045,595);
    glVertex2f(1065,580);
    glVertex2f(1060,550);
    glEnd();


    glBegin(GL_POLYGON);
    //glColor3ub(255, 255, 204);
    glColor3ub(255, 255, 0);
    glVertex2f(425,550);
    glVertex2f(420,580);
    glVertex2f(445,595);
    glVertex2f(465,580);
    glVertex2f(460,550);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,0, 0);
    glVertex2f(435,405);
    glVertex2f(435,550);
    glVertex2f(450,550);
    glVertex2f(450,405);
    glEnd();

    glBegin(GL_POLYGON);
    //glColor3ub(255, 255, 204);
    glColor3ub(255, 255, 0);
    glVertex2f(1425,550);
    glVertex2f(1420,580);
    glVertex2f(1445,595);
    glVertex2f(1465,580);
    glVertex2f(1460,550);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,0, 0);
    glVertex2f(1435,405);
    glVertex2f(1435,550);
    glVertex2f(1450,550);
    glVertex2f(1450,405);
    glEnd();


    glBegin(GL_POLYGON);
    //glColor3ub(255, 255, 204);
    glColor3ub(255, 255, 0);
    glVertex2f(1825,550);
    glVertex2f(1820,580);
    glVertex2f(1845,595);
    glVertex2f(1865,580);
    glVertex2f(1860,550);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,0, 0);
    glVertex2f(1835,405);
    glVertex2f(1835,550);
    glVertex2f(1850,550);
    glVertex2f(1850,405);
    glEnd();

}

void lamppostnight(){
    glBegin(GL_POLYGON);
    glColor3ub(0,0, 0);
    glVertex2f(735,405);
    glVertex2f(735,550);
    glVertex2f(750,550);
    glVertex2f(750,405);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 204);
    //glColor3ub(255, 255, 0);
    glVertex2f(725,550);
    glVertex2f(720,580);
    glVertex2f(745,595);
    glVertex2f(765,580);
    glVertex2f(760,550);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(0,0, 0);
    glVertex2f(1035,405);
    glVertex2f(1035,550);
    glVertex2f(1050,550);
    glVertex2f(1050,405);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 204);
    //glColor3ub(255, 255, 0);
    glVertex2f(1025,550);
    glVertex2f(1020,580);
    glVertex2f(1045,595);
    glVertex2f(1065,580);
    glVertex2f(1060,550);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 204);
    //glColor3ub(255, 255, 0);
    glVertex2f(425,550);
    glVertex2f(420,580);
    glVertex2f(445,595);
    glVertex2f(465,580);
    glVertex2f(460,550);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,0, 0);
    glVertex2f(435,405);
    glVertex2f(435,550);
    glVertex2f(450,550);
    glVertex2f(450,405);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 204);
    //glColor3ub(255, 255, 0);
    glVertex2f(1425,550);
    glVertex2f(1420,580);
    glVertex2f(1445,595);
    glVertex2f(1465,580);
    glVertex2f(1460,550);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,0, 0);
    glVertex2f(1435,405);
    glVertex2f(1435,550);
    glVertex2f(1450,550);
    glVertex2f(1450,405);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 204);
   // glColor3ub(255, 255, 0);
    glVertex2f(1825,550);
    glVertex2f(1820,580);
    glVertex2f(1845,595);
    glVertex2f(1865,580);
    glVertex2f(1860,550);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,0, 0);
    glVertex2f(1835,405);
    glVertex2f(1835,550);
    glVertex2f(1850,550);
    glVertex2f(1850,405);
    glEnd();

}
void railtrack(float x,float y){
glBegin(GL_POLYGON);
glColor3ub( 58, 71, 71);
glVertex2f(x+10,y+0);
glVertex2f(x+30,y+0);
glVertex2f(x+20,y+80);
glVertex2f(x+00,y+80);
glEnd();
}
void railline(){

glBegin(GL_POLYGON);
glColor3ub( 143, 153, 153);
glVertex2f(0, 590);
glVertex2f(0, 660);
glVertex2f(1920, 660);
glVertex2f(1920, 580);;
glEnd();

/*glBegin(GL_POLYGON);
glColor3ub( 143, 153, 153);
glVertex2i(0,12);
glVertex2i(205,13);
glVertex2i(205,13);
glVertex2i(0,12);
glEnd();

glBegin(GL_POLYGON);
glColor3ub( 143, 153, 153);
glVertex2i(200,8);
glVertex2i(200,18);
glVertex2i(0,18);
glVertex2i(0,8);
glEnd();
*/
}
void rail(float x,float y){
glMatrixMode(GL_MODELVIEW);

 glPushMatrix();
glTranslatef(_movexxx,0.0f, 0.0f);
glBegin(GL_POLYGON);
glColor3ub(34, 139, 34);
glVertex2f(x+0.0,y+0);
glVertex2f(x+800.0,y+0);
glVertex2f(x+800.0,y+150);
glVertex2f(x+0.0,y+150);
glEnd();

glPointSize(1.5);
glBegin(GL_LINES);
glColor3ub( 71, 69, 58);
glVertex2f(x+250,y+00);
glVertex2f(x+250,y+150);
glEnd();

glPointSize(1.5);
glBegin(GL_LINES);
glColor3ub( 71, 69, 58);
glVertex2f(x+550,y+0);
glVertex2f(x+550,y+150);
glEnd();

circle(75,x+800,y+75, 34, 139, 34);
circle(25,x+100,y+75, 228, 234, 240);
circle(25,x+200,y+75, 228, 234, 240);
circle(25,x+300,y+75, 228, 234, 240);
circle(25,x+400,y+75, 228, 234, 240);
circle(25,x+500,y+75, 228, 234, 240);
circle(25,x+600,y+75, 228, 234, 240);
circle(25,x+700,y+75, 228, 234, 240);


circle(15,x+50,y+5,4, 0, 5 );
circle(15,x+100,y+5,4, 0, 5 );
circle(15,x+200,y+5,4, 0, 5 );
circle(15,x+300,y+5,4, 0, 5 );
circle(15,x+400,y+5,4, 0, 5 );
circle(15,x+500,y+5,4, 0, 5 );
circle(15,x+600,y+5,4, 0, 5 );
circle(15,x+700,y+5,4, 0, 5 );
circle(15,x+150,y+5,4, 0, 5 );
circle(15,x+250,y+5,4, 0, 5 );
circle(15,x+350,y+5,4, 0, 5 );
circle(15,x+450,y+5,4, 0, 5 );
circle(15,x+550,y+5,4, 0, 5 );
circle(15,x+650,y+5,4, 0, 5 );
circle(15,x+750,y+5,4, 0, 5 );

glPopMatrix();
}


void cloud1(){

    glMatrixMode(GL_MODELVIEW);

 glPushMatrix();
glTranslatef(_movexxxxx,0.0f, 0.0f);
///Circle 1

glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(253,254,254);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=75;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+300,y+1640 );
        }


	glEnd();

///Circle 2

glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(253,254,254);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=75;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+250,y+1655 );
        }


	glEnd();
///Circle 3

glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(253,254,254);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=75;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+350,y+1665 );
        }


	glEnd();


	///Circle 4

glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(253,254,254);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=75;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+750,y+1645 );
        }


	glEnd();


	///Circle 5

glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(253,254,254);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=75;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+850,y+1655 );
        }


	glEnd();


	///Circle 6

glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(253,254,254);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=75;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+800,y+1665 );
        }


	glEnd();


	///Circle 7

glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(253,254,254);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=50;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+700,y+1660 );
        }


	glEnd();

glPopMatrix();
}

void cloud2(){

    glMatrixMode(GL_MODELVIEW);

 glPushMatrix();
glTranslatef(-_movexxxx,0.0f , 0.0f);

///Circle 1

glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(253,254,254);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=75;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+1500,y+1735 );
        }


	glEnd();

///Circle 2

glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(253,254,254);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=90;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+1400,y+1750 );
        }


	glEnd();

///Circle 3

glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(253,254,254);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=75;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+1450,y+1760 );
        }


	glEnd();


	///Circle 4

glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(253,254,254);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=50;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+1650,y+1730 );
        }


	glEnd();


	///Circle 5

glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(253,254,254);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=75;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+1700,y+1750 );
        }


	glEnd();


	///Circle 6

glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(253,254,254);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=50;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+1600,y+1750 );
        }


	glEnd();


	///Circle 7

glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(253,254,254);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=75;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+1750,y+1740 );
        }


	glEnd();
glPopMatrix();

}


void back_building(){


    ///building 1
    glBegin(GL_POLYGON);
    glColor3ub(100, 180, 235); // Light gray color for the building
    glVertex2f(280,800);
    glVertex2f(280,1300);
    glVertex2f(500,1300);
    glVertex2f(500,800);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(0, 0, 255); // Blue color for the windows
    glVertex2f(500,900);
    glVertex2f(280,900);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0, 0, 255); // Blue color for the windows
    glVertex2f(500,850);
    glVertex2f(280,850);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0, 0, 255); // Blue color for the windows
    glVertex2f(500,950);
    glVertex2f(280,950);
    glEnd();

glBegin(GL_LINES);
    glColor3ub(0, 0, 255); // Blue color for the windows
    glVertex2f(500,1000);
    glVertex2f(280,1000);
    glEnd();
glBegin(GL_LINES);
    glColor3ub(0, 0, 255); // Blue color for the windows
    glVertex2f(500,1050);
    glVertex2f(280,1050);
    glEnd();
glBegin(GL_LINES);
    glColor3ub(0, 0, 255); // Blue color for the windows
    glVertex2f(500,1100);
    glVertex2f(280,1100);
    glEnd();
glBegin(GL_LINES);
    glColor3ub(0, 0, 255); // Blue color for the windows
    glVertex2f(500,1150);
    glVertex2f(280,1150);
    glEnd();
glBegin(GL_LINES);
    glColor3ub(0, 0, 255); // Blue color for the windows
    glVertex2f(500,1200);
    glVertex2f(280,1200);
    glEnd();
glBegin(GL_LINES);
    glColor3ub(0, 0, 255); // Blue color for the windows
    glVertex2f(500,1250);
    glVertex2f(280,1250);
    glEnd();



    ///building 2

    glBegin(GL_POLYGON);
    glColor3ub(100, 180, 235); // Light blue color with transparency for glass building
    glVertex2f(800,800);
    glVertex2f(800,1300);
    glVertex2f(505,1300);
    glVertex2f(505,800);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(100, 180, 235); // Light blue color with transparency for glass building
    glVertex2f(800,1350);
    glVertex2f(800,1300);
    glVertex2f(505,1300);
    glVertex2f(505,1400);
    glEnd();



    ///building 3

     glBegin(GL_POLYGON);
    glColor3ub(176, 224, 230);
    glVertex2f(820,1000);
    glVertex2f(820,1400);
    glVertex2f(985,1400);
    glVertex2f(985,1000);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(100, 180, 235);
    glVertex2f(805,800);
    glVertex2f(805,1300);
    glVertex2f(1005,1300);
    glVertex2f(1005,800);
    glEnd();

glLineWidth(0.5);


    glBegin(GL_LINES);
    glColor3ub(255, 229, 180); // Blue color for the windows
    glVertex2f(805,900);
    glVertex2f(1005,900);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255, 229, 180); // Blue color for the windows
    glVertex2f(805,850);
    glVertex2f(1005,850);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255, 229, 180); // Blue color for the windows
    glVertex2f(805,950);
    glVertex2f(1005,950);
    glEnd();

glBegin(GL_LINES);
    glColor3ub(255, 229, 180); // Blue color for the windows
    glVertex2f(805,1000);
    glVertex2f(1005,1000);
    glEnd();
glBegin(GL_LINES);
    glColor3ub(255, 229, 180); // Blue color for the windows
    glVertex2f(805,1050);
    glVertex2f(1005,1050);
    glEnd();
glBegin(GL_LINES);
    glColor3ub(255, 229, 180); // Blue color for the windows
    glVertex2f(805,1100);
    glVertex2f(1005,1100);
    glEnd();
glBegin(GL_LINES);
    glColor3ub(255, 229, 180); // Blue color for the windows
    glVertex2f(805,1150);
    glVertex2f(1005,1150);
    glEnd();
glBegin(GL_LINES);
    glColor3ub(255, 229, 180); // Blue color for the windows
    glVertex2f(805,1200);
    glVertex2f(1005,1200);
    glEnd();
glBegin(GL_LINES);
    glColor3ub(255, 229, 180); // Blue color for the windows
    glVertex2f(805,1250);
    glVertex2f(1005,1250);
    glEnd();


/// building 4
    glBegin(GL_POLYGON);
    glColor3ub(100, 180, 235);
    glVertex2f(1100,800);
    glVertex2f(1100,1400);
    glVertex2f(1300,1400);
    glVertex2f(1300,800);
    glEnd();
glLineWidth(0.5);

glBegin(GL_LINES);
    glColor3ub(255, 229, 180); // Blue color for the windows
    glVertex2f(1150,800);
    glVertex2f(1150,1400);
    glEnd();
glBegin(GL_LINES);
    glColor3ub(255, 229, 180); // Blue color for the windows
    glVertex2f(1200,800);
    glVertex2f(1200,1400);
    glEnd();
glBegin(GL_LINES);
    glColor3ub(255, 229, 180); // Blue color for the windows
    glVertex2f(1250,800);
    glVertex2f(1250,1400);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255, 229, 180); // Blue color for the windows
    glVertex2f(1100,900);
    glVertex2f(1300,900);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255, 229, 180); // Blue color for the windows
    glVertex2f(1100,850);
    glVertex2f(1300,850);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255, 229, 180); // Blue color for the windows
    glVertex2f(1100,950);
    glVertex2f(1300,950);
    glEnd();

glBegin(GL_LINES);
    glColor3ub(255, 229, 180); // Blue color for the windows
    glVertex2f(1100,1000);
    glVertex2f(1300,1000);
    glEnd();
glBegin(GL_LINES);
    glColor3ub(255, 229, 180); // Blue color for the windows
    glVertex2f(1100,1050);
    glVertex2f(1300,1050);
    glEnd();
glBegin(GL_LINES);
    glColor3ub(255, 229, 180); // Blue color for the windows
    glVertex2f(1100,1100);
    glVertex2f(1300,1100);
    glEnd();
glBegin(GL_LINES);
    glColor3ub(255, 229, 180); // Blue color for the windows
    glVertex2f(1100,1150);
    glVertex2f(1300,1150);
    glEnd();
glBegin(GL_LINES);
    glColor3ub(255, 229, 180); // Blue color for the windows
    glVertex2f(1100,1200);
    glVertex2f(1300,1200);
    glEnd();
glBegin(GL_LINES);
    glColor3ub(255, 229, 180); // Blue color for the windows
    glVertex2f(1100,1250);
    glVertex2f(1300,1250);
    glEnd();
glBegin(GL_LINES);
    glColor3ub(255, 229, 180); // Blue color for the windows
    glVertex2f(1100,1350);
    glVertex2f(1300,1350);
    glEnd();
glBegin(GL_LINES);
    glColor3ub(255, 229, 180); // Blue color for the windows
    glVertex2f(1100,1300);
    glVertex2f(1300,1300);
    glEnd();

    ///building 5
glBegin(GL_POLYGON);
    glColor3ub(100, 180, 235);
    glVertex2f(1350,800);
    glVertex2f(1350,1400);
    glVertex2f(1600,1400);
    glVertex2f(1600,800);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(0, 0, 255); // Blue color for the windows
    glVertex2f(1350,900);
    glVertex2f(1600,900);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0, 0, 255); // Blue color for the windows
    glVertex2f(1350,850);
    glVertex2f(1600,850);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0, 0, 255); // Blue color for the windows
    glVertex2f(1350,950);
    glVertex2f(1600,950);
    glEnd();

glBegin(GL_LINES);
    glColor3ub(0, 0, 255); // Blue color for the windows
    glVertex2f(1350,1000);
    glVertex2f(1600,1000);
    glEnd();
glBegin(GL_LINES);
    glColor3ub(0, 0, 255); // Blue color for the windows
    glVertex2f(1350,1050);
    glVertex2f(1600,1050);
    glEnd();
glBegin(GL_LINES);
    glColor3ub(0, 0, 255); // Blue color for the windows
    glVertex2f(1350,1100);
    glVertex2f(1600,1100);
    glEnd();
glBegin(GL_LINES);
    glColor3ub(0, 0, 255); // Blue color for the windows
    glVertex2f(1350,1150);
    glVertex2f(1600,1150);
    glEnd();
glBegin(GL_LINES);
    glColor3ub(0, 0, 255); // Blue color for the windows
    glVertex2f(1350,1200);
    glVertex2f(1600,1200);
    glEnd();
glBegin(GL_LINES);
    glColor3ub(0, 0, 255); // Blue color for the windows
    glVertex2f(1350,1250);
    glVertex2f(1600,1250);
    glEnd();
glBegin(GL_LINES);
    glColor3ub(0, 0, 255); // Blue color for the windows
    glVertex2f(1350,1350);
    glVertex2f(1600,1350);
    glEnd();
glBegin(GL_LINES);
    glColor3ub(0, 0, 255); // Blue color for the windows
    glVertex2f(1350,1300);
    glVertex2f(1600,1300);
    glEnd();


///building 6
    glBegin(GL_POLYGON);
    glColor3ub(100, 180, 235);
    glVertex2f(1620,800);
    glVertex2f(1620,1400);
    glVertex2f(1850,1300);
    glVertex2f(1850,800);
    glEnd();

 /// building 7
glMatrixMode(GL_MODELVIEW);

 glPushMatrix();
glTranslatef(-1050,0.0f, 0.0f);
glBegin(GL_POLYGON);
    glColor3ub(100, 180, 235);
    glVertex2f(1100,800);
    glVertex2f(1100,1400);
    glVertex2f(1300,1400);
    glVertex2f(1300,800);
    glEnd();
glLineWidth(0.5);

glBegin(GL_LINES);
    glColor3ub(0,0,255); // Blue color for the windows
    glVertex2f(1150,800);
    glVertex2f(1150,1400);
    glEnd();
glBegin(GL_LINES);
    glColor3ub(0,0,255); // Blue color for the windows
    glVertex2f(1200,800);
    glVertex2f(1200,1400);
    glEnd();
glBegin(GL_LINES);
    glColor3ub(0,0,255); // Blue color for the windows
    glVertex2f(1250,800);
    glVertex2f(1250,1400);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0,0,255); // Blue color for the windows
    glVertex2f(1100,900);
    glVertex2f(1300,900);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0,0,255); // Blue color for the windows
    glVertex2f(1100,850);
    glVertex2f(1300,850);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0,0,255); // Blue color for the windows
    glVertex2f(1100,950);
    glVertex2f(1300,950);
    glEnd();

glBegin(GL_LINES);
    glColor3ub(0,0,255); // Blue color for the windows
    glVertex2f(1100,1000);
    glVertex2f(1300,1000);
    glEnd();
glBegin(GL_LINES);
    glColor3ub(0,0,255); // Blue color for the windows
    glVertex2f(1100,1050);
    glVertex2f(1300,1050);
    glEnd();
glBegin(GL_LINES);
    glColor3ub(0,0,255); // Blue color for the windows
    glVertex2f(1100,1100);
    glVertex2f(1300,1100);
    glEnd();
glBegin(GL_LINES);
    glColor3ub(0,0,255); // Blue color for the windows
    glVertex2f(1100,1150);
    glVertex2f(1300,1150);
    glEnd();
glBegin(GL_LINES);
    glColor3ub(0,0,255); // Blue color for the windows
    glVertex2f(1100,1200);
    glVertex2f(1300,1200);
    glEnd();
glBegin(GL_LINES);
    glColor3ub(0,0,255); // Blue color for the windows
    glVertex2f(1100,1250);
    glVertex2f(1300,1250);
    glEnd();
glBegin(GL_LINES);
    glColor3ub(0,0,255); // Blue color for the windows
    glVertex2f(1100,1350);
    glVertex2f(1300,1350);
    glEnd();
glBegin(GL_LINES);
    glColor3ub(0,0,255); // Blue color for the windows
    glVertex2f(1100,1300);
    glVertex2f(1300,1300);
    glEnd();
 glPopMatrix();
/// building 8
glMatrixMode(GL_MODELVIEW);
 glPushMatrix();
glTranslatef(940,0.0f, 0.0f);
     glBegin(GL_POLYGON);
    glColor3ub(176, 224, 230);
    glVertex2f(820,1000);
    glVertex2f(820,1400);
    glVertex2f(985,1400);
    glVertex2f(985,1000);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(100, 180, 235);
    glVertex2f(805,800);
    glVertex2f(805,1300);
    glVertex2f(1005,1300);
    glVertex2f(1005,800);
    glEnd();

glLineWidth(0.5);


    glBegin(GL_LINES);
    glColor3ub(255, 229, 180); // Blue color for the windows
    glVertex2f(805,900);
    glVertex2f(1005,900);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255, 229, 180); // Blue color for the windows
    glVertex2f(805,850);
    glVertex2f(1005,850);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255, 229, 180); // Blue color for the windows
    glVertex2f(805,950);
    glVertex2f(1005,950);
    glEnd();

glBegin(GL_LINES);
    glColor3ub(255, 229, 180); // Blue color for the windows
    glVertex2f(805,1000);
    glVertex2f(1005,1000);
    glEnd();
glBegin(GL_LINES);
    glColor3ub(255, 229, 180); // Blue color for the windows
    glVertex2f(805,1050);
    glVertex2f(1005,1050);
    glEnd();
glBegin(GL_LINES);
    glColor3ub(255, 229, 180); // Blue color for the windows
    glVertex2f(805,1100);
    glVertex2f(1005,1100);
    glEnd();
glBegin(GL_LINES);
    glColor3ub(255, 229, 180); // Blue color for the windows
    glVertex2f(805,1150);
    glVertex2f(1005,1150);
    glEnd();
glBegin(GL_LINES);
    glColor3ub(255, 229, 180); // Blue color for the windows
    glVertex2f(805,1200);
    glVertex2f(1005,1200);
    glEnd();
glBegin(GL_LINES);
    glColor3ub(255, 229, 180); // Blue color for the windows
    glVertex2f(805,1250);
    glVertex2f(1005,1250);
    glEnd();

glPopMatrix();
}



void sun(){
    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(253, 184, 19);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=75;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+500,y+1650 );
        }
     glEnd();

}

void moon(){

    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(255, 255, 204); // Pale yellow or white color for the moon
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=75;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+530,y+1650 );
        }
     glEnd();



    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(19,24,98);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=75;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+500,y+1650 );
        }
     glEnd();
}

void initStar() {
    for (int i = 0; i < MAX_DROPS; i++) {
        drops[i].x = (float)rand() / (float)RAND_MAX * 1920.0f ; // Random x position in range 800 to 1920
        drops[i].y = (float)rand() / (float)RAND_MAX * 1120.0f + 800.0f; // Random y position in range 800 to 1920
        drops[i].speed = (float)rand() / (float)RAND_MAX * 0.02f + 0.01f; // Random speed
    }
}



void display() {
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
if(midnight)
{
     drawBackground();

    bus();
    car();

    railline();
    for(int i=0;i<=1920;i=i+40){
    railtrack(i,585);
    }

    back_building();
    red_building();

    rail(200,590);
    tree();
    piller();

    lamppostnight();
if(isRaining)
    {
        rain();
    }
    else{
            moon();
        glutSwapBuffers();
    }

}
else{
    drawBackground();
    bus();
    car();

    railline();
    for(int i=0;i<=1920;i=i+40){
    railtrack(i,585);
    }

    back_building();
    red_building();


    rail(200,590);
    tree();
    piller();

    lamppost();
    if(isRaining)
    {
        rain();
    }
    else{
            sun();
    cloud2();
    cloud1();
        glutSwapBuffers();
    }

}
}
void update(int value) {

if(_movext > 1800 )
{
_movext = -1400;
}
else if(_movexx > 1800 )
{
_movexx = -700;
}
else if(_movexxx > 1800 )
{
_movexxx = -750;
}
else if(_movexxxx > 1800 )
{
_movexxxx = -750;
}
else if(_movexxxxx > 1800 )
{
_movexxxxx = -750;
}
_movext += speed1;//car
_movexx+=speed2;//bus
_movexxx+=speed3;//rail
_movexxxx+=speed4;//cloud2
_movexxxxx+=speed5;//cloud1
glutPostRedisplay();
glutTimerFunc(20, update, 0);
}
void handleKeypress(unsigned char key, int x, int y) {
	switch (key) {
case 'a':
    speed1 -= 10; /// car speed
    break;
case 's':
    speed1 += 10;
    break;
case 'z':
    speed2 -= 10; /// bus speed
    break;
case 'x':
    speed2 += 10;
    break;
case 'q':
    speed4 -= 10; /// cloud2
    break;
case 'w':
    speed4 += 10;
    break;
case 'e':
    speed5 -= 10; ///cloud1
    break;
case 'r':
    speed5 += 10;
    break;
case 'n':
    midnight = true;
    break;
case 'd':
    midnight = false;
    break;
case 'k':
    isRaining = false;
    break;
case 'l':
    isRaining = true; ///raining

    break;
glutPostRedisplay();
	}}

void handleMouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
	{	speed3 -= 5;
			}
if (button == GLUT_RIGHT_BUTTON)
	{speed3 += 5;}
glutPostRedisplay();
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-600)/2, (glutGet(GLUT_SCREEN_HEIGHT)-600)/2);
    glutCreateWindow("Scenario of 2020");
   // glMatrixMode(GL_PROJECTION);
 //   glLoadIdentity();
    glutDisplayFunc(display);
    //init();
    gluOrtho2D(0, 1920, 0, 1923.4919545627597);
    glutTimerFunc(20, update, 0);
    glutTimerFunc(10, update1, 0);
    initStar();
   glutKeyboardFunc(handleKeypress);
   glutMouseFunc(handleMouse);
    glutMainLoop();
    return 0;
}
