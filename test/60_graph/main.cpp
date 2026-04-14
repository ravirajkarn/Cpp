#include <sciplot/sciplot.hpp>

int main(int argc, char** argv)
{
    // Create values for your x-axis
    sciplot::Vec x = sciplot::linspace(0.0, 25.0, 100);

    // Create a Plot object
    sciplot::Plot2D BinarySearch;
    // Set color palette for first Plot
    BinarySearch.palette("paired");
    // Draw a sine graph putting x on the x-axis and sin(x) on the y-axis
    BinarySearch.drawCurve(x, std::sin(x)).label("sin(x)").lineWidth(4);
    // Draw a cosine graph putting x on the x-axis and cos(x) on the y-axis
    BinarySearch.drawCurve(x, std::cos(x)).label("cos(x)").lineWidth(2);

    sciplot::Figure figure = {{BinarySearch}};

    // Create a canvas / drawing area to hold figure and plots
    sciplot::Canvas canvas = {{{{BinarySearch}}}};
    // Set color palette for all Plots that do not have a palette set (plot2) / the default palette
    canvas.defaultPalette("set1");

    // Show the canvas in a pop-up window
    canvas.show();
    // Save the plot to a SVG file
    canvas.save("example-readme.svg");
}