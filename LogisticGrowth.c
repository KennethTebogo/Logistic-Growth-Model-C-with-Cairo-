#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cairo/cairo.h>

// Function to compute P(t) using the logistic growth formula
double logisticGrowth(double P0, double k, double M, double t) {
    return (M * P0) / (P0 + (M - P0) * exp(-k * M * t));
}

// Function to draw the logistic growth curve
void drawGraph(double P0, double k, double M, int width, int height) {
    cairo_surface_t *surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, width, height);
    cairo_t *cr = cairo_create(surface);

    // Background
    cairo_set_source_rgb(cr, 1, 1, 1);
    cairo_paint(cr);

    // Draw axes
    cairo_set_source_rgb(cr, 0, 0, 0);
    cairo_set_line_width(cr, 2);
    cairo_move_to(cr, 50, height - 50);
    cairo_line_to(cr, 50, 50);
    cairo_move_to(cr, 50, height - 50);
    cairo_line_to(cr, width - 50, height - 50);
    cairo_stroke(cr);

    // Draw logistic curve
    cairo_set_source_rgb(cr, 1, 0, 0);
    cairo_set_line_width(cr, 2);
    cairo_move_to(cr, 50, height - 50);
    
    int timeSteps = 100;
    double maxTime = 50;
    for (int i = 0; i <= timeSteps; i++) {
        double t = (maxTime / timeSteps) * i;
        double P = logisticGrowth(P0, k, M, t);
        double x = 50 + (t / maxTime) * (width - 100);
        double y = height - 50 - (P / M) * (height - 100);
        cairo_line_to(cr, x, y);
    }
    cairo_stroke(cr);

    // Save the image
    cairo_surface_write_to_png(surface, "logistic_growth.png");
    cairo_destroy(cr);
    cairo_surface_destroy(surface);
}

int main() {
    // Define parameters
    double P0 = 10;  // Initial population
    double k = 0.1;   // Growth rate
    double M = 100;   // Carrying capacity
    int width = 800, height = 600;

    // Draw the graph
    drawGraph(P0, k, M, width, height);
    
    printf("Logistic growth graph saved as logistic_growth.png\n");
    return 0;
}

