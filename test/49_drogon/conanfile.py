from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMake, cmake_layout, CMakeDeps
from conan.tools.env import VirtualRunEnv


class ConanDrogon(ConanFile):
    name = "ConanDrogon"
    version = "0.1"
    package_type = "application"

    # Optional metadata
    license = "<Non>"
    author = "Sumit Kumar(ravirajkarn21@gmail.com)"
    url = "<non>"
    description = "test project conan and drogon together and first drogon project."
    topics = ("Drogon", "Conan", "Cpp", "WebApplication", "CSS")

    # Binary configuration
    settings = "os", "compiler", "build_type", "arch"

    # Sources are located in the same place as this recipe, copy them to the recipe
    exports_sources = "CMakeLists.txt", "src/*"

    def requirements(self):
        self.requires("drogon/1.9.11")
        
    def layout(self):
        cmake_layout(self)

    def generate(self):
        # Dependency generator
        deps = CMakeDeps(self)
        deps.generate()

        # Toolchain generator
        tc = CMakeToolchain(self, generator="Ninja")
        tc.generate()

        # environment generator 
        env = VirtualRunEnv(self)
        env.generate()

    def configure(self):
        # configure drogon to make with dg_ctl
        self.options["drogon"].with_ctl = True

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.install()
# cspell: ignore Drogon