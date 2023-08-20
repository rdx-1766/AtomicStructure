#include <GL/glut.h>

// Atom properties
struct Atom {
    float x;
    float y;
    float red;
    float green;
    float blue;
    int numElectrons;
    bool electronTransferred;
};

Atom atomA;
Atom atomB;

void initAtoms() {
    // Initialize atom A properties
    atomA.x = -0.5;
    atomA.y = 0.0;
    atomA.red = 1.0;
    atomA.green = 0.0;
    atomA.blue = 0.0;
    atomA.numElectrons = 8;
    atomA.electronTransferred = false;

    // Initialize atom B properties
    atomB.x = 0.5;
    atomB.y = 0.0;
    atomB.red = 0.0;
    atomB.green = 0.0;
    atomB.blue = 1.0;
    atomB.numElectrons = 8;
    atomB.electronTransferred = false;
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw atom A
    glPushMatrix();
    glTranslatef(atomA.x, atomA.y, 0.0);
    glColor3f(atomA.red, atomA.green, atomA.blue);
    glutSolidSphere(0.2, 20, 20);
    glPopMatrix();

    // Draw atom B
    glPushMatrix();
    glTranslatef(atomB.x, atomB.y, 0.0);
    glColor3f(atomB.red, atomB.green, atomB.blue);
    glutSolidSphere(0.2, 20, 20);
    glPopMatrix();

    // Draw bond if electron transferred
    if (atomA.electronTransferred && atomB.electronTransferred) {
        glBegin(GL_LINES);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2f(atomA.x, atomA.y);
        glVertex2f(atomB.x, atomB.y);
        glEnd();
    }

    glFlush();
}

void keyboard(unsigned char key, int x, int y) {
    if (key == 'b' && !atomA.electronTransferred && !atomB.electronTransferred) {
        // Transfer electron from atom A to atom B
        atomA.numElectrons--;
        atomB.numElectrons++;
        atomA.electronTransferred = true;
        atomB.electronTransferred = true;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Electron Transfer and Bond Formation");

    glClearColor(0.0, 0.0, 0.0, 1.0);

    initAtoms();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    glutMainLoop();

    return 0;
}
