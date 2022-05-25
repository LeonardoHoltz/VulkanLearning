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
#include <optional>

class HelloTriangleApplication {
public:
	void run();

private:

	/* === CONSTANTS === */

	const uint32_t WIDTH = 1280;
	const uint32_t HEIGHT = 720;

	const std::vector<const char*> validationLayers = { "VK_LAYER_KHRONOS_validation" };
	const std::vector<const char*> deviceExtensions = { VK_KHR_SWAPCHAIN_EXTENSION_NAME };

#ifdef NDEBUG
	const bool enableValidationLayers = false;
#else
	const bool enableValidationLayers = true;
#endif

	/* === STRUCTURES === */
	struct QueueFamilyIndices {
		std::optional<uint32_t> graphicsFamily;
		std::optional<uint32_t> presentFamily;

		bool hasGraphicQueue() {
			return graphicsFamily.has_value();
		}

		bool hasPresentationQueue() {
			return presentFamily.has_value();
		}
	};

	struct SwapChainSupportDetails {
		VkSurfaceCapabilitiesKHR capabilities;
		std::vector<VkSurfaceFormatKHR> formats;
		std::vector<VkPresentModeKHR> presentModes;
	};

	/* === CLASS MEMBERS === */

	GLFWwindow* window = nullptr;

	VkInstance instance;

	VkDebugUtilsMessengerEXT debugMessenger;

	VkSurfaceKHR surface;

	VkPhysicalDevice physicalDevice = VK_NULL_HANDLE; // implicity destroyed when VkInstance is destroyed.

	VkDevice device;

	VkQueue graphicsQueue; // implicity destroyed when VkDevice is destroyed.

	VkQueue presentQueue;

	VkSwapchainKHR swapChain;

	std::vector<VkImage> swapChainImages; // implicity destroyed when VkSwapChainKHR is destroyed.

	VkFormat swapChainImageFormat;
	VkExtent2D swapChainExtent;

	std::vector<VkImageView> swapChainImageViews;

	/* === FUNCTIONS === */

	/* =========== Main logic =========== */
	void initWindow();
	void initVulkan();
	void mainLoop();
	void cleanup();

	/* =========== Vulkan instance =========== */
	void createInstance();
	VkResult checkExtensions();
	bool checkValidationLayerSupport();
	std::vector<const char*> getRequiredExtensions();

	/* =========== Surface =========== */
	void createSurface();

	/* =========== Swap chain =========== */
	SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);
	VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
	VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
	VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);
	void createSwapChain();

	/* =========== Image views =========== */
	void createImageViews();

	/* =========== Physical device =========== */
	void pickPhysicalDevice();
	int rateDeviceSuitability(VkPhysicalDevice device);
	bool checkDeviceExtensionSupport(VkPhysicalDevice device);

	/* =========== Logical device =========== */
	void createLogicalDevice();

	/* =========== Queues =========== */

	/* Find at least one queue for graphic commands */
	QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);

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