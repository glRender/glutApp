#include <GL/glew.h>
#include <GL/freeglut.h>

#include "glRender.h"

static const int WINDOW_WIDTH = 1024;
static const int WINDOW_HEIGHT = 800;

using namespace glRender;

Model * model0;
Model * model1;

Camera * camera;
Vec3 cameraPos;

Scene * scene;

float scale = 1.0;

void init ()
{
    glClearColor ( 0.5, 0.5, 0.5, 1.0111 );
    glEnable     ( GL_DEPTH_TEST );
    glDepthFunc  ( GL_LEQUAL );
}

void idle()
{
     scene->update();

    glutPostRedisplay();

}

 void display ()
 {
     glClearColor ( 0.5, 0.5, 0.5, 1.0 );
     glEnable     ( GL_DEPTH_TEST );
     glDepthFunc  ( GL_LEQUAL );
     glClear      ( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

      scene->draw();

     glutSwapBuffers ();

 }

 void reshape ( int w, int h )
 {
     glViewport ( 0, 0, (GLsizei)w, (GLsizei)h );
 }

 // void key ( unsigned char key, int x, int y )
 // {
 // //     if ( key == 27 || key == 'q' || key == 'Q' )    //  quit requested
 // //         exit ( 0 );

 //     float cameraSpeed = 0.1f;

 //     // w
 //     if(key == 'w')
 //     {
 //         camera->translate( cameraSpeed * -Vec3::AXE_Z() );
 //         std::cout << "w" << std::endl;

 //     }

 //     // s
 //     if(key == 's')
 //     {
 //         camera->translate( cameraSpeed * Vec3::AXE_Z() );
 //         std::cout << "s" << std::endl;
 //     }

 //     // a
 //     if(key == 'a')
 //     {
 //         camera->translate( cameraSpeed * -Vec3::AXE_X() );
 //         std::cout << "a" << std::endl;
 //     }

 //     // d
 //     if(key == 'd')
 //     {
 //         camera->translate( cameraSpeed * Vec3::AXE_X() );
 //         std::cout << "d" << std::endl;
 //     }

 //     // q
 //     if(key == 'q')
 //     {
 //         camera->rotate( -45, Vec3::AXE_Y() );

 //         std::cout << 'q' << std::endl;
 //     }

 //     // e
 //     if(key == 'e')
 //     {
 //         camera->rotate( 45, Vec3::AXE_Y() );
 //         std::cout << "e" << std::endl;
 //     }

 //     // r
 //     if(key == 'r')
 //     {
 //         camera->rotate( -45, Vec3::AXE_X() );
 //         std::cout << "r" << std::endl;
 //     }

 //     // f
 //     if(key == 'f')
 //     {
 //         camera->rotate( 45, Vec3::AXE_X() );
 //         std::cout << "f" << std::endl;
 //     }


 //     std::cout << "camera->position()" << camera->position() << std::endl;

 //     std::cout << "camera->up       " << camera->up() << std::endl;
 //     std::cout << "camera->front    " << camera->front() << std::endl;
 //     std::cout << "camera->right    " << camera->right() << std::endl;

 // //    std::cout << "camera->upOrig       " << camera->upOrig() << std::endl;
 // //    std::cout << "camera->frontOrig    " << camera->frontOrig() << std::endl;
 // //    std::cout << "camera->rightOrig    " << camera->rightOrig() << std::endl;

 // //    std::cout << "camera->modelViewMatrix()  " << std::endl << camera->modelViewMatrix() << std::endl;
 // //    std::cout << "camera->projectionMatrix() " << std::endl << camera->projectionMatrix() << std::endl;

 //     glutPostRedisplay();
 // }

// void mouse(int button, int state, int x, int y)
// {
//     // Wheel reports as button 3(scroll up) and button 4(scroll down)
//     if ((button == 3) || (button == 4)) // It's a wheel event
//     {
//         // Each wheel event reports like a button click, GLUT_DOWN then GLUT_UP
//         if (state == GLUT_UP) return; // Disregard redundant GLUT_UP events
// //        printf("Scroll %s At %d %d\n", (button == 3) ? "Up" : "Down", x, y);
//         // std::cout << "mouseWheel" << std::endl;
//         if ( button == 3 )
//         {
//             printf("Up!\n");
//             scale += 0.05;
//         }
//         else
//         {
//             printf("Down!\n");
//             scale -= 0.05;
//         }

//         model1->shaderProgram()->setUniform1f("angle", scale);

//     }
//     else
//     {  // normal button event
//         printf("Button %s At %d %d\n", (state == GLUT_DOWN) ? "Down" : "Up", x, y);
//         if ( state == GLUT_DOWN )
//         {
//         }
//     }

//     glutPostRedisplay();

// };

 class MyModel : public NodeModel
 {
 public:
     MyModel(Model * model) :
         NodeModel(model)
     {

     }

     void update() override
     {
         // model()->translate(0.01, 0.0, 0.0);
     }

 };

 class MyCamera : public NodeCamera
 {
 public:
     MyCamera(Camera * camera) :
         NodeCamera(camera)
     {

     }

     void draw(Camera * camera) override
     {

     }

     void update() override
     {
//         camera()->translate(0.0, 0.0, 0.5);

//         Vec3 p = camera()->position();
//
//         camera()->translate(-p);
//         camera()->rotate( -7, Vec3::AXE_Y() );
//         camera()->rotate( -7, Vec3::AXE_Z() );
//         camera()->translate(p);


     }

 };

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
     glutCreateWindow ( "GL 3.3 demo" );

     glewExperimental = GL_TRUE;

     glewInit ();

     if ( !GLEW_VERSION_3_3 )
     {
         printf ( "OpenGL 3.3 not supported.\n" );

         return 1;
     }

     // print context information
     printf ("**************************\n");
     printf ("Vendor: %s\n", glGetString (GL_VENDOR));
     printf ("Renderer: %s\n", glGetString (GL_RENDERER));
     printf ("Version: %s\n", glGetString (GL_VERSION));
     printf ("GLSL: %s\n", glGetString (GL_SHADING_LANGUAGE_VERSION));
     printf ("**************************\n");

     // register handlers
     glutDisplayFunc    ( display );
     glutReshapeFunc    ( reshape );
     // glutKeyboardFunc   ( key     );
//     glutMouseFunc      ( mouse   );
     glutIdleFunc       ( idle    );

     if ( !GL_ARB_vertex_array_object )
         printf ( "No VAO support\n" );
         exit;

    ////////////////////////////////////////////////////////////////////////////////////////////


    Geometry * geometry0 = GeometryHelper::Cube(0.5);

    ShaderProgram * shaderProgram0 = new ShaderProgram("data/shader0.vertex", "data/shader0.frag");
    shaderProgram0->setAttribute( "vertex", AttributeType::XYZ);
    shaderProgram0->setAttribute( "uv", AttributeType::UV);

      Textures * textures0 = new Textures();
      textures0->setTexture( "texture0", new Texture("data/a.png") );
      textures0->setTexture( "texture1", new Texture("data/a.png") );

      model0 = new Model(geometry0, textures0, shaderProgram0);
      model0->setWireframeMode(false);
      model0->setPosition(0.0, 0.0, 0.0);
      std::cout << "model0->position " << model0->position() << std::endl;

 //     /////////////////////////////////////////////////////////////////////////////////////////////

      camera = new PerspectiveCamera( 90.0 / 180.0 * MATH_PI, (float)WINDOW_WIDTH / (float)WINDOW_HEIGHT, 0.01f, 200.0f );
  //    camera->lookAt(Vec3(0,0,5), Vec3(0,0,0), Vec3(0,1,0));
  //    cameraPos = Vec3(0,0,5);

      scene = new Scene();
      scene->setActiveCamera(camera);

      MyCamera * nc = new MyCamera(camera);
      scene->addNode(nc);

      MyModel * n0 = new MyModel(model0);
      scene->addNode(n0);

      srand( time(0) );

      for (int i=0; i<5000; i++)
      {
          model1 = new Model(GeometryHelper::Cube( (rand() % 10) / 10.0), textures0, shaderProgram0);
          model1->setWireframeMode(true);
          model1->setPosition( (-5.0 + rand() % 50), (-5.0 + rand() % 50), (-5.0 + rand() % 50) );

          MyModel * n = new MyModel(model1);

          scene->addNode(n);
      }

     //////////////////////////////////////////////////////////////////////////////////////////////

     glutMainLoop ();

    return 0;
}