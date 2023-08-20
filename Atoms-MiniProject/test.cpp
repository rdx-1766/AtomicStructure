#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <string>
#define pi 3.142
int reshape_flag = 0;
static GLfloat angle = 0;

static int submenu,submenu2;
static int mainmenu;
static int value = -1;

void init()
{
    gluOrtho2D(-1000, 1000, -1000, 1000);
}



void circle(float rad)
{
    glBegin(GL_POINTS);
    glColor3f(1, 0, 0);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(rad * cos(i), rad * sin(i));
    }
    glEnd();
}

void drawString(float x, float y, float z, char* string)
{
    glColor3f(1, 1, 1);
    glRasterPos3f(x, y, z);

    for (char* c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, *c);
    }
}

void drawhead(float x, float y, float z, char* string)
{
    glColor3f(1, 1, 1);
    glRasterPos3f(x, y, z);

    for (char* c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }
}

void drawsubhead(float x, float y, float z, char* string)
{
    glColor3f(1, 1, 1);
    glRasterPos3f(x, y, z);

    for (char* c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c);
    }
}

void nuc(float rad)
{
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 1);
    for (float i = 0; i < (2 * pi); i = i + 0.00001)
    {
        glVertex2f(rad * cos(i), rad * sin(i));
    }
    glEnd();
}

void eleright(float rad)
{
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(rad + 20 * cos(i), 20 * sin(i));
    }
    glEnd();
}

void eleleft(float rad)
{
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(-(rad + 20 * cos(i)), 20 * sin(i));
    }
    glEnd();
}

void eletop(float rad)
{
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(20 * cos(i), rad + 20 * sin(i));
    }
    glEnd();
}

void eledown(float rad)
{
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(20 * cos(i), -(rad + 20 * sin(i)));
    }
    glEnd();
}
void eletr(float rad)
{
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(((rad - 175) + 20 * cos(i)), ((rad - 175) + 20 * sin(i)));
    }
    glEnd();
}

void eletl(float rad)
{
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(-((rad - 175) + 20 * cos(i)), ((rad - 175) + 20 * sin(i)));
    }
    glEnd();
}

void eledl(float rad)
{
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(-((rad - 175) + 20 * cos(i)), -((rad - 175) + 20 * sin(i)));
    }
    glEnd();
}

void eledr(float rad)
{
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(((rad - 175) + 20 * cos(i)), -((rad - 175) + 20 * sin(i)));
    }
    glEnd();
}

void renderBitmapString(float x, float y, float z, void* font, std::string string) {
    glDisable(GL_LIGHTING); // Disable lighting temporarily
    glRasterPos3f(x, y, z);
    for (char c : string) {
        glutBitmapCharacter(font, c);
    }
    glEnable(GL_LIGHTING); // Enable lighting again
}



