#define _USE_MATH_DEFINES
#include <pybind11/pybind11.h>
#include <cmath>
#include <tuple>

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

double to_radians(double val) {
    return val * M_PI / 180.0;
}

double haversine(std::tuple<double, double> source, std::tuple<double, double> destination) {
    const double EARTH_RADIUS_IN_METERS = 6372797.560856; 
    double lat_1_rad = to_radians(std::get<0>(source));
    double lon_1_rad = to_radians(std::get<1>(source));
    double lat_2_rad = to_radians(std::get<0>(destination));
    double lon_2_rad = to_radians(std::get<1>(destination));
    double lat_arc = lat_2_rad - lat_1_rad;
    double lon_arc = lon_2_rad - lon_1_rad;
    double sin_half_lat = sin (lat_arc / 2.);
    double sin_half_lon = sin (lon_arc / 2.);
    double prod_cos_lat = cos (lat_1_rad) * cos (lat_2_rad);
    double a = (sin_half_lat*sin_half_lat) + (prod_cos_lat * sin_half_lon*sin_half_lon);
    double c = 2. * asin (sqrt (a));
    return EARTH_RADIUS_IN_METERS * c;
}

namespace py = pybind11;

PYBIND11_MODULE(pyhaversine, m) {
    m.doc() = R"pbdoc(
        Pybind11 example plugin
        -----------------------

        .. currentmodule:: pyhaversine

        .. autosummary::
           :toctree: _generate

           haversine
    )pbdoc";

    m.def("haversine", &haversine, R"pbdoc(
        TODO doc
    )pbdoc");

#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}
