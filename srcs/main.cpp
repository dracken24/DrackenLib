/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 22:14:08 by dracken24         #+#    #+#             */
/*   Updated: 2023/02/03 20:37:52 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/class/_ProgramGestion.hpp"

// #define STB_IMAGE_IMPLEMENTATION

ProgramGestion app;

void	key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	// std::cout << "Key pressed: " << key << std::endl;
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		app._quit = false;
	}
}

int	keyPress(GLFWwindow *window)
{
	glfwSetKeyCallback(window, key_callback);	// Key Hook //
	
	return (0);
}

void mainLoop()
{
	while (app._quit == true && glfwWindowShouldClose(app.window) != true)
	{
		glfwPollEvents();

		keyPress(app.window);
		
		app.drawFrame();
        
        app.useFPS();
	}
}

int		main(void)
{
    // ProgramGestion app;

    try 
	{
        app.init("BANKAI");
    }
	catch (const std::exception& e)
	{
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    app.setFPS(60);

    mainLoop();
    
    app.cleanup();

    return EXIT_SUCCESS;
}