void display1() {

    glClearColor(0, 0, 0.54, 0.9);

    GLfloat light_position[] = { 1.0f, 1.0f, 1.0f, 0.0f };
    GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat light_ambient[] = { 0.2f, 0.2f, 0.2f, 1.0f };

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    int width = glutGet(GLUT_WINDOW_WIDTH);
    int height = glutGet(GLUT_WINDOW_HEIGHT);

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (float)width / (float)height, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0f, 0.0f, 5.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

    reshape_flag = 1;
    // Draw heading
    if(value==15){
    glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix();
    glTranslatef(-1.0f, 3.2f, -5.0f);
    //drawhead(0, 0, 0,(char*) "H20 Molecular Structure");
    renderBitmapString(0.0f, 0.0f, 0.0f, GLUT_BITMAP_HELVETICA_18, "H2O Molecular Structure");
    glPopMatrix();

    // Draw oxygen atom
    GLfloat oxygen_diffuse[] = { 1.0f, 0.0f, 0.0f, 1.0f };
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, oxygen_diffuse);
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);  // Position of the oxygen atom
    glutSolidSphere(1.0f, 50, 50);  // Sphere representing the oxygen atom
    glColor3f(1.0f, 1.0f, 1.0f);
    renderBitmapString(-0.1f, -1.3f, 0.0f, GLUT_BITMAP_HELVETICA_12, "O");
    glPopMatrix();

    // Draw hydrogen atoms
    GLfloat hydrogen_diffuse[] = { 0.0f, 1.0f, 0.0f, 1.0f };
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, hydrogen_diffuse);
    glPushMatrix();
    glTranslatef(-1.0f, 0.0f, 0.0f);  // Position of the first hydrogen atom
    glutSolidSphere(0.5f, 50, 50);  // Sphere representing the first hydrogen atom
    glColor3f(1.0f, 1.0f, 1.0f);
    renderBitmapString(-0.5f, -0.4f, 0.0f, GLUT_BITMAP_HELVETICA_12, "H");
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.0f, 0.0f, 0.0f);  // Position of the second hydrogen atom
    glutSolidSphere(0.5f, 50, 50);  // Sphere representing the second hydrogen atom
    glColor3f(1.0f, 1.0f, 1.0f);
    renderBitmapString(0.4f, -0.4f, 0.0f, GLUT_BITMAP_HELVETICA_12, "H");
    glPopMatrix();

    char nu[] = "RIGHT CLICK AND SELECT THE ELEMENT USING MENU";
    renderBitmapString(-570, 900, 0,GLUT_BITMAP_HELVETICA_18, nu);
   }

    if (value == 16) {
        glPushMatrix();
        glTranslatef(0.0f, 0.0f, -7.0f);  // Translate to the center for CO

        // Draw heading for CO
        glColor3f(1.0f, 1.0f, 1.0f);
        renderBitmapString(-1.f, 2.3f, 0.0f, GLUT_BITMAP_HELVETICA_18, "CO Molecular Structure");
        

        // Draw carbon atom
        GLfloat carbon_diffuse[] = { 0.0f, 1.0f, 0.0f, 1.0f };
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, carbon_diffuse);
        glPushMatrix();
        glTranslatef(0.0f, 0.0f, 0.0f);  // Position of the carbon atom
        glutSolidSphere(1.0f, 50, 50);  // Sphere representing the carbon atom
        glColor3f(1.0f, 1.0f, 1.0f);
        renderBitmapString(-0.15f, -1.2f, 0.0f, GLUT_BITMAP_HELVETICA_12, "C");
        glPopMatrix();

        // Draw oxygen atom
        GLfloat oxygen_diffuse[] = { 1.0f, 0.0f, 0.0f, 1.0f };
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, oxygen_diffuse);
        glPushMatrix();
        glTranslatef(1.2f, 0.0f, 0.0f);  // Position of the oxygen atom
        glutSolidSphere(0.8f, 50, 50);  // Sphere representing the oxygen atom
        glColor3f(1.0f, 1.0f, 1.0f);
        renderBitmapString(0.5f, -0.8f, 0.0f, GLUT_BITMAP_HELVETICA_12, "O");
        glPopMatrix();

        glPopMatrix();
        
    }

    if (value == 17) {
        glColor3f(1.0f, 1.0f, 1.0f);
        glPushMatrix();
        glTranslatef(-1.0f, 3.0f, -5.0f);
        renderBitmapString(0.0f, 0.0f, 0.0f, GLUT_BITMAP_HELVETICA_18, "CO2 Molecular Structure");
        glPopMatrix();

        // Draw carbon atom
        GLfloat carbon_diffuse[] = { 1.0f, 1.0f, 0.0f, 1.0f };
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, carbon_diffuse);
        glPushMatrix();
        glTranslatef(0.0f, 0.0f, 0.0f);  // Position of the carbon atom
        glutSolidSphere(0.4f, 50, 50);  // Sphere representing the carbon atom
        glColor3f(1.0f, 1.0f, 1.0f);
        renderBitmapString(-0.1f, -0.2f, 0.0f, GLUT_BITMAP_HELVETICA_12, "C");
        glPopMatrix();

        // Draw oxygen atoms
        GLfloat oxygen_diffuse[] = { 1.0f, 0.0f, 0.0f, 1.0f };
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, oxygen_diffuse);
        glPushMatrix();
        glTranslatef(-1.0f, 0.0f, 0.0f);  // Position of the first oxygen atom
        glutSolidSphere(0.7f, 50, 50);  // Sphere representing the first oxygen atom
        glColor3f(1.0f, 1.0f, 1.0f);
        renderBitmapString(-0.4f, -0.7f, 0.0f, GLUT_BITMAP_HELVETICA_12, "O");
        glPopMatrix();

        glPushMatrix();
        glTranslatef(1.0f, 0.0f, 0.0f);  // Position of the second oxygen atom
        glutSolidSphere(0.7f, 50, 50);  // Sphere representing the second oxygen atom
        glColor3f(1.0f, 1.0f, 1.0f);
        renderBitmapString(0.4f, -0.7f, 0.0f, GLUT_BITMAP_HELVETICA_12, "O");
        glPopMatrix();
    }

    glFlush();
    glutSwapBuffers();
    glutDetachMenu(GLUT_RIGHT_BUTTON);
}


