from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMake, cmake_layout, CMakeDeps


class pkgRecipe(ConanFile):
    name = "keyhit"
    version = "0.1"
    package_type = "application"

    # Optional metadata
    license = "<Put the package license here>"
    author = "Sumit Kumar", "ravirajkarn21@gmail.com"
    url = "<Package recipe repository url here, for issues about the package>"
    description = "demonstration and study of different type keyboard input."
    topics = ("input", "keyboard", "C++", "Console")

    # Binary configuration
    settings = "os", "compiler", "build_type", "arch"

    # Sources are located in the same place as this recipe, copy them to the recipe
    exports_sources = "CMakeLists.txt", "src/*"

    # cspell: ignore gtest ncurses
    def requirements(self):
        self.requires("fmt/11.1.4")
        self.requires("gtest/1.16.0")
        self.requires("ncurses/6.5")

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