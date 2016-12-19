#include <GL/freeglut.h>

#include "glRender.h"

#include "Mark.hpp"
#include "WoodenBox.hpp"
#include "BrickBox.hpp"
#include "QuadraticBezeirCurve.hpp"
#include "Line.hpp"

static const int WINDOW_WIDTH = 1024;
static const int WINDOW_HEIGHT = 800;

using namespace glRender;

Camera * camera;

Mark * np;
Mark * fp;
Line * l;

Scene * scene;

NodePicker * nodePicker;

void init ()
{
    camera = new PerspectiveCamera( 90.0 / 180.0 * MATH_PI, 16.0f/9.0f, 1.0f, 200.0f );
    camera->lookAt(Vec3(0,0,0), Vec3(0,0,-10), Vec3::AXE_Y());
//    camera->lookAt(Vec3(-10,0,-10), Vec3(10,0,-10), Vec3::AXE_Y());

    scene = new Scene();
    scene->setActiveCamera(camera);

    nodePicker = new NodePicker(camera, scene);

    srand( time(0) );

    for (int i=0; i<1000; i++)
    {
//        if ((int)(rand() % 5) == 0)
//        {
//                 WoodenBox *n = new WoodenBox();
//                 n->model()->setOrigin( ((rand() % 50)) - 25, ((rand() % 50)) - 25, ((rand() % 50) - 25) );
//                 n->model()->setWireframeMode(false);
//                 scene->addNode(n);

//        } else
//        if ((int)(rand() % 3) == 1)
//        {
//            qDebug() << "1";
//                 BrickBox *bb = new BrickBox();
//                 bb->model()->setWireframeMode(false);
//     //            bb->model()->setOrigin( ((rand() % 50)) - 25, ((rand() % 50)) - 25, ((rand() % 50) - 25) );
//                 bb->model()->setOrigin(Vec3(1,0, -3));

//                 scene->addNode(bb);

//        } else
//        if ((int)(rand() % 3) == 0)
//        {
//            qDebug() << "0";

//                 Mark * m = new Mark(0,1,0,1);
//                 m->model()->setWireframeMode(false);
//                 m->setOrigin(Vec3(((rand() % 50)) - 25, ((rand() % 50)) - 25, 0));
////                 m->setOrigin(Vec3(0,0, -3));

//                 scene->addNode(m);

//        }
//        else
//        if ((int)(rand() % 3) == 1)
//        {
            Vec3 p0 = Vec3(((rand() % 50)) - 25, ((rand() % 50)) - 25, ((rand() % 50) - 25));
            Vec3 p1 = Vec3(((rand() % 50)) - 25, ((rand() % 50)) - 25, ((rand() % 50) - 25));

            float r = (rand() % 255) / 255.0;
            float g = (rand() % 255) / 255.0;
            float b = (rand() % 255) / 255.0;

            Line * l = new Line(p0, p1, 350, r, g, b);
////            l->setOrigin(Vec3(((rand() % 50)) - 25, ((rand() % 50)) - 25, ((rand() % 50) - 25)));
            l->setOrigin(Vec3(0,0, -3));

            scene->addNode(l);

//        }
//              else
//             if ((int)(rand() % 5) == 4)
//             {
//            Vec3 p0 = Vec3(((rand() % 50)) - 25, ((rand() % 50)) - 25, ((rand() % 50) - 25));
//            Vec3 p1 = Vec3(((rand() % 50)) - 25, ((rand() % 50)) - 25, ((rand() % 50) - 25));
//            Vec3 p2 = Vec3(((rand() % 50)) - 25, ((rand() % 50)) - 25, ((rand() % 50) - 25));
//
//            float r = (rand() % 255) / 255.0;
//            float g = (rand() % 255) / 255.0;
//            float b = (rand() % 255) / 255.0;
//
//            QuadraticBezeirCurve * l = new QuadraticBezeirCurve(p0, p1, p2, 512, r, g, b);
//            scene->addNode(l);
//             }
    }

}

void idle()
{
//    scene->update();
//    glutPostRedisplay();
}

void display ()
{
    Render::draw(scene);
    glutSwapBuffers ();
}

void reshape ( int w, int h )
{
    Render::setViewPortSize(w, h);
}

void key ( unsigned char key, int x, int y )
{
    if ( key == 27 )    //  quit requested
        exit ( 0 );

    float cameraMoveSpeed = 0.3f;
    float cameraRotationSpeed = 5.0f;

    // w
    if(key == 'w')
    {
        camera->setPosition( camera->position() + camera->front() * cameraMoveSpeed );
        std::cout << "w" << std::endl;

    }

    // s
    if(key == 's')
    {
        camera->setPosition( camera->position() - camera->front() * cameraMoveSpeed );
        std::cout << "s" << std::endl;
    }

    // a
    if(key == 'a')
    {
        camera->setPosition( camera->position() - camera->right() * cameraMoveSpeed );
        std::cout << "a" << std::endl;
    }

    // d
    if(key == 'd')
    {
        camera->setPosition( camera->position() + camera->right() * cameraMoveSpeed );
        std::cout << "d" << std::endl;
    }

    // q
    if(key == 'q')
    {
        camera->setEulerAngles( camera->pitch(), camera->yaw() + cameraRotationSpeed, camera->roll() );
        std::cout << 'q' << std::endl;
    }

    // e
    if(key == 'e')
    {
        camera->setEulerAngles( camera->pitch(), camera->yaw() - cameraRotationSpeed, camera->roll() );
        std::cout << "e" << std::endl;
    }

    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
    Vec2 normDeviceCoords(
        2.0f * (float)x / WINDOW_WIDTH - 1.0f,
        1.0f - 2.0f * (float)y / WINDOW_HEIGHT );

    std::vector<Mark *> selectedMarks = nodePicker->find<Mark>(normDeviceCoords);
    if (selectedMarks.size() > 0)
    {
        for (Mark * m : selectedMarks)
        {
            m->changeColor();
        }
        std::cout << "Has intersection!" << std::endl;
    }

    glutPostRedisplay();

}

int main ( int argc, char * argv [] )
{
    // initialize glut
    glutInit            ( &argc, argv );
    glutInitDisplayMode ( GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
    glutInitWindowSize  ( WINDOW_WIDTH, WINDOW_HEIGHT );

    // prepare context for 3.3
    glutInitContextVersion ( 3, 3 );
    glutInitContextFlags   ( GLUT_FORWARD_COMPATIBLE | GLUT_DEBUG );
    glutInitContextProfile ( GLUT_CORE_PROFILE );

    // create window
    glutCreateWindow ( "GLUT application, which use glRender" );

    if (!Render::glLoad())
    {
        exit(3);
    }

    printf("%s\n\n", Render::contextInformation());

    // register handlers
    glutDisplayFunc    ( display );
    glutReshapeFunc    ( reshape );
    glutKeyboardFunc   ( key     );
    glutMouseFunc      ( mouse   );
    glutIdleFunc       ( idle    );

    init();

    glutMainLoop ();

    return 0;
}
