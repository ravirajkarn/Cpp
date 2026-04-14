from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMake, cmake_layout, CMakeDeps


class pkgRecipe(ConanFile):
    name = "Loading Research"
    version = "0.1"
    package_type = "application"

    # Optional metadata
    license = "<none>"
    author = "Sumit Kumar ravirajkarn21@gmail.com"
    url = "<none>"
    description = "project to learn loading animation for terminal applications"
    topics = ("terminal", "loading", "animation")

    # Binary configuration  
    settings = "os", "compiler", "build_type", "arch"

    # Sources are located in the same place as this recipe, copy them to the recipe
    exports_sources = "CMakeLists.txt", "src/*"

    def requirements(self):
        self.requires("fmt/11.1.4")
        self.requires("indicators/2.3")

    def layout(self):
        cmake_layout(self)

    def generate(self):
        deps = CMakeDeps(self)
        deps.generate()
        tc = CMakeToolchain(self)
        tc.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.install()

    

    
