#include <iostream>
#include<GL/glew.h>
#include <GLFW/glfw3.h>

// GLEW is the library helps us point to the opengl functions 


int main()
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);


    if (glewInit() != GLEW_OK)
        std::cout << "Error!" << std::endl;
    
    std::cout << glGetString(GL_VERSION) << std::endl;

    //OPENGL is state based 
    float positions[6] = { -0.5f, -0.5f  , 0.0f , 0.5f , 0.5f . - 0.5f };
    // TRIANGLE VERTEX BUFFER 
    unsigned int buffer; 
    glGenBuffers(1, &buffer); 
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);

    // Layout of the buffer -- how the buffer is represented for the required the thing 
    // Attributes 



    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        // legacy opengl to create a triangle 
        //glBegin(GL_TRIANGLES);
        //glVertex2f(-0.5f, -0.5f);
        //glVertex2f(0.5f, -0.5f);
        //glVertex2f(0.5f, 0.5f);
        //glEnd();


        glDrawArrays( GL_TRIANGLES , 0 , 3);
        // glDrawElements(GL_TRIANGLES, 3, );


        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;

}