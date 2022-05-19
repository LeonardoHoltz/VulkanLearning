// HelloTriangleApplication.h
#ifndef HELLO_TRIANGLE_APPLICATION_H
#define HELLO_TRIANGLE_APPLICATION_H

// GLFW will include its own definitions and automatically load the Vulkan header with it.
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <cstring>

#include <vector>

class HelloTriangleApplication {
public:
	void run();

private:

	/* === CONSTANTS === */

	const uint32_t WIDTH = 1280;
	const uint32_t HEIGHT = 720;

	const std::vector<const char*> validationLayers = { "VK_LAYER_KHRONOS_validation" };

#ifdef NDEBUG
	const bool enableValidationLayers = false;
#else
	const bool enableValidationLayers = true;
#endif

	/* === VARIABLES === */

	GLFWwindow* window = nullptr;

	VkInstance instance;

	VkDebugUtilsMessengerEXT debugMessenger;

	VkPhysicalDevice physicalDevice = VK_NULL_HANDLE; // implicity destroyed when VkInstance is destroyed.

	/* === FUNCTIONS === */

	/* Main logic */
	void initWindow();
	void initVulkan();
	void mainLoop();
	void cleanup();

	/* Vulkan instance */
	void createInstance();
	VkResult checkExtensions();
	bool checkValidationLayerSupport();
	std::vector<const char*> getRequiredExtensions();

	/* Physical device*/
	void pickPhysicalDevice();
	bool isDeviceSuitable(VkPhysicalDevice device);

	/* Debug */

	void setupDebugMessenger();
	void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);

	static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
		VkDebugUtilsMessageTypeFlagsEXT messageType,
		const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
		void* pUserData);
};

#endif /* HELLO_TRIANGLE_APPLICATION_H */

VkResult CreateDebugUtilsMessengerEXT(VkInstance instance, const
	VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const
	VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT*
	pDebugMessenger);

void DestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger, const VkAllocationCallbacks* pAllocator);