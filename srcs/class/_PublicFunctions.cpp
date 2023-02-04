/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _PublicFunctions.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dracken24 <dracken24@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:55:55 by dracken24         #+#    #+#             */
/*   Updated: 2023/02/04 18:11:43 by dracken24        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/class/_ProgramGestion.hpp"

extern ProgramGestion app;

//******************************************************************************************************//
//												Init										    		//
//******************************************************************************************************//

void	ProgramGestion::initVariables(int argc, char **argv)
{
	_deltaTime = 0.0f;
	
	app._translate.x = 0.0f;
	app._translate.y = 0.0f;
	app._translate.z = 0.0f;
	app._rotate.x = 0.0f;
	app._rotate.y = 0.0f;
	app._rotate.z = 0.0f;

	app._scale.x = 1.0f;
	app._scale.y = 1.0f;
	app._scale.z = 1.0f;

	MODEL_PATH = argv[1];
	TEXTURE_PATH = argv[2];
}

//******************************************************************************************************//
//										 	Gestion GPU								  		    		//
//******************************************************************************************************//

void	resetTransform(void)
{
	app._translate.x = 0.0f;
	app._translate.y = 0.0f;
	app._translate.z = 0.0f;
	app._rotate.x = 0.0f;
	app._rotate.y = 0.0f;
	app._rotate.z = 0.0f;

	app._scale.x = 1.0f;
	app._scale.y = 1.0f;
	app._scale.z = 1.0f;
}

void	onKeyPress(void)
{
	// Rotate //
	if (app._a == 1)
		app._rotate.x -= 2.0f;
	if (app._d == 1)
		app._rotate.x += 2.0f;
		
	if (app._w == 1)
		app._rotate.y -= 2.0f;
	if (app._s == 1)
		app._rotate.y += 2.0f;
		
	if (app._q == 1)
		app._rotate.z -= 2.0f;
	if (app._e == 1)
		app._rotate.z += 2.0f;

	// Translate //
	if (app._up == 1)
		app._translate.z += 0.1f;
	if (app._down == 1)
		app._translate.z -= 0.1f;
		
	if (app._left == 1)
	{
		app._translate.x += 0.1f;
		app._translate.y -= 0.1f;
	}
	if (app._right == 1)
	{
		app._translate.x -= 0.1f;
		app._translate.y += 0.1f;
	}

	// Reset //
	if (app._space == 1)
		resetTransform();
}

void	key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	// std::cout << "Key pressed: " << key << std::endl;
	
	switch (key)
	{
		// Rotate //	
		case GLFW_KEY_A:
			if (action == GLFW_PRESS)
				app._a = 1;
			else if (action == GLFW_RELEASE)
				app._a = 0;
			break;
		case GLFW_KEY_D:
			if (action == GLFW_PRESS)
				app._d = 1;
			else if (action == GLFW_RELEASE)
				app._d = 0;
			break;
			
		case GLFW_KEY_W:
			if (action == GLFW_PRESS)
				app._w = 1;
			else if (action == GLFW_RELEASE)
				app._w = 0;
			break;
		case GLFW_KEY_S:
			if (action == GLFW_PRESS)
				app._s = 1;
			else if (action == GLFW_RELEASE)
				app._s = 0;
			break;
			
		case GLFW_KEY_Q:
			if (action == GLFW_PRESS)
				app._q = 1;
			else if (action == GLFW_RELEASE)
				app._q = 0;
			break;
		case GLFW_KEY_E:
			if (action == GLFW_PRESS)
				app._e = 1;
			else if (action == GLFW_RELEASE)
				app._e = 0;
			break;
			
		// Translate //	
		case GLFW_KEY_UP:
			if (action == GLFW_PRESS)
				app._up = 1;
			else if (action == GLFW_RELEASE)
				app._up = 0;
			break;
		case GLFW_KEY_DOWN:
			if (action == GLFW_PRESS)
				app._down = 1;
			else if (action == GLFW_RELEASE)
				app._down = 0;
			break;
			
		case GLFW_KEY_LEFT:
			if (action == GLFW_PRESS)
				app._left = 1;
			else if (action == GLFW_RELEASE)
				app._left = 0;
			break;
		case GLFW_KEY_RIGHT:
			if (action == GLFW_PRESS)
				app._right = 1;
			else if (action == GLFW_RELEASE)
				app._right = 0;
			break;

		// Reset //
		case GLFW_KEY_SPACE:
			if (action == GLFW_PRESS)
				app._space = 1;
			else if (action == GLFW_RELEASE)
				app._space = 0;
			break;

		// Exit //
		case GLFW_KEY_ESCAPE:
			if (action == GLFW_PRESS)
				app._quit = false;
			break;
	}
}