void display2()
{
    glClearColor(0, 0, 0.54, 0.9);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if (value == -1)
    {
        reshape_flag = 0;
        char cn[] = "RNSIT INSTITUTE OF TECHNOLOGY";
        drawhead(-490, 900, 0, cn);
        char pn[] = "RR Nagar, Bangalore-560098";
        drawsubhead(-250, 850, 0, pn);

        char dn[] = "DEPARTMENT OF COMPUTER SCIENCE & ENGINEERING";
        drawhead(-690, 650, 0, dn);

        char prn[] = "A Mini Project On";
        drawsubhead(-150, 450, 0, prn);
        char pro[] = "ATOMIC STRUCTURE";
        drawhead(-250, 350, 0, pro);

        char pb[] = "PROJECT BY: ";
        drawhead(-690, -150, 0, pb);

        char p1[] = "ABHISHEK KULKARNI";
        drawhead(-690, -250, 0, p1);
        char p1u[] = "1RN20CS005";
        drawsubhead(-690, -300, 0, p1u);

        char p2[] = "PAVAN KUMAR M";
        drawhead(-690, -400, 0, p2);
        char p2u[] = "1RN20CS191";
        drawsubhead(-690, -450, 0, p2u);

        char gb[] = "GUIDED BY: ";
        drawhead(290, -150, 0, gb);

        char g1[] = "Ms.MAMATHA JAJUR S";
        drawhead(290, -250, 0, g1);
        char d1[] = "Assistant Professor, Dept. Of CSE, RNSIT";
        drawsubhead(290, -300, 0, d1);

        char in[] = "Press enter to Continue";
        drawhead(-250, -700, 0, in);

        glutSwapBuffers();
        glutDetachMenu(GLUT_RIGHT_BUTTON);
    }
    if (value != -1)
    {
        nuc(250);
        char n[] = "NUCLEUS";
        drawString(-70, 20, 0, n);
        char d[] = "(NEUTRON + PROTON)";
        drawString(-185, -30, 0, d);
        if (value == 0)
        {
            char nu[] = "RIGHT CLICK AND SELECT THE ELEMENT USING MENU";
            drawhead(-570, 900, 0, nu);
        }
    }
    if (value == 1)
    {
        reshape_flag = 0;
        char n[] = "HYDROGEN";
        drawhead(-100, 900, 0, n);
        circle(400);
        char o[] = "ORBIT";
        drawString(410, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        char e[] = "ELECTRON";
        drawString(420, 0, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 2)
    {
        reshape_flag = 0;
        char n[] = "HELIUM";
        drawhead(-100, 900, 0, n);
        circle(400);
        char o[] = "ORBIT";
        drawString(410, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        eleleft(400);
        char e[] = "ELECTRON";
        drawString(420, 0, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 3)
    {
        reshape_flag = 0;
        char n[] = "LITHIUM";
        drawhead(-100, 900, 0, n);
        circle(400);
        circle(600);
        char o[] = "ORBIT";
        drawString(610, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        eleleft(400);
        eletop(600);
        char e[] = "ELECTRON";
        drawString(0, 620, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 4)
    {
        reshape_flag = 0;
        char n[] = "BERYLLIUM";
        drawhead(-100, 900, 0, n);
        circle(400);
        circle(600);
        char o[] = "ORBIT";
        drawString(610, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        eleleft(400);
        eletop(600);
        eledown(600);
        char e[] = "ELECTRON";
        drawString(0, 620, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 5)
    {
        reshape_flag = 0;
        char n[] = "BORON";
        drawhead(-100, 900, 0, n);
        circle(400);
        circle(600);
        char o[] = "ORBIT";
        drawString(610, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        eleleft(400);
        eletop(600);
        eledown(600);
        eletr(600);
        char e[] = "ELECTRON";
        drawString(0, 620, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 6)
    {
        reshape_flag = 0;
        char n[] = "CARBON";
        drawhead(-100, 900, 0, n);
        circle(400);
        circle(600);
        char o[] = "ORBIT";
        drawString(610, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        eleleft(400);
        eletop(600);
        eledown(600);
        eletr(600);
        eledl(600);
        char e[] = "ELECTRON";
        drawString(0, 620, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 7)
    {
        reshape_flag = 0;
        char n[] = "NITROGEN";
        drawhead(-100, 900, 0, n);
        circle(400);
        circle(600);
        char o[] = "ORBIT";
        drawString(610, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        eleleft(400);
        eletop(600);
        eledown(600);
        eletr(600);
        eledl(600);
        eletl(600);
        char e[] = "ELECTRON";
        drawString(0, 620, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 8)
    {
        reshape_flag = 0;
        char n[] = "OXYGEN";
        drawhead(-100, 900, 0, n);
        circle(400);
        circle(600);
        char o[] = "ORBIT";
        drawString(610, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        eleleft(400);
        eletop(600);
        eledown(600);
        eletr(600);
        eledl(600);
        eletl(600);
        eledr(600);
        char e[] = "ELECTRON";
        drawString(0, 620, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 9)
    {
        reshape_flag = 0;
        char n[] = "FLUORINE";
        drawhead(-100, 900, 0, n);
        circle(400);
        circle(600);
        char o[] = "ORBIT";
        drawString(610, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        eleleft(400);
        eletop(600);
        eledown(600);
        eletr(600);
        eledl(600);
        eletl(600);
        eledr(600);
        eleleft(600);
        char e[] = "ELECTRON";
        drawString(0, 620, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 10)
    {
        reshape_flag = 0;
        char n[] = "NEON";
        drawhead(-100, 900, 0, n);
        circle(400);
        circle(600);
        char o[] = "ORBIT";
        drawString(610, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        eleleft(400);
        eletop(600);
        eledown(600);
        eletr(600);
        eledl(600);
        eletl(600);
        eledr(600);
        eleleft(600);
        eleright(600);
        char e[] = "ELECTRON";
        drawString(0, 620, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    glutSwapBuffers();
}





void rotate()
{
    angle = angle + 5.0;
    if (angle > 360)
    {
        angle = angle - 360;
    }
    glClear(GL_COLOR_BUFFER_BIT);
    glutPostRedisplay();

}

void mouseControl(int button, int state, int x, int y)
{
    switch (button)
    {
    case GLUT_LEFT_BUTTON:
        if (state == GLUT_DOWN)
            glutIdleFunc(rotate);
        break;
    default:
        break;
    }
}

void keyboard(unsigned char key, int x, int y)
{
    if (key == 13)
    {
        value = 0;
        glClear(GL_COLOR_BUFFER_BIT);
        glutAttachMenu(GLUT_RIGHT_BUTTON);
        glutPostRedisplay();
    }
    else if (key == 's')
    {
        glutIdleFunc(NULL);
    }
    else if (key == 32)
    {
        glutIdleFunc(rotate);
    }
    else if (key == 'q' || key == 'Q')
    {
        exit(0);
    }
    else if (key == 27)
    {
        glutReshapeWindow(700, 700);
    }
}

void fkey(int key, int x, int y)
{

    if (key == GLUT_KEY_F10)
    {
        glutReshapeWindow(glutGet(GLUT_SCREEN_WIDTH), glutGet(GLUT_SCREEN_HEIGHT));
    }
}

void display() {
    if (value >= 15) {
        display1();
    }
    else
        display2();
    glutSwapBuffers();
}

void menu(int option)
{
    if (option == 13)
    {
        exit(0);
    }
    else if (option == 11)
    {
        glutIdleFunc(rotate);
    }
    else if (option == 12)
    {
        glutIdleFunc(NULL);
    }
    else if (option == 14) {
        value = -1;
    }
    else
    {
        value = option;
    }
    glClear(GL_COLOR_BUFFER_BIT);

    glutPostRedisplay();
}

void createMenu(void)
{
    submenu = glutCreateMenu(menu);
    glutAddMenuEntry("HYDROGEN", 1);
    glutAddMenuEntry("HELIUM", 2);
    glutAddMenuEntry("LITHIUM", 3);
    glutAddMenuEntry("BERILIUM", 4);
    glutAddMenuEntry("BORON", 5);
    glutAddMenuEntry("CARBON", 6);
    glutAddMenuEntry("NITROGEN", 7);
    glutAddMenuEntry("OXYGEN", 8);
    glutAddMenuEntry("FLUORINE", 9);
    glutAddMenuEntry("NEON", 10);
    
    submenu2 = glutCreateMenu(menu);
    glutAddMenuEntry("WATER", 15);
    glutAddMenuEntry("CARBONMONOXIDE", 16);
    glutAddMenuEntry("CARBONDIOXIDE", 17);
    mainmenu = glutCreateMenu(menu);
    glutAddSubMenu("SELECT THE ELEMENT", submenu);
    glutAddSubMenu("SELECT THE MOLECULES", submenu2);
    glutAddMenuEntry("START SIMULATION", 11);
    glutAddMenuEntry("STOP SIMULATION", 12);
    glutAddMenuEntry("GOTO HOME SCREEN", 14);
    glutAddMenuEntry("EXIT", 13);

    glutAttachMenu(GLUT_RIGHT_BUTTON);
}



int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(700, 700);
    glutCreateWindow("ATOMIC STRUCTURE");

    glutDisplayFunc(display);

    init();
    glutMouseFunc(mouseControl);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(fkey);
    createMenu();
    glutMainLoop();
}
