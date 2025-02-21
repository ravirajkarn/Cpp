from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMake, cmake_layout, CMakeDeps

# How this recipe is working.

# 1. The recipe is a Python class that inherits from ConanFile.(basically whose kitchen is this. mine or yours. this is a conan's kitchen)
class pkgRecipe(ConanFile):

    # 2. The recipe has a series of attributes that define the package.(imagine the end food. such that is name, smell etc.)
        name = "storedate"
        version = "0.1"
        package_type = "application"

        # Optional metadata
        license = "<Put the package license here>"
        author = "<Ravirajkarn><ravirajkarn21@gmail.com>"
        url = "non"
        description = "file to test to store date"
        topics = ("date")

    # 3. which type of food is going to be prepared. I mean, is it a human food or animal food.
        # Binary configuration
        settings = "os", "compiler", "build_type", "arch"

    # 4. ingredient's need to purchase to prepare the food. 
        # No build required
        def requirements(self):
            self.requires("fmt/11.1.3")

    # 5. Sources are located in the same place as this recipe, copy them to the recipe (ingredients from the freezer)
        exports_sources = "CMakeLists.txt", "src/*"
    	
    # 6. Calling the chef to prepare the food.
        def build(self):
            cmake = CMake(self.settings)
            cmake.configure()  # Missing cmake.configure() and cmake.build(): You have these lines commented out. When using the CMake helper from conan.tools.cmake, it's generally recommended to use cmake.configure() and cmake.build() instead of calling self.run() directly. These methods handle the configuration and build steps in a more Conan-integrated way.
            cmake.build()
            # self.run("cmake storedate %S" % (cmake.build_config))
            # self.run("cmake --build . %S" % (cmake.build_config))
    
    # 7. explaining the chef to prepare the food.
        def generate(self):
            deps = CMakeDeps(self)
            deps.generate()
            tc = CMakeToolchain(self)
            tc.generate()

    # 8. The food is ready to serve.i.e. food is kept on the different plates.
        def package(self):
            self.copy("*.h", dst="include", src="src")
            self.copy("*.lib", dst="lib", keep_path=False)
            self.copy("*.dll", dst="bin", keep_path=False)
            self.copy("*.a", dst="lib", keep_path=False)
    
    # 9. giving the final information about the food. i.e. is it overcooked or undercooked or else.
        def package_info(self):
            self.cpp_info.libs = ["storedate.cpp"]
    
    # I don't now what this function is doing.
        def package(self):
            cmake = CMake(self)
            cmake.install()

        def layout(self):
            cmake_layout(self)
            


    

    