void	mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	// std::cout << "Mouse button pressed: " << button << std::endl;
	// std::cout << "Mouse button action : " << action << std::endl;
	// std::cout << "Mouse button mods   : " << mods << std::endl;
	
	switch (button)
	{
		case GLFW_MOUSE_BUTTON_LEFT:
			if (action == GLFW_PRESS)
				app._mouseLeft = 1;
			else if (action == GLFW_RELEASE)
				app._mouseLeft = 0;
			break;
		case GLFW_MOUSE_BUTTON_RIGHT:
			if (action == GLFW_PRESS)
				app._mouseRight = 1;
			else if (action == GLFW_RELEASE)
				app._mouseRight = 0;
			break;
		case GLFW_MOUSE_BUTTON_MIDDLE:
			if (action == GLFW_MOUSE_BUTTON_MIDDLE)
				app._mouseMiddle = 1;
			else if (action == GLFW_RELEASE)
				app._mouseMiddle = 0;
			break;
	}
	std::cout << std::endl;
}

void	scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	// std::cout << "Scroll xoffset: " << xoffset << std::endl;
	// std::cout << "Scroll yoffset: " << yoffset << std::endl;

	if (yoffset == 1)
	{
		app._scale.x += 0.1f;
		app._scale.y += 0.1f;
		app._scale.z += 0.1f;
	}
	else if (yoffset == -1)
	{
		app._scale.x -= 0.1f;
		app._scale.y -= 0.1f;
		app._scale.z -= 0.1f;
	}
}

int	keyPress(GLFWwindow *window)
{
	glfwSetKeyCallback(window, key_callback);	                // Key Hook //
	glfwSetMouseButtonCallback(window, mouse_button_callback);	// Mouse Hook //;
	glfwSetScrollCallback(window, scroll_callback);	            // Scroll Hook //;
	
	return (0);
}

void	drop_callback(GLFWwindow* window, int count, const char** paths)
{
    ProgramGestion::Texture2D   texture;
    
    std::cout << "Dropped " << count << std::endl;
    for (int i = 0; i < count; i++)
    {
        // std::cout << "Dropped file: " << paths[i] << std::endl;
        if (strrchr(paths[i], '.') != NULL)
        {
            if (strcmp(strrchr(paths[i], '.'), ".obj") == 0)
            {
                texture.objPath = paths[i];
                texture.objName = strrchr(paths[i], '/');
            }
            else if (strcmp(strrchr(paths[i], '.'), ".png") == 0)
            {
                texture.imgPath = paths[i];
                texture.imgName = strrchr(paths[i], '/');
                texture.imgType = "png";
                texture.imgSize = app.getImgSize(paths[i]);
            }
            else if (strcmp(strrchr(paths[i], '.'), ".jpg") == 0)
            {
                texture.imgPath = paths[i];
                texture.imgName = strrchr(paths[i], '/');
                texture.imgType = "jpg";
                texture.imgSize = app.getImgSize(paths[i]);
            }
            if (texture.objPath != "" && texture.imgPath != "")
            {
                app._objs.push_back(texture);
            }
        }
        else
            std::cout << "Error: File type not supported" << std::endl;
    }
    if (app._objs.size() > 0)
    {
        for (int i = 0; i < app._objs.size(); i++)
        {
            std::cout << "\nDropped Obj Name  : " << app._objs[i].objName << std::endl;
            std::cout << "Dropped Obj Path  : " << app._objs[i].objPath << std::endl;
            std::cout << "Dropped Img Name  : " << app._objs[i].imgName << std::endl;
            std::cout << "Dropped Img Path  : " << app._objs[i].imgPath << std::endl;
            std::cout << "Dropped Img Type  : " << app._objs[i].imgType << std::endl;
            std::cout << "Dropped Img Width : " << app._objs[i].imgSize.x << std::endl;
            std::cout << "Dropped Img Height: " << app._objs[i].imgSize.y << std::endl << std::endl;
        }
    }
}
