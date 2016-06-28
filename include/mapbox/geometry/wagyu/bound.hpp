#pragma once

#include <list>

#include <mapbox/geometry/point.hpp>

#include <mapbox/geometry/wagyu/config.hpp>
#include <mapbox/geometry/wagyu/edge.hpp>

#ifdef DEBUG
#include <iostream>
#endif

namespace mapbox {
namespace geometry {
namespace wagyu {

template <typename T>
struct bound {

    edge_list<T> edges;
    edge_list_itr<T> current_edge;
    mapbox::geometry::point<T> curr;
    ring_ptr<T> ring;
    bound_ptr<T> maximum_bound; // the bound who's maximum connects with this bound
    std::int32_t winding_count;
    std::int32_t winding_count2; // winding count of the opposite polytype
    std::int8_t winding_delta;   // 1 or -1 depending on winding direction - 0 for linestrings
    polygon_type poly_type;
    edge_side side; // side only refers to current side of solution poly

    bound()
        : edges(),
          current_edge(edges.end()),
          curr({ 0, 0 }),
          ring(nullptr),
          maximum_bound(nullptr),
          winding_count(0),
          winding_count2(0),
          winding_delta(0),
          poly_type(type),
          side(edge_left) {
    }
}

#ifdef DEBUG

template <class charT, class traits, typename T>
inline std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& out,
                                                     const bound<T>& bnd) {
    out << "Bound: " << std::endl;
    out << " winding count: " << bnd.winding_count << std::endl;
    out << " winding_count2: " << bnd.winding_count2 << std::endl;
    out << " winding_delta: " << bnd.winding_delta << std::endl;
    return out;
}

#endif
}
}
}
